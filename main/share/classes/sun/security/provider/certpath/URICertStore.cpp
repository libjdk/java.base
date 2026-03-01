#include <sun/security/provider/certpath/URICertStore.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/net/HttpURLConnection.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/Provider.h>
#include <java/security/cert/CRL.h>
#include <java/security/cert/CRLException.h>
#include <java/security/cert/CRLSelector.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/CertStore.h>
#include <java/security/cert/CertStoreException.h>
#include <java/security/cert/CertStoreParameters.h>
#include <java/security/cert/CertStoreSpi.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/security/cert/URICertStoreParameters.h>
#include <java/security/cert/X509CRL.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Set.h>
#include <sun/security/action/GetIntegerAction.h>
#include <sun/security/provider/certpath/PKIX$CertStoreTypeException.h>
#include <sun/security/provider/certpath/URICertStore$UCS.h>
#include <sun/security/util/Cache.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AccessDescription.h>
#include <sun/security/x509/GeneralName.h>
#include <sun/security/x509/GeneralNameInterface.h>
#include <sun/security/x509/URIName.h>
#include <jcpp.h>

#undef CACHE_SIZE
#undef CHECK_INTERVAL
#undef CRL_CONNECT_TIMEOUT
#undef CRL_READ_TIMEOUT
#undef DEFAULT_CRL_CONNECT_TIMEOUT
#undef DEFAULT_CRL_READ_TIMEOUT
#undef ENGLISH
#undef HTTP_NOT_MODIFIED

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $HttpURLConnection = ::java::net::HttpURLConnection;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $Provider = ::java::security::Provider;
using $CRL = ::java::security::cert::CRL;
using $CRLException = ::java::security::cert::CRLException;
using $CRLSelector = ::java::security::cert::CRLSelector;
using $CertSelector = ::java::security::cert::CertSelector;
using $CertStore = ::java::security::cert::CertStore;
using $CertStoreException = ::java::security::cert::CertStoreException;
using $CertStoreParameters = ::java::security::cert::CertStoreParameters;
using $CertStoreSpi = ::java::security::cert::CertStoreSpi;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $URICertStoreParameters = ::java::security::cert::URICertStoreParameters;
using $X509CRL = ::java::security::cert::X509CRL;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $GetIntegerAction = ::sun::security::action::GetIntegerAction;
using $PKIX$CertStoreTypeException = ::sun::security::provider::certpath::PKIX$CertStoreTypeException;
using $URICertStore$UCS = ::sun::security::provider::certpath::URICertStore$UCS;
using $Cache = ::sun::security::util::Cache;
using $Debug = ::sun::security::util::Debug;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AccessDescription = ::sun::security::x509::AccessDescription;
using $GeneralName = ::sun::security::x509::GeneralName;
using $GeneralNameInterface = ::sun::security::x509::GeneralNameInterface;
using $URIName = ::sun::security::x509::URIName;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _URICertStore_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(URICertStore, debug)},
	{"CHECK_INTERVAL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(URICertStore, CHECK_INTERVAL)},
	{"CACHE_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(URICertStore, CACHE_SIZE)},
	{"factory", "Ljava/security/cert/CertificateFactory;", nullptr, $PRIVATE | $FINAL, $field(URICertStore, factory)},
	{"certs", "Ljava/util/Collection;", "Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;", $PRIVATE, $field(URICertStore, certs)},
	{"crl", "Ljava/security/cert/X509CRL;", nullptr, $PRIVATE, $field(URICertStore, crl)},
	{"lastChecked", "J", nullptr, $PRIVATE, $field(URICertStore, lastChecked)},
	{"lastModified", "J", nullptr, $PRIVATE, $field(URICertStore, lastModified)},
	{"uri", "Ljava/net/URI;", nullptr, $PRIVATE, $field(URICertStore, uri)},
	{"ldap", "Z", nullptr, $PRIVATE, $field(URICertStore, ldap)},
	{"ldapCertStore", "Ljava/security/cert/CertStore;", nullptr, $PRIVATE, $field(URICertStore, ldapCertStore)},
	{"DEFAULT_CRL_CONNECT_TIMEOUT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(URICertStore, DEFAULT_CRL_CONNECT_TIMEOUT)},
	{"DEFAULT_CRL_READ_TIMEOUT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(URICertStore, DEFAULT_CRL_READ_TIMEOUT)},
	{"CRL_CONNECT_TIMEOUT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(URICertStore, CRL_CONNECT_TIMEOUT)},
	{"CRL_READ_TIMEOUT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(URICertStore, CRL_READ_TIMEOUT)},
	{"certStoreCache", "Lsun/security/util/Cache;", "Lsun/security/util/Cache<Ljava/security/cert/URICertStoreParameters;Ljava/security/cert/CertStore;>;", $PRIVATE | $STATIC | $FINAL, $staticField(URICertStore, certStoreCache)},
	{}
};

$MethodInfo _URICertStore_MethodInfo_[] = {
	{"<init>", "(Ljava/security/cert/CertStoreParameters;)V", nullptr, 0, $method(URICertStore, init$, void, $CertStoreParameters*), "java.security.InvalidAlgorithmParameterException,java.security.NoSuchAlgorithmException"},
	{"engineGetCRLs", "(Ljava/security/cert/CRLSelector;)Ljava/util/Collection;", "(Ljava/security/cert/CRLSelector;)Ljava/util/Collection<Ljava/security/cert/X509CRL;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(URICertStore, engineGetCRLs, $Collection*, $CRLSelector*), "java.security.cert.CertStoreException"},
	{"engineGetCertificates", "(Ljava/security/cert/CertSelector;)Ljava/util/Collection;", "(Ljava/security/cert/CertSelector;)Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(URICertStore, engineGetCertificates, $Collection*, $CertSelector*), "java.security.cert.CertStoreException"},
	{"getInstance", "(Ljava/security/cert/URICertStoreParameters;)Ljava/security/cert/CertStore;", nullptr, $STATIC | $SYNCHRONIZED, $staticMethod(URICertStore, getInstance, $CertStore*, $URICertStoreParameters*), "java.security.NoSuchAlgorithmException,java.security.InvalidAlgorithmParameterException"},
	{"getInstance", "(Lsun/security/x509/AccessDescription;)Ljava/security/cert/CertStore;", nullptr, $STATIC, $staticMethod(URICertStore, getInstance, $CertStore*, $AccessDescription*)},
	{"getMatchingCRLs", "(Ljava/security/cert/X509CRL;Ljava/security/cert/CRLSelector;)Ljava/util/Collection;", "(Ljava/security/cert/X509CRL;Ljava/security/cert/CRLSelector;)Ljava/util/Collection<Ljava/security/cert/X509CRL;>;", $PRIVATE | $STATIC, $staticMethod(URICertStore, getMatchingCRLs, $Collection*, $X509CRL*, $CRLSelector*)},
	{"getMatchingCerts", "(Ljava/util/Collection;Ljava/security/cert/CertSelector;)Ljava/util/Collection;", "(Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;Ljava/security/cert/CertSelector;)Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;", $PRIVATE | $STATIC, $staticMethod(URICertStore, getMatchingCerts, $Collection*, $Collection*, $CertSelector*)},
	{"initializeTimeout", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(URICertStore, initializeTimeout, int32_t, $String*, int32_t)},
	{}
};

$InnerClassInfo _URICertStore_InnerClassesInfo_[] = {
	{"sun.security.provider.certpath.URICertStore$UCS", "sun.security.provider.certpath.URICertStore", "UCS", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _URICertStore_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.certpath.URICertStore",
	"java.security.cert.CertStoreSpi",
	nullptr,
	_URICertStore_FieldInfo_,
	_URICertStore_MethodInfo_,
	nullptr,
	nullptr,
	_URICertStore_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.certpath.URICertStore$UCS"
};

$Object* allocate$URICertStore($Class* clazz) {
	return $of($alloc(URICertStore));
}

$Debug* URICertStore::debug = nullptr;
int32_t URICertStore::CRL_CONNECT_TIMEOUT = 0;
int32_t URICertStore::CRL_READ_TIMEOUT = 0;
$Cache* URICertStore::certStoreCache = nullptr;

int32_t URICertStore::initializeTimeout($String* prop, int32_t def) {
	$init(URICertStore);
	$useLocalCurrentObjectStackCache();
	$var($Integer, tmp, $GetIntegerAction::privilegedGetProperty(prop));
	if (tmp == nullptr || $nc(tmp)->intValue() < 0) {
		return def;
	}
	if (URICertStore::debug != nullptr) {
		$nc(URICertStore::debug)->println($$str({prop, " set to "_s, tmp, " seconds"_s}));
	}
	return $nc(tmp)->intValue() * 1000;
}

void URICertStore::init$($CertStoreParameters* params) {
	$useLocalCurrentObjectStackCache();
	$CertStoreSpi::init$(params);
	$set(this, certs, $Collections::emptySet());
	this->ldap = false;
	if (!($instanceOf($URICertStoreParameters, params))) {
		$throwNew($InvalidAlgorithmParameterException, "params must be instanceof URICertStoreParameters"_s);
	}
	$set(this, uri, $nc(($cast($URICertStoreParameters, params)))->getURI());
	$init($Locale);
	if ($($nc($($nc(this->uri)->getScheme()))->toLowerCase($Locale::ENGLISH))->equals("ldap"_s)) {
		this->ldap = true;
		$set(this, ldapCertStore, $CertStore::getInstance("LDAP"_s, params));
	}
	try {
		$set(this, factory, $CertificateFactory::getInstance("X.509"_s));
	} catch ($CertificateException& e) {
		$throwNew($RuntimeException);
	}
}

$CertStore* URICertStore::getInstance($URICertStoreParameters* params) {
	$load(URICertStore);
	$synchronized(class$) {
		$init(URICertStore);
		$useLocalCurrentObjectStackCache();
		if (URICertStore::debug != nullptr) {
			$nc(URICertStore::debug)->println($$str({"CertStore URI:"_s, $($nc(params)->getURI())}));
		}
		$var($CertStore, ucs, $cast($CertStore, $nc(URICertStore::certStoreCache)->get(params)));
		if (ucs == nullptr) {
			$assign(ucs, $new($URICertStore$UCS, $$new(URICertStore, params), nullptr, "URI"_s, params));
			$nc(URICertStore::certStoreCache)->put(params, ucs);
		} else {
			if (URICertStore::debug != nullptr) {
				$nc(URICertStore::debug)->println("URICertStore.getInstance: cache hit"_s);
			}
		}
		return ucs;
	}
}

$CertStore* URICertStore::getInstance($AccessDescription* ad) {
	$init(URICertStore);
	$useLocalCurrentObjectStackCache();
	$init($AccessDescription);
	if (!$nc($($nc(ad)->getAccessMethod()))->equals($AccessDescription::Ad_CAISSUERS_Id)) {
		return nullptr;
	}
	$var($GeneralNameInterface, gn, $nc($($nc(ad)->getAccessLocation()))->getName());
	if (!($instanceOf($URIName, gn))) {
		return nullptr;
	}
	$var($URI, uri, $nc(($cast($URIName, gn)))->getURI());
	try {
		return URICertStore::getInstance($$new($URICertStoreParameters, uri));
	} catch ($Exception& ex) {
		if (URICertStore::debug != nullptr) {
			$nc(URICertStore::debug)->println($$str({"exception creating CertStore: "_s, ex}));
			ex->printStackTrace();
		}
		return nullptr;
	}
	$shouldNotReachHere();
}

$Collection* URICertStore::engineGetCertificates($CertSelector* selector) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->ldap) {
			return $nc(this->ldapCertStore)->getCertificates(selector);
		}
		int64_t time = $System::currentTimeMillis();
		if (time - this->lastChecked < URICertStore::CHECK_INTERVAL) {
			if (URICertStore::debug != nullptr) {
				$nc(URICertStore::debug)->println("Returning certificates from cache"_s);
			}
			return getMatchingCerts(this->certs, selector);
		}
		this->lastChecked = time;
		try {
			$var($URLConnection, connection, $nc($($nc(this->uri)->toURL()))->openConnection());
			if (this->lastModified != 0) {
				$nc(connection)->setIfModifiedSince(this->lastModified);
			}
			int64_t oldLastModified = this->lastModified;
			{
				$var($InputStream, in, $nc(connection)->getInputStream());
				{
					$var($Throwable, var$0, nullptr);
					$var($Collection, var$2, nullptr);
					bool return$1 = false;
					try {
						try {
							this->lastModified = connection->getLastModified();
							if (oldLastModified != 0) {
								if (oldLastModified == this->lastModified) {
									if (URICertStore::debug != nullptr) {
										$nc(URICertStore::debug)->println("Not modified, using cached copy"_s);
									}
									$assign(var$2, getMatchingCerts(this->certs, selector));
									return$1 = true;
									goto $finally;
								} else if ($instanceOf($HttpURLConnection, connection)) {
									$var($HttpURLConnection, hconn, $cast($HttpURLConnection, connection));
									if (hconn->getResponseCode() == $HttpURLConnection::HTTP_NOT_MODIFIED) {
										if (URICertStore::debug != nullptr) {
											$nc(URICertStore::debug)->println("Not modified, using cached copy"_s);
										}
										$assign(var$2, getMatchingCerts(this->certs, selector));
										return$1 = true;
										goto $finally;
									}
								}
							}
							if (URICertStore::debug != nullptr) {
								$nc(URICertStore::debug)->println("Downloading new certificates..."_s);
							}
							$set(this, certs, $nc(this->factory)->generateCertificates(in));
						} catch ($Throwable& t$) {
							if (in != nullptr) {
								try {
									in->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
							}
							$throw(t$);
						}
					} catch ($Throwable& var$3) {
						$assign(var$0, var$3);
					} $finally: {
						if (in != nullptr) {
							in->close();
						}
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
					if (return$1) {
						return var$2;
					}
				}
			}
			return getMatchingCerts(this->certs, selector);
		} catch ($IOException& e) {
			if (URICertStore::debug != nullptr) {
				$nc(URICertStore::debug)->println("Exception fetching certificates:"_s);
				e->printStackTrace();
			}
		} catch ($CertificateException& e) {
			if (URICertStore::debug != nullptr) {
				$nc(URICertStore::debug)->println("Exception fetching certificates:"_s);
				e->printStackTrace();
			}
		}
		this->lastModified = 0;
		$set(this, certs, $Collections::emptySet());
		return this->certs;
	}
}

$Collection* URICertStore::getMatchingCerts($Collection* certs, $CertSelector* selector) {
	$init(URICertStore);
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

$Collection* URICertStore::engineGetCRLs($CRLSelector* selector) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->ldap) {
			try {
				return $nc(this->ldapCertStore)->getCRLs(selector);
			} catch ($CertStoreException& cse) {
				$throwNew($PKIX$CertStoreTypeException, "LDAP"_s, cse);
			}
		}
		int64_t time = $System::currentTimeMillis();
		if (time - this->lastChecked < URICertStore::CHECK_INTERVAL) {
			if (URICertStore::debug != nullptr) {
				$nc(URICertStore::debug)->println("Returning CRL from cache"_s);
			}
			return getMatchingCRLs(this->crl, selector);
		}
		this->lastChecked = time;
		try {
			$var($URLConnection, connection, $nc($($nc(this->uri)->toURL()))->openConnection());
			if (this->lastModified != 0) {
				$nc(connection)->setIfModifiedSince(this->lastModified);
			}
			int64_t oldLastModified = this->lastModified;
			$nc(connection)->setConnectTimeout(URICertStore::CRL_CONNECT_TIMEOUT);
			connection->setReadTimeout(URICertStore::CRL_READ_TIMEOUT);
			{
				$var($InputStream, in, connection->getInputStream());
				{
					$var($Throwable, var$0, nullptr);
					$var($Collection, var$2, nullptr);
					bool return$1 = false;
					try {
						try {
							this->lastModified = connection->getLastModified();
							if (oldLastModified != 0) {
								if (oldLastModified == this->lastModified) {
									if (URICertStore::debug != nullptr) {
										$nc(URICertStore::debug)->println("Not modified, using cached copy"_s);
									}
									$assign(var$2, getMatchingCRLs(this->crl, selector));
									return$1 = true;
									goto $finally;
								} else if ($instanceOf($HttpURLConnection, connection)) {
									$var($HttpURLConnection, hconn, $cast($HttpURLConnection, connection));
									if (hconn->getResponseCode() == $HttpURLConnection::HTTP_NOT_MODIFIED) {
										if (URICertStore::debug != nullptr) {
											$nc(URICertStore::debug)->println("Not modified, using cached copy"_s);
										}
										$assign(var$2, getMatchingCRLs(this->crl, selector));
										return$1 = true;
										goto $finally;
									}
								}
							}
							if (URICertStore::debug != nullptr) {
								$nc(URICertStore::debug)->println("Downloading new CRL..."_s);
							}
							$set(this, crl, $cast($X509CRL, $nc(this->factory)->generateCRL(in)));
						} catch ($Throwable& t$) {
							if (in != nullptr) {
								try {
									in->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
							}
							$throw(t$);
						}
					} catch ($Throwable& var$3) {
						$assign(var$0, var$3);
					} $finally: {
						if (in != nullptr) {
							in->close();
						}
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
					if (return$1) {
						return var$2;
					}
				}
			}
			return getMatchingCRLs(this->crl, selector);
		} catch ($IOException& e) {
			if (URICertStore::debug != nullptr) {
				$nc(URICertStore::debug)->println("Exception fetching CRL:"_s);
				e->printStackTrace();
			}
			this->lastModified = 0;
			$set(this, crl, nullptr);
			$throwNew($PKIX$CertStoreTypeException, "URI"_s, $$new($CertStoreException, static_cast<$Throwable*>(e)));
		} catch ($CRLException& e) {
			if (URICertStore::debug != nullptr) {
				$nc(URICertStore::debug)->println("Exception fetching CRL:"_s);
				e->printStackTrace();
			}
			this->lastModified = 0;
			$set(this, crl, nullptr);
			$throwNew($PKIX$CertStoreTypeException, "URI"_s, $$new($CertStoreException, static_cast<$Throwable*>(e)));
		}
	}
	$shouldNotReachHere();
}

$Collection* URICertStore::getMatchingCRLs($X509CRL* crl, $CRLSelector* selector) {
	$init(URICertStore);
	if (selector == nullptr || (crl != nullptr && $nc(selector)->match(crl))) {
		return $Collections::singletonList(crl);
	} else {
		return $Collections::emptyList();
	}
}

void clinit$URICertStore($Class* class$) {
	$assignStatic(URICertStore::debug, $Debug::getInstance("certpath"_s));
	URICertStore::CRL_CONNECT_TIMEOUT = URICertStore::initializeTimeout("com.sun.security.crl.timeout"_s, URICertStore::DEFAULT_CRL_CONNECT_TIMEOUT);
	URICertStore::CRL_READ_TIMEOUT = URICertStore::initializeTimeout("com.sun.security.crl.readtimeout"_s, URICertStore::DEFAULT_CRL_READ_TIMEOUT);
	$assignStatic(URICertStore::certStoreCache, $Cache::newSoftMemoryCache(URICertStore::CACHE_SIZE));
}

URICertStore::URICertStore() {
}

$Class* URICertStore::load$($String* name, bool initialize) {
	$loadClass(URICertStore, name, initialize, &_URICertStore_ClassInfo_, clinit$URICertStore, allocate$URICertStore);
	return class$;
}

$Class* URICertStore::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun