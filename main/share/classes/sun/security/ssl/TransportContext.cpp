#include <sun/security/ssl/TransportContext.h>

#include <java/io/IOException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Runnable.h>
#include <java/lang/ThreadGroup.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Queue.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <javax/crypto/SecretKey.h>
#include <javax/net/ssl/HandshakeCompletedEvent.h>
#include <javax/net/ssl/SSLEngineResult$HandshakeStatus.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLSession.h>
#include <javax/net/ssl/SSLSocket.h>
#include <sun/security/ssl/Alert$Level.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/ContentType.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/InputRecord.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/Plaintext.h>
#include <sun/security/ssl/PostHandshakeContext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLReadCipher.h>
#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLConsumer.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLSocketImpl.h>
#include <sun/security/ssl/SSLTransport.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/TransportContext$1.h>
#include <sun/security/ssl/TransportContext$NotifyHandshake.h>
#include <jcpp.h>

#undef CLOSE_NOTIFY
#undef FATAL
#undef FINISHED
#undef KEY_UPDATE
#undef NEED_TASK
#undef NEED_UNWRAP
#undef NEED_UNWRAP_AGAIN
#undef NEED_WRAP
#undef NEW_SESSION_TICKET
#undef NOT_HANDSHAKING
#undef UNEXPECTED_MESSAGE
#undef USER_CANCELED
#undef WARNING

