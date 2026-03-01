#include <sun/security/ssl/NamedGroup$XDHScheme.h>

#include <java/security/AlgorithmConstraints.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/NamedGroup$ExceptionSupplier.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/NamedGroupPossession.h>
#include <sun/security/ssl/SSLCredentials.h>
#include <sun/security/ssl/SSLKeyAgreementGenerator.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLPossession.h>
#include <sun/security/ssl/XDHKeyExchange$XDHECredentials.h>
#include <sun/security/ssl/XDHKeyExchange$XDHEPossession.h>
#include <sun/security/ssl/XDHKeyExchange.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $SecureRandom = ::java::security::SecureRandom;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $NamedGroup$ExceptionSupplier = ::sun::security::ssl::NamedGroup$ExceptionSupplier;
using $NamedGroupPossession = ::sun::security::ssl::NamedGroupPossession;
using $SSLCredentials = ::sun::security::ssl::SSLCredentials;
using $SSLKeyAgreementGenerator = ::sun::security::ssl::SSLKeyAgreementGenerator;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLPossession = ::sun::security::ssl::SSLPossession;
using $XDHKeyExchange = ::sun::security::ssl::XDHKeyExchange;
using $XDHKeyExchange$XDHECredentials = ::sun::security::ssl::XDHKeyExchange$XDHECredentials;
using $XDHKeyExchange$XDHEPossession = ::sun::security::ssl::XDHKeyExchange$XDHEPossession;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _NamedGroup$XDHScheme_FieldInfo_[] = {
	{"instance", "Lsun/security/ssl/NamedGroup$XDHScheme;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(NamedGroup$XDHScheme, instance)},
	{}
};

$MethodInfo _NamedGroup$XDHScheme_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(NamedGroup$XDHScheme, init$, void)},
	{"createKeyDerivation", "(Lsun/security/ssl/HandshakeContext;)Lsun/security/ssl/SSLKeyDerivation;", nullptr, $PUBLIC, $virtualMethod(NamedGroup$XDHScheme, createKeyDerivation, $SSLKeyDerivation*, $HandshakeContext*), "java.io.IOException"},
	{"createPossession", "(Lsun/security/ssl/NamedGroup;Ljava/security/SecureRandom;)Lsun/security/ssl/SSLPossession;", nullptr, $PUBLIC, $virtualMethod(NamedGroup$XDHScheme, createPossession, $SSLPossession*, $NamedGroup*, $SecureRandom*)},
	{"decodeCredentials", "(Lsun/security/ssl/NamedGroup;[BLjava/security/AlgorithmConstraints;Lsun/security/ssl/NamedGroup$ExceptionSupplier;)Lsun/security/ssl/SSLCredentials;", nullptr, $PUBLIC, $virtualMethod(NamedGroup$XDHScheme, decodeCredentials, $SSLCredentials*, $NamedGroup*, $bytes*, $AlgorithmConstraints*, $NamedGroup$ExceptionSupplier*), "java.io.IOException,java.security.GeneralSecurityException"},
	{"encodePossessionPublicKey", "(Lsun/security/ssl/NamedGroupPossession;)[B", nullptr, $PUBLIC, $virtualMethod(NamedGroup$XDHScheme, encodePossessionPublicKey, $bytes*, $NamedGroupPossession*)},
	{}
};

$InnerClassInfo _NamedGroup$XDHScheme_InnerClassesInfo_[] = {
	{"sun.security.ssl.NamedGroup$XDHScheme", "sun.security.ssl.NamedGroup", "XDHScheme", $PRIVATE | $STATIC},
	{"sun.security.ssl.NamedGroup$NamedGroupScheme", "sun.security.ssl.NamedGroup", "NamedGroupScheme", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _NamedGroup$XDHScheme_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.ssl.NamedGroup$XDHScheme",
	"java.lang.Object",
	"sun.security.ssl.NamedGroup$NamedGroupScheme",
	_NamedGroup$XDHScheme_FieldInfo_,
	_NamedGroup$XDHScheme_MethodInfo_,
	nullptr,
	nullptr,
	_NamedGroup$XDHScheme_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.NamedGroup"
};

$Object* allocate$NamedGroup$XDHScheme($Class* clazz) {
	return $of($alloc(NamedGroup$XDHScheme));
}

NamedGroup$XDHScheme* NamedGroup$XDHScheme::instance = nullptr;

void NamedGroup$XDHScheme::init$() {
}

$bytes* NamedGroup$XDHScheme::encodePossessionPublicKey($NamedGroupPossession* poss) {
	return $nc(($cast($XDHKeyExchange$XDHEPossession, poss)))->encode();
}

$SSLCredentials* NamedGroup$XDHScheme::decodeCredentials($NamedGroup* ng, $bytes* encoded, $AlgorithmConstraints* constraints, $NamedGroup$ExceptionSupplier* onConstraintFail) {
	$useLocalCurrentObjectStackCache();
	$var($XDHKeyExchange$XDHECredentials, result, $XDHKeyExchange$XDHECredentials::valueOf(ng, encoded));
	checkConstraints($($nc(result)->getPublicKey()), constraints, onConstraintFail);
	return result;
}

$SSLPossession* NamedGroup$XDHScheme::createPossession($NamedGroup* ng, $SecureRandom* random) {
	return $new($XDHKeyExchange$XDHEPossession, ng, random);
}

$SSLKeyDerivation* NamedGroup$XDHScheme::createKeyDerivation($HandshakeContext* hc) {
	$init($XDHKeyExchange);
	return $nc($XDHKeyExchange::xdheKAGenerator)->createKeyDerivation(hc);
}

void clinit$NamedGroup$XDHScheme($Class* class$) {
	$assignStatic(NamedGroup$XDHScheme::instance, $new(NamedGroup$XDHScheme));
}

NamedGroup$XDHScheme::NamedGroup$XDHScheme() {
}

$Class* NamedGroup$XDHScheme::load$($String* name, bool initialize) {
	$loadClass(NamedGroup$XDHScheme, name, initialize, &_NamedGroup$XDHScheme_ClassInfo_, clinit$NamedGroup$XDHScheme, allocate$NamedGroup$XDHScheme);
	return class$;
}

$Class* NamedGroup$XDHScheme::class$ = nullptr;

		} // ssl
	} // security
} // sun