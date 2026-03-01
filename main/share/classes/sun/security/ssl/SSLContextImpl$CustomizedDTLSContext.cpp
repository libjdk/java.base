#include <sun/security/ssl/SSLContextImpl$CustomizedDTLSContext.h>

#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLContextImpl$AbstractDTLSContext.h>
#include <sun/security/ssl/SSLContextImpl$CustomizedSSLProtocols.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <jcpp.h>

#undef DTLS10
#undef DTLS12

using $ProtocolVersionArray = $Array<::sun::security::ssl::ProtocolVersion>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLContextImpl$AbstractDTLSContext = ::sun::security::ssl::SSLContextImpl$AbstractDTLSContext;
using $SSLContextImpl$CustomizedSSLProtocols = ::sun::security::ssl::SSLContextImpl$CustomizedSSLProtocols;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLContextImpl$CustomizedDTLSContext_FieldInfo_[] = {
	{"clientDefaultProtocols", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$CustomizedDTLSContext, clientDefaultProtocols)},
	{"serverDefaultProtocols", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$CustomizedDTLSContext, serverDefaultProtocols)},
	{"clientDefaultCipherSuites", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$CustomizedDTLSContext, clientDefaultCipherSuites)},
	{"serverDefaultCipherSuites", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SSLContextImpl$CustomizedDTLSContext, serverDefaultCipherSuites)},
	{"reservedException", "Ljava/lang/IllegalArgumentException;", nullptr, $PRIVATE | $STATIC, $staticField(SSLContextImpl$CustomizedDTLSContext, reservedException)},
	{}
};

