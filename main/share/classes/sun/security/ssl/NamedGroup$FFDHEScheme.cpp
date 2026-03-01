#include <sun/security/ssl/NamedGroup$FFDHEScheme.h>

#include <java/security/AlgorithmConstraints.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <sun/security/ssl/DHKeyExchange$DHECredentials.h>
#include <sun/security/ssl/DHKeyExchange$DHEPossession.h>
#include <sun/security/ssl/DHKeyExchange.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/NamedGroup$ExceptionSupplier.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/NamedGroupPossession.h>
#include <sun/security/ssl/SSLCredentials.h>
#include <sun/security/ssl/SSLKeyAgreementGenerator.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLPossession.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $SecureRandom = ::java::security::SecureRandom;
using $DHKeyExchange = ::sun::security::ssl::DHKeyExchange;
using $DHKeyExchange$DHECredentials = ::sun::security::ssl::DHKeyExchange$DHECredentials;
using $DHKeyExchange$DHEPossession = ::sun::security::ssl::DHKeyExchange$DHEPossession;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $NamedGroup$ExceptionSupplier = ::sun::security::ssl::NamedGroup$ExceptionSupplier;
using $NamedGroupPossession = ::sun::security::ssl::NamedGroupPossession;
using $SSLCredentials = ::sun::security::ssl::SSLCredentials;
using $SSLKeyAgreementGenerator = ::sun::security::ssl::SSLKeyAgreementGenerator;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLPossession = ::sun::security::ssl::SSLPossession;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _NamedGroup$FFDHEScheme_FieldInfo_[] = {
	{"instance", "Lsun/security/ssl/NamedGroup$FFDHEScheme;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(NamedGroup$FFDHEScheme, instance)},
	{}
};

$MethodInfo _NamedGroup$FFDHEScheme_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(NamedGroup$FFDHEScheme, init$, void)},
	{"createKeyDerivation", "(Lsun/security/ssl/HandshakeContext;)Lsun/security/ssl/SSLKeyDerivation;", nullptr, $PUBLIC, $virtualMethod(NamedGroup$FFDHEScheme, createKeyDerivation, $SSLKeyDerivation*, $HandshakeContext*), "java.io.IOException"},
	{"createPossession", "(Lsun/security/ssl/NamedGroup;Ljava/security/SecureRandom;)Lsun/security/ssl/SSLPossession;", nullptr, $PUBLIC, $virtualMethod(NamedGroup$FFDHEScheme, createPossession, $SSLPossession*, $NamedGroup*, $SecureRandom*)},
	{"decodeCredentials", "(Lsun/security/ssl/NamedGroup;[BLjava/security/AlgorithmConstraints;Lsun/security/ssl/NamedGroup$ExceptionSupplier;)Lsun/security/ssl/SSLCredentials;", nullptr, $PUBLIC, $virtualMethod(NamedGroup$FFDHEScheme, decodeCredentials, $SSLCredentials*, $NamedGroup*, $bytes*, $AlgorithmConstraints*, $NamedGroup$ExceptionSupplier*), "java.io.IOException,java.security.GeneralSecurityException"},
	{"encodePossessionPublicKey", "(Lsun/security/ssl/NamedGroupPossession;)[B", nullptr, $PUBLIC, $virtualMethod(NamedGroup$FFDHEScheme, encodePossessionPublicKey, $bytes*, $NamedGroupPossession*)},
	{}
};

$InnerClassInfo _NamedGroup$FFDHEScheme_InnerClassesInfo_[] = {
	{"sun.security.ssl.NamedGroup$FFDHEScheme", "sun.security.ssl.NamedGroup", "FFDHEScheme", $PRIVATE | $STATIC},
	{"sun.security.ssl.NamedGroup$NamedGroupScheme", "sun.security.ssl.NamedGroup", "NamedGroupScheme", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _NamedGroup$FFDHEScheme_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.ssl.NamedGroup$FFDHEScheme",
	"java.lang.Object",
	"sun.security.ssl.NamedGroup$NamedGroupScheme",
	_NamedGroup$FFDHEScheme_FieldInfo_,
	_NamedGroup$FFDHEScheme_MethodInfo_,
	nullptr,
	nullptr,
	_NamedGroup$FFDHEScheme_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.NamedGroup"
};

$Object* allocate$NamedGroup$FFDHEScheme($Class* clazz) {
	return $of($alloc(NamedGroup$FFDHEScheme));
}

NamedGroup$FFDHEScheme* NamedGroup$FFDHEScheme::instance = nullptr;

void NamedGroup$FFDHEScheme::init$() {
}

$bytes* NamedGroup$FFDHEScheme::encodePossessionPublicKey($NamedGroupPossession* namedGroupPossession) {
	return $nc(($cast($DHKeyExchange$DHEPossession, namedGroupPossession)))->encode();
}

$SSLCredentials* NamedGroup$FFDHEScheme::decodeCredentials($NamedGroup* ng, $bytes* encoded, $AlgorithmConstraints* constraints, $NamedGroup$ExceptionSupplier* onConstraintFail) {
	$useLocalCurrentObjectStackCache();
	$var($DHKeyExchange$DHECredentials, result, $DHKeyExchange$DHECredentials::valueOf(ng, encoded));
	checkConstraints($($nc(result)->getPublicKey()), constraints, onConstraintFail);
	return result;
}

$SSLPossession* NamedGroup$FFDHEScheme::createPossession($NamedGroup* ng, $SecureRandom* random) {
	return $new($DHKeyExchange$DHEPossession, ng, random);
}

$SSLKeyDerivation* NamedGroup$FFDHEScheme::createKeyDerivation($HandshakeContext* hc) {
	$init($DHKeyExchange);
	return $nc($DHKeyExchange::kaGenerator)->createKeyDerivation(hc);
}

void clinit$NamedGroup$FFDHEScheme($Class* class$) {
	$assignStatic(NamedGroup$FFDHEScheme::instance, $new(NamedGroup$FFDHEScheme));
}

NamedGroup$FFDHEScheme::NamedGroup$FFDHEScheme() {
}

$Class* NamedGroup$FFDHEScheme::load$($String* name, bool initialize) {
	$loadClass(NamedGroup$FFDHEScheme, name, initialize, &_NamedGroup$FFDHEScheme_ClassInfo_, clinit$NamedGroup$FFDHEScheme, allocate$NamedGroup$FFDHEScheme);
	return class$;
}

$Class* NamedGroup$FFDHEScheme::class$ = nullptr;

		} // ssl
	} // security
} // sun