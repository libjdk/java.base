#include <sun/security/ssl/ClientHello$ClientHelloMessage.h>

#include <java/io/IOException.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/SecureRandom.h>
#include <java/text/MessageFormat.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientHello.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/RandomCookie.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLExtensions.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SessionId.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <jcpp.h>

#undef CH_PRE_SHARED_KEY
#undef CLIENT_HELLO
#undef ENGLISH
#undef ILLEGAL_PARAMETER
#undef NULL_COMPRESSION

using $SSLExtensionArray = $Array<::sun::security::ssl::SSLExtension>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $SecureRandom = ::java::security::SecureRandom;
using $MessageFormat = ::java::text::MessageFormat;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $RandomCookie = ::sun::security::ssl::RandomCookie;
using $Record = ::sun::security::ssl::Record;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLExtensions = ::sun::security::ssl::SSLExtensions;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SessionId = ::sun::security::ssl::SessionId;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _ClientHello$ClientHelloMessage_FieldInfo_[] = {
	{"isDTLS", "Z", nullptr, $PRIVATE | $FINAL, $field(ClientHello$ClientHelloMessage, isDTLS)},
	{"clientVersion", "I", nullptr, $FINAL, $field(ClientHello$ClientHelloMessage, clientVersion)},
	{"clientRandom", "Lsun/security/ssl/RandomCookie;", nullptr, $FINAL, $field(ClientHello$ClientHelloMessage, clientRandom)},
	{"sessionId", "Lsun/security/ssl/SessionId;", nullptr, $FINAL, $field(ClientHello$ClientHelloMessage, sessionId)},
	{"cookie", "[B", nullptr, $PRIVATE, $field(ClientHello$ClientHelloMessage, cookie)},
	{"cipherSuiteIds", "[I", nullptr, $FINAL, $field(ClientHello$ClientHelloMessage, cipherSuiteIds)},
	{"cipherSuites", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", $FINAL, $field(ClientHello$ClientHelloMessage, cipherSuites)},
	{"compressionMethod", "[B", nullptr, $FINAL, $field(ClientHello$ClientHelloMessage, compressionMethod)},
	{"extensions", "Lsun/security/ssl/SSLExtensions;", nullptr, $FINAL, $field(ClientHello$ClientHelloMessage, extensions)},
	{"NULL_COMPRESSION", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ClientHello$ClientHelloMessage, NULL_COMPRESSION)},
	{}
};

