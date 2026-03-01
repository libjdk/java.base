#include <sun/security/ssl/SSLContextImpl$DefaultSSLContextHolder.h>

#include <java/security/KeyManagementException.h>
#include <sun/security/ssl/SSLContextImpl$DefaultManagersHolder.h>
#include <sun/security/ssl/SSLContextImpl$DefaultSSLContext.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLLogger.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $KeyManagementException = ::java::security::KeyManagementException;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLContextImpl$DefaultManagersHolder = ::sun::security::ssl::SSLContextImpl$DefaultManagersHolder;
using $SSLContextImpl$DefaultSSLContext = ::sun::security::ssl::SSLContextImpl$DefaultSSLContext;
using $SSLLogger = ::sun::security::ssl::SSLLogger;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLContextImpl$DefaultSSLContextHolder_FieldInfo_[] = {
	{"sslContext", "Lsun/security/ssl/SSLContextImpl;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$DefaultSSLContextHolder, sslContext)},
	{"reservedException", "Ljava/lang/Exception;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$DefaultSSLContextHolder, reservedException)},
	{}
};

$MethodInfo _SSLContextImpl$DefaultSSLContextHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(SSLContextImpl$DefaultSSLContextHolder, init$, void)},
	{}
};

$InnerClassInfo _SSLContextImpl$DefaultSSLContextHolder_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLContextImpl$DefaultSSLContextHolder", "sun.security.ssl.SSLContextImpl", "DefaultSSLContextHolder", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _SSLContextImpl$DefaultSSLContextHolder_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLContextImpl$DefaultSSLContextHolder",
	"java.lang.Object",
	nullptr,
	_SSLContextImpl$DefaultSSLContextHolder_FieldInfo_,
	_SSLContextImpl$DefaultSSLContextHolder_MethodInfo_,
	nullptr,
	nullptr,
	_SSLContextImpl$DefaultSSLContextHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLContextImpl"
};

$Object* allocate$SSLContextImpl$DefaultSSLContextHolder($Class* clazz) {
	return $of($alloc(SSLContextImpl$DefaultSSLContextHolder));
}

$SSLContextImpl* SSLContextImpl$DefaultSSLContextHolder::sslContext = nullptr;
$Exception* SSLContextImpl$DefaultSSLContextHolder::reservedException = nullptr;

void SSLContextImpl$DefaultSSLContextHolder::init$() {
}

void clinit$SSLContextImpl$DefaultSSLContextHolder($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Exception, reserved, nullptr);
		$var($SSLContextImpl, mediator, nullptr);
		$init($SSLContextImpl$DefaultManagersHolder);
		if ($SSLContextImpl$DefaultManagersHolder::reservedException != nullptr) {
			$assign(reserved, $SSLContextImpl$DefaultManagersHolder::reservedException);
		} else {
			try {
				$assign(mediator, $new($SSLContextImpl$DefaultSSLContext));
			} catch ($Exception& e) {
				$assign(reserved, $new($KeyManagementException, $(e->getMessage())));
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,defaultctx"_s)) {
					$SSLLogger::warning("Failed to load default SSLContext"_s, $$new($ObjectArray, {$of(e)}));
				}
			}
		}
		$assignStatic(SSLContextImpl$DefaultSSLContextHolder::sslContext, mediator);
		$assignStatic(SSLContextImpl$DefaultSSLContextHolder::reservedException, reserved);
	}
}

SSLContextImpl$DefaultSSLContextHolder::SSLContextImpl$DefaultSSLContextHolder() {
}

$Class* SSLContextImpl$DefaultSSLContextHolder::load$($String* name, bool initialize) {
	$loadClass(SSLContextImpl$DefaultSSLContextHolder, name, initialize, &_SSLContextImpl$DefaultSSLContextHolder_ClassInfo_, clinit$SSLContextImpl$DefaultSSLContextHolder, allocate$SSLContextImpl$DefaultSSLContextHolder);
	return class$;
}

$Class* SSLContextImpl$DefaultSSLContextHolder::class$ = nullptr;

		} // ssl
	} // security
} // sun