#include <sun/security/ssl/SSLAlgorithmConstraints.h>

#include <java/security/AlgorithmConstraints.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/Key.h>
#include <java/util/Set.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLParameters.h>
#include <javax/net/ssl/SSLSocket.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/SSLAlgorithmConstraints$SupportedSignatureAlgorithmConstraints.h>
#include <sun/security/ssl/SSLAlgorithmDecomposer.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLEngineImpl.h>
#include <sun/security/ssl/SSLSocketImpl.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/util/AlgorithmDecomposer.h>
#include <sun/security/util/DisabledAlgorithmConstraints.h>
#include <jcpp.h>

#undef DEFAULT
#undef DEFAULT_SSL_ONLY

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $Key = ::java::security::Key;
using $Set = ::java::util::Set;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $SSLSocket = ::javax::net::ssl::SSLSocket;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $SSLAlgorithmConstraints$SupportedSignatureAlgorithmConstraints = ::sun::security::ssl::SSLAlgorithmConstraints$SupportedSignatureAlgorithmConstraints;
using $SSLAlgorithmDecomposer = ::sun::security::ssl::SSLAlgorithmDecomposer;
using $SSLEngineImpl = ::sun::security::ssl::SSLEngineImpl;
using $SSLSocketImpl = ::sun::security::ssl::SSLSocketImpl;
using $AlgorithmDecomposer = ::sun::security::util::AlgorithmDecomposer;
using $DisabledAlgorithmConstraints = ::sun::security::util::DisabledAlgorithmConstraints;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLAlgorithmConstraints_FieldInfo_[] = {
	{"tlsDisabledAlgConstraints", "Ljava/security/AlgorithmConstraints;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLAlgorithmConstraints, tlsDisabledAlgConstraints)},
	{"x509DisabledAlgConstraints", "Ljava/security/AlgorithmConstraints;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLAlgorithmConstraints, x509DisabledAlgConstraints)},
	{"userSpecifiedConstraints", "Ljava/security/AlgorithmConstraints;", nullptr, $PRIVATE | $FINAL, $field(SSLAlgorithmConstraints, userSpecifiedConstraints)},
	{"peerSpecifiedConstraints", "Ljava/security/AlgorithmConstraints;", nullptr, $PRIVATE | $FINAL, $field(SSLAlgorithmConstraints, peerSpecifiedConstraints)},
	{"enabledX509DisabledAlgConstraints", "Z", nullptr, $PRIVATE | $FINAL, $field(SSLAlgorithmConstraints, enabledX509DisabledAlgConstraints)},
	{"DEFAULT", "Ljava/security/AlgorithmConstraints;", nullptr, $STATIC | $FINAL, $staticField(SSLAlgorithmConstraints, DEFAULT)},
	{"DEFAULT_SSL_ONLY", "Ljava/security/AlgorithmConstraints;", nullptr, $STATIC | $FINAL, $staticField(SSLAlgorithmConstraints, DEFAULT_SSL_ONLY)},
	{}
};

$MethodInfo _SSLAlgorithmConstraints_MethodInfo_[] = {
	{"<init>", "(Ljava/security/AlgorithmConstraints;)V", nullptr, 0, $method(SSLAlgorithmConstraints, init$, void, $AlgorithmConstraints*)},
	{"<init>", "(Ljavax/net/ssl/SSLSocket;Z)V", nullptr, 0, $method(SSLAlgorithmConstraints, init$, void, $SSLSocket*, bool)},
	{"<init>", "(Ljavax/net/ssl/SSLEngine;Z)V", nullptr, 0, $method(SSLAlgorithmConstraints, init$, void, $SSLEngine*, bool)},
	{"<init>", "(Ljavax/net/ssl/SSLSocket;[Ljava/lang/String;Z)V", nullptr, 0, $method(SSLAlgorithmConstraints, init$, void, $SSLSocket*, $StringArray*, bool)},
	{"<init>", "(Ljavax/net/ssl/SSLEngine;[Ljava/lang/String;Z)V", nullptr, 0, $method(SSLAlgorithmConstraints, init$, void, $SSLEngine*, $StringArray*, bool)},
	{"getUserSpecifiedConstraints", "(Ljavax/net/ssl/SSLEngine;)Ljava/security/AlgorithmConstraints;", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLAlgorithmConstraints, getUserSpecifiedConstraints, $AlgorithmConstraints*, $SSLEngine*)},
	{"getUserSpecifiedConstraints", "(Ljavax/net/ssl/SSLSocket;)Ljava/security/AlgorithmConstraints;", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLAlgorithmConstraints, getUserSpecifiedConstraints, $AlgorithmConstraints*, $SSLSocket*)},
	{"permits", "(Ljava/util/Set;Ljava/lang/String;Ljava/security/AlgorithmParameters;)Z", "(Ljava/util/Set<Ljava/security/CryptoPrimitive;>;Ljava/lang/String;Ljava/security/AlgorithmParameters;)Z", $PUBLIC, $virtualMethod(SSLAlgorithmConstraints, permits, bool, $Set*, $String*, $AlgorithmParameters*)},
	{"permits", "(Ljava/util/Set;Ljava/security/Key;)Z", "(Ljava/util/Set<Ljava/security/CryptoPrimitive;>;Ljava/security/Key;)Z", $PUBLIC, $virtualMethod(SSLAlgorithmConstraints, permits, bool, $Set*, $Key*)},
	{"permits", "(Ljava/util/Set;Ljava/lang/String;Ljava/security/Key;Ljava/security/AlgorithmParameters;)Z", "(Ljava/util/Set<Ljava/security/CryptoPrimitive;>;Ljava/lang/String;Ljava/security/Key;Ljava/security/AlgorithmParameters;)Z", $PUBLIC, $virtualMethod(SSLAlgorithmConstraints, permits, bool, $Set*, $String*, $Key*, $AlgorithmParameters*)},
	{}
};

$InnerClassInfo _SSLAlgorithmConstraints_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLAlgorithmConstraints$SupportedSignatureAlgorithmConstraints", "sun.security.ssl.SSLAlgorithmConstraints", "SupportedSignatureAlgorithmConstraints", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SSLAlgorithmConstraints_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLAlgorithmConstraints",
	"java.lang.Object",
	"java.security.AlgorithmConstraints",
	_SSLAlgorithmConstraints_FieldInfo_,
	_SSLAlgorithmConstraints_MethodInfo_,
	nullptr,
	nullptr,
	_SSLAlgorithmConstraints_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLAlgorithmConstraints$SupportedSignatureAlgorithmConstraints"
};

$Object* allocate$SSLAlgorithmConstraints($Class* clazz) {
	return $of($alloc(SSLAlgorithmConstraints));
}

$AlgorithmConstraints* SSLAlgorithmConstraints::tlsDisabledAlgConstraints = nullptr;
$AlgorithmConstraints* SSLAlgorithmConstraints::x509DisabledAlgConstraints = nullptr;
$AlgorithmConstraints* SSLAlgorithmConstraints::DEFAULT = nullptr;
$AlgorithmConstraints* SSLAlgorithmConstraints::DEFAULT_SSL_ONLY = nullptr;

void SSLAlgorithmConstraints::init$($AlgorithmConstraints* userSpecifiedConstraints) {
	$set(this, userSpecifiedConstraints, userSpecifiedConstraints);
	$set(this, peerSpecifiedConstraints, nullptr);
	this->enabledX509DisabledAlgConstraints = true;
}

void SSLAlgorithmConstraints::init$($SSLSocket* socket, bool withDefaultCertPathConstraints) {
	$set(this, userSpecifiedConstraints, getUserSpecifiedConstraints(socket));
	$set(this, peerSpecifiedConstraints, nullptr);
	this->enabledX509DisabledAlgConstraints = withDefaultCertPathConstraints;
}

void SSLAlgorithmConstraints::init$($SSLEngine* engine, bool withDefaultCertPathConstraints) {
	$set(this, userSpecifiedConstraints, getUserSpecifiedConstraints(engine));
	$set(this, peerSpecifiedConstraints, nullptr);
	this->enabledX509DisabledAlgConstraints = withDefaultCertPathConstraints;
}

void SSLAlgorithmConstraints::init$($SSLSocket* socket, $StringArray* supportedAlgorithms, bool withDefaultCertPathConstraints) {
	$set(this, userSpecifiedConstraints, getUserSpecifiedConstraints(socket));
	$set(this, peerSpecifiedConstraints, $new($SSLAlgorithmConstraints$SupportedSignatureAlgorithmConstraints, supportedAlgorithms));
	this->enabledX509DisabledAlgConstraints = withDefaultCertPathConstraints;
}

void SSLAlgorithmConstraints::init$($SSLEngine* engine, $StringArray* supportedAlgorithms, bool withDefaultCertPathConstraints) {
	$set(this, userSpecifiedConstraints, getUserSpecifiedConstraints(engine));
	$set(this, peerSpecifiedConstraints, $new($SSLAlgorithmConstraints$SupportedSignatureAlgorithmConstraints, supportedAlgorithms));
	this->enabledX509DisabledAlgConstraints = withDefaultCertPathConstraints;
}

$AlgorithmConstraints* SSLAlgorithmConstraints::getUserSpecifiedConstraints($SSLEngine* engine) {
	$init(SSLAlgorithmConstraints);
	$useLocalCurrentObjectStackCache();
	if (engine != nullptr) {
		if ($instanceOf($SSLEngineImpl, engine)) {
			$var($HandshakeContext, hc, $nc($nc(($cast($SSLEngineImpl, engine)))->conContext)->handshakeContext);
			if (hc != nullptr) {
				return $nc(hc->sslConfig)->userSpecifiedAlgorithmConstraints;
			}
		}
		return $nc($(engine->getSSLParameters()))->getAlgorithmConstraints();
	}
	return nullptr;
}

$AlgorithmConstraints* SSLAlgorithmConstraints::getUserSpecifiedConstraints($SSLSocket* socket) {
	$init(SSLAlgorithmConstraints);
	$useLocalCurrentObjectStackCache();
	if (socket != nullptr) {
		if ($instanceOf($SSLSocketImpl, socket)) {
			$var($HandshakeContext, hc, $nc($nc(($cast($SSLSocketImpl, socket)))->conContext)->handshakeContext);
			if (hc != nullptr) {
				return $nc(hc->sslConfig)->userSpecifiedAlgorithmConstraints;
			}
		}
		return $nc($(socket->getSSLParameters()))->getAlgorithmConstraints();
	}
	return nullptr;
}

bool SSLAlgorithmConstraints::permits($Set* primitives, $String* algorithm, $AlgorithmParameters* parameters) {
	bool permitted = true;
	if (this->peerSpecifiedConstraints != nullptr) {
		permitted = $nc(this->peerSpecifiedConstraints)->permits(primitives, algorithm, parameters);
	}
	if (permitted && this->userSpecifiedConstraints != nullptr) {
		permitted = $nc(this->userSpecifiedConstraints)->permits(primitives, algorithm, parameters);
	}
	if (permitted) {
		permitted = $nc(SSLAlgorithmConstraints::tlsDisabledAlgConstraints)->permits(primitives, algorithm, parameters);
	}
	if (permitted && this->enabledX509DisabledAlgConstraints) {
		permitted = $nc(SSLAlgorithmConstraints::x509DisabledAlgConstraints)->permits(primitives, algorithm, parameters);
	}
	return permitted;
}

bool SSLAlgorithmConstraints::permits($Set* primitives, $Key* key) {
	bool permitted = true;
	if (this->peerSpecifiedConstraints != nullptr) {
		permitted = $nc(this->peerSpecifiedConstraints)->permits(primitives, key);
	}
	if (permitted && this->userSpecifiedConstraints != nullptr) {
		permitted = $nc(this->userSpecifiedConstraints)->permits(primitives, key);
	}
	if (permitted) {
		permitted = $nc(SSLAlgorithmConstraints::tlsDisabledAlgConstraints)->permits(primitives, key);
	}
	if (permitted && this->enabledX509DisabledAlgConstraints) {
		permitted = $nc(SSLAlgorithmConstraints::x509DisabledAlgConstraints)->permits(primitives, key);
	}
	return permitted;
}

bool SSLAlgorithmConstraints::permits($Set* primitives, $String* algorithm, $Key* key, $AlgorithmParameters* parameters) {
	bool permitted = true;
	if (this->peerSpecifiedConstraints != nullptr) {
		permitted = $nc(this->peerSpecifiedConstraints)->permits(primitives, algorithm, key, parameters);
	}
	if (permitted && this->userSpecifiedConstraints != nullptr) {
		permitted = $nc(this->userSpecifiedConstraints)->permits(primitives, algorithm, key, parameters);
	}
	if (permitted) {
		permitted = $nc(SSLAlgorithmConstraints::tlsDisabledAlgConstraints)->permits(primitives, algorithm, key, parameters);
	}
	if (permitted && this->enabledX509DisabledAlgConstraints) {
		permitted = $nc(SSLAlgorithmConstraints::x509DisabledAlgConstraints)->permits(primitives, algorithm, key, parameters);
	}
	return permitted;
}

void clinit$SSLAlgorithmConstraints($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(SSLAlgorithmConstraints::tlsDisabledAlgConstraints, $new($DisabledAlgorithmConstraints, "jdk.tls.disabledAlgorithms"_s, $$new($SSLAlgorithmDecomposer)));
	$assignStatic(SSLAlgorithmConstraints::x509DisabledAlgConstraints, $new($DisabledAlgorithmConstraints, "jdk.certpath.disabledAlgorithms"_s, $$new($SSLAlgorithmDecomposer, true)));
	$assignStatic(SSLAlgorithmConstraints::DEFAULT, $new(SSLAlgorithmConstraints, nullptr));
	$assignStatic(SSLAlgorithmConstraints::DEFAULT_SSL_ONLY, $new(SSLAlgorithmConstraints, ($SSLSocket*)nullptr, false));
}

SSLAlgorithmConstraints::SSLAlgorithmConstraints() {
}

$Class* SSLAlgorithmConstraints::load$($String* name, bool initialize) {
	$loadClass(SSLAlgorithmConstraints, name, initialize, &_SSLAlgorithmConstraints_ClassInfo_, clinit$SSLAlgorithmConstraints, allocate$SSLAlgorithmConstraints);
	return class$;
}

$Class* SSLAlgorithmConstraints::class$ = nullptr;

		} // ssl
	} // security
} // sun