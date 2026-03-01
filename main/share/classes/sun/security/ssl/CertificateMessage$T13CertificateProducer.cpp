#include <sun/security/ssl/CertificateMessage$T13CertificateProducer.h>

#include <java/security/AlgorithmConstraints.h>
#include <java/security/PrivateKey.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CertificateMessage$CertificateEntry.h>
#include <sun/security/ssl/CertificateMessage$T13CertificateMessage.h>
#include <sun/security/ssl/CertificateMessage.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ClientHello$ClientHelloMessage.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLAuthentication.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLExtensions.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLPossession.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/SignatureScheme.h>
#include <sun/security/ssl/StatusResponseManager$StaplingParameters.h>
#include <sun/security/ssl/StatusResponseManager.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/X509Authentication$X509Possession.h>
#include <sun/security/ssl/X509Authentication.h>
#include <jcpp.h>

#undef CERTIFICATE
#undef HANDSHAKE_FAILURE
#undef PROTOCOLS_OF_13

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $SSLExtensionArray = $Array<::sun::security::ssl::SSLExtension>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CertificateException = ::java::security::cert::CertificateException;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractSet = ::java::util::AbstractSet;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $SSLException = ::javax::net::ssl::SSLException;
using $Alert = ::sun::security::ssl::Alert;
using $CertificateMessage$CertificateEntry = ::sun::security::ssl::CertificateMessage$CertificateEntry;
using $CertificateMessage$T13CertificateMessage = ::sun::security::ssl::CertificateMessage$T13CertificateMessage;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ClientHello$ClientHelloMessage = ::sun::security::ssl::ClientHello$ClientHelloMessage;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLAuthentication = ::sun::security::ssl::SSLAuthentication;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLExtensions = ::sun::security::ssl::SSLExtensions;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLPossession = ::sun::security::ssl::SSLPossession;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $SignatureScheme = ::sun::security::ssl::SignatureScheme;
using $StatusResponseManager = ::sun::security::ssl::StatusResponseManager;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $X509Authentication = ::sun::security::ssl::X509Authentication;
using $X509Authentication$X509Possession = ::sun::security::ssl::X509Authentication$X509Possession;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _CertificateMessage$T13CertificateProducer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(CertificateMessage$T13CertificateProducer, init$, void)},
	{"choosePossession", "(Lsun/security/ssl/HandshakeContext;Lsun/security/ssl/ClientHello$ClientHelloMessage;)Lsun/security/ssl/SSLPossession;", nullptr, $PRIVATE | $STATIC, $staticMethod(CertificateMessage$T13CertificateProducer, choosePossession, $SSLPossession*, $HandshakeContext*, $ClientHello$ClientHelloMessage*), "java.io.IOException"},
	{"onProduceCertificate", "(Lsun/security/ssl/ServerHandshakeContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PRIVATE, $method(CertificateMessage$T13CertificateProducer, onProduceCertificate, $bytes*, $ServerHandshakeContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{"onProduceCertificate", "(Lsun/security/ssl/ClientHandshakeContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PRIVATE, $method(CertificateMessage$T13CertificateProducer, onProduceCertificate, $bytes*, $ClientHandshakeContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{"produce", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PUBLIC, $virtualMethod(CertificateMessage$T13CertificateProducer, produce, $bytes*, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _CertificateMessage$T13CertificateProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertificateMessage$T13CertificateProducer", "sun.security.ssl.CertificateMessage", "T13CertificateProducer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _CertificateMessage$T13CertificateProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertificateMessage$T13CertificateProducer",
	"java.lang.Object",
	"sun.security.ssl.HandshakeProducer",
	nullptr,
	_CertificateMessage$T13CertificateProducer_MethodInfo_,
	nullptr,
	nullptr,
	_CertificateMessage$T13CertificateProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertificateMessage"
};

$Object* allocate$CertificateMessage$T13CertificateProducer($Class* clazz) {
	return $of($alloc(CertificateMessage$T13CertificateProducer));
}

void CertificateMessage$T13CertificateProducer::init$() {
}

$bytes* CertificateMessage$T13CertificateProducer::produce($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$var($HandshakeContext, hc, $cast($HandshakeContext, context));
	if ($nc($nc(hc)->sslConfig)->isClientMode) {
		return onProduceCertificate($cast($ClientHandshakeContext, context), message);
	} else {
		return onProduceCertificate($cast($ServerHandshakeContext, context), message);
	}
}

$bytes* CertificateMessage$T13CertificateProducer::onProduceCertificate($ServerHandshakeContext* shc, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($ClientHello$ClientHelloMessage, clientHello, $cast($ClientHello$ClientHelloMessage, message));
	$var($SSLPossession, pos, choosePossession(shc, clientHello));
	if (pos == nullptr) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "No available authentication scheme"_s)));
	}
	if (!($instanceOf($X509Authentication$X509Possession, pos))) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "No X.509 certificate for server authentication"_s)));
	}
	$var($X509Authentication$X509Possession, x509Possession, $cast($X509Authentication$X509Possession, pos));
	$var($X509CertificateArray, localCerts, $nc(x509Possession)->popCerts);
	if (localCerts == nullptr || $nc(localCerts)->length == 0) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "No X.509 certificate for server authentication"_s)));
	}
	$nc($nc(shc)->handshakePossessions)->add(x509Possession);
	$nc(shc->handshakeSession)->setLocalPrivateKey(x509Possession->popPrivateKey);
	$nc(shc->handshakeSession)->setLocalCertificates(localCerts);
	$var($CertificateMessage$T13CertificateMessage, cm, nullptr);
	try {
		$assign(cm, $new($CertificateMessage$T13CertificateMessage, static_cast<$HandshakeContext*>(shc), ($$new($bytes, 0)), localCerts));
	} catch ($SSLException& ce) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Failed to produce server Certificate message"_s, ce)));
	} catch ($CertificateException& ce) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Failed to produce server Certificate message"_s, ce)));
	}
	$set(shc, stapleParams, $StatusResponseManager::processStapling(shc));
	shc->staplingActive = (shc->stapleParams != nullptr);
	$init($SSLHandshake);
	$init($ProtocolVersion);
	$var($SSLExtensionArray, enabledCTExts, $nc(shc->sslConfig)->getEnabledExtensions($SSLHandshake::CERTIFICATE, $($Arrays::asList($ProtocolVersion::PROTOCOLS_OF_13))));
	{
		$var($Iterator, i$, $nc($nc(cm)->certEntries)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertificateMessage$CertificateEntry, certEnt, $cast($CertificateMessage$CertificateEntry, i$->next()));
			{
				$set(shc, currentCertEntry, certEnt);
				$nc($nc(certEnt)->extensions)->produce(shc, enabledCTExts);
			}
		}
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Produced server Certificate message"_s, $$new($ObjectArray, {$of(cm)}));
	}
	cm->write(shc->handshakeOutput);
	$nc(shc->handshakeOutput)->flush();
	return nullptr;
}

