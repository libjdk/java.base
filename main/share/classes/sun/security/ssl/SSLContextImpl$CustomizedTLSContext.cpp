#include <sun/security/ssl/SSLContextImpl$CustomizedTLSContext.h>

#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLContextImpl$AbstractTLSContext.h>
#include <sun/security/ssl/SSLContextImpl$CustomizedSSLProtocols.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <jcpp.h>

#undef TLS10
#undef TLS11
#undef TLS12
#undef TLS13

using $ProtocolVersionArray = $Array<::sun::security::ssl::ProtocolVersion>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLContextImpl$AbstractTLSContext = ::sun::security::ssl::SSLContextImpl$AbstractTLSContext;
using $SSLContextImpl$CustomizedSSLProtocols = ::sun::security::ssl::SSLContextImpl$CustomizedSSLProtocols;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLContextImpl$CustomizedTLSContext_FieldInfo_[] = {
	{"clientDefaultProtocols", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$CustomizedTLSContext, clientDefaultProtocols)},
	{"serverDefaultProtocols", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$CustomizedTLSContext, serverDefaultProtocols)},
	{"clientDefaultCipherSuites", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$CustomizedTLSContext, clientDefaultCipherSuites)},
	{"serverDefaultCipherSuites", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$CustomizedTLSContext, serverDefaultCipherSuites)},
	{"reservedException", "Ljava/lang/IllegalArgumentException;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$CustomizedTLSContext, reservedException)},
	{}
};