$MethodInfo _ClientHello$ClientHelloMessage_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;ILsun/security/ssl/SessionId;Ljava/util/List;Ljava/security/SecureRandom;)V", "(Lsun/security/ssl/HandshakeContext;ILsun/security/ssl/SessionId;Ljava/util/List<Lsun/security/ssl/CipherSuite;>;Ljava/security/SecureRandom;)V", 0, $method(ClientHello$ClientHelloMessage, init$, void, $HandshakeContext*, int32_t, $SessionId*, $List*, $SecureRandom*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;[Lsun/security/ssl/SSLExtension;)V", nullptr, 0, $method(ClientHello$ClientHelloMessage, init$, void, $HandshakeContext*, $ByteBuffer*, $SSLExtensionArray*), "java.io.IOException"},
	{"getCipherSuiteIds", "(Ljava/util/List;)[I", "(Ljava/util/List<Lsun/security/ssl/CipherSuite;>;)[I", $PRIVATE | $STATIC, $staticMethod(ClientHello$ClientHelloMessage, getCipherSuiteIds, $ints*, $List*)},
	{"getCipherSuiteNames", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $method(ClientHello$ClientHelloMessage, getCipherSuiteNames, $List*)},
	{"getCipherSuites", "([I)Ljava/util/List;", "([I)Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", $PRIVATE | $STATIC, $staticMethod(ClientHello$ClientHelloMessage, getCipherSuites, $List*, $ints*)},
	{"getEncodedCipherSuites", "()[B", nullptr, $PRIVATE, $method(ClientHello$ClientHelloMessage, getEncodedCipherSuites, $bytes*)},
	{"getHeaderBytes", "()[B", nullptr, 0, $method(ClientHello$ClientHelloMessage, getHeaderBytes, $bytes*)},
	{"getHelloCookieBytes", "()[B", nullptr, 0, $method(ClientHello$ClientHelloMessage, getHelloCookieBytes, $bytes*)},
	{"handshakeType", "()Lsun/security/ssl/SSLHandshake;", nullptr, $PUBLIC, $virtualMethod(ClientHello$ClientHelloMessage, handshakeType, $SSLHandshake*)},
	{"messageLength", "()I", nullptr, $PUBLIC, $virtualMethod(ClientHello$ClientHelloMessage, messageLength, int32_t)},
	{"readPartial", "(Lsun/security/ssl/TransportContext;Ljava/nio/ByteBuffer;)V", nullptr, $STATIC, $staticMethod(ClientHello$ClientHelloMessage, readPartial, void, $TransportContext*, $ByteBuffer*), "java.io.IOException"},
	{"send", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, $PUBLIC, $virtualMethod(ClientHello$ClientHelloMessage, send, void, $HandshakeOutStream*), "java.io.IOException"},
	{"sendCore", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, 0, $method(ClientHello$ClientHelloMessage, sendCore, void, $HandshakeOutStream*), "java.io.IOException"},
	{"setHelloCookie", "([B)V", nullptr, 0, $method(ClientHello$ClientHelloMessage, setHelloCookie, void, $bytes*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ClientHello$ClientHelloMessage, toString, $String*)},
	{}
};

