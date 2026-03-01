#include <sun/security/ssl/PreSharedKeyExtension$CHPreSharedKeyConsumer.h>

#include <java/io/IOException.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLSessionContext.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/ClientHello$ClientHelloMessage.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/PreSharedKeyExtension$CHPreSharedKeySpec.h>
#include <sun/security/ssl/PreSharedKeyExtension$PskIdentity.h>
#include <sun/security/ssl/PreSharedKeyExtension$SHPreSharedKeySpec.h>
#include <sun/security/ssl/PreSharedKeyExtension.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSessionContextImpl.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/SessionId.h>
#include <sun/security/ssl/SessionTicketExtension$SessionTicketSpec.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef CH_PRE_SHARED_KEY
#undef ILLEGAL_PARAMETER
#undef MAX_LENGTH
#undef PSK_KEY_EXCHANGE_MODES
#undef SH_PRE_SHARED_KEY

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Alert = ::sun::security::ssl::Alert;
using $ClientHello$ClientHelloMessage = ::sun::security::ssl::ClientHello$ClientHelloMessage;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $PreSharedKeyExtension = ::sun::security::ssl::PreSharedKeyExtension;
using $PreSharedKeyExtension$CHPreSharedKeySpec = ::sun::security::ssl::PreSharedKeyExtension$CHPreSharedKeySpec;
using $PreSharedKeyExtension$PskIdentity = ::sun::security::ssl::PreSharedKeyExtension$PskIdentity;
using $PreSharedKeyExtension$SHPreSharedKeySpec = ::sun::security::ssl::PreSharedKeyExtension$SHPreSharedKeySpec;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSessionContextImpl = ::sun::security::ssl::SSLSessionContextImpl;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $SessionId = ::sun::security::ssl::SessionId;
using $SessionTicketExtension$SessionTicketSpec = ::sun::security::ssl::SessionTicketExtension$SessionTicketSpec;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _PreSharedKeyExtension$CHPreSharedKeyConsumer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(PreSharedKeyExtension$CHPreSharedKeyConsumer, init$, void)},
	{"consume", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $virtualMethod(PreSharedKeyExtension$CHPreSharedKeyConsumer, consume, void, $ConnectionContext*, $SSLHandshake$HandshakeMessage*, $ByteBuffer*), "java.io.IOException"},
	{}
};

$InnerClassInfo _PreSharedKeyExtension$CHPreSharedKeyConsumer_InnerClassesInfo_[] = {
	{"sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyConsumer", "sun.security.ssl.PreSharedKeyExtension", "CHPreSharedKeyConsumer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$ExtensionConsumer", "sun.security.ssl.SSLExtension", "ExtensionConsumer", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _PreSharedKeyExtension$CHPreSharedKeyConsumer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyConsumer",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$ExtensionConsumer",
	nullptr,
	_PreSharedKeyExtension$CHPreSharedKeyConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_PreSharedKeyExtension$CHPreSharedKeyConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.PreSharedKeyExtension"
};

$Object* allocate$PreSharedKeyExtension$CHPreSharedKeyConsumer($Class* clazz) {
	return $of($alloc(PreSharedKeyExtension$CHPreSharedKeyConsumer));
}

void PreSharedKeyExtension$CHPreSharedKeyConsumer::init$() {
}

void PreSharedKeyExtension$CHPreSharedKeyConsumer::consume($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message, $ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	$var($ClientHello$ClientHelloMessage, clientHello, $cast($ClientHello$ClientHelloMessage, message));
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, context));
	$init($SSLExtension);
	if (!$nc($nc(shc)->sslConfig)->isAvailable($SSLExtension::CH_PRE_SHARED_KEY)) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("Ignore unavailable pre_shared_key extension"_s, $$new($ObjectArray, 0));
		}
		return;
	}
	$var($PreSharedKeyExtension$CHPreSharedKeySpec, pskSpec, $new($PreSharedKeyExtension$CHPreSharedKeySpec, static_cast<$HandshakeContext*>(shc), buffer));
	if (!$nc($nc(shc)->handshakeExtensions)->containsKey($SSLExtension::PSK_KEY_EXCHANGE_MODES)) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Client sent PSK but not PSK modes, or the PSK extension is not the last extension"_s)));
	}
	int32_t var$0 = $nc(pskSpec->identities)->size();
	if (var$0 != $nc(pskSpec->binders)->size()) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "PSK extension has incorrect number of binders"_s)));
	}
	if ($nc(shc)->isResumption) {
		$var($SSLSessionContextImpl, sessionCache, $cast($SSLSessionContextImpl, $nc(shc->sslContext)->engineGetServerSessionContext()));
		int32_t idIndex = 0;
		$var($SSLSessionImpl, s, nullptr);
		{
			$var($Iterator, i$, $nc(pskSpec->identities)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($PreSharedKeyExtension$PskIdentity, requestedId, $cast($PreSharedKeyExtension$PskIdentity, i$->next()));
				{
					if ($nc($nc(requestedId)->identity)->length == $SessionId::MAX_LENGTH) {
						$assign(s, $nc(sessionCache)->pull(requestedId->identity));
					}
					if (s == nullptr && $nc($nc(requestedId)->identity)->length > $SessionId::MAX_LENGTH && $nc(sessionCache)->statelessEnabled()) {
						$var($ByteBuffer, b, $$new($SessionTicketExtension$SessionTicketSpec, static_cast<$HandshakeContext*>(shc), requestedId->identity)->decrypt(shc));
						if (b != nullptr) {
							try {
								$assign(s, $new($SSLSessionImpl, static_cast<$HandshakeContext*>(shc), b));
							} catch ($IOException& e) {
								$assign(s, nullptr);
							} catch ($RuntimeException& e) {
								$assign(s, nullptr);
							}
						}
						if (b == nullptr || s == nullptr) {
							$init($SSLLogger);
							if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
								$SSLLogger::fine("Stateless session ticket invalid"_s, $$new($ObjectArray, 0));
							}
						}
					}
					if (s != nullptr && $PreSharedKeyExtension::canRejoin(clientHello, shc, s)) {
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
							$SSLLogger::fine("Resuming session: "_s, $$new($ObjectArray, {$of(s)}));
						}
						$set(shc, resumingSession, s);
						$nc(shc->handshakeExtensions)->put($SSLExtension::SH_PRE_SHARED_KEY, $$new($PreSharedKeyExtension$SHPreSharedKeySpec, idIndex));
						break;
					}
					++idIndex;
				}
			}
		}
		if (idIndex == $nc(pskSpec->identities)->size()) {
			shc->isResumption = false;
			$set(shc, resumingSession, nullptr);
		}
	}
	$nc($nc(shc)->handshakeExtensions)->put($SSLExtension::CH_PRE_SHARED_KEY, pskSpec);
}

PreSharedKeyExtension$CHPreSharedKeyConsumer::PreSharedKeyExtension$CHPreSharedKeyConsumer() {
}

$Class* PreSharedKeyExtension$CHPreSharedKeyConsumer::load$($String* name, bool initialize) {
	$loadClass(PreSharedKeyExtension$CHPreSharedKeyConsumer, name, initialize, &_PreSharedKeyExtension$CHPreSharedKeyConsumer_ClassInfo_, allocate$PreSharedKeyExtension$CHPreSharedKeyConsumer);
	return class$;
}

$Class* PreSharedKeyExtension$CHPreSharedKeyConsumer::class$ = nullptr;

		} // ssl
	} // security
} // sun