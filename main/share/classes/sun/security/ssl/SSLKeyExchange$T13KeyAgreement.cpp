#include <sun/security/ssl/SSLKeyExchange$T13KeyAgreement.h>

#include <java/security/SecureRandom.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLKeyExchange.h>
#include <sun/security/ssl/SSLPossession.h>
#include <sun/security/ssl/SupportedGroupsExtension$SupportedGroups.h>
#include <jcpp.h>

using $NamedGroupArray = $Array<::sun::security::ssl::NamedGroup>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLPossession = ::sun::security::ssl::SSLPossession;
using $SupportedGroupsExtension$SupportedGroups = ::sun::security::ssl::SupportedGroupsExtension$SupportedGroups;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLKeyExchange$T13KeyAgreement_FieldInfo_[] = {
	{"namedGroup", "Lsun/security/ssl/NamedGroup;", nullptr, $PRIVATE | $FINAL, $field(SSLKeyExchange$T13KeyAgreement, namedGroup)},
	{"supportedKeyShares", "Ljava/util/Map;", "Ljava/util/Map<Lsun/security/ssl/NamedGroup;Lsun/security/ssl/SSLKeyExchange$T13KeyAgreement;>;", $STATIC | $FINAL, $staticField(SSLKeyExchange$T13KeyAgreement, supportedKeyShares)},
	{}
};

$MethodInfo _SSLKeyExchange$T13KeyAgreement_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/NamedGroup;)V", nullptr, $PRIVATE, $method(SSLKeyExchange$T13KeyAgreement, init$, void, $NamedGroup*)},
	{"createKeyDerivation", "(Lsun/security/ssl/HandshakeContext;)Lsun/security/ssl/SSLKeyDerivation;", nullptr, $PUBLIC, $virtualMethod(SSLKeyExchange$T13KeyAgreement, createKeyDerivation, $SSLKeyDerivation*, $HandshakeContext*), "java.io.IOException"},
	{"createPossession", "(Lsun/security/ssl/HandshakeContext;)Lsun/security/ssl/SSLPossession;", nullptr, $PUBLIC, $virtualMethod(SSLKeyExchange$T13KeyAgreement, createPossession, $SSLPossession*, $HandshakeContext*)},
	{"valueOf", "(Lsun/security/ssl/NamedGroup;)Lsun/security/ssl/SSLKeyExchange$T13KeyAgreement;", nullptr, $STATIC, $staticMethod(SSLKeyExchange$T13KeyAgreement, valueOf, SSLKeyExchange$T13KeyAgreement*, $NamedGroup*)},
	{}
};

$InnerClassInfo _SSLKeyExchange$T13KeyAgreement_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLKeyExchange$T13KeyAgreement", "sun.security.ssl.SSLKeyExchange", "T13KeyAgreement", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _SSLKeyExchange$T13KeyAgreement_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLKeyExchange$T13KeyAgreement",
	"java.lang.Object",
	"sun.security.ssl.SSLKeyAgreement",
	_SSLKeyExchange$T13KeyAgreement_FieldInfo_,
	_SSLKeyExchange$T13KeyAgreement_MethodInfo_,
	nullptr,
	nullptr,
	_SSLKeyExchange$T13KeyAgreement_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLKeyExchange"
};

$Object* allocate$SSLKeyExchange$T13KeyAgreement($Class* clazz) {
	return $of($alloc(SSLKeyExchange$T13KeyAgreement));
}

$Map* SSLKeyExchange$T13KeyAgreement::supportedKeyShares = nullptr;

void SSLKeyExchange$T13KeyAgreement::init$($NamedGroup* namedGroup) {
	$set(this, namedGroup, namedGroup);
}

SSLKeyExchange$T13KeyAgreement* SSLKeyExchange$T13KeyAgreement::valueOf($NamedGroup* namedGroup) {
	$init(SSLKeyExchange$T13KeyAgreement);
	return $cast(SSLKeyExchange$T13KeyAgreement, $nc(SSLKeyExchange$T13KeyAgreement::supportedKeyShares)->get(namedGroup));
}

$SSLPossession* SSLKeyExchange$T13KeyAgreement::createPossession($HandshakeContext* hc) {
	return this->namedGroup->createPossession($($nc($nc(hc)->sslContext)->getSecureRandom()));
}

$SSLKeyDerivation* SSLKeyExchange$T13KeyAgreement::createKeyDerivation($HandshakeContext* hc) {
	return this->namedGroup->createKeyDerivation(hc);
}

void clinit$SSLKeyExchange$T13KeyAgreement($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(SSLKeyExchange$T13KeyAgreement::supportedKeyShares, $new($HashMap));
	{
		{
			$init($SupportedGroupsExtension$SupportedGroups);
			$var($NamedGroupArray, arr$, $SupportedGroupsExtension$SupportedGroups::supportedNamedGroups);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$NamedGroup* namedGroup = arr$->get(i$);
				{
					$nc(SSLKeyExchange$T13KeyAgreement::supportedKeyShares)->put(namedGroup, $$new(SSLKeyExchange$T13KeyAgreement, namedGroup));
				}
			}
		}
	}
}

SSLKeyExchange$T13KeyAgreement::SSLKeyExchange$T13KeyAgreement() {
}

$Class* SSLKeyExchange$T13KeyAgreement::load$($String* name, bool initialize) {
	$loadClass(SSLKeyExchange$T13KeyAgreement, name, initialize, &_SSLKeyExchange$T13KeyAgreement_ClassInfo_, clinit$SSLKeyExchange$T13KeyAgreement, allocate$SSLKeyExchange$T13KeyAgreement);
	return class$;
}

$Class* SSLKeyExchange$T13KeyAgreement::class$ = nullptr;

		} // ssl
	} // security
} // sun