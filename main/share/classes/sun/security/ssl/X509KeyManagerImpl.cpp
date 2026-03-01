#include <sun/security/ssl/X509KeyManagerImpl.h>

#include <java/lang/ref/Reference.h>
#include <java/lang/ref/SoftReference.h>
#include <java/net/Socket.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/KeyStore$Builder.h>
#include <java/security/KeyStore$Entry.h>
#include <java/security/KeyStore$PrivateKeyEntry.h>
#include <java/security/KeyStore$ProtectionParameter.h>
#include <java/security/KeyStore.h>
#include <java/security/Principal.h>
#include <java/security/PrivateKey.h>
#include <java/security/cert/CertPathValidatorException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <javax/net/ssl/ExtendedSSLSession.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLSession.h>
#include <javax/net/ssl/SSLSocket.h>
#include <javax/net/ssl/X509ExtendedKeyManager.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/provider/certpath/AlgorithmChecker.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLAlgorithmConstraints.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/X509KeyManagerImpl$CheckResult.h>
#include <sun/security/ssl/X509KeyManagerImpl$CheckType.h>
#include <sun/security/ssl/X509KeyManagerImpl$EntryStatus.h>
#include <sun/security/ssl/X509KeyManagerImpl$KeyType.h>
#include <sun/security/ssl/X509KeyManagerImpl$SizedMap.h>
#include <sun/security/ssl/X509TrustManagerImpl.h>
#include <jcpp.h>

#undef CLIENT
#undef OK
#undef SERVER

using $PrincipalArray = $Array<::java::security::Principal>;
using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Reference = ::java::lang::ref::Reference;
using $SoftReference = ::java::lang::ref::SoftReference;
using $Socket = ::java::net::Socket;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $KeyStore = ::java::security::KeyStore;
using $KeyStore$Builder = ::java::security::KeyStore$Builder;
using $KeyStore$Entry = ::java::security::KeyStore$Entry;
using $KeyStore$PrivateKeyEntry = ::java::security::KeyStore$PrivateKeyEntry;
using $PrivateKey = ::java::security::PrivateKey;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $Certificate = ::java::security::cert::Certificate;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $ExtendedSSLSession = ::javax::net::ssl::ExtendedSSLSession;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $SSLSocket = ::javax::net::ssl::SSLSocket;
using $X509ExtendedKeyManager = ::javax::net::ssl::X509ExtendedKeyManager;
using $AlgorithmChecker = ::sun::security::provider::certpath::AlgorithmChecker;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLAlgorithmConstraints = ::sun::security::ssl::SSLAlgorithmConstraints;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $X509KeyManagerImpl$CheckResult = ::sun::security::ssl::X509KeyManagerImpl$CheckResult;
using $X509KeyManagerImpl$CheckType = ::sun::security::ssl::X509KeyManagerImpl$CheckType;
using $X509KeyManagerImpl$EntryStatus = ::sun::security::ssl::X509KeyManagerImpl$EntryStatus;
using $X509KeyManagerImpl$KeyType = ::sun::security::ssl::X509KeyManagerImpl$KeyType;
using $X509KeyManagerImpl$SizedMap = ::sun::security::ssl::X509KeyManagerImpl$SizedMap;
using $X509TrustManagerImpl = ::sun::security::ssl::X509TrustManagerImpl;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _X509KeyManagerImpl_FieldInfo_[] = {
	{"verificationDate", "Ljava/util/Date;", nullptr, $PRIVATE | $STATIC, $staticField(X509KeyManagerImpl, verificationDate)},
	{"builders", "Ljava/util/List;", "Ljava/util/List<Ljava/security/KeyStore$Builder;>;", $PRIVATE | $FINAL, $field(X509KeyManagerImpl, builders)},
	{"uidCounter", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $FINAL, $field(X509KeyManagerImpl, uidCounter)},
	{"entryCacheMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/ref/Reference<Ljava/security/KeyStore$PrivateKeyEntry;>;>;", $PRIVATE | $FINAL, $field(X509KeyManagerImpl, entryCacheMap)},
	{}
};

