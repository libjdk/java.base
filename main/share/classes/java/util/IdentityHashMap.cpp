#include <java/util/IdentityHashMap.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/StreamCorruptedException.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/IdentityHashMap$EntrySet.h>
#include <java/util/IdentityHashMap$KeySet.h>
#include <java/util/IdentityHashMap$Values.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <jdk/internal/access/JavaObjectInputStreamAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef DEFAULT_CAPACITY
#undef MAXIMUM_CAPACITY
#undef MINIMUM_CAPACITY
#undef NULL_KEY

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $StreamCorruptedException = ::java::io::StreamCorruptedException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $IdentityHashMap$EntrySet = ::java::util::IdentityHashMap$EntrySet;
using $IdentityHashMap$KeySet = ::java::util::IdentityHashMap$KeySet;
using $IdentityHashMap$Values = ::java::util::IdentityHashMap$Values;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $JavaObjectInputStreamAccess = ::jdk::internal::access::JavaObjectInputStreamAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace util {

$FieldInfo _IdentityHashMap_FieldInfo_[] = {
	{"DEFAULT_CAPACITY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IdentityHashMap, DEFAULT_CAPACITY)},
	{"MINIMUM_CAPACITY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IdentityHashMap, MINIMUM_CAPACITY)},
	{"MAXIMUM_CAPACITY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IdentityHashMap, MAXIMUM_CAPACITY)},
	{"table", "[Ljava/lang/Object;", nullptr, $TRANSIENT, $field(IdentityHashMap, table)},
	{"size", "I", nullptr, 0, $field(IdentityHashMap, size$)},
	{"modCount", "I", nullptr, $TRANSIENT, $field(IdentityHashMap, modCount)},
	{"NULL_KEY", "Ljava/lang/Object;", nullptr, $STATIC | $FINAL, $staticField(IdentityHashMap, NULL_KEY)},
	{"entrySet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PRIVATE | $TRANSIENT, $field(IdentityHashMap, entrySet$)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IdentityHashMap, serialVersionUID)},
	{}
};

$MethodInfo _IdentityHashMap_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "()V", nullptr, $PUBLIC, $method(IdentityHashMap, init$, void)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(IdentityHashMap, init$, void, int32_t)},
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<+TK;+TV;>;)V", $PUBLIC, $method(IdentityHashMap, init$, void, $Map*)},
	{"capacity", "(I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(IdentityHashMap, capacity, int32_t, int32_t)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap, clone, $Object*)},
	{"closeDeletion", "(I)V", nullptr, $PRIVATE, $method(IdentityHashMap, closeDeletion, void, int32_t)},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap, containsKey, bool, Object$*)},
	{"containsMapping", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PRIVATE, $method(IdentityHashMap, containsMapping, bool, Object$*, Object$*)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap, containsValue, bool, Object$*)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(IdentityHashMap, entrySet, $Set*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap, equals, bool, Object$*)},
	{"forEach", "(Ljava/util/function/BiConsumer;)V", "(Ljava/util/function/BiConsumer<-TK;-TV;>;)V", $PUBLIC, $virtualMethod(IdentityHashMap, forEach, void, $BiConsumer*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(IdentityHashMap, get, $Object*, Object$*)},
	{"hash", "(Ljava/lang/Object;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(IdentityHashMap, hash, int32_t, Object$*, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap, hashCode, int32_t)},
	{"init", "(I)V", nullptr, $PRIVATE, $method(IdentityHashMap, init, void, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap, isEmpty, bool)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<TK;>;", $PUBLIC, $virtualMethod(IdentityHashMap, keySet, $Set*)},
	{"maskNull", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticMethod(IdentityHashMap, maskNull, $Object*, Object$*)},
	{"nextKeyIndex", "(II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(IdentityHashMap, nextKeyIndex, int32_t, int32_t, int32_t)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(IdentityHashMap, put, $Object*, Object$*, Object$*)},
	{"putAll", "(Ljava/util/Map;)V", "(Ljava/util/Map<+TK;+TV;>;)V", $PUBLIC, $virtualMethod(IdentityHashMap, putAll, void, $Map*)},
	{"putForCreate", "(Ljava/lang/Object;Ljava/lang/Object;)V", "(TK;TV;)V", $PRIVATE, $method(IdentityHashMap, putForCreate, void, Object$*, Object$*), "java.io.StreamCorruptedException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(IdentityHashMap, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(IdentityHashMap, remove, $Object*, Object$*)},
	{"removeMapping", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PRIVATE, $method(IdentityHashMap, removeMapping, bool, Object$*, Object$*)},
	{"replaceAll", "(Ljava/util/function/BiFunction;)V", "(Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)V", $PUBLIC, $virtualMethod(IdentityHashMap, replaceAll, void, $BiFunction*)},
	{"resize", "(I)Z", nullptr, $PRIVATE, $method(IdentityHashMap, resize, bool, int32_t)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap, size, int32_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unmaskNull", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $STATIC | $FINAL, $staticMethod(IdentityHashMap, unmaskNull, $Object*, Object$*)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<TV;>;", $PUBLIC, $virtualMethod(IdentityHashMap, values, $Collection*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(IdentityHashMap, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _IdentityHashMap_InnerClassesInfo_[] = {
	{"java.util.IdentityHashMap$EntrySpliterator", "java.util.IdentityHashMap", "EntrySpliterator", $STATIC | $FINAL},
	{"java.util.IdentityHashMap$ValueSpliterator", "java.util.IdentityHashMap", "ValueSpliterator", $STATIC | $FINAL},
	{"java.util.IdentityHashMap$KeySpliterator", "java.util.IdentityHashMap", "KeySpliterator", $STATIC | $FINAL},
	{"java.util.IdentityHashMap$IdentityHashMapSpliterator", "java.util.IdentityHashMap", "IdentityHashMapSpliterator", $STATIC},
	{"java.util.IdentityHashMap$EntrySet", "java.util.IdentityHashMap", "EntrySet", $PRIVATE},
	{"java.util.IdentityHashMap$Values", "java.util.IdentityHashMap", "Values", $PRIVATE},
	{"java.util.IdentityHashMap$KeySet", "java.util.IdentityHashMap", "KeySet", $PRIVATE},
	{"java.util.IdentityHashMap$EntryIterator", "java.util.IdentityHashMap", "EntryIterator", $PRIVATE},
	{"java.util.IdentityHashMap$ValueIterator", "java.util.IdentityHashMap", "ValueIterator", $PRIVATE},
	{"java.util.IdentityHashMap$KeyIterator", "java.util.IdentityHashMap", "KeyIterator", $PRIVATE},
	{"java.util.IdentityHashMap$IdentityHashMapIterator", "java.util.IdentityHashMap", "IdentityHashMapIterator", $PRIVATE | $ABSTRACT},
	{}
};

$ClassInfo _IdentityHashMap_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.IdentityHashMap",
	"java.util.AbstractMap",
	"java.io.Serializable,java.lang.Cloneable",
	_IdentityHashMap_FieldInfo_,
	_IdentityHashMap_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/AbstractMap<TK;TV;>;Ljava/util/Map<TK;TV;>;Ljava/io/Serializable;Ljava/lang/Cloneable;",
	nullptr,
	_IdentityHashMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.IdentityHashMap$EntrySpliterator,java.util.IdentityHashMap$ValueSpliterator,java.util.IdentityHashMap$KeySpliterator,java.util.IdentityHashMap$IdentityHashMapSpliterator,java.util.IdentityHashMap$EntrySet,java.util.IdentityHashMap$Values,java.util.IdentityHashMap$KeySet,java.util.IdentityHashMap$EntryIterator,java.util.IdentityHashMap$EntryIterator$Entry,java.util.IdentityHashMap$ValueIterator,java.util.IdentityHashMap$KeyIterator,java.util.IdentityHashMap$IdentityHashMapIterator"
};

$Object* allocate$IdentityHashMap($Class* clazz) {
	return $of($alloc(IdentityHashMap));
}

$String* IdentityHashMap::toString() {
	 return this->$AbstractMap::toString();
}

void IdentityHashMap::finalize() {
	this->$AbstractMap::finalize();
}

$Object* IdentityHashMap::NULL_KEY = nullptr;

$Object* IdentityHashMap::maskNull(Object$* key) {
	$init(IdentityHashMap);
	return $of((key == nullptr ? IdentityHashMap::NULL_KEY : $of(key)));
}

$Object* IdentityHashMap::unmaskNull(Object$* key) {
	$init(IdentityHashMap);
	return $of(($equals(key, IdentityHashMap::NULL_KEY) ? ($Object*)nullptr : $of(key)));
}

void IdentityHashMap::init$() {
	$AbstractMap::init$();
	init(IdentityHashMap::DEFAULT_CAPACITY);
}

void IdentityHashMap::init$(int32_t expectedMaxSize) {
	$useLocalCurrentObjectStackCache();
	$AbstractMap::init$();
	if (expectedMaxSize < 0) {
		$throwNew($IllegalArgumentException, $$str({"expectedMaxSize is negative: "_s, $$str(expectedMaxSize)}));
	}
	init(capacity(expectedMaxSize));
}

int32_t IdentityHashMap::capacity(int32_t expectedMaxSize) {
	$init(IdentityHashMap);
	return (expectedMaxSize > IdentityHashMap::MAXIMUM_CAPACITY / 3) ? IdentityHashMap::MAXIMUM_CAPACITY : (expectedMaxSize <= 2 * IdentityHashMap::MINIMUM_CAPACITY / 3) ? IdentityHashMap::MINIMUM_CAPACITY : $Integer::highestOneBit(expectedMaxSize + (expectedMaxSize << 1));
}

void IdentityHashMap::init(int32_t initCapacity) {
	$set(this, table, $new($ObjectArray, 2 * initCapacity));
}

void IdentityHashMap::init$($Map* m) {
	IdentityHashMap::init$($cast(int32_t, ((1 + $nc(m)->size()) * 1.1)));
	putAll(m);
}

int32_t IdentityHashMap::size() {
	return this->size$;
}

bool IdentityHashMap::isEmpty() {
	return this->size$ == 0;
}

int32_t IdentityHashMap::hash(Object$* x, int32_t length) {
	$init(IdentityHashMap);
	int32_t h = $System::identityHashCode(x);
	return (int32_t)(((h << 1) - (h << 8)) & (uint32_t)(length - 1));
}

int32_t IdentityHashMap::nextKeyIndex(int32_t i, int32_t len) {
	$init(IdentityHashMap);
	return (i + 2 < len ? i + 2 : 0);
}

$Object* IdentityHashMap::get(Object$* key) {
	$useLocalCurrentObjectStackCache();
	$var($Object, k, maskNull(key));
	$var($ObjectArray, tab, this->table);
	int32_t len = $nc(tab)->length;
	int32_t i = hash(k, len);
	while (true) {
		$var($Object0, item, tab->get(i));
		if ($equals(item, k)) {
			return $of(tab->get(i + 1));
		}
		if (item == nullptr) {
			return $of(nullptr);
		}
		i = nextKeyIndex(i, len);
	}
}

bool IdentityHashMap::containsKey(Object$* key) {
	$useLocalCurrentObjectStackCache();
	$var($Object, k, maskNull(key));
	$var($ObjectArray, tab, this->table);
	int32_t len = $nc(tab)->length;
	int32_t i = hash(k, len);
	while (true) {
		$var($Object0, item, tab->get(i));
		if ($equals(item, k)) {
			return true;
		}
		if (item == nullptr) {
			return false;
		}
		i = nextKeyIndex(i, len);
	}
}

bool IdentityHashMap::containsValue(Object$* value) {
	$var($ObjectArray, tab, this->table);
	for (int32_t i = 1; i < $nc(tab)->length; i += 2) {
		if ($equals(tab->get(i), value) && tab->get(i - 1) != nullptr) {
			return true;
		}
	}
	return false;
}

bool IdentityHashMap::containsMapping(Object$* key, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$var($Object, k, maskNull(key));
	$var($ObjectArray, tab, this->table);
	int32_t len = $nc(tab)->length;
	int32_t i = hash(k, len);
	while (true) {
		$var($Object0, item, tab->get(i));
		if ($equals(item, k)) {
			return $equals(tab->get(i + 1), value);
		}
		if (item == nullptr) {
			return false;
		}
		i = nextKeyIndex(i, len);
	}
}

$Object* IdentityHashMap::put(Object$* key, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$var($Object, k, maskNull(key));
	bool retryAfterResize$continue = false;
	for (;;) {
		$var($ObjectArray, tab, this->table);
		int32_t len = $nc(tab)->length;
		int32_t i = hash(k, len);
		{
			$var($Object, item, nullptr);
			for (; ($assign(item, tab->get(i))) != nullptr; i = nextKeyIndex(i, len)) {
				if ($equals(item, k)) {
					$var($Object, oldValue, tab->get(i + 1));
					tab->set(i + 1, value);
					return $of(oldValue);
				}
			}
		}
		int32_t s = this->size$ + 1;
		if (s + (s << 1) > len && resize(len)) {
			continue;
		}
		++this->modCount;
		tab->set(i, k);
		tab->set(i + 1, value);
		this->size$ = s;
		return $of(nullptr);
	}
}

bool IdentityHashMap::resize(int32_t newCapacity) {
	$useLocalCurrentObjectStackCache();
	int32_t newLength = newCapacity * 2;
	$var($ObjectArray, oldTable, this->table);
	int32_t oldLength = $nc(oldTable)->length;
	if (oldLength == 2 * IdentityHashMap::MAXIMUM_CAPACITY) {
		if (this->size$ == IdentityHashMap::MAXIMUM_CAPACITY - 1) {
			$throwNew($IllegalStateException, "Capacity exhausted."_s);
		}
		return false;
	}
	if (oldLength >= newLength) {
		return false;
	}
	$var($ObjectArray, newTable, $new($ObjectArray, newLength));
	for (int32_t j = 0; j < oldLength; j += 2) {
		$var($Object0, key, oldTable->get(j));
		if (key != nullptr) {
			$var($Object0, value, oldTable->get(j + 1));
			oldTable->set(j, nullptr);
			oldTable->set(j + 1, nullptr);
			int32_t i = hash(key, newLength);
			while (newTable->get(i) != nullptr) {
				i = nextKeyIndex(i, newLength);
			}
			newTable->set(i, key);
			newTable->set(i + 1, value);
		}
	}
	$set(this, table, newTable);
	return true;
}

void IdentityHashMap::putAll($Map* m) {
	$useLocalCurrentObjectStackCache();
	int32_t n = $nc(m)->size();
	if (n == 0) {
		return;
	}
	if (n > this->size$) {
		resize(capacity(n));
	}
	{
		$var($Iterator, i$, $nc($(m->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			$var($Object, var$0, $nc(e)->getKey());
			put(var$0, $(e->getValue()));
		}
	}
}

$Object* IdentityHashMap::remove(Object$* key) {
	$useLocalCurrentObjectStackCache();
	$var($Object, k, maskNull(key));
	$var($ObjectArray, tab, this->table);
	int32_t len = $nc(tab)->length;
	int32_t i = hash(k, len);
	while (true) {
		$var($Object0, item, tab->get(i));
		if ($equals(item, k)) {
			++this->modCount;
			--this->size$;
			$var($Object, oldValue, tab->get(i + 1));
			tab->set(i + 1, nullptr);
			tab->set(i, nullptr);
			closeDeletion(i);
			return $of(oldValue);
		}
		if (item == nullptr) {
			return $of(nullptr);
		}
		i = nextKeyIndex(i, len);
	}
}

bool IdentityHashMap::removeMapping(Object$* key, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$var($Object, k, maskNull(key));
	$var($ObjectArray, tab, this->table);
	int32_t len = $nc(tab)->length;
	int32_t i = hash(k, len);
	while (true) {
		$var($Object0, item, tab->get(i));
		if ($equals(item, k)) {
			if (!$equals(tab->get(i + 1), value)) {
				return false;
			}
			++this->modCount;
			--this->size$;
			tab->set(i, nullptr);
			tab->set(i + 1, nullptr);
			closeDeletion(i);
			return true;
		}
		if (item == nullptr) {
			return false;
		}
		i = nextKeyIndex(i, len);
	}
}

void IdentityHashMap::closeDeletion(int32_t d) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, tab, this->table);
	int32_t len = $nc(tab)->length;
	$var($Object, item, nullptr);
	for (int32_t i = nextKeyIndex(d, len); ($assign(item, tab->get(i))) != nullptr; i = nextKeyIndex(i, len)) {
		int32_t r = hash(item, len);
		if ((i < r && (r <= d || d <= i)) || (r <= d && d <= i)) {
			tab->set(d, item);
			tab->set(d + 1, tab->get(i + 1));
			tab->set(i, nullptr);
			tab->set(i + 1, nullptr);
			d = i;
		}
	}
}

void IdentityHashMap::clear() {
	++this->modCount;
	$var($ObjectArray, tab, this->table);
	for (int32_t i = 0; i < $nc(tab)->length; ++i) {
		tab->set(i, nullptr);
	}
	this->size$ = 0;
}

bool IdentityHashMap::equals(Object$* o) {
	$useLocalCurrentObjectStackCache();
	{
		$var(IdentityHashMap, m, nullptr);
		$var($Map, m_1, nullptr);
		if ($equals(o, this)) {
			return true;
		} else {
			bool var$1 = $instanceOf(IdentityHashMap, o);
			if (var$1) {
				$assign(m, $cast(IdentityHashMap, o));
				var$1 = true;
			}
			if (var$1) {
				if ($nc(m)->size() != this->size$) {
					return false;
				}
				$var($ObjectArray, tab, $nc(m)->table);
				for (int32_t i = 0; i < $nc(tab)->length; i += 2) {
					$var($Object0, k, tab->get(i));
					if (k != nullptr && !containsMapping(k, tab->get(i + 1))) {
						return false;
					}
				}
				return true;
			} else {
				bool var$3 = $instanceOf($Map, o);
				if (var$3) {
					$assign(m_1, $cast($Map, o));
					var$3 = true;
				}
				if (var$3) {
					return $nc($(entrySet()))->equals($($nc(m_1)->entrySet()));
				} else {
					return false;
				}
			}
		}
	}
}

int32_t IdentityHashMap::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t result = 0;
	$var($ObjectArray, tab, this->table);
	for (int32_t i = 0; i < $nc(tab)->length; i += 2) {
		$var($Object0, key, tab->get(i));
		if (key != nullptr) {
			$var($Object, k, unmaskNull(key));
			int32_t var$0 = $System::identityHashCode(k);
			result += var$0 ^ $System::identityHashCode(tab->get(i + 1));
		}
	}
	return result;
}

$Object* IdentityHashMap::clone() {
	try {
		$var(IdentityHashMap, m, $cast(IdentityHashMap, $AbstractMap::clone()));
		$set($nc(m), entrySet$, nullptr);
		$set(m, table, $cast($ObjectArray, $nc(this->table)->clone()));
		return $of(m);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$Set* IdentityHashMap::keySet() {
	$var($Set, ks, this->$AbstractMap::keySet$);
	if (ks == nullptr) {
		$assign(ks, $new($IdentityHashMap$KeySet, this));
		$set(this, keySet$, ks);
	}
	return ks;
}

$Collection* IdentityHashMap::values() {
	$var($Collection, vs, this->$AbstractMap::values$);
	if (vs == nullptr) {
		$assign(vs, $new($IdentityHashMap$Values, this));
		$set(this, values$, vs);
	}
	return vs;
}

$Set* IdentityHashMap::entrySet() {
	$var($Set, es, this->entrySet$);
	if (es != nullptr) {
		return es;
	} else {
		return $set(this, entrySet$, $new($IdentityHashMap$EntrySet, this));
	}
}

void IdentityHashMap::writeObject($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultWriteObject();
	s->writeInt(this->size$);
	$var($ObjectArray, tab, this->table);
	for (int32_t i = 0; i < $nc(tab)->length; i += 2) {
		$var($Object0, key, tab->get(i));
		if (key != nullptr) {
			s->writeObject($(unmaskNull(key)));
			s->writeObject(tab->get(i + 1));
		}
	}
}

void IdentityHashMap::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	int32_t size = s->readInt();
	if (size < 0) {
		$throwNew($StreamCorruptedException, $$str({"Illegal mappings count: "_s, $$str(size)}));
	}
	int32_t cap = capacity(size);
	$load($ObjectArray);
	$nc($($SharedSecrets::getJavaObjectInputStreamAccess()))->checkArray(s, $getClass($ObjectArray), cap);
	init(cap);
	for (int32_t i = 0; i < size; ++i) {
		$var($Object, key, s->readObject());
		$var($Object, value, s->readObject());
		putForCreate(key, value);
	}
}

void IdentityHashMap::putForCreate(Object$* key, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$var($Object, k, maskNull(key));
	$var($ObjectArray, tab, this->table);
	int32_t len = $nc(tab)->length;
	int32_t i = hash(k, len);
	$var($Object, item, nullptr);
	while (($assign(item, tab->get(i))) != nullptr) {
		if ($equals(item, k)) {
			$throwNew($StreamCorruptedException);
		}
		i = nextKeyIndex(i, len);
	}
	tab->set(i, k);
	tab->set(i + 1, value);
}

void IdentityHashMap::forEach($BiConsumer* action) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(action);
	int32_t expectedModCount = this->modCount;
	$var($ObjectArray, t, this->table);
	for (int32_t index = 0; index < $nc(t)->length; index += 2) {
		$var($Object0, k, t->get(index));
		if (k != nullptr) {
			action->accept($(unmaskNull(k)), t->get(index + 1));
		}
		if (this->modCount != expectedModCount) {
			$throwNew($ConcurrentModificationException);
		}
	}
}

void IdentityHashMap::replaceAll($BiFunction* function) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(function);
	int32_t expectedModCount = this->modCount;
	$var($ObjectArray, t, this->table);
	for (int32_t index = 0; index < $nc(t)->length; index += 2) {
		$var($Object0, k, t->get(index));
		if (k != nullptr) {
			t->set(index + 1, $(function->apply($(unmaskNull(k)), t->get(index + 1))));
		}
		if (this->modCount != expectedModCount) {
			$throwNew($ConcurrentModificationException);
		}
	}
}

void clinit$IdentityHashMap($Class* class$) {
	$assignStatic(IdentityHashMap::NULL_KEY, $new($Object));
}

IdentityHashMap::IdentityHashMap() {
}

$Class* IdentityHashMap::load$($String* name, bool initialize) {
	$loadClass(IdentityHashMap, name, initialize, &_IdentityHashMap_ClassInfo_, clinit$IdentityHashMap, allocate$IdentityHashMap);
	return class$;
}

$Class* IdentityHashMap::class$ = nullptr;

	} // util
} // java