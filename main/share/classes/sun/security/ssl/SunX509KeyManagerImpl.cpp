#include <sun/security/ssl/SunX509KeyManagerImpl.h>

#include <java/lang/CharSequence.h>
#include <java/net/Socket.h>
#include <java/security/Key.h>
#include <java/security/KeyStore.h>
#include <java/security/Principal.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/X509ExtendedKeyManager.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SunX509KeyManagerImpl$X509Credentials.h>
#include <jcpp.h>

#undef ENGLISH
#undef STRING0

using $PrincipalArray = $Array<::java::security::Principal>;
using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $X500PrincipalArray = $Array<::javax::security::auth::x500::X500Principal>;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Socket = ::java::net::Socket;
using $Key = ::java::security::Key;
using $KeyStore = ::java::security::KeyStore;
using $Principal = ::java::security::Principal;
using $PrivateKey = ::java::security::PrivateKey;
using $PublicKey = ::java::security::PublicKey;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $X509ExtendedKeyManager = ::javax::net::ssl::X509ExtendedKeyManager;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SunX509KeyManagerImpl$X509Credentials = ::sun::security::ssl::SunX509KeyManagerImpl$X509Credentials;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SunX509KeyManagerImpl_FieldInfo_[] = {
	{"STRING0", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SunX509KeyManagerImpl, STRING0)},
	{"credentialsMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Lsun/security/ssl/SunX509KeyManagerImpl$X509Credentials;>;", $PRIVATE | $FINAL, $field(SunX509KeyManagerImpl, credentialsMap)},
	{"serverAliasCache", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;[Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(SunX509KeyManagerImpl, serverAliasCache)},
	{}
};

