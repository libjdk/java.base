#include <sun/security/ssl/ServerHello$T13HelloRetryRequestConsumer.h>

#include <java/io/IOException.h>
#include <java/nio/ByteBuffer.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ClientHello$ClientHelloMessage.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLExtensions.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/ServerHello$ServerHelloMessage.h>
#include <sun/security/ssl/ServerHello.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef CH_COOKIE
#undef CH_KEY_SHARE
#undef CH_PRE_SHARED_KEY
#undef CLIENT_HELLO
#undef HANDSHAKE_FAILURE
#undef HELLO_RETRY_REQUEST
#undef MESSAGE_HASH
#undef PROTOCOL_VERSION
#undef TLS12

using $SSLExtensionArray = $Array<::sun::security::ssl::SSLExtension>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Alert = ::sun::security::ssl::Alert;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ClientHello$ClientHelloMessage = ::sun::security::ssl::ClientHello$ClientHelloMessage;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLExtensions = ::sun::security::ssl::SSLExtensions;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $ServerHello$ServerHelloMessage = ::sun::security::ssl::ServerHello$ServerHelloMessage;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _ServerHello$T13HelloRetryRequestConsumer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ServerHello$T13HelloRetryRequestConsumer, init$, void)},
	{"consume", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)V", nullptr, $PUBLIC, $virtualMethod(ServerHello$T13HelloRetryRequestConsumer, consume, void, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ServerHello$T13HelloRetryRequestConsumer_InnerClassesInfo_[] = {
	{"sun.security.ssl.ServerHello$T13HelloRetryRequestConsumer", "sun.security.ssl.ServerHello", "T13HelloRetryRequestConsumer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ServerHello$T13HelloRetryRequestConsumer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ServerHello$T13HelloRetryRequestConsumer",
	"java.lang.Object",
	"sun.security.ssl.HandshakeConsumer",
	nullptr,
	_ServerHello$T13HelloRetryRequestConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_ServerHello$T13HelloRetryRequestConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ServerHello"
};

$Object* allocate$ServerHello$T13HelloRetryRequestConsumer($Class* clazz) {
	return $of($alloc(ServerHello$T13HelloRetryRequestConsumer));
}

void ServerHello$T13HelloRetryRequestConsumer::init$() {
}

void ServerHello$T13HelloRetryRequestConsumer::consume($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, context));
	$var($ServerHello$ServerHelloMessage, helloRetryRequest, $cast($ServerHello$ServerHelloMessage, message));
	$init($ProtocolVersion);
	if ($nc(helloRetryRequest)->serverVersion != $ProtocolVersion::TLS12) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::PROTOCOL_VERSION, "The HelloRetryRequest.legacy_version is not TLS 1.2"_s)));
	}
	$set($nc(chc), negotiatedCipherSuite, $nc(helloRetryRequest)->cipherSuite);
	$init($SSLHandshake);
	$var($SSLExtensionArray, extTypes, $nc(chc->sslConfig)->getEnabledExtensions($SSLHandshake::HELLO_RETRY_REQUEST));
	$nc(helloRetryRequest->extensions)->consumeOnLoad(chc, extTypes);
	$nc(helloRetryRequest->extensions)->consumeOnTrade(chc, extTypes);
	$nc(chc->handshakeHash)->finish();
	$var($HandshakeOutStream, hos, $new($HandshakeOutStream, nullptr));
	try {
		$nc(chc->initialClientHelloMsg)->write(hos);
	} catch ($IOException& ioe) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Failed to construct message hash"_s, ioe)));
	}
	$nc(chc->handshakeHash)->deliver($(hos->toByteArray()));
	$nc(chc->handshakeHash)->determine(chc->negotiatedProtocol, chc->negotiatedCipherSuite);
	$var($bytes, clientHelloHash, $nc(chc->handshakeHash)->digest());
	int32_t hashLen = $nc(chc->negotiatedCipherSuite)->hashAlg->hashLength;
	$var($bytes, hashedClientHello, $new($bytes, 4 + hashLen));
	hashedClientHello->set(0, $SSLHandshake::MESSAGE_HASH->id);
	hashedClientHello->set(1, (int8_t)0);
	hashedClientHello->set(2, (int8_t)0);
	hashedClientHello->set(3, (int8_t)((int32_t)(hashLen & (uint32_t)255)));
	$System::arraycopy(clientHelloHash, 0, hashedClientHello, 4, hashLen);
	$nc(chc->handshakeHash)->finish();
	$nc(chc->handshakeHash)->deliver(hashedClientHello);
	int32_t hrrBodyLen = $nc(helloRetryRequest->handshakeRecord)->remaining();
	$var($bytes, hrrMessage, $new($bytes, 4 + hrrBodyLen));
	hrrMessage->set(0, $SSLHandshake::HELLO_RETRY_REQUEST->id);
	hrrMessage->set(1, (int8_t)((int32_t)((hrrBodyLen >> 16) & (uint32_t)255)));
	hrrMessage->set(2, (int8_t)((int32_t)((hrrBodyLen >> 8) & (uint32_t)255)));
	hrrMessage->set(3, (int8_t)((int32_t)(hrrBodyLen & (uint32_t)255)));
	$var($ByteBuffer, hrrBody, $nc(helloRetryRequest->handshakeRecord)->duplicate());
	$nc(hrrBody)->get(hrrMessage, 4, hrrBodyLen);
	$nc(chc->handshakeHash)->receive(hrrMessage);
	$init($SSLExtension);
	$nc($nc(chc->initialClientHelloMsg)->extensions)->reproduce(chc, $$new($SSLExtensionArray, {
		$SSLExtension::CH_COOKIE,
		$SSLExtension::CH_KEY_SHARE,
		$SSLExtension::CH_PRE_SHARED_KEY
	}));
	$SSLHandshake::CLIENT_HELLO->produce(context, helloRetryRequest);
}

ServerHello$T13HelloRetryRequestConsumer::ServerHello$T13HelloRetryRequestConsumer() {
}

$Class* ServerHello$T13HelloRetryRequestConsumer::load$($String* name, bool initialize) {
	$loadClass(ServerHello$T13HelloRetryRequestConsumer, name, initialize, &_ServerHello$T13HelloRetryRequestConsumer_ClassInfo_, allocate$ServerHello$T13HelloRetryRequestConsumer);
	return class$;
}

$Class* ServerHello$T13HelloRetryRequestConsumer::class$ = nullptr;

		} // ssl
	} // security
} // sun