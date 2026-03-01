#include <sun/security/ssl/ClientHello$ClientHelloProducer.h>

#include <java/io/IOException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/ChangeCipherSpec.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ClientHello$1.h>
#include <sun/security/ssl/ClientHello$ClientHelloMessage.h>
#include <sun/security/ssl/ClientHello.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/ContentType.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLConsumer.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef CHANGE_CIPHER_SPEC
#undef HANDSHAKE_FAILURE
#undef HELLO_VERIFY_REQUEST
#undef NONE
#undef SERVER_HELLO

using $IOException = ::java::io::IOException;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Alert = ::sun::security::ssl::Alert;
using $ChangeCipherSpec = ::sun::security::ssl::ChangeCipherSpec;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ClientHello$1 = ::sun::security::ssl::ClientHello$1;
using $ClientHello$ClientHelloMessage = ::sun::security::ssl::ClientHello$ClientHelloMessage;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $ContentType = ::sun::security::ssl::ContentType;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _ClientHello$ClientHelloProducer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ClientHello$ClientHelloProducer, init$, void)},
	{"produce", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PUBLIC, $virtualMethod(ClientHello$ClientHelloProducer, produce, $bytes*, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ClientHello$ClientHelloProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.ClientHello$ClientHelloProducer", "sun.security.ssl.ClientHello", "ClientHelloProducer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ClientHello$ClientHelloProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ClientHello$ClientHelloProducer",
	"java.lang.Object",
	"sun.security.ssl.HandshakeProducer",
	nullptr,
	_ClientHello$ClientHelloProducer_MethodInfo_,
	nullptr,
	nullptr,
	_ClientHello$ClientHelloProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ClientHello"
};

$Object* allocate$ClientHello$ClientHelloProducer($Class* clazz) {
	return $of($alloc(ClientHello$ClientHelloProducer));
}

void ClientHello$ClientHelloProducer::init$() {
}

$bytes* ClientHello$ClientHelloProducer::produce($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, context));
	$SSLHandshake* ht = $nc(message)->handshakeType();
	if (ht == nullptr) {
		$throwNew($UnsupportedOperationException, "Not supported yet."_s);
	}
	$init($ClientHello$1);
	{
		$var($ProtocolVersion, minimumVersion, nullptr)
		switch ($nc($ClientHello$1::$SwitchMap$sun$security$ssl$SSLHandshake)->get($nc((ht))->ordinal())) {
		case 1:
			{
				try {
					$nc(chc)->kickstart();
				} catch ($IOException& ioe) {
					$init($Alert);
					$throw($($nc($nc(chc)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, static_cast<$Throwable*>(ioe))));
				}
				return nullptr;
			}
		case 2:
			{
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
					$SSLLogger::fine("Produced ClientHello(cookie) handshake message"_s, $$new($ObjectArray, {$of($nc(chc)->initialClientHelloMsg)}));
				}
				$nc($nc(chc)->initialClientHelloMsg)->write(chc->handshakeOutput);
				$nc($nc(chc)->handshakeOutput)->flush();
				$init($SSLHandshake);
				$nc($nc(chc)->handshakeConsumers)->put($($Byte::valueOf($SSLHandshake::SERVER_HELLO->id)), $SSLHandshake::SERVER_HELLO);
				$init($ProtocolVersion);
				$assign(minimumVersion, $ProtocolVersion::NONE);
				{
					$var($Iterator, i$, $nc($nc(chc)->activeProtocols)->iterator());
					for (; $nc(i$)->hasNext();) {
						$ProtocolVersion* pv = $cast($ProtocolVersion, i$->next());
						{
							if (minimumVersion == $ProtocolVersion::NONE || $nc(pv)->compare(minimumVersion) < 0) {
								minimumVersion = pv;
							}
						}
					}
				}
				bool var$0 = $nc($nc(chc)->sslContext)->isDTLS();
				if (var$0 && !$nc(minimumVersion)->useTLS13PlusSpec()) {
					$init($SSLHandshake);
					$nc(chc->handshakeConsumers)->put($($Byte::valueOf($SSLHandshake::HELLO_VERIFY_REQUEST->id)), $SSLHandshake::HELLO_VERIFY_REQUEST);
				}
				return nullptr;
			}
		case 3:
			{
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
					$SSLLogger::fine("Produced ClientHello(HRR) handshake message"_s, $$new($ObjectArray, {$of($nc(chc)->initialClientHelloMsg)}));
				}
				$nc($nc(chc)->initialClientHelloMsg)->write(chc->handshakeOutput);
				$nc($nc(chc)->handshakeOutput)->flush();
				$init($ContentType);
				$init($ChangeCipherSpec);
				$nc($nc($nc(chc)->conContext)->consumers)->putIfAbsent($($Byte::valueOf($ContentType::CHANGE_CIPHER_SPEC->id)), $ChangeCipherSpec::t13Consumer);
				$init($SSLHandshake);
				$nc($nc(chc)->handshakeConsumers)->put($($Byte::valueOf($SSLHandshake::SERVER_HELLO->id)), $SSLHandshake::SERVER_HELLO);
				return nullptr;
			}
		default:
			{
				$throwNew($UnsupportedOperationException, "Not supported yet."_s);
			}
		}
	}
}

ClientHello$ClientHelloProducer::ClientHello$ClientHelloProducer() {
}

$Class* ClientHello$ClientHelloProducer::load$($String* name, bool initialize) {
	$loadClass(ClientHello$ClientHelloProducer, name, initialize, &_ClientHello$ClientHelloProducer_ClassInfo_, allocate$ClientHello$ClientHelloProducer);
	return class$;
}

$Class* ClientHello$ClientHelloProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun