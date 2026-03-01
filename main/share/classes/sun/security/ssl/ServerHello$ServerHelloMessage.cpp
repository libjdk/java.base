#include <sun/security/ssl/ServerHello$ServerHelloMessage.h>

#include <java/io/OutputStream.h>
#include <java/nio/ByteBuffer.h>
#include <java/text/MessageFormat.h>
#include <java/util/HexFormat.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientHello$ClientHelloMessage.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/RandomCookie.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLExtensions.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/ServerHello.h>
#include <sun/security/ssl/SessionId.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <jcpp.h>

#undef ENGLISH
#undef HELLO_RETRY_REQUEST
#undef ILLEGAL_PARAMETER
#undef PROTOCOL_VERSION
#undef SERVER_HELLO

using $SSLExtensionArray = $Array<::sun::security::ssl::SSLExtension>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MessageFormat = ::java::text::MessageFormat;
using $HexFormat = ::java::util::HexFormat;
using $Locale = ::java::util::Locale;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $ClientHello$ClientHelloMessage = ::sun::security::ssl::ClientHello$ClientHelloMessage;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $RandomCookie = ::sun::security::ssl::RandomCookie;
using $Record = ::sun::security::ssl::Record;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLExtensions = ::sun::security::ssl::SSLExtensions;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SessionId = ::sun::security::ssl::SessionId;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _ServerHello$ServerHelloMessage_FieldInfo_[] = {
	{"serverVersion", "Lsun/security/ssl/ProtocolVersion;", nullptr, $FINAL, $field(ServerHello$ServerHelloMessage, serverVersion)},
	{"serverRandom", "Lsun/security/ssl/RandomCookie;", nullptr, $FINAL, $field(ServerHello$ServerHelloMessage, serverRandom)},
	{"sessionId", "Lsun/security/ssl/SessionId;", nullptr, $FINAL, $field(ServerHello$ServerHelloMessage, sessionId)},
	{"cipherSuite", "Lsun/security/ssl/CipherSuite;", nullptr, $FINAL, $field(ServerHello$ServerHelloMessage, cipherSuite)},
	{"compressionMethod", "B", nullptr, $FINAL, $field(ServerHello$ServerHelloMessage, compressionMethod)},
	{"extensions", "Lsun/security/ssl/SSLExtensions;", nullptr, $FINAL, $field(ServerHello$ServerHelloMessage, extensions)},
	{"clientHello", "Lsun/security/ssl/ClientHello$ClientHelloMessage;", nullptr, $FINAL, $field(ServerHello$ServerHelloMessage, clientHello)},
	{"handshakeRecord", "Ljava/nio/ByteBuffer;", nullptr, $FINAL, $field(ServerHello$ServerHelloMessage, handshakeRecord)},
	{}
};

$MethodInfo _ServerHello$ServerHelloMessage_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Lsun/security/ssl/ProtocolVersion;Lsun/security/ssl/SessionId;Lsun/security/ssl/CipherSuite;Lsun/security/ssl/RandomCookie;Lsun/security/ssl/ClientHello$ClientHelloMessage;)V", nullptr, 0, $method(ServerHello$ServerHelloMessage, init$, void, $HandshakeContext*, $ProtocolVersion*, $SessionId*, $CipherSuite*, $RandomCookie*, $ClientHello$ClientHelloMessage*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(ServerHello$ServerHelloMessage, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"handshakeType", "()Lsun/security/ssl/SSLHandshake;", nullptr, $PUBLIC, $virtualMethod(ServerHello$ServerHelloMessage, handshakeType, $SSLHandshake*)},
	{"messageLength", "()I", nullptr, $PUBLIC, $virtualMethod(ServerHello$ServerHelloMessage, messageLength, int32_t)},
	{"send", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, $PUBLIC, $virtualMethod(ServerHello$ServerHelloMessage, send, void, $HandshakeOutStream*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ServerHello$ServerHelloMessage, toString, $String*)},
	{}
};

