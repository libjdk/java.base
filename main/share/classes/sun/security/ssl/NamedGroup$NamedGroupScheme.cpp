#include <sun/security/ssl/NamedGroup$NamedGroupScheme.h>

#include <java/lang/Enum.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/CryptoPrimitive.h>
#include <java/security/Key.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/util/EnumSet.h>
#include <java/util/Set.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/NamedGroup$ExceptionSupplier.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/NamedGroupPossession.h>
#include <sun/security/ssl/SSLCredentials.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLPossession.h>
#include <jcpp.h>

#undef KEY_AGREEMENT

using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $CryptoPrimitive = ::java::security::CryptoPrimitive;
using $Key = ::java::security::Key;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $EnumSet = ::java::util::EnumSet;
using $Set = ::java::util::Set;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $NamedGroup$ExceptionSupplier = ::sun::security::ssl::NamedGroup$ExceptionSupplier;
using $NamedGroupPossession = ::sun::security::ssl::NamedGroupPossession;
using $SSLCredentials = ::sun::security::ssl::SSLCredentials;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLPossession = ::sun::security::ssl::SSLPossession;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _NamedGroup$NamedGroupScheme_MethodInfo_[] = {
	{"checkConstraints", "(Ljava/security/PublicKey;Ljava/security/AlgorithmConstraints;Lsun/security/ssl/NamedGroup$ExceptionSupplier;)V", nullptr, $PUBLIC, $virtualMethod(NamedGroup$NamedGroupScheme, checkConstraints, void, $PublicKey*, $AlgorithmConstraints*, $NamedGroup$ExceptionSupplier*), "javax.net.ssl.SSLException"},
	{"createKeyDerivation", "(Lsun/security/ssl/HandshakeContext;)Lsun/security/ssl/SSLKeyDerivation;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(NamedGroup$NamedGroupScheme, createKeyDerivation, $SSLKeyDerivation*, $HandshakeContext*), "java.io.IOException"},
	{"createPossession", "(Lsun/security/ssl/NamedGroup;Ljava/security/SecureRandom;)Lsun/security/ssl/SSLPossession;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(NamedGroup$NamedGroupScheme, createPossession, $SSLPossession*, $NamedGroup*, $SecureRandom*)},
	{"decodeCredentials", "(Lsun/security/ssl/NamedGroup;[BLjava/security/AlgorithmConstraints;Lsun/security/ssl/NamedGroup$ExceptionSupplier;)Lsun/security/ssl/SSLCredentials;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(NamedGroup$NamedGroupScheme, decodeCredentials, $SSLCredentials*, $NamedGroup*, $bytes*, $AlgorithmConstraints*, $NamedGroup$ExceptionSupplier*), "java.io.IOException,java.security.GeneralSecurityException"},
	{"encodePossessionPublicKey", "(Lsun/security/ssl/NamedGroupPossession;)[B", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(NamedGroup$NamedGroupScheme, encodePossessionPublicKey, $bytes*, $NamedGroupPossession*)},
	{}
};

$InnerClassInfo _NamedGroup$NamedGroupScheme_InnerClassesInfo_[] = {
	{"sun.security.ssl.NamedGroup$NamedGroupScheme", "sun.security.ssl.NamedGroup", "NamedGroupScheme", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _NamedGroup$NamedGroupScheme_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"sun.security.ssl.NamedGroup$NamedGroupScheme",
	nullptr,
	nullptr,
	nullptr,
	_NamedGroup$NamedGroupScheme_MethodInfo_,
	nullptr,
	nullptr,
	_NamedGroup$NamedGroupScheme_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.NamedGroup"
};

$Object* allocate$NamedGroup$NamedGroupScheme($Class* clazz) {
	return $of($alloc(NamedGroup$NamedGroupScheme));
}

void NamedGroup$NamedGroupScheme::checkConstraints($PublicKey* publicKey, $AlgorithmConstraints* constraints, $NamedGroup$ExceptionSupplier* onConstraintFail) {
	$init($CryptoPrimitive);
	if (!$nc(constraints)->permits($($EnumSet::of($CryptoPrimitive::KEY_AGREEMENT)), publicKey)) {
		$nc(onConstraintFail)->apply("key share entry does not comply with algorithm constraints"_s);
	}
}

$Class* NamedGroup$NamedGroupScheme::load$($String* name, bool initialize) {
	$loadClass(NamedGroup$NamedGroupScheme, name, initialize, &_NamedGroup$NamedGroupScheme_ClassInfo_, allocate$NamedGroup$NamedGroupScheme);
	return class$;
}

$Class* NamedGroup$NamedGroupScheme::class$ = nullptr;

		} // ssl
	} // security
} // sun