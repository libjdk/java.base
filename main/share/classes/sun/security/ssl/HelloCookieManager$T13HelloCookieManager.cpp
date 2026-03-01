#include <sun/security/ssl/HelloCookieManager$T13HelloCookieManager.h>

#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/SecureRandom.h>
#include <java/util/Arrays.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientHello$ClientHelloMessage.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/HandshakeProducer.h>
#include <sun/security/ssl/HelloCookieManager.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/ServerHello.h>
#include <jcpp.h>

#undef MESSAGE_HASH

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $SecureRandom = ::java::security::SecureRandom;
using $Arrays = ::java::util::Arrays;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $ClientHello$ClientHelloMessage = ::sun::security::ssl::ClientHello$ClientHelloMessage;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $HandshakeProducer = ::sun::security::ssl::HandshakeProducer;
using $HelloCookieManager = ::sun::security::ssl::HelloCookieManager;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $ServerHello = ::sun::security::ssl::ServerHello;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _HelloCookieManager$T13HelloCookieManager_FieldInfo_[] = {
	{"secureRandom", "Ljava/security/SecureRandom;", nullptr, $FINAL, $field(HelloCookieManager$T13HelloCookieManager, secureRandom)},
	{"cookieVersion", "I", nullptr, $PRIVATE, $field(HelloCookieManager$T13HelloCookieManager, cookieVersion)},
	{"cookieSecret", "[B", nullptr, $PRIVATE | $FINAL, $field(HelloCookieManager$T13HelloCookieManager, cookieSecret)},
	{"legacySecret", "[B", nullptr, $PRIVATE | $FINAL, $field(HelloCookieManager$T13HelloCookieManager, legacySecret)},
	{"t13ManagerLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(HelloCookieManager$T13HelloCookieManager, t13ManagerLock)},
	{}
};

$MethodInfo _HelloCookieManager$T13HelloCookieManager_MethodInfo_[] = {
	{"<init>", "(Ljava/security/SecureRandom;)V", nullptr, 0, $method(HelloCookieManager$T13HelloCookieManager, init$, void, $SecureRandom*)},
	{"createCookie", "(Lsun/security/ssl/ServerHandshakeContext;Lsun/security/ssl/ClientHello$ClientHelloMessage;)[B", nullptr, 0, $virtualMethod(HelloCookieManager$T13HelloCookieManager, createCookie, $bytes*, $ServerHandshakeContext*, $ClientHello$ClientHelloMessage*), "java.io.IOException"},
	{"isCookieValid", "(Lsun/security/ssl/ServerHandshakeContext;Lsun/security/ssl/ClientHello$ClientHelloMessage;[B)Z", nullptr, 0, $virtualMethod(HelloCookieManager$T13HelloCookieManager, isCookieValid, bool, $ServerHandshakeContext*, $ClientHello$ClientHelloMessage*, $bytes*), "java.io.IOException"},
	{}
};

$InnerClassInfo _HelloCookieManager$T13HelloCookieManager_InnerClassesInfo_[] = {
	{"sun.security.ssl.HelloCookieManager$T13HelloCookieManager", "sun.security.ssl.HelloCookieManager", "T13HelloCookieManager", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _HelloCookieManager$T13HelloCookieManager_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.HelloCookieManager$T13HelloCookieManager",
	"sun.security.ssl.HelloCookieManager",
	nullptr,
	_HelloCookieManager$T13HelloCookieManager_FieldInfo_,
	_HelloCookieManager$T13HelloCookieManager_MethodInfo_,
	nullptr,
	nullptr,
	_HelloCookieManager$T13HelloCookieManager_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.HelloCookieManager"
};

$Object* allocate$HelloCookieManager$T13HelloCookieManager($Class* clazz) {
	return $of($alloc(HelloCookieManager$T13HelloCookieManager));
}

void HelloCookieManager$T13HelloCookieManager::init$($SecureRandom* secureRandom) {
	$HelloCookieManager::init$();
	$set(this, t13ManagerLock, $new($ReentrantLock));
	$set(this, secureRandom, secureRandom);
	this->cookieVersion = $nc(secureRandom)->nextInt();
	$set(this, cookieSecret, $new($bytes, 64));
	$set(this, legacySecret, $new($bytes, 64));
	secureRandom->nextBytes(this->cookieSecret);
	$System::arraycopy(this->cookieSecret, 0, this->legacySecret, 0, 64);
}

$bytes* HelloCookieManager$T13HelloCookieManager::createCookie($ServerHandshakeContext* context, $ClientHello$ClientHelloMessage* clientHello) {
	$useLocalCurrentObjectStackCache();
	int32_t version = 0;
	$var($bytes, secret, nullptr);
	$nc(this->t13ManagerLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			version = this->cookieVersion;
			$assign(secret, this->cookieSecret);
			if (((int32_t)(this->cookieVersion & (uint32_t)0x00FFFFFF)) == 0) {
				$System::arraycopy(this->cookieSecret, 0, this->legacySecret, 0, 64);
				$nc(this->secureRandom)->nextBytes(this->cookieSecret);
			}
			++this->cookieVersion;
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->t13ManagerLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var($MessageDigest, md, nullptr);
	try {
		$assign(md, $MessageDigest::getInstance($nc($nc(context)->negotiatedCipherSuite)->hashAlg->name$));
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($RuntimeException, $$str({"MessageDigest algorithm "_s, $nc($nc(context)->negotiatedCipherSuite)->hashAlg->name$, " is not available"_s}), nsae);
	}
	$var($bytes, headerBytes, $nc(clientHello)->getHeaderBytes());
	$nc(md)->update(headerBytes);
	$var($bytes, headerCookie, md->digest(secret));
	$nc($nc(context)->handshakeHash)->update();
	$var($bytes, clientHelloHash, $nc(context->handshakeHash)->digest());
	$var($bytes, prefix, $new($bytes, {
		(int8_t)((int32_t)(($nc(context->negotiatedCipherSuite)->id >> 8) & (uint32_t)255)),
		(int8_t)((int32_t)($nc(context->negotiatedCipherSuite)->id & (uint32_t)255)),
		(int8_t)((int32_t)((version >> 24) & (uint32_t)255))
	}));
	$var($bytes, cookie, $Arrays::copyOf(prefix, prefix->length + $nc(headerCookie)->length + $nc(clientHelloHash)->length));
	$System::arraycopy(headerCookie, 0, cookie, prefix->length, $nc(headerCookie)->length);
	$System::arraycopy(clientHelloHash, 0, cookie, prefix->length + $nc(headerCookie)->length, $nc(clientHelloHash)->length);
	return cookie;
}

bool HelloCookieManager$T13HelloCookieManager::isCookieValid($ServerHandshakeContext* context, $ClientHello$ClientHelloMessage* clientHello, $bytes* cookie) {
	$useLocalCurrentObjectStackCache();
	if ((cookie == nullptr) || ($nc(cookie)->length <= 32)) {
		return false;
	}
	int32_t csId = (((int32_t)($nc(cookie)->get(0) & (uint32_t)255)) << 8) | ((int32_t)(cookie->get(1) & (uint32_t)255));
	$CipherSuite* cs = $CipherSuite::valueOf(csId);
	if (cs == nullptr || $nc(cs)->hashAlg == nullptr || $nc(cs)->hashAlg->hashLength == 0) {
		return false;
	}
	int32_t hashLen = $nc(cs)->hashAlg->hashLength;
	if (cookie->length != (3 + hashLen * 2)) {
		return false;
	}
	$var($bytes, prevHeadCookie, $Arrays::copyOfRange(cookie, 3, 3 + hashLen));
	$var($bytes, prevClientHelloHash, $Arrays::copyOfRange(cookie, 3 + hashLen, cookie->length));
	$var($bytes, secret, nullptr);
	$nc(this->t13ManagerLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if ((int8_t)((int32_t)((this->cookieVersion >> 24) & (uint32_t)255)) == cookie->get(2)) {
				$assign(secret, this->cookieSecret);
			} else {
				$assign(secret, this->legacySecret);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->t13ManagerLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var($MessageDigest, md, nullptr);
	try {
		$assign(md, $MessageDigest::getInstance(cs->hashAlg->name$));
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($RuntimeException, $$str({"MessageDigest algorithm "_s, cs->hashAlg->name$, " is not available"_s}), nsae);
	}
	$var($bytes, headerBytes, $nc(clientHello)->getHeaderBytes());
	$nc(md)->update(headerBytes);
	$var($bytes, headerCookie, md->digest(secret));
	if (!$Arrays::equals(headerCookie, prevHeadCookie)) {
		return false;
	}
	$init($ServerHello);
	$var($bytes, hrrMessage, $nc($ServerHello::hrrReproducer)->produce(context, clientHello));
	$nc($nc(context)->handshakeHash)->push(hrrMessage);
	$var($bytes, hashedClientHello, $new($bytes, 4 + hashLen));
	$init($SSLHandshake);
	hashedClientHello->set(0, $SSLHandshake::MESSAGE_HASH->id);
	hashedClientHello->set(1, (int8_t)0);
	hashedClientHello->set(2, (int8_t)0);
	hashedClientHello->set(3, (int8_t)((int32_t)(hashLen & (uint32_t)255)));
	$System::arraycopy(prevClientHelloHash, 0, hashedClientHello, 4, hashLen);
	$nc(context->handshakeHash)->push(hashedClientHello);
	return true;
}

HelloCookieManager$T13HelloCookieManager::HelloCookieManager$T13HelloCookieManager() {
}

$Class* HelloCookieManager$T13HelloCookieManager::load$($String* name, bool initialize) {
	$loadClass(HelloCookieManager$T13HelloCookieManager, name, initialize, &_HelloCookieManager$T13HelloCookieManager_ClassInfo_, allocate$HelloCookieManager$T13HelloCookieManager);
	return class$;
}

$Class* HelloCookieManager$T13HelloCookieManager::class$ = nullptr;

		} // ssl
	} // security
} // sun