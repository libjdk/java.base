#include <sun/security/ssl/DHKeyExchange$DHEPossession.h>

#include <java/math/BigInteger.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/KeyFactory.h>
#include <java/security/KeyPair.h>
#include <java/security/KeyPairGenerator.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/Provider.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/InvalidKeySpecException.h>
#include <java/security/spec/KeySpec.h>
#include <java/util/Map.h>
#include <javax/crypto/interfaces/DHPublicKey.h>
#include <javax/crypto/spec/DHParameterSpec.h>
#include <javax/crypto/spec/DHPublicKeySpec.h>
#include <sun/security/ssl/DHKeyExchange$DHECredentials.h>
#include <sun/security/ssl/DHKeyExchange.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/PredefinedDHParameterSpecs.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/util/KeyUtil.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigInteger = ::java::math::BigInteger;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $KeyFactory = ::java::security::KeyFactory;
using $KeyPair = ::java::security::KeyPair;
using $KeyPairGenerator = ::java::security::KeyPairGenerator;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivateKey = ::java::security::PrivateKey;
using $Provider = ::java::security::Provider;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $InvalidKeySpecException = ::java::security::spec::InvalidKeySpecException;
using $KeySpec = ::java::security::spec::KeySpec;
using $Map = ::java::util::Map;
using $DHPublicKey = ::javax::crypto::interfaces::DHPublicKey;
using $DHParameterSpec = ::javax::crypto::spec::DHParameterSpec;
using $DHPublicKeySpec = ::javax::crypto::spec::DHPublicKeySpec;
using $DHKeyExchange$DHECredentials = ::sun::security::ssl::DHKeyExchange$DHECredentials;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $PredefinedDHParameterSpecs = ::sun::security::ssl::PredefinedDHParameterSpecs;
using $Utilities = ::sun::security::ssl::Utilities;
using $KeyUtil = ::sun::security::util::KeyUtil;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _DHKeyExchange$DHEPossession_FieldInfo_[] = {
	{"privateKey", "Ljava/security/PrivateKey;", nullptr, $FINAL, $field(DHKeyExchange$DHEPossession, privateKey)},
	{"publicKey", "Ljavax/crypto/interfaces/DHPublicKey;", nullptr, $FINAL, $field(DHKeyExchange$DHEPossession, publicKey)},
	{"namedGroup", "Lsun/security/ssl/NamedGroup;", nullptr, $FINAL, $field(DHKeyExchange$DHEPossession, namedGroup)},
	{}
};

$MethodInfo _DHKeyExchange$DHEPossession_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/NamedGroup;Ljava/security/SecureRandom;)V", nullptr, 0, $method(DHKeyExchange$DHEPossession, init$, void, $NamedGroup*, $SecureRandom*)},
	{"<init>", "(ILjava/security/SecureRandom;)V", nullptr, 0, $method(DHKeyExchange$DHEPossession, init$, void, int32_t, $SecureRandom*)},
	{"<init>", "(Lsun/security/ssl/DHKeyExchange$DHECredentials;Ljava/security/SecureRandom;)V", nullptr, 0, $method(DHKeyExchange$DHEPossession, init$, void, $DHKeyExchange$DHECredentials*, $SecureRandom*)},
	{"encode", "()[B", nullptr, $PUBLIC, $virtualMethod(DHKeyExchange$DHEPossession, encode, $bytes*)},
	{"generateDHKeyPair", "(Ljava/security/KeyPairGenerator;)Ljava/security/KeyPair;", nullptr, $PRIVATE, $method(DHKeyExchange$DHEPossession, generateDHKeyPair, $KeyPair*, $KeyPairGenerator*), "java.security.GeneralSecurityException"},
	{"getDHPublicKeySpec", "(Ljava/security/PublicKey;)Ljavax/crypto/spec/DHPublicKeySpec;", nullptr, $PRIVATE | $STATIC, $staticMethod(DHKeyExchange$DHEPossession, getDHPublicKeySpec, $DHPublicKeySpec*, $PublicKey*)},
	{"getNamedGroup", "()Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC, $virtualMethod(DHKeyExchange$DHEPossession, getNamedGroup, $NamedGroup*)},
	{"getPrivateKey", "()Ljava/security/PrivateKey;", nullptr, $PUBLIC, $virtualMethod(DHKeyExchange$DHEPossession, getPrivateKey, $PrivateKey*)},
	{"getPublicKey", "()Ljava/security/PublicKey;", nullptr, $PUBLIC, $virtualMethod(DHKeyExchange$DHEPossession, getPublicKey, $PublicKey*)},
	{}
};

$InnerClassInfo _DHKeyExchange$DHEPossession_InnerClassesInfo_[] = {
	{"sun.security.ssl.DHKeyExchange$DHEPossession", "sun.security.ssl.DHKeyExchange", "DHEPossession", $STATIC | $FINAL},
	{}
};

$ClassInfo _DHKeyExchange$DHEPossession_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.DHKeyExchange$DHEPossession",
	"java.lang.Object",
	"sun.security.ssl.NamedGroupPossession",
	_DHKeyExchange$DHEPossession_FieldInfo_,
	_DHKeyExchange$DHEPossession_MethodInfo_,
	nullptr,
	nullptr,
	_DHKeyExchange$DHEPossession_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.DHKeyExchange"
};

$Object* allocate$DHKeyExchange$DHEPossession($Class* clazz) {
	return $of($alloc(DHKeyExchange$DHEPossession));
}

void DHKeyExchange$DHEPossession::init$($NamedGroup* namedGroup, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($KeyPairGenerator, kpg, $KeyPairGenerator::getInstance("DiffieHellman"_s));
		$nc(kpg)->initialize($nc(namedGroup)->keAlgParamSpec, random);
		$var($KeyPair, kp, generateDHKeyPair(kpg));
		if (kp == nullptr) {
			$throwNew($RuntimeException, "Could not generate DH keypair"_s);
		}
		$set(this, privateKey, $nc(kp)->getPrivate());
		$set(this, publicKey, $cast($DHPublicKey, kp->getPublic()));
	} catch ($GeneralSecurityException& gse) {
		$throwNew($RuntimeException, "Could not generate DH keypair"_s, gse);
	}
	$set(this, namedGroup, namedGroup);
}

void DHKeyExchange$DHEPossession::init$(int32_t keyLength, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	$init($PredefinedDHParameterSpecs);
	$var($DHParameterSpec, params, $cast($DHParameterSpec, $nc($PredefinedDHParameterSpecs::definedParams)->get($($Integer::valueOf(keyLength)))));
	try {
		$var($KeyPairGenerator, kpg, $KeyPairGenerator::getInstance("DiffieHellman"_s));
		if (params != nullptr) {
			$nc(kpg)->initialize(static_cast<$AlgorithmParameterSpec*>(params), random);
		} else {
			$nc(kpg)->initialize(keyLength, random);
		}
		$var($KeyPair, kp, generateDHKeyPair(kpg));
		if (kp == nullptr) {
			$throwNew($RuntimeException, $$str({"Could not generate DH keypair of "_s, $$str(keyLength), " bits"_s}));
		}
		$set(this, privateKey, $nc(kp)->getPrivate());
		$set(this, publicKey, $cast($DHPublicKey, kp->getPublic()));
	} catch ($GeneralSecurityException& gse) {
		$throwNew($RuntimeException, "Could not generate DH keypair"_s, gse);
	}
	$set(this, namedGroup, $NamedGroup::valueOf($($nc(this->publicKey)->getParams())));
}

