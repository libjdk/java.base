#include <sun/net/www/http/KeepAliveCache.h>

#include <java/io/NotSerializableException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InterruptedException.h>
#include <java/net/URL.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/ArrayList.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <sun/net/www/http/ClientVector.h>
#include <sun/net/www/http/HttpClient.h>
#include <sun/net/www/http/KeepAliveCache$1.h>
#include <sun/net/www/http/KeepAliveEntry.h>
#include <sun/net/www/http/KeepAliveKey.h>
#include <sun/security/action/GetIntegerAction.h>
#include <jcpp.h>

#undef LIFETIME
#undef MAX_CONNECTIONS

using $NotSerializableException = ::java::io::NotSerializableException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $URL = ::java::net::URL;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ArrayList = ::java::util::ArrayList;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $ClientVector = ::sun::net::www::http::ClientVector;
using $HttpClient = ::sun::net::www::http::HttpClient;
using $KeepAliveCache$1 = ::sun::net::www::http::KeepAliveCache$1;
using $KeepAliveEntry = ::sun::net::www::http::KeepAliveEntry;
using $KeepAliveKey = ::sun::net::www::http::KeepAliveKey;
using $GetIntegerAction = ::sun::security::action::GetIntegerAction;

namespace sun {
	namespace net {
		namespace www {
			namespace http {

$FieldInfo _KeepAliveCache_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(KeepAliveCache, $assertionsDisabled)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KeepAliveCache, serialVersionUID)},
	{"MAX_CONNECTIONS", "I", nullptr, $STATIC | $FINAL, $constField(KeepAliveCache, MAX_CONNECTIONS)},
	{"result", "I", nullptr, $STATIC, $staticField(KeepAliveCache, result)},
	{"LIFETIME", "I", nullptr, $STATIC | $FINAL, $constField(KeepAliveCache, LIFETIME)},
	{"cacheLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(KeepAliveCache, cacheLock)},
	{"keepAliveTimer", "Ljava/lang/Thread;", nullptr, $PRIVATE, $field(KeepAliveCache, keepAliveTimer)},
	{}
};

$MethodInfo _KeepAliveCache_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PUBLIC, $method(KeepAliveCache, init$, void)},
	{"get", "(Ljava/net/URL;Ljava/lang/Object;)Lsun/net/www/http/HttpClient;", nullptr, $PUBLIC, $virtualMethod(KeepAliveCache, get, $HttpClient*, $URL*, Object$*)},
	{"getMaxConnections", "()I", nullptr, $STATIC, $staticMethod(KeepAliveCache, getMaxConnections, int32_t)},
	{"put", "(Ljava/net/URL;Ljava/lang/Object;Lsun/net/www/http/HttpClient;)V", nullptr, $PUBLIC, $virtualMethod(KeepAliveCache, put, void, $URL*, Object$*, $HttpClient*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(KeepAliveCache, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(Lsun/net/www/http/HttpClient;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(KeepAliveCache, remove, void, $HttpClient*, Object$*)},
	{"removeVector", "(Lsun/net/www/http/KeepAliveKey;)V", nullptr, $PRIVATE, $method(KeepAliveCache, removeVector, void, $KeepAliveKey*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(KeepAliveCache, run, void)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(KeepAliveCache, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _KeepAliveCache_InnerClassesInfo_[] = {
	{"sun.net.www.http.KeepAliveCache$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _KeepAliveCache_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.http.KeepAliveCache",
	"java.util.HashMap",
	"java.lang.Runnable",
	_KeepAliveCache_FieldInfo_,
	_KeepAliveCache_MethodInfo_,
	"Ljava/util/HashMap<Lsun/net/www/http/KeepAliveKey;Lsun/net/www/http/ClientVector;>;Ljava/lang/Runnable;",
	nullptr,
	_KeepAliveCache_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.net.www.http.KeepAliveCache$1"
};

$Object* allocate$KeepAliveCache($Class* clazz) {
	return $of($alloc(KeepAliveCache));
}

$Object* KeepAliveCache::clone() {
	 return this->$HashMap::clone();
}

bool KeepAliveCache::equals(Object$* o) {
	 return this->$HashMap::equals(o);
}

int32_t KeepAliveCache::hashCode() {
	 return this->$HashMap::hashCode();
}

$String* KeepAliveCache::toString() {
	 return this->$HashMap::toString();
}

void KeepAliveCache::finalize() {
	this->$HashMap::finalize();
}

bool KeepAliveCache::$assertionsDisabled = false;
int32_t KeepAliveCache::result = 0;

int32_t KeepAliveCache::getMaxConnections() {
	$init(KeepAliveCache);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (KeepAliveCache::result == -1) {
		KeepAliveCache::result = $nc(($cast($Integer, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($GetIntegerAction, "http.maxConnections"_s, KeepAliveCache::MAX_CONNECTIONS)))))))->intValue();
		if (KeepAliveCache::result <= 0) {
			KeepAliveCache::result = KeepAliveCache::MAX_CONNECTIONS;
		}
	}
	return KeepAliveCache::result;
}

void KeepAliveCache::init$() {
	$HashMap::init$();
	$set(this, cacheLock, $new($ReentrantLock));
	$set(this, keepAliveTimer, nullptr);
}

void KeepAliveCache::put($URL* url, Object$* obj, $HttpClient* http) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$nc(this->cacheLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			bool startThread = (this->keepAliveTimer == nullptr);
			if (!startThread) {
				if (!$nc(this->keepAliveTimer)->isAlive()) {
					startThread = true;
				}
			}
			if (startThread) {
				clear();
				$var(KeepAliveCache, cache, this);
				$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($KeepAliveCache$1, this, cache)));
			}
			$var($KeepAliveKey, key, $new($KeepAliveKey, url, obj));
			$var($ClientVector, v, $cast($ClientVector, $HashMap::get(key)));
			if (v == nullptr) {
				int32_t keepAliveTimeout = $nc(http)->getKeepAliveTimeout();
				$assign(v, $new($ClientVector, keepAliveTimeout > 0 ? keepAliveTimeout * 1000 : KeepAliveCache::LIFETIME));
				v->put(http);
				$HashMap::put(key, v);
			} else {
				$nc(v)->put(http);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->cacheLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void KeepAliveCache::remove($HttpClient* h, Object$* obj) {
	$useLocalCurrentObjectStackCache();
	$nc(this->cacheLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($KeepAliveKey, key, $new($KeepAliveKey, $nc(h)->url, obj));
			$var($ClientVector, v, $cast($ClientVector, $HashMap::get(key)));
			if (v != nullptr) {
				v->remove(h);
				if (v->isEmpty()) {
					removeVector(key);
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->cacheLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void KeepAliveCache::removeVector($KeepAliveKey* k) {
	if (!KeepAliveCache::$assertionsDisabled && !$nc(this->cacheLock)->isHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	$HashMap::remove(k);
}

$HttpClient* KeepAliveCache::get($URL* url, Object$* obj) {
	$useLocalCurrentObjectStackCache();
	$nc(this->cacheLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($HttpClient, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($KeepAliveKey, key, $new($KeepAliveKey, url, obj));
			$var($ClientVector, v, $cast($ClientVector, $HashMap::get(key)));
			if (v == nullptr) {
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
			$assign(var$2, $nc(v)->get());
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->cacheLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void KeepAliveCache::run() {
	$useLocalCurrentObjectStackCache();
	do {
		try {
			$Thread::sleep(KeepAliveCache::LIFETIME);
		} catch ($InterruptedException& e) {
		}
		$nc(this->cacheLock)->lock();
		{
			$var($Throwable, var$0, nullptr);
			try {
				int64_t currentTime = $System::currentTimeMillis();
				$var($List, keysToRemove, $new($ArrayList));
				{
					$var($Iterator, i$, $nc($(keySet()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($KeepAliveKey, key, $cast($KeepAliveKey, i$->next()));
						{
							$var($ClientVector, v, $cast($ClientVector, get(key)));
							$nc(v)->lock();
							{
								$var($Throwable, var$1, nullptr);
								try {
									$var($KeepAliveEntry, e, $cast($KeepAliveEntry, v->peek()));
									while (e != nullptr) {
										if ((currentTime - e->idleStartTime) > v->nap) {
											v->poll();
											$nc(e->hc)->closeServer();
										} else {
											break;
										}
										$assign(e, $cast($KeepAliveEntry, v->peek()));
									}
									if (v->isEmpty()) {
										keysToRemove->add(key);
									}
								} catch ($Throwable& var$2) {
									$assign(var$1, var$2);
								} /*finally*/ {
									v->unlock();
								}
								if (var$1 != nullptr) {
									$throw(var$1);
								}
							}
						}
					}
				}
				{
					$var($Iterator, i$, keysToRemove->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($KeepAliveKey, key, $cast($KeepAliveKey, i$->next()));
						{
							removeVector(key);
						}
					}
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} /*finally*/ {
				$nc(this->cacheLock)->unlock();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} while (!isEmpty());
}

void KeepAliveCache::writeObject($ObjectOutputStream* stream) {
	$throwNew($NotSerializableException);
}

void KeepAliveCache::readObject($ObjectInputStream* stream) {
	$throwNew($NotSerializableException);
}

void clinit$KeepAliveCache($Class* class$) {
	KeepAliveCache::$assertionsDisabled = !KeepAliveCache::class$->desiredAssertionStatus();
	KeepAliveCache::result = -1;
}

KeepAliveCache::KeepAliveCache() {
}

$Class* KeepAliveCache::load$($String* name, bool initialize) {
	$loadClass(KeepAliveCache, name, initialize, &_KeepAliveCache_ClassInfo_, clinit$KeepAliveCache, allocate$KeepAliveCache);
	return class$;
}

$Class* KeepAliveCache::class$ = nullptr;

			} // http
		} // www
	} // net
} // sun