$MethodInfo _X509KeyManagerImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/security/KeyStore$Builder;)V", nullptr, 0, $method(X509KeyManagerImpl, init$, void, $KeyStore$Builder*)},
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/security/KeyStore$Builder;>;)V", 0, $method(X509KeyManagerImpl, init$, void, $List*)},
	{"chooseAlias", "(Ljava/util/List;[Ljava/security/Principal;Lsun/security/ssl/X509KeyManagerImpl$CheckType;Ljava/security/AlgorithmConstraints;)Ljava/lang/String;", "(Ljava/util/List<Lsun/security/ssl/X509KeyManagerImpl$KeyType;>;[Ljava/security/Principal;Lsun/security/ssl/X509KeyManagerImpl$CheckType;Ljava/security/AlgorithmConstraints;)Ljava/lang/String;", $PRIVATE, $method(X509KeyManagerImpl, chooseAlias, $String*, $List*, $PrincipalArray*, $X509KeyManagerImpl$CheckType*, $AlgorithmConstraints*)},
	{"chooseAlias", "(Ljava/util/List;[Ljava/security/Principal;Lsun/security/ssl/X509KeyManagerImpl$CheckType;Ljava/security/AlgorithmConstraints;Ljava/util/List;Ljava/lang/String;)Ljava/lang/String;", "(Ljava/util/List<Lsun/security/ssl/X509KeyManagerImpl$KeyType;>;[Ljava/security/Principal;Lsun/security/ssl/X509KeyManagerImpl$CheckType;Ljava/security/AlgorithmConstraints;Ljava/util/List<Ljavax/net/ssl/SNIServerName;>;Ljava/lang/String;)Ljava/lang/String;", $PRIVATE, $method(X509KeyManagerImpl, chooseAlias, $String*, $List*, $PrincipalArray*, $X509KeyManagerImpl$CheckType*, $AlgorithmConstraints*, $List*, $String*)},
	{"chooseClientAlias", "([Ljava/lang/String;[Ljava/security/Principal;Ljava/net/Socket;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509KeyManagerImpl, chooseClientAlias, $String*, $StringArray*, $PrincipalArray*, $Socket*)},
	{"chooseEngineClientAlias", "([Ljava/lang/String;[Ljava/security/Principal;Ljavax/net/ssl/SSLEngine;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509KeyManagerImpl, chooseEngineClientAlias, $String*, $StringArray*, $PrincipalArray*, $SSLEngine*)},
	{"chooseEngineServerAlias", "(Ljava/lang/String;[Ljava/security/Principal;Ljavax/net/ssl/SSLEngine;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509KeyManagerImpl, chooseEngineServerAlias, $String*, $String*, $PrincipalArray*, $SSLEngine*)},
	{"chooseServerAlias", "(Ljava/lang/String;[Ljava/security/Principal;Ljava/net/Socket;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509KeyManagerImpl, chooseServerAlias, $String*, $String*, $PrincipalArray*, $Socket*)},
	{"conformsToAlgorithmConstraints", "(Ljava/security/AlgorithmConstraints;[Ljava/security/cert/Certificate;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(X509KeyManagerImpl, conformsToAlgorithmConstraints, bool, $AlgorithmConstraints*, $CertificateArray*, $String*)},
	{"getAlgorithmConstraints", "(Ljava/net/Socket;)Ljava/security/AlgorithmConstraints;", nullptr, $PRIVATE, $method(X509KeyManagerImpl, getAlgorithmConstraints, $AlgorithmConstraints*, $Socket*)},
	{"getAlgorithmConstraints", "(Ljavax/net/ssl/SSLEngine;)Ljava/security/AlgorithmConstraints;", nullptr, $PRIVATE, $method(X509KeyManagerImpl, getAlgorithmConstraints, $AlgorithmConstraints*, $SSLEngine*)},
	{"getAliases", "(Ljava/lang/String;[Ljava/security/Principal;Lsun/security/ssl/X509KeyManagerImpl$CheckType;Ljava/security/AlgorithmConstraints;)[Ljava/lang/String;", nullptr, $PUBLIC, $method(X509KeyManagerImpl, getAliases, $StringArray*, $String*, $PrincipalArray*, $X509KeyManagerImpl$CheckType*, $AlgorithmConstraints*)},
	{"getAliases", "(ILjava/util/List;Ljava/util/Set;ZLsun/security/ssl/X509KeyManagerImpl$CheckType;Ljava/security/AlgorithmConstraints;Ljava/util/List;Ljava/lang/String;)Ljava/util/List;", "(ILjava/util/List<Lsun/security/ssl/X509KeyManagerImpl$KeyType;>;Ljava/util/Set<Ljava/security/Principal;>;ZLsun/security/ssl/X509KeyManagerImpl$CheckType;Ljava/security/AlgorithmConstraints;Ljava/util/List<Ljavax/net/ssl/SNIServerName;>;Ljava/lang/String;)Ljava/util/List<Lsun/security/ssl/X509KeyManagerImpl$EntryStatus;>;", $PRIVATE, $method(X509KeyManagerImpl, getAliases, $List*, int32_t, $List*, $Set*, bool, $X509KeyManagerImpl$CheckType*, $AlgorithmConstraints*, $List*, $String*), "java.lang.Exception"},
	{"getCertificateChain", "(Ljava/lang/String;)[Ljava/security/cert/X509Certificate;", nullptr, $PUBLIC, $virtualMethod(X509KeyManagerImpl, getCertificateChain, $X509CertificateArray*, $String*)},
	{"getClientAliases", "(Ljava/lang/String;[Ljava/security/Principal;)[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509KeyManagerImpl, getClientAliases, $StringArray*, $String*, $PrincipalArray*)},
	{"getEntry", "(Ljava/lang/String;)Ljava/security/KeyStore$PrivateKeyEntry;", nullptr, $PRIVATE, $method(X509KeyManagerImpl, getEntry, $KeyStore$PrivateKeyEntry*, $String*)},
	{"getIssuerSet", "([Ljava/security/Principal;)Ljava/util/Set;", "([Ljava/security/Principal;)Ljava/util/Set<Ljava/security/Principal;>;", $PRIVATE, $method(X509KeyManagerImpl, getIssuerSet, $Set*, $PrincipalArray*)},
	{"getKeyTypes", "([Ljava/lang/String;)Ljava/util/List;", "([Ljava/lang/String;)Ljava/util/List<Lsun/security/ssl/X509KeyManagerImpl$KeyType;>;", $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(X509KeyManagerImpl, getKeyTypes, $List*, $StringArray*)},
	{"getPrivateKey", "(Ljava/lang/String;)Ljava/security/PrivateKey;", nullptr, $PUBLIC, $virtualMethod(X509KeyManagerImpl, getPrivateKey, $PrivateKey*, $String*)},
	{"getServerAliases", "(Ljava/lang/String;[Ljava/security/Principal;)[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509KeyManagerImpl, getServerAliases, $StringArray*, $String*, $PrincipalArray*)},
	{"makeAlias", "(Lsun/security/ssl/X509KeyManagerImpl$EntryStatus;)Ljava/lang/String;", nullptr, $PRIVATE, $method(X509KeyManagerImpl, makeAlias, $String*, $X509KeyManagerImpl$EntryStatus*)},
	{"toAliases", "(Ljava/util/List;)[Ljava/lang/String;", "(Ljava/util/List<Lsun/security/ssl/X509KeyManagerImpl$EntryStatus;>;)[Ljava/lang/String;", $PRIVATE, $method(X509KeyManagerImpl, toAliases, $StringArray*, $List*)},
	{}
};

$InnerClassInfo _X509KeyManagerImpl_InnerClassesInfo_[] = {
	{"sun.security.ssl.X509KeyManagerImpl$CheckResult", "sun.security.ssl.X509KeyManagerImpl", "CheckResult", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{"sun.security.ssl.X509KeyManagerImpl$CheckType", "sun.security.ssl.X509KeyManagerImpl", "CheckType", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{"sun.security.ssl.X509KeyManagerImpl$EntryStatus", "sun.security.ssl.X509KeyManagerImpl", "EntryStatus", $PRIVATE | $STATIC},
	{"sun.security.ssl.X509KeyManagerImpl$KeyType", "sun.security.ssl.X509KeyManagerImpl", "KeyType", $PRIVATE | $STATIC},
	{"sun.security.ssl.X509KeyManagerImpl$SizedMap", "sun.security.ssl.X509KeyManagerImpl", "SizedMap", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _X509KeyManagerImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.X509KeyManagerImpl",
	"javax.net.ssl.X509ExtendedKeyManager",
	nullptr,
	_X509KeyManagerImpl_FieldInfo_,
	_X509KeyManagerImpl_MethodInfo_,
	nullptr,
	nullptr,
	_X509KeyManagerImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.X509KeyManagerImpl$CheckResult,sun.security.ssl.X509KeyManagerImpl$CheckType,sun.security.ssl.X509KeyManagerImpl$EntryStatus,sun.security.ssl.X509KeyManagerImpl$KeyType,sun.security.ssl.X509KeyManagerImpl$SizedMap"
};

$Object* allocate$X509KeyManagerImpl($Class* clazz) {
	return $of($alloc(X509KeyManagerImpl));
}

$Date* X509KeyManagerImpl::verificationDate = nullptr;

void X509KeyManagerImpl::init$($KeyStore$Builder* builder) {
	X509KeyManagerImpl::init$($($Collections::singletonList(builder)));
}

void X509KeyManagerImpl::init$($List* builders) {
	$X509ExtendedKeyManager::init$();
	$set(this, builders, builders);
	$set(this, uidCounter, $new($AtomicLong));
	$set(this, entryCacheMap, $Collections::synchronizedMap($$new($X509KeyManagerImpl$SizedMap)));
}

$X509CertificateArray* X509KeyManagerImpl::getCertificateChain($String* alias) {
	$var($KeyStore$PrivateKeyEntry, entry, getEntry(alias));
	return entry == nullptr ? ($X509CertificateArray*)nullptr : $fcast($X509CertificateArray, $nc(entry)->getCertificateChain());
}

$PrivateKey* X509KeyManagerImpl::getPrivateKey($String* alias) {
	$var($KeyStore$PrivateKeyEntry, entry, getEntry(alias));
	return entry == nullptr ? ($PrivateKey*)nullptr : $nc(entry)->getPrivateKey();
}

$String* X509KeyManagerImpl::chooseClientAlias($StringArray* keyTypes, $PrincipalArray* issuers, $Socket* socket) {
	$useLocalCurrentObjectStackCache();
	$var($List, var$0, getKeyTypes(keyTypes));
	$var($PrincipalArray, var$1, issuers);
	$init($X509KeyManagerImpl$CheckType);
	$var($X509KeyManagerImpl$CheckType, var$2, $X509KeyManagerImpl$CheckType::CLIENT);
	return chooseAlias(var$0, var$1, var$2, $(getAlgorithmConstraints(socket)));
}

$String* X509KeyManagerImpl::chooseEngineClientAlias($StringArray* keyTypes, $PrincipalArray* issuers, $SSLEngine* engine) {
	$useLocalCurrentObjectStackCache();
	$var($List, var$0, getKeyTypes(keyTypes));
	$var($PrincipalArray, var$1, issuers);
	$init($X509KeyManagerImpl$CheckType);
	$var($X509KeyManagerImpl$CheckType, var$2, $X509KeyManagerImpl$CheckType::CLIENT);
	return chooseAlias(var$0, var$1, var$2, $(getAlgorithmConstraints(engine)));
}

$String* X509KeyManagerImpl::chooseServerAlias($String* keyType, $PrincipalArray* issuers, $Socket* socket) {
	$useLocalCurrentObjectStackCache();
	$var($List, var$0, getKeyTypes($$new($StringArray, {keyType})));
	$var($PrincipalArray, var$1, issuers);
	$init($X509KeyManagerImpl$CheckType);
	$var($X509KeyManagerImpl$CheckType, var$2, $X509KeyManagerImpl$CheckType::SERVER);
	$var($AlgorithmConstraints, var$3, getAlgorithmConstraints(socket));
	return chooseAlias(var$0, var$1, var$2, var$3, $($X509TrustManagerImpl::getRequestedServerNames(socket)), "HTTPS"_s);
}

$String* X509KeyManagerImpl::chooseEngineServerAlias($String* keyType, $PrincipalArray* issuers, $SSLEngine* engine) {
	$useLocalCurrentObjectStackCache();
	$var($List, var$0, getKeyTypes($$new($StringArray, {keyType})));
	$var($PrincipalArray, var$1, issuers);
	$init($X509KeyManagerImpl$CheckType);
	$var($X509KeyManagerImpl$CheckType, var$2, $X509KeyManagerImpl$CheckType::SERVER);
	$var($AlgorithmConstraints, var$3, getAlgorithmConstraints(engine));
	return chooseAlias(var$0, var$1, var$2, var$3, $($X509TrustManagerImpl::getRequestedServerNames(engine)), "HTTPS"_s);
}

$StringArray* X509KeyManagerImpl::getClientAliases($String* keyType, $PrincipalArray* issuers) {
	$init($X509KeyManagerImpl$CheckType);
	return getAliases(keyType, issuers, $X509KeyManagerImpl$CheckType::CLIENT, nullptr);
}

$StringArray* X509KeyManagerImpl::getServerAliases($String* keyType, $PrincipalArray* issuers) {
	$init($X509KeyManagerImpl$CheckType);
	return getAliases(keyType, issuers, $X509KeyManagerImpl$CheckType::SERVER, nullptr);
}

$AlgorithmConstraints* X509KeyManagerImpl::getAlgorithmConstraints($Socket* socket) {
	$useLocalCurrentObjectStackCache();
	if (socket != nullptr && socket->isConnected() && $instanceOf($SSLSocket, socket)) {
		$var($SSLSocket, sslSocket, $cast($SSLSocket, socket));
		$var($SSLSession, session, sslSocket->getHandshakeSession());
		if (session != nullptr) {
			if ($ProtocolVersion::useTLS12PlusSpec($(session->getProtocol()))) {
				$var($StringArray, peerSupportedSignAlgs, nullptr);
				if ($instanceOf($ExtendedSSLSession, session)) {
					$var($ExtendedSSLSession, extSession, $cast($ExtendedSSLSession, session));
					$assign(peerSupportedSignAlgs, extSession->getPeerSupportedSignatureAlgorithms());
				}
				return $new($SSLAlgorithmConstraints, sslSocket, peerSupportedSignAlgs, true);
			}
		}
		return $new($SSLAlgorithmConstraints, sslSocket, true);
	}
	return $new($SSLAlgorithmConstraints, ($SSLSocket*)nullptr, true);
}

$AlgorithmConstraints* X509KeyManagerImpl::getAlgorithmConstraints($SSLEngine* engine) {
	$useLocalCurrentObjectStackCache();
	if (engine != nullptr) {
		$var($SSLSession, session, engine->getHandshakeSession());
		if (session != nullptr) {
			if ($ProtocolVersion::useTLS12PlusSpec($(session->getProtocol()))) {
				$var($StringArray, peerSupportedSignAlgs, nullptr);
				if ($instanceOf($ExtendedSSLSession, session)) {
					$var($ExtendedSSLSession, extSession, $cast($ExtendedSSLSession, session));
					$assign(peerSupportedSignAlgs, extSession->getPeerSupportedSignatureAlgorithms());
				}
				return $new($SSLAlgorithmConstraints, engine, peerSupportedSignAlgs, true);
			}
		}
	}
	return $new($SSLAlgorithmConstraints, engine, true);
}

$String* X509KeyManagerImpl::makeAlias($X509KeyManagerImpl$EntryStatus* entry) {
	$useLocalCurrentObjectStackCache();
	return $str({$$str($nc(this->uidCounter)->incrementAndGet()), "."_s, $$str($nc(entry)->builderIndex), "."_s, entry->alias});
}

$KeyStore$PrivateKeyEntry* X509KeyManagerImpl::getEntry($String* alias) {
	$useLocalCurrentObjectStackCache();
	if (alias == nullptr) {
		return nullptr;
	}
	$var($Reference, ref, $cast($Reference, $nc(this->entryCacheMap)->get(alias)));
	$var($KeyStore$PrivateKeyEntry, entry, (ref != nullptr) ? $cast($KeyStore$PrivateKeyEntry, $nc(ref)->get()) : ($KeyStore$PrivateKeyEntry*)nullptr);
	if (entry != nullptr) {
		return entry;
	}
	int32_t firstDot = $nc(alias)->indexOf((int32_t)u'.');
	int32_t secondDot = alias->indexOf((int32_t)u'.', firstDot + 1);
	if ((firstDot == -1) || (secondDot == firstDot)) {
		return nullptr;
	}
	try {
		int32_t builderIndex = $Integer::parseInt($(alias->substring(firstDot + 1, secondDot)));
		$var($String, keyStoreAlias, alias->substring(secondDot + 1));
		$var($KeyStore$Builder, builder, $cast($KeyStore$Builder, $nc(this->builders)->get(builderIndex)));
		$var($KeyStore, ks, $nc(builder)->getKeyStore());
		$var($KeyStore$Entry, newEntry, $nc(ks)->getEntry(keyStoreAlias, $(builder->getProtectionParameter(keyStoreAlias))));
		if (!($instanceOf($KeyStore$PrivateKeyEntry, newEntry))) {
			return nullptr;
		}
		$assign(entry, $cast($KeyStore$PrivateKeyEntry, newEntry));
		$nc(this->entryCacheMap)->put(alias, $$new($SoftReference, entry));
		return entry;
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$List* X509KeyManagerImpl::getKeyTypes($StringArray* keyTypes) {
	$init(X509KeyManagerImpl);
	$useLocalCurrentObjectStackCache();
	if ((keyTypes == nullptr) || ($nc(keyTypes)->length == 0) || ($nc(keyTypes)->get(0) == nullptr)) {
		return nullptr;
	}
	$var($List, list, $new($ArrayList, $nc(keyTypes)->length));
	{
		$var($StringArray, arr$, keyTypes);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, keyType, arr$->get(i$));
			{
				list->add($$new($X509KeyManagerImpl$KeyType, keyType));
			}
		}
	}
	return list;
}

$String* X509KeyManagerImpl::chooseAlias($List* keyTypeList, $PrincipalArray* issuers, $X509KeyManagerImpl$CheckType* checkType, $AlgorithmConstraints* constraints) {
	return chooseAlias(keyTypeList, issuers, checkType, constraints, nullptr, nullptr);
}

$String* X509KeyManagerImpl::chooseAlias($List* keyTypeList, $PrincipalArray* issuers, $X509KeyManagerImpl$CheckType* checkType, $AlgorithmConstraints* constraints, $List* requestedServerNames, $String* idAlgorithm) {
	$useLocalCurrentObjectStackCache();
	if (keyTypeList == nullptr || $nc(keyTypeList)->isEmpty()) {
		return nullptr;
	}
	$var($Set, issuerSet, getIssuerSet(issuers));
	$var($List, allResults, nullptr);
	{
		int32_t i = 0;
		int32_t n = $nc(this->builders)->size();
		for (; i < n; ++i) {
			try {
				$var($List, results, getAliases(i, keyTypeList, issuerSet, false, checkType, constraints, requestedServerNames, idAlgorithm));
				if (results != nullptr) {
					$var($X509KeyManagerImpl$EntryStatus, status, $cast($X509KeyManagerImpl$EntryStatus, results->get(0)));
					$init($X509KeyManagerImpl$CheckResult);
					if ($nc(status)->checkResult == $X509KeyManagerImpl$CheckResult::OK) {
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
							$SSLLogger::fine($$str({"KeyMgr: choosing key: "_s, status}), $$new($ObjectArray, 0));
						}
						return makeAlias(status);
					}
					if (allResults == nullptr) {
						$assign(allResults, $new($ArrayList));
					}
					$nc(allResults)->addAll(results);
				}
			} catch ($Exception& e) {
			}
		}
	}
	if (allResults == nullptr) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
			$SSLLogger::fine("KeyMgr: no matching key found"_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	$Collections::sort(allResults);
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
		$SSLLogger::fine("KeyMgr: no good matching key found, returning best match out of"_s, $$new($ObjectArray, {$of(allResults)}));
	}
	return makeAlias($cast($X509KeyManagerImpl$EntryStatus, $($nc(allResults)->get(0))));
}

$StringArray* X509KeyManagerImpl::getAliases($String* keyType, $PrincipalArray* issuers, $X509KeyManagerImpl$CheckType* checkType, $AlgorithmConstraints* constraints) {
	$useLocalCurrentObjectStackCache();
	if (keyType == nullptr) {
		return nullptr;
	}
	$var($Set, issuerSet, getIssuerSet(issuers));
	$var($List, keyTypeList, getKeyTypes($$new($StringArray, {keyType})));
	$var($List, allResults, nullptr);
	{
		int32_t i = 0;
		int32_t n = $nc(this->builders)->size();
		for (; i < n; ++i) {
			try {
				$var($List, results, getAliases(i, keyTypeList, issuerSet, true, checkType, constraints, nullptr, nullptr));
				if (results != nullptr) {
					if (allResults == nullptr) {
						$assign(allResults, $new($ArrayList));
					}
					$nc(allResults)->addAll(results);
				}
			} catch ($Exception& e) {
			}
		}
	}
	if (allResults == nullptr || $nc(allResults)->isEmpty()) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
			$SSLLogger::fine("KeyMgr: no matching alias found"_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	$Collections::sort(allResults);
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
		$SSLLogger::fine("KeyMgr: getting aliases"_s, $$new($ObjectArray, {$of(allResults)}));
	}
	return toAliases(allResults);
}

$StringArray* X509KeyManagerImpl::toAliases($List* results) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, s, $new($StringArray, $nc(results)->size()));
	int32_t i = 0;
	{
		$var($Iterator, i$, results->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($X509KeyManagerImpl$EntryStatus, result, $cast($X509KeyManagerImpl$EntryStatus, i$->next()));
			{
				s->set(i++, $(makeAlias(result)));
			}
		}
	}
	return s;
}

$Set* X509KeyManagerImpl::getIssuerSet($PrincipalArray* issuers) {
	if ((issuers != nullptr) && (issuers->length != 0)) {
		return $new($HashSet, $(static_cast<$Collection*>($Arrays::asList(issuers))));
	} else {
		return nullptr;
	}
}

$List* X509KeyManagerImpl::getAliases(int32_t builderIndex, $List* keyTypes, $Set* issuerSet, bool findAll, $X509KeyManagerImpl$CheckType* checkType, $AlgorithmConstraints* constraints, $List* requestedServerNames, $String* idAlgorithm) {
	$useLocalCurrentObjectStackCache();
	$var($KeyStore$Builder, builder, $cast($KeyStore$Builder, $nc(this->builders)->get(builderIndex)));
	$var($KeyStore, ks, $nc(builder)->getKeyStore());
	$var($List, results, nullptr);
	$var($Date, date, X509KeyManagerImpl::verificationDate);
	bool preferred = false;
	{
		$var($Enumeration, e, $nc(ks)->aliases());
		for (; $nc(e)->hasMoreElements();) {
			$var($String, alias, $cast($String, e->nextElement()));
			if (!ks->isKeyEntry(alias)) {
				continue;
			}
			$var($CertificateArray, chain, ks->getCertificateChain(alias));
			if ((chain == nullptr) || ($nc(chain)->length == 0)) {
				continue;
			}
			bool incompatible = false;
			{
				$var($CertificateArray, arr$, chain);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($Certificate, cert, arr$->get(i$));
					{
						if (!($instanceOf($X509Certificate, cert))) {
							incompatible = true;
							break;
						}
					}
				}
			}
			if (incompatible) {
				continue;
			}
			int32_t keyIndex = -1;
			int32_t j = 0;
			{
				$var($Iterator, i$, $nc(keyTypes)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($X509KeyManagerImpl$KeyType, keyType, $cast($X509KeyManagerImpl$KeyType, i$->next()));
					{
						if ($nc(keyType)->matches(chain)) {
							keyIndex = j;
							break;
						}
						++j;
					}
				}
			}
			if (keyIndex == -1) {
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
					$SSLLogger::fine($$str({"Ignore alias "_s, alias, ": key algorithm does not match"_s}), $$new($ObjectArray, 0));
				}
				continue;
			}
			if (issuerSet != nullptr) {
				bool found = false;
				{
					$var($CertificateArray, arr$, chain);
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($Certificate, cert, arr$->get(i$));
						{
							$var($X509Certificate, xcert, $cast($X509Certificate, cert));
							if (issuerSet->contains($($nc(xcert)->getIssuerX500Principal()))) {
								found = true;
								break;
							}
						}
					}
				}
				if (!found) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
						$SSLLogger::fine($$str({"Ignore alias "_s, alias, ": issuers do not match"_s}), $$new($ObjectArray, 0));
					}
					continue;
				}
			}
			if (constraints != nullptr && !conformsToAlgorithmConstraints(constraints, chain, $($nc(checkType)->getValidator()))) {
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
					$SSLLogger::fine($$str({"Ignore alias "_s, alias, ": certificate list does not conform to algorithm constraints"_s}), $$new($ObjectArray, 0));
				}
				continue;
			}
			if (date == nullptr) {
				$assign(date, $new($Date));
			}
			$X509KeyManagerImpl$CheckResult* checkResult = $nc(checkType)->check($cast($X509Certificate, $nc(chain)->get(0)), date, requestedServerNames, idAlgorithm);
			$var($X509KeyManagerImpl$EntryStatus, status, $new($X509KeyManagerImpl$EntryStatus, builderIndex, keyIndex, alias, chain, checkResult));
			$init($X509KeyManagerImpl$CheckResult);
			if (!preferred && checkResult == $X509KeyManagerImpl$CheckResult::OK && keyIndex == 0) {
				preferred = true;
			}
			if (preferred && !findAll) {
				return $Collections::singletonList(status);
			} else {
				if (results == nullptr) {
					$assign(results, $new($ArrayList));
				}
				$nc(results)->add(status);
			}
		}
	}
	return results;
}

