#include <java/io/ExpiringCache.h>

#include <java/io/ExpiringCache$1.h>
#include <java/io/ExpiringCache$Entry.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef MAX_ENTRIES

using $ExpiringCache$1 = ::java::io::ExpiringCache$1;
using $ExpiringCache$Entry = ::java::io::ExpiringCache$Entry;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;

namespace java {
	namespace io {

$FieldInfo _ExpiringCache_FieldInfo_[] = {
	{"millisUntilExpiration", "J", nullptr, $PRIVATE, $field(ExpiringCache, millisUntilExpiration)},
	{"map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/io/ExpiringCache$Entry;>;", $PRIVATE, $field(ExpiringCache, map)},
	{"queryCount", "I", nullptr, $PRIVATE, $field(ExpiringCache, queryCount)},
	{"queryOverflow", "I", nullptr, $PRIVATE, $field(ExpiringCache, queryOverflow)},
	{"MAX_ENTRIES", "I", nullptr, $PRIVATE, $field(ExpiringCache, MAX_ENTRIES)},
	{}
};

$MethodInfo _ExpiringCache_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(ExpiringCache, init$, void)},
	{"<init>", "(J)V", nullptr, 0, $method(ExpiringCache, init$, void, int64_t)},
	{"cleanup", "()V", nullptr, $PRIVATE, $method(ExpiringCache, cleanup, void)},
	{"clear", "()V", nullptr, $SYNCHRONIZED, $virtualMethod(ExpiringCache, clear, void)},
	{"entryFor", "(Ljava/lang/String;)Ljava/io/ExpiringCache$Entry;", nullptr, $PRIVATE, $method(ExpiringCache, entryFor, $ExpiringCache$Entry*, $String*)},
	{"get", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $SYNCHRONIZED, $virtualMethod(ExpiringCache, get, $String*, $String*)},
	{"put", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $SYNCHRONIZED, $virtualMethod(ExpiringCache, put, void, $String*, $String*)},
	{}
};

$InnerClassInfo _ExpiringCache_InnerClassesInfo_[] = {
	{"java.io.ExpiringCache$Entry", "java.io.ExpiringCache", "Entry", $STATIC},
	{"java.io.ExpiringCache$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ExpiringCache_ClassInfo_ = {
	$ACC_SUPER,
	"java.io.ExpiringCache",
	"java.lang.Object",
	nullptr,
	_ExpiringCache_FieldInfo_,
	_ExpiringCache_MethodInfo_,
	nullptr,
	nullptr,
	_ExpiringCache_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.io.ExpiringCache$Entry,java.io.ExpiringCache$1"
};

$Object* allocate$ExpiringCache($Class* clazz) {
	return $of($alloc(ExpiringCache));
}

void ExpiringCache::init$() {
	ExpiringCache::init$(30000);
}

void ExpiringCache::init$(int64_t millisUntilExpiration) {
	this->queryOverflow = 300;
	this->MAX_ENTRIES = 200;
	this->millisUntilExpiration = millisUntilExpiration;
	$set(this, map, $new($ExpiringCache$1, this));
}

$String* ExpiringCache::get($String* key) {
	$synchronized(this) {
		if (++this->queryCount >= this->queryOverflow) {
			cleanup();
		}
		$var($ExpiringCache$Entry, entry, entryFor(key));
		if (entry != nullptr) {
			return entry->val();
		}
		return nullptr;
	}
}

void ExpiringCache::put($String* key, $String* val) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (++this->queryCount >= this->queryOverflow) {
			cleanup();
		}
		$var($ExpiringCache$Entry, entry, entryFor(key));
		if (entry != nullptr) {
			entry->setTimestamp($System::currentTimeMillis());
			entry->setVal(val);
		} else {
			$nc(this->map)->put(key, $$new($ExpiringCache$Entry, $System::currentTimeMillis(), val));
		}
	}
}

void ExpiringCache::clear() {
	$synchronized(this) {
		$nc(this->map)->clear();
	}
}

$ExpiringCache$Entry* ExpiringCache::entryFor($String* key) {
	$var($ExpiringCache$Entry, entry, $cast($ExpiringCache$Entry, $nc(this->map)->get(key)));
	if (entry != nullptr) {
		int64_t var$0 = $System::currentTimeMillis();
		int64_t delta = var$0 - entry->timestamp();
		if (delta < 0 || delta >= this->millisUntilExpiration) {
			$nc(this->map)->remove(key);
			$assign(entry, nullptr);
		}
	}
	return entry;
}

void ExpiringCache::cleanup() {
	$useLocalCurrentObjectStackCache();
	$var($Set, keySet, $nc(this->map)->keySet());
	$var($StringArray, keys, $new($StringArray, $nc(keySet)->size()));
	int32_t i = 0;
	{
		$var($Iterator, i$, keySet->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, key, $cast($String, i$->next()));
			{
				keys->set(i++, key);
			}
		}
	}
	for (int32_t j = 0; j < keys->length; ++j) {
		entryFor(keys->get(j));
	}
	this->queryCount = 0;
}

ExpiringCache::ExpiringCache() {
}

$Class* ExpiringCache::load$($String* name, bool initialize) {
	$loadClass(ExpiringCache, name, initialize, &_ExpiringCache_ClassInfo_, allocate$ExpiringCache);
	return class$;
}

$Class* ExpiringCache::class$ = nullptr;

	} // io
} // java