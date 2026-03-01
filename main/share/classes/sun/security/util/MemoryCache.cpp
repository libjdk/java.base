#include <sun/security/util/MemoryCache.h>

#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/Map.h>
#include <sun/security/util/Cache$CacheVisitor.h>
#include <sun/security/util/Cache.h>
#include <sun/security/util/MemoryCache$CacheEntry.h>
#include <sun/security/util/MemoryCache$HardCacheEntry.h>
#include <sun/security/util/MemoryCache$SoftCacheEntry.h>
#include <jcpp.h>

#undef DEBUG
#undef LOAD_FACTOR
#undef MAX_VALUE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $Map = ::java::util::Map;
using $Cache = ::sun::security::util::Cache;
using $Cache$CacheVisitor = ::sun::security::util::Cache$CacheVisitor;
using $MemoryCache$CacheEntry = ::sun::security::util::MemoryCache$CacheEntry;
using $MemoryCache$HardCacheEntry = ::sun::security::util::MemoryCache$HardCacheEntry;
using $MemoryCache$SoftCacheEntry = ::sun::security::util::MemoryCache$SoftCacheEntry;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _MemoryCache_FieldInfo_[] = {
	{"LOAD_FACTOR", "F", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MemoryCache, LOAD_FACTOR)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MemoryCache, DEBUG)},
	{"cacheMap", "Ljava/util/Map;", "Ljava/util/Map<TK;Lsun/security/util/MemoryCache$CacheEntry<TK;TV;>;>;", $PRIVATE | $FINAL, $field(MemoryCache, cacheMap)},
	{"maxSize", "I", nullptr, $PRIVATE, $field(MemoryCache, maxSize)},
	{"lifetime", "J", nullptr, $PRIVATE, $field(MemoryCache, lifetime)},
	{"nextExpirationTime", "J", nullptr, $PRIVATE, $field(MemoryCache, nextExpirationTime)},
	{"queue", "Ljava/lang/ref/ReferenceQueue;", "Ljava/lang/ref/ReferenceQueue<TV;>;", $PRIVATE | $FINAL, $field(MemoryCache, queue)},
	{}
};