using $IOException = ::java::io::IOException;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $ThreadGroup = ::java::lang::ThreadGroup;
using $AccessController = ::java::security::AccessController;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $Queue = ::java::util::Queue;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $HandshakeCompletedEvent = ::javax::net::ssl::HandshakeCompletedEvent;
using $SSLEngineResult$HandshakeStatus = ::javax::net::ssl::SSLEngineResult$HandshakeStatus;
using $SSLException = ::javax::net::ssl::SSLException;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $SSLSocket = ::javax::net::ssl::SSLSocket;
using $Alert = ::sun::security::ssl::Alert;
using $Alert$Level = ::sun::security::ssl::Alert$Level;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $ContentType = ::sun::security::ssl::ContentType;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $InputRecord = ::sun::security::ssl::InputRecord;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $Plaintext = ::sun::security::ssl::Plaintext;
using $PostHandshakeContext = ::sun::security::ssl::PostHandshakeContext;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLConsumer = ::sun::security::ssl::SSLConsumer;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SSLSocketImpl = ::sun::security::ssl::SSLSocketImpl;
using $SSLTransport = ::sun::security::ssl::SSLTransport;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $TransportContext$1 = ::sun::security::ssl::TransportContext$1;
using $TransportContext$NotifyHandshake = ::sun::security::ssl::TransportContext$NotifyHandshake;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _TransportContext_FieldInfo_[] = {
	{"transport", "Lsun/security/ssl/SSLTransport;", nullptr, $FINAL, $field(TransportContext, transport)},
	{"consumers", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Byte;Lsun/security/ssl/SSLConsumer;>;", $FINAL, $field(TransportContext, consumers)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $FINAL, $field(TransportContext, acc)},
	{"sslContext", "Lsun/security/ssl/SSLContextImpl;", nullptr, $FINAL, $field(TransportContext, sslContext)},
	{"sslConfig", "Lsun/security/ssl/SSLConfiguration;", nullptr, $FINAL, $field(TransportContext, sslConfig)},
	{"inputRecord", "Lsun/security/ssl/InputRecord;", nullptr, $FINAL, $field(TransportContext, inputRecord)},
	{"outputRecord", "Lsun/security/ssl/OutputRecord;", nullptr, $FINAL, $field(TransportContext, outputRecord)},
	{"isUnsureMode", "Z", nullptr, 0, $field(TransportContext, isUnsureMode)},
	{"isNegotiated", "Z", nullptr, 0, $field(TransportContext, isNegotiated)},
	{"isBroken", "Z", nullptr, 0, $field(TransportContext, isBroken)},
	{"isInputCloseNotified", "Z", nullptr, 0, $field(TransportContext, isInputCloseNotified)},
	{"peerUserCanceled", "Z", nullptr, 0, $field(TransportContext, peerUserCanceled)},
	{"closeReason", "Ljava/lang/Exception;", nullptr, 0, $field(TransportContext, closeReason)},
	{"delegatedThrown", "Ljava/lang/Exception;", nullptr, 0, $field(TransportContext, delegatedThrown)},
	{"needHandshakeFinishedStatus", "Z", nullptr, 0, $field(TransportContext, needHandshakeFinishedStatus)},
	{"hasDelegatedFinished", "Z", nullptr, 0, $field(TransportContext, hasDelegatedFinished)},
	{"conSession", "Lsun/security/ssl/SSLSessionImpl;", nullptr, 0, $field(TransportContext, conSession)},
	{"protocolVersion", "Lsun/security/ssl/ProtocolVersion;", nullptr, 0, $field(TransportContext, protocolVersion)},
	{"applicationProtocol", "Ljava/lang/String;", nullptr, 0, $field(TransportContext, applicationProtocol)},
	{"handshakeContext", "Lsun/security/ssl/HandshakeContext;", nullptr, 0, $field(TransportContext, handshakeContext)},
	{"secureRenegotiation", "Z", nullptr, 0, $field(TransportContext, secureRenegotiation)},
	{"clientVerifyData", "[B", nullptr, 0, $field(TransportContext, clientVerifyData)},
	{"serverVerifyData", "[B", nullptr, 0, $field(TransportContext, serverVerifyData)},
	{"serverRequestedNamedGroups", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/NamedGroup;>;", 0, $field(TransportContext, serverRequestedNamedGroups)},
	{"cipherSuite", "Lsun/security/ssl/CipherSuite;", nullptr, 0, $field(TransportContext, cipherSuite)},
	{"emptyByteArray", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TransportContext, emptyByteArray)},
	{}
};

$MethodInfo _TransportContext_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Lsun/security/ssl/SSLTransport;Lsun/security/ssl/InputRecord;Lsun/security/ssl/OutputRecord;)V", nullptr, 0, $method(TransportContext, init$, void, $SSLContextImpl*, $SSLTransport*, $InputRecord*, $OutputRecord*)},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Lsun/security/ssl/SSLTransport;Lsun/security/ssl/InputRecord;Lsun/security/ssl/OutputRecord;Z)V", nullptr, 0, $method(TransportContext, init$, void, $SSLContextImpl*, $SSLTransport*, $InputRecord*, $OutputRecord*, bool)},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Lsun/security/ssl/SSLTransport;Lsun/security/ssl/SSLConfiguration;Lsun/security/ssl/InputRecord;Lsun/security/ssl/OutputRecord;)V", nullptr, 0, $method(TransportContext, init$, void, $SSLContextImpl*, $SSLTransport*, $SSLConfiguration*, $InputRecord*, $OutputRecord*)},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Lsun/security/ssl/SSLTransport;Lsun/security/ssl/SSLConfiguration;Lsun/security/ssl/InputRecord;Lsun/security/ssl/OutputRecord;Z)V", nullptr, $PRIVATE, $method(TransportContext, init$, void, $SSLContextImpl*, $SSLTransport*, $SSLConfiguration*, $InputRecord*, $OutputRecord*, bool)},
	{"closeInbound", "()V", nullptr, 0, $method(TransportContext, closeInbound, void), "javax.net.ssl.SSLException"},
	{"closeNotify", "(Z)V", nullptr, 0, $method(TransportContext, closeNotify, void, bool), "java.io.IOException"},
	{"closeOutbound", "()V", nullptr, 0, $method(TransportContext, closeOutbound, void)},
	{"dispatch", "(Lsun/security/ssl/Plaintext;)V", nullptr, 0, $method(TransportContext, dispatch, void, $Plaintext*), "java.io.IOException"},
	{"fatal", "(Lsun/security/ssl/Alert;Ljava/lang/String;)Ljavax/net/ssl/SSLException;", nullptr, 0, $method(TransportContext, fatal, $SSLException*, $Alert*, $String*), "javax.net.ssl.SSLException"},
	{"fatal", "(Lsun/security/ssl/Alert;Ljava/lang/Throwable;)Ljavax/net/ssl/SSLException;", nullptr, 0, $method(TransportContext, fatal, $SSLException*, $Alert*, $Throwable*), "javax.net.ssl.SSLException"},
	{"fatal", "(Lsun/security/ssl/Alert;Ljava/lang/String;Ljava/lang/Throwable;)Ljavax/net/ssl/SSLException;", nullptr, 0, $method(TransportContext, fatal, $SSLException*, $Alert*, $String*, $Throwable*), "javax.net.ssl.SSLException"},
	{"fatal", "(Lsun/security/ssl/Alert;Ljava/lang/String;ZLjava/lang/Throwable;)Ljavax/net/ssl/SSLException;", nullptr, 0, $method(TransportContext, fatal, $SSLException*, $Alert*, $String*, bool, $Throwable*), "javax.net.ssl.SSLException"},
	{"finishHandshake", "()Ljavax/net/ssl/SSLEngineResult$HandshakeStatus;", nullptr, 0, $method(TransportContext, finishHandshake, $SSLEngineResult$HandshakeStatus*)},
	{"finishPostHandshake", "()Ljavax/net/ssl/SSLEngineResult$HandshakeStatus;", nullptr, 0, $method(TransportContext, finishPostHandshake, $SSLEngineResult$HandshakeStatus*)},
	{"getHandshakeStatus", "()Ljavax/net/ssl/SSLEngineResult$HandshakeStatus;", nullptr, 0, $method(TransportContext, getHandshakeStatus, $SSLEngineResult$HandshakeStatus*)},
	{"initiateInboundClose", "()V", nullptr, $PRIVATE, $method(TransportContext, initiateInboundClose, void), "java.io.IOException"},
	{"initiateOutboundClose", "()V", nullptr, $PRIVATE, $method(TransportContext, initiateOutboundClose, void), "java.io.IOException"},
	{"isInboundClosed", "()Z", nullptr, 0, $method(TransportContext, isInboundClosed, bool)},
	{"isOutboundClosed", "()Z", nullptr, 0, $method(TransportContext, isOutboundClosed, bool)},
	{"isOutboundDone", "()Z", nullptr, 0, $method(TransportContext, isOutboundDone, bool)},
	{"isPostHandshakeContext", "()Z", nullptr, 0, $method(TransportContext, isPostHandshakeContext, bool)},
	{"kickstart", "()V", nullptr, 0, $method(TransportContext, kickstart, void), "java.io.IOException"},
	{"passiveInboundClose", "()V", nullptr, $PRIVATE, $method(TransportContext, passiveInboundClose, void), "java.io.IOException"},
	{"setUseClientMode", "(Z)V", nullptr, 0, $method(TransportContext, setUseClientMode, void, bool)},
	{"warning", "(Lsun/security/ssl/Alert;)V", nullptr, 0, $method(TransportContext, warning, void, $Alert*)},
	{}
};

$InnerClassInfo _TransportContext_InnerClassesInfo_[] = {
	{"sun.security.ssl.TransportContext$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"sun.security.ssl.TransportContext$NotifyHandshake", "sun.security.ssl.TransportContext", "NotifyHandshake", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _TransportContext_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.TransportContext",
	"java.lang.Object",
	"sun.security.ssl.ConnectionContext",
	_TransportContext_FieldInfo_,
	_TransportContext_MethodInfo_,
	nullptr,
	nullptr,
	_TransportContext_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.TransportContext$1,sun.security.ssl.TransportContext$NotifyHandshake,sun.security.ssl.TransportContext$NotifyHandshake$1"
};

$Object* allocate$TransportContext($Class* clazz) {
	return $of($alloc(TransportContext));
}

$bytes* TransportContext::emptyByteArray = nullptr;

void TransportContext::init$($SSLContextImpl* sslContext, $SSLTransport* transport, $InputRecord* inputRecord, $OutputRecord* outputRecord) {
	TransportContext::init$(sslContext, transport, $$new($SSLConfiguration, sslContext, false), inputRecord, outputRecord, true);
}

void TransportContext::init$($SSLContextImpl* sslContext, $SSLTransport* transport, $InputRecord* inputRecord, $OutputRecord* outputRecord, bool isClientMode) {
	TransportContext::init$(sslContext, transport, $$new($SSLConfiguration, sslContext, isClientMode), inputRecord, outputRecord, false);
}

void TransportContext::init$($SSLContextImpl* sslContext, $SSLTransport* transport, $SSLConfiguration* sslConfig, $InputRecord* inputRecord, $OutputRecord* outputRecord) {
	TransportContext::init$(sslContext, transport, $cast($SSLConfiguration, $($nc(sslConfig)->clone())), inputRecord, outputRecord, false);
}

void TransportContext::init$($SSLContextImpl* sslContext, $SSLTransport* transport, $SSLConfiguration* sslConfig, $InputRecord* inputRecord, $OutputRecord* outputRecord, bool isUnsureMode) {
	this->isNegotiated = false;
	this->isBroken = false;
	this->isInputCloseNotified = false;
	this->peerUserCanceled = false;
	$set(this, closeReason, nullptr);
	$set(this, delegatedThrown, nullptr);
	this->needHandshakeFinishedStatus = false;
	this->hasDelegatedFinished = false;
	$set(this, applicationProtocol, nullptr);
	$set(this, handshakeContext, nullptr);
	this->secureRenegotiation = false;
	$set(this, transport, transport);
	$set(this, sslContext, sslContext);
	$set(this, inputRecord, inputRecord);
	$set(this, outputRecord, outputRecord);
	$set(this, sslConfig, sslConfig);
	if ($nc(this->sslConfig)->maximumPacketSize == 0) {
		$nc(this->sslConfig)->maximumPacketSize = $nc(outputRecord)->getMaxPacketSize();
	}
	this->isUnsureMode = isUnsureMode;
	$set(this, conSession, $new($SSLSessionImpl));
	$set(this, protocolVersion, $nc(this->sslConfig)->maximumProtocolVersion);
	$set(this, clientVerifyData, TransportContext::emptyByteArray);
	$set(this, serverVerifyData, TransportContext::emptyByteArray);
	$set(this, acc, $AccessController::getContext());
	$set(this, consumers, $new($HashMap));
}

void TransportContext::dispatch($Plaintext* plaintext) {
	$useLocalCurrentObjectStackCache();
	if (plaintext == nullptr) {
		return;
	}
	$ContentType* ct = $ContentType::valueOf($nc(plaintext)->contentType);
	if (ct == nullptr) {
		$init($Alert);
		$throw($(fatal($Alert::UNEXPECTED_MESSAGE, $$str({"Unknown content type: "_s, $$str($nc(plaintext)->contentType)}))));
	}
	$init($TransportContext$1);
	{
		int8_t type = 0;
		$var($SSLConsumer, consumer, nullptr)
		switch ($nc($TransportContext$1::$SwitchMap$sun$security$ssl$ContentType)->get($nc((ct))->ordinal())) {
		case 1:
			{
				type = $HandshakeContext::getHandshakeType(this, plaintext);
				if (this->handshakeContext == nullptr) {
					$init($SSLHandshake);
					if (type == $SSLHandshake::KEY_UPDATE->id || type == $SSLHandshake::NEW_SESSION_TICKET->id) {
						if (!this->isNegotiated) {
							$init($Alert);
							$throw($(fatal($Alert::UNEXPECTED_MESSAGE, $$str({"Unexpected unnegotiated post-handshake message: "_s, $($SSLHandshake::nameOf(type))}))));
						}
						if (!$PostHandshakeContext::isConsumable(this, type)) {
							$init($Alert);
							$throw($(fatal($Alert::UNEXPECTED_MESSAGE, $$str({"Unexpected post-handshake message: "_s, $($SSLHandshake::nameOf(type))}))));
						}
						$set(this, handshakeContext, $new($PostHandshakeContext, this));
					} else {
						$set(this, handshakeContext, $nc(this->sslConfig)->isClientMode ? static_cast<$HandshakeContext*>($new($ClientHandshakeContext, this->sslContext, this)) : static_cast<$HandshakeContext*>($new($ServerHandshakeContext, this->sslContext, this)));
						$nc(this->outputRecord)->initHandshaker();
					}
				}
				$nc(this->handshakeContext)->dispatch(type, plaintext);
				break;
			}
		case 2:
			{
				$init($Alert);
				$nc($Alert::alertConsumer)->consume(this, $nc(plaintext)->fragment);
				break;
			}
		default:
			{
				$assign(consumer, $cast($SSLConsumer, $nc(this->consumers)->get($($Byte::valueOf($nc(plaintext)->contentType)))));
				if (consumer != nullptr) {
					consumer->consume(this, $nc(plaintext)->fragment);
				} else {
					$init($Alert);
					$throw($(fatal($Alert::UNEXPECTED_MESSAGE, $$str({"Unexpected content: "_s, $$str($nc(plaintext)->contentType)}))));
				}
			}
		}
	}
}

void TransportContext::kickstart() {
	if (this->isUnsureMode) {
		$throwNew($IllegalStateException, "Client/Server mode not yet set."_s);
	}
	bool var$0 = $nc(this->outputRecord)->isClosed();
	if (var$0 || $nc(this->inputRecord)->isClosed() || this->isBroken) {
		if (this->closeReason != nullptr) {
			$throwNew($SSLException, "Cannot kickstart, the connection is broken or closed"_s, this->closeReason);
		} else {
			$throwNew($SSLException, "Cannot kickstart, the connection is broken or closed"_s);
		}
	}
	if (this->handshakeContext == nullptr) {
		if (this->isNegotiated && $nc(this->protocolVersion)->useTLS13PlusSpec()) {
			$set(this, handshakeContext, $new($PostHandshakeContext, this));
		} else {
			$set(this, handshakeContext, $nc(this->sslConfig)->isClientMode ? static_cast<$HandshakeContext*>($new($ClientHandshakeContext, this->sslContext, this)) : static_cast<$HandshakeContext*>($new($ServerHandshakeContext, this->sslContext, this)));
			$nc(this->outputRecord)->initHandshaker();
		}
	}
	if (this->isNegotiated || $nc(this->sslConfig)->isClientMode) {
		$nc(this->handshakeContext)->kickstart();
	}
}

bool TransportContext::isPostHandshakeContext() {
	return this->handshakeContext != nullptr && ($instanceOf($PostHandshakeContext, this->handshakeContext));
}

void TransportContext::warning($Alert* alert) {
	$useLocalCurrentObjectStackCache();
	if (this->isNegotiated || this->handshakeContext != nullptr) {
		try {
			$init($Alert$Level);
			$nc(this->outputRecord)->encodeAlert($Alert$Level::WARNING->level, $nc(alert)->id);
		} catch ($IOException& ioe) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
				$SSLLogger::warning($$str({"Warning: failed to send warning alert "_s, alert}), $$new($ObjectArray, {$of(ioe)}));
			}
		}
	}
}