$InnerClassInfo _ClientHello$ClientHelloMessage_InnerClassesInfo_[] = {
	{"sun.security.ssl.ClientHello$ClientHelloMessage", "sun.security.ssl.ClientHello", "ClientHelloMessage", $STATIC | $FINAL},
	{"sun.security.ssl.SSLHandshake$HandshakeMessage", "sun.security.ssl.SSLHandshake", "HandshakeMessage", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _ClientHello$ClientHelloMessage_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ClientHello$ClientHelloMessage",
	"sun.security.ssl.SSLHandshake$HandshakeMessage",
	nullptr,
	_ClientHello$ClientHelloMessage_FieldInfo_,
	_ClientHello$ClientHelloMessage_MethodInfo_,
	nullptr,
	nullptr,
	_ClientHello$ClientHelloMessage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ClientHello"
};

$Object* allocate$ClientHello$ClientHelloMessage($Class* clazz) {
	return $of($alloc(ClientHello$ClientHelloMessage));
}

$bytes* ClientHello$ClientHelloMessage::NULL_COMPRESSION = nullptr;

void ClientHello$ClientHelloMessage::init$($HandshakeContext* handshakeContext, int32_t clientVersion, $SessionId* sessionId, $List* cipherSuites, $SecureRandom* generator) {
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	this->isDTLS = $nc($nc(handshakeContext)->sslContext)->isDTLS();
	this->clientVersion = clientVersion;
	$set(this, clientRandom, $new($RandomCookie, generator));
	$set(this, sessionId, sessionId);
	if (this->isDTLS) {
		$set(this, cookie, $new($bytes, 0));
	} else {
		$set(this, cookie, nullptr);
	}
	$set(this, cipherSuites, cipherSuites);
	$set(this, cipherSuiteIds, getCipherSuiteIds(cipherSuites));
	$set(this, extensions, $new($SSLExtensions, this));
	$set(this, compressionMethod, ClientHello$ClientHelloMessage::NULL_COMPRESSION);
}

void ClientHello$ClientHelloMessage::readPartial($TransportContext* tc, $ByteBuffer* m) {
	$init(ClientHello$ClientHelloMessage);
	$useLocalCurrentObjectStackCache();
	bool isDTLS = $nc($nc(tc)->sslContext)->isDTLS();
	$Record::getInt16(m);
	$new($RandomCookie, m);
	$Record::getBytes8(m);
	if (isDTLS) {
		$Record::getBytes8(m);
	}
	$Record::getBytes16(m);
	$Record::getBytes8(m);
	if ($nc(m)->remaining() >= 2) {
		int32_t remaining = $Record::getInt16(m);
		while (remaining > 0) {
			int32_t id = $Record::getInt16(m);
			int32_t extLen = $Record::getInt16(m);
			remaining -= extLen + 4;
			$init($SSLExtension);
			if (id == $SSLExtension::CH_PRE_SHARED_KEY->id) {
				if (remaining > 0) {
					$init($Alert);
					$throw($(tc->fatal($Alert::ILLEGAL_PARAMETER, "pre_shared_key extension is not last"_s)));
				}
				$Record::getBytes16(m);
				return;
			} else {
				m->position(m->position() + extLen);
			}
		}
	}
}

void ClientHello$ClientHelloMessage::init$($HandshakeContext* handshakeContext, $ByteBuffer* m, $SSLExtensionArray* supportedExtensions) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	this->isDTLS = $nc($nc(handshakeContext)->sslContext)->isDTLS();
	int32_t var$0 = (((int32_t)($nc(m)->get() & (uint32_t)255)) << 8);
	this->clientVersion = var$0 | ((int32_t)(m->get() & (uint32_t)255));
	$set(this, clientRandom, $new($RandomCookie, m));
	$set(this, sessionId, $new($SessionId, $($Record::getBytes8(m))));
	try {
		$nc(this->sessionId)->checkLength(this->clientVersion);
	} catch ($SSLProtocolException& ex) {
		$init($Alert);
		$throw($($nc(handshakeContext->conContext)->fatal($Alert::ILLEGAL_PARAMETER, static_cast<$Throwable*>(ex))));
	}
	if (this->isDTLS) {
		$set(this, cookie, $Record::getBytes8(m));
	} else {
		$set(this, cookie, nullptr);
	}
	$var($bytes, encodedIds, $Record::getBytes16(m));
	if ($nc(encodedIds)->length == 0 || ((int32_t)($nc(encodedIds)->length & (uint32_t)1)) != 0) {
		$init($Alert);
		$throw($($nc(handshakeContext->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Invalid ClientHello message"_s)));
	}
	$set(this, cipherSuiteIds, $new($ints, $nc(encodedIds)->length >> 1));
	{
		int32_t i = 0;
		int32_t j = 0;
		for (; i < encodedIds->length; ++i, ++j) {
			int32_t var$1 = (((int32_t)(encodedIds->get(i++) & (uint32_t)255)) << 8);
			$nc(this->cipherSuiteIds)->set(j, var$1 | ((int32_t)(encodedIds->get(i) & (uint32_t)255)));
		}
	}
	$set(this, cipherSuites, getCipherSuites(this->cipherSuiteIds));
	$set(this, compressionMethod, $Record::getBytes8(m));
	if (m->hasRemaining()) {
		$set(this, extensions, $new($SSLExtensions, this, m, supportedExtensions));
	} else {
		$set(this, extensions, $new($SSLExtensions, this));
	}
}

void ClientHello$ClientHelloMessage::setHelloCookie($bytes* cookie) {
	$set(this, cookie, cookie);
}

$bytes* ClientHello$ClientHelloMessage::getHelloCookieBytes() {
	$useLocalCurrentObjectStackCache();
	$var($HandshakeOutStream, hos, $new($HandshakeOutStream, nullptr));
	try {
		hos->putInt8((int8_t)((int32_t)(((int32_t)((uint32_t)this->clientVersion >> 8)) & (uint32_t)255)));
		hos->putInt8((int8_t)((int32_t)(this->clientVersion & (uint32_t)255)));
		hos->write($nc(this->clientRandom)->randomBytes, 0, 32);
		hos->putBytes8($($nc(this->sessionId)->getId()));
		hos->putBytes16($(getEncodedCipherSuites()));
		hos->putBytes8(this->compressionMethod);
		$nc(this->extensions)->send(hos);
	} catch ($IOException& ioe) {
	}
	return hos->toByteArray();
}

$bytes* ClientHello$ClientHelloMessage::getHeaderBytes() {
	$useLocalCurrentObjectStackCache();
	$var($HandshakeOutStream, hos, $new($HandshakeOutStream, nullptr));
	try {
		hos->putInt8((int8_t)((int32_t)(((int32_t)((uint32_t)this->clientVersion >> 8)) & (uint32_t)255)));
		hos->putInt8((int8_t)((int32_t)(this->clientVersion & (uint32_t)255)));
		hos->write($nc(this->clientRandom)->randomBytes, 0, 32);
		hos->putBytes8($($nc(this->sessionId)->getId()));
		hos->putBytes16($(getEncodedCipherSuites()));
		hos->putBytes8(this->compressionMethod);
	} catch ($IOException& ioe) {
	}
	return hos->toByteArray();
}

$ints* ClientHello$ClientHelloMessage::getCipherSuiteIds($List* cipherSuites) {
	$init(ClientHello$ClientHelloMessage);
	$useLocalCurrentObjectStackCache();
	if (cipherSuites != nullptr) {
		$var($ints, ids, $new($ints, cipherSuites->size()));
		int32_t i = 0;
		{
			$var($Iterator, i$, cipherSuites->iterator());
			for (; $nc(i$)->hasNext();) {
				$CipherSuite* cipherSuite = $cast($CipherSuite, i$->next());
				{
					ids->set(i++, $nc(cipherSuite)->id);
				}
			}
		}
		return ids;
	}
	return $new($ints, 0);
}

$List* ClientHello$ClientHelloMessage::getCipherSuites($ints* ids) {
	$init(ClientHello$ClientHelloMessage);
	$useLocalCurrentObjectStackCache();
	$var($List, cipherSuites, $new($LinkedList));
	{
		$var($ints, arr$, ids);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int32_t id = arr$->get(i$);
			{
				$CipherSuite* cipherSuite = $CipherSuite::valueOf(id);
				if (cipherSuite != nullptr) {
					cipherSuites->add(cipherSuite);
				}
			}
		}
	}
	return $Collections::unmodifiableList(cipherSuites);
}

$List* ClientHello$ClientHelloMessage::getCipherSuiteNames() {
	$useLocalCurrentObjectStackCache();
	$var($List, names, $new($LinkedList));
	{
		$var($ints, arr$, this->cipherSuiteIds);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int32_t id = arr$->get(i$);
			{
				$var($String, var$1, $$str({$($CipherSuite::nameOf(id)), "("_s}));
				$var($String, var$0, $$concat(var$1, $($Utilities::byte16HexString(id))));
				names->add($$concat(var$0, ")"_s));
			}
		}
	}
	return names;
}

$bytes* ClientHello$ClientHelloMessage::getEncodedCipherSuites() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encoded, $new($bytes, $nc(this->cipherSuiteIds)->length << 1));
	int32_t i = 0;
	{
		$var($ints, arr$, this->cipherSuiteIds);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int32_t id = arr$->get(i$);
			{
				encoded->set(i++, (int8_t)(id >> 8));
				encoded->set(i++, (int8_t)id);
			}
		}
	}
	return encoded;
}

