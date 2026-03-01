#include <sun/security/ssl/SSLEngineImpl.h>

#include <java/io/IOException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/Runnable.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/ReadOnlyBufferException.h>
#include <java/util/List.h>
#include <java/util/Queue.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <java/util/function/BiFunction.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLEngineResult$HandshakeStatus.h>
#include <javax/net/ssl/SSLEngineResult$Status.h>
#include <javax/net/ssl/SSLEngineResult.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <javax/net/ssl/SSLKeyException.h>
#include <javax/net/ssl/SSLParameters.h>
#include <javax/net/ssl/SSLPeerUnverifiedException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <javax/net/ssl/SSLSession.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/Ciphertext.h>
#include <sun/security/ssl/ClientAuthType.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/ContentType.h>
#include <sun/security/ssl/DTLSInputRecord.h>
#include <sun/security/ssl/DTLSOutputRecord.h>
#include <sun/security/ssl/DTLSRecord.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/InputRecord.h>
#include <sun/security/ssl/NewSessionTicket.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/Plaintext.h>
#include <sun/security/ssl/PostHandshakeContext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLReadCipher.h>
#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLEngineImpl$DelegatedTask.h>
#include <sun/security/ssl/SSLEngineInputRecord.h>
#include <sun/security/ssl/SSLEngineOutputRecord.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLProducer.h>
#include <sun/security/ssl/SSLRecord.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLTransport.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <jcpp.h>

