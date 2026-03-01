#include <sun/security/ssl/ECDHKeyExchange$ECDHEPossession.h>

#include <java/io/IOException.h>
#include <java/lang/Enum.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/CryptoPrimitive.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Key.h>
#include <java/security/KeyFactory.h>
#include <java/security/KeyPair.h>
#include <java/security/KeyPairGenerator.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/interfaces/ECPublicKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/ECParameterSpec.h>
#include <java/security/spec/ECPoint.h>
#include <java/security/spec/ECPublicKeySpec.h>
#include <java/security/spec/EllipticCurve.h>
#include <java/security/spec/KeySpec.h>
#include <java/util/EnumSet.h>
#include <java/util/Set.h>
#include <javax/crypto/KeyAgreement.h>
#include <javax/crypto/SecretKey.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <sun/security/ssl/ECDHKeyExchange$ECDHECredentials.h>
#include <sun/security/ssl/ECDHKeyExchange.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/util/ECUtil.h>
#include <jcpp.h>

#undef KEY_AGREEMENT

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $CryptoPrimitive = ::java::security::CryptoPrimitive;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Key = ::java::security::Key;
using $KeyFactory = ::java::security::KeyFactory;
using $KeyPair = ::java::security::KeyPair;
using $KeyPairGenerator = ::java::security::KeyPairGenerator;
using $PrivateKey = ::java::security::PrivateKey;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $ECPublicKey = ::java::security::interfaces::ECPublicKey;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $ECParameterSpec = ::java::security::spec::ECParameterSpec;
using $ECPoint = ::java::security::spec::ECPoint;
using $ECPublicKeySpec = ::java::security::spec::ECPublicKeySpec;
using $KeySpec = ::java::security::spec::KeySpec;
using $EnumSet = ::java::util::EnumSet;
using $Set = ::java::util::Set;
using $KeyAgreement = ::javax::crypto::KeyAgreement;
using $SecretKey = ::javax::crypto::SecretKey;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $ECDHKeyExchange$ECDHECredentials = ::sun::security::ssl::ECDHKeyExchange$ECDHECredentials;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $ECUtil = ::sun::security::util::ECUtil;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _ECDHKeyExchange$ECDHEPossession_FieldInfo_[] = {
	{"privateKey", "Ljava/security/PrivateKey;", nullptr, $FINAL, $field(ECDHKeyExchange$ECDHEPossession, privateKey)},
	{"publicKey", "Ljava/security/interfaces/ECPublicKey;", nullptr, $FINAL, $field(ECDHKeyExchange$ECDHEPossession, publicKey)},
	{"namedGroup", "Lsun/security/ssl/NamedGroup;", nullptr, $FINAL, $field(ECDHKeyExchange$ECDHEPossession, namedGroup)},
	{}
};

$MethodInfo _ECDHKeyExchange$ECDHEPossession_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/NamedGroup;Ljava/security/SecureRandom;)V", nullptr, 0, $method(ECDHKeyExchange$ECDHEPossession, init$, void, $NamedGroup*, $SecureRandom*)},
	{"<init>", "(Lsun/security/ssl/ECDHKeyExchange$ECDHECredentials;Ljava/security/SecureRandom;)V", nullptr, 0, $method(ECDHKeyExchange$ECDHEPossession, init$, void, $ECDHKeyExchange$ECDHECredentials*, $SecureRandom*)},
	{"checkConstraints", "(Ljava/security/AlgorithmConstraints;[B)V", nullptr, 0, $method(ECDHKeyExchange$ECDHEPossession, checkConstraints, void, $AlgorithmConstraints*, $bytes*), "javax.net.ssl.SSLHandshakeException"},
	{"encode", "()[B", nullptr, $PUBLIC, $virtualMethod(ECDHKeyExchange$ECDHEPossession, encode, $bytes*)},
	{"getAgreedSecret", "(Ljava/security/PublicKey;)Ljavax/crypto/SecretKey;", nullptr, 0, $method(ECDHKeyExchange$ECDHEPossession, getAgreedSecret, $SecretKey*, $PublicKey*), "javax.net.ssl.SSLHandshakeException"},
	{"getAgreedSecret", "([B)Ljavax/crypto/SecretKey;", nullptr, 0, $method(ECDHKeyExchange$ECDHEPossession, getAgreedSecret, $SecretKey*, $bytes*), "javax.net.ssl.SSLHandshakeException"},
	{"getNamedGroup", "()Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC, $virtualMethod(ECDHKeyExchange$ECDHEPossession, getNamedGroup, $NamedGroup*)},
	{"getPrivateKey", "()Ljava/security/PrivateKey;", nullptr, $PUBLIC, $virtualMethod(ECDHKeyExchange$ECDHEPossession, getPrivateKey, $PrivateKey*)},
	{"getPublicKey", "()Ljava/security/PublicKey;", nullptr, $PUBLIC, $virtualMethod(ECDHKeyExchange$ECDHEPossession, getPublicKey, $PublicKey*)},
	{}
};