$MethodInfo _SSLContextImpl$CustomizedDTLSContext_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(SSLContextImpl$CustomizedDTLSContext, init$, void)},
	{"customizedProtocols", "(ZLjava/util/List;)Ljava/util/List;", "(ZLjava/util/List<Lsun/security/ssl/ProtocolVersion;>;)Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", $PRIVATE | $STATIC, $staticMethod(SSLContextImpl$CustomizedDTLSContext, customizedProtocols, $List*, bool, $List*)},
	{"getClientDefaultCipherSuites", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", 0, $virtualMethod(SSLContextImpl$CustomizedDTLSContext, getClientDefaultCipherSuites, $List*)},
	{"getClientDefaultProtocolVersions", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", 0, $virtualMethod(SSLContextImpl$CustomizedDTLSContext, getClientDefaultProtocolVersions, $List*)},
	{"getServerDefaultCipherSuites", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", 0, $virtualMethod(SSLContextImpl$CustomizedDTLSContext, getServerDefaultCipherSuites, $List*)},
	{"getServerDefaultProtocolVersions", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", 0, $virtualMethod(SSLContextImpl$CustomizedDTLSContext, getServerDefaultProtocolVersions, $List*)},
	{}
};

$InnerClassInfo _SSLContextImpl$CustomizedDTLSContext_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLContextImpl$CustomizedDTLSContext", "sun.security.ssl.SSLContextImpl", "CustomizedDTLSContext", $PRIVATE | $STATIC},
	{"sun.security.ssl.SSLContextImpl$AbstractDTLSContext", "sun.security.ssl.SSLContextImpl", "AbstractDTLSContext", $PRIVATE | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SSLContextImpl$CustomizedDTLSContext_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.ssl.SSLContextImpl$CustomizedDTLSContext",
	"sun.security.ssl.SSLContextImpl$AbstractDTLSContext",
	nullptr,
	_SSLContextImpl$CustomizedDTLSContext_FieldInfo_,
	_SSLContextImpl$CustomizedDTLSContext_MethodInfo_,
	nullptr,
	nullptr,
	_SSLContextImpl$CustomizedDTLSContext_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLContextImpl"
};

$Object* allocate$SSLContextImpl$CustomizedDTLSContext($Class* clazz) {
	return $of($alloc(SSLContextImpl$CustomizedDTLSContext));
}

$List* SSLContextImpl$CustomizedDTLSContext::clientDefaultProtocols = nullptr;
$List* SSLContextImpl$CustomizedDTLSContext::serverDefaultProtocols = nullptr;
$List* SSLContextImpl$CustomizedDTLSContext::clientDefaultCipherSuites = nullptr;
$List* SSLContextImpl$CustomizedDTLSContext::serverDefaultCipherSuites = nullptr;
$IllegalArgumentException* SSLContextImpl$CustomizedDTLSContext::reservedException = nullptr;

$List* SSLContextImpl$CustomizedDTLSContext::customizedProtocols(bool client, $List* customized) {
	$init(SSLContextImpl$CustomizedDTLSContext);
	$useLocalCurrentObjectStackCache();
	$var($List, refactored, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(customized)->iterator());
		for (; $nc(i$)->hasNext();) {
			$ProtocolVersion* pv = $cast($ProtocolVersion, i$->next());
			{
				if ($nc(pv)->isDTLS) {
					refactored->add(pv);
				}
			}
		}
	}
	$var($ProtocolVersionArray, candidates, nullptr);
	if (refactored->isEmpty()) {
		$init($ProtocolVersion);
		$assign(candidates, $new($ProtocolVersionArray, {
			$ProtocolVersion::DTLS12,
			$ProtocolVersion::DTLS10
		}));
		if (!client) {
			return $Arrays::asList(candidates);
		}
	} else {
		$assign(candidates, $new($ProtocolVersionArray, customized->size()));
		$assign(candidates, $fcast($ProtocolVersionArray, customized->toArray(candidates)));
	}
	return $SSLContextImpl::getAvailableProtocols(candidates);
}

void SSLContextImpl$CustomizedDTLSContext::init$() {
	$SSLContextImpl$AbstractDTLSContext::init$();
	if (SSLContextImpl$CustomizedDTLSContext::reservedException != nullptr) {
		$throw(SSLContextImpl$CustomizedDTLSContext::reservedException);
	}
}

$List* SSLContextImpl$CustomizedDTLSContext::getClientDefaultProtocolVersions() {
	return SSLContextImpl$CustomizedDTLSContext::clientDefaultProtocols;
}

$List* SSLContextImpl$CustomizedDTLSContext::getServerDefaultProtocolVersions() {
	return SSLContextImpl$CustomizedDTLSContext::serverDefaultProtocols;
}

$List* SSLContextImpl$CustomizedDTLSContext::getClientDefaultCipherSuites() {
	return SSLContextImpl$CustomizedDTLSContext::clientDefaultCipherSuites;
}

$List* SSLContextImpl$CustomizedDTLSContext::getServerDefaultCipherSuites() {
	return SSLContextImpl$CustomizedDTLSContext::serverDefaultCipherSuites;
}

void clinit$SSLContextImpl$CustomizedDTLSContext($Class* class$) {
	{
		$init($SSLContextImpl$CustomizedSSLProtocols);
		$assignStatic(SSLContextImpl$CustomizedDTLSContext::reservedException, $SSLContextImpl$CustomizedSSLProtocols::reservedException);
		if (SSLContextImpl$CustomizedDTLSContext::reservedException == nullptr) {
			$assignStatic(SSLContextImpl$CustomizedDTLSContext::clientDefaultProtocols, SSLContextImpl$CustomizedDTLSContext::customizedProtocols(true, $SSLContextImpl$CustomizedSSLProtocols::customizedClientProtocols));
			$assignStatic(SSLContextImpl$CustomizedDTLSContext::serverDefaultProtocols, SSLContextImpl$CustomizedDTLSContext::customizedProtocols(false, $SSLContextImpl$CustomizedSSLProtocols::customizedServerProtocols));
			$assignStatic(SSLContextImpl$CustomizedDTLSContext::clientDefaultCipherSuites, $SSLContextImpl::getApplicableEnabledCipherSuites(SSLContextImpl$CustomizedDTLSContext::clientDefaultProtocols, true));
			$assignStatic(SSLContextImpl$CustomizedDTLSContext::serverDefaultCipherSuites, $SSLContextImpl::getApplicableEnabledCipherSuites(SSLContextImpl$CustomizedDTLSContext::serverDefaultProtocols, false));
		} else {
			$assignStatic(SSLContextImpl$CustomizedDTLSContext::clientDefaultProtocols, nullptr);
			$assignStatic(SSLContextImpl$CustomizedDTLSContext::serverDefaultProtocols, nullptr);
			$assignStatic(SSLContextImpl$CustomizedDTLSContext::clientDefaultCipherSuites, nullptr);
			$assignStatic(SSLContextImpl$CustomizedDTLSContext::serverDefaultCipherSuites, nullptr);
		}
	}
}

SSLContextImpl$CustomizedDTLSContext::SSLContextImpl$CustomizedDTLSContext() {
}

$Class* SSLContextImpl$CustomizedDTLSContext::load$($String* name, bool initialize) {
	$loadClass(SSLContextImpl$CustomizedDTLSContext, name, initialize, &_SSLContextImpl$CustomizedDTLSContext_ClassInfo_, clinit$SSLContextImpl$CustomizedDTLSContext, allocate$SSLContextImpl$CustomizedDTLSContext);
	return class$;
}

$Class* SSLContextImpl$CustomizedDTLSContext::class$ = nullptr;

		} // ssl
	} // security
} // sun