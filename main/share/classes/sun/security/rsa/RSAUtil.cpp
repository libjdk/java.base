#include <sun/security/rsa/RSAUtil.h>

#include <java/security/AlgorithmParameters.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/ProviderException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <sun/security/rsa/RSAUtil$KeyType.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AlgorithmId.h>
#include <jcpp.h>

#undef RSA

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $ProviderException = ::java::security::ProviderException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $RSAUtil$KeyType = ::sun::security::rsa::RSAUtil$KeyType;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;

namespace sun {
	namespace security {
		namespace rsa {

$MethodInfo _RSAUtil_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(RSAUtil, init$, void)},
	{"checkParamsAgainstType", "(Lsun/security/rsa/RSAUtil$KeyType;Ljava/security/spec/AlgorithmParameterSpec;)Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAUtil, checkParamsAgainstType, $AlgorithmParameterSpec*, $RSAUtil$KeyType*, $AlgorithmParameterSpec*), "java.security.ProviderException"},
	{"createAlgorithmId", "(Lsun/security/rsa/RSAUtil$KeyType;Ljava/security/spec/AlgorithmParameterSpec;)Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAUtil, createAlgorithmId, $AlgorithmId*, $RSAUtil$KeyType*, $AlgorithmParameterSpec*), "java.security.ProviderException"},
	{"getParamSpec", "(Ljava/security/AlgorithmParameters;)Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAUtil, getParamSpec, $AlgorithmParameterSpec*, $AlgorithmParameters*), "java.security.ProviderException"},
	{"getParams", "(Lsun/security/rsa/RSAUtil$KeyType;Ljava/security/spec/AlgorithmParameterSpec;)Ljava/security/AlgorithmParameters;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAUtil, getParams, $AlgorithmParameters*, $RSAUtil$KeyType*, $AlgorithmParameterSpec*), "java.security.ProviderException"},
	{"getTypeAndParamSpec", "(Lsun/security/x509/AlgorithmId;)[Ljava/lang/Object;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAUtil, getTypeAndParamSpec, $ObjectArray*, $AlgorithmId*), "java.security.ProviderException"},
	{"requireNonNull", "(Ljava/lang/Object;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(RSAUtil, requireNonNull, void, Object$*, $String*)},
	{}
};

$InnerClassInfo _RSAUtil_InnerClassesInfo_[] = {
	{"sun.security.rsa.RSAUtil$KeyType", "sun.security.rsa.RSAUtil", "KeyType", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _RSAUtil_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.rsa.RSAUtil",
	"java.lang.Object",
	nullptr,
	nullptr,
	_RSAUtil_MethodInfo_,
	nullptr,
	nullptr,
	_RSAUtil_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.rsa.RSAUtil$KeyType"
};

$Object* allocate$RSAUtil($Class* clazz) {
	return $of($alloc(RSAUtil));
}

void RSAUtil::init$() {
}

void RSAUtil::requireNonNull(Object$* obj, $String* msg) {
	if (obj == nullptr) {
		$throwNew($ProviderException, msg);
	}
}

$AlgorithmParameterSpec* RSAUtil::checkParamsAgainstType($RSAUtil$KeyType* type, $AlgorithmParameterSpec* paramSpec) {
	$useLocalCurrentObjectStackCache();
	if (paramSpec == nullptr) {
		return nullptr;
	}
	$Class* expCls = $nc(type)->paramSpecCls;
	if (expCls == nullptr) {
		$throwNew($ProviderException, $$str({"null params expected for "_s, type->keyAlgo}));
	} else if (!$nc(expCls)->isInstance(paramSpec)) {
		$throwNew($ProviderException, $$str({expCls, " expected for "_s, type->keyAlgo}));
	}
	return paramSpec;
}

$AlgorithmParameters* RSAUtil::getParams($RSAUtil$KeyType* type, $AlgorithmParameterSpec* spec) {
	if (spec == nullptr) {
		return nullptr;
	}
	try {
		$var($AlgorithmParameters, params, $AlgorithmParameters::getInstance($nc(type)->keyAlgo));
		$nc(params)->init(spec);
		return params;
	} catch ($NoSuchAlgorithmException& ex) {
		$throwNew($ProviderException, static_cast<$Throwable*>(ex));
	} catch ($InvalidParameterSpecException& ex) {
		$throwNew($ProviderException, static_cast<$Throwable*>(ex));
	}
	$shouldNotReachHere();
}

$AlgorithmId* RSAUtil::createAlgorithmId($RSAUtil$KeyType* type, $AlgorithmParameterSpec* paramSpec) {
	$useLocalCurrentObjectStackCache();
	checkParamsAgainstType(type, paramSpec);
	$var($ObjectIdentifier, oid, $nc(type)->oid);
	$var($AlgorithmParameters, params, getParams(type, paramSpec));
	return $new($AlgorithmId, oid, params);
}

$AlgorithmParameterSpec* RSAUtil::getParamSpec($AlgorithmParameters* params) {
	$useLocalCurrentObjectStackCache();
	if (params == nullptr) {
		return nullptr;
	}
	$var($String, algName, $nc(params)->getAlgorithm());
	$RSAUtil$KeyType* type = $RSAUtil$KeyType::lookup(algName);
	$Class* specCls = $nc(type)->paramSpecCls;
	if (specCls == nullptr) {
		$throwNew($ProviderException, $$str({"No params accepted for "_s, type->keyAlgo}));
	}
	try {
		return params->getParameterSpec(specCls);
	} catch ($InvalidParameterSpecException& ex) {
		$throwNew($ProviderException, static_cast<$Throwable*>(ex));
	}
	$shouldNotReachHere();
}

$ObjectArray* RSAUtil::getTypeAndParamSpec($AlgorithmId* algid) {
	$useLocalCurrentObjectStackCache();
	requireNonNull(algid, "AlgorithmId should not be null"_s);
	$var($ObjectArray, result, $new($ObjectArray, 2));
	$var($String, algName, $nc(algid)->getName());
	try {
		result->set(0, $($RSAUtil$KeyType::lookup(algName)));
	} catch ($ProviderException& pe) {
		if ($nc(algName)->indexOf("RSA"_s) != -1) {
			$init($RSAUtil$KeyType);
			result->set(0, $RSAUtil$KeyType::RSA);
		} else {
			$throw(pe);
		}
	}
	result->set(1, $(getParamSpec($(algid->getParameters()))));
	return result;
}

RSAUtil::RSAUtil() {
}

$Class* RSAUtil::load$($String* name, bool initialize) {
	$loadClass(RSAUtil, name, initialize, &_RSAUtil_ClassInfo_, allocate$RSAUtil);
	return class$;
}

$Class* RSAUtil::class$ = nullptr;

		} // rsa
	} // security
} // sun