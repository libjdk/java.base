#include <sun/security/ssl/CertStatusExtension$CTCertStatusResponseConsumer.h>

#include <java/nio/ByteBuffer.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusResponse.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusResponseSpec.h>
#include <sun/security/ssl/CertStatusExtension.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $CertStatusExtension$CertStatusResponseSpec = ::sun::security::ssl::CertStatusExtension$CertStatusResponseSpec;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _CertStatusExtension$CTCertStatusResponseConsumer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(CertStatusExtension$CTCertStatusResponseConsumer, init$, void)},
	{"consume", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $virtualMethod(CertStatusExtension$CTCertStatusResponseConsumer, consume, void, $ConnectionContext*, $SSLHandshake$HandshakeMessage*, $ByteBuffer*), "java.io.IOException"},
	{}
};

$InnerClassInfo _CertStatusExtension$CTCertStatusResponseConsumer_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertStatusExtension$CTCertStatusResponseConsumer", "sun.security.ssl.CertStatusExtension", "CTCertStatusResponseConsumer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$ExtensionConsumer", "sun.security.ssl.SSLExtension", "ExtensionConsumer", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _CertStatusExtension$CTCertStatusResponseConsumer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertStatusExtension$CTCertStatusResponseConsumer",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$ExtensionConsumer",
	nullptr,
	_CertStatusExtension$CTCertStatusResponseConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_CertStatusExtension$CTCertStatusResponseConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertStatusExtension"
};

$Object* allocate$CertStatusExtension$CTCertStatusResponseConsumer($Class* clazz) {
	return $of($alloc(CertStatusExtension$CTCertStatusResponseConsumer));
}

void CertStatusExtension$CTCertStatusResponseConsumer::init$() {
}

void CertStatusExtension$CTCertStatusResponseConsumer::consume($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message, $ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, context));
	$var($CertStatusExtension$CertStatusResponseSpec, spec, $new($CertStatusExtension$CertStatusResponseSpec, chc, buffer));
	if ($nc($nc(chc)->sslContext)->isStaplingEnabled(true)) {
		chc->staplingActive = true;
	} else {
		return;
	}
	if (($nc(chc)->handshakeSession != nullptr) && (!chc->isResumption)) {
		$var($List, respList, $new($ArrayList, $(static_cast<$Collection*>($nc(chc->handshakeSession)->getStatusResponses()))));
		respList->add($nc(spec->statusResponse)->encodedResponse);
		$nc(chc->handshakeSession)->setStatusResponses(respList);
	} else {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
			$SSLLogger::finest("Ignoring stapled data on resumed session"_s, $$new($ObjectArray, 0));
		}
	}
}

CertStatusExtension$CTCertStatusResponseConsumer::CertStatusExtension$CTCertStatusResponseConsumer() {
}

$Class* CertStatusExtension$CTCertStatusResponseConsumer::load$($String* name, bool initialize) {
	$loadClass(CertStatusExtension$CTCertStatusResponseConsumer, name, initialize, &_CertStatusExtension$CTCertStatusResponseConsumer_ClassInfo_, allocate$CertStatusExtension$CTCertStatusResponseConsumer);
	return class$;
}

$Class* CertStatusExtension$CTCertStatusResponseConsumer::class$ = nullptr;

		} // ssl
	} // security
} // sun