$MethodInfo _SSLContextImpl$CustomizedTLSContext_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(SSLContextImpl$CustomizedTLSContext, init$, void)},
	{"customizedProtocols", "(ZLjava/util/List;)Ljava/util/List;", "(ZLjava/util/List<Lsun/security/ssl/ProtocolVersion;>;)Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", $PRIVATE | $STATIC, $staticMethod(SSLContextImpl$CustomizedTLSContext, customizedProtocols, $List*, bool, $List*)},
	{"getClientDefaultCipherSuites", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", 0, $virtualMethod(SSLContextImpl$CustomizedTLSContext, getClientDefaultCipherSuites, $List*)},
	{"getClientDefaultProtocolVersions", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", 0, $virtualMethod(SSLContextImpl$CustomizedTLSContext, getClientDefaultProtocolVersions, $List*)},
	{"getServerDefaultCipherSuites", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", 0, $virtualMethod(SSLContextImpl$CustomizedTLSContext, getServerDefaultCipherSuites, $List*)},
	{"getServerDefaultProtocolVersions", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", 0, $virtualMethod(SSLContextImpl$CustomizedTLSContext, getServerDefaultProtocolVersions, $List*)},
	{}
};

$InnerClassInfo _SSLContextImpl$CustomizedTLSContext_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLContextImpl$CustomizedTLSContext", "sun.security.ssl.SSLContextImpl", "CustomizedTLSContext", $PRIVATE | $STATIC},
	{"sun.security.ssl.SSLContextImpl$AbstractTLSContext", "sun.security.ssl.SSLContextImpl", "AbstractTLSContext", $PRIVATE | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SSLContextImpl$CustomizedTLSContext_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.ssl.SSLContextImpl$CustomizedTLSContext",
	"sun.security.ssl.SSLContextImpl$AbstractTLSContext",
	nullptr,
	_SSLContextImpl$CustomizedTLSContext_FieldInfo_,
	_SSLContextImpl$CustomizedTLSContext_MethodInfo_,
	nullptr,
	nullptr,
	_SSLContextImpl$CustomizedTLSContext_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLContextImpl"
};

$Object* allocate$SSLContextImpl$CustomizedTLSContext($Class* clazz) {
	return $of($alloc(SSLContextImpl$CustomizedTLSContext));
}

$List* SSLContextImpl$CustomizedTLSContext::clientDefaultProtocols = nullptr;
$List* SSLContextImpl$CustomizedTLSContext::serverDefaultProtocols = nullptr;
$List* SSLContextImpl$CustomizedTLSContext::clientDefaultCipherSuites = nullptr;
$List* SSLContextImpl$CustomizedTLSContext::serverDefaultCipherSuites = nullptr;
$IllegalArgumentException* SSLContextImpl$CustomizedTLSContext::reservedException = nullptr;

$List* SSLContextImpl$CustomizedTLSContext::customizedProtocols(bool client, $List* customized) {
	$init(SSLContextImpl$CustomizedTLSContext);
	$useLocalCurrentObjectStackCache();
	$var($List, refactored, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(customized)->iterator());
		for (; $nc(i$)->hasNext();) {
			$ProtocolVersion* pv = $cast($ProtocolVersion, i$->next());
			{
				if (!$nc(pv)->isDTLS) {
					refactored->add(pv);
				}
			}
		}
	}
	$var($ProtocolVersionArray, candidates, nullptr);
	if (refactored->isEmpty()) {
		$init($ProtocolVersion);
		$assign(candidates, $new($ProtocolVersionArray, {
			$ProtocolVersion::TLS13,
			$ProtocolVersion::TLS12,
			$ProtocolVersion::TLS11,
			$ProtocolVersion::TLS10
		}));
	} else {
		$assign(candidates, $fcast($ProtocolVersionArray, refactored->toArray($$new($ProtocolVersionArray, 0))));
	}
	return $SSLContextImpl::getAvailableProtocols(candidates);
}

void SSLContextImpl$CustomizedTLSContext::init$() {
	$SSLContextImpl$AbstractTLSContext::init$();
	if (SSLContextImpl$CustomizedTLSContext::reservedException != nullptr) {
		$throw(SSLContextImpl$CustomizedTLSContext::reservedException);
	}
}

$List* SSLContextImpl$CustomizedTLSContext::getClientDefaultProtocolVersions() {
	return SSLContextImpl$CustomizedTLSContext::clientDefaultProtocols;
}

$List* SSLContextImpl$CustomizedTLSContext::getServerDefaultProtocolVersions() {
	return SSLContextImpl$CustomizedTLSContext::serverDefaultProtocols;
}

$List* SSLContextImpl$CustomizedTLSContext::getClientDefaultCipherSuites() {
	return SSLContextImpl$CustomizedTLSContext::clientDefaultCipherSuites;
}

$List* SSLContextImpl$CustomizedTLSContext::getServerDefaultCipherSuites() {
	return SSLContextImpl$CustomizedTLSContext::serverDefaultCipherSuites;
}

void clinit$SSLContextImpl$CustomizedTLSContext($Class* class$) {
	{
		$init($SSLContextImpl$CustomizedSSLProtocols);
		$assignStatic(SSLContextImpl$CustomizedTLSContext::reservedException, $SSLContextImpl$CustomizedSSLProtocols::reservedException);
		if (SSLContextImpl$CustomizedTLSContext::reservedException == nullptr) {
			$assignStatic(SSLContextImpl$CustomizedTLSContext::clientDefaultProtocols, SSLContextImpl$CustomizedTLSContext::customizedProtocols(true, $SSLContextImpl$CustomizedSSLProtocols::customizedClientProtocols));
			$assignStatic(SSLContextImpl$CustomizedTLSContext::serverDefaultProtocols, SSLContextImpl$CustomizedTLSContext::customizedProtocols(false, $SSLContextImpl$CustomizedSSLProtocols::customizedServerProtocols));
			$assignStatic(SSLContextImpl$CustomizedTLSContext::clientDefaultCipherSuites, $SSLContextImpl::getApplicableEnabledCipherSuites(SSLContextImpl$CustomizedTLSContext::clientDefaultProtocols, true));
			$assignStatic(SSLContextImpl$CustomizedTLSContext::serverDefaultCipherSuites, $SSLContextImpl::getApplicableEnabledCipherSuites(SSLContextImpl$CustomizedTLSContext::serverDefaultProtocols, false));
		} else {
			$assignStatic(SSLContextImpl$CustomizedTLSContext::clientDefaultProtocols, nullptr);
			$assignStatic(SSLContextImpl$CustomizedTLSContext::serverDefaultProtocols, nullptr);
			$assignStatic(SSLContextImpl$CustomizedTLSContext::clientDefaultCipherSuites, nullptr);
			$assignStatic(SSLContextImpl$CustomizedTLSContext::serverDefaultCipherSuites, nullptr);
		}
	}
}

SSLContextImpl$CustomizedTLSContext::SSLContextImpl$CustomizedTLSContext() {
}

$Class* SSLContextImpl$CustomizedTLSContext::load$($String* name, bool initialize) {
	$loadClass(SSLContextImpl$CustomizedTLSContext, name, initialize, &_SSLContextImpl$CustomizedTLSContext_ClassInfo_, clinit$SSLContextImpl$CustomizedTLSContext, allocate$SSLContextImpl$CustomizedTLSContext);
	return class$;
}

$Class* SSLContextImpl$CustomizedTLSContext::class$ = nullptr;

		} // ssl
	} // security
} // sun