void TransportContext::closeNotify(bool isUserCanceled) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($SSLSocketImpl, this->transport)) {
		$nc(($cast($SSLSocketImpl, this->transport)))->closeNotify(isUserCanceled);
	} else {
		$nc($nc(this->outputRecord)->recordLock)->lock();
		{
			$var($Throwable, var$0, nullptr);
			try {
				{
					$var($Throwable, var$1, nullptr);
					try {
						if (isUserCanceled) {
							$init($Alert);
							warning($Alert::USER_CANCELED);
						}
						$init($Alert);
						warning($Alert::CLOSE_NOTIFY);
					} catch ($Throwable& var$2) {
						$assign(var$1, var$2);
					} /*finally*/ {
						$nc(this->outputRecord)->close();
					}
					if (var$1 != nullptr) {
						$throw(var$1);
					}
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} /*finally*/ {
				$nc($nc(this->outputRecord)->recordLock)->unlock();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

$SSLException* TransportContext::fatal($Alert* alert, $String* diagnostic) {
	return fatal(alert, diagnostic, nullptr);
}

$SSLException* TransportContext::fatal($Alert* alert, $Throwable* cause) {
	return fatal(alert, nullptr, cause);
}

$SSLException* TransportContext::fatal($Alert* alert, $String* diagnostic, $Throwable* cause) {
	return fatal(alert, diagnostic, false, cause);
}

$SSLException* TransportContext::fatal($Alert* alert, $String* diagnostic$renamed, bool recvFatalAlert, $Throwable* cause$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, cause, cause$renamed);
	$var($String, diagnostic, diagnostic$renamed);
	if (this->closeReason != nullptr) {
		if (cause == nullptr) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
				$SSLLogger::warning("Closed transport, general or untracked problem"_s, $$new($ObjectArray, 0));
			}
			$throw($($nc(alert)->createSSLException("Closed transport, general or untracked problem"_s)));
		}
		if ($instanceOf($SSLException, cause)) {
			$throw($cast($SSLException, cause));
		} else {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
				$SSLLogger::warning("Closed transport, unexpected rethrowing"_s, $$new($ObjectArray, {$of(cause)}));
			}
			$throw($($nc(alert)->createSSLException("Unexpected rethrowing"_s, cause)));
		}
	}
	if (diagnostic == nullptr) {
		if (cause == nullptr) {
			$assign(diagnostic, "General/Untracked problem"_s);
		} else {
			$assign(diagnostic, $nc(cause)->getMessage());
		}
	}
	if (cause == nullptr) {
		$assign(cause, $nc(alert)->createSSLException(diagnostic));
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
		$SSLLogger::severe($$str({"Fatal ("_s, alert, "): "_s, diagnostic}), $$new($ObjectArray, {$of(cause)}));
	}
	if ($instanceOf($SSLException, cause)) {
		$set(this, closeReason, $cast($SSLException, cause));
	} else {
		$set(this, closeReason, $nc(alert)->createSSLException(diagnostic, cause));
	}
	try {
		$nc(this->inputRecord)->close();
	} catch ($IOException& ioe) {
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::warning("Fatal: input record closure failed"_s, $$new($ObjectArray, {$of(ioe)}));
		}
		$nc(this->closeReason)->addSuppressed(ioe);
	}
	if (this->conSession != nullptr) {
		$nc(this->conSession)->invalidate();
	}
	if (this->handshakeContext != nullptr && $nc(this->handshakeContext)->handshakeSession != nullptr) {
		$nc($nc(this->handshakeContext)->handshakeSession)->invalidate();
	}
	if (!recvFatalAlert && !isOutboundClosed() && !this->isBroken && (this->isNegotiated || this->handshakeContext != nullptr)) {
		try {
			$init($Alert$Level);
			$nc(this->outputRecord)->encodeAlert($Alert$Level::FATAL->level, $nc(alert)->id);
		} catch ($IOException& ioe) {
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
				$SSLLogger::warning($$str({"Fatal: failed to send fatal alert "_s, alert}), $$new($ObjectArray, {$of(ioe)}));
			}
			$nc(this->closeReason)->addSuppressed(ioe);
		}
	}
	try {
		$nc(this->outputRecord)->close();
	} catch ($IOException& ioe) {
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::warning("Fatal: output record closure failed"_s, $$new($ObjectArray, {$of(ioe)}));
		}
		$nc(this->closeReason)->addSuppressed(ioe);
	}
	if (this->handshakeContext != nullptr) {
		$set(this, handshakeContext, nullptr);
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$nc(this->transport)->shutdown();
			} catch ($IOException& ioe) {
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
					$SSLLogger::warning("Fatal: transport closure failed"_s, $$new($ObjectArray, {$of(ioe)}));
				}
				$nc(this->closeReason)->addSuppressed(ioe);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			this->isBroken = true;
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if ($instanceOf($SSLException, this->closeReason)) {
		$throw($cast($SSLException, this->closeReason));
	} else {
		$throw($cast($RuntimeException, this->closeReason));
	}
	$shouldNotReachHere();
}

void TransportContext::setUseClientMode(bool useClientMode) {
	if (this->handshakeContext != nullptr || this->isNegotiated) {
		$throwNew($IllegalArgumentException, "Cannot change mode after SSL traffic has started"_s);
	}
	if ($nc(this->sslConfig)->isClientMode != useClientMode) {
		if ($nc(this->sslContext)->isDefaultProtocolVesions($nc(this->sslConfig)->enabledProtocols)) {
			$set($nc(this->sslConfig), enabledProtocols, $nc(this->sslContext)->getDefaultProtocolVersions(!useClientMode));
		}
		if ($nc(this->sslContext)->isDefaultCipherSuiteList($nc(this->sslConfig)->enabledCipherSuites)) {
			$set($nc(this->sslConfig), enabledCipherSuites, $nc(this->sslContext)->getDefaultCipherSuites(!useClientMode));
		}
		$nc(this->sslConfig)->toggleClientMode();
	}
	this->isUnsureMode = false;
}

bool TransportContext::isOutboundDone() {
	bool var$0 = $nc(this->outputRecord)->isClosed();
	return var$0 && $nc(this->outputRecord)->isEmpty();
}

bool TransportContext::isOutboundClosed() {
	return $nc(this->outputRecord)->isClosed();
}

bool TransportContext::isInboundClosed() {
	return $nc(this->inputRecord)->isClosed();
}

void TransportContext::closeInbound() {
	if (isInboundClosed()) {
		return;
	}
	try {
		if (!this->isInputCloseNotified) {
			initiateInboundClose();
		} else {
			passiveInboundClose();
		}
	} catch ($IOException& ioe) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::warning("inbound closure failed"_s, $$new($ObjectArray, {$of(ioe)}));
		}
	}
}

void TransportContext::passiveInboundClose() {
	if (!isInboundClosed()) {
		$nc(this->inputRecord)->close();
	}
	if (!isOutboundClosed()) {
		$init($SSLConfiguration);
		bool needCloseNotify = $SSLConfiguration::acknowledgeCloseNotify;
		if (!needCloseNotify) {
			if (this->isNegotiated) {
				if (!$nc(this->protocolVersion)->useTLS13PlusSpec()) {
					needCloseNotify = true;
				}
			} else if (this->handshakeContext != nullptr) {
				$ProtocolVersion* pv = $nc(this->handshakeContext)->negotiatedProtocol;
				if (pv == nullptr || (!$nc(pv)->useTLS13PlusSpec())) {
					needCloseNotify = true;
				}
			}
		}
		if (needCloseNotify) {
			closeNotify(false);
		}
	}
}

void TransportContext::initiateInboundClose() {
	if (!isInboundClosed()) {
		$nc(this->inputRecord)->close();
	}
}