$MethodInfo _MemoryCache_MethodInfo_[] = {
	{"<init>", "(ZI)V", nullptr, $PUBLIC, $method(MemoryCache, init$, void, bool, int32_t)},
	{"<init>", "(ZII)V", nullptr, $PUBLIC, $method(MemoryCache, init$, void, bool, int32_t, int32_t)},
	{"accept", "(Lsun/security/util/Cache$CacheVisitor;)V", "(Lsun/security/util/Cache$CacheVisitor<TK;TV;>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(MemoryCache, accept, void, $Cache$CacheVisitor*)},
	{"clear", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MemoryCache, clear, void)},
	{"emptyQueue", "()V", nullptr, $PRIVATE, $method(MemoryCache, emptyQueue, void)},
	{"expungeExpiredEntries", "()V", nullptr, $PRIVATE, $method(MemoryCache, expungeExpiredEntries, void)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(MemoryCache, get, $Object*, Object$*)},
	{"getCachedEntries", "()Ljava/util/Map;", "()Ljava/util/Map<TK;TV;>;", $PRIVATE, $method(MemoryCache, getCachedEntries, $Map*)},
	{"newEntry", "(Ljava/lang/Object;Ljava/lang/Object;JLjava/lang/ref/ReferenceQueue;)Lsun/security/util/MemoryCache$CacheEntry;", "(TK;TV;JLjava/lang/ref/ReferenceQueue<TV;>;)Lsun/security/util/MemoryCache$CacheEntry<TK;TV;>;", $PROTECTED, $virtualMethod(MemoryCache, newEntry, $MemoryCache$CacheEntry*, Object$*, Object$*, int64_t, $ReferenceQueue*)},
	{"pull", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(MemoryCache, pull, $Object*, Object$*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)V", "(TK;TV;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(MemoryCache, put, void, Object$*, Object$*)},
	{"remove", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MemoryCache, remove, void, Object$*)},
	{"setCapacity", "(I)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MemoryCache, setCapacity, void, int32_t)},
	{"setTimeout", "(I)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MemoryCache, setTimeout, void, int32_t)},
	{"size", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MemoryCache, size, int32_t)},
	{}
};

$InnerClassInfo _MemoryCache_InnerClassesInfo_[] = {
	{"sun.security.util.MemoryCache$SoftCacheEntry", "sun.security.util.MemoryCache", "SoftCacheEntry", $PRIVATE | $STATIC},
	{"sun.security.util.MemoryCache$HardCacheEntry", "sun.security.util.MemoryCache", "HardCacheEntry", $PRIVATE | $STATIC},
	{"sun.security.util.MemoryCache$CacheEntry", "sun.security.util.MemoryCache", "CacheEntry", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _MemoryCache_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.util.MemoryCache",
	"sun.security.util.Cache",
	nullptr,
	_MemoryCache_FieldInfo_,
	_MemoryCache_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Lsun/security/util/Cache<TK;TV;>;",
	nullptr,
	_MemoryCache_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.util.MemoryCache$SoftCacheEntry,sun.security.util.MemoryCache$HardCacheEntry,sun.security.util.MemoryCache$CacheEntry"
};

$Object* allocate$MemoryCache($Class* clazz) {
	return $of($alloc(MemoryCache));
}

float MemoryCache::LOAD_FACTOR = 0.0;

void MemoryCache::init$(bool soft, int32_t maxSize) {
	MemoryCache::init$(soft, maxSize, 0);
}

void MemoryCache::init$(bool soft, int32_t maxSize, int32_t lifetime) {
	$Cache::init$();
	this->nextExpirationTime = $Long::MAX_VALUE;
	this->maxSize = maxSize;
	this->lifetime = lifetime * 1000;
	if (soft) {
		$set(this, queue, $new($ReferenceQueue));
	} else {
		$set(this, queue, nullptr);
	}
	$set(this, cacheMap, $new($LinkedHashMap, 1, MemoryCache::LOAD_FACTOR, true));
}

void MemoryCache::emptyQueue() {
	$useLocalCurrentObjectStackCache();
	if (this->queue == nullptr) {
		return;
	}
	int32_t startSize = $nc(this->cacheMap)->size();
	while (true) {
		$var($MemoryCache$CacheEntry, entry, $cast($MemoryCache$CacheEntry, $nc(this->queue)->poll()));
		if (entry == nullptr) {
			break;
		}
		$var($Object, key, $nc(entry)->getKey());
		if (key == nullptr) {
			continue;
		}
		$var($MemoryCache$CacheEntry, currentEntry, $cast($MemoryCache$CacheEntry, $nc(this->cacheMap)->remove(key)));
		if ((currentEntry != nullptr) && (entry != currentEntry)) {
			$nc(this->cacheMap)->put(key, currentEntry);
		}
	}
}

void MemoryCache::expungeExpiredEntries() {
	$useLocalCurrentObjectStackCache();
	emptyQueue();
	if (this->lifetime == 0) {
		return;
	}
	int32_t cnt = 0;
	int64_t time = $System::currentTimeMillis();
	if (this->nextExpirationTime > time) {
		return;
	}
	this->nextExpirationTime = $Long::MAX_VALUE;
	{
		$var($Iterator, t, $nc($($nc(this->cacheMap)->values()))->iterator());
		for (; $nc(t)->hasNext();) {
			$var($MemoryCache$CacheEntry, entry, $cast($MemoryCache$CacheEntry, t->next()));
			if ($nc(entry)->isValid(time) == false) {
				t->remove();
				++cnt;
			} else if (this->nextExpirationTime > entry->getExpirationTime()) {
				this->nextExpirationTime = entry->getExpirationTime();
			}
		}
	}
}

int32_t MemoryCache::size() {
	$synchronized(this) {
		expungeExpiredEntries();
		return $nc(this->cacheMap)->size();
	}
}

void MemoryCache::clear() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->queue != nullptr) {
			{
				$var($Iterator, i$, $nc($($nc(this->cacheMap)->values()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($MemoryCache$CacheEntry, entry, $cast($MemoryCache$CacheEntry, i$->next()));
					{
						$nc(entry)->invalidate();
					}
				}
			}
			while ($nc(this->queue)->poll() != nullptr) {
			}
		}
		$nc(this->cacheMap)->clear();
	}
}

void MemoryCache::put(Object$* key, Object$* value) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		emptyQueue();
		int64_t expirationTime = (this->lifetime == 0) ? (int64_t)0 : $System::currentTimeMillis() + this->lifetime;
		if (expirationTime < this->nextExpirationTime) {
			this->nextExpirationTime = expirationTime;
		}
		$var($MemoryCache$CacheEntry, newEntry, this->newEntry(key, value, expirationTime, this->queue));
		$var($MemoryCache$CacheEntry, oldEntry, $cast($MemoryCache$CacheEntry, $nc(this->cacheMap)->put(key, newEntry)));
		if (oldEntry != nullptr) {
			oldEntry->invalidate();
			return;
		}
		if (this->maxSize > 0 && $nc(this->cacheMap)->size() > this->maxSize) {
			expungeExpiredEntries();
			if ($nc(this->cacheMap)->size() > this->maxSize) {
				$var($Iterator, t, $nc($($nc(this->cacheMap)->values()))->iterator());
				$var($MemoryCache$CacheEntry, lruEntry, $cast($MemoryCache$CacheEntry, $nc(t)->next()));
				t->remove();
				$nc(lruEntry)->invalidate();
			}
		}
	}
}

$Object* MemoryCache::get(Object$* key) {
	$synchronized(this) {
		emptyQueue();
		$var($MemoryCache$CacheEntry, entry, $cast($MemoryCache$CacheEntry, $nc(this->cacheMap)->get(key)));
		if (entry == nullptr) {
			return $of(nullptr);
		}
		int64_t time = (this->lifetime == 0) ? (int64_t)0 : $System::currentTimeMillis();
		if ($nc(entry)->isValid(time) == false) {
			$nc(this->cacheMap)->remove(key);
			return $of(nullptr);
		}
		return $of($nc(entry)->getValue());
	}
}

void MemoryCache::remove(Object$* key) {
	$synchronized(this) {
		emptyQueue();
		$var($MemoryCache$CacheEntry, entry, $cast($MemoryCache$CacheEntry, $nc(this->cacheMap)->remove(key)));
		if (entry != nullptr) {
			entry->invalidate();
		}
	}
}

$Object* MemoryCache::pull(Object$* key) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		emptyQueue();
		$var($MemoryCache$CacheEntry, entry, $cast($MemoryCache$CacheEntry, $nc(this->cacheMap)->remove(key)));
		if (entry == nullptr) {
			return $of(nullptr);
		}
		int64_t time = (this->lifetime == 0) ? (int64_t)0 : $System::currentTimeMillis();
		if ($nc(entry)->isValid(time)) {
			$var($Object, value, entry->getValue());
			entry->invalidate();
			return $of(value);
		} else {
			return $of(nullptr);
		}
	}
}

void MemoryCache::setCapacity(int32_t size) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		expungeExpiredEntries();
		if (size > 0 && $nc(this->cacheMap)->size() > size) {
			$var($Iterator, t, $nc($($nc(this->cacheMap)->values()))->iterator());
			for (int32_t i = $nc(this->cacheMap)->size() - size; i > 0; --i) {
				$var($MemoryCache$CacheEntry, lruEntry, $cast($MemoryCache$CacheEntry, $nc(t)->next()));
				t->remove();
				$nc(lruEntry)->invalidate();
			}
		}
		this->maxSize = size > 0 ? size : 0;
	}
}

void MemoryCache::setTimeout(int32_t timeout) {
	$synchronized(this) {
		emptyQueue();
		this->lifetime = timeout > 0 ? timeout * (int64_t)1000 : (int64_t)0;
	}
}

void MemoryCache::accept($Cache$CacheVisitor* visitor) {
	$synchronized(this) {
		expungeExpiredEntries();
		$var($Map, cached, getCachedEntries());
		$nc(visitor)->visit(cached);
	}
}

$Map* MemoryCache::getCachedEntries() {
	$useLocalCurrentObjectStackCache();
	$var($Map, kvmap, $new($HashMap, $nc(this->cacheMap)->size()));
	{
		$var($Iterator, i$, $nc($($nc(this->cacheMap)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($MemoryCache$CacheEntry, entry, $cast($MemoryCache$CacheEntry, i$->next()));
			{
				$var($Object, var$0, $nc(entry)->getKey());
				kvmap->put(var$0, $(entry->getValue()));
			}
		}
	}
	return kvmap;
}

$MemoryCache$CacheEntry* MemoryCache::newEntry(Object$* key, Object$* value, int64_t expirationTime, $ReferenceQueue* queue) {
	if (queue != nullptr) {
		return $new($MemoryCache$SoftCacheEntry, key, value, expirationTime, queue);
	} else {
		return $new($MemoryCache$HardCacheEntry, key, value, expirationTime);
	}
}

MemoryCache::MemoryCache() {
}

void clinit$MemoryCache($Class* class$) {
	MemoryCache::LOAD_FACTOR = 0.75f;
}

$Class* MemoryCache::load$($String* name, bool initialize) {
	$loadClass(MemoryCache, name, initialize, &_MemoryCache_ClassInfo_, clinit$MemoryCache, allocate$MemoryCache);
	return class$;
}

$Class* MemoryCache::class$ = nullptr;

		} // util
	} // security
} // sun