void DHKeyExchange$DHEPossession::init$($DHKeyExchange$DHECredentials* credentials, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($KeyPairGenerator, kpg, $KeyPairGenerator::getInstance("DiffieHellman"_s));
		$nc(kpg)->initialize($(static_cast<$AlgorithmParameterSpec*>($nc($nc(credentials)->popPublicKey)->getParams())), random);
		$var($KeyPair, kp, generateDHKeyPair(kpg));
		if (kp == nullptr) {
			$throwNew($RuntimeException, "Could not generate DH keypair"_s);
		}
		$set(this, privateKey, $nc(kp)->getPrivate());
		$set(this, publicKey, $cast($DHPublicKey, kp->getPublic()));
	} catch ($GeneralSecurityException& gse) {
		$throwNew($RuntimeException, "Could not generate DH keypair"_s, gse);
	}
	$set(this, namedGroup, $nc(credentials)->namedGroup);
}

$KeyPair* DHKeyExchange$DHEPossession::generateDHKeyPair($KeyPairGenerator* kpg) {
	$useLocalCurrentObjectStackCache();
	bool doExtraValidation = (!$KeyUtil::isOracleJCEProvider($($nc($($nc(kpg)->getProvider()))->getName())));
	bool isRecovering = false;
	for (int32_t i = 0; i <= 2; ++i) {
		$var($KeyPair, kp, $nc(kpg)->generateKeyPair());
		if (doExtraValidation) {
			$var($DHPublicKeySpec, spec, getDHPublicKeySpec($($nc(kp)->getPublic())));
			try {
				$KeyUtil::validate(static_cast<$KeySpec*>(spec));
			} catch ($InvalidKeyException& ivke) {
				if (isRecovering) {
					$throw(ivke);
				}
				isRecovering = true;
				continue;
			}
		}
		return kp;
	}
	return nullptr;
}

$DHPublicKeySpec* DHKeyExchange$DHEPossession::getDHPublicKeySpec($PublicKey* key) {
	$init(DHKeyExchange$DHEPossession);
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($DHPublicKey, key)) {
		$var($DHPublicKey, dhKey, $cast($DHPublicKey, key));
		$var($DHParameterSpec, params, $nc(dhKey)->getParams());
		$var($BigInteger, var$0, dhKey->getY());
		$var($BigInteger, var$1, $nc(params)->getP());
		return $new($DHPublicKeySpec, var$0, var$1, $(params->getG()));
	}
	try {
		$var($KeyFactory, factory, $KeyFactory::getInstance("DiffieHellman"_s));
		$load($DHPublicKeySpec);
		return $cast($DHPublicKeySpec, $nc(factory)->getKeySpec(key, $DHPublicKeySpec::class$));
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($RuntimeException, "Unable to get DHPublicKeySpec"_s, e);
	} catch ($InvalidKeySpecException& e) {
		$throwNew($RuntimeException, "Unable to get DHPublicKeySpec"_s, e);
	}
	$shouldNotReachHere();
}

$bytes* DHKeyExchange$DHEPossession::encode() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encoded, $Utilities::toByteArray($($nc(this->publicKey)->getY())));
	int32_t pSize = (int32_t)((uint32_t)($KeyUtil::getKeySize(static_cast<$Key*>(this->publicKey)) + 7) >> 3);
	if (pSize > 0 && $nc(encoded)->length < pSize) {
		$var($bytes, buffer, $new($bytes, pSize));
		$System::arraycopy(encoded, 0, buffer, pSize - encoded->length, encoded->length);
		$assign(encoded, buffer);
	}
	return encoded;
}

$PublicKey* DHKeyExchange$DHEPossession::getPublicKey() {
	return this->publicKey;
}

$NamedGroup* DHKeyExchange$DHEPossession::getNamedGroup() {
	return this->namedGroup;
}

$PrivateKey* DHKeyExchange$DHEPossession::getPrivateKey() {
	return this->privateKey;
}

DHKeyExchange$DHEPossession::DHKeyExchange$DHEPossession() {
}

$Class* DHKeyExchange$DHEPossession::load$($String* name, bool initialize) {
	$loadClass(DHKeyExchange$DHEPossession, name, initialize, &_DHKeyExchange$DHEPossession_ClassInfo_, allocate$DHKeyExchange$DHEPossession);
	return class$;
}

$Class* DHKeyExchange$DHEPossession::class$ = nullptr;

		} // ssl
	} // security
} // sun