$SSLHandshake* ClientHello$ClientHelloMessage::handshakeType() {
	$init($SSLHandshake);
	return $SSLHandshake::CLIENT_HELLO;
}

int32_t ClientHello$ClientHelloMessage::messageLength() {
	int32_t var$0 = (2 + 32 + 1 + 2 + 1 + $nc(this->sessionId)->length() + (this->isDTLS ? (1 + $nc(this->cookie)->length) : 0) + ($nc(this->cipherSuiteIds)->length * 2) + $nc(this->compressionMethod)->length);
	return var$0 + $nc(this->extensions)->length();
}

void ClientHello$ClientHelloMessage::send($HandshakeOutStream* hos) {
	sendCore(hos);
	$nc(this->extensions)->send(hos);
}

void ClientHello$ClientHelloMessage::sendCore($HandshakeOutStream* hos) {
	$useLocalCurrentObjectStackCache();
	$nc(hos)->putInt8((int8_t)((int32_t)((uint32_t)this->clientVersion >> 8)));
	hos->putInt8((int8_t)this->clientVersion);
	hos->write($nc(this->clientRandom)->randomBytes, 0, 32);
	hos->putBytes8($($nc(this->sessionId)->getId()));
	if (this->isDTLS) {
		hos->putBytes8(this->cookie);
	}
	hos->putBytes16($(getEncodedCipherSuites()));
	hos->putBytes8(this->compressionMethod);
}