#undef BUFFER_OVERFLOW
#undef BUFFER_UNDERFLOW
#undef CLIENT_AUTH_NONE
#undef CLIENT_AUTH_REQUESTED
#undef CLIENT_AUTH_REQUIRED
#undef CLOSED
#undef FINISHED
#undef HANDSHAKE
#undef HANDSHAKE_FAILURE
#undef INTERNAL_ERROR
#undef NEED_TASK
#undef NEED_UNWRAP
#undef NEED_UNWRAP_AGAIN
#undef NEED_WRAP
#undef OK
#undef PLAINTEXT_NULL
#undef UNEXPECTED_MESSAGE

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ReadOnlyBufferException = ::java::nio::ReadOnlyBufferException;
using $Queue = ::java::util::Queue;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $BiFunction = ::java::util::function::BiFunction;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLEngineResult = ::javax::net::ssl::SSLEngineResult;
using $SSLEngineResult$HandshakeStatus = ::javax::net::ssl::SSLEngineResult$HandshakeStatus;
using $SSLEngineResult$Status = ::javax::net::ssl::SSLEngineResult$Status;
using $SSLException = ::javax::net::ssl::SSLException;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $SSLKeyException = ::javax::net::ssl::SSLKeyException;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $SSLPeerUnverifiedException = ::javax::net::ssl::SSLPeerUnverifiedException;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $Alert = ::sun::security::ssl::Alert;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $Ciphertext = ::sun::security::ssl::Ciphertext;
using $ClientAuthType = ::sun::security::ssl::ClientAuthType;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $ContentType = ::sun::security::ssl::ContentType;
using $DTLSInputRecord = ::sun::security::ssl::DTLSInputRecord;
using $DTLSOutputRecord = ::sun::security::ssl::DTLSOutputRecord;
using $DTLSRecord = ::sun::security::ssl::DTLSRecord;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $InputRecord = ::sun::security::ssl::InputRecord;
using $NewSessionTicket = ::sun::security::ssl::NewSessionTicket;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $Plaintext = ::sun::security::ssl::Plaintext;
using $PostHandshakeContext = ::sun::security::ssl::PostHandshakeContext;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher$SSLReadCipher = ::sun::security::ssl::SSLCipher$SSLReadCipher;
using $SSLCipher$SSLWriteCipher = ::sun::security::ssl::SSLCipher$SSLWriteCipher;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLEngineImpl$DelegatedTask = ::sun::security::ssl::SSLEngineImpl$DelegatedTask;
using $SSLEngineInputRecord = ::sun::security::ssl::SSLEngineInputRecord;
using $SSLEngineOutputRecord = ::sun::security::ssl::SSLEngineOutputRecord;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLProducer = ::sun::security::ssl::SSLProducer;
using $SSLRecord = ::sun::security::ssl::SSLRecord;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SSLTransport = ::sun::security::ssl::SSLTransport;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLEngineImpl_FieldInfo_[] = {
	{"sslContext", "Lsun/security/ssl/SSLContextImpl;", nullptr, $PRIVATE | $FINAL, $field(SSLEngineImpl, sslContext)},
	{"conContext", "Lsun/security/ssl/TransportContext;", nullptr, $FINAL, $field(SSLEngineImpl, conContext)},
	{"engineLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(SSLEngineImpl, engineLock)},
	{}
};

$MethodInfo _SSLEngineImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*getPeerHost", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getPeerPort", "()I", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;)V", nullptr, 0, $method(SSLEngineImpl, init$, void, $SSLContextImpl*)},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Ljava/lang/String;I)V", nullptr, 0, $method(SSLEngineImpl, init$, void, $SSLContextImpl*, $String*, int32_t)},
	{"beginHandshake", "()V", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, beginHandshake, void), "javax.net.ssl.SSLException"},
	{"checkParams", "([Ljava/nio/ByteBuffer;II[Ljava/nio/ByteBuffer;II)V", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLEngineImpl, checkParams, void, $ByteBufferArray*, int32_t, int32_t, $ByteBufferArray*, int32_t, int32_t)},
	{"checkTaskThrown", "()V", nullptr, $PRIVATE, $method(SSLEngineImpl, checkTaskThrown, void), "javax.net.ssl.SSLException"},
	{"closeInbound", "()V", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, closeInbound, void), "javax.net.ssl.SSLException"},
	{"closeOutbound", "()V", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, closeOutbound, void)},
	{"decode", "([Ljava/nio/ByteBuffer;II[Ljava/nio/ByteBuffer;II)Lsun/security/ssl/Plaintext;", nullptr, $PRIVATE, $method(SSLEngineImpl, decode, $Plaintext*, $ByteBufferArray*, int32_t, int32_t, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException"},
	{"encode", "([Ljava/nio/ByteBuffer;II[Ljava/nio/ByteBuffer;II)Lsun/security/ssl/Ciphertext;", nullptr, $PRIVATE, $method(SSLEngineImpl, encode, $Ciphertext*, $ByteBufferArray*, int32_t, int32_t, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException"},
	{"getApplicationProtocol", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getApplicationProtocol, $String*)},
	{"getDelegatedTask", "()Ljava/lang/Runnable;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getDelegatedTask, $Runnable*)},
	{"getEnableSessionCreation", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getEnableSessionCreation, bool)},
	{"getEnabledCipherSuites", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getEnabledCipherSuites, $StringArray*)},
	{"getEnabledProtocols", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getEnabledProtocols, $StringArray*)},
	{"getHandshakeApplicationProtocol", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getHandshakeApplicationProtocol, $String*)},
	{"getHandshakeApplicationProtocolSelector", "()Ljava/util/function/BiFunction;", "()Ljava/util/function/BiFunction<Ljavax/net/ssl/SSLEngine;Ljava/util/List<Ljava/lang/String;>;Ljava/lang/String;>;", $PUBLIC, $virtualMethod(SSLEngineImpl, getHandshakeApplicationProtocolSelector, $BiFunction*)},
	{"getHandshakeSession", "()Ljavax/net/ssl/SSLSession;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getHandshakeSession, $SSLSession*)},
	{"getHandshakeStatus", "()Ljavax/net/ssl/SSLEngineResult$HandshakeStatus;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getHandshakeStatus, $SSLEngineResult$HandshakeStatus*)},
	{"getNeedClientAuth", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getNeedClientAuth, bool)},
	{"getSSLParameters", "()Ljavax/net/ssl/SSLParameters;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getSSLParameters, $SSLParameters*)},
	{"getSession", "()Ljavax/net/ssl/SSLSession;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getSession, $SSLSession*)},
	{"getSupportedCipherSuites", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getSupportedCipherSuites, $StringArray*)},
	{"getSupportedProtocols", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getSupportedProtocols, $StringArray*)},
	{"getTaskThrown", "(Ljava/lang/Exception;)Ljavax/net/ssl/SSLException;", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLEngineImpl, getTaskThrown, $SSLException*, $Exception*)},
	{"getUseClientMode", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getUseClientMode, bool)},
	{"getWantClientAuth", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, getWantClientAuth, bool)},
	{"isInboundDone", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, isInboundDone, bool)},
	{"isOutboundDone", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, isOutboundDone, bool)},
	{"readRecord", "([Ljava/nio/ByteBuffer;II[Ljava/nio/ByteBuffer;II)Ljavax/net/ssl/SSLEngineResult;", nullptr, $PRIVATE, $method(SSLEngineImpl, readRecord, $SSLEngineResult*, $ByteBufferArray*, int32_t, int32_t, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException"},
	{"setEnableSessionCreation", "(Z)V", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, setEnableSessionCreation, void, bool)},
	{"setEnabledCipherSuites", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, setEnabledCipherSuites, void, $StringArray*)},
	{"setEnabledProtocols", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, setEnabledProtocols, void, $StringArray*)},
	{"setHandshakeApplicationProtocolSelector", "(Ljava/util/function/BiFunction;)V", "(Ljava/util/function/BiFunction<Ljavax/net/ssl/SSLEngine;Ljava/util/List<Ljava/lang/String;>;Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(SSLEngineImpl, setHandshakeApplicationProtocolSelector, void, $BiFunction*)},
	{"setNeedClientAuth", "(Z)V", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, setNeedClientAuth, void, bool)},
	{"setSSLParameters", "(Ljavax/net/ssl/SSLParameters;)V", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, setSSLParameters, void, $SSLParameters*)},
	{"setUseClientMode", "(Z)V", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, setUseClientMode, void, bool)},
	{"setWantClientAuth", "(Z)V", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, setWantClientAuth, void, bool)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, toString, $String*)},
	{"tryKeyUpdate", "(Ljavax/net/ssl/SSLEngineResult$HandshakeStatus;)Ljavax/net/ssl/SSLEngineResult$HandshakeStatus;", nullptr, $PRIVATE, $method(SSLEngineImpl, tryKeyUpdate, $SSLEngineResult$HandshakeStatus*, $SSLEngineResult$HandshakeStatus*), "java.io.IOException"},
	{"tryNewSessionTicket", "(Ljavax/net/ssl/SSLEngineResult$HandshakeStatus;)Ljavax/net/ssl/SSLEngineResult$HandshakeStatus;", nullptr, $PRIVATE, $method(SSLEngineImpl, tryNewSessionTicket, $SSLEngineResult$HandshakeStatus*, $SSLEngineResult$HandshakeStatus*), "java.io.IOException"},
	{"tryToFinishHandshake", "(B)Ljavax/net/ssl/SSLEngineResult$HandshakeStatus;", nullptr, $PRIVATE, $method(SSLEngineImpl, tryToFinishHandshake, $SSLEngineResult$HandshakeStatus*, int8_t)},
	{"unwrap", "(Ljava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;II)Ljavax/net/ssl/SSLEngineResult;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, unwrap, $SSLEngineResult*, $ByteBuffer*, $ByteBufferArray*, int32_t, int32_t), "javax.net.ssl.SSLException"},
	{"unwrap", "([Ljava/nio/ByteBuffer;II[Ljava/nio/ByteBuffer;II)Ljavax/net/ssl/SSLEngineResult;", nullptr, $PUBLIC, $method(SSLEngineImpl, unwrap, $SSLEngineResult*, $ByteBufferArray*, int32_t, int32_t, $ByteBufferArray*, int32_t, int32_t), "javax.net.ssl.SSLException"},
	{"useDelegatedTask", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, useDelegatedTask, bool)},
	{"wrap", "([Ljava/nio/ByteBuffer;IILjava/nio/ByteBuffer;)Ljavax/net/ssl/SSLEngineResult;", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl, wrap, $SSLEngineResult*, $ByteBufferArray*, int32_t, int32_t, $ByteBuffer*), "javax.net.ssl.SSLException"},
	{"wrap", "([Ljava/nio/ByteBuffer;II[Ljava/nio/ByteBuffer;II)Ljavax/net/ssl/SSLEngineResult;", nullptr, $PUBLIC, $method(SSLEngineImpl, wrap, $SSLEngineResult*, $ByteBufferArray*, int32_t, int32_t, $ByteBufferArray*, int32_t, int32_t), "javax.net.ssl.SSLException"},
	{"writeRecord", "([Ljava/nio/ByteBuffer;II[Ljava/nio/ByteBuffer;II)Ljavax/net/ssl/SSLEngineResult;", nullptr, $PRIVATE, $method(SSLEngineImpl, writeRecord, $SSLEngineResult*, $ByteBufferArray*, int32_t, int32_t, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException"},
	{}
};

$InnerClassInfo _SSLEngineImpl_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLEngineImpl$DelegatedTask", "sun.security.ssl.SSLEngineImpl", "DelegatedTask", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SSLEngineImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLEngineImpl",
	"javax.net.ssl.SSLEngine",
	"sun.security.ssl.SSLTransport",
	_SSLEngineImpl_FieldInfo_,
	_SSLEngineImpl_MethodInfo_,
	nullptr,
	nullptr,
	_SSLEngineImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLEngineImpl$DelegatedTask,sun.security.ssl.SSLEngineImpl$DelegatedTask$DelegatedAction"
};