$InnerClassInfo _ECDHKeyExchange$ECDHEPossession_InnerClassesInfo_[] = {
	{"sun.security.ssl.ECDHKeyExchange$ECDHEPossession", "sun.security.ssl.ECDHKeyExchange", "ECDHEPossession", $STATIC | $FINAL},
	{}
};

$ClassInfo _ECDHKeyExchange$ECDHEPossession_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ECDHKeyExchange$ECDHEPossession",
	"java.lang.Object",
	"sun.security.ssl.NamedGroupPossession",
	_ECDHKeyExchange$ECDHEPossession_FieldInfo_,
	_ECDHKeyExchange$ECDHEPossession_MethodInfo_,
	nullptr,
	nullptr,
	_ECDHKeyExchange$ECDHEPossession_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ECDHKeyExchange"
};

$Object* allocate$ECDHKeyExchange$ECDHEPossession($Class* clazz) {
	return $of($alloc(ECDHKeyExchange$ECDHEPossession));
}

void ECDHKeyExchange$ECDHEPossession::init$($NamedGroup* namedGroup, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($KeyPairGenerator, kpg, $KeyPairGenerator::getInstance("EC"_s));
		$nc(kpg)->initialize($nc(namedGroup)->keAlgParamSpec, random);
		$var($KeyPair, kp, kpg->generateKeyPair());
		$set(this, privateKey, $nc(kp)->getPrivate());
		$set(this, publicKey, $cast($ECPublicKey, kp->getPublic()));
	} catch ($GeneralSecurityException& e) {
		$throwNew($RuntimeException, "Could not generate ECDH keypair"_s, e);
	}
	$set(this, namedGroup, namedGroup);
}

void ECDHKeyExchange$ECDHEPossession::init$($ECDHKeyExchange$ECDHECredentials* credentials, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	$var($ECParameterSpec, params, $nc($nc(credentials)->popPublicKey)->getParams());
	try {
		$var($KeyPairGenerator, kpg, $KeyPairGenerator::getInstance("EC"_s));
		$nc(kpg)->initialize(static_cast<$AlgorithmParameterSpec*>(params), random);
		$var($KeyPair, kp, kpg->generateKeyPair());
		$set(this, privateKey, $nc(kp)->getPrivate());
		$set(this, publicKey, $cast($ECPublicKey, kp->getPublic()));
	} catch ($GeneralSecurityException& e) {
		$throwNew($RuntimeException, "Could not generate ECDH keypair"_s, e);
	}
	$set(this, namedGroup, credentials->namedGroup);
}

$bytes* ECDHKeyExchange$ECDHEPossession::encode() {
	$useLocalCurrentObjectStackCache();
	$var($ECPoint, var$0, $nc(this->publicKey)->getW());
	return $ECUtil::encodePoint(var$0, $($nc($($nc(this->publicKey)->getParams()))->getCurve()));
}

