#include <sun/security/ssl/SSLContextImpl$DefaultManagersHolder.h>

#include <java/io/FileInputStream.h>
#include <java/io/InputStream.h>
#include <java/security/AccessController.h>
#include <java/security/KeyManagementException.h>
#include <java/security/KeyStore.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/security/Provider.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <javax/net/ssl/KeyManager.h>
#include <javax/net/ssl/KeyManagerFactory.h>
#include <javax/net/ssl/TrustManager.h>
#include <javax/net/ssl/TrustManagerFactory.h>
#include <sun/security/ssl/SSLContextImpl$DefaultManagersHolder$1.h>
#include <sun/security/ssl/SSLContextImpl$DefaultManagersHolder$2.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/TrustStoreManager.h>
#include <jcpp.h>

#undef NONE
#undef P11KEYSTORE

using $KeyManagerArray = $Array<::javax::net::ssl::KeyManager>;
using $TrustManagerArray = $Array<::javax::net::ssl::TrustManager>;
using $FileInputStream = ::java::io::FileInputStream;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $KeyManagementException = ::java::security::KeyManagementException;
using $KeyStore = ::java::security::KeyStore;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Provider = ::java::security::Provider;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $KeyManagerFactory = ::javax::net::ssl::KeyManagerFactory;
using $TrustManagerFactory = ::javax::net::ssl::TrustManagerFactory;
using $SSLContextImpl$DefaultManagersHolder$1 = ::sun::security::ssl::SSLContextImpl$DefaultManagersHolder$1;
using $SSLContextImpl$DefaultManagersHolder$2 = ::sun::security::ssl::SSLContextImpl$DefaultManagersHolder$2;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $TrustStoreManager = ::sun::security::ssl::TrustStoreManager;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLContextImpl$DefaultManagersHolder_FieldInfo_[] = {
	{"NONE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$DefaultManagersHolder, NONE)},
	{"P11KEYSTORE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$DefaultManagersHolder, P11KEYSTORE)},
	{"trustManagers", "[Ljavax/net/ssl/TrustManager;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$DefaultManagersHolder, trustManagers)},
	{"keyManagers", "[Ljavax/net/ssl/KeyManager;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$DefaultManagersHolder, keyManagers)},
	{"reservedException", "Ljava/lang/Exception;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$DefaultManagersHolder, reservedException)},
	{}
};

$MethodInfo _SSLContextImpl$DefaultManagersHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(SSLContextImpl$DefaultManagersHolder, init$, void)},
	{"getKeyManagers", "()[Ljavax/net/ssl/KeyManager;", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLContextImpl$DefaultManagersHolder, getKeyManagers, $KeyManagerArray*), "java.lang.Exception"},
	{"getTrustManagers", "()[Ljavax/net/ssl/TrustManager;", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLContextImpl$DefaultManagersHolder, getTrustManagers, $TrustManagerArray*), "java.lang.Exception"},
	{}
};

$InnerClassInfo _SSLContextImpl$DefaultManagersHolder_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLContextImpl$DefaultManagersHolder", "sun.security.ssl.SSLContextImpl", "DefaultManagersHolder", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLContextImpl$DefaultManagersHolder$2", nullptr, nullptr, 0},
	{"sun.security.ssl.SSLContextImpl$DefaultManagersHolder$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SSLContextImpl$DefaultManagersHolder_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLContextImpl$DefaultManagersHolder",
	"java.lang.Object",
	nullptr,
	_SSLContextImpl$DefaultManagersHolder_FieldInfo_,
	_SSLContextImpl$DefaultManagersHolder_MethodInfo_,
	nullptr,
	nullptr,
	_SSLContextImpl$DefaultManagersHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLContextImpl"
};

$Object* allocate$SSLContextImpl$DefaultManagersHolder($Class* clazz) {
	return $of($alloc(SSLContextImpl$DefaultManagersHolder));
}

$String* SSLContextImpl$DefaultManagersHolder::NONE = nullptr;
$String* SSLContextImpl$DefaultManagersHolder::P11KEYSTORE = nullptr;
$TrustManagerArray* SSLContextImpl$DefaultManagersHolder::trustManagers = nullptr;
$KeyManagerArray* SSLContextImpl$DefaultManagersHolder::keyManagers = nullptr;
$Exception* SSLContextImpl$DefaultManagersHolder::reservedException = nullptr;

void SSLContextImpl$DefaultManagersHolder::init$() {
}

$TrustManagerArray* SSLContextImpl$DefaultManagersHolder::getTrustManagers() {
	$init(SSLContextImpl$DefaultManagersHolder);
	$useLocalCurrentObjectStackCache();
	$var($TrustManagerFactory, tmf, $TrustManagerFactory::getInstance($($TrustManagerFactory::getDefaultAlgorithm())));
	if ("SunJSSE"_s->equals($($nc($($nc(tmf)->getProvider()))->getName()))) {
		$nc(tmf)->init(($KeyStore*)nullptr);
	} else {
		$var($KeyStore, ks, $TrustStoreManager::getTrustedKeyStore());
		$nc(tmf)->init(ks);
	}
	return $nc(tmf)->getTrustManagers();
}

$KeyManagerArray* SSLContextImpl$DefaultManagersHolder::getKeyManagers() {
	$init(SSLContextImpl$DefaultManagersHolder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Map, props, $new($HashMap));
	$AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($SSLContextImpl$DefaultManagersHolder$1, props)));
	$var($String, defaultKeyStore, $cast($String, props->get("keyStore"_s)));
	$var($String, defaultKeyStoreType, $cast($String, props->get("keyStoreType"_s)));
	$var($String, defaultKeyStoreProvider, $cast($String, props->get("keyStoreProvider"_s)));
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,defaultctx"_s)) {
		$SSLLogger::fine($$str({"keyStore is : "_s, defaultKeyStore}), $$new($ObjectArray, 0));
		$SSLLogger::fine($$str({"keyStore type is : "_s, defaultKeyStoreType}), $$new($ObjectArray, 0));
		$SSLLogger::fine($$str({"keyStore provider is : "_s, defaultKeyStoreProvider}), $$new($ObjectArray, 0));
	}
	bool var$0 = $nc(SSLContextImpl$DefaultManagersHolder::P11KEYSTORE)->equals(defaultKeyStoreType);
	if (var$0 && !$nc(SSLContextImpl$DefaultManagersHolder::NONE)->equals(defaultKeyStore)) {
		$throwNew($IllegalArgumentException, $$str({"if keyStoreType is "_s, SSLContextImpl$DefaultManagersHolder::P11KEYSTORE, ", then keyStore must be "_s, SSLContextImpl$DefaultManagersHolder::NONE}));
	}
	$var($FileInputStream, fs, nullptr);
	$var($KeyStore, ks, nullptr);
	$var($chars, passwd, nullptr);
	{
		$var($Throwable, var$1, nullptr);
		try {
			bool var$2 = !$nc(defaultKeyStore)->isEmpty();
			if (var$2 && !$nc(SSLContextImpl$DefaultManagersHolder::NONE)->equals(defaultKeyStore)) {
				$assign(fs, $cast($FileInputStream, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($SSLContextImpl$DefaultManagersHolder$2, defaultKeyStore)))));
			}
			$var($String, defaultKeyStorePassword, $cast($String, props->get("keyStorePasswd"_s)));
			if (!$nc(defaultKeyStorePassword)->isEmpty()) {
				$assign(passwd, defaultKeyStorePassword->toCharArray());
			}
			if (($nc(defaultKeyStoreType)->length()) != 0) {
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,defaultctx"_s)) {
					$SSLLogger::finest("init keystore"_s, $$new($ObjectArray, 0));
				}
				if ($nc(defaultKeyStoreProvider)->isEmpty()) {
					$assign(ks, $KeyStore::getInstance(defaultKeyStoreType));
				} else {
					$assign(ks, $KeyStore::getInstance(defaultKeyStoreType, defaultKeyStoreProvider));
				}
				$nc(ks)->load(fs, passwd);
			}
		} catch ($Throwable& var$3) {
			$assign(var$1, var$3);
		} /*finally*/ {
			if (fs != nullptr) {
				fs->close();
				$assign(fs, nullptr);
			}
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
	}
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,defaultctx"_s)) {
		$SSLLogger::fine($$str({"init keymanager of type "_s, $($KeyManagerFactory::getDefaultAlgorithm())}), $$new($ObjectArray, 0));
	}
	$var($KeyManagerFactory, kmf, $KeyManagerFactory::getInstance($($KeyManagerFactory::getDefaultAlgorithm())));
	if ($nc(SSLContextImpl$DefaultManagersHolder::P11KEYSTORE)->equals(defaultKeyStoreType)) {
		$nc(kmf)->init(ks, nullptr);
	} else {
		$nc(kmf)->init(ks, passwd);
	}
	return $nc(kmf)->getKeyManagers();
}

void clinit$SSLContextImpl$DefaultManagersHolder($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(SSLContextImpl$DefaultManagersHolder::NONE, "NONE"_s);
	$assignStatic(SSLContextImpl$DefaultManagersHolder::P11KEYSTORE, "PKCS11"_s);
	{
		$var($Exception, reserved, nullptr);
		$var($TrustManagerArray, tmMediator, nullptr);
		try {
			$assign(tmMediator, SSLContextImpl$DefaultManagersHolder::getTrustManagers());
		} catch ($Exception& e) {
			$assign(reserved, e);
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,defaultctx"_s)) {
				$SSLLogger::warning("Failed to load default trust managers"_s, $$new($ObjectArray, {$of(e)}));
			}
		}
		$var($KeyManagerArray, kmMediator, nullptr);
		if (reserved == nullptr) {
			try {
				$assign(kmMediator, SSLContextImpl$DefaultManagersHolder::getKeyManagers());
			} catch ($Exception& e) {
				$assign(reserved, e);
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,defaultctx"_s)) {
					$SSLLogger::warning("Failed to load default key managers"_s, $$new($ObjectArray, {$of(e)}));
				}
			}
		}
		if (reserved != nullptr) {
			$assignStatic(SSLContextImpl$DefaultManagersHolder::trustManagers, $new($TrustManagerArray, 0));
			$assignStatic(SSLContextImpl$DefaultManagersHolder::keyManagers, $new($KeyManagerArray, 0));
			$assignStatic(SSLContextImpl$DefaultManagersHolder::reservedException, $new($KeyManagementException, $(reserved->getMessage())));
		} else {
			$assignStatic(SSLContextImpl$DefaultManagersHolder::trustManagers, tmMediator);
			$assignStatic(SSLContextImpl$DefaultManagersHolder::keyManagers, kmMediator);
			$assignStatic(SSLContextImpl$DefaultManagersHolder::reservedException, nullptr);
		}
	}
}

SSLContextImpl$DefaultManagersHolder::SSLContextImpl$DefaultManagersHolder() {
}

$Class* SSLContextImpl$DefaultManagersHolder::load$($String* name, bool initialize) {
	$loadClass(SSLContextImpl$DefaultManagersHolder, name, initialize, &_SSLContextImpl$DefaultManagersHolder_ClassInfo_, clinit$SSLContextImpl$DefaultManagersHolder, allocate$SSLContextImpl$DefaultManagersHolder);
	return class$;
}

$Class* SSLContextImpl$DefaultManagersHolder::class$ = nullptr;

		} // ssl
	} // security
} // sun