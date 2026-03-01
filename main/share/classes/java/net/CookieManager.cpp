#include <java/net/CookieManager.h>

#include <java/lang/CharSequence.h>
#include <java/lang/NumberFormatException.h>
#include <java/net/CookieHandler.h>
#include <java/net/CookieManager$CookieComparator.h>
#include <java/net/CookiePolicy.h>
#include <java/net/CookieStore.h>
#include <java/net/HttpCookie.h>
#include <java/net/InMemoryCookieStore.h>
#include <java/net/URI.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <sun/util/logging/PlatformLogger$Level.h>
#include <sun/util/logging/PlatformLogger.h>
#include <jcpp.h>

#undef ACCEPT_ORIGINAL_SERVER
#undef SEVERE

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $CookieHandler = ::java::net::CookieHandler;
using $CookieManager$CookieComparator = ::java::net::CookieManager$CookieComparator;
using $CookiePolicy = ::java::net::CookiePolicy;
using $CookieStore = ::java::net::CookieStore;
using $HttpCookie = ::java::net::HttpCookie;
using $InMemoryCookieStore = ::java::net::InMemoryCookieStore;
using $URI = ::java::net::URI;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $PlatformLogger = ::sun::util::logging::PlatformLogger;
using $PlatformLogger$Level = ::sun::util::logging::PlatformLogger$Level;

namespace java {
	namespace net {

$FieldInfo _CookieManager_FieldInfo_[] = {
	{"policyCallback", "Ljava/net/CookiePolicy;", nullptr, $PRIVATE, $field(CookieManager, policyCallback)},
	{"cookieJar", "Ljava/net/CookieStore;", nullptr, $PRIVATE, $field(CookieManager, cookieJar)},
	{}
};

$MethodInfo _CookieManager_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CookieManager, init$, void)},
	{"<init>", "(Ljava/net/CookieStore;Ljava/net/CookiePolicy;)V", nullptr, $PUBLIC, $method(CookieManager, init$, void, $CookieStore*, $CookiePolicy*)},
	{"get", "(Ljava/net/URI;Ljava/util/Map;)Ljava/util/Map;", "(Ljava/net/URI;Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;)Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PUBLIC, $virtualMethod(CookieManager, get, $Map*, $URI*, $Map*), "java.io.IOException"},
	{"getCookieStore", "()Ljava/net/CookieStore;", nullptr, $PUBLIC, $virtualMethod(CookieManager, getCookieStore, $CookieStore*)},
	{"isInPortList", "(Ljava/lang/String;I)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(CookieManager, isInPortList, bool, $String*, int32_t)},
	{"pathMatches", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(CookieManager, pathMatches, bool, $String*, $String*)},
	{"put", "(Ljava/net/URI;Ljava/util/Map;)V", "(Ljava/net/URI;Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;)V", $PUBLIC, $virtualMethod(CookieManager, put, void, $URI*, $Map*), "java.io.IOException"},
	{"setCookiePolicy", "(Ljava/net/CookiePolicy;)V", nullptr, $PUBLIC, $virtualMethod(CookieManager, setCookiePolicy, void, $CookiePolicy*)},
	{"shouldAcceptInternal", "(Ljava/net/URI;Ljava/net/HttpCookie;)Z", nullptr, $PRIVATE, $method(CookieManager, shouldAcceptInternal, bool, $URI*, $HttpCookie*)},
	{"sortByPathAndAge", "(Ljava/util/List;)Ljava/util/List;", "(Ljava/util/List<Ljava/net/HttpCookie;>;)Ljava/util/List<Ljava/lang/String;>;", $STATIC, $staticMethod(CookieManager, sortByPathAndAge, $List*, $List*)},
	{}
};

$InnerClassInfo _CookieManager_InnerClassesInfo_[] = {
	{"java.net.CookieManager$CookieComparator", "java.net.CookieManager", "CookieComparator", $STATIC},
	{}
};

$ClassInfo _CookieManager_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.net.CookieManager",
	"java.net.CookieHandler",
	nullptr,
	_CookieManager_FieldInfo_,
	_CookieManager_MethodInfo_,
	nullptr,
	nullptr,
	_CookieManager_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.net.CookieManager$CookieComparator"
};

$Object* allocate$CookieManager($Class* clazz) {
	return $of($alloc(CookieManager));
}

