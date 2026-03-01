#include <sun/security/util/SignatureUtil.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/interfaces/EdECKey.h>
#include <java/security/interfaces/EdECPrivateKey.h>
#include <java/security/interfaces/RSAKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/ECParameterSpec.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <java/security/spec/NamedParameterSpec.h>
#include <java/security/spec/PSSParameterSpec.h>
#include <java/util/Locale.h>
#include <jdk/internal/access/JavaSecuritySignatureAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/security/rsa/RSAUtil.h>
#include <sun/security/util/ECUtil.h>
#include <sun/security/util/KeyUtil.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/SignatureUtil$EdDSADigestAlgHolder.h>
#include <sun/security/util/SignatureUtil$PSSParamsHolder.h>
#include <sun/security/x509/AlgorithmId.h>
#include <jcpp.h>

#undef ENGLISH
#undef PSS_256_SPEC
#undef PSS_384_SPEC
#undef PSS_512_SPEC
#undef US

using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivateKey = ::java::security::PrivateKey;
using $Provider = ::java::security::Provider;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $Signature = ::java::security::Signature;
using $SignatureException = ::java::security::SignatureException;
using $Certificate = ::java::security::cert::Certificate;
using $EdECKey = ::java::security::interfaces::EdECKey;
using $EdECPrivateKey = ::java::security::interfaces::EdECPrivateKey;
using $RSAKey = ::java::security::interfaces::RSAKey;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $ECParameterSpec = ::java::security::spec::ECParameterSpec;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $NamedParameterSpec = ::java::security::spec::NamedParameterSpec;
using $PSSParameterSpec = ::java::security::spec::PSSParameterSpec;
using $Locale = ::java::util::Locale;
using $JavaSecuritySignatureAccess = ::jdk::internal::access::JavaSecuritySignatureAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $RSAUtil = ::sun::security::rsa::RSAUtil;
using $ECUtil = ::sun::security::util::ECUtil;
using $KeyUtil = ::sun::security::util::KeyUtil;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $SignatureUtil$EdDSADigestAlgHolder = ::sun::security::util::SignatureUtil$EdDSADigestAlgHolder;
using $SignatureUtil$PSSParamsHolder = ::sun::security::util::SignatureUtil$PSSParamsHolder;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;