$SSLPossession* CertificateMessage$T13CertificateProducer::choosePossession($HandshakeContext* hc, $ClientHello$ClientHelloMessage* clientHello) {
	$init(CertificateMessage$T13CertificateProducer);
	$useLocalCurrentObjectStackCache();
	if ($nc(hc)->peerRequestedCertSignSchemes == nullptr || $nc($nc(hc)->peerRequestedCertSignSchemes)->isEmpty()) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::warning("No signature_algorithms(_cert) in ClientHello"_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	$var($Collection, checkedKeyTypes, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>($new($HashSet)))));
	{
		$var($Iterator, i$, $nc($nc(hc)->peerRequestedCertSignSchemes)->iterator());
		for (; $nc(i$)->hasNext();) {
			$SignatureScheme* ss = $cast($SignatureScheme, i$->next());
			{
				if (checkedKeyTypes->contains($nc(ss)->keyAlgorithm)) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::warning($$str({"Unsupported authentication scheme: "_s, $nc(ss)->name$}), $$new($ObjectArray, 0));
					}
					continue;
				}
				if ($SignatureScheme::getPreferableAlgorithm(hc->algorithmConstraints, hc->peerRequestedSignatureSchemes, ss, hc->negotiatedProtocol) == nullptr) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::warning($$str({"Unable to produce CertificateVerify for signature scheme: "_s, $nc(ss)->name$}), $$new($ObjectArray, 0));
					}
					checkedKeyTypes->add($nc(ss)->keyAlgorithm);
					continue;
				}
				$var($SSLAuthentication, ka, $X509Authentication::valueOf(ss));
				if (ka == nullptr) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::warning($$str({"Unsupported authentication scheme: "_s, $nc(ss)->name$}), $$new($ObjectArray, 0));
					}
					checkedKeyTypes->add($nc(ss)->keyAlgorithm);
					continue;
				}
				$var($SSLPossession, pos, $nc(ka)->createPossession(hc));
				if (pos == nullptr) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::warning($$str({"Unavailable authentication scheme: "_s, $nc(ss)->name$}), $$new($ObjectArray, 0));
					}
					continue;
				}
				return pos;
			}
		}
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::warning("No available authentication scheme"_s, $$new($ObjectArray, 0));
	}
	return nullptr;
}

$bytes* CertificateMessage$T13CertificateProducer::onProduceCertificate($ClientHandshakeContext* chc, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($ClientHello$ClientHelloMessage, clientHello, $cast($ClientHello$ClientHelloMessage, message));
	$var($SSLPossession, pos, choosePossession(chc, clientHello));
	$var($X509CertificateArray, localCerts, nullptr);
	if (pos == nullptr) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("No available client authentication scheme"_s, $$new($ObjectArray, 0));
		}
		$assign(localCerts, $new($X509CertificateArray, 0));
	} else {
		$nc($nc(chc)->handshakePossessions)->add(pos);
		if (!($instanceOf($X509Authentication$X509Possession, pos))) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
				$SSLLogger::fine("No X.509 certificate for client authentication"_s, $$new($ObjectArray, 0));
			}
			$assign(localCerts, $new($X509CertificateArray, 0));
		} else {
			$var($X509Authentication$X509Possession, x509Possession, $cast($X509Authentication$X509Possession, pos));
			$assign(localCerts, $nc(x509Possession)->popCerts);
			$nc(chc->handshakeSession)->setLocalPrivateKey(x509Possession->popPrivateKey);
		}
	}
	if (localCerts != nullptr && localCerts->length != 0) {
		$nc($nc(chc)->handshakeSession)->setLocalCertificates(localCerts);
	} else {
		$nc($nc(chc)->handshakeSession)->setLocalCertificates(nullptr);
	}
	$var($CertificateMessage$T13CertificateMessage, cm, nullptr);
	try {
		$assign(cm, $new($CertificateMessage$T13CertificateMessage, static_cast<$HandshakeContext*>(chc), $nc(chc)->certRequestContext, localCerts));
	} catch ($SSLException& ce) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Failed to produce client Certificate message"_s, ce)));
	} catch ($CertificateException& ce) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Failed to produce client Certificate message"_s, ce)));
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Produced client Certificate message"_s, $$new($ObjectArray, {$of(cm)}));
	}
	$nc(cm)->write($nc(chc)->handshakeOutput);
	$nc($nc(chc)->handshakeOutput)->flush();
	return nullptr;
}

CertificateMessage$T13CertificateProducer::CertificateMessage$T13CertificateProducer() {
}

$Class* CertificateMessage$T13CertificateProducer::load$($String* name, bool initialize) {
	$loadClass(CertificateMessage$T13CertificateProducer, name, initialize, &_CertificateMessage$T13CertificateProducer_ClassInfo_, allocate$CertificateMessage$T13CertificateProducer);
	return class$;
}

$Class* CertificateMessage$T13CertificateProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun