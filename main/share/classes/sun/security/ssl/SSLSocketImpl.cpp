#include <sun/security/ssl/SSLSocketImpl.h>

#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InterruptedIOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/InterruptedException.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/Socket.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketException.h>
#include <java/net/SocketOption.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <java/util/function/BiFunction.h>
#include <javax/net/ssl/HandshakeCompletedListener.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <javax/net/ssl/SSLParameters.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <javax/net/ssl/SSLSession.h>
#include <jdk/internal/access/JavaNetInetAddressAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/BaseSSLSocketImpl.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientAuthType.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/ContentType.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/InputRecord.h>
#include <sun/security/ssl/NewSessionTicket.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/Plaintext.h>
#include <sun/security/ssl/PostHandshakeContext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLReadCipher.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLProducer.h>
#include <sun/security/ssl/SSLRecord.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLSocketImpl$AppInputStream.h>
#include <sun/security/ssl/SSLSocketImpl$AppOutputStream.h>
#include <sun/security/ssl/SSLSocketInputRecord.h>
#include <sun/security/ssl/SSLSocketOutputRecord.h>
#include <sun/security/ssl/SSLTransport.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <jcpp.h>

#undef APPLICATION_DATA
#undef CLIENT_AUTH_NONE
#undef CLIENT_AUTH_REQUESTED
#undef CLIENT_AUTH_REQUIRED
#undef CLOSE_NOTIFY
#undef HANDSHAKE
#undef HANDSHAKE_FAILURE
#undef INTERNAL_ERROR
#undef PLAINTEXT_NULL
#undef SECONDS
#undef UNEXPECTED_MESSAGE
#undef USER_CANCELED

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InterruptedIOException = ::java::io::InterruptedIOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $Socket = ::java::net::Socket;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketException = ::java::net::SocketException;
using $SocketOption = ::java::net::SocketOption;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $BiFunction = ::java::util::function::BiFunction;
using $HandshakeCompletedListener = ::javax::net::ssl::HandshakeCompletedListener;
using $SSLException = ::javax::net::ssl::SSLException;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $JavaNetInetAddressAccess = ::jdk::internal::access::JavaNetInetAddressAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $Alert = ::sun::security::ssl::Alert;
using $BaseSSLSocketImpl = ::sun::security::ssl::BaseSSLSocketImpl;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $ClientAuthType = ::sun::security::ssl::ClientAuthType;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $ContentType = ::sun::security::ssl::ContentType;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $InputRecord = ::sun::security::ssl::InputRecord;
using $NewSessionTicket = ::sun::security::ssl::NewSessionTicket;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $Plaintext = ::sun::security::ssl::Plaintext;
using $PostHandshakeContext = ::sun::security::ssl::PostHandshakeContext;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher$SSLReadCipher = ::sun::security::ssl::SSLCipher$SSLReadCipher;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLProducer = ::sun::security::ssl::SSLProducer;
using $SSLRecord = ::sun::security::ssl::SSLRecord;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SSLSocketImpl$AppInputStream = ::sun::security::ssl::SSLSocketImpl$AppInputStream;
using $SSLSocketImpl$AppOutputStream = ::sun::security::ssl::SSLSocketImpl$AppOutputStream;
using $SSLSocketInputRecord = ::sun::security::ssl::SSLSocketInputRecord;
using $SSLSocketOutputRecord = ::sun::security::ssl::SSLSocketOutputRecord;
using $SSLTransport = ::sun::security::ssl::SSLTransport;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLSocketImpl_FieldInfo_[] = {
	{"sslContext", "Lsun/security/ssl/SSLContextImpl;", nullptr, $FINAL, $field(SSLSocketImpl, sslContext)},
	{"conContext", "Lsun/security/ssl/TransportContext;", nullptr, $FINAL, $field(SSLSocketImpl, conContext)},
	{"appInput", "Lsun/security/ssl/SSLSocketImpl$AppInputStream;", nullptr, $PRIVATE | $FINAL, $field(SSLSocketImpl, appInput)},
	{"appOutput", "Lsun/security/ssl/SSLSocketImpl$AppOutputStream;", nullptr, $PRIVATE | $FINAL, $field(SSLSocketImpl, appOutput)},
	{"peerHost", "Ljava/lang/String;", nullptr, $PRIVATE, $field(SSLSocketImpl, peerHost)},
	{"autoClose", "Z", nullptr, $PRIVATE, $field(SSLSocketImpl, autoClose)},
	{"isConnected", "Z", nullptr, $PRIVATE, $field(SSLSocketImpl, isConnected$)},
	{"tlsIsClosed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(SSLSocketImpl, tlsIsClosed)},
	{"socketLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(SSLSocketImpl, socketLock)},
	{"handshakeLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(SSLSocketImpl, handshakeLock)},
	{"trustNameService", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLSocketImpl, trustNameService)},
	{}
};

$MethodInfo _SSLSocketImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $FINAL},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;)V", nullptr, 0, $method(SSLSocketImpl, init$, void, $SSLContextImpl*)},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Lsun/security/ssl/SSLConfiguration;)V", nullptr, 0, $method(SSLSocketImpl, init$, void, $SSLContextImpl*, $SSLConfiguration*)},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Ljava/lang/String;I)V", nullptr, 0, $method(SSLSocketImpl, init$, void, $SSLContextImpl*, $String*, int32_t), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Ljava/net/InetAddress;I)V", nullptr, 0, $method(SSLSocketImpl, init$, void, $SSLContextImpl*, $InetAddress*, int32_t), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Ljava/lang/String;ILjava/net/InetAddress;I)V", nullptr, 0, $method(SSLSocketImpl, init$, void, $SSLContextImpl*, $String*, int32_t, $InetAddress*, int32_t), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Ljava/net/InetAddress;ILjava/net/InetAddress;I)V", nullptr, 0, $method(SSLSocketImpl, init$, void, $SSLContextImpl*, $InetAddress*, int32_t, $InetAddress*, int32_t), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Ljava/net/Socket;Ljava/io/InputStream;Z)V", nullptr, 0, $method(SSLSocketImpl, init$, void, $SSLContextImpl*, $Socket*, $InputStream*, bool), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Ljava/net/Socket;Ljava/lang/String;IZ)V", nullptr, 0, $method(SSLSocketImpl, init$, void, $SSLContextImpl*, $Socket*, $String*, int32_t, bool), "java.io.IOException"},
	{"addHandshakeCompletedListener", "(Ljavax/net/ssl/HandshakeCompletedListener;)V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, addHandshakeCompletedListener, void, $HandshakeCompletedListener*)},
	{"bind", "(Ljava/net/SocketAddress;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SSLSocketImpl, bind, void, $SocketAddress*), "java.io.IOException"},
	{"bruteForceCloseInput", "(Z)V", nullptr, $PRIVATE, $method(SSLSocketImpl, bruteForceCloseInput, void, bool), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, close, void), "java.io.IOException"},
	{"closeNotify", "(Z)V", nullptr, 0, $method(SSLSocketImpl, closeNotify, void, bool), "java.io.IOException"},
	{"closeSocket", "(Z)V", nullptr, $PRIVATE, $method(SSLSocketImpl, closeSocket, void, bool), "java.io.IOException"},
	{"connect", "(Ljava/net/SocketAddress;I)V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, connect, void, $SocketAddress*, int32_t), "java.io.IOException"},
	{"decode", "(Ljava/nio/ByteBuffer;)Lsun/security/ssl/Plaintext;", nullptr, $PRIVATE, $method(SSLSocketImpl, decode, $Plaintext*, $ByteBuffer*), "java.io.IOException"},
	{"deliverClosedNotify", "(Z)V", nullptr, $PRIVATE, $method(SSLSocketImpl, deliverClosedNotify, void, bool), "java.io.IOException"},
	{"doneConnect", "()V", nullptr, 0, $method(SSLSocketImpl, doneConnect, void), "java.io.IOException"},
	{"duplexCloseInput", "()V", nullptr, $PRIVATE, $method(SSLSocketImpl, duplexCloseInput, void), "java.io.IOException"},
	{"duplexCloseOutput", "()V", nullptr, $PRIVATE, $method(SSLSocketImpl, duplexCloseOutput, void), "java.io.IOException"},
	{"ensureNegotiated", "(Z)V", nullptr, $PRIVATE, $method(SSLSocketImpl, ensureNegotiated, void, bool), "java.io.IOException"},
	{"getApplicationProtocol", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getApplicationProtocol, $String*)},
	{"getEnableSessionCreation", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getEnableSessionCreation, bool)},
	{"getEnabledCipherSuites", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getEnabledCipherSuites, $StringArray*)},
	{"getEnabledProtocols", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getEnabledProtocols, $StringArray*)},
	{"getHandshakeApplicationProtocol", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getHandshakeApplicationProtocol, $String*)},
	{"getHandshakeApplicationProtocolSelector", "()Ljava/util/function/BiFunction;", "()Ljava/util/function/BiFunction<Ljavax/net/ssl/SSLSocket;Ljava/util/List<Ljava/lang/String;>;Ljava/lang/String;>;", $PUBLIC, $virtualMethod(SSLSocketImpl, getHandshakeApplicationProtocolSelector, $BiFunction*)},
	{"getHandshakeSession", "()Ljavax/net/ssl/SSLSession;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getHandshakeSession, $SSLSession*)},
	{"getInputStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getInputStream, $InputStream*), "java.io.IOException"},
	{"getLocalSocketAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SSLSocketImpl, getLocalSocketAddress, $SocketAddress*)},
	{"getNeedClientAuth", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getNeedClientAuth, bool)},
	{"getOption", "(Ljava/net/SocketOption;)Ljava/lang/Object;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SSLSocketImpl, getOption, $Object*, $SocketOption*), "java.io.IOException"},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getOutputStream, $OutputStream*), "java.io.IOException"},
	{"getPeerHost", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getPeerHost, $String*)},
	{"getPeerPort", "()I", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getPeerPort, int32_t)},
	{"getRemoteSocketAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SSLSocketImpl, getRemoteSocketAddress, $SocketAddress*)},
	{"getSSLParameters", "()Ljavax/net/ssl/SSLParameters;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getSSLParameters, $SSLParameters*)},
	{"getSession", "()Ljavax/net/ssl/SSLSession;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getSession, $SSLSession*)},
	{"getSupportedCipherSuites", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getSupportedCipherSuites, $StringArray*)},
	{"getSupportedProtocols", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getSupportedProtocols, $StringArray*)},
	{"getUseClientMode", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getUseClientMode, bool)},
	{"getWantClientAuth", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, getWantClientAuth, bool)},
	{"handleEOF", "(Ljava/io/EOFException;)Lsun/security/ssl/Plaintext;", nullptr, $PRIVATE, $method(SSLSocketImpl, handleEOF, $Plaintext*, $EOFException*), "java.io.IOException"},
	{"handleException", "(Ljava/lang/Exception;)V", nullptr, $PRIVATE, $method(SSLSocketImpl, handleException, void, $Exception*), "java.io.IOException"},
	{"isClosed", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, isClosed, bool)},
	{"isInputShutdown", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, isInputShutdown, bool)},
	{"isOutputShutdown", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, isOutputShutdown, bool)},
	{"readApplicationRecord", "(Ljava/nio/ByteBuffer;)Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $method(SSLSocketImpl, readApplicationRecord, $ByteBuffer*, $ByteBuffer*), "java.io.IOException"},
	{"readHandshakeRecord", "()I", nullptr, $PRIVATE, $method(SSLSocketImpl, readHandshakeRecord, int32_t), "java.io.IOException"},
	{"removeHandshakeCompletedListener", "(Ljavax/net/ssl/HandshakeCompletedListener;)V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, removeHandshakeCompletedListener, void, $HandshakeCompletedListener*)},
	{"setEnableSessionCreation", "(Z)V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, setEnableSessionCreation, void, bool)},
	{"setEnabledCipherSuites", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, setEnabledCipherSuites, void, $StringArray*)},
	{"setEnabledProtocols", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, setEnabledProtocols, void, $StringArray*)},
	{"setHandshakeApplicationProtocolSelector", "(Ljava/util/function/BiFunction;)V", "(Ljava/util/function/BiFunction<Ljavax/net/ssl/SSLSocket;Ljava/util/List<Ljava/lang/String;>;Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(SSLSocketImpl, setHandshakeApplicationProtocolSelector, void, $BiFunction*)},
	{"setHost", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(SSLSocketImpl, setHost, void, $String*)},
	{"setNeedClientAuth", "(Z)V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, setNeedClientAuth, void, bool)},
	{"setOption", "(Ljava/net/SocketOption;Ljava/lang/Object;)Ljava/net/Socket;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SSLSocketImpl, setOption, $Socket*, $SocketOption*, Object$*), "java.io.IOException"},
	{"setPerformancePreferences", "(III)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SSLSocketImpl, setPerformancePreferences, void, int32_t, int32_t, int32_t)},
	{"setSSLParameters", "(Ljavax/net/ssl/SSLParameters;)V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, setSSLParameters, void, $SSLParameters*)},
	{"setSoTimeout", "(I)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SSLSocketImpl, setSoTimeout, void, int32_t), "java.net.SocketException"},
	{"setUseClientMode", "(Z)V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, setUseClientMode, void, bool)},
	{"setWantClientAuth", "(Z)V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, setWantClientAuth, void, bool)},
	{"shutdown", "()V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, shutdown, void), "java.io.IOException"},
	{"shutdownInput", "()V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, shutdownInput, void), "java.io.IOException"},
	{"shutdownInput", "(Z)V", nullptr, $PRIVATE, $method(SSLSocketImpl, shutdownInput, void, bool), "java.io.IOException"},
	{"shutdownOutput", "()V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, shutdownOutput, void), "java.io.IOException"},
	{"startHandshake", "()V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, startHandshake, void), "java.io.IOException"},
	{"startHandshake", "(Z)V", nullptr, $PRIVATE, $method(SSLSocketImpl, startHandshake, void, bool), "java.io.IOException"},
	{"supportedOptions", "()Ljava/util/Set;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SSLSocketImpl, supportedOptions, $Set*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, toString, $String*)},
	{"tryKeyUpdate", "()V", nullptr, $PRIVATE, $method(SSLSocketImpl, tryKeyUpdate, void), "java.io.IOException"},
	{"tryNewSessionTicket", "()V", nullptr, $PRIVATE, $method(SSLSocketImpl, tryNewSessionTicket, void), "java.io.IOException"},
	{"useDelegatedTask", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl, useDelegatedTask, bool)},
	{"useImplicitHost", "(Z)V", nullptr, $PRIVATE, $method(SSLSocketImpl, useImplicitHost, void, bool)},
	{"waitForClose", "()V", nullptr, $PRIVATE, $method(SSLSocketImpl, waitForClose, void), "java.io.IOException"},
	{}
};

$InnerClassInfo _SSLSocketImpl_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLSocketImpl$AppOutputStream", "sun.security.ssl.SSLSocketImpl", "AppOutputStream", $PRIVATE},
	{"sun.security.ssl.SSLSocketImpl$AppInputStream", "sun.security.ssl.SSLSocketImpl", "AppInputStream", $PRIVATE},
	{}
};

$ClassInfo _SSLSocketImpl_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLSocketImpl",
	"sun.security.ssl.BaseSSLSocketImpl",
	"sun.security.ssl.SSLTransport",
	_SSLSocketImpl_FieldInfo_,
	_SSLSocketImpl_MethodInfo_,
	nullptr,
	nullptr,
	_SSLSocketImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLSocketImpl$AppOutputStream,sun.security.ssl.SSLSocketImpl$AppInputStream"
};

$Object* allocate$SSLSocketImpl($Class* clazz) {
	return $of($alloc(SSLSocketImpl));
}

void SSLSocketImpl::finalize() {
	this->$BaseSSLSocketImpl::finalize();
}

int32_t SSLSocketImpl::hashCode() {
	 return this->$BaseSSLSocketImpl::hashCode();
}

bool SSLSocketImpl::equals(Object$* obj) {
	 return this->$BaseSSLSocketImpl::equals(obj);
}

$Object* SSLSocketImpl::clone() {
	 return this->$BaseSSLSocketImpl::clone();
}

bool SSLSocketImpl::trustNameService = false;

void SSLSocketImpl::init$($SSLContextImpl* sslContext) {
	$useLocalCurrentObjectStackCache();
	$BaseSSLSocketImpl::init$();
	$set(this, appInput, $new($SSLSocketImpl$AppInputStream, this));
	$set(this, appOutput, $new($SSLSocketImpl$AppOutputStream, this));
	$set(this, socketLock, $new($ReentrantLock));
	$set(this, handshakeLock, $new($ReentrantLock));
	$set(this, sslContext, sslContext);
	$var($HandshakeHash, handshakeHash, $new($HandshakeHash));
	$var($SSLContextImpl, var$0, sslContext);
	$var($InputRecord, var$1, static_cast<$InputRecord*>($new($SSLSocketInputRecord, handshakeHash)));
	$set(this, conContext, $new($TransportContext, var$0, static_cast<$SSLTransport*>(this), var$1, static_cast<$OutputRecord*>($$new($SSLSocketOutputRecord, handshakeHash)), true));
}

void SSLSocketImpl::init$($SSLContextImpl* sslContext, $SSLConfiguration* sslConfig) {
	$useLocalCurrentObjectStackCache();
	$BaseSSLSocketImpl::init$();
	$set(this, appInput, $new($SSLSocketImpl$AppInputStream, this));
	$set(this, appOutput, $new($SSLSocketImpl$AppOutputStream, this));
	$set(this, socketLock, $new($ReentrantLock));
	$set(this, handshakeLock, $new($ReentrantLock));
	$set(this, sslContext, sslContext);
	$var($HandshakeHash, handshakeHash, $new($HandshakeHash));
	$var($SSLContextImpl, var$0, sslContext);
	$var($SSLConfiguration, var$1, sslConfig);
	$var($InputRecord, var$2, static_cast<$InputRecord*>($new($SSLSocketInputRecord, handshakeHash)));
	$set(this, conContext, $new($TransportContext, var$0, static_cast<$SSLTransport*>(this), var$1, var$2, static_cast<$OutputRecord*>($$new($SSLSocketOutputRecord, handshakeHash))));
}

void SSLSocketImpl::init$($SSLContextImpl* sslContext, $String* peerHost, int32_t peerPort) {
	$useLocalCurrentObjectStackCache();
	$BaseSSLSocketImpl::init$();
	$set(this, appInput, $new($SSLSocketImpl$AppInputStream, this));
	$set(this, appOutput, $new($SSLSocketImpl$AppOutputStream, this));
	$set(this, socketLock, $new($ReentrantLock));
	$set(this, handshakeLock, $new($ReentrantLock));
	$set(this, sslContext, sslContext);
	$var($HandshakeHash, handshakeHash, $new($HandshakeHash));
	$var($SSLContextImpl, var$0, sslContext);
	$var($InputRecord, var$1, static_cast<$InputRecord*>($new($SSLSocketInputRecord, handshakeHash)));
	$set(this, conContext, $new($TransportContext, var$0, static_cast<$SSLTransport*>(this), var$1, static_cast<$OutputRecord*>($$new($SSLSocketOutputRecord, handshakeHash)), true));
	$set(this, peerHost, peerHost);
	$var($SocketAddress, socketAddress, peerHost != nullptr ? static_cast<$SocketAddress*>($new($InetSocketAddress, peerHost, peerPort)) : static_cast<$SocketAddress*>($new($InetSocketAddress, $($InetAddress::getByName(nullptr)), peerPort)));
	connect(socketAddress, 0);
}

void SSLSocketImpl::init$($SSLContextImpl* sslContext, $InetAddress* address, int32_t peerPort) {
	$useLocalCurrentObjectStackCache();
	$BaseSSLSocketImpl::init$();
	$set(this, appInput, $new($SSLSocketImpl$AppInputStream, this));
	$set(this, appOutput, $new($SSLSocketImpl$AppOutputStream, this));
	$set(this, socketLock, $new($ReentrantLock));
	$set(this, handshakeLock, $new($ReentrantLock));
	$set(this, sslContext, sslContext);
	$var($HandshakeHash, handshakeHash, $new($HandshakeHash));
	$var($SSLContextImpl, var$0, sslContext);
	$var($InputRecord, var$1, static_cast<$InputRecord*>($new($SSLSocketInputRecord, handshakeHash)));
	$set(this, conContext, $new($TransportContext, var$0, static_cast<$SSLTransport*>(this), var$1, static_cast<$OutputRecord*>($$new($SSLSocketOutputRecord, handshakeHash)), true));
	$var($SocketAddress, socketAddress, $new($InetSocketAddress, address, peerPort));
	connect(socketAddress, 0);
}

void SSLSocketImpl::init$($SSLContextImpl* sslContext, $String* peerHost, int32_t peerPort, $InetAddress* localAddr, int32_t localPort) {
	$useLocalCurrentObjectStackCache();
	$BaseSSLSocketImpl::init$();
	$set(this, appInput, $new($SSLSocketImpl$AppInputStream, this));
	$set(this, appOutput, $new($SSLSocketImpl$AppOutputStream, this));
	$set(this, socketLock, $new($ReentrantLock));
	$set(this, handshakeLock, $new($ReentrantLock));
	$set(this, sslContext, sslContext);
	$var($HandshakeHash, handshakeHash, $new($HandshakeHash));
	$var($SSLContextImpl, var$0, sslContext);
	$var($InputRecord, var$1, static_cast<$InputRecord*>($new($SSLSocketInputRecord, handshakeHash)));
	$set(this, conContext, $new($TransportContext, var$0, static_cast<$SSLTransport*>(this), var$1, static_cast<$OutputRecord*>($$new($SSLSocketOutputRecord, handshakeHash)), true));
	$set(this, peerHost, peerHost);
	bind($$new($InetSocketAddress, localAddr, localPort));
	$var($SocketAddress, socketAddress, peerHost != nullptr ? static_cast<$SocketAddress*>($new($InetSocketAddress, peerHost, peerPort)) : static_cast<$SocketAddress*>($new($InetSocketAddress, $($InetAddress::getByName(nullptr)), peerPort)));
	connect(socketAddress, 0);
}

void SSLSocketImpl::init$($SSLContextImpl* sslContext, $InetAddress* peerAddr, int32_t peerPort, $InetAddress* localAddr, int32_t localPort) {
	$useLocalCurrentObjectStackCache();
	$BaseSSLSocketImpl::init$();
	$set(this, appInput, $new($SSLSocketImpl$AppInputStream, this));
	$set(this, appOutput, $new($SSLSocketImpl$AppOutputStream, this));
	$set(this, socketLock, $new($ReentrantLock));
	$set(this, handshakeLock, $new($ReentrantLock));
	$set(this, sslContext, sslContext);
	$var($HandshakeHash, handshakeHash, $new($HandshakeHash));
	$var($SSLContextImpl, var$0, sslContext);
	$var($InputRecord, var$1, static_cast<$InputRecord*>($new($SSLSocketInputRecord, handshakeHash)));
	$set(this, conContext, $new($TransportContext, var$0, static_cast<$SSLTransport*>(this), var$1, static_cast<$OutputRecord*>($$new($SSLSocketOutputRecord, handshakeHash)), true));
	bind($$new($InetSocketAddress, localAddr, localPort));
	$var($SocketAddress, socketAddress, $new($InetSocketAddress, peerAddr, peerPort));
	connect(socketAddress, 0);
}

void SSLSocketImpl::init$($SSLContextImpl* sslContext, $Socket* sock, $InputStream* consumed, bool autoClose) {
	$useLocalCurrentObjectStackCache();
	$BaseSSLSocketImpl::init$(sock, consumed);
	$set(this, appInput, $new($SSLSocketImpl$AppInputStream, this));
	$set(this, appOutput, $new($SSLSocketImpl$AppOutputStream, this));
	$set(this, socketLock, $new($ReentrantLock));
	$set(this, handshakeLock, $new($ReentrantLock));
	if (!$nc(sock)->isConnected()) {
		$throwNew($SocketException, "Underlying socket is not connected"_s);
	}
	$set(this, sslContext, sslContext);
	$var($HandshakeHash, handshakeHash, $new($HandshakeHash));
	$var($SSLContextImpl, var$0, sslContext);
	$var($InputRecord, var$1, static_cast<$InputRecord*>($new($SSLSocketInputRecord, handshakeHash)));
	$set(this, conContext, $new($TransportContext, var$0, static_cast<$SSLTransport*>(this), var$1, static_cast<$OutputRecord*>($$new($SSLSocketOutputRecord, handshakeHash)), false));
	this->autoClose = autoClose;
	doneConnect();
}

void SSLSocketImpl::init$($SSLContextImpl* sslContext, $Socket* sock, $String* peerHost, int32_t port, bool autoClose) {
	$useLocalCurrentObjectStackCache();
	$BaseSSLSocketImpl::init$(sock);
	$set(this, appInput, $new($SSLSocketImpl$AppInputStream, this));
	$set(this, appOutput, $new($SSLSocketImpl$AppOutputStream, this));
	$set(this, socketLock, $new($ReentrantLock));
	$set(this, handshakeLock, $new($ReentrantLock));
	if (!$nc(sock)->isConnected()) {
		$throwNew($SocketException, "Underlying socket is not connected"_s);
	}
	$set(this, sslContext, sslContext);
	$var($HandshakeHash, handshakeHash, $new($HandshakeHash));
	$var($SSLContextImpl, var$0, sslContext);
	$var($InputRecord, var$1, static_cast<$InputRecord*>($new($SSLSocketInputRecord, handshakeHash)));
	$set(this, conContext, $new($TransportContext, var$0, static_cast<$SSLTransport*>(this), var$1, static_cast<$OutputRecord*>($$new($SSLSocketOutputRecord, handshakeHash)), true));
	$set(this, peerHost, peerHost);
	this->autoClose = autoClose;
	doneConnect();
}

void SSLSocketImpl::connect($SocketAddress* endpoint, int32_t timeout) {
	if (isLayered()) {
		$throwNew($SocketException, "Already connected"_s);
	}
	if (!($instanceOf($InetSocketAddress, endpoint))) {
		$throwNew($SocketException, "Cannot handle non-Inet socket addresses."_s);
	}
	$BaseSSLSocketImpl::connect(endpoint, timeout);
	doneConnect();
}

$StringArray* SSLSocketImpl::getSupportedCipherSuites() {
	return $CipherSuite::namesOf($($nc(this->sslContext)->getSupportedCipherSuites()));
}

$StringArray* SSLSocketImpl::getEnabledCipherSuites() {
	$useLocalCurrentObjectStackCache();
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($StringArray, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $CipherSuite::namesOf($nc($nc(this->conContext)->sslConfig)->enabledCipherSuites));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void SSLSocketImpl::setEnabledCipherSuites($StringArray* suites) {
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$set($nc($nc(this->conContext)->sslConfig), enabledCipherSuites, $CipherSuite::validValuesOf(suites));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$StringArray* SSLSocketImpl::getSupportedProtocols() {
	return $ProtocolVersion::toStringArray($($nc(this->sslContext)->getSupportedProtocolVersions()));
}

$StringArray* SSLSocketImpl::getEnabledProtocols() {
	$useLocalCurrentObjectStackCache();
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($StringArray, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $ProtocolVersion::toStringArray($nc($nc(this->conContext)->sslConfig)->enabledProtocols));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void SSLSocketImpl::setEnabledProtocols($StringArray* protocols) {
	if (protocols == nullptr) {
		$throwNew($IllegalArgumentException, "Protocols cannot be null"_s);
	}
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$set($nc($nc(this->conContext)->sslConfig), enabledProtocols, $ProtocolVersion::namesOf(protocols));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$SSLSession* SSLSocketImpl::getSession() {
	try {
		ensureNegotiated(false);
	} catch ($IOException& ioe) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("handshake"_s)) {
			$SSLLogger::severe("handshake failed"_s, $$new($ObjectArray, {$of(ioe)}));
		}
		return $new($SSLSessionImpl);
	}
	return $nc(this->conContext)->conSession;
}

$SSLSession* SSLSocketImpl::getHandshakeSession() {
	$useLocalCurrentObjectStackCache();
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($SSLSession, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc(this->conContext)->handshakeContext == nullptr ? ($SSLSession*)nullptr : static_cast<$SSLSession*>($nc($nc(this->conContext)->handshakeContext)->handshakeSession));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void SSLSocketImpl::addHandshakeCompletedListener($HandshakeCompletedListener* listener) {
	if (listener == nullptr) {
		$throwNew($IllegalArgumentException, "listener is null"_s);
	}
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc($nc(this->conContext)->sslConfig)->addHandshakeCompletedListener(listener);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void SSLSocketImpl::removeHandshakeCompletedListener($HandshakeCompletedListener* listener) {
	if (listener == nullptr) {
		$throwNew($IllegalArgumentException, "listener is null"_s);
	}
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc($nc(this->conContext)->sslConfig)->removeHandshakeCompletedListener(listener);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void SSLSocketImpl::startHandshake() {
	startHandshake(true);
}

void SSLSocketImpl::startHandshake(bool resumable) {
	$useLocalCurrentObjectStackCache();
	if (!this->isConnected$) {
		$throwNew($SocketException, "Socket is not connected"_s);
	}
	bool var$0 = $nc(this->conContext)->isBroken || $nc(this->conContext)->isInboundClosed();
	if (var$0 || $nc(this->conContext)->isOutboundClosed()) {
		$throwNew($SocketException, "Socket has been closed or broken"_s);
	}
	$nc(this->handshakeLock)->lock();
	{
		$var($Throwable, var$1, nullptr);
		try {
			bool var$2 = $nc(this->conContext)->isBroken || $nc(this->conContext)->isInboundClosed();
			if (var$2 || $nc(this->conContext)->isOutboundClosed()) {
				$throwNew($SocketException, "Socket has been closed or broken"_s);
			}
			try {
				$nc(this->conContext)->kickstart();
				if (!$nc(this->conContext)->isNegotiated) {
					readHandshakeRecord();
				}
			} catch ($InterruptedIOException& iioe) {
				if (resumable) {
					handleException(iioe);
				} else {
					$init($Alert);
					$throw($($nc(this->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Couldn\'t kickstart handshaking"_s, iioe)));
				}
			} catch ($SocketException& se) {
				handleException(se);
			} catch ($IOException& ioe) {
				$init($Alert);
				$throw($($nc(this->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Couldn\'t kickstart handshaking"_s, ioe)));
			} catch ($Exception& oe) {
				handleException(oe);
			}
		} catch ($Throwable& var$3) {
			$assign(var$1, var$3);
		} /*finally*/ {
			$nc(this->handshakeLock)->unlock();
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
	}
}

void SSLSocketImpl::setUseClientMode(bool mode) {
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->conContext)->setUseClientMode(mode);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool SSLSocketImpl::getUseClientMode() {
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			var$2 = $nc($nc(this->conContext)->sslConfig)->isClientMode;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void SSLSocketImpl::setNeedClientAuth(bool need) {
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$init($ClientAuthType);
			$set($nc($nc(this->conContext)->sslConfig), clientAuthType, need ? $ClientAuthType::CLIENT_AUTH_REQUIRED : $ClientAuthType::CLIENT_AUTH_NONE);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool SSLSocketImpl::getNeedClientAuth() {
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			$init($ClientAuthType);
			var$2 = ($nc($nc(this->conContext)->sslConfig)->clientAuthType == $ClientAuthType::CLIENT_AUTH_REQUIRED);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void SSLSocketImpl::setWantClientAuth(bool want) {
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$init($ClientAuthType);
			$set($nc($nc(this->conContext)->sslConfig), clientAuthType, want ? $ClientAuthType::CLIENT_AUTH_REQUESTED : $ClientAuthType::CLIENT_AUTH_NONE);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool SSLSocketImpl::getWantClientAuth() {
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			$init($ClientAuthType);
			var$2 = ($nc($nc(this->conContext)->sslConfig)->clientAuthType == $ClientAuthType::CLIENT_AUTH_REQUESTED);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void SSLSocketImpl::setEnableSessionCreation(bool flag) {
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc($nc(this->conContext)->sslConfig)->enableSessionCreation = flag;
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool SSLSocketImpl::getEnableSessionCreation() {
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			var$2 = $nc($nc(this->conContext)->sslConfig)->enableSessionCreation;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

bool SSLSocketImpl::isClosed() {
	return this->tlsIsClosed;
}

void SSLSocketImpl::close() {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		return;
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
		$SSLLogger::fine("duplex close of SSLSocket"_s, $$new($ObjectArray, 0));
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				if (isConnected()) {
					if (!isOutputShutdown()) {
						duplexCloseOutput();
					}
					if (!isInputShutdown()) {
						duplexCloseInput();
					}
				}
			} catch ($IOException& ioe) {
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
					$SSLLogger::warning("SSLSocket duplex close failed. Debug info only. Exception details:"_s, $$new($ObjectArray, {$of(ioe)}));
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (!isClosed()) {
				{
					$var($Throwable, var$2, nullptr);
					try {
						try {
							closeSocket(false);
						} catch ($IOException& ioe) {
							if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
								$SSLLogger::warning("SSLSocket close failed. Debug info only. Exception details:"_s, $$new($ObjectArray, {$of(ioe)}));
							}
						}
					} catch ($Throwable& var$3) {
						$assign(var$2, var$3);
					} /*finally*/ {
						this->tlsIsClosed = true;
					}
					if (var$2 != nullptr) {
						$throw(var$2);
					}
				}
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void SSLSocketImpl::duplexCloseOutput() {
	bool useUserCanceled = false;
	bool hasCloseReceipt = false;
	if ($nc(this->conContext)->isNegotiated) {
		if (!$nc($nc(this->conContext)->protocolVersion)->useTLS13PlusSpec()) {
			hasCloseReceipt = true;
		} else {
			useUserCanceled = true;
		}
	} else if ($nc(this->conContext)->handshakeContext != nullptr) {
		useUserCanceled = true;
		$ProtocolVersion* pv = $nc($nc(this->conContext)->handshakeContext)->negotiatedProtocol;
		if (pv == nullptr || (!$nc(pv)->useTLS13PlusSpec())) {
			hasCloseReceipt = true;
		}
	}
	closeNotify(useUserCanceled);
	if (!isInputShutdown()) {
		bruteForceCloseInput(hasCloseReceipt);
	}
}

void SSLSocketImpl::closeNotify(bool useUserCanceled) {
	$useLocalCurrentObjectStackCache();
	int32_t linger = getSoLinger();
	if (linger >= 0) {
		bool interrupted = $Thread::interrupted();
		try {
			bool var$0 = $nc($nc($nc(this->conContext)->outputRecord)->recordLock)->tryLock();
			$init($TimeUnit);
			if (var$0 || $nc($nc($nc(this->conContext)->outputRecord)->recordLock)->tryLock(linger, $TimeUnit::SECONDS)) {
				{
					$var($Throwable, var$1, nullptr);
					try {
						deliverClosedNotify(useUserCanceled);
					} catch ($Throwable& var$2) {
						$assign(var$1, var$2);
					} /*finally*/ {
						$nc($nc($nc(this->conContext)->outputRecord)->recordLock)->unlock();
					}
					if (var$1 != nullptr) {
						$throw(var$1);
					}
				}
			} else {
				if (!$BaseSSLSocketImpl::isOutputShutdown()) {
					if (isLayered() && !this->autoClose) {
						$throwNew($SSLException, "SO_LINGER timeout, close_notify message cannot be sent."_s);
					} else {
						$BaseSSLSocketImpl::shutdownOutput();
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
							$SSLLogger::warning("SSLSocket output duplex close failed: SO_LINGER timeout, close_notify message cannot be sent."_s, $$new($ObjectArray, 0));
						}
					}
				}
				$nc($nc(this->conContext)->conSession)->invalidate();
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
					$SSLLogger::warning("Invalidate the session: SO_LINGER timeout, close_notify message cannot be sent."_s, $$new($ObjectArray, 0));
				}
			}
		} catch ($InterruptedException& ex) {
			interrupted = true;
		}
		if (interrupted) {
			$($Thread::currentThread())->interrupt();
		}
	} else {
		$nc($nc($nc(this->conContext)->outputRecord)->recordLock)->lock();
		{
			$var($Throwable, var$3, nullptr);
			try {
				deliverClosedNotify(useUserCanceled);
			} catch ($Throwable& var$4) {
				$assign(var$3, var$4);
			} /*finally*/ {
				$nc($nc($nc(this->conContext)->outputRecord)->recordLock)->unlock();
			}
			if (var$3 != nullptr) {
				$throw(var$3);
			}
		}
	}
}

void SSLSocketImpl::deliverClosedNotify(bool useUserCanceled) {
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (useUserCanceled) {
				$init($Alert);
				$nc(this->conContext)->warning($Alert::USER_CANCELED);
			}
			$init($Alert);
			$nc(this->conContext)->warning($Alert::CLOSE_NOTIFY);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (!$nc(this->conContext)->isOutboundClosed()) {
				$nc($nc(this->conContext)->outputRecord)->close();
			}
			bool var$2 = !$BaseSSLSocketImpl::isOutputShutdown();
			if (var$2 && (this->autoClose || !isLayered())) {
				$BaseSSLSocketImpl::shutdownOutput();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void SSLSocketImpl::duplexCloseInput() {
	bool hasCloseReceipt = false;
	if ($nc(this->conContext)->isNegotiated && !$nc($nc(this->conContext)->protocolVersion)->useTLS13PlusSpec()) {
		hasCloseReceipt = true;
	}
	bruteForceCloseInput(hasCloseReceipt);
}

void SSLSocketImpl::bruteForceCloseInput(bool hasCloseReceipt) {
	$useLocalCurrentObjectStackCache();
	if (hasCloseReceipt) {
		{
			$var($Throwable, var$0, nullptr);
			try {
				this->shutdown();
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				if (!isInputShutdown()) {
					shutdownInput(false);
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} else {
		if (!$nc(this->conContext)->isInboundClosed()) {
			{
				$var($InputRecord, twrVar0$, $nc(this->conContext)->inputRecord);
				{
					$var($Throwable, var$2, nullptr);
					try {
						try {
							$nc(this->appInput)->deplete();
						} catch ($Throwable& t$) {
							if (twrVar0$ != nullptr) {
								try {
									twrVar0$->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
							}
							$throw(t$);
						}
					} catch ($Throwable& var$3) {
						$assign(var$2, var$3);
					} /*finally*/ {
						if (twrVar0$ != nullptr) {
							twrVar0$->close();
						}
					}
					if (var$2 != nullptr) {
						$throw(var$2);
					}
				}
			}
		}
		bool var$4 = (this->autoClose || !isLayered());
		if (var$4 && !$BaseSSLSocketImpl::isInputShutdown()) {
			$BaseSSLSocketImpl::shutdownInput();
		}
	}
}

void SSLSocketImpl::shutdownInput() {
	shutdownInput(true);
}

void SSLSocketImpl::shutdownInput(bool checkCloseNotify) {
	$useLocalCurrentObjectStackCache();
	if (isInputShutdown()) {
		return;
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
		$SSLLogger::fine("close inbound of SSLSocket"_s, $$new($ObjectArray, 0));
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (checkCloseNotify && !$nc(this->conContext)->isInputCloseNotified && ($nc(this->conContext)->isNegotiated || $nc(this->conContext)->handshakeContext != nullptr)) {
				$throwNew($SSLException, "closing inbound before receiving peer\'s close_notify"_s);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->conContext)->closeInbound();
			bool var$2 = (this->autoClose || !isLayered());
			if (var$2 && !$BaseSSLSocketImpl::isInputShutdown()) {
				$BaseSSLSocketImpl::shutdownInput();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool SSLSocketImpl::isInputShutdown() {
	bool var$0 = $nc(this->conContext)->isInboundClosed();
	if (var$0) {
		bool var$1 = !this->autoClose && isLayered();
		var$0 = (var$1 || $BaseSSLSocketImpl::isInputShutdown());
	}
	return var$0;
}

void SSLSocketImpl::shutdownOutput() {
	if (isOutputShutdown()) {
		return;
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
		$SSLLogger::fine("close outbound of SSLSocket"_s, $$new($ObjectArray, 0));
	}
	$nc(this->conContext)->closeOutbound();
	bool var$0 = (this->autoClose || !isLayered());
	if (var$0 && !$BaseSSLSocketImpl::isOutputShutdown()) {
		$BaseSSLSocketImpl::shutdownOutput();
	}
}

bool SSLSocketImpl::isOutputShutdown() {
	bool var$0 = $nc(this->conContext)->isOutboundClosed();
	if (var$0) {
		bool var$1 = !this->autoClose && isLayered();
		var$0 = (var$1 || $BaseSSLSocketImpl::isOutputShutdown());
	}
	return var$0;
}

$InputStream* SSLSocketImpl::getInputStream() {
	$useLocalCurrentObjectStackCache();
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($InputStream, var$2, nullptr);
		bool return$1 = false;
		try {
			if (isClosed()) {
				$throwNew($SocketException, "Socket is closed"_s);
			}
			if (!this->isConnected$) {
				$throwNew($SocketException, "Socket is not connected"_s);
			}
			bool var$3 = $nc(this->conContext)->isInboundClosed();
			if (var$3 || isInputShutdown()) {
				$throwNew($SocketException, "Socket input is already shutdown"_s);
			}
			$assign(var$2, this->appInput);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void SSLSocketImpl::ensureNegotiated(bool resumable) {
	bool var$0 = $nc(this->conContext)->isNegotiated || $nc(this->conContext)->isBroken || $nc(this->conContext)->isInboundClosed();
	if (var$0 || $nc(this->conContext)->isOutboundClosed()) {
		return;
	}
	$nc(this->handshakeLock)->lock();
	{
		$var($Throwable, var$1, nullptr);
		bool return$2 = false;
		try {
			bool var$3 = $nc(this->conContext)->isNegotiated || $nc(this->conContext)->isBroken || $nc(this->conContext)->isInboundClosed();
			if (var$3 || $nc(this->conContext)->isOutboundClosed()) {
				return$2 = true;
				goto $finally;
			}
			startHandshake(resumable);
		} catch ($Throwable& var$4) {
			$assign(var$1, var$4);
		} $finally: {
			$nc(this->handshakeLock)->unlock();
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
		if (return$2) {
			return;
		}
	}
}

$OutputStream* SSLSocketImpl::getOutputStream() {
	$useLocalCurrentObjectStackCache();
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($OutputStream, var$2, nullptr);
		bool return$1 = false;
		try {
			if (isClosed()) {
				$throwNew($SocketException, "Socket is closed"_s);
			}
			if (!this->isConnected$) {
				$throwNew($SocketException, "Socket is not connected"_s);
			}
			bool var$3 = $nc(this->conContext)->isOutboundDone();
			if (var$3 || isOutputShutdown()) {
				$throwNew($SocketException, "Socket output is already shutdown"_s);
			}
			$assign(var$2, this->appOutput);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$SSLParameters* SSLSocketImpl::getSSLParameters() {
	$useLocalCurrentObjectStackCache();
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($SSLParameters, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc($nc(this->conContext)->sslConfig)->getSSLParameters());
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void SSLSocketImpl::setSSLParameters($SSLParameters* params) {
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc($nc(this->conContext)->sslConfig)->setSSLParameters(params);
			if ($nc($nc(this->conContext)->sslConfig)->maximumPacketSize != 0) {
				$nc($nc(this->conContext)->outputRecord)->changePacketSize($nc($nc(this->conContext)->sslConfig)->maximumPacketSize);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$String* SSLSocketImpl::getApplicationProtocol() {
	$useLocalCurrentObjectStackCache();
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($String, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc(this->conContext)->applicationProtocol);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$String* SSLSocketImpl::getHandshakeApplicationProtocol() {
	$useLocalCurrentObjectStackCache();
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($String, var$2, nullptr);
		bool return$1 = false;
		try {
			if ($nc(this->conContext)->handshakeContext != nullptr) {
				$assign(var$2, $nc($nc(this->conContext)->handshakeContext)->applicationProtocol);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	return nullptr;
}

void SSLSocketImpl::setHandshakeApplicationProtocolSelector($BiFunction* selector) {
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$set($nc($nc(this->conContext)->sslConfig), socketAPSelector, selector);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$BiFunction* SSLSocketImpl::getHandshakeApplicationProtocolSelector() {
	$useLocalCurrentObjectStackCache();
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($BiFunction, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc($nc(this->conContext)->sslConfig)->socketAPSelector);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

int32_t SSLSocketImpl::readHandshakeRecord() {
	$useLocalCurrentObjectStackCache();
	while (!$nc(this->conContext)->isInboundClosed()) {
		try {
			$var($Plaintext, plainText, decode(nullptr));
			$init($ContentType);
			if (($nc(plainText)->contentType == $ContentType::HANDSHAKE->id) && $nc(this->conContext)->isNegotiated) {
				return 0;
			}
		} catch ($SSLException& se) {
			$throw(se);
		} catch ($InterruptedIOException& se) {
			$throw(se);
		} catch ($SocketException& se) {
			$throw(se);
		} catch ($IOException& ioe) {
			$throwNew($SSLException, "readHandshakeRecord"_s, ioe);
		}
	}
	return -1;
}

$ByteBuffer* SSLSocketImpl::readApplicationRecord($ByteBuffer* buffer$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, buffer, buffer$renamed);
	while (!$nc(this->conContext)->isInboundClosed()) {
		$nc(buffer)->clear();
		int32_t inLen = $nc($nc(this->conContext)->inputRecord)->bytesInCompletePacket();
		if (inLen < 0) {
			handleEOF(nullptr);
			return nullptr;
		}
		if (inLen > $SSLRecord::maxLargeRecordSize) {
			$throwNew($SSLProtocolException, $$str({"Illegal packet size: "_s, $$str(inLen)}));
		}
		if (inLen > buffer->remaining()) {
			$assign(buffer, $ByteBuffer::allocate(inLen));
		}
		try {
			$var($Plaintext, plainText, decode(buffer));
			$init($ContentType);
			if ($nc(plainText)->contentType == $ContentType::APPLICATION_DATA->id && buffer->position() > 0) {
				return buffer;
			}
		} catch ($SSLException& se) {
			$throw(se);
		} catch ($InterruptedIOException& se) {
			$throw(se);
		} catch ($SocketException& se) {
			$throw(se);
		} catch ($IOException& ioe) {
			$throwNew($SSLException, "readApplicationRecord"_s, ioe);
		}
	}
	return nullptr;
}

$Plaintext* SSLSocketImpl::decode($ByteBuffer* destination) {
	$useLocalCurrentObjectStackCache();
	$var($Plaintext, plainText, nullptr);
	try {
		if (destination == nullptr) {
			$assign(plainText, $SSLTransport::decode(this->conContext, nullptr, 0, 0, nullptr, 0, 0));
		} else {
			$assign(plainText, $SSLTransport::decode(this->conContext, nullptr, 0, 0, $$new($ByteBufferArray, {destination}), 0, 1));
		}
	} catch ($EOFException& eofe) {
		$assign(plainText, handleEOF(eofe));
	}
	$init($Plaintext);
	bool var$0 = plainText != $Plaintext::PLAINTEXT_NULL;
	if (var$0) {
		bool var$1 = $nc($nc(this->conContext)->inputRecord)->seqNumIsHuge();
		var$0 = (var$1 || $nc($nc($nc(this->conContext)->inputRecord)->readCipher)->atKeyLimit());
	}
	if (var$0) {
		tryKeyUpdate();
	}
	return plainText;
}

void SSLSocketImpl::tryKeyUpdate() {
	bool var$0 = ($nc(this->conContext)->handshakeContext == nullptr) && !$nc(this->conContext)->isOutboundClosed();
	if (var$0 && !$nc(this->conContext)->isInboundClosed() && !$nc(this->conContext)->isBroken) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::finest("trigger key update"_s, $$new($ObjectArray, 0));
		}
		startHandshake();
	}
}

void SSLSocketImpl::tryNewSessionTicket() {
	$useLocalCurrentObjectStackCache();
	bool var$1 = !$nc($nc(this->conContext)->sslConfig)->isClientMode && $nc($nc(this->conContext)->protocolVersion)->useTLS13PlusSpec() && $nc(this->conContext)->handshakeContext == nullptr;
	bool var$0 = var$1 && !$nc(this->conContext)->isOutboundClosed();
	if (var$0 && !$nc(this->conContext)->isInboundClosed() && !$nc(this->conContext)->isBroken) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::finest("trigger new session ticket"_s, $$new($ObjectArray, 0));
		}
		$init($NewSessionTicket);
		$nc($NewSessionTicket::t13PosthandshakeProducer)->produce($$new($PostHandshakeContext, this->conContext));
	}
}

void SSLSocketImpl::doneConnect() {
	$useLocalCurrentObjectStackCache();
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (this->peerHost == nullptr || $nc(this->peerHost)->isEmpty()) {
				bool useNameService = SSLSocketImpl::trustNameService && $nc($nc(this->conContext)->sslConfig)->isClientMode;
				useImplicitHost(useNameService);
			} else {
				$set($nc($nc(this->conContext)->sslConfig), serverNames, $Utilities::addToSNIServerNameList($nc($nc(this->conContext)->sslConfig)->serverNames, this->peerHost));
			}
			$var($InputStream, sockInput, $BaseSSLSocketImpl::getInputStream());
			$nc($nc(this->conContext)->inputRecord)->setReceiverStream(sockInput);
			$var($OutputStream, sockOutput, $BaseSSLSocketImpl::getOutputStream());
			$nc($nc(this->conContext)->inputRecord)->setDeliverStream(sockOutput);
			$nc($nc(this->conContext)->outputRecord)->setDeliverStream(sockOutput);
			this->isConnected$ = true;
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void SSLSocketImpl::useImplicitHost(bool useNameService) {
	$useLocalCurrentObjectStackCache();
	$var($InetAddress, inetAddress, getInetAddress());
	if (inetAddress == nullptr) {
		return;
	}
	$var($JavaNetInetAddressAccess, jna, $SharedSecrets::getJavaNetInetAddressAccess());
	$var($String, originalHostname, $nc(jna)->getOriginalHostName(inetAddress));
	if (originalHostname != nullptr && !originalHostname->isEmpty()) {
		$set(this, peerHost, originalHostname);
		if ($nc($nc($nc(this->conContext)->sslConfig)->serverNames)->isEmpty() && !$nc($nc(this->conContext)->sslConfig)->noSniExtension) {
			$set($nc($nc(this->conContext)->sslConfig), serverNames, $Utilities::addToSNIServerNameList($nc($nc(this->conContext)->sslConfig)->serverNames, this->peerHost));
		}
		return;
	}
	if (!useNameService) {
		$set(this, peerHost, $nc(inetAddress)->getHostAddress());
	} else {
		$set(this, peerHost, $nc($(getInetAddress()))->getHostName());
	}
}

void SSLSocketImpl::setHost($String* host) {
	$nc(this->socketLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$set(this, peerHost, host);
			$set($nc($nc(this->conContext)->sslConfig), serverNames, $Utilities::addToSNIServerNameList($nc($nc(this->conContext)->sslConfig)->serverNames, host));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->socketLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void SSLSocketImpl::handleException($Exception* cause) {
	$useLocalCurrentObjectStackCache();
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
		$SSLLogger::warning("handling exception"_s, $$new($ObjectArray, {$of(cause)}));
	}
	if ($instanceOf($InterruptedIOException, cause)) {
		$throw($cast($IOException, cause));
	}
	bool isSSLException = ($instanceOf($SSLException, cause));
	$Alert* alert = nullptr;
	if (isSSLException) {
		if ($instanceOf($SSLHandshakeException, cause)) {
			$init($Alert);
			alert = $Alert::HANDSHAKE_FAILURE;
		} else {
			$init($Alert);
			alert = $Alert::UNEXPECTED_MESSAGE;
		}
	} else if ($instanceOf($IOException, cause)) {
		$init($Alert);
		alert = $Alert::UNEXPECTED_MESSAGE;
	} else {
		$init($Alert);
		alert = $Alert::INTERNAL_ERROR;
	}
	if ($instanceOf($SocketException, cause)) {
		try {
			$throw($($nc(this->conContext)->fatal(alert, static_cast<$Throwable*>(cause))));
		} catch ($Exception& e) {
		}
		$throw($cast($SocketException, cause));
	}
	$throw($($nc(this->conContext)->fatal(alert, static_cast<$Throwable*>(cause))));
}

$Plaintext* SSLSocketImpl::handleEOF($EOFException* eofe) {
	$init($BaseSSLSocketImpl);
	if ($BaseSSLSocketImpl::requireCloseNotify || $nc(this->conContext)->handshakeContext != nullptr) {
		$var($SSLException, ssle, nullptr);
		if ($nc(this->conContext)->handshakeContext != nullptr) {
			$assign(ssle, $new($SSLHandshakeException, "Remote host terminated the handshake"_s));
		} else {
			$assign(ssle, $new($SSLProtocolException, "Remote host terminated the connection"_s));
		}
		if (eofe != nullptr) {
			$nc(ssle)->initCause(eofe);
		}
		$throw(ssle);
	} else {
		$nc(this->conContext)->isInputCloseNotified = true;
		shutdownInput();
		$init($Plaintext);
		return $Plaintext::PLAINTEXT_NULL;
	}
}

$String* SSLSocketImpl::getPeerHost() {
	return this->peerHost;
}

int32_t SSLSocketImpl::getPeerPort() {
	return getPort();
}

bool SSLSocketImpl::useDelegatedTask() {
	return false;
}

void SSLSocketImpl::shutdown() {
	$useLocalCurrentObjectStackCache();
	if (!isClosed()) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::fine("close the underlying socket"_s, $$new($ObjectArray, 0));
		}
		{
			$var($Throwable, var$0, nullptr);
			try {
				closeSocket($nc(this->conContext)->isNegotiated && !$nc(this->conContext)->isInputCloseNotified);
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				this->tlsIsClosed = true;
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

$String* SSLSocketImpl::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$3, $$str({"SSLSocket[hostname="_s, $(getPeerHost()), ", port="_s}));
	$var($String, var$2, $$concat(var$3, $$str(getPeerPort())));
	$var($String, var$1, $$concat(var$2, ", "_s));
	$var($String, var$0, $$concat(var$1, $nc(this->conContext)->conSession));
	return $concat(var$0, "]"_s);
}

void SSLSocketImpl::closeSocket(bool selfInitiated) {
	$useLocalCurrentObjectStackCache();
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
		$SSLLogger::fine($$str({"close the SSL connection "_s, (selfInitiated ? "(initiative)"_s : "(passive)"_s)}), $$new($ObjectArray, 0));
	}
	if (this->autoClose || !isLayered()) {
		{
			$var($SSLSocketInputRecord, inputRecord, nullptr);
			$var($InputRecord, patt62913$temp, $nc(this->conContext)->inputRecord);
			bool var$0 = $instanceOf($SSLSocketInputRecord, patt62913$temp);
			if (var$0) {
				$assign(inputRecord, $cast($SSLSocketInputRecord, patt62913$temp));
				var$0 = true;
			}
			if (var$0 && this->isConnected$) {
				if ($nc($nc(this->appInput)->readLock)->tryLock()) {
					{
						$var($Throwable, var$1, nullptr);
						try {
							$nc(inputRecord)->deplete(false);
						} catch ($Throwable& var$2) {
							$assign(var$1, var$2);
						} /*finally*/ {
							$nc($nc(this->appInput)->readLock)->unlock();
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				}
			}
		}
		$BaseSSLSocketImpl::close();
	} else if (selfInitiated) {
		bool var$3 = !$nc(this->conContext)->isInboundClosed();
		if (var$3 && !isInputShutdown()) {
			waitForClose();
		}
	}
}

void SSLSocketImpl::waitForClose() {
	$useLocalCurrentObjectStackCache();
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
		$SSLLogger::fine("wait for close_notify or alert"_s, $$new($ObjectArray, 0));
	}
	$nc($nc(this->appInput)->readLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			while (!$nc(this->conContext)->isInboundClosed()) {
				try {
					$var($Plaintext, plainText, decode(nullptr));
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
						$SSLLogger::finest("discard plaintext while waiting for close"_s, $$new($ObjectArray, {$of(plainText)}));
					}
				} catch ($Exception& e) {
					handleException(e);
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc($nc(this->appInput)->readLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$Set* SSLSocketImpl::supportedOptions() {
	return $BaseSSLSocketImpl::supportedOptions();
}

$Object* SSLSocketImpl::getOption($SocketOption* name) {
	return $of($BaseSSLSocketImpl::getOption(name));
}

$Socket* SSLSocketImpl::setOption($SocketOption* name, Object$* value) {
	return $BaseSSLSocketImpl::setOption(name, value);
}

void SSLSocketImpl::setSoTimeout(int32_t timeout) {
	$BaseSSLSocketImpl::setSoTimeout(timeout);
}

void SSLSocketImpl::setPerformancePreferences(int32_t connectionTime, int32_t latency, int32_t bandwidth) {
	$BaseSSLSocketImpl::setPerformancePreferences(connectionTime, latency, bandwidth);
}

$SocketAddress* SSLSocketImpl::getRemoteSocketAddress() {
	return $BaseSSLSocketImpl::getRemoteSocketAddress();
}

$SocketAddress* SSLSocketImpl::getLocalSocketAddress() {
	return $BaseSSLSocketImpl::getLocalSocketAddress();
}

void SSLSocketImpl::bind($SocketAddress* bindpoint) {
	$BaseSSLSocketImpl::bind(bindpoint);
}

void clinit$SSLSocketImpl($Class* class$) {
	SSLSocketImpl::trustNameService = $Utilities::getBooleanProperty("jdk.tls.trustNameService"_s, false);
}

SSLSocketImpl::SSLSocketImpl() {
}

$Class* SSLSocketImpl::load$($String* name, bool initialize) {
	$loadClass(SSLSocketImpl, name, initialize, &_SSLSocketImpl_ClassInfo_, clinit$SSLSocketImpl, allocate$SSLSocketImpl);
	return class$;
}

$Class* SSLSocketImpl::class$ = nullptr;

		} // ssl
	} // security
} // sun