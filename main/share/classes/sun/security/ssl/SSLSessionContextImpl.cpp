#include <sun/security/ssl/SSLSessionContextImpl.h>

#include <java/lang/NumberFormatException.h>
#include <java/util/Enumeration.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLSession.h>
#include <sun/security/action/GetIntegerAction.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/ssl/NewSessionTicket.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSessionContextImpl$SessionCacheVisitor.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SessionId.h>
#include <sun/security/util/Cache$CacheVisitor.h>
#include <sun/security/util/Cache.h>
#include <jcpp.h>

#undef DEFAULT_MAX_CACHE_SIZE
#undef DEFAULT_SESSION_TIMEOUT
#undef ENGLISH
#undef MAX_TICKET_LIFETIME

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $Enumeration = ::java::util::Enumeration;
using $Locale = ::java::util::Locale;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $GetIntegerAction = ::sun::security::action::GetIntegerAction;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $NewSessionTicket = ::sun::security::ssl::NewSessionTicket;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSessionContextImpl$SessionCacheVisitor = ::sun::security::ssl::SSLSessionContextImpl$SessionCacheVisitor;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SessionId = ::sun::security::ssl::SessionId;
using $Cache = ::sun::security::util::Cache;
using $Cache$CacheVisitor = ::sun::security::util::Cache$CacheVisitor;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLSessionContextImpl_FieldInfo_[] = {
	{"DEFAULT_MAX_CACHE_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SSLSessionContextImpl, DEFAULT_MAX_CACHE_SIZE)},
	{"DEFAULT_SESSION_TIMEOUT", "I", nullptr, $STATIC | $FINAL, $constField(SSLSessionContextImpl, DEFAULT_SESSION_TIMEOUT)},
	{"sessionCache", "Lsun/security/util/Cache;", "Lsun/security/util/Cache<Lsun/security/ssl/SessionId;Lsun/security/ssl/SSLSessionImpl;>;", $PRIVATE | $FINAL, $field(SSLSessionContextImpl, sessionCache)},
	{"sessionHostPortCache", "Lsun/security/util/Cache;", "Lsun/security/util/Cache<Ljava/lang/String;Lsun/security/ssl/SSLSessionImpl;>;", $PRIVATE | $FINAL, $field(SSLSessionContextImpl, sessionHostPortCache)},
	{"cacheLimit", "I", nullptr, $PRIVATE, $field(SSLSessionContextImpl, cacheLimit)},
	{"timeout", "I", nullptr, $PRIVATE, $field(SSLSessionContextImpl, timeout)},
	{"statelessSession", "Z", nullptr, $PRIVATE, $field(SSLSessionContextImpl, statelessSession)},
	{}
};

$MethodInfo _SSLSessionContextImpl_MethodInfo_[] = {
	{"<init>", "(Z)V", nullptr, 0, $method(SSLSessionContextImpl, init$, void, bool)},
	{"get", "([B)Lsun/security/ssl/SSLSessionImpl;", nullptr, 0, $method(SSLSessionContextImpl, get, $SSLSessionImpl*, $bytes*)},
	{"get", "(Ljava/lang/String;I)Lsun/security/ssl/SSLSessionImpl;", nullptr, 0, $method(SSLSessionContextImpl, get, $SSLSessionImpl*, $String*, int32_t)},
	{"getDefaults", "(Z)I", nullptr, $PRIVATE, $method(SSLSessionContextImpl, getDefaults, int32_t, bool)},
	{"getIds", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<[B>;", $PUBLIC, $virtualMethod(SSLSessionContextImpl, getIds, $Enumeration*)},
	{"getKey", "(Ljava/lang/String;I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLSessionContextImpl, getKey, $String*, $String*, int32_t)},
	{"getSession", "([B)Ljavax/net/ssl/SSLSession;", nullptr, $PUBLIC, $virtualMethod(SSLSessionContextImpl, getSession, $SSLSession*, $bytes*)},
	{"getSessionCacheSize", "()I", nullptr, $PUBLIC, $virtualMethod(SSLSessionContextImpl, getSessionCacheSize, int32_t)},
	{"getSessionTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(SSLSessionContextImpl, getSessionTimeout, int32_t)},
	{"isTimedout", "(Ljavax/net/ssl/SSLSession;)Z", nullptr, $PRIVATE, $method(SSLSessionContextImpl, isTimedout, bool, $SSLSession*)},
	{"pull", "([B)Lsun/security/ssl/SSLSessionImpl;", nullptr, 0, $method(SSLSessionContextImpl, pull, $SSLSessionImpl*, $bytes*)},
	{"put", "(Lsun/security/ssl/SSLSessionImpl;)V", nullptr, 0, $method(SSLSessionContextImpl, put, void, $SSLSessionImpl*)},
	{"remove", "(Lsun/security/ssl/SessionId;)V", nullptr, 0, $method(SSLSessionContextImpl, remove, void, $SessionId*)},
	{"setSessionCacheSize", "(I)V", nullptr, $PUBLIC, $virtualMethod(SSLSessionContextImpl, setSessionCacheSize, void, int32_t), "java.lang.IllegalArgumentException"},
	{"setSessionTimeout", "(I)V", nullptr, $PUBLIC, $virtualMethod(SSLSessionContextImpl, setSessionTimeout, void, int32_t), "java.lang.IllegalArgumentException"},
	{"statelessEnabled", "()Z", nullptr, 0, $method(SSLSessionContextImpl, statelessEnabled, bool)},
	{}
};

$InnerClassInfo _SSLSessionContextImpl_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLSessionContextImpl$SessionCacheVisitor", "sun.security.ssl.SSLSessionContextImpl", "SessionCacheVisitor", $PRIVATE | $FINAL},
	{}
};

$ClassInfo _SSLSessionContextImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLSessionContextImpl",
	"java.lang.Object",
	"javax.net.ssl.SSLSessionContext",
	_SSLSessionContextImpl_FieldInfo_,
	_SSLSessionContextImpl_MethodInfo_,
	nullptr,
	nullptr,
	_SSLSessionContextImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLSessionContextImpl$SessionCacheVisitor"
};

$Object* allocate$SSLSessionContextImpl($Class* clazz) {
	return $of($alloc(SSLSessionContextImpl));
}

void SSLSessionContextImpl::init$(bool server) {
	this->statelessSession = true;
	this->timeout = SSLSessionContextImpl::DEFAULT_SESSION_TIMEOUT;
	this->cacheLimit = getDefaults(server);
	$set(this, sessionCache, $Cache::newSoftMemoryCache(this->cacheLimit, this->timeout));
	$set(this, sessionHostPortCache, $Cache::newSoftMemoryCache(this->cacheLimit, this->timeout));
}

bool SSLSessionContextImpl::statelessEnabled() {
	return this->statelessSession;
}

$SSLSession* SSLSessionContextImpl::getSession($bytes* sessionId) {
	$useLocalCurrentObjectStackCache();
	if (sessionId == nullptr) {
		$throwNew($NullPointerException, "session id cannot be null"_s);
	}
	$var($SSLSessionImpl, sess, $cast($SSLSessionImpl, $nc(this->sessionCache)->get($$new($SessionId, sessionId))));
	if (!isTimedout(sess)) {
		return sess;
	}
	return nullptr;
}

$Enumeration* SSLSessionContextImpl::getIds() {
	$var($SSLSessionContextImpl$SessionCacheVisitor, scVisitor, $new($SSLSessionContextImpl$SessionCacheVisitor, this));
	$nc(this->sessionCache)->accept(scVisitor);
	return scVisitor->getSessionIds();
}

void SSLSessionContextImpl::setSessionTimeout(int32_t seconds) {
	if (seconds < 0) {
		$throwNew($IllegalArgumentException);
	}
	if (this->timeout != seconds) {
		$nc(this->sessionCache)->setTimeout(seconds);
		$nc(this->sessionHostPortCache)->setTimeout(seconds);
		this->timeout = seconds;
	}
}

int32_t SSLSessionContextImpl::getSessionTimeout() {
	return this->timeout;
}

void SSLSessionContextImpl::setSessionCacheSize(int32_t size) {
	if (size < 0) {
		$throwNew($IllegalArgumentException);
	}
	if (this->cacheLimit != size) {
		$nc(this->sessionCache)->setCapacity(size);
		$nc(this->sessionHostPortCache)->setCapacity(size);
		this->cacheLimit = size;
	}
}

int32_t SSLSessionContextImpl::getSessionCacheSize() {
	return this->cacheLimit;
}

$SSLSessionImpl* SSLSessionContextImpl::get($bytes* id) {
	return $cast($SSLSessionImpl, getSession(id));
}

$SSLSessionImpl* SSLSessionContextImpl::pull($bytes* id) {
	if (id != nullptr) {
		return $cast($SSLSessionImpl, $nc(this->sessionCache)->pull($$new($SessionId, id)));
	}
	return nullptr;
}

$SSLSessionImpl* SSLSessionContextImpl::get($String* hostname, int32_t port) {
	$useLocalCurrentObjectStackCache();
	if (hostname == nullptr && port == -1) {
		return nullptr;
	}
	$var($SSLSessionImpl, sess, $cast($SSLSessionImpl, $nc(this->sessionHostPortCache)->get($(getKey(hostname, port)))));
	if (!isTimedout(sess)) {
		return sess;
	}
	return nullptr;
}

$String* SSLSessionContextImpl::getKey($String* hostname, int32_t port) {
	$init(SSLSessionContextImpl);
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	return $nc(($$str({hostname, ":"_s, $$str(port)})))->toLowerCase($Locale::ENGLISH);
}

void SSLSessionContextImpl::put($SSLSessionImpl* s) {
	$useLocalCurrentObjectStackCache();
	$nc(this->sessionCache)->put($($nc(s)->getSessionId()), s);
	bool var$0 = ($nc(s)->getPeerHost() != nullptr);
	if (var$0 && (s->getPeerPort() != -1)) {
		$var($String, var$1, s->getPeerHost());
		$nc(this->sessionHostPortCache)->put($(getKey(var$1, s->getPeerPort())), s);
	}
	$nc(s)->setContext(this);
}

void SSLSessionContextImpl::remove($SessionId* key) {
	$useLocalCurrentObjectStackCache();
	$var($SSLSessionImpl, s, $cast($SSLSessionImpl, $nc(this->sessionCache)->get(key)));
	if (s != nullptr) {
		$nc(this->sessionCache)->remove(key);
		$var($String, var$0, s->getPeerHost());
		$nc(this->sessionHostPortCache)->remove($(getKey(var$0, s->getPeerPort())));
	}
}

int32_t SSLSessionContextImpl::getDefaults(bool server) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($String, st, nullptr);
		if (server) {
			$assign(st, $GetPropertyAction::privilegedGetProperty("jdk.tls.server.enableSessionTicketExtension"_s, "true"_s));
		} else {
			$assign(st, $GetPropertyAction::privilegedGetProperty("jdk.tls.client.enableSessionTicketExtension"_s, "true"_s));
		}
		if ($nc(st)->compareToIgnoreCase("false"_s) == 0) {
			this->statelessSession = false;
		}
		$var($String, s, $GetPropertyAction::privilegedGetProperty("jdk.tls.server.sessionTicketTimeout"_s));
		if (s != nullptr) {
			try {
				int32_t t = $Integer::parseInt(s);
				if (t < 0 || t > $NewSessionTicket::MAX_TICKET_LIFETIME) {
					this->timeout = SSLSessionContextImpl::DEFAULT_SESSION_TIMEOUT;
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
						$SSLLogger::warning($$str({"Invalid timeout given jdk.tls.server.sessionTicketTimeout: "_s, $$str(t), ".  Set to default value "_s, $$str(this->timeout)}), $$new($ObjectArray, 0));
					}
				} else {
					this->timeout = t;
				}
			} catch ($NumberFormatException& e) {
				setSessionTimeout(SSLSessionContextImpl::DEFAULT_SESSION_TIMEOUT);
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
					$SSLLogger::warning($$str({"Invalid timeout for jdk.tls.server.sessionTicketTimeout: "_s, s, ".  Set to default value "_s, $$str(this->timeout)}), $$new($ObjectArray, 0));
				}
			}
		}
		int32_t defaultCacheLimit = $nc($($GetIntegerAction::privilegedGetProperty("javax.net.ssl.sessionCacheSize"_s, SSLSessionContextImpl::DEFAULT_MAX_CACHE_SIZE)))->intValue();
		if (defaultCacheLimit >= 0) {
			return defaultCacheLimit;
		} else {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
				$SSLLogger::warning($$str({"invalid System Property javax.net.ssl.sessionCacheSize, use the default session cache size ("_s, $$str(SSLSessionContextImpl::DEFAULT_MAX_CACHE_SIZE), ") instead"_s}), $$new($ObjectArray, 0));
			}
		}
	} catch ($Exception& e) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::warning($$str({"the System Property javax.net.ssl.sessionCacheSize is not available, use the default value ("_s, $$str(SSLSessionContextImpl::DEFAULT_MAX_CACHE_SIZE), ") instead"_s}), $$new($ObjectArray, 0));
		}
	}
	return SSLSessionContextImpl::DEFAULT_MAX_CACHE_SIZE;
}

bool SSLSessionContextImpl::isTimedout($SSLSession* sess) {
	if (this->timeout == 0) {
		return false;
	}
	bool var$0 = (sess != nullptr);
	if (var$0) {
		int64_t var$1 = (sess->getCreationTime() + this->timeout * (int64_t)1000);
		var$0 = (var$1 <= ($System::currentTimeMillis()));
	}
	if (var$0) {
		sess->invalidate();
		return true;
	}
	return false;
}

SSLSessionContextImpl::SSLSessionContextImpl() {
}

$Class* SSLSessionContextImpl::load$($String* name, bool initialize) {
	$loadClass(SSLSessionContextImpl, name, initialize, &_SSLSessionContextImpl_ClassInfo_, allocate$SSLSessionContextImpl);
	return class$;
}

$Class* SSLSessionContextImpl::class$ = nullptr;

		} // ssl
	} // security
} // sun