$SecretKey* ECDHKeyExchange$ECDHEPossession::getAgreedSecret($PublicKey* peerPublicKey) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($KeyAgreement, ka, $KeyAgreement::getInstance("ECDH"_s));
		$nc(ka)->init(this->privateKey);
		ka->doPhase(peerPublicKey, true);
		return ka->generateSecret("TlsPremasterSecret"_s);
	} catch ($GeneralSecurityException& e) {
		$throw($cast($SSLHandshakeException, $($$new($SSLHandshakeException, "Could not generate secret"_s)->initCause(e))));
	}
	$shouldNotReachHere();
}

$SecretKey* ECDHKeyExchange$ECDHEPossession::getAgreedSecret($bytes* encodedPoint) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ECParameterSpec, params, $nc(this->publicKey)->getParams());
		$var($ECPoint, point, $ECUtil::decodePoint(encodedPoint, $($nc(params)->getCurve())));
		$var($KeyFactory, kf, $KeyFactory::getInstance("EC"_s));
		$var($ECPublicKeySpec, spec, $new($ECPublicKeySpec, point, params));
		$var($PublicKey, peerPublicKey, $nc(kf)->generatePublic(spec));
		return getAgreedSecret(peerPublicKey);
	} catch ($GeneralSecurityException& e) {
		$throw($cast($SSLHandshakeException, $($$new($SSLHandshakeException, "Could not generate secret"_s)->initCause(e))));
	} catch ($IOException& e) {
		$throw($cast($SSLHandshakeException, $($$new($SSLHandshakeException, "Could not generate secret"_s)->initCause(e))));
	}
	$shouldNotReachHere();
}

void ECDHKeyExchange$ECDHEPossession::checkConstraints($AlgorithmConstraints* constraints, $bytes* encodedPoint) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ECParameterSpec, params, $nc(this->publicKey)->getParams());
		$var($ECPoint, point, $ECUtil::decodePoint(encodedPoint, $($nc(params)->getCurve())));
		$var($ECPublicKeySpec, spec, $new($ECPublicKeySpec, point, params));
		$var($KeyFactory, kf, $KeyFactory::getInstance("EC"_s));
		$var($ECPublicKey, pubKey, $cast($ECPublicKey, $nc(kf)->generatePublic(spec)));
		$init($CryptoPrimitive);
		if (!$nc(constraints)->permits($($EnumSet::of($CryptoPrimitive::KEY_AGREEMENT)), pubKey)) {
			$throwNew($SSLHandshakeException, "ECPublicKey does not comply to algorithm constraints"_s);
		}
	} catch ($GeneralSecurityException& e) {
		$throw($cast($SSLHandshakeException, $($$new($SSLHandshakeException, "Could not generate ECPublicKey"_s)->initCause(e))));
	} catch ($IOException& e) {
		$throw($cast($SSLHandshakeException, $($$new($SSLHandshakeException, "Could not generate ECPublicKey"_s)->initCause(e))));
	}
}

$PublicKey* ECDHKeyExchange$ECDHEPossession::getPublicKey() {
	return this->publicKey;
}

$NamedGroup* ECDHKeyExchange$ECDHEPossession::getNamedGroup() {
	return this->namedGroup;
}

$PrivateKey* ECDHKeyExchange$ECDHEPossession::getPrivateKey() {
	return this->privateKey;
}

ECDHKeyExchange$ECDHEPossession::ECDHKeyExchange$ECDHEPossession() {
}

$Class* ECDHKeyExchange$ECDHEPossession::load$($String* name, bool initialize) {
	$loadClass(ECDHKeyExchange$ECDHEPossession, name, initialize, &_ECDHKeyExchange$ECDHEPossession_ClassInfo_, allocate$ECDHKeyExchange$ECDHEPossession);
	return class$;
}

$Class* ECDHKeyExchange$ECDHEPossession::class$ = nullptr;

		} // ssl
	} // security
} // sun