void CookieManager::init$() {
	CookieManager::init$(nullptr, nullptr);
}

void CookieManager::init$($CookieStore* store, $CookiePolicy* cookiePolicy) {
	$CookieHandler::init$();
	$set(this, cookieJar, nullptr);
	$init($CookiePolicy);
	$set(this, policyCallback, (cookiePolicy == nullptr) ? $CookiePolicy::ACCEPT_ORIGINAL_SERVER : cookiePolicy);
	if (store == nullptr) {
		$set(this, cookieJar, $new($InMemoryCookieStore));
	} else {
		$set(this, cookieJar, store);
	}
}

void CookieManager::setCookiePolicy($CookiePolicy* cookiePolicy) {
	if (cookiePolicy != nullptr) {
		$set(this, policyCallback, cookiePolicy);
	}
}

$CookieStore* CookieManager::getCookieStore() {
	return this->cookieJar;
}

$Map* CookieManager::get($URI* uri, $Map* requestHeaders) {
	$useLocalCurrentObjectStackCache();
	if (uri == nullptr || requestHeaders == nullptr) {
		$throwNew($IllegalArgumentException, "Argument is null"_s);
	}
	if (this->cookieJar == nullptr) {
		return $Map::of();
	}
	bool secureLink = "https"_s->equalsIgnoreCase($($nc(uri)->getScheme()));
	$var($List, cookies, $new($ArrayList));
	$var($String, path, $nc(uri)->getPath());
	if (path == nullptr || $nc(path)->isEmpty()) {
		$assign(path, "/"_s);
	}
	{
		$var($Iterator, i$, $nc($($nc(this->cookieJar)->get(uri)))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($HttpCookie, cookie, $cast($HttpCookie, i$->next()));
			{
				bool var$0 = pathMatches(path, $($nc(cookie)->getPath()));
				if (var$0 && (secureLink || !$nc(cookie)->getSecure())) {
					if (cookie->isHttpOnly()) {
						$var($String, s, uri->getScheme());
						bool var$1 = !"http"_s->equalsIgnoreCase(s);
						if (var$1 && !"https"_s->equalsIgnoreCase(s)) {
							continue;
						}
					}
					$var($String, ports, cookie->getPortlist());
					if (ports != nullptr && !ports->isEmpty()) {
						int32_t port = uri->getPort();
						if (port == -1) {
							port = "https"_s->equals($(uri->getScheme())) ? 443 : 80;
						}
						if (isInPortList(ports, port)) {
							cookies->add(cookie);
						}
					} else {
						cookies->add(cookie);
					}
				}
			}
		}
	}
	$var($List, cookieHeader, sortByPathAndAge(cookies));
	return $Map::of("Cookie"_s, cookieHeader);
}

void CookieManager::put($URI* uri, $Map* responseHeaders) {
	$useLocalCurrentObjectStackCache();
	if (uri == nullptr || responseHeaders == nullptr) {
		$throwNew($IllegalArgumentException, "Argument is null"_s);
	}
	if (this->cookieJar == nullptr) {
		return;
	}
	$var($PlatformLogger, logger, $PlatformLogger::getLogger("java.net.CookieManager"_s));
	{
		$var($Iterator, i$, $nc($($nc(responseHeaders)->keySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, headerKey, $cast($String, i$->next()));
			{
				bool var$0 = headerKey == nullptr;
				if (!var$0) {
					bool var$1 = $nc(headerKey)->equalsIgnoreCase("Set-Cookie2"_s);
					var$0 = !(var$1 || $nc(headerKey)->equalsIgnoreCase("Set-Cookie"_s));
				}
				if (var$0) {
					continue;
				}
				{
					$var($Iterator, i$, $nc(($cast($List, $(responseHeaders->get(headerKey)))))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, headerValue, $cast($String, i$->next()));
						{
							try {
								$var($List, cookies, nullptr);
								try {
									$assign(cookies, $HttpCookie::parse(headerValue));
								} catch ($IllegalArgumentException& e) {
									$assign(cookies, $Collections::emptyList());
									$init($PlatformLogger$Level);
									if ($nc(logger)->isLoggable($PlatformLogger$Level::SEVERE)) {
										logger->severe($$str({"Invalid cookie for "_s, uri, ": "_s, headerValue}));
									}
								}
								{
									$var($Iterator, i$, $nc(cookies)->iterator());
									for (; $nc(i$)->hasNext();) {
										$var($HttpCookie, cookie, $cast($HttpCookie, i$->next()));
										{
											if ($nc(cookie)->getPath() == nullptr) {
												$var($String, path, $nc(uri)->getPath());
												if (!$nc(path)->endsWith("/"_s)) {
													int32_t i = path->lastIndexOf((int32_t)u'/');
													if (i > 0) {
														$assign(path, path->substring(0, i + 1));
													} else {
														$assign(path, "/"_s);
													}
												}
												cookie->setPath(path);
											}
											if ($nc(cookie)->getDomain() == nullptr) {
												$var($String, host, $nc(uri)->getHost());
												if (host != nullptr && !host->contains("."_s)) {
													$plusAssign(host, ".local"_s);
												}
												cookie->setDomain(host);
											}
											$var($String, ports, $nc(cookie)->getPortlist());
											if (ports != nullptr) {
												int32_t port = $nc(uri)->getPort();
												if (port == -1) {
													port = "https"_s->equals($(uri->getScheme())) ? 443 : 80;
												}
												if (ports->isEmpty()) {
													cookie->setPortlist($$str({""_s, $$str(port)}));
													if (shouldAcceptInternal(uri, cookie)) {
														$nc(this->cookieJar)->add(uri, cookie);
													}
												} else {
													bool var$3 = isInPortList(ports, port);
													if (var$3 && shouldAcceptInternal(uri, cookie)) {
														$nc(this->cookieJar)->add(uri, cookie);
													}
												}
											} else if (shouldAcceptInternal(uri, cookie)) {
												$nc(this->cookieJar)->add(uri, cookie);
											}
										}
									}
								}
							} catch ($IllegalArgumentException& e) {
							}
						}
					}
				}
			}
		}
	}
}

bool CookieManager::shouldAcceptInternal($URI* uri, $HttpCookie* cookie) {
	try {
		return $nc(this->policyCallback)->shouldAccept(uri, cookie);
	} catch ($Exception& ignored) {
		return false;
	}
	$shouldNotReachHere();
}

bool CookieManager::isInPortList($String* lst$renamed, int32_t port) {
	$init(CookieManager);
	$var($String, lst, lst$renamed);
	int32_t i = $nc(lst)->indexOf((int32_t)u',');
	int32_t val = -1;
	while (i > 0) {
		try {
			val = $Integer::parseInt(lst, 0, i, 10);
			if (val == port) {
				return true;
			}
		} catch ($NumberFormatException& numberFormatException) {
		}
		$assign(lst, lst->substring(i + 1));
		i = lst->indexOf((int32_t)u',');
	}
	if (!lst->isEmpty()) {
		try {
			val = $Integer::parseInt(lst);
			if (val == port) {
				return true;
			}
		} catch ($NumberFormatException& numberFormatException) {
		}
	}
	return false;
}

bool CookieManager::pathMatches($String* path, $String* pathToMatchWith) {
	if (path == pathToMatchWith) {
		return true;
	}
	if (path == nullptr || pathToMatchWith == nullptr) {
		return false;
	}
	if ($nc(path)->startsWith(pathToMatchWith)) {
		return true;
	}
	return false;
}

$List* CookieManager::sortByPathAndAge($List* cookies) {
	$init(CookieManager);
	$useLocalCurrentObjectStackCache();
	$Collections::sort(cookies, $$new($CookieManager$CookieComparator));
	$var($List, cookieHeader, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(cookies)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($HttpCookie, cookie, $cast($HttpCookie, i$->next()));
			{
				bool var$0 = cookies->indexOf(cookie) == 0;
				if (var$0 && $nc(cookie)->getVersion() > 0) {
					cookieHeader->add("$Version=\"1\""_s);
				}
				cookieHeader->add($($nc(cookie)->toString()));
			}
		}
	}
	return cookieHeader;
}

CookieManager::CookieManager() {
}

$Class* CookieManager::load$($String* name, bool initialize) {
	$loadClass(CookieManager, name, initialize, &_CookieManager_ClassInfo_, allocate$CookieManager);
	return class$;
}

$Class* CookieManager::class$ = nullptr;

	} // net
} // java