void TransportContext::closeOutbound() {
	if (isOutboundClosed()) {
		return;
	}
	try {
		initiateOutboundClose();
	} catch ($IOException& ioe) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::warning("outbound closure failed"_s, $$new($ObjectArray, {$of(ioe)}));
		}
	}
}

void TransportContext::initiateOutboundClose() {
	bool useUserCanceled = false;
	if (!this->isNegotiated && (this->handshakeContext != nullptr) && !this->peerUserCanceled) {
		useUserCanceled = true;
	}
	closeNotify(useUserCanceled);
}

$SSLEngineResult$HandshakeStatus* TransportContext::getHandshakeStatus() {
	if (!$nc(this->outputRecord)->isEmpty()) {
		$init($SSLEngineResult$HandshakeStatus);
		return $SSLEngineResult$HandshakeStatus::NEED_WRAP;
	} else {
		bool var$1 = isOutboundClosed();
		if (var$1 && isInboundClosed()) {
			$init($SSLEngineResult$HandshakeStatus);
			return $SSLEngineResult$HandshakeStatus::NOT_HANDSHAKING;
		} else if (this->handshakeContext != nullptr) {
			if (!$nc($nc(this->handshakeContext)->delegatedActions)->isEmpty()) {
				$init($SSLEngineResult$HandshakeStatus);
				return $SSLEngineResult$HandshakeStatus::NEED_TASK;
			} else if (!isInboundClosed()) {
				bool var$2 = $nc(this->sslContext)->isDTLS();
				if (var$2 && !$nc(this->inputRecord)->isEmpty()) {
					$init($SSLEngineResult$HandshakeStatus);
					return $SSLEngineResult$HandshakeStatus::NEED_UNWRAP_AGAIN;
				} else {
					$init($SSLEngineResult$HandshakeStatus);
					return $SSLEngineResult$HandshakeStatus::NEED_UNWRAP;
				}
			} else if (!isOutboundClosed()) {
				$init($SSLEngineResult$HandshakeStatus);
				return $SSLEngineResult$HandshakeStatus::NEED_WRAP;
			}
		} else if (this->needHandshakeFinishedStatus) {
			$init($SSLEngineResult$HandshakeStatus);
			return $SSLEngineResult$HandshakeStatus::NEED_WRAP;
		}
	}
	$init($SSLEngineResult$HandshakeStatus);
	return $SSLEngineResult$HandshakeStatus::NOT_HANDSHAKING;
}

