#include <java/net/InMemoryCookieStore.h>

#include <java/lang/Comparable.h>
#include <java/net/HttpCookie.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <jcpp.h>

#undef D
#undef H

using $ClassInfo = ::java::lang::ClassInfo;
using $Comparable = ::java::lang::Comparable;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $HttpCookie = ::java::net::HttpCookie;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;

namespace java {
	namespace net {

$FieldInfo _InMemoryCookieStore_FieldInfo_[] = {
	{"cookieJar", "Ljava/util/List;", "Ljava/util/List<Ljava/net/HttpCookie;>;", $PRIVATE, $field(InMemoryCookieStore, cookieJar)},
	{"domainIndex", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/net/HttpCookie;>;>;", $PRIVATE, $field(InMemoryCookieStore, domainIndex)},
	{"uriIndex", "Ljava/util/Map;", "Ljava/util/Map<Ljava/net/URI;Ljava/util/List<Ljava/net/HttpCookie;>;>;", $PRIVATE, $field(InMemoryCookieStore, uriIndex)},
	{"lock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE, $field(InMemoryCookieStore, lock)},
	{}
};

$MethodInfo _InMemoryCookieStore_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(InMemoryCookieStore, init$, void)},
	{"add", "(Ljava/net/URI;Ljava/net/HttpCookie;)V", nullptr, $PUBLIC, $virtualMethod(InMemoryCookieStore, add, void, $URI*, $HttpCookie*)},
	{"addIndex", "(Ljava/util/Map;Ljava/lang/Object;Ljava/net/HttpCookie;)V", "<T:Ljava/lang/Object;>(Ljava/util/Map<TT;Ljava/util/List<Ljava/net/HttpCookie;>;>;TT;Ljava/net/HttpCookie;)V", $PRIVATE, $method(InMemoryCookieStore, addIndex, void, $Map*, Object$*, $HttpCookie*)},
	{"get", "(Ljava/net/URI;)Ljava/util/List;", "(Ljava/net/URI;)Ljava/util/List<Ljava/net/HttpCookie;>;", $PUBLIC, $virtualMethod(InMemoryCookieStore, get, $List*, $URI*)},
	{"getCookies", "()Ljava/util/List;", "()Ljava/util/List<Ljava/net/HttpCookie;>;", $PUBLIC, $virtualMethod(InMemoryCookieStore, getCookies, $List*)},
	{"getEffectiveURI", "(Ljava/net/URI;)Ljava/net/URI;", nullptr, $PRIVATE, $method(InMemoryCookieStore, getEffectiveURI, $URI*, $URI*)},
	{"getInternal1", "(Ljava/util/List;Ljava/util/Map;Ljava/lang/String;Z)V", "(Ljava/util/List<Ljava/net/HttpCookie;>;Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/net/HttpCookie;>;>;Ljava/lang/String;Z)V", $PRIVATE, $method(InMemoryCookieStore, getInternal1, void, $List*, $Map*, $String*, bool)},
	{"getInternal2", "(Ljava/util/List;Ljava/util/Map;Ljava/lang/Comparable;Z)V", "<T:Ljava/lang/Object;>(Ljava/util/List<Ljava/net/HttpCookie;>;Ljava/util/Map<TT;Ljava/util/List<Ljava/net/HttpCookie;>;>;Ljava/lang/Comparable<TT;>;Z)V", $PRIVATE, $method(InMemoryCookieStore, getInternal2, void, $List*, $Map*, $Comparable*, bool)},
	{"getURIs", "()Ljava/util/List;", "()Ljava/util/List<Ljava/net/URI;>;", $PUBLIC, $virtualMethod(InMemoryCookieStore, getURIs, $List*)},
	{"netscapeDomainMatches", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(InMemoryCookieStore, netscapeDomainMatches, bool, $String*, $String*)},
	{"remove", "(Ljava/net/URI;Ljava/net/HttpCookie;)Z", nullptr, $PUBLIC, $virtualMethod(InMemoryCookieStore, remove, bool, $URI*, $HttpCookie*)},
	{"removeAll", "()Z", nullptr, $PUBLIC, $virtualMethod(InMemoryCookieStore, removeAll, bool)},
	{}
};

$ClassInfo _InMemoryCookieStore_ClassInfo_ = {
	$ACC_SUPER,
	"java.net.InMemoryCookieStore",
	"java.lang.Object",
	"java.net.CookieStore",
	_InMemoryCookieStore_FieldInfo_,
	_InMemoryCookieStore_MethodInfo_
};

$Object* allocate$InMemoryCookieStore($Class* clazz) {
	return $of($alloc(InMemoryCookieStore));
}

void InMemoryCookieStore::init$() {
	$set(this, cookieJar, nullptr);
	$set(this, domainIndex, nullptr);
	$set(this, uriIndex, nullptr);
	$set(this, lock, nullptr);
	$set(this, cookieJar, $new($ArrayList));
	$set(this, domainIndex, $new($HashMap));
	$set(this, uriIndex, $new($HashMap));
	$set(this, lock, $new($ReentrantLock, false));
}

void InMemoryCookieStore::add($URI* uri, $HttpCookie* cookie) {
	$useLocalCurrentObjectStackCache();
	if (cookie == nullptr) {
		$throwNew($NullPointerException, "cookie is null"_s);
	}
	$nc(this->lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->cookieJar)->remove($of(cookie));
			if ($nc(cookie)->getMaxAge() != 0) {
				$nc(this->cookieJar)->add(cookie);
				if (cookie->getDomain() != nullptr) {
					addIndex(this->domainIndex, $(cookie->getDomain()), cookie);
				}
				if (uri != nullptr) {
					addIndex(this->uriIndex, $(getEffectiveURI(uri)), cookie);
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->lock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$List* InMemoryCookieStore::get($URI* uri) {
	$useLocalCurrentObjectStackCache();
	if (uri == nullptr) {
		$throwNew($NullPointerException, "uri is null"_s);
	}
	$var($List, cookies, $new($ArrayList));
	bool secureLink = "https"_s->equalsIgnoreCase($($nc(uri)->getScheme()));
	$nc(this->lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			getInternal1(cookies, this->domainIndex, $($nc(uri)->getHost()), secureLink);
			getInternal2(cookies, this->uriIndex, $(getEffectiveURI(uri)), secureLink);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->lock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return cookies;
}

$List* InMemoryCookieStore::getCookies() {
	$useLocalCurrentObjectStackCache();
	$var($List, rt, nullptr);
	$nc(this->lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($Iterator, it, $nc(this->cookieJar)->iterator());
			while ($nc(it)->hasNext()) {
				if ($nc(($cast($HttpCookie, $(it->next()))))->hasExpired()) {
					it->remove();
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$assign(rt, $Collections::unmodifiableList(this->cookieJar));
			$nc(this->lock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return rt;
}

$List* InMemoryCookieStore::getURIs() {
	$useLocalCurrentObjectStackCache();
	$var($List, uris, $new($ArrayList));
	$nc(this->lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($Iterator, it, $nc($($nc(this->uriIndex)->keySet()))->iterator());
			while ($nc(it)->hasNext()) {
				$var($URI, uri, $cast($URI, it->next()));
				$var($List, cookies, $cast($List, $nc(this->uriIndex)->get(uri)));
				if (cookies == nullptr || $nc(cookies)->size() == 0) {
					it->remove();
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			uris->addAll($($nc(this->uriIndex)->keySet()));
			$nc(this->lock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return uris;
}

bool InMemoryCookieStore::remove($URI* uri, $HttpCookie* ck) {
	if (ck == nullptr) {
		$throwNew($NullPointerException, "cookie is null"_s);
	}
	bool modified = false;
	$nc(this->lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			modified = $nc(this->cookieJar)->remove($of(ck));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->lock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return modified;
}

bool InMemoryCookieStore::removeAll() {
	$nc(this->lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			if ($nc(this->cookieJar)->isEmpty()) {
				var$2 = false;
				return$1 = true;
				goto $finally;
			}
			$nc(this->cookieJar)->clear();
			$nc(this->domainIndex)->clear();
			$nc(this->uriIndex)->clear();
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->lock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	return true;
}

bool InMemoryCookieStore::netscapeDomainMatches($String* domain, $String* host) {
	$useLocalCurrentObjectStackCache();
	if (domain == nullptr || host == nullptr) {
		return false;
	}
	bool isLocalDomain = ".local"_s->equalsIgnoreCase(domain);
	int32_t embeddedDotInDomain = $nc(domain)->indexOf((int32_t)u'.');
	if (embeddedDotInDomain == 0) {
		embeddedDotInDomain = domain->indexOf((int32_t)u'.', 1);
	}
	if (!isLocalDomain && (embeddedDotInDomain == -1 || embeddedDotInDomain == domain->length() - 1)) {
		return false;
	}
	int32_t firstDotInHost = $nc(host)->indexOf((int32_t)u'.');
	if (firstDotInHost == -1 && isLocalDomain) {
		return true;
	}
	int32_t domainLength = domain->length();
	int32_t lengthDiff = host->length() - domainLength;
	if (lengthDiff == 0) {
		return host->equalsIgnoreCase(domain);
	} else if (lengthDiff > 0) {
		$var($String, H, host->substring(0, lengthDiff));
		$var($String, D, host->substring(lengthDiff));
		return (D->equalsIgnoreCase(domain));
	} else if (lengthDiff == -1) {
		bool var$0 = domain->charAt(0) == u'.';
		return (var$0 && host->equalsIgnoreCase($(domain->substring(1))));
	}
	return false;
}

void InMemoryCookieStore::getInternal1($List* cookies, $Map* cookieIndex, $String* host, bool secureLink) {
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, toRemove, $new($ArrayList));
	{
		$var($Iterator, i$, $nc($($nc(cookieIndex)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($String, domain, $cast($String, $nc(entry)->getKey()));
				$var($List, lst, $cast($List, entry->getValue()));
				{
					$var($Iterator, i$, $nc(lst)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($HttpCookie, c, $cast($HttpCookie, i$->next()));
						{
							bool var$1 = $nc(c)->getVersion() == 0;
							bool var$0 = (var$1 && netscapeDomainMatches(domain, host));
							if (!var$0) {
								bool var$2 = $nc(c)->getVersion() == 1;
								var$0 = (var$2 && $HttpCookie::domainMatches(domain, host));
							}
							if (var$0) {
								if ($nc(this->cookieJar)->indexOf(c) != -1) {
									if (!c->hasExpired()) {
										bool var$3 = (secureLink || !c->getSecure());
										if (var$3 && !$nc(cookies)->contains(c)) {
											cookies->add(c);
										}
									} else {
										toRemove->add(c);
									}
								} else {
									toRemove->add(c);
								}
							}
						}
					}
				}
				{
					$var($Iterator, i$, toRemove->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($HttpCookie, c, $cast($HttpCookie, i$->next()));
						{
							lst->remove($of(c));
							$nc(this->cookieJar)->remove($of(c));
						}
					}
				}
				toRemove->clear();
			}
		}
	}
}

void InMemoryCookieStore::getInternal2($List* cookies, $Map* cookieIndex, $Comparable* comparator, bool secureLink) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(cookieIndex)->keySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, index, i$->next());
			{
				if ($nc(comparator)->compareTo(index) == 0) {
					$var($List, indexedCookies, $cast($List, cookieIndex->get(index)));
					if (indexedCookies != nullptr) {
						$var($Iterator, it, indexedCookies->iterator());
						while ($nc(it)->hasNext()) {
							$var($HttpCookie, ck, $cast($HttpCookie, it->next()));
							if ($nc(this->cookieJar)->indexOf(ck) != -1) {
								if (!$nc(ck)->hasExpired()) {
									bool var$0 = (secureLink || !ck->getSecure());
									if (var$0 && !$nc(cookies)->contains(ck)) {
										cookies->add(ck);
									}
								} else {
									it->remove();
									$nc(this->cookieJar)->remove($of(ck));
								}
							} else {
								it->remove();
							}
						}
					}
				}
			}
		}
	}
}

void InMemoryCookieStore::addIndex($Map* indexStore, Object$* index, $HttpCookie* cookie) {
	if (index != nullptr) {
		$var($List, cookies, $cast($List, $nc(indexStore)->get(index)));
		if (cookies != nullptr) {
			cookies->remove($of(cookie));
			cookies->add(cookie);
		} else {
			$assign(cookies, $new($ArrayList));
			cookies->add(cookie);
			indexStore->put(index, cookies);
		}
	}
}

$URI* InMemoryCookieStore::getEffectiveURI($URI* uri) {
	$useLocalCurrentObjectStackCache();
	$var($URI, effectiveURI, nullptr);
	try {
		$assign(effectiveURI, $new($URI, "http"_s, $($nc(uri)->getHost()), nullptr, nullptr, nullptr));
	} catch ($URISyntaxException& ignored) {
		$assign(effectiveURI, uri);
	}
	return effectiveURI;
}

InMemoryCookieStore::InMemoryCookieStore() {
}

$Class* InMemoryCookieStore::load$($String* name, bool initialize) {
	$loadClass(InMemoryCookieStore, name, initialize, &_InMemoryCookieStore_ClassInfo_, allocate$InMemoryCookieStore);
	return class$;
}

$Class* InMemoryCookieStore::class$ = nullptr;

	} // net
} // java