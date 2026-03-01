#include <sun/security/ssl/XDHKeyExchange$XDHEPossession.h>

#include <java/math/BigInteger.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/KeyPair.h>
#include <java/security/KeyPairGenerator.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/interfaces/XECPublicKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/ssl/XDHKeyExchange$1.h>
#include <sun/security/ssl/XDHKeyExchange.h>
#include <sun/security/util/ECUtil.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigInteger = ::java::math::BigInteger;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $KeyPair = ::java::security::KeyPair;
using $KeyPairGenerator = ::java::security::KeyPairGenerator;
using $PrivateKey = ::java::security::PrivateKey;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $XECPublicKey = ::java::security::interfaces::XECPublicKey;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $Utilities = ::sun::security::ssl::Utilities;
using $XDHKeyExchange$1 = ::sun::security::ssl::XDHKeyExchange$1;
using $ECUtil = ::sun::security::util::ECUtil;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _XDHKeyExchange$XDHEPossession_FieldInfo_[] = {
	{"privateKey", "Ljava/security/PrivateKey;", nullptr, $FINAL, $field(XDHKeyExchange$XDHEPossession, privateKey)},
	{"publicKey", "Ljava/security/interfaces/XECPublicKey;", nullptr, $FINAL, $field(XDHKeyExchange$XDHEPossession, publicKey)},
	{"namedGroup", "Lsun/security/ssl/NamedGroup;", nullptr, $FINAL, $field(XDHKeyExchange$XDHEPossession, namedGroup)},
	{}
};

$MethodInfo _XDHKeyExchange$XDHEPossession_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/NamedGroup;Ljava/security/SecureRandom;)V", nullptr, 0, $method(XDHKeyExchange$XDHEPossession, init$, void, $NamedGroup*, $SecureRandom*)},
	{"encode", "()[B", nullptr, $PUBLIC, $virtualMethod(XDHKeyExchange$XDHEPossession, encode, $bytes*)},
	{"getNamedGroup", "()Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC, $virtualMethod(XDHKeyExchange$XDHEPossession, getNamedGroup, $NamedGroup*)},
	{"getPrivateKey", "()Ljava/security/PrivateKey;", nullptr, $PUBLIC, $virtualMethod(XDHKeyExchange$XDHEPossession, getPrivateKey, $PrivateKey*)},
	{"getPublicKey", "()Ljava/security/PublicKey;", nullptr, $PUBLIC, $virtualMethod(XDHKeyExchange$XDHEPossession, getPublicKey, $PublicKey*)},
	{}
};

$InnerClassInfo _XDHKeyExchange$XDHEPossession_InnerClassesInfo_[] = {
	{"sun.security.ssl.XDHKeyExchange$XDHEPossession", "sun.security.ssl.XDHKeyExchange", "XDHEPossession", $STATIC | $FINAL},
	{}
};

$ClassInfo _XDHKeyExchange$XDHEPossession_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.XDHKeyExchange$XDHEPossession",
	"java.lang.Object",
	"sun.security.ssl.NamedGroupPossession",
	_XDHKeyExchange$XDHEPossession_FieldInfo_,
	_XDHKeyExchange$XDHEPossession_MethodInfo_,
	nullptr,
	nullptr,
	_XDHKeyExchange$XDHEPossession_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.XDHKeyExchange"
};

$Object* allocate$XDHKeyExchange$XDHEPossession($Class* clazz) {
	return $of($alloc(XDHKeyExchange$XDHEPossession));
}

void XDHKeyExchange$XDHEPossession::init$($NamedGroup* namedGroup, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($KeyPairGenerator, kpg, $KeyPairGenerator::getInstance($nc(namedGroup)->algorithm));
		$nc(kpg)->initialize($nc(namedGroup)->keAlgParamSpec, random);
		$var($KeyPair, kp, kpg->generateKeyPair());
		$set(this, privateKey, $nc(kp)->getPrivate());
		$set(this, publicKey, $cast($XECPublicKey, kp->getPublic()));
	} catch ($GeneralSecurityException& e) {
		$throwNew($RuntimeException, "Could not generate XDH keypair"_s, e);
	}
	$set(this, namedGroup, namedGroup);
}

$bytes* XDHKeyExchange$XDHEPossession::encode() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, uBytes, $ECUtil::trimZeroes($($nc($($nc(this->publicKey)->getU()))->toByteArray())));
	int32_t expLength = 0;
	$init($XDHKeyExchange$1);
	switch ($nc($XDHKeyExchange$1::$SwitchMap$sun$security$ssl$NamedGroup)->get((this->namedGroup)->ordinal())) {
	case 1:
		{
			expLength = 32;
			break;
		}
	case 2:
		{
			expLength = 56;
			break;
		}
	default:
		{
			$throwNew($RuntimeException, "Invalid XDH group"_s);
		}
	}
	if ($nc(uBytes)->length > expLength) {
		$throwNew($RuntimeException, "Encoded XDH key too large"_s);
	}
	if ($nc(uBytes)->length != expLength) {
		$var($bytes, tmp, $new($bytes, expLength));
		$System::arraycopy(uBytes, 0, tmp, expLength - uBytes->length, uBytes->length);
		$assign(uBytes, tmp);
	}
	$Utilities::reverseBytes(uBytes);
	return (uBytes);
}

$PublicKey* XDHKeyExchange$XDHEPossession::getPublicKey() {
	return this->publicKey;
}

$NamedGroup* XDHKeyExchange$XDHEPossession::getNamedGroup() {
	return this->namedGroup;
}

$PrivateKey* XDHKeyExchange$XDHEPossession::getPrivateKey() {
	return this->privateKey;
}

XDHKeyExchange$XDHEPossession::XDHKeyExchange$XDHEPossession() {
}

$Class* XDHKeyExchange$XDHEPossession::load$($String* name, bool initialize) {
	$loadClass(XDHKeyExchange$XDHEPossession, name, initialize, &_XDHKeyExchange$XDHEPossession_ClassInfo_, allocate$XDHKeyExchange$XDHEPossession);
	return class$;
}

$Class* XDHKeyExchange$XDHEPossession::class$ = nullptr;

		} // ssl
	} // security
} // sun