$Object* allocate$SSLEngineImpl($Class* clazz) {
	return $of($alloc(SSLEngineImpl));
}

$String* SSLEngineImpl::getPeerHost() {
	 return this->$SSLEngine::getPeerHost();
}

int32_t SSLEngineImpl::getPeerPort() {
	 return this->$SSLEngine::getPeerPort();
}

int32_t SSLEngineImpl::hashCode() {
	 return this->$SSLEngine::hashCode();
}

bool SSLEngineImpl::equals(Object$* obj) {
	 return this->$SSLEngine::equals(obj);
}

$Object* SSLEngineImpl::clone() {
	 return this->$SSLEngine::clone();
}

void SSLEngineImpl::finalize() {
	this->$SSLEngine::finalize();
}

void SSLEngineImpl::init$($SSLContextImpl* sslContext) {
	SSLEngineImpl::init$(sslContext, nullptr, -1);
}

void SSLEngineImpl::init$($SSLContextImpl* sslContext, $String* host, int32_t port) {
	$useLocalCurrentObjectStackCache();
	$SSLEngine::init$(host, port);
	$set(this, engineLock, $new($ReentrantLock));
	$set(this, sslContext, sslContext);
	$var($HandshakeHash, handshakeHash, $new($HandshakeHash));
	if ($nc(sslContext)->isDTLS()) {
		$var($SSLContextImpl, var$0, sslContext);
		$var($InputRecord, var$1, static_cast<$InputRecord*>($new($DTLSInputRecord, handshakeHash)));
		$set(this, conContext, $new($TransportContext, var$0, this, var$1, $$new($DTLSOutputRecord, handshakeHash)));
	} else {
		$var($SSLContextImpl, var$2, sslContext);
		$var($InputRecord, var$3, static_cast<$InputRecord*>($new($SSLEngineInputRecord, handshakeHash)));
		$set(this, conContext, $new($TransportContext, var$2, this, var$3, $$new($SSLEngineOutputRecord, handshakeHash)));
	}
	if (host != nullptr) {
		$set($nc($nc(this->conContext)->sslConfig), serverNames, $Utilities::addToSNIServerNameList($nc($nc(this->conContext)->sslConfig)->serverNames, host));
	}
}

void SSLEngineImpl::beginHandshake() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if ($nc(this->conContext)->isUnsureMode) {
				$throwNew($IllegalStateException, "Client/Server mode has not yet been set."_s);
			}
			try {
				$nc(this->conContext)->kickstart();
			} catch ($IOException& ioe) {
				$init($Alert);
				$throw($($nc(this->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Couldn\'t kickstart handshaking"_s, ioe)));
			} catch ($Exception& ex) {
				$init($Alert);
				$throw($($nc(this->conContext)->fatal($Alert::INTERNAL_ERROR, "Fail to begin handshake"_s, ex)));
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$SSLEngineResult* SSLEngineImpl::wrap($ByteBufferArray* appData, int32_t offset, int32_t length, $ByteBuffer* netData) {
	return wrap(appData, offset, length, $$new($ByteBufferArray, {netData}), 0, 1);
}

$SSLEngineResult* SSLEngineImpl::wrap($ByteBufferArray* srcs, int32_t srcsOffset, int32_t srcsLength, $ByteBufferArray* dsts, int32_t dstsOffset, int32_t dstsLength) {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($SSLEngineResult, var$2, nullptr);
		bool return$1 = false;
		try {
			if ($nc(this->conContext)->isUnsureMode) {
				$throwNew($IllegalStateException, "Client/Server mode has not yet been set."_s);
			}
			checkTaskThrown();
			checkParams(srcs, srcsOffset, srcsLength, dsts, dstsOffset, dstsLength);
			try {
				$assign(var$2, writeRecord(srcs, srcsOffset, srcsLength, dsts, dstsOffset, dstsLength));
				return$1 = true;
				goto $finally;
			} catch ($SSLProtocolException& spe) {
				$init($Alert);
				$throw($($nc(this->conContext)->fatal($Alert::UNEXPECTED_MESSAGE, static_cast<$Throwable*>(spe))));
			} catch ($IOException& ioe) {
				$init($Alert);
				$throw($($nc(this->conContext)->fatal($Alert::INTERNAL_ERROR, "problem wrapping app data"_s, ioe)));
			} catch ($Exception& ex) {
				$init($Alert);
				$throw($($nc(this->conContext)->fatal($Alert::INTERNAL_ERROR, "Fail to wrap application data"_s, ex)));
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->engineLock)->unlock();
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

$SSLEngineResult* SSLEngineImpl::writeRecord($ByteBufferArray* srcs, int32_t srcsOffset, int32_t srcsLength, $ByteBufferArray* dsts, int32_t dstsOffset, int32_t dstsLength) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->conContext)->needHandshakeFinishedStatus) {
		$nc(this->conContext)->needHandshakeFinishedStatus = false;
		$init($SSLEngineResult$Status);
		$init($SSLEngineResult$HandshakeStatus);
		return $new($SSLEngineResult, $SSLEngineResult$Status::OK, $SSLEngineResult$HandshakeStatus::FINISHED, 0, 0);
	}
	if (isOutboundDone()) {
		$init($SSLEngineResult$Status);
		return $new($SSLEngineResult, $SSLEngineResult$Status::CLOSED, $($nc(this->conContext)->getHandshakeStatus()), 0, 0);
	}
	$var($HandshakeContext, hc, $nc(this->conContext)->handshakeContext);
	$SSLEngineResult$HandshakeStatus* hsStatus = nullptr;
	bool var$0 = !$nc(this->conContext)->isNegotiated && !$nc(this->conContext)->isBroken && !$nc(this->conContext)->isInboundClosed();
	if (var$0 && !$nc(this->conContext)->isOutboundClosed()) {
		$nc(this->conContext)->kickstart();
		hsStatus = $nc(this->conContext)->getHandshakeStatus();
		$init($SSLEngineResult$HandshakeStatus);
		if (hsStatus == $SSLEngineResult$HandshakeStatus::NEED_UNWRAP) {
			if (!$nc(this->sslContext)->isDTLS() || hc == nullptr || !$nc($nc(hc)->sslConfig)->enableRetransmissions || $nc($nc(this->conContext)->outputRecord)->firstMessage) {
				$init($SSLEngineResult$Status);
				return $new($SSLEngineResult, $SSLEngineResult$Status::OK, hsStatus, 0, 0);
			}
		}
	}
	if (hsStatus == nullptr) {
		hsStatus = $nc(this->conContext)->getHandshakeStatus();
	}
	$init($SSLEngineResult$HandshakeStatus);
	if (hsStatus == $SSLEngineResult$HandshakeStatus::NEED_TASK) {
		$init($SSLEngineResult$Status);
		return $new($SSLEngineResult, $SSLEngineResult$Status::OK, hsStatus, 0, 0);
	}
	int32_t dstsRemains = 0;
	for (int32_t i = dstsOffset; i < dstsOffset + dstsLength; ++i) {
		dstsRemains += $nc($nc(dsts)->get(i))->remaining();
	}
	if (dstsRemains < $nc($nc(this->conContext)->conSession)->getPacketBufferSize()) {
		$init($SSLEngineResult$Status);
		return $new($SSLEngineResult, $SSLEngineResult$Status::BUFFER_OVERFLOW, $($nc(this->conContext)->getHandshakeStatus()), 0, 0);
	}
	int32_t srcsRemains = 0;
	for (int32_t i = srcsOffset; i < srcsOffset + srcsLength; ++i) {
		srcsRemains += $nc($nc(srcs)->get(i))->remaining();
	}
	$var($Ciphertext, ciphertext, nullptr);
	try {
		bool var$1 = !$nc($nc(this->conContext)->outputRecord)->isEmpty();
		if (var$1 || (hc != nullptr && $nc(hc->sslConfig)->enableRetransmissions && $nc(hc->sslContext)->isDTLS() && hsStatus == $SSLEngineResult$HandshakeStatus::NEED_UNWRAP)) {
			$assign(ciphertext, encode(nullptr, 0, 0, dsts, dstsOffset, dstsLength));
		}
		if (ciphertext == nullptr && srcsRemains != 0) {
			$assign(ciphertext, encode(srcs, srcsOffset, srcsLength, dsts, dstsOffset, dstsLength));
		}
	} catch ($IOException& ioe) {
		if ($instanceOf($SSLException, ioe)) {
			$throw(ioe);
		} else {
			$throwNew($SSLException, "Write problems"_s, ioe);
		}
	}
	$init($SSLEngineResult$Status);
	$SSLEngineResult$Status* status = (isOutboundDone() ? $SSLEngineResult$Status::CLOSED : $SSLEngineResult$Status::OK);
	if (ciphertext != nullptr && ciphertext->handshakeStatus != nullptr) {
		hsStatus = ciphertext->handshakeStatus;
	} else {
		hsStatus = $nc(this->conContext)->getHandshakeStatus();
		if (ciphertext == nullptr && !$nc(this->conContext)->isNegotiated && $nc(this->conContext)->isInboundClosed() && hsStatus == $SSLEngineResult$HandshakeStatus::NEED_WRAP) {
			status = $SSLEngineResult$Status::CLOSED;
		}
	}
	int32_t deltaSrcs = srcsRemains;
	for (int32_t i = srcsOffset; i < srcsOffset + srcsLength; ++i) {
		deltaSrcs -= $nc($nc(srcs)->get(i))->remaining();
	}
	int32_t deltaDsts = dstsRemains;
	for (int32_t i = dstsOffset; i < dstsOffset + dstsLength; ++i) {
		deltaDsts -= $nc($nc(dsts)->get(i))->remaining();
	}
	return $new($SSLEngineResult, status, hsStatus, deltaSrcs, deltaDsts, ciphertext != nullptr ? $nc(ciphertext)->recordSN : (int64_t)-1);
}

$Ciphertext* SSLEngineImpl::encode($ByteBufferArray* srcs, int32_t srcsOffset, int32_t srcsLength, $ByteBufferArray* dsts, int32_t dstsOffset, int32_t dstsLength) {
	$useLocalCurrentObjectStackCache();
	$var($Ciphertext, ciphertext, nullptr);
	try {
		$assign(ciphertext, $nc($nc(this->conContext)->outputRecord)->encode(srcs, srcsOffset, srcsLength, dsts, dstsOffset, dstsLength));
	} catch ($SSLHandshakeException& she) {
		$init($Alert);
		$throw($($nc(this->conContext)->fatal($Alert::HANDSHAKE_FAILURE, static_cast<$Throwable*>(she))));
	} catch ($IOException& e) {
		$init($Alert);
		$throw($($nc(this->conContext)->fatal($Alert::UNEXPECTED_MESSAGE, static_cast<$Throwable*>(e))));
	}
	if (ciphertext == nullptr) {
		return nullptr;
	}
	bool needRetransmission = $nc($nc(this->conContext)->sslContext)->isDTLS() && $nc(this->conContext)->handshakeContext != nullptr && $nc($nc($nc(this->conContext)->handshakeContext)->sslConfig)->enableRetransmissions;
	$SSLEngineResult$HandshakeStatus* hsStatus = tryToFinishHandshake($nc(ciphertext)->contentType);
	$init($SSLEngineResult$HandshakeStatus);
	$init($SSLHandshake);
	if (needRetransmission && hsStatus == $SSLEngineResult$HandshakeStatus::FINISHED && $nc($nc(this->conContext)->sslContext)->isDTLS() && $nc(ciphertext)->handshakeType == $SSLHandshake::FINISHED->id) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,verbose"_s)) {
			$SSLLogger::finest("retransmit the last flight messages"_s, $$new($ObjectArray, 0));
		}
		$nc($nc(this->conContext)->outputRecord)->launchRetransmission();
		hsStatus = $SSLEngineResult$HandshakeStatus::NEED_WRAP;
	}
	if (hsStatus == nullptr) {
		hsStatus = $nc(this->conContext)->getHandshakeStatus();
	}
	bool var$0 = $nc($nc(this->conContext)->outputRecord)->seqNumIsHuge();
	if (var$0 || $nc($nc($nc(this->conContext)->outputRecord)->writeCipher)->atKeyLimit()) {
		hsStatus = tryKeyUpdate(hsStatus);
	}
	if ($nc($nc(this->conContext)->conSession)->updateNST && !$nc($nc(this->conContext)->sslConfig)->isClientMode) {
		hsStatus = tryNewSessionTicket(hsStatus);
	}
	$set($nc(ciphertext), handshakeStatus, hsStatus);
	return ciphertext;
}

$SSLEngineResult$HandshakeStatus* SSLEngineImpl::tryToFinishHandshake(int8_t contentType) {
	$SSLEngineResult$HandshakeStatus* hsStatus = nullptr;
	$init($ContentType);
	if ((contentType == $ContentType::HANDSHAKE->id) && $nc($nc(this->conContext)->outputRecord)->isEmpty()) {
		if ($nc(this->conContext)->handshakeContext == nullptr) {
			$init($SSLEngineResult$HandshakeStatus);
			hsStatus = $SSLEngineResult$HandshakeStatus::FINISHED;
		} else if ($nc(this->conContext)->isPostHandshakeContext()) {
			hsStatus = $nc(this->conContext)->finishPostHandshake();
		} else if ($nc($nc(this->conContext)->handshakeContext)->handshakeFinished) {
			hsStatus = $nc(this->conContext)->finishHandshake();
		}
	}
	return hsStatus;
}

$SSLEngineResult$HandshakeStatus* SSLEngineImpl::tryKeyUpdate($SSLEngineResult$HandshakeStatus* currentHandshakeStatus) {
	bool var$0 = ($nc(this->conContext)->handshakeContext == nullptr) && !$nc(this->conContext)->isOutboundClosed();
	if (var$0 && !$nc(this->conContext)->isInboundClosed() && !$nc(this->conContext)->isBroken) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::finest("trigger key update"_s, $$new($ObjectArray, 0));
		}
		beginHandshake();
		return $nc(this->conContext)->getHandshakeStatus();
	}
	return currentHandshakeStatus;
}