$String* ClientHello$ClientHelloMessage::toString() {
	$useLocalCurrentObjectStackCache();
	if (this->isDTLS) {
		$init($Locale);
		$var($MessageFormat, messageFormat, $new($MessageFormat, "\"ClientHello\": \'{\'\n  \"client version\"      : \"{0}\",\n  \"random\"              : \"{1}\",\n  \"session id\"          : \"{2}\",\n  \"cookie\"              : \"{3}\",\n  \"cipher suites\"       : \"{4}\",\n  \"compression methods\" : \"{5}\",\n  \"extensions\"          : [\n{6}\n  ]\n\'}\'"_s, $Locale::ENGLISH));
		$var($ObjectArray, messageFields, $new($ObjectArray, {
			$($of($ProtocolVersion::nameOf(this->clientVersion))),
			$($of($Utilities::toHexString($nc(this->clientRandom)->randomBytes))),
			$($of($nc(this->sessionId)->toString())),
			$($of($Utilities::toHexString(this->cookie))),
			$($of($nc($of($(getCipherSuiteNames())))->toString())),
			$($of($Utilities::toHexString(this->compressionMethod))),
			$($of($Utilities::indent($($Utilities::indent($($nc(this->extensions)->toString()))))))
		}));
		return messageFormat->format(messageFields);
	} else {
		$init($Locale);
		$var($MessageFormat, messageFormat, $new($MessageFormat, "\"ClientHello\": \'{\'\n  \"client version\"      : \"{0}\",\n  \"random\"              : \"{1}\",\n  \"session id\"          : \"{2}\",\n  \"cipher suites\"       : \"{3}\",\n  \"compression methods\" : \"{4}\",\n  \"extensions\"          : [\n{5}\n  ]\n\'}\'"_s, $Locale::ENGLISH));
		$var($ObjectArray, messageFields, $new($ObjectArray, {
			$($of($ProtocolVersion::nameOf(this->clientVersion))),
			$($of($Utilities::toHexString($nc(this->clientRandom)->randomBytes))),
			$($of($nc(this->sessionId)->toString())),
			$($of($nc($of($(getCipherSuiteNames())))->toString())),
			$($of($Utilities::toHexString(this->compressionMethod))),
			$($of($Utilities::indent($($Utilities::indent($($nc(this->extensions)->toString()))))))
		}));
		return messageFormat->format(messageFields);
	}
}

void clinit$ClientHello$ClientHelloMessage($Class* class$) {
	$assignStatic(ClientHello$ClientHelloMessage::NULL_COMPRESSION, $new($bytes, {(int8_t)0}));
}

ClientHello$ClientHelloMessage::ClientHello$ClientHelloMessage() {
}

$Class* ClientHello$ClientHelloMessage::load$($String* name, bool initialize) {
	$loadClass(ClientHello$ClientHelloMessage, name, initialize, &_ClientHello$ClientHelloMessage_ClassInfo_, clinit$ClientHello$ClientHelloMessage, allocate$ClientHello$ClientHelloMessage);
	return class$;
}

$Class* ClientHello$ClientHelloMessage::class$ = nullptr;

		} // ssl
	} // security
} // sun