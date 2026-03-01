#include <sun/security/ssl/PreSharedKeyExtension.h>

#include <java/lang/CharSequence.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Principal.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <javax/crypto/Mac.h>
#include <javax/crypto/SecretKey.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLPeerUnverifiedException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientAuthType.h>
#include <sun/security/ssl/ClientHello$ClientHelloMessage.h>
#include <sun/security/ssl/HKDF.h>
#include <sun/security/ssl/HandshakeAbsence.h>
#include <sun/security/ssl/HandshakeConsumer.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/HandshakeProducer.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/PreSharedKeyExtension$CHPreSharedKeyConsumer.h>
#include <sun/security/ssl/PreSharedKeyExtension$CHPreSharedKeyOnLoadAbsence.h>
#include <sun/security/ssl/PreSharedKeyExtension$CHPreSharedKeyOnTradeAbsence.h>
#include <sun/security/ssl/PreSharedKeyExtension$CHPreSharedKeyProducer.h>
#include <sun/security/ssl/PreSharedKeyExtension$CHPreSharedKeySpec.h>
#include <sun/security/ssl/PreSharedKeyExtension$CHPreSharedKeyStringizer.h>
#include <sun/security/ssl/PreSharedKeyExtension$CHPreSharedKeyUpdate.h>
#include <sun/security/ssl/PreSharedKeyExtension$PartialClientHelloMessage.h>
#include <sun/security/ssl/PreSharedKeyExtension$SHPreSharedKeyAbsence.h>
#include <sun/security/ssl/PreSharedKeyExtension$SHPreSharedKeyConsumer.h>
#include <sun/security/ssl/PreSharedKeyExtension$SHPreSharedKeyProducer.h>
#include <sun/security/ssl/PreSharedKeyExtension$SHPreSharedKeyStringizer.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLEngineOutputRecord.h>
#include <sun/security/ssl/SSLExtension$ExtensionConsumer.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSecretDerivation.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLStringizer.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/SignatureScheme.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef CLIENT_AUTH_REQUIRED
#undef ILLEGAL_PARAMETER
#undef INTERNAL_ERROR

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $Mac = ::javax::crypto::Mac;
using $SecretKey = ::javax::crypto::SecretKey;
using $SSLPeerUnverifiedException = ::javax::net::ssl::SSLPeerUnverifiedException;
using $Alert = ::sun::security::ssl::Alert;
using $CipherSuite$HashAlg = ::sun::security::ssl::CipherSuite$HashAlg;
using $ClientAuthType = ::sun::security::ssl::ClientAuthType;
using $ClientHello$ClientHelloMessage = ::sun::security::ssl::ClientHello$ClientHelloMessage;
using $HKDF = ::sun::security::ssl::HKDF;
using $HandshakeAbsence = ::sun::security::ssl::HandshakeAbsence;
using $HandshakeConsumer = ::sun::security::ssl::HandshakeConsumer;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $HandshakeProducer = ::sun::security::ssl::HandshakeProducer;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $PreSharedKeyExtension$CHPreSharedKeyConsumer = ::sun::security::ssl::PreSharedKeyExtension$CHPreSharedKeyConsumer;
using $PreSharedKeyExtension$CHPreSharedKeyOnLoadAbsence = ::sun::security::ssl::PreSharedKeyExtension$CHPreSharedKeyOnLoadAbsence;
using $PreSharedKeyExtension$CHPreSharedKeyOnTradeAbsence = ::sun::security::ssl::PreSharedKeyExtension$CHPreSharedKeyOnTradeAbsence;
using $PreSharedKeyExtension$CHPreSharedKeyProducer = ::sun::security::ssl::PreSharedKeyExtension$CHPreSharedKeyProducer;
using $PreSharedKeyExtension$CHPreSharedKeySpec = ::sun::security::ssl::PreSharedKeyExtension$CHPreSharedKeySpec;
using $PreSharedKeyExtension$CHPreSharedKeyStringizer = ::sun::security::ssl::PreSharedKeyExtension$CHPreSharedKeyStringizer;
using $PreSharedKeyExtension$CHPreSharedKeyUpdate = ::sun::security::ssl::PreSharedKeyExtension$CHPreSharedKeyUpdate;
using $PreSharedKeyExtension$PartialClientHelloMessage = ::sun::security::ssl::PreSharedKeyExtension$PartialClientHelloMessage;
using $PreSharedKeyExtension$SHPreSharedKeyAbsence = ::sun::security::ssl::PreSharedKeyExtension$SHPreSharedKeyAbsence;
using $PreSharedKeyExtension$SHPreSharedKeyConsumer = ::sun::security::ssl::PreSharedKeyExtension$SHPreSharedKeyConsumer;
using $PreSharedKeyExtension$SHPreSharedKeyProducer = ::sun::security::ssl::PreSharedKeyExtension$SHPreSharedKeyProducer;
using $PreSharedKeyExtension$SHPreSharedKeyStringizer = ::sun::security::ssl::PreSharedKeyExtension$SHPreSharedKeyStringizer;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLEngineOutputRecord = ::sun::security::ssl::SSLEngineOutputRecord;
using $SSLExtension$ExtensionConsumer = ::sun::security::ssl::SSLExtension$ExtensionConsumer;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSecretDerivation = ::sun::security::ssl::SSLSecretDerivation;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SSLStringizer = ::sun::security::ssl::SSLStringizer;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $SignatureScheme = ::sun::security::ssl::SignatureScheme;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _PreSharedKeyExtension_FieldInfo_[] = {
	{"chNetworkProducer", "Lsun/security/ssl/HandshakeProducer;", nullptr, $STATIC | $FINAL, $staticField(PreSharedKeyExtension, chNetworkProducer)},
	{"chOnLoadConsumer", "Lsun/security/ssl/SSLExtension$ExtensionConsumer;", nullptr, $STATIC | $FINAL, $staticField(PreSharedKeyExtension, chOnLoadConsumer)},
	{"chOnLoadAbsence", "Lsun/security/ssl/HandshakeAbsence;", nullptr, $STATIC | $FINAL, $staticField(PreSharedKeyExtension, chOnLoadAbsence)},
	{"chOnTradeConsumer", "Lsun/security/ssl/HandshakeConsumer;", nullptr, $STATIC | $FINAL, $staticField(PreSharedKeyExtension, chOnTradeConsumer)},
	{"chOnTradAbsence", "Lsun/security/ssl/HandshakeAbsence;", nullptr, $STATIC | $FINAL, $staticField(PreSharedKeyExtension, chOnTradAbsence)},
	{"chStringizer", "Lsun/security/ssl/SSLStringizer;", nullptr, $STATIC | $FINAL, $staticField(PreSharedKeyExtension, chStringizer)},
	{"shNetworkProducer", "Lsun/security/ssl/HandshakeProducer;", nullptr, $STATIC | $FINAL, $staticField(PreSharedKeyExtension, shNetworkProducer)},
	{"shOnLoadConsumer", "Lsun/security/ssl/SSLExtension$ExtensionConsumer;", nullptr, $STATIC | $FINAL, $staticField(PreSharedKeyExtension, shOnLoadConsumer)},
	{"shOnLoadAbsence", "Lsun/security/ssl/HandshakeAbsence;", nullptr, $STATIC | $FINAL, $staticField(PreSharedKeyExtension, shOnLoadAbsence)},
	{"shStringizer", "Lsun/security/ssl/SSLStringizer;", nullptr, $STATIC | $FINAL, $staticField(PreSharedKeyExtension, shStringizer)},
	{}
};