$SSLEngineResult$HandshakeStatus* SSLEngineImpl::tryNewSessionTicket($SSLEngineResult$HandshakeStatus* currentHandshakeStatus) {
	$useLocalCurrentObjectStackCache();
	bool var$1 = ($nc(this->conContext)->handshakeContext == nullptr) && $nc($nc(this->conContext)->protocolVersion)->useTLS13PlusSpec();
	bool var$0 = var$1 && !$nc(this->conContext)->isOutboundClosed();
	if (var$0 && !$nc(this->conContext)->isInboundClosed() && !$nc(this->conContext)->isBroken) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::finest("trigger NST"_s, $$new($ObjectArray, 0));
		}
		$nc($nc(this->conContext)->conSession)->updateNST = false;
		$init($NewSessionTicket);
		$nc($NewSessionTicket::t13PosthandshakeProducer)->produce($$new($PostHandshakeContext, this->conContext));
		return $nc(this->conContext)->getHandshakeStatus();
	}
	return currentHandshakeStatus;
}

void SSLEngineImpl::checkParams($ByteBufferArray* srcs, int32_t srcsOffset, int32_t srcsLength, $ByteBufferArray* dsts, int32_t dstsOffset, int32_t dstsLength) {
	$init(SSLEngineImpl);
	$useLocalCurrentObjectStackCache();
	if ((srcs == nullptr) || (dsts == nullptr)) {
		$throwNew($IllegalArgumentException, "source or destination buffer is null"_s);
	}
	if ((dstsOffset < 0) || (dstsLength < 0) || (dstsOffset > $nc(dsts)->length - dstsLength)) {
		$throwNew($IndexOutOfBoundsException, "index out of bound of the destination buffers"_s);
	}
	if ((srcsOffset < 0) || (srcsLength < 0) || (srcsOffset > $nc(srcs)->length - srcsLength)) {
		$throwNew($IndexOutOfBoundsException, "index out of bound of the source buffers"_s);
	}
	for (int32_t i = dstsOffset; i < dstsOffset + dstsLength; ++i) {
		if ($nc(dsts)->get(i) == nullptr) {
			$throwNew($IllegalArgumentException, $$str({"destination buffer["_s, $$str(i), "] == null"_s}));
		}
		if ($nc($nc(dsts)->get(i))->isReadOnly()) {
			$throwNew($ReadOnlyBufferException);
		}
	}
	for (int32_t i = srcsOffset; i < srcsOffset + srcsLength; ++i) {
		if ($nc(srcs)->get(i) == nullptr) {
			$throwNew($IllegalArgumentException, $$str({"source buffer["_s, $$str(i), "] == null"_s}));
		}
	}
}

$SSLEngineResult* SSLEngineImpl::unwrap($ByteBuffer* src, $ByteBufferArray* dsts, int32_t offset, int32_t length) {
	return unwrap($$new($ByteBufferArray, {src}), 0, 1, dsts, offset, length);
}

$SSLEngineResult* SSLEngineImpl::unwrap($ByteBufferArray* srcs, int32_t srcsOffset, int32_t srcsLength, $ByteBufferArray* dsts, int32_t dstsOffset, int32_t dstsLength) {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($SSLEngineResult, var$2, nullptr);
		bool return$1 = false;
		try {
			if ($nc(this->conContext)->isUnsureMode) {
				$throwNew($IllegalStateException, "Client/Server mode has not yet been set."_s);
			}
			checkTaskThrown();
			checkParams(srcs, srcsOffset, srcsLength, dsts, dstsOffset, dstsLength);
			try {
				$assign(var$2, readRecord(srcs, srcsOffset, srcsLength, dsts, dstsOffset, dstsLength));
				return$1 = true;
				goto $finally;
			} catch ($SSLProtocolException& spe) {
				$init($Alert);
				$throw($($nc(this->conContext)->fatal($Alert::UNEXPECTED_MESSAGE, $(spe->getMessage()), spe)));
			} catch ($IOException& ioe) {
				$init($Alert);
				$throw($($nc(this->conContext)->fatal($Alert::INTERNAL_ERROR, "problem unwrapping net record"_s, ioe)));
			} catch ($Exception& ex) {
				$init($Alert);
				$throw($($nc(this->conContext)->fatal($Alert::INTERNAL_ERROR, "Fail to unwrap network record"_s, ex)));
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->engineLock)->unlock();
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

$SSLEngineResult* SSLEngineImpl::readRecord($ByteBufferArray* srcs, int32_t srcsOffset, int32_t srcsLength, $ByteBufferArray* dsts, int32_t dstsOffset, int32_t dstsLength) {
	$useLocalCurrentObjectStackCache();
	if (isInboundDone()) {
		$init($SSLEngineResult$Status);
		return $new($SSLEngineResult, $SSLEngineResult$Status::CLOSED, $($nc(this->conContext)->getHandshakeStatus()), 0, 0);
	}
	$SSLEngineResult$HandshakeStatus* hsStatus = nullptr;
	bool var$0 = !$nc(this->conContext)->isNegotiated && !$nc(this->conContext)->isBroken && !$nc(this->conContext)->isInboundClosed();
	if (var$0 && !$nc(this->conContext)->isOutboundClosed()) {
		$nc(this->conContext)->kickstart();
		hsStatus = $nc(this->conContext)->getHandshakeStatus();
		$init($SSLEngineResult$HandshakeStatus);
		if (hsStatus == $SSLEngineResult$HandshakeStatus::NEED_WRAP) {
			$init($SSLEngineResult$Status);
			return $new($SSLEngineResult, $SSLEngineResult$Status::OK, hsStatus, 0, 0);
		}
	}
	if (hsStatus == nullptr) {
		hsStatus = $nc(this->conContext)->getHandshakeStatus();
	}
	$init($SSLEngineResult$HandshakeStatus);
	if (hsStatus == $SSLEngineResult$HandshakeStatus::NEED_TASK) {
		$init($SSLEngineResult$Status);
		return $new($SSLEngineResult, $SSLEngineResult$Status::OK, hsStatus, 0, 0);
	}
	if (hsStatus == $SSLEngineResult$HandshakeStatus::NEED_UNWRAP_AGAIN) {
		$var($Plaintext, plainText, nullptr);
		try {
			$assign(plainText, decode(nullptr, 0, 0, dsts, dstsOffset, dstsLength));
		} catch ($IOException& ioe) {
			if ($instanceOf($SSLException, ioe)) {
				$throw(ioe);
			} else {
				$throwNew($SSLException, "readRecord"_s, ioe);
			}
		}
		$init($SSLEngineResult$Status);
		$SSLEngineResult$Status* status = (isInboundDone() ? $SSLEngineResult$Status::CLOSED : $SSLEngineResult$Status::OK);
		if ($nc(plainText)->handshakeStatus != nullptr) {
			hsStatus = plainText->handshakeStatus;
		} else {
			hsStatus = $nc(this->conContext)->getHandshakeStatus();
		}
		return $new($SSLEngineResult, status, hsStatus, 0, 0, $nc(plainText)->recordSN);
	}
	int32_t srcsRemains = 0;
	for (int32_t i = srcsOffset; i < srcsOffset + srcsLength; ++i) {
		srcsRemains += $nc($nc(srcs)->get(i))->remaining();
	}
	if (srcsRemains == 0) {
		$init($SSLEngineResult$Status);
		return $new($SSLEngineResult, $SSLEngineResult$Status::BUFFER_UNDERFLOW, hsStatus, 0, 0);
	}
	int32_t packetLen = 0;
	try {
		packetLen = $nc($nc(this->conContext)->inputRecord)->bytesInCompletePacket(srcs, srcsOffset, srcsLength);
	} catch ($SSLException& ssle) {
		if ($nc(this->sslContext)->isDTLS()) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,verbose"_s)) {
				$SSLLogger::finest("Discard invalid DTLS records"_s, $$new($ObjectArray, {$of(ssle)}));
			}
			for (int32_t i = srcsOffset; i < srcsOffset + srcsLength; ++i) {
				$nc($nc(srcs)->get(i))->position($nc(srcs->get(i))->limit());
			}
			$init($SSLEngineResult$Status);
			$SSLEngineResult$Status* status = (isInboundDone() ? $SSLEngineResult$Status::CLOSED : $SSLEngineResult$Status::OK);
			if (hsStatus == nullptr) {
				hsStatus = $nc(this->conContext)->getHandshakeStatus();
			}
			return $new($SSLEngineResult, status, hsStatus, srcsRemains, 0, -1);
		} else {
			$throw(ssle);
		}
	}
	if (packetLen > $nc($nc(this->conContext)->conSession)->getPacketBufferSize()) {
		int32_t largestRecordSize = $nc(this->sslContext)->isDTLS() ? $DTLSRecord::maxRecordSize : $SSLRecord::maxLargeRecordSize;
		if ((packetLen <= largestRecordSize) && !$nc(this->sslContext)->isDTLS()) {
			$nc($nc(this->conContext)->conSession)->expandBufferSizes();
		}
		largestRecordSize = $nc($nc(this->conContext)->conSession)->getPacketBufferSize();
		if (packetLen > largestRecordSize) {
			$throwNew($SSLProtocolException, $$str({"Input record too big: max = "_s, $$str(largestRecordSize), " len = "_s, $$str(packetLen)}));
		}
	}
	int32_t dstsRemains = 0;
	for (int32_t i = dstsOffset; i < dstsOffset + dstsLength; ++i) {
		dstsRemains += $nc($nc(dsts)->get(i))->remaining();
	}
	if ($nc(this->conContext)->isNegotiated) {
		int32_t FragLen = $nc($nc(this->conContext)->inputRecord)->estimateFragmentSize(packetLen);
		if (FragLen > dstsRemains) {
			$init($SSLEngineResult$Status);
			return $new($SSLEngineResult, $SSLEngineResult$Status::BUFFER_OVERFLOW, hsStatus, 0, 0);
		}
	}
	if ((packetLen == -1) || (srcsRemains < packetLen)) {
		$init($SSLEngineResult$Status);
		return $new($SSLEngineResult, $SSLEngineResult$Status::BUFFER_UNDERFLOW, hsStatus, 0, 0);
	}
	$var($Plaintext, plainText, nullptr);
	try {
		$assign(plainText, decode(srcs, srcsOffset, srcsLength, dsts, dstsOffset, dstsLength));
	} catch ($IOException& ioe) {
		if ($instanceOf($SSLException, ioe)) {
			$throw(ioe);
		} else {
			$throwNew($SSLException, "readRecord"_s, ioe);
		}
	}
	$init($SSLEngineResult$Status);
	$SSLEngineResult$Status* status = (isInboundDone() ? $SSLEngineResult$Status::CLOSED : $SSLEngineResult$Status::OK);
	if ($nc(plainText)->handshakeStatus != nullptr) {
		hsStatus = plainText->handshakeStatus;
	} else {
		hsStatus = $nc(this->conContext)->getHandshakeStatus();
	}
	int32_t deltaNet = srcsRemains;
	for (int32_t i = srcsOffset; i < srcsOffset + srcsLength; ++i) {
		deltaNet -= $nc($nc(srcs)->get(i))->remaining();
	}
	int32_t deltaApp = dstsRemains;
	for (int32_t i = dstsOffset; i < dstsOffset + dstsLength; ++i) {
		deltaApp -= $nc($nc(dsts)->get(i))->remaining();
	}
	return $new($SSLEngineResult, status, hsStatus, deltaNet, deltaApp, $nc(plainText)->recordSN);
}

$Plaintext* SSLEngineImpl::decode($ByteBufferArray* srcs, int32_t srcsOffset, int32_t srcsLength, $ByteBufferArray* dsts, int32_t dstsOffset, int32_t dstsLength) {
	$var($Plaintext, pt, $SSLTransport::decode(this->conContext, srcs, srcsOffset, srcsLength, dsts, dstsOffset, dstsLength));
	$init($Plaintext);
	if (pt != $Plaintext::PLAINTEXT_NULL) {
		$SSLEngineResult$HandshakeStatus* hsStatus = tryToFinishHandshake($nc(pt)->contentType);
		if (hsStatus == nullptr) {
			$set($nc(pt), handshakeStatus, $nc(this->conContext)->getHandshakeStatus());
		} else {
			$set($nc(pt), handshakeStatus, hsStatus);
		}
		bool var$0 = $nc($nc(this->conContext)->inputRecord)->seqNumIsHuge();
		if (var$0 || $nc($nc($nc(this->conContext)->inputRecord)->readCipher)->atKeyLimit()) {
			$set($nc(pt), handshakeStatus, tryKeyUpdate(pt->handshakeStatus));
		}
	}
	return pt;
}

$Runnable* SSLEngineImpl::getDelegatedTask() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($Runnable, var$2, nullptr);
		bool return$1 = false;
		try {
			if ($nc(this->conContext)->handshakeContext != nullptr && !$nc($nc(this->conContext)->handshakeContext)->taskDelegated && !$nc($nc($nc(this->conContext)->handshakeContext)->delegatedActions)->isEmpty()) {
				$nc($nc(this->conContext)->handshakeContext)->taskDelegated = true;
				$assign(var$2, $new($SSLEngineImpl$DelegatedTask, this));
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->engineLock)->unlock();
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

void SSLEngineImpl::closeInbound() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			if (isInboundDone()) {
				return$1 = true;
				goto $finally;
			}
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
				$SSLLogger::finest("Closing inbound of SSLEngine"_s, $$new($ObjectArray, 0));
			}
			if (!$nc(this->conContext)->isInputCloseNotified && ($nc(this->conContext)->isNegotiated || $nc(this->conContext)->handshakeContext != nullptr)) {
				$init($Alert);
				$throw($($nc(this->conContext)->fatal($Alert::INTERNAL_ERROR, "closing inbound before receiving peer\'s close_notify"_s)));
			}
			$nc(this->conContext)->closeInbound();
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			$nc(this->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

bool SSLEngineImpl::isInboundDone() {
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			var$2 = $nc(this->conContext)->isInboundClosed();
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->engineLock)->unlock();
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

void SSLEngineImpl::closeOutbound() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			if ($nc(this->conContext)->isOutboundClosed()) {
				return$1 = true;
				goto $finally;
			}
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
				$SSLLogger::finest("Closing outbound of SSLEngine"_s, $$new($ObjectArray, 0));
			}
			$nc(this->conContext)->closeOutbound();
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			$nc(this->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

bool SSLEngineImpl::isOutboundDone() {
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			var$2 = $nc(this->conContext)->isOutboundDone();
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->engineLock)->unlock();
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

$StringArray* SSLEngineImpl::getSupportedCipherSuites() {
	return $CipherSuite::namesOf($($nc(this->sslContext)->getSupportedCipherSuites()));
}

$StringArray* SSLEngineImpl::getEnabledCipherSuites() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
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
			$nc(this->engineLock)->unlock();
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

void SSLEngineImpl::setEnabledCipherSuites($StringArray* suites) {
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$set($nc($nc(this->conContext)->sslConfig), enabledCipherSuites, $CipherSuite::validValuesOf(suites));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$StringArray* SSLEngineImpl::getSupportedProtocols() {
	return $ProtocolVersion::toStringArray($($nc(this->sslContext)->getSupportedProtocolVersions()));
}

$StringArray* SSLEngineImpl::getEnabledProtocols() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
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
			$nc(this->engineLock)->unlock();
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

void SSLEngineImpl::setEnabledProtocols($StringArray* protocols) {
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (protocols == nullptr) {
				$throwNew($IllegalArgumentException, "Protocols cannot be null"_s);
			}
			$set($nc($nc(this->conContext)->sslConfig), enabledProtocols, $ProtocolVersion::namesOf(protocols));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$SSLSession* SSLEngineImpl::getSession() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($SSLSession, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc(this->conContext)->conSession);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->engineLock)->unlock();
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

$SSLSession* SSLEngineImpl::getHandshakeSession() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
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
			$nc(this->engineLock)->unlock();
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

$SSLEngineResult$HandshakeStatus* SSLEngineImpl::getHandshakeStatus() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($SSLEngineResult$HandshakeStatus, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc(this->conContext)->getHandshakeStatus());
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->engineLock)->unlock();
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

void SSLEngineImpl::setUseClientMode(bool mode) {
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->conContext)->setUseClientMode(mode);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool SSLEngineImpl::getUseClientMode() {
	$nc(this->engineLock)->lock();
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
			$nc(this->engineLock)->unlock();
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

void SSLEngineImpl::setNeedClientAuth(bool need) {
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$init($ClientAuthType);
			$set($nc($nc(this->conContext)->sslConfig), clientAuthType, need ? $ClientAuthType::CLIENT_AUTH_REQUIRED : $ClientAuthType::CLIENT_AUTH_NONE);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool SSLEngineImpl::getNeedClientAuth() {
	$nc(this->engineLock)->lock();
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
			$nc(this->engineLock)->unlock();
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

void SSLEngineImpl::setWantClientAuth(bool want) {
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$init($ClientAuthType);
			$set($nc($nc(this->conContext)->sslConfig), clientAuthType, want ? $ClientAuthType::CLIENT_AUTH_REQUESTED : $ClientAuthType::CLIENT_AUTH_NONE);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool SSLEngineImpl::getWantClientAuth() {
	$nc(this->engineLock)->lock();
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
			$nc(this->engineLock)->unlock();
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

void SSLEngineImpl::setEnableSessionCreation(bool flag) {
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc($nc(this->conContext)->sslConfig)->enableSessionCreation = flag;
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool SSLEngineImpl::getEnableSessionCreation() {
	$nc(this->engineLock)->lock();
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
			$nc(this->engineLock)->unlock();
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

$SSLParameters* SSLEngineImpl::getSSLParameters() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
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
			$nc(this->engineLock)->unlock();
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

void SSLEngineImpl::setSSLParameters($SSLParameters* params) {
	$nc(this->engineLock)->lock();
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
			$nc(this->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$String* SSLEngineImpl::getApplicationProtocol() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
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
			$nc(this->engineLock)->unlock();
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

$String* SSLEngineImpl::getHandshakeApplicationProtocol() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($String, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc(this->conContext)->handshakeContext == nullptr ? ($String*)nullptr : $nc($nc(this->conContext)->handshakeContext)->applicationProtocol);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->engineLock)->unlock();
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

void SSLEngineImpl::setHandshakeApplicationProtocolSelector($BiFunction* selector) {
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$set($nc($nc(this->conContext)->sslConfig), engineAPSelector, selector);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$BiFunction* SSLEngineImpl::getHandshakeApplicationProtocolSelector() {
	$useLocalCurrentObjectStackCache();
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($BiFunction, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc($nc(this->conContext)->sslConfig)->engineAPSelector);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->engineLock)->unlock();
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

bool SSLEngineImpl::useDelegatedTask() {
	return true;
}

$String* SSLEngineImpl::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$3, $$str({"SSLEngine[hostname="_s, $(getPeerHost()), ", port="_s}));
	$var($String, var$2, $$concat(var$3, $$str(getPeerPort())));
	$var($String, var$1, $$concat(var$2, ", "_s));
	$var($String, var$0, $$concat(var$1, $nc(this->conContext)->conSession));
	return $concat(var$0, "]"_s);
}

void SSLEngineImpl::checkTaskThrown() {
	$useLocalCurrentObjectStackCache();
	$var($Exception, exc, nullptr);
	$nc(this->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($HandshakeContext, hc, $nc(this->conContext)->handshakeContext);
			if ((hc != nullptr) && (hc->delegatedThrown != nullptr)) {
				$assign(exc, hc->delegatedThrown);
				$set(hc, delegatedThrown, nullptr);
			}
			if ($nc(this->conContext)->delegatedThrown != nullptr) {
				if (exc != nullptr) {
					if ($nc(this->conContext)->delegatedThrown == exc) {
						$set($nc(this->conContext), delegatedThrown, nullptr);
					}
				} else {
					$assign(exc, $nc(this->conContext)->delegatedThrown);
					$set($nc(this->conContext), delegatedThrown, nullptr);
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if (exc == nullptr) {
		return;
	}
	if ($instanceOf($SSLException, exc)) {
		$throw($cast($SSLException, exc));
	} else if ($instanceOf($RuntimeException, exc)) {
		$throw($cast($RuntimeException, exc));
	} else {
		$throw($(getTaskThrown(exc)));
	}
}

$SSLException* SSLEngineImpl::getTaskThrown($Exception* taskThrown) {
	$init(SSLEngineImpl);
	$useLocalCurrentObjectStackCache();
	$var($String, msg, $nc(taskThrown)->getMessage());
	if (msg == nullptr) {
		$assign(msg, "Delegated task threw Exception or Error"_s);
	}
	if ($instanceOf($RuntimeException, taskThrown)) {
		$throwNew($RuntimeException, msg, taskThrown);
	} else if ($instanceOf($SSLHandshakeException, taskThrown)) {
		return $cast($SSLHandshakeException, $$new($SSLHandshakeException, msg)->initCause(taskThrown));
	} else if ($instanceOf($SSLKeyException, taskThrown)) {
		return $cast($SSLKeyException, $$new($SSLKeyException, msg)->initCause(taskThrown));
	} else if ($instanceOf($SSLPeerUnverifiedException, taskThrown)) {
		return $cast($SSLPeerUnverifiedException, $$new($SSLPeerUnverifiedException, msg)->initCause(taskThrown));
	} else if ($instanceOf($SSLProtocolException, taskThrown)) {
		return $cast($SSLProtocolException, $$new($SSLProtocolException, msg)->initCause(taskThrown));
	} else if ($instanceOf($SSLException, taskThrown)) {
		return $cast($SSLException, taskThrown);
	} else {
		return $new($SSLException, msg, taskThrown);
	}
}

SSLEngineImpl::SSLEngineImpl() {
}

$Class* SSLEngineImpl::load$($String* name, bool initialize) {
	$loadClass(SSLEngineImpl, name, initialize, &_SSLEngineImpl_ClassInfo_, allocate$SSLEngineImpl);
	return class$;
}

$Class* SSLEngineImpl::class$ = nullptr;

		} // ssl
	} // security
} // sun