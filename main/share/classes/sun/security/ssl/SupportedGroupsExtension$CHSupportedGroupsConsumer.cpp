#include <sun/security/ssl/SupportedGroupsExtension$CHSupportedGroupsConsumer.h>

#include <java/nio/ByteBuffer.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/SupportedGroupsExtension$SupportedGroupsSpec.h>
#include <sun/security/ssl/SupportedGroupsExtension.h>
#include <jcpp.h>

#undef CH_SUPPORTED_GROUPS

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $SupportedGroupsExtension$SupportedGroupsSpec = ::sun::security::ssl::SupportedGroupsExtension$SupportedGroupsSpec;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _SupportedGroupsExtension$CHSupportedGroupsConsumer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(SupportedGroupsExtension$CHSupportedGroupsConsumer, init$, void)},
	{"consume", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $virtualMethod(SupportedGroupsExtension$CHSupportedGroupsConsumer, consume, void, $ConnectionContext*, $SSLHandshake$HandshakeMessage*, $ByteBuffer*), "java.io.IOException"},
	{}
};

$InnerClassInfo _SupportedGroupsExtension$CHSupportedGroupsConsumer_InnerClassesInfo_[] = {
	{"sun.security.ssl.SupportedGroupsExtension$CHSupportedGroupsConsumer", "sun.security.ssl.SupportedGroupsExtension", "CHSupportedGroupsConsumer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$ExtensionConsumer", "sun.security.ssl.SSLExtension", "ExtensionConsumer", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SupportedGroupsExtension$CHSupportedGroupsConsumer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SupportedGroupsExtension$CHSupportedGroupsConsumer",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$ExtensionConsumer",
	nullptr,
	_SupportedGroupsExtension$CHSupportedGroupsConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_SupportedGroupsExtension$CHSupportedGroupsConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SupportedGroupsExtension"
};

$Object* allocate$SupportedGroupsExtension$CHSupportedGroupsConsumer($Class* clazz) {
	return $of($alloc(SupportedGroupsExtension$CHSupportedGroupsConsumer));
}

void SupportedGroupsExtension$CHSupportedGroupsConsumer::init$() {
}

void SupportedGroupsExtension$CHSupportedGroupsConsumer::consume($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message, $ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, context));
	$init($SSLExtension);
	if (!$nc($nc(shc)->sslConfig)->isAvailable($SSLExtension::CH_SUPPORTED_GROUPS)) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("Ignore unavailable supported_groups extension"_s, $$new($ObjectArray, 0));
		}
		return;
	}
	$var($SupportedGroupsExtension$SupportedGroupsSpec, spec, $new($SupportedGroupsExtension$SupportedGroupsSpec, shc, buffer));
	$var($List, knownNamedGroups, $new($LinkedList));
	{
		$var($ints, arr$, spec->namedGroupsIds);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int32_t id = arr$->get(i$);
			{
				$NamedGroup* ng = $NamedGroup::valueOf(id);
				if (ng != nullptr) {
					knownNamedGroups->add(ng);
				}
			}
		}
	}
	$set($nc(shc), clientRequestedNamedGroups, knownNamedGroups);
	$nc(shc->handshakeExtensions)->put($SSLExtension::CH_SUPPORTED_GROUPS, spec);
}

SupportedGroupsExtension$CHSupportedGroupsConsumer::SupportedGroupsExtension$CHSupportedGroupsConsumer() {
}

$Class* SupportedGroupsExtension$CHSupportedGroupsConsumer::load$($String* name, bool initialize) {
	$loadClass(SupportedGroupsExtension$CHSupportedGroupsConsumer, name, initialize, &_SupportedGroupsExtension$CHSupportedGroupsConsumer_ClassInfo_, allocate$SupportedGroupsExtension$CHSupportedGroupsConsumer);
	return class$;
}

$Class* SupportedGroupsExtension$CHSupportedGroupsConsumer::class$ = nullptr;

		} // ssl
	} // security
} // sun