namespace sun {
	namespace security {
		namespace util {

$MethodInfo _SignatureUtil_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SignatureUtil, init$, void)},
	{"autoInitInternal", "(Ljava/lang/String;Ljava/security/Key;Ljava/security/Signature;)Ljava/security/Signature;", nullptr, $PRIVATE | $STATIC, $staticMethod(SignatureUtil, autoInitInternal, $Signature*, $String*, $Key*, $Signature*), "java.security.InvalidKeyException"},
	{"checkKeyAndSigAlgMatch", "(Ljava/security/PrivateKey;Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, checkKeyAndSigAlgMatch, void, $PrivateKey*, $String*)},
	{"checkName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(SignatureUtil, checkName, $String*, $String*)},
	{"createAlgorithmParameters", "(Ljava/lang/String;[B)Ljava/security/AlgorithmParameters;", nullptr, $PRIVATE | $STATIC, $staticMethod(SignatureUtil, createAlgorithmParameters, $AlgorithmParameters*, $String*, $bytes*), "java.security.ProviderException"},
	{"ecStrength", "(I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(SignatureUtil, ecStrength, $String*, int32_t)},
	{"extractDigestAlgFromDwithE", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, extractDigestAlgFromDwithE, $String*, $String*)},
	{"extractKeyAlgFromDwithE", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, extractKeyAlgFromDwithE, $String*, $String*)},
	{"fromKey", "(Ljava/lang/String;Ljava/security/Key;Ljava/lang/String;)Ljava/security/Signature;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, fromKey, $Signature*, $String*, $Key*, $String*), "java.security.NoSuchAlgorithmException,java.security.NoSuchProviderException,java.security.InvalidKeyException"},
	{"fromKey", "(Ljava/lang/String;Ljava/security/Key;Ljava/security/Provider;)Ljava/security/Signature;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, fromKey, $Signature*, $String*, $Key*, $Provider*), "java.security.NoSuchAlgorithmException,java.security.InvalidKeyException"},
	{"fromSignature", "(Ljava/security/Signature;Ljava/security/PrivateKey;)Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, fromSignature, $AlgorithmId*, $Signature*, $PrivateKey*), "java.security.SignatureException"},
	{"getDefaultParamSpec", "(Ljava/lang/String;Ljava/security/Key;)Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, getDefaultParamSpec, $AlgorithmParameterSpec*, $String*, $Key*)},
	{"getDefaultSigAlgForKey", "(Ljava/security/PrivateKey;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, getDefaultSigAlgForKey, $String*, $PrivateKey*)},
	{"getDigestAlgInPkcs7SignerInfo", "(Ljava/security/Signature;Ljava/lang/String;Ljava/security/PrivateKey;Z)Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, getDigestAlgInPkcs7SignerInfo, $AlgorithmId*, $Signature*, $String*, $PrivateKey*, bool), "java.security.NoSuchAlgorithmException"},
	{"getParamSpec", "(Ljava/lang/String;Ljava/security/AlgorithmParameters;)Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, getParamSpec, $AlgorithmParameterSpec*, $String*, $AlgorithmParameters*), "java.security.ProviderException"},
	{"getParamSpec", "(Ljava/lang/String;[B)Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, getParamSpec, $AlgorithmParameterSpec*, $String*, $bytes*), "java.security.ProviderException"},
	{"ifcFfcStrength", "(I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(SignatureUtil, ifcFfcStrength, $String*, int32_t)},
	{"initSignWithParam", "(Ljava/security/Signature;Ljava/security/PrivateKey;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, initSignWithParam, void, $Signature*, $PrivateKey*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.ProviderException,java.security.InvalidAlgorithmParameterException,java.security.InvalidKeyException"},
	{"initVerifyWithParam", "(Ljava/security/Signature;Ljava/security/PublicKey;Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, initVerifyWithParam, void, $Signature*, $PublicKey*, $AlgorithmParameterSpec*), "java.security.ProviderException,java.security.InvalidAlgorithmParameterException,java.security.InvalidKeyException"},
	{"initVerifyWithParam", "(Ljava/security/Signature;Ljava/security/cert/Certificate;Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureUtil, initVerifyWithParam, void, $Signature*, $Certificate*, $AlgorithmParameterSpec*), "java.security.ProviderException,java.security.InvalidAlgorithmParameterException,java.security.InvalidKeyException"},
	{}
};

$InnerClassInfo _SignatureUtil_InnerClassesInfo_[] = {
	{"sun.security.util.SignatureUtil$PSSParamsHolder", "sun.security.util.SignatureUtil", "PSSParamsHolder", $PRIVATE | $STATIC},
	{"sun.security.util.SignatureUtil$EdDSADigestAlgHolder", "sun.security.util.SignatureUtil", "EdDSADigestAlgHolder", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _SignatureUtil_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.util.SignatureUtil",
	"java.lang.Object",
	nullptr,
	nullptr,
	_SignatureUtil_MethodInfo_,
	nullptr,
	nullptr,
	_SignatureUtil_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.util.SignatureUtil$PSSParamsHolder,sun.security.util.SignatureUtil$EdDSADigestAlgHolder"
};

$Object* allocate$SignatureUtil($Class* clazz) {
	return $of($alloc(SignatureUtil));
}

void SignatureUtil::init$() {
}

$String* SignatureUtil::checkName($String* algName$renamed) {
	$var($String, algName, algName$renamed);
	if ($nc(algName)->indexOf("."_s) == -1) {
		return algName;
	} else {
		if (algName->startsWith("OID."_s)) {
			$assign(algName, algName->substring(4));
		}
		$KnownOIDs* ko = $KnownOIDs::findMatch(algName);
		return ko != nullptr ? $nc(ko)->stdName() : algName;
	}
}

$AlgorithmParameters* SignatureUtil::createAlgorithmParameters($String* algName$renamed, $bytes* paramBytes) {
	$useLocalCurrentObjectStackCache();
	$var($String, algName, algName$renamed);
	try {
		$assign(algName, checkName(algName));
		$var($AlgorithmParameters, result, $AlgorithmParameters::getInstance(algName));
		$nc(result)->init(paramBytes);
		return result;
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($ProviderException, static_cast<$Throwable*>(e));
	} catch ($IOException& e) {
		$throwNew($ProviderException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$AlgorithmParameterSpec* SignatureUtil::getParamSpec($String* sigName$renamed, $AlgorithmParameters* params$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, sigName, sigName$renamed);
	$var($AlgorithmParameters, params, params$renamed);
	$var($AlgorithmParameterSpec, paramSpec, nullptr);
	if (params != nullptr) {
		$init($Locale);
		$assign(sigName, $nc($(checkName(sigName)))->toUpperCase($Locale::ENGLISH));
		if ($nc($(params->getAlgorithm()))->indexOf("."_s) != -1) {
			try {
				$assign(params, createAlgorithmParameters(sigName, $(params->getEncoded())));
			} catch ($IOException& e) {
				$throwNew($ProviderException, static_cast<$Throwable*>(e));
			}
		}
		if (sigName->indexOf("RSA"_s) != -1) {
			$assign(paramSpec, $RSAUtil::getParamSpec(params));
		} else if (sigName->indexOf("ECDSA"_s) != -1) {
			try {
				$load($ECParameterSpec);
				$assign(paramSpec, params->getParameterSpec($ECParameterSpec::class$));
			} catch ($Exception& e) {
				$throwNew($ProviderException, "Error handling EC parameters"_s, e);
			}
		} else {
			$throwNew($ProviderException, $$str({"Unrecognized algorithm for signature parameters "_s, sigName}));
		}
	}
	return paramSpec;
}

$AlgorithmParameterSpec* SignatureUtil::getParamSpec($String* sigName$renamed, $bytes* paramBytes) {
	$useLocalCurrentObjectStackCache();
	$var($String, sigName, sigName$renamed);
	$var($AlgorithmParameterSpec, paramSpec, nullptr);
	if (paramBytes != nullptr) {
		$init($Locale);
		$assign(sigName, $nc($(checkName(sigName)))->toUpperCase($Locale::ENGLISH));
		if (sigName->indexOf("RSA"_s) != -1) {
			$var($AlgorithmParameters, params, createAlgorithmParameters(sigName, paramBytes));
			$assign(paramSpec, $RSAUtil::getParamSpec(params));
		} else if (sigName->indexOf("ECDSA"_s) != -1) {
			try {
				$var($Provider, p, $nc($($Signature::getInstance(sigName)))->getProvider());
				$assign(paramSpec, $ECUtil::getECParameterSpec(p, paramBytes));
			} catch ($Exception& e) {
				$throwNew($ProviderException, "Error handling EC parameters"_s, e);
			}
			if (paramSpec == nullptr) {
				$throwNew($ProviderException, "Error handling EC parameters"_s);
			}
		} else {
			$throwNew($ProviderException, $$str({"Unrecognized algorithm for signature parameters "_s, sigName}));
		}
	}
	return paramSpec;
}

void SignatureUtil::initVerifyWithParam($Signature* s, $PublicKey* key, $AlgorithmParameterSpec* params) {
	$nc($($SharedSecrets::getJavaSecuritySignatureAccess()))->initVerify(s, key, params);
}

void SignatureUtil::initVerifyWithParam($Signature* s, $Certificate* cert, $AlgorithmParameterSpec* params) {
	$nc($($SharedSecrets::getJavaSecuritySignatureAccess()))->initVerify(s, cert, params);
}

void SignatureUtil::initSignWithParam($Signature* s, $PrivateKey* key, $AlgorithmParameterSpec* params, $SecureRandom* sr) {
	$nc($($SharedSecrets::getJavaSecuritySignatureAccess()))->initSign(s, key, params, sr);
}

$AlgorithmId* SignatureUtil::getDigestAlgInPkcs7SignerInfo($Signature* signer, $String* sigalg, $PrivateKey* privateKey, bool directsign) {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmId, digAlgID, nullptr);
	$var($String, kAlg, $nc(privateKey)->getAlgorithm());
	bool var$0 = $instanceOf($EdECPrivateKey, privateKey) || $nc(kAlg)->equalsIgnoreCase("Ed25519"_s);
	if (var$0 || $nc(kAlg)->equalsIgnoreCase("Ed448"_s)) {
		if ($instanceOf($EdECPrivateKey, privateKey)) {
			$assign(kAlg, $nc($($nc(($cast($EdECPrivateKey, privateKey)))->getParams()))->getName());
		}
		{
			$init($Locale);
			$var($String, s9866$, kAlg->toUpperCase($Locale::ENGLISH));
			int32_t tmp9866$ = -1;
			switch (s9866$->hashCode()) {
			case (int32_t)0xB8F0FEBB:
				{
					if (s9866$->equals("ED25519"_s)) {
						tmp9866$ = 0;
					}
					break;
				}
			case 0x03EC08B9:
				{
					if (s9866$->equals("ED448"_s)) {
						tmp9866$ = 1;
					}
					break;
				}
			}
			switch (tmp9866$) {
			case 0:
				{
					$init($SignatureUtil$EdDSADigestAlgHolder);
					$assign(digAlgID, $SignatureUtil$EdDSADigestAlgHolder::sha512);
					break;
				}
			case 1:
				{
					if (directsign) {
						$init($SignatureUtil$EdDSADigestAlgHolder);
						$assign(digAlgID, $SignatureUtil$EdDSADigestAlgHolder::shake256);
					} else {
						$init($SignatureUtil$EdDSADigestAlgHolder);
						$assign(digAlgID, $SignatureUtil$EdDSADigestAlgHolder::shake256$512);
					}
					break;
				}
			default:
				{
					$throwNew($AssertionError, $of($$str({"Unknown curve name: "_s, kAlg})));
				}
			}
		}
	} else if ($nc(sigalg)->equalsIgnoreCase("RSASSA-PSS"_s)) {
		try {
			$load($PSSParameterSpec);
			$assign(digAlgID, $AlgorithmId::get($($nc(($cast($PSSParameterSpec, $($nc($($nc(signer)->getParameters()))->getParameterSpec($PSSParameterSpec::class$)))))->getDigestAlgorithm())));
		} catch ($InvalidParameterSpecException& e) {
			$throwNew($AssertionError, "Should not happen"_s, e);
		}
	} else {
		$assign(digAlgID, $AlgorithmId::get($(extractDigestAlgFromDwithE(sigalg))));
	}
	return digAlgID;
}

$String* SignatureUtil::extractDigestAlgFromDwithE($String* signatureAlgorithm$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, signatureAlgorithm, signatureAlgorithm$renamed);
	$init($Locale);
	$assign(signatureAlgorithm, $nc(signatureAlgorithm)->toUpperCase($Locale::ENGLISH));
	int32_t with = signatureAlgorithm->indexOf("WITH"_s);
	if (with > 0) {
		return signatureAlgorithm->substring(0, with);
	} else {
		$throwNew($IllegalArgumentException, $$str({"Unknown algorithm: "_s, signatureAlgorithm}));
	}
}

$String* SignatureUtil::extractKeyAlgFromDwithE($String* signatureAlgorithm$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, signatureAlgorithm, signatureAlgorithm$renamed);
	$init($Locale);
	$assign(signatureAlgorithm, $nc(signatureAlgorithm)->toUpperCase($Locale::ENGLISH));
	int32_t with = signatureAlgorithm->indexOf("WITH"_s);
	$var($String, keyAlgorithm, nullptr);
	if (with > 0) {
		int32_t and$ = signatureAlgorithm->indexOf("AND"_s, with + 4);
		if (and$ > 0) {
			$assign(keyAlgorithm, signatureAlgorithm->substring(with + 4, and$));
		} else {
			$assign(keyAlgorithm, signatureAlgorithm->substring(with + 4));
		}
		if ($nc(keyAlgorithm)->equalsIgnoreCase("ECDSA"_s)) {
			$assign(keyAlgorithm, "EC"_s);
		}
	}
	return keyAlgorithm;
}

$AlgorithmParameterSpec* SignatureUtil::getDefaultParamSpec($String* sigAlg$renamed, $Key* k) {
	$useLocalCurrentObjectStackCache();
	$var($String, sigAlg, sigAlg$renamed);
	$assign(sigAlg, checkName(sigAlg));
	if ($nc(sigAlg)->equalsIgnoreCase("RSASSA-PSS"_s)) {
		if ($instanceOf($RSAKey, k)) {
			$var($AlgorithmParameterSpec, spec, $nc(($cast($RSAKey, k)))->getParams());
			if ($instanceOf($PSSParameterSpec, spec)) {
				return spec;
			}
		}
		{
			$var($String, s13377$, ifcFfcStrength($KeyUtil::getKeySize(k)));
			int32_t tmp13377$ = -1;
			switch ($nc(s13377$)->hashCode()) {
			case (int32_t)0x91B72647:
				{
					if (s13377$->equals("SHA256"_s)) {
						tmp13377$ = 0;
					}
					break;
				}
			case (int32_t)0x91B72A63:
				{
					if (s13377$->equals("SHA384"_s)) {
						tmp13377$ = 1;
					}
					break;
				}
			case (int32_t)0x91B7310A:
				{
					if (s13377$->equals("SHA512"_s)) {
						tmp13377$ = 2;
					}
					break;
				}
			}
			switch (tmp13377$) {
			case 0:
				{
					$init($SignatureUtil$PSSParamsHolder);
					return $SignatureUtil$PSSParamsHolder::PSS_256_SPEC;
				}
			case 1:
				{
					$init($SignatureUtil$PSSParamsHolder);
					return $SignatureUtil$PSSParamsHolder::PSS_384_SPEC;
				}
			case 2:
				{
					$init($SignatureUtil$PSSParamsHolder);
					return $SignatureUtil$PSSParamsHolder::PSS_512_SPEC;
				}
			default:
				{
					$throwNew($AssertionError, $of("Should not happen"_s));
				}
			}
		}
	} else {
		return nullptr;
	}
}

$Signature* SignatureUtil::fromKey($String* sigAlg, $Key* key, $String* provider) {
	$var($Signature, sigEngine, (provider == nullptr || $nc(provider)->isEmpty()) ? $Signature::getInstance(sigAlg) : $Signature::getInstance(sigAlg, provider));
	return autoInitInternal(sigAlg, key, sigEngine);
}

$Signature* SignatureUtil::fromKey($String* sigAlg, $Key* key, $Provider* provider) {
	$var($Signature, sigEngine, (provider == nullptr) ? $Signature::getInstance(sigAlg) : $Signature::getInstance(sigAlg, provider));
	return autoInitInternal(sigAlg, key, sigEngine);
}

$Signature* SignatureUtil::autoInitInternal($String* alg, $Key* key, $Signature* s) {
	$var($AlgorithmParameterSpec, params, SignatureUtil::getDefaultParamSpec(alg, key));
	try {
		if ($instanceOf($PrivateKey, key)) {
			SignatureUtil::initSignWithParam(s, $cast($PrivateKey, key), params, nullptr);
		} else {
			SignatureUtil::initVerifyWithParam(s, $cast($PublicKey, key), params);
		}
	} catch ($InvalidAlgorithmParameterException& e) {
		$throwNew($AssertionError, "Should not happen"_s, e);
	}
	return s;
}

$AlgorithmId* SignatureUtil::fromSignature($Signature* sigEngine, $PrivateKey* key) {
	$useLocalCurrentObjectStackCache();
	try {
		if ($instanceOf($EdECKey, key)) {
			return $AlgorithmId::get($($nc($($nc(($cast($EdECKey, key)))->getParams()))->getName()));
		}
		$var($AlgorithmParameters, params, nullptr);
		try {
			$assign(params, $nc(sigEngine)->getParameters());
		} catch ($UnsupportedOperationException& e) {
		}
		if (params != nullptr) {
			return $AlgorithmId::get($($nc(sigEngine)->getParameters()));
		} else {
			$var($String, sigAlg, $nc(sigEngine)->getAlgorithm());
			if ($nc(sigAlg)->equalsIgnoreCase("EdDSA"_s)) {
				$assign(sigAlg, $nc(key)->getAlgorithm());
			}
			return $AlgorithmId::get(sigAlg);
		}
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($SignatureException, "Cannot derive AlgorithmIdentifier"_s, e);
	}
	$shouldNotReachHere();
}

void SignatureUtil::checkKeyAndSigAlgMatch($PrivateKey* key, $String* sAlg$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, sAlg, sAlg$renamed);
	$init($Locale);
	$var($String, kAlg, $nc($($nc(key)->getAlgorithm()))->toUpperCase($Locale::ENGLISH));
	$assign(sAlg, $nc($(checkName(sAlg)))->toUpperCase($Locale::ENGLISH));
	{
		$var($String, s17871$, sAlg);
		int32_t tmp17871$ = -1;
		switch (s17871$->hashCode()) {
		case 0x69D3B2A4:
			{
				if (s17871$->equals("RSASSA-PSS"_s)) {
					tmp17871$ = 0;
				}
				break;
			}
		case 0x03EC4893:
			{
				if (s17871$->equals("EDDSA"_s)) {
					tmp17871$ = 1;
				}
				break;
			}
		case (int32_t)0xB8F0FEBB:
			{
				if (s17871$->equals("ED25519"_s)) {
					tmp17871$ = 2;
				}
				break;
			}
		case 0x03EC08B9:
			{
				if (s17871$->equals("ED448"_s)) {
					tmp17871$ = 3;
				}
				break;
			}
		}
		switch (tmp17871$) {
		case 0:
			{
				{
					bool var$0 = !kAlg->equals("RSASSA-PSS"_s);
					if (var$0 && !kAlg->equals("RSA"_s)) {
						$throwNew($IllegalArgumentException, "key algorithm not compatible with signature algorithm"_s);
					}
				}
				break;
			}
		case 1:
			{
				{
					bool var$2 = !kAlg->equals("EDDSA"_s);
					bool var$1 = var$2 && !kAlg->equals("ED448"_s);
					if (var$1 && !kAlg->equals("ED25519"_s)) {
						$throwNew($IllegalArgumentException, "key algorithm not compatible with signature algorithm"_s);
					}
				}
				break;
			}
		case 2:
			{}
		case 3:
			{
				{
					if ($instanceOf($EdECKey, key)) {
						$var($String, groupName, $nc($($nc($($nc(($cast($EdECKey, key)))->getParams()))->getName()))->toUpperCase($Locale::US));
						if (!sAlg->equals(groupName)) {
							$throwNew($IllegalArgumentException, "key algorithm not compatible with signature algorithm"_s);
						}
					} else {
						bool var$4 = !kAlg->equals("EDDSA"_s);
						if (var$4 && !kAlg->equals(sAlg)) {
							$throwNew($IllegalArgumentException, "key algorithm not compatible with signature algorithm"_s);
						}
					}
				}
				break;
			}
		default:
			{
				{
					if (sAlg->contains("WITH"_s)) {
						bool var$7 = sAlg->endsWith("WITHRSA"_s);
						bool var$6 = (var$7 && !kAlg->equals("RSA"_s));
						if (!var$6) {
							bool var$8 = sAlg->endsWith("WITHECDSA"_s);
							var$6 = (var$8 && !kAlg->equals("EC"_s));
						}
						bool var$5 = var$6;
						if (!var$5) {
							bool var$9 = sAlg->endsWith("WITHDSA"_s);
							var$5 = (var$9 && !kAlg->equals("DSA"_s));
						}
						if (var$5) {
							$throwNew($IllegalArgumentException, "key algorithm not compatible with signature algorithm"_s);
						}
					}
				}
				break;
			}
		}
	}
}

$String* SignatureUtil::getDefaultSigAlgForKey($PrivateKey* k) {
	$useLocalCurrentObjectStackCache();
	$var($String, kAlg, $nc(k)->getAlgorithm());
	$init($Locale);
	$var($String, s20391$, $nc(kAlg)->toUpperCase($Locale::ENGLISH));
	int32_t tmp20391$ = -1;
	switch (s20391$->hashCode()) {
	case 0x00010992:
		{
			if (s20391$->equals("DSA"_s)) {
				tmp20391$ = 0;
			}
			break;
		}
	case 0x00013E20:
		{
			if (s20391$->equals("RSA"_s)) {
				tmp20391$ = 1;
			}
			break;
		}
	case 2206:
		{
			if (s20391$->equals("EC"_s)) {
				tmp20391$ = 2;
			}
			break;
		}
	case 0x03EC4893:
		{
			if (s20391$->equals("EDDSA"_s)) {
				tmp20391$ = 3;
			}
			break;
		}
	case 0x69D3B2A4:
		{
			if (s20391$->equals("RSASSA-PSS"_s)) {
				tmp20391$ = 4;
			}
			break;
		}
	case (int32_t)0xB8F0FEBB:
		{
			if (s20391$->equals("ED25519"_s)) {
				tmp20391$ = 5;
			}
			break;
		}
	case 0x03EC08B9:
		{
			if (s20391$->equals("ED448"_s)) {
				tmp20391$ = 6;
			}
			break;
		}
	}

	$var($String, var$0, nullptr)
	switch (tmp20391$) {
	case 0:
		{}
	case 1:
		{
			$assign(var$0, $str({$(ifcFfcStrength($KeyUtil::getKeySize(static_cast<$Key*>(k)))), "with"_s, kAlg}));
			break;
		}
	case 2:
		{
			$assign(var$0, $str({$(ecStrength($KeyUtil::getKeySize(static_cast<$Key*>(k)))), "withECDSA"_s}));
			break;
		}
	case 3:
		{
			$assign(var$0, $instanceOf($EdECPrivateKey, k) ? $nc($($nc(($cast($EdECPrivateKey, k)))->getParams()))->getName() : kAlg);
			break;
		}
	case 4:
		{}
	case 5:
		{}
	case 6:
		{
			$assign(var$0, kAlg);
			break;
		}
	default:
		{
			$assign(var$0, nullptr);
			break;
		}
	}
	return var$0;
}

$String* SignatureUtil::ecStrength(int32_t bitLength) {
	if (bitLength >= 512) {
		return "SHA512"_s;
	} else if (bitLength >= 384) {
		return "SHA384"_s;
	} else {
		return "SHA256"_s;
	}
}

$String* SignatureUtil::ifcFfcStrength(int32_t bitLength) {
	if (bitLength > 7680) {
		return "SHA512"_s;
	} else if (bitLength > 3072) {
		return "SHA384"_s;
	} else {
		return "SHA256"_s;
	}
}

SignatureUtil::SignatureUtil() {
}

$Class* SignatureUtil::load$($String* name, bool initialize) {
	$loadClass(SignatureUtil, name, initialize, &_SignatureUtil_ClassInfo_, allocate$SignatureUtil);
	return class$;
}

$Class* SignatureUtil::class$ = nullptr;

		} // util
	} // security
} // sun