$SSLEngineResult$HandshakeStatus* TransportContext::finishHandshake() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->protocolVersion)->useTLS13PlusSpec()) {
		$set($nc(this->outputRecord), tc, this);
		$set($nc(this->inputRecord), tc, this);
		$set(this, cipherSuite, $nc(this->handshakeContext)->negotiatedCipherSuite);
		$set($nc($nc(this->inputRecord)->readCipher), baseSecret, $nc(this->handshakeContext)->baseReadSecret);
		$set($nc($nc(this->outputRecord)->writeCipher), baseSecret, $nc(this->handshakeContext)->baseWriteSecret);
	}
	$set(this, handshakeContext, nullptr);
	$nc($nc(this->outputRecord)->handshakeHash)->finish();
	$nc(this->inputRecord)->finishHandshake();
	$nc(this->outputRecord)->finishHandshake();
	this->isNegotiated = true;
	if ($instanceOf($SSLSocket, this->transport) && $nc(this->sslConfig)->handshakeListeners != nullptr && !$nc($nc(this->sslConfig)->handshakeListeners)->isEmpty()) {
		$var($HandshakeCompletedEvent, hce, $new($HandshakeCompletedEvent, $cast($SSLSocket, this->transport), this->conSession));
		$var($Thread, thread, $new($Thread, nullptr, $$new($TransportContext$NotifyHandshake, $nc(this->sslConfig)->handshakeListeners, hce), "HandshakeCompletedNotify-Thread"_s, 0, false));
		thread->start();
	}
	$init($SSLEngineResult$HandshakeStatus);
	return $SSLEngineResult$HandshakeStatus::FINISHED;
}

$SSLEngineResult$HandshakeStatus* TransportContext::finishPostHandshake() {
	$set(this, handshakeContext, nullptr);
	$init($SSLEngineResult$HandshakeStatus);
	return $SSLEngineResult$HandshakeStatus::FINISHED;
}

void clinit$TransportContext($Class* class$) {
	$assignStatic(TransportContext::emptyByteArray, $new($bytes, 0));
}

TransportContext::TransportContext() {
}

$Class* TransportContext::load$($String* name, bool initialize) {
	$loadClass(TransportContext, name, initialize, &_TransportContext_ClassInfo_, clinit$TransportContext, allocate$TransportContext);
	return class$;
}

$Class* TransportContext::class$ = nullptr;

		} // ssl
	} // security
} // sun