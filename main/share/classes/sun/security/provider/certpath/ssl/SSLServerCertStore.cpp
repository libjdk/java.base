#include <sun/security/provider/certpath/ssl/SSLServerCertStore.h>

#include <java/io/IOException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Provider.h>
#include <java/security/SecureRandom.h>
#include <java/security/cert/CRLSelector.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/CertStore.h>
#include <java/security/cert/CertStoreException.h>
#include <java/security/cert/CertStoreParameters.h>
#include <java/security/cert/CertStoreSpi.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <javax/net/ssl/HostnameVerifier.h>
#include <javax/net/ssl/HttpsURLConnection.h>
#include <javax/net/ssl/KeyManager.h>
#include <javax/net/ssl/SSLContext.h>
#include <javax/net/ssl/SSLSocketFactory.h>
#include <javax/net/ssl/TrustManager.h>
#include <sun/security/provider/certpath/ssl/SSLServerCertStore$1.h>
#include <sun/security/provider/certpath/ssl/SSLServerCertStore$CS.h>
#include <sun/security/provider/certpath/ssl/SSLServerCertStore$GetChainTrustManager.h>
#include <jcpp.h>

using $KeyManagerArray = $Array<::javax::net::ssl::KeyManager>;
using $TrustManagerArray = $Array<::javax::net::ssl::TrustManager>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Provider = ::java::security::Provider;
using $SecureRandom = ::java::security::SecureRandom;
using $CRLSelector = ::java::security::cert::CRLSelector;
using $CertSelector = ::java::security::cert::CertSelector;
using $CertStore = ::java::security::cert::CertStore;
using $CertStoreException = ::java::security::cert::CertStoreException;
using $CertStoreParameters = ::java::security::cert::CertStoreParameters;
using $CertStoreSpi = ::java::security::cert::CertStoreSpi;
using $Certificate = ::java::security::cert::Certificate;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $HostnameVerifier = ::javax::net::ssl::HostnameVerifier;
using $HttpsURLConnection = ::javax::net::ssl::HttpsURLConnection;
using $SSLContext = ::javax::net::ssl::SSLContext;
using $SSLSocketFactory = ::javax::net::ssl::SSLSocketFactory;
using $TrustManager = ::javax::net::ssl::TrustManager;
using $SSLServerCertStore$1 = ::sun::security::provider::certpath::ssl::SSLServerCertStore$1;
using $SSLServerCertStore$CS = ::sun::security::provider::certpath::ssl::SSLServerCertStore$CS;
using $SSLServerCertStore$GetChainTrustManager = ::sun::security::provider::certpath::ssl::SSLServerCertStore$GetChainTrustManager;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {
				namespace ssl {

$FieldInfo _SSLServerCertStore_FieldInfo_[] = {
	{"uri", "Ljava/net/URI;", nullptr, $PRIVATE | $FINAL, $field(SSLServerCertStore, uri)},
	{"trustManager", "Lsun/security/provider/certpath/ssl/SSLServerCertStore$GetChainTrustManager;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLServerCertStore, trustManager)},
	{"socketFactory", "Ljavax/net/ssl/SSLSocketFactory;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLServerCertStore, socketFactory)},
	{"hostnameVerifier", "Ljavax/net/ssl/HostnameVerifier;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLServerCertStore, hostnameVerifier)},
	{}
};

$MethodInfo _SSLServerCertStore_MethodInfo_[] = {
	{"<init>", "(Ljava/net/URI;)V", nullptr, 0, $method(SSLServerCertStore, init$, void, $URI*), "java.security.InvalidAlgorithmParameterException"},
	{"engineGetCRLs", "(Ljava/security/cert/CRLSelector;)Ljava/util/Collection;", "(Ljava/security/cert/CRLSelector;)Ljava/util/Collection<Ljava/security/cert/X509CRL;>;", $PUBLIC, $virtualMethod(SSLServerCertStore, engineGetCRLs, $Collection*, $CRLSelector*), "java.security.cert.CertStoreException"},
	{"engineGetCertificates", "(Ljava/security/cert/CertSelector;)Ljava/util/Collection;", "(Ljava/security/cert/CertSelector;)Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;", $PUBLIC, $virtualMethod(SSLServerCertStore, engineGetCertificates, $Collection*, $CertSelector*), "java.security.cert.CertStoreException"},
	{"getInstance", "(Ljava/net/URI;)Ljava/security/cert/CertStore;", nullptr, $PUBLIC | $STATIC, $staticMethod(SSLServerCertStore, getInstance, $CertStore*, $URI*), "java.security.InvalidAlgorithmParameterException"},
	{"getMatchingCerts", "(Ljava/util/List;Ljava/security/cert/CertSelector;)Ljava/util/List;", "(Ljava/util/List<Ljava/security/cert/X509Certificate;>;Ljava/security/cert/CertSelector;)Ljava/util/List<Ljava/security/cert/X509Certificate;>;", $PRIVATE | $STATIC, $staticMethod(SSLServerCertStore, getMatchingCerts, $List*, $List*, $CertSelector*)},
	{}
};

$InnerClassInfo _SSLServerCertStore_InnerClassesInfo_[] = {
	{"sun.security.provider.certpath.ssl.SSLServerCertStore$CS", "sun.security.provider.certpath.ssl.SSLServerCertStore", "CS", $PRIVATE | $STATIC},
	{"sun.security.provider.certpath.ssl.SSLServerCertStore$GetChainTrustManager", "sun.security.provider.certpath.ssl.SSLServerCertStore", "GetChainTrustManager", $PRIVATE | $STATIC},
	{"sun.security.provider.certpath.ssl.SSLServerCertStore$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SSLServerCertStore_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.provider.certpath.ssl.SSLServerCertStore",
	"java.security.cert.CertStoreSpi",
	nullptr,
	_SSLServerCertStore_FieldInfo_,
	_SSLServerCertStore_MethodInfo_,
	nullptr,
	nullptr,
	_SSLServerCertStore_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.certpath.ssl.SSLServerCertStore$CS,sun.security.provider.certpath.ssl.SSLServerCertStore$GetChainTrustManager,sun.security.provider.certpath.ssl.SSLServerCertStore$1"
};

$Object* allocate$SSLServerCertStore($Class* clazz) {
	return $of($alloc(SSLServerCertStore));
}

$SSLServerCertStore$GetChainTrustManager* SSLServerCertStore::trustManager = nullptr;
$SSLSocketFactory* SSLServerCertStore::socketFactory = nullptr;
$HostnameVerifier* SSLServerCertStore::hostnameVerifier = nullptr;

void SSLServerCertStore::init$($URI* uri) {
	$CertStoreSpi::init$(nullptr);
	$set(this, uri, uri);
}

$Collection* SSLServerCertStore::engineGetCertificates($CertSelector* selector) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($URLConnection, urlConn, $nc($($nc(this->uri)->toURL()))->openConnection());
		if ($instanceOf($HttpsURLConnection, urlConn)) {
			if (SSLServerCertStore::socketFactory == nullptr) {
				$throwNew($CertStoreException, "No initialized SSLSocketFactory"_s);
			}
			$var($HttpsURLConnection, https, $cast($HttpsURLConnection, urlConn));
			$nc(https)->setSSLSocketFactory(SSLServerCertStore::socketFactory);
			https->setHostnameVerifier(SSLServerCertStore::hostnameVerifier);
			$synchronized(SSLServerCertStore::trustManager) {
				{
					$var($Throwable, var$0, nullptr);
					$var($Collection, var$2, nullptr);
					bool return$1 = false;
					try {
						try {
							https->connect();
							$assign(var$2, getMatchingCerts($nc(SSLServerCertStore::trustManager)->serverChain, selector));
							return$1 = true;
							goto $finally;
						} catch ($IOException& ioe) {
							if ($nc(SSLServerCertStore::trustManager)->exchangedServerCerts) {
								$assign(var$2, getMatchingCerts($nc(SSLServerCertStore::trustManager)->serverChain, selector));
								return$1 = true;
								goto $finally;
							}
							$throw(ioe);
						}
					} catch ($Throwable& var$3) {
						$assign(var$0, var$3);
					} $finally: {
						$nc(SSLServerCertStore::trustManager)->cleanup();
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
					if (return$1) {
						return var$2;
					}
				}
			}
		}
	} catch ($IOException& ioe) {
		$throwNew($CertStoreException, static_cast<$Throwable*>(ioe));
	}
	return $Collections::emptySet();
}

$List* SSLServerCertStore::getMatchingCerts($List* certs, $CertSelector* selector) {
	$init(SSLServerCertStore);
	$useLocalCurrentObjectStackCache();
	if (selector == nullptr) {
		return certs;
	}
	$var($List, matchedCerts, $new($ArrayList, $nc(certs)->size()));
	{
		$var($Iterator, i$, $nc(certs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($X509Certificate, cert, $cast($X509Certificate, i$->next()));
			{
				if ($nc(selector)->match(cert)) {
					matchedCerts->add(cert);
				}
			}
		}
	}
	return matchedCerts;
}

$Collection* SSLServerCertStore::engineGetCRLs($CRLSelector* selector) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$CertStore* SSLServerCertStore::getInstance($URI* uri) {
	$init(SSLServerCertStore);
	return $new($SSLServerCertStore$CS, $$new(SSLServerCertStore, uri), nullptr, "SSLServer"_s, nullptr);
}

void clinit$SSLServerCertStore($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$assignStatic(SSLServerCertStore::trustManager, $new($SSLServerCertStore$GetChainTrustManager));
		$assignStatic(SSLServerCertStore::hostnameVerifier, $new($SSLServerCertStore$1));
		$var($SSLSocketFactory, tempFactory, nullptr);
		try {
			$var($SSLContext, context, $SSLContext::getInstance("SSL"_s));
			$nc(context)->init(nullptr, $$new($TrustManagerArray, {static_cast<$TrustManager*>(SSLServerCertStore::trustManager)}), nullptr);
			$assign(tempFactory, context->getSocketFactory());
		} catch ($GeneralSecurityException& gse) {
			$assign(tempFactory, nullptr);
		}
		$assignStatic(SSLServerCertStore::socketFactory, tempFactory);
	}
}

SSLServerCertStore::SSLServerCertStore() {
}

$Class* SSLServerCertStore::load$($String* name, bool initialize) {
	$loadClass(SSLServerCertStore, name, initialize, &_SSLServerCertStore_ClassInfo_, clinit$SSLServerCertStore, allocate$SSLServerCertStore);
	return class$;
}

$Class* SSLServerCertStore::class$ = nullptr;

				} // ssl
			} // certpath
		} // provider
	} // security
} // sun