$MethodInfo _SunX509KeyManagerImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/security/KeyStore;[C)V", nullptr, 0, $method(SunX509KeyManagerImpl, init$, void, $KeyStore*, $chars*), "java.security.KeyStoreException,java.security.NoSuchAlgorithmException,java.security.UnrecoverableKeyException"},
	{"chooseClientAlias", "([Ljava/lang/String;[Ljava/security/Principal;Ljava/net/Socket;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SunX509KeyManagerImpl, chooseClientAlias, $String*, $StringArray*, $PrincipalArray*, $Socket*)},
	{"chooseEngineClientAlias", "([Ljava/lang/String;[Ljava/security/Principal;Ljavax/net/ssl/SSLEngine;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SunX509KeyManagerImpl, chooseEngineClientAlias, $String*, $StringArray*, $PrincipalArray*, $SSLEngine*)},
	{"chooseEngineServerAlias", "(Ljava/lang/String;[Ljava/security/Principal;Ljavax/net/ssl/SSLEngine;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SunX509KeyManagerImpl, chooseEngineServerAlias, $String*, $String*, $PrincipalArray*, $SSLEngine*)},
	{"chooseServerAlias", "(Ljava/lang/String;[Ljava/security/Principal;Ljava/net/Socket;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SunX509KeyManagerImpl, chooseServerAlias, $String*, $String*, $PrincipalArray*, $Socket*)},
	{"convertPrincipals", "([Ljava/security/Principal;)[Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE | $STATIC, $staticMethod(SunX509KeyManagerImpl, convertPrincipals, $X500PrincipalArray*, $PrincipalArray*)},
	{"getAliases", "(Ljava/lang/String;[Ljava/security/Principal;)[Ljava/lang/String;", nullptr, $PRIVATE, $method(SunX509KeyManagerImpl, getAliases, $StringArray*, $String*, $PrincipalArray*)},
	{"getCertificateChain", "(Ljava/lang/String;)[Ljava/security/cert/X509Certificate;", nullptr, $PUBLIC, $virtualMethod(SunX509KeyManagerImpl, getCertificateChain, $X509CertificateArray*, $String*)},
	{"getClientAliases", "(Ljava/lang/String;[Ljava/security/Principal;)[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SunX509KeyManagerImpl, getClientAliases, $StringArray*, $String*, $PrincipalArray*)},
	{"getPrivateKey", "(Ljava/lang/String;)Ljava/security/PrivateKey;", nullptr, $PUBLIC, $virtualMethod(SunX509KeyManagerImpl, getPrivateKey, $PrivateKey*, $String*)},
	{"getServerAliases", "(Ljava/lang/String;[Ljava/security/Principal;)[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SunX509KeyManagerImpl, getServerAliases, $StringArray*, $String*, $PrincipalArray*)},
	{}
};

$InnerClassInfo _SunX509KeyManagerImpl_InnerClassesInfo_[] = {
	{"sun.security.ssl.SunX509KeyManagerImpl$X509Credentials", "sun.security.ssl.SunX509KeyManagerImpl", "X509Credentials", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SunX509KeyManagerImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SunX509KeyManagerImpl",
	"javax.net.ssl.X509ExtendedKeyManager",
	nullptr,
	_SunX509KeyManagerImpl_FieldInfo_,
	_SunX509KeyManagerImpl_MethodInfo_,
	nullptr,
	nullptr,
	_SunX509KeyManagerImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.SunX509KeyManagerImpl$X509Credentials"
};

$Object* allocate$SunX509KeyManagerImpl($Class* clazz) {
	return $of($alloc(SunX509KeyManagerImpl));
}

$StringArray* SunX509KeyManagerImpl::STRING0 = nullptr;

void SunX509KeyManagerImpl::init$($KeyStore* ks, $chars* password) {
	$useLocalCurrentObjectStackCache();
	$X509ExtendedKeyManager::init$();
	$set(this, credentialsMap, $new($HashMap));
	$set(this, serverAliasCache, $Collections::synchronizedMap($$new($HashMap)));
	if (ks == nullptr) {
		return;
	}
	{
		$var($Enumeration, aliases, $nc(ks)->aliases());
		for (; $nc(aliases)->hasMoreElements();) {
			$var($String, alias, $cast($String, aliases->nextElement()));
			if (!ks->isKeyEntry(alias)) {
				continue;
			}
			$var($Key, key, ks->getKey(alias, password));
			if (!($instanceOf($PrivateKey, key))) {
				continue;
			}
			$var($CertificateArray, certs, ks->getCertificateChain(alias));
			if ((certs == nullptr) || ($nc(certs)->length == 0) || !($instanceOf($X509Certificate, $nc(certs)->get(0)))) {
				continue;
			}
			if (!($instanceOf($X509CertificateArray, certs))) {
				$var($CertificateArray, tmp, $fcast($CertificateArray, $new($X509CertificateArray, $nc(certs)->length)));
				$System::arraycopy(certs, 0, tmp, 0, certs->length);
				$assign(certs, tmp);
			}
			$var($SunX509KeyManagerImpl$X509Credentials, cred, $new($SunX509KeyManagerImpl$X509Credentials, $cast($PrivateKey, key), $fcast($X509CertificateArray, certs)));
			$nc(this->credentialsMap)->put(alias, cred);
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
				$SSLLogger::fine($$str({"found key for : "_s, alias}), certs);
			}
		}
	}
}

$X509CertificateArray* SunX509KeyManagerImpl::getCertificateChain($String* alias) {
	if (alias == nullptr) {
		return nullptr;
	}
	$var($SunX509KeyManagerImpl$X509Credentials, cred, $cast($SunX509KeyManagerImpl$X509Credentials, $nc(this->credentialsMap)->get(alias)));
	if (cred == nullptr) {
		return nullptr;
	} else {
		return $cast($X509CertificateArray, $nc($nc(cred)->certificates)->clone());
	}
}

$PrivateKey* SunX509KeyManagerImpl::getPrivateKey($String* alias) {
	if (alias == nullptr) {
		return nullptr;
	}
	$var($SunX509KeyManagerImpl$X509Credentials, cred, $cast($SunX509KeyManagerImpl$X509Credentials, $nc(this->credentialsMap)->get(alias)));
	if (cred == nullptr) {
		return nullptr;
	} else {
		return $nc(cred)->privateKey;
	}
}

$String* SunX509KeyManagerImpl::chooseClientAlias($StringArray* keyTypes, $PrincipalArray* issuers, $Socket* socket) {
	$useLocalCurrentObjectStackCache();
	if (keyTypes == nullptr) {
		return nullptr;
	}
	for (int32_t i = 0; i < $nc(keyTypes)->length; ++i) {
		$var($StringArray, aliases, getClientAliases(keyTypes->get(i), issuers));
		if ((aliases != nullptr) && (aliases->length > 0)) {
			return aliases->get(0);
		}
	}
	return nullptr;
}

$String* SunX509KeyManagerImpl::chooseEngineClientAlias($StringArray* keyType, $PrincipalArray* issuers, $SSLEngine* engine) {
	return chooseClientAlias(keyType, issuers, nullptr);
}

$String* SunX509KeyManagerImpl::chooseServerAlias($String* keyType, $PrincipalArray* issuers, $Socket* socket) {
	if (keyType == nullptr) {
		return nullptr;
	}
	$var($StringArray, aliases, nullptr);
	if (issuers == nullptr || $nc(issuers)->length == 0) {
		$assign(aliases, $cast($StringArray, $nc(this->serverAliasCache)->get(keyType)));
		if (aliases == nullptr) {
			$assign(aliases, getServerAliases(keyType, issuers));
			if (aliases == nullptr) {
				$assign(aliases, SunX509KeyManagerImpl::STRING0);
			}
			$nc(this->serverAliasCache)->put(keyType, aliases);
		}
	} else {
		$assign(aliases, getServerAliases(keyType, issuers));
	}
	if ((aliases != nullptr) && (aliases->length > 0)) {
		return aliases->get(0);
	}
	return nullptr;
}

$String* SunX509KeyManagerImpl::chooseEngineServerAlias($String* keyType, $PrincipalArray* issuers, $SSLEngine* engine) {
	return chooseServerAlias(keyType, issuers, nullptr);
}

$StringArray* SunX509KeyManagerImpl::getClientAliases($String* keyType, $PrincipalArray* issuers) {
	return getAliases(keyType, issuers);
}

$StringArray* SunX509KeyManagerImpl::getServerAliases($String* keyType, $PrincipalArray* issuers) {
	return getAliases(keyType, issuers);
}

$StringArray* SunX509KeyManagerImpl::getAliases($String* keyType$renamed, $PrincipalArray* issuers$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, keyType, keyType$renamed);
	$var($PrincipalArray, issuers, issuers$renamed);
	if (keyType == nullptr) {
		return nullptr;
	}
	if (issuers == nullptr) {
		$assign(issuers, $fcast($PrincipalArray, $new($X500PrincipalArray, 0)));
	}
	if (!($instanceOf($X500PrincipalArray, issuers))) {
		$assign(issuers, $fcast($PrincipalArray, convertPrincipals(issuers)));
	}
	$var($String, sigType, nullptr);
	if ($nc(keyType)->contains("_"_s)) {
		int32_t k = keyType->indexOf((int32_t)u'_');
		$assign(sigType, keyType->substring(k + 1));
		$assign(keyType, keyType->substring(0, k));
	} else {
		$assign(sigType, nullptr);
	}
	$var($X500PrincipalArray, x500Issuers, $fcast($X500PrincipalArray, issuers));
	$var($List, aliases, $new($ArrayList));
	{
		$var($Iterator, i$, $nc($($nc(this->credentialsMap)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($String, alias, $cast($String, $nc(entry)->getKey()));
				$var($SunX509KeyManagerImpl$X509Credentials, credentials, $cast($SunX509KeyManagerImpl$X509Credentials, entry->getValue()));
				$var($X509CertificateArray, certs, $nc(credentials)->certificates);
				if (!$nc(keyType)->equals($($nc($($nc($nc(certs)->get(0))->getPublicKey()))->getAlgorithm()))) {
					continue;
				}
				if (sigType != nullptr) {
					if ($nc(certs)->length > 1) {
						if (!sigType->equals($($nc($($nc(certs->get(1))->getPublicKey()))->getAlgorithm()))) {
							continue;
						}
					} else {
						$init($Locale);
						$var($String, sigAlgName, $nc($($nc(certs->get(0))->getSigAlgName()))->toUpperCase($Locale::ENGLISH));
						$var($String, pattern, $str({"WITH"_s, $(sigType->toUpperCase($Locale::ENGLISH))}));
						if (!sigAlgName->contains(pattern)) {
							continue;
						}
					}
				}
				if ($nc(issuers)->length == 0) {
					aliases->add(alias);
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
						$SSLLogger::fine($$str({"matching alias: "_s, alias}), $$new($ObjectArray, 0));
					}
				} else {
					$var($Set, certIssuers, credentials->getIssuerX500Principals());
					for (int32_t i = 0; i < $nc(x500Issuers)->length; ++i) {
						if ($nc(certIssuers)->contains(issuers->get(i))) {
							aliases->add(alias);
							$init($SSLLogger);
							if ($SSLLogger::isOn$ && $SSLLogger::isOn("keymanager"_s)) {
								$SSLLogger::fine($$str({"matching alias: "_s, alias}), $$new($ObjectArray, 0));
							}
							break;
						}
					}
				}
			}
		}
	}
	$var($StringArray, aliasStrings, $fcast($StringArray, aliases->toArray(SunX509KeyManagerImpl::STRING0)));
	return (($nc(aliasStrings)->length == 0) ? ($StringArray*)nullptr : aliasStrings);
}

$X500PrincipalArray* SunX509KeyManagerImpl::convertPrincipals($PrincipalArray* principals) {
	$init(SunX509KeyManagerImpl);
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList, $nc(principals)->length));
	for (int32_t i = 0; i < $nc(principals)->length; ++i) {
		$var($Principal, p, principals->get(i));
		if ($instanceOf($X500Principal, p)) {
			list->add($cast($X500Principal, p));
		} else {
			try {
				list->add($$new($X500Principal, $($nc(p)->getName())));
			} catch ($IllegalArgumentException& e) {
			}
		}
	}
	return $fcast($X500PrincipalArray, list->toArray($$new($X500PrincipalArray, 0)));
}

void clinit$SunX509KeyManagerImpl($Class* class$) {
	$assignStatic(SunX509KeyManagerImpl::STRING0, $new($StringArray, 0));
}

SunX509KeyManagerImpl::SunX509KeyManagerImpl() {
}

$Class* SunX509KeyManagerImpl::load$($String* name, bool initialize) {
	$loadClass(SunX509KeyManagerImpl, name, initialize, &_SunX509KeyManagerImpl_ClassInfo_, clinit$SunX509KeyManagerImpl, allocate$SunX509KeyManagerImpl);
	return class$;
}

$Class* SunX509KeyManagerImpl::class$ = nullptr;

		} // ssl
	} // security
} // sun