$InnerClassInfo _ServerHello$ServerHelloMessage_InnerClassesInfo_[] = {
	{"sun.security.ssl.ServerHello$ServerHelloMessage", "sun.security.ssl.ServerHello", "ServerHelloMessage", $STATIC | $FINAL},
	{"sun.security.ssl.SSLHandshake$HandshakeMessage", "sun.security.ssl.SSLHandshake", "HandshakeMessage", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _ServerHello$ServerHelloMessage_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ServerHello$ServerHelloMessage",
	"sun.security.ssl.SSLHandshake$HandshakeMessage",
	nullptr,
	_ServerHello$ServerHelloMessage_FieldInfo_,
	_ServerHello$ServerHelloMessage_MethodInfo_,
	nullptr,
	nullptr,
	_ServerHello$ServerHelloMessage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ServerHello"
};

$Object* allocate$ServerHello$ServerHelloMessage($Class* clazz) {
	return $of($alloc(ServerHello$ServerHelloMessage));
}

void ServerHello$ServerHelloMessage::init$($HandshakeContext* context, $ProtocolVersion* serverVersion, $SessionId* sessionId, $CipherSuite* cipherSuite, $RandomCookie* serverRandom, $ClientHello$ClientHelloMessage* clientHello) {
	$SSLHandshake$HandshakeMessage::init$(context);
	$set(this, serverVersion, serverVersion);
	$set(this, serverRandom, serverRandom);
	$set(this, sessionId, sessionId);
	$set(this, cipherSuite, cipherSuite);
	this->compressionMethod = (int8_t)0;
	$set(this, extensions, $new($SSLExtensions, this));
	$set(this, clientHello, clientHello);
	$set(this, handshakeRecord, nullptr);
}

void ServerHello$ServerHelloMessage::init$($HandshakeContext* context, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(context);
	$set(this, handshakeRecord, $nc(m)->duplicate());
	int8_t major = m->get();
	int8_t minor = m->get();
	$set(this, serverVersion, $ProtocolVersion::valueOf(major, minor));
	if (this->serverVersion == nullptr) {
		$init($Alert);
		$throw($($nc($nc(context)->conContext)->fatal($Alert::PROTOCOL_VERSION, $$str({"Unsupported protocol version: "_s, $($ProtocolVersion::nameOf(major, minor))}))));
	}
	$set(this, serverRandom, $new($RandomCookie, m));
	$set(this, sessionId, $new($SessionId, $($Record::getBytes8(m))));
	try {
		$nc(this->sessionId)->checkLength(this->serverVersion->id);
	} catch ($SSLProtocolException& ex) {
		$init($Alert);
		$throw($($nc($nc(this->handshakeContext)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, static_cast<$Throwable*>(ex))));
	}
	int32_t cipherSuiteId = $Record::getInt16(m);
	$set(this, cipherSuite, $CipherSuite::valueOf(cipherSuiteId));
	if (this->cipherSuite == nullptr || !$nc(context)->isNegotiable(this->cipherSuite)) {
		$init($Alert);
		$throw($($nc(context->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Server selected improper ciphersuite "_s, $($CipherSuite::nameOf(cipherSuiteId))}))));
	}
	this->compressionMethod = m->get();
	if (this->compressionMethod != 0) {
		$init($Alert);
		$throw($($nc($nc(context)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"compression type not supported, "_s, $$str(this->compressionMethod)}))));
	}
	$var($SSLExtensionArray, supportedExtensions, nullptr);
	if ($nc(this->serverRandom)->isHelloRetryRequest()) {
		$init($SSLHandshake);
		$assign(supportedExtensions, $nc($nc(context)->sslConfig)->getEnabledExtensions($SSLHandshake::HELLO_RETRY_REQUEST));
	} else {
		$init($SSLHandshake);
		$assign(supportedExtensions, $nc($nc(context)->sslConfig)->getEnabledExtensions($SSLHandshake::SERVER_HELLO));
	}
	if (m->hasRemaining()) {
		$set(this, extensions, $new($SSLExtensions, this, m, supportedExtensions));
	} else {
		$set(this, extensions, $new($SSLExtensions, this));
	}
	$set(this, clientHello, nullptr);
}

$SSLHandshake* ServerHello$ServerHelloMessage::handshakeType() {
	$init($SSLHandshake);
	return $nc(this->serverRandom)->isHelloRetryRequest() ? $SSLHandshake::HELLO_RETRY_REQUEST : $SSLHandshake::SERVER_HELLO;
}

int32_t ServerHello$ServerHelloMessage::messageLength() {
	int32_t var$0 = 38 + $nc(this->sessionId)->length();
	return var$0 + $nc(this->extensions)->length();
}

void ServerHello$ServerHelloMessage::send($HandshakeOutStream* hos) {
	$nc(hos)->putInt8(this->serverVersion->major);
	hos->putInt8(this->serverVersion->minor);
	hos->write($nc(this->serverRandom)->randomBytes);
	hos->putBytes8($($nc(this->sessionId)->getId()));
	hos->putInt8((int32_t)((this->cipherSuite->id >> 8) & (uint32_t)255));
	hos->putInt8((int32_t)(this->cipherSuite->id & (uint32_t)255));
	hos->putInt8(this->compressionMethod);
	$nc(this->extensions)->send(hos);
}

$String* ServerHello$ServerHelloMessage::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"{0}\": \'{\'\n  \"server version\"      : \"{1}\",\n  \"random\"              : \"{2}\",\n  \"session id\"          : \"{3}\",\n  \"cipher suite\"        : \"{4}\",\n  \"compression methods\" : \"{5}\",\n  \"extensions\"          : [\n{6}\n  ]\n\'}\'"_s, $Locale::ENGLISH));
	$var($ObjectArray, messageFields, $new($ObjectArray, {
		$nc(this->serverRandom)->isHelloRetryRequest() ? $of("HelloRetryRequest"_s) : $of("ServerHello"_s),
		$of(this->serverVersion->name$),
		$($of($Utilities::toHexString($nc(this->serverRandom)->randomBytes))),
		$($of($nc(this->sessionId)->toString())),
		$of($$str({this->cipherSuite->name$, "("_s, $($Utilities::byte16HexString(this->cipherSuite->id)), ")"_s})),
		$($of($nc($($HexFormat::of()))->toHexDigits(this->compressionMethod))),
		$($of($Utilities::indent($($nc(this->extensions)->toString()), "    "_s)))
	}));
	return messageFormat->format(messageFields);
}

ServerHello$ServerHelloMessage::ServerHello$ServerHelloMessage() {
}

$Class* ServerHello$ServerHelloMessage::load$($String* name, bool initialize) {
	$loadClass(ServerHello$ServerHelloMessage, name, initialize, &_ServerHello$ServerHelloMessage_ClassInfo_, allocate$ServerHello$ServerHelloMessage);
	return class$;
}

$Class* ServerHello$ServerHelloMessage::class$ = nullptr;

		} // ssl
	} // security
} // sun