$MethodInfo _PreSharedKeyExtension_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(PreSharedKeyExtension, init$, void)},
	{"canRejoin", "(Lsun/security/ssl/ClientHello$ClientHelloMessage;Lsun/security/ssl/ServerHandshakeContext;Lsun/security/ssl/SSLSessionImpl;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(PreSharedKeyExtension, canRejoin, bool, $ClientHello$ClientHelloMessage*, $ServerHandshakeContext*, $SSLSessionImpl*)},
	{"checkBinder", "(Lsun/security/ssl/ServerHandshakeContext;Lsun/security/ssl/SSLSessionImpl;Lsun/security/ssl/HandshakeHash;[B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(PreSharedKeyExtension, checkBinder, void, $ServerHandshakeContext*, $SSLSessionImpl*, $HandshakeHash*, $bytes*), "java.io.IOException"},
	{"computeBinder", "(Lsun/security/ssl/HandshakeContext;Ljavax/crypto/SecretKey;Lsun/security/ssl/SSLSessionImpl;Lsun/security/ssl/HandshakeHash;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(PreSharedKeyExtension, computeBinder, $bytes*, $HandshakeContext*, $SecretKey*, $SSLSessionImpl*, $HandshakeHash*), "java.io.IOException"},
	{"computeBinder", "(Lsun/security/ssl/HandshakeContext;Ljavax/crypto/SecretKey;Lsun/security/ssl/HandshakeHash;Lsun/security/ssl/SSLSessionImpl;Lsun/security/ssl/HandshakeContext;Lsun/security/ssl/ClientHello$ClientHelloMessage;Lsun/security/ssl/PreSharedKeyExtension$CHPreSharedKeySpec;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(PreSharedKeyExtension, computeBinder, $bytes*, $HandshakeContext*, $SecretKey*, $HandshakeHash*, $SSLSessionImpl*, $HandshakeContext*, $ClientHello$ClientHelloMessage*, $PreSharedKeyExtension$CHPreSharedKeySpec*), "java.io.IOException"},
	{"computeBinder", "(Lsun/security/ssl/HandshakeContext;Ljavax/crypto/SecretKey;Lsun/security/ssl/SSLSessionImpl;[B)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(PreSharedKeyExtension, computeBinder, $bytes*, $HandshakeContext*, $SecretKey*, $SSLSessionImpl*, $bytes*), "java.io.IOException"},
	{"deriveBinderKey", "(Lsun/security/ssl/HandshakeContext;Ljavax/crypto/SecretKey;Lsun/security/ssl/SSLSessionImpl;)Ljavax/crypto/SecretKey;", nullptr, $PRIVATE | $STATIC, $staticMethod(PreSharedKeyExtension, deriveBinderKey, $SecretKey*, $HandshakeContext*, $SecretKey*, $SSLSessionImpl*), "java.io.IOException"},
	{}
};

$InnerClassInfo _PreSharedKeyExtension_InnerClassesInfo_[] = {
	{"sun.security.ssl.PreSharedKeyExtension$SHPreSharedKeyProducer", "sun.security.ssl.PreSharedKeyExtension", "SHPreSharedKeyProducer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$SHPreSharedKeyAbsence", "sun.security.ssl.PreSharedKeyExtension", "SHPreSharedKeyAbsence", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$SHPreSharedKeyConsumer", "sun.security.ssl.PreSharedKeyExtension", "SHPreSharedKeyConsumer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyOnTradeAbsence", "sun.security.ssl.PreSharedKeyExtension", "CHPreSharedKeyOnTradeAbsence", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyOnLoadAbsence", "sun.security.ssl.PreSharedKeyExtension", "CHPreSharedKeyOnLoadAbsence", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyProducer", "sun.security.ssl.PreSharedKeyExtension", "CHPreSharedKeyProducer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$PartialClientHelloMessage", "sun.security.ssl.PreSharedKeyExtension", "PartialClientHelloMessage", $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyUpdate", "sun.security.ssl.PreSharedKeyExtension", "CHPreSharedKeyUpdate", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyConsumer", "sun.security.ssl.PreSharedKeyExtension", "CHPreSharedKeyConsumer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$SHPreSharedKeyStringizer", "sun.security.ssl.PreSharedKeyExtension", "SHPreSharedKeyStringizer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$SHPreSharedKeySpec", "sun.security.ssl.PreSharedKeyExtension", "SHPreSharedKeySpec", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyStringizer", "sun.security.ssl.PreSharedKeyExtension", "CHPreSharedKeyStringizer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeySpec", "sun.security.ssl.PreSharedKeyExtension", "CHPreSharedKeySpec", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.PreSharedKeyExtension$PskIdentity", "sun.security.ssl.PreSharedKeyExtension", "PskIdentity", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _PreSharedKeyExtension_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.PreSharedKeyExtension",
	"java.lang.Object",
	nullptr,
	_PreSharedKeyExtension_FieldInfo_,
	_PreSharedKeyExtension_MethodInfo_,
	nullptr,
	nullptr,
	_PreSharedKeyExtension_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.PreSharedKeyExtension$SHPreSharedKeyProducer,sun.security.ssl.PreSharedKeyExtension$SHPreSharedKeyAbsence,sun.security.ssl.PreSharedKeyExtension$SHPreSharedKeyConsumer,sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyOnTradeAbsence,sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyOnLoadAbsence,sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyProducer,sun.security.ssl.PreSharedKeyExtension$PartialClientHelloMessage,sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyUpdate,sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyConsumer,sun.security.ssl.PreSharedKeyExtension$SHPreSharedKeyStringizer,sun.security.ssl.PreSharedKeyExtension$SHPreSharedKeySpec,sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeyStringizer,sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeySpec,sun.security.ssl.PreSharedKeyExtension$PskIdentity"
};

$Object* allocate$PreSharedKeyExtension($Class* clazz) {
	return $of($alloc(PreSharedKeyExtension));
}

$HandshakeProducer* PreSharedKeyExtension::chNetworkProducer = nullptr;
$SSLExtension$ExtensionConsumer* PreSharedKeyExtension::chOnLoadConsumer = nullptr;
$HandshakeAbsence* PreSharedKeyExtension::chOnLoadAbsence = nullptr;
$HandshakeConsumer* PreSharedKeyExtension::chOnTradeConsumer = nullptr;
$HandshakeAbsence* PreSharedKeyExtension::chOnTradAbsence = nullptr;
$SSLStringizer* PreSharedKeyExtension::chStringizer = nullptr;
$HandshakeProducer* PreSharedKeyExtension::shNetworkProducer = nullptr;
$SSLExtension$ExtensionConsumer* PreSharedKeyExtension::shOnLoadConsumer = nullptr;
$HandshakeAbsence* PreSharedKeyExtension::shOnLoadAbsence = nullptr;
$SSLStringizer* PreSharedKeyExtension::shStringizer = nullptr;

void PreSharedKeyExtension::init$() {
}

bool PreSharedKeyExtension::canRejoin($ClientHello$ClientHelloMessage* clientHello, $ServerHandshakeContext* shc, $SSLSessionImpl* s) {
	$init(PreSharedKeyExtension);
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(s)->isRejoinable();
	bool result = var$0 && (s->getPreSharedKey() != nullptr);
	if (result && s->getProtocolVersion() != $nc(shc)->negotiatedProtocol) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
			$SSLLogger::finest("Can\'t resume, incorrect protocol version"_s, $$new($ObjectArray, 0));
		}
		result = false;
	}
	if ($nc(shc)->localSupportedSignAlgs == nullptr) {
		$set(shc, localSupportedSignAlgs, $SignatureScheme::getSupportedAlgorithms(shc->sslConfig, shc->algorithmConstraints, shc->activeProtocols));
	}
	$init($ClientAuthType);
	if (result && ($nc($nc(shc)->sslConfig)->clientAuthType == $ClientAuthType::CLIENT_AUTH_REQUIRED)) {
		try {
			s->getPeerPrincipal();
		} catch ($SSLPeerUnverifiedException& e) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
				$SSLLogger::finest("Can\'t resume, client authentication is required"_s, $$new($ObjectArray, 0));
			}
			result = false;
		}
		$var($Collection, sessionSigAlgs, s->getLocalSupportedSignatureSchemes());
		if (result && !$nc(shc->localSupportedSignAlgs)->containsAll(sessionSigAlgs)) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
				$SSLLogger::fine("Can\'t resume. Session uses different signature algorithms"_s, $$new($ObjectArray, 0));
			}
			result = false;
		}
	}
	$var($String, identityAlg, $nc($nc(shc)->sslConfig)->identificationProtocol);
	if (result && identityAlg != nullptr) {
		$var($String, sessionIdentityAlg, s->getIdentificationProtocol());
		if (!identityAlg->equalsIgnoreCase(sessionIdentityAlg)) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
				$SSLLogger::finest($$str({"Can\'t resume, endpoint id algorithm does not match, requested: "_s, identityAlg, ", cached: "_s, sessionIdentityAlg}), $$new($ObjectArray, 0));
			}
			result = false;
		}
	}
	bool var$1 = result;
	if (var$1) {
		bool var$2 = !shc->isNegotiable($(s->getSuite()));
		var$1 = (var$2 || !$nc($nc(clientHello)->cipherSuites)->contains($(s->getSuite())));
	}
	if (var$1) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
			$SSLLogger::finest("Can\'t resume, unavailable session cipher suite"_s, $$new($ObjectArray, 0));
		}
		result = false;
	}
	return result;
}

void PreSharedKeyExtension::checkBinder($ServerHandshakeContext* shc, $SSLSessionImpl* session, $HandshakeHash* pskBinderHash, $bytes* binder) {
	$init(PreSharedKeyExtension);
	$useLocalCurrentObjectStackCache();
	$var($SecretKey, psk, $nc(session)->getPreSharedKey());
	if (psk == nullptr) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::INTERNAL_ERROR, "Session has no PSK"_s)));
	}
	$var($SecretKey, binderKey, deriveBinderKey(shc, psk, session));
	$var($bytes, computedBinder, computeBinder(static_cast<$HandshakeContext*>(shc), binderKey, session, pskBinderHash));
	if (!$Arrays::equals(binder, computedBinder)) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Incorect PSK binder value"_s)));
	}
}

$bytes* PreSharedKeyExtension::computeBinder($HandshakeContext* context, $SecretKey* binderKey, $SSLSessionImpl* session, $HandshakeHash* pskBinderHash) {
	$init(PreSharedKeyExtension);
	$useLocalCurrentObjectStackCache();
	$var($ProtocolVersion, var$0, $nc(session)->getProtocolVersion());
	$nc(pskBinderHash)->determine(var$0, $(session->getSuite()));
	pskBinderHash->update();
	$var($bytes, digest, pskBinderHash->digest());
	return computeBinder(context, binderKey, session, digest);
}

$bytes* PreSharedKeyExtension::computeBinder($HandshakeContext* context, $SecretKey* binderKey, $HandshakeHash* hash, $SSLSessionImpl* session, $HandshakeContext* ctx, $ClientHello$ClientHelloMessage* hello, $PreSharedKeyExtension$CHPreSharedKeySpec* pskPrototype) {
	$init(PreSharedKeyExtension);
	$useLocalCurrentObjectStackCache();
	$var($PreSharedKeyExtension$PartialClientHelloMessage, partialMsg, $new($PreSharedKeyExtension$PartialClientHelloMessage, ctx, hello, pskPrototype));
	$var($SSLEngineOutputRecord, record, $new($SSLEngineOutputRecord, hash));
	$var($HandshakeOutStream, hos, $new($HandshakeOutStream, record));
	partialMsg->write(hos);
	$var($ProtocolVersion, var$0, $nc(session)->getProtocolVersion());
	$nc(hash)->determine(var$0, $(session->getSuite()));
	hash->update();
	$var($bytes, digest, hash->digest());
	return computeBinder(context, binderKey, session, digest);
}

$bytes* PreSharedKeyExtension::computeBinder($HandshakeContext* context, $SecretKey* binderKey, $SSLSessionImpl* session, $bytes* digest) {
	$init(PreSharedKeyExtension);
	$useLocalCurrentObjectStackCache();
	try {
		$CipherSuite$HashAlg* hashAlg = $nc($($nc(session)->getSuite()))->hashAlg;
		$var($HKDF, hkdf, $new($HKDF, $nc(hashAlg)->name$));
		$var($bytes, label, ("tls13 finished"_s)->getBytes());
		$var($bytes, hkdfInfo, $SSLSecretDerivation::createHkdfInfo(label, $$new($bytes, 0), $nc(hashAlg)->hashLength));
		$var($SecretKey, finishedKey, hkdf->expand(binderKey, hkdfInfo, $nc(hashAlg)->hashLength, "TlsBinderKey"_s));
		$var($String, hmacAlg, $str({"Hmac"_s, $($nc($nc(hashAlg)->name$)->replace(static_cast<$CharSequence*>("-"_s), static_cast<$CharSequence*>(""_s)))}));
		try {
			$var($Mac, hmac, $Mac::getInstance(hmacAlg));
			$nc(hmac)->init(finishedKey);
			return hmac->doFinal(digest);
		} catch ($NoSuchAlgorithmException& ex) {
			$init($Alert);
			$throw($($nc($nc(context)->conContext)->fatal($Alert::INTERNAL_ERROR, static_cast<$Throwable*>(ex))));
		} catch ($InvalidKeyException& ex) {
			$init($Alert);
			$throw($($nc($nc(context)->conContext)->fatal($Alert::INTERNAL_ERROR, static_cast<$Throwable*>(ex))));
		}
	} catch ($GeneralSecurityException& ex) {
		$init($Alert);
		$throw($($nc($nc(context)->conContext)->fatal($Alert::INTERNAL_ERROR, static_cast<$Throwable*>(ex))));
	}
	$shouldNotReachHere();
}

$SecretKey* PreSharedKeyExtension::deriveBinderKey($HandshakeContext* context, $SecretKey* psk, $SSLSessionImpl* session) {
	$init(PreSharedKeyExtension);
	$useLocalCurrentObjectStackCache();
	try {
		$CipherSuite$HashAlg* hashAlg = $nc($($nc(session)->getSuite()))->hashAlg;
		$var($HKDF, hkdf, $new($HKDF, $nc(hashAlg)->name$));
		$var($bytes, zeros, $new($bytes, $nc(hashAlg)->hashLength));
		$var($SecretKey, earlySecret, hkdf->extract(zeros, psk, "TlsEarlySecret"_s));
		$var($bytes, label, ("tls13 res binder"_s)->getBytes());
		$var($MessageDigest, md, $MessageDigest::getInstance(hashAlg->name$));
		$var($bytes, hkdfInfo, $SSLSecretDerivation::createHkdfInfo(label, $($nc(md)->digest($$new($bytes, 0))), hashAlg->hashLength));
		return hkdf->expand(earlySecret, hkdfInfo, hashAlg->hashLength, "TlsBinderKey"_s);
	} catch ($GeneralSecurityException& ex) {
		$init($Alert);
		$throw($($nc($nc(context)->conContext)->fatal($Alert::INTERNAL_ERROR, static_cast<$Throwable*>(ex))));
	}
	$shouldNotReachHere();
}

void clinit$PreSharedKeyExtension($Class* class$) {
	$assignStatic(PreSharedKeyExtension::chNetworkProducer, $new($PreSharedKeyExtension$CHPreSharedKeyProducer));
	$assignStatic(PreSharedKeyExtension::chOnLoadConsumer, $new($PreSharedKeyExtension$CHPreSharedKeyConsumer));
	$assignStatic(PreSharedKeyExtension::chOnLoadAbsence, $new($PreSharedKeyExtension$CHPreSharedKeyOnLoadAbsence));
	$assignStatic(PreSharedKeyExtension::chOnTradeConsumer, $new($PreSharedKeyExtension$CHPreSharedKeyUpdate));
	$assignStatic(PreSharedKeyExtension::chOnTradAbsence, $new($PreSharedKeyExtension$CHPreSharedKeyOnTradeAbsence));
	$assignStatic(PreSharedKeyExtension::chStringizer, $new($PreSharedKeyExtension$CHPreSharedKeyStringizer));
	$assignStatic(PreSharedKeyExtension::shNetworkProducer, $new($PreSharedKeyExtension$SHPreSharedKeyProducer));
	$assignStatic(PreSharedKeyExtension::shOnLoadConsumer, $new($PreSharedKeyExtension$SHPreSharedKeyConsumer));
	$assignStatic(PreSharedKeyExtension::shOnLoadAbsence, $new($PreSharedKeyExtension$SHPreSharedKeyAbsence));
	$assignStatic(PreSharedKeyExtension::shStringizer, $new($PreSharedKeyExtension$SHPreSharedKeyStringizer));
}

PreSharedKeyExtension::PreSharedKeyExtension() {
}

$Class* PreSharedKeyExtension::load$($String* name, bool initialize) {
	$loadClass(PreSharedKeyExtension, name, initialize, &_PreSharedKeyExtension_ClassInfo_, clinit$PreSharedKeyExtension, allocate$PreSharedKeyExtension);
	return class$;
}

$Class* PreSharedKeyExtension::class$ = nullptr;

		} // ssl
	} // security
} // sun