bool X509KeyManagerImpl::conformsToAlgorithmConstraints($AlgorithmConstraints* constraints, $CertificateArray* chain, $String* variant) {
	$init(X509KeyManagerImpl);
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmChecker, checker, $new($AlgorithmChecker, constraints, variant));
	try {
		checker->init(false);
	} catch ($CertPathValidatorException& cpve) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
			$SSLLogger::fine("Cannot initialize algorithm constraints checker"_s, $$new($ObjectArray, {$of(cpve)}));
		}
		return false;
	}
	for (int32_t i = $nc(chain)->length - 1; i >= 0; --i) {
		$var($Certificate, cert, chain->get(i));
		try {
			checker->check(cert, $($Collections::emptySet()));
		} catch ($CertPathValidatorException& cpve) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
				$SSLLogger::fine("Certificate does not conform to algorithm constraints"_s, $$new($ObjectArray, {
					$of(cert),
					$of(cpve)
				}));
			}
			return false;
		}
	}
	return true;
}

X509KeyManagerImpl::X509KeyManagerImpl() {
}

$Class* X509KeyManagerImpl::load$($String* name, bool initialize) {
	$loadClass(X509KeyManagerImpl, name, initialize, &_X509KeyManagerImpl_ClassInfo_, allocate$X509KeyManagerImpl);
	return class$;
}

$Class* X509KeyManagerImpl::class$ = nullptr;

		} // ssl
	} // security
} // sun