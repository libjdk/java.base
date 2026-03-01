#include <java/util/WeakHashMap.h>

#include <java/lang/Math.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/util/AbstractMap.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/WeakHashMap$Entry.h>
#include <java/util/WeakHashMap$EntrySet.h>
#include <java/util/WeakHashMap$KeySet.h>
#include <java/util/WeakHashMap$Values.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <jcpp.h>

#undef DEFAULT_INITIAL_CAPACITY
#undef DEFAULT_LOAD_FACTOR
#undef MAXIMUM_CAPACITY
#undef MAX_VALUE
#undef NULL_KEY

using $WeakHashMap$EntryArray = $Array<::java::util::WeakHashMap$Entry>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $AbstractMap = ::java::util::AbstractMap;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $WeakHashMap$Entry = ::java::util::WeakHashMap$Entry;
using $WeakHashMap$EntrySet = ::java::util::WeakHashMap$EntrySet;
using $WeakHashMap$KeySet = ::java::util::WeakHashMap$KeySet;
using $WeakHashMap$Values = ::java::util::WeakHashMap$Values;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;

namespace java {
	namespace util {

$FieldInfo _WeakHashMap_FieldInfo_[] = {
	{"DEFAULT_INITIAL_CAPACITY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WeakHashMap, DEFAULT_INITIAL_CAPACITY)},
	{"MAXIMUM_CAPACITY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WeakHashMap, MAXIMUM_CAPACITY)},
	{"DEFAULT_LOAD_FACTOR", "F", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WeakHashMap, DEFAULT_LOAD_FACTOR)},
	{"table", "[Ljava/util/WeakHashMap$Entry;", "[Ljava/util/WeakHashMap$Entry<TK;TV;>;", 0, $field(WeakHashMap, table)},
	{"size", "I", nullptr, $PRIVATE, $field(WeakHashMap, size$)},
	{"threshold", "I", nullptr, $PRIVATE, $field(WeakHashMap, threshold)},
	{"loadFactor", "F", nullptr, $PRIVATE | $FINAL, $field(WeakHashMap, loadFactor)},
	{"queue", "Ljava/lang/ref/ReferenceQueue;", "Ljava/lang/ref/ReferenceQueue<Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(WeakHashMap, queue)},
	{"modCount", "I", nullptr, 0, $field(WeakHashMap, modCount)},
	{"NULL_KEY", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WeakHashMap, NULL_KEY)},
	{"entrySet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PRIVATE | $TRANSIENT, $field(WeakHashMap, entrySet$)},
	{}
};

$MethodInfo _WeakHashMap_MethodInfo_[] = {
	{"<init>", "(IF)V", nullptr, $PUBLIC, $method(WeakHashMap, init$, void, int32_t, float)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(WeakHashMap, init$, void, int32_t)},
	{"<init>", "()V", nullptr, $PUBLIC, $method(WeakHashMap, init$, void)},
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<+TK;+TV;>;)V", $PUBLIC, $method(WeakHashMap, init$, void, $Map*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(WeakHashMap, clear, void)},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(WeakHashMap, containsKey, bool, Object$*)},
	{"containsNullValue", "()Z", nullptr, $PRIVATE, $method(WeakHashMap, containsNullValue, bool)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(WeakHashMap, containsValue, bool, Object$*)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(WeakHashMap, entrySet, $Set*)},
	{"expungeStaleEntries", "()V", nullptr, $PRIVATE, $method(WeakHashMap, expungeStaleEntries, void)},
	{"forEach", "(Ljava/util/function/BiConsumer;)V", "(Ljava/util/function/BiConsumer<-TK;-TV;>;)V", $PUBLIC, $virtualMethod(WeakHashMap, forEach, void, $BiConsumer*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(WeakHashMap, get, $Object*, Object$*)},
	{"getEntry", "(Ljava/lang/Object;)Ljava/util/WeakHashMap$Entry;", "(Ljava/lang/Object;)Ljava/util/WeakHashMap$Entry<TK;TV;>;", 0, $virtualMethod(WeakHashMap, getEntry, $WeakHashMap$Entry*, Object$*)},
	{"getTable", "()[Ljava/util/WeakHashMap$Entry;", "()[Ljava/util/WeakHashMap$Entry<TK;TV;>;", $PRIVATE, $method(WeakHashMap, getTable, $WeakHashMap$EntryArray*)},
	{"hash", "(Ljava/lang/Object;)I", nullptr, $FINAL, $method(WeakHashMap, hash, int32_t, Object$*)},
	{"indexFor", "(II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(WeakHashMap, indexFor, int32_t, int32_t, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(WeakHashMap, isEmpty, bool)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<TK;>;", $PUBLIC, $virtualMethod(WeakHashMap, keySet, $Set*)},
	{"maskNull", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticMethod(WeakHashMap, maskNull, $Object*, Object$*)},
	{"matchesKey", "(Ljava/util/WeakHashMap$Entry;Ljava/lang/Object;)Z", "(Ljava/util/WeakHashMap$Entry<TK;TV;>;Ljava/lang/Object;)Z", $PRIVATE, $method(WeakHashMap, matchesKey, bool, $WeakHashMap$Entry*, Object$*)},
	{"newTable", "(I)[Ljava/util/WeakHashMap$Entry;", "(I)[Ljava/util/WeakHashMap$Entry<TK;TV;>;", $PRIVATE, $method(WeakHashMap, newTable, $WeakHashMap$EntryArray*, int32_t)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(WeakHashMap, put, $Object*, Object$*, Object$*)},
	{"putAll", "(Ljava/util/Map;)V", "(Ljava/util/Map<+TK;+TV;>;)V", $PUBLIC, $virtualMethod(WeakHashMap, putAll, void, $Map*)},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(WeakHashMap, remove, $Object*, Object$*)},
	{"removeMapping", "(Ljava/lang/Object;)Z", nullptr, 0, $virtualMethod(WeakHashMap, removeMapping, bool, Object$*)},
	{"replaceAll", "(Ljava/util/function/BiFunction;)V", "(Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)V", $PUBLIC, $virtualMethod(WeakHashMap, replaceAll, void, $BiFunction*)},
	{"resize", "(I)V", nullptr, 0, $virtualMethod(WeakHashMap, resize, void, int32_t)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(WeakHashMap, size, int32_t)},
	{"transfer", "([Ljava/util/WeakHashMap$Entry;[Ljava/util/WeakHashMap$Entry;)V", "([Ljava/util/WeakHashMap$Entry<TK;TV;>;[Ljava/util/WeakHashMap$Entry<TK;TV;>;)V", $PRIVATE, $method(WeakHashMap, transfer, void, $WeakHashMap$EntryArray*, $WeakHashMap$EntryArray*)},
	{"unmaskNull", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(WeakHashMap, unmaskNull, $Object*, Object$*)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<TV;>;", $PUBLIC, $virtualMethod(WeakHashMap, values, $Collection*)},
	{}
};

$InnerClassInfo _WeakHashMap_InnerClassesInfo_[] = {
	{"java.util.WeakHashMap$EntrySpliterator", "java.util.WeakHashMap", "EntrySpliterator", $STATIC | $FINAL},
	{"java.util.WeakHashMap$ValueSpliterator", "java.util.WeakHashMap", "ValueSpliterator", $STATIC | $FINAL},
	{"java.util.WeakHashMap$KeySpliterator", "java.util.WeakHashMap", "KeySpliterator", $STATIC | $FINAL},
	{"java.util.WeakHashMap$WeakHashMapSpliterator", "java.util.WeakHashMap", "WeakHashMapSpliterator", $STATIC},
	{"java.util.WeakHashMap$EntrySet", "java.util.WeakHashMap", "EntrySet", $PRIVATE},
	{"java.util.WeakHashMap$Values", "java.util.WeakHashMap", "Values", $PRIVATE},
	{"java.util.WeakHashMap$KeySet", "java.util.WeakHashMap", "KeySet", $PRIVATE},
	{"java.util.WeakHashMap$EntryIterator", "java.util.WeakHashMap", "EntryIterator", $PRIVATE},
	{"java.util.WeakHashMap$KeyIterator", "java.util.WeakHashMap", "KeyIterator", $PRIVATE},
	{"java.util.WeakHashMap$ValueIterator", "java.util.WeakHashMap", "ValueIterator", $PRIVATE},
	{"java.util.WeakHashMap$HashIterator", "java.util.WeakHashMap", "HashIterator", $PRIVATE | $ABSTRACT},
	{"java.util.WeakHashMap$Entry", "java.util.WeakHashMap", "Entry", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _WeakHashMap_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.WeakHashMap",
	"java.util.AbstractMap",
	nullptr,
	_WeakHashMap_FieldInfo_,
	_WeakHashMap_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/AbstractMap<TK;TV;>;Ljava/util/Map<TK;TV;>;",
	nullptr,
	_WeakHashMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.WeakHashMap$EntrySpliterator,java.util.WeakHashMap$ValueSpliterator,java.util.WeakHashMap$KeySpliterator,java.util.WeakHashMap$WeakHashMapSpliterator,java.util.WeakHashMap$EntrySet,java.util.WeakHashMap$Values,java.util.WeakHashMap$KeySet,java.util.WeakHashMap$EntryIterator,java.util.WeakHashMap$KeyIterator,java.util.WeakHashMap$ValueIterator,java.util.WeakHashMap$HashIterator,java.util.WeakHashMap$Entry"
};

$Object* allocate$WeakHashMap($Class* clazz) {
	return $of($alloc(WeakHashMap));
}

float WeakHashMap::DEFAULT_LOAD_FACTOR = 0.0;
$Object* WeakHashMap::NULL_KEY = nullptr;

$WeakHashMap$EntryArray* WeakHashMap::newTable(int32_t n) {
	return $new($WeakHashMap$EntryArray, n);
}

void WeakHashMap::init$(int32_t initialCapacity, float loadFactor) {
	$useLocalCurrentObjectStackCache();
	$AbstractMap::init$();
	$set(this, queue, $new($ReferenceQueue));
	if (initialCapacity < 0) {
		$throwNew($IllegalArgumentException, $$str({"Illegal Initial Capacity: "_s, $$str(initialCapacity)}));
	}
	if (initialCapacity > WeakHashMap::MAXIMUM_CAPACITY) {
		initialCapacity = WeakHashMap::MAXIMUM_CAPACITY;
	}
	if (loadFactor <= 0 || $Float::isNaN(loadFactor)) {
		$throwNew($IllegalArgumentException, $$str({"Illegal Load factor: "_s, $$str(loadFactor)}));
	}
	int32_t capacity = 1;
	while (capacity < initialCapacity) {
		capacity <<= 1;
	}
	$set(this, table, newTable(capacity));
	this->loadFactor = loadFactor;
	this->threshold = $cast(int32_t, (capacity * loadFactor));
}

void WeakHashMap::init$(int32_t initialCapacity) {
	WeakHashMap::init$(initialCapacity, WeakHashMap::DEFAULT_LOAD_FACTOR);
}

void WeakHashMap::init$() {
	WeakHashMap::init$(WeakHashMap::DEFAULT_INITIAL_CAPACITY, WeakHashMap::DEFAULT_LOAD_FACTOR);
}

void WeakHashMap::init$($Map* m) {
	WeakHashMap::init$($Math::max($cast(int32_t, ($div((float)$nc(m)->size(), WeakHashMap::DEFAULT_LOAD_FACTOR) + 1.0f)), WeakHashMap::DEFAULT_INITIAL_CAPACITY), WeakHashMap::DEFAULT_LOAD_FACTOR);
	putAll(m);
}

$Object* WeakHashMap::maskNull(Object$* key) {
	$init(WeakHashMap);
	return $of((key == nullptr) ? WeakHashMap::NULL_KEY : $of(key));
}

$Object* WeakHashMap::unmaskNull(Object$* key) {
	$init(WeakHashMap);
	return $of(($equals(key, WeakHashMap::NULL_KEY)) ? ($Object*)nullptr : $of(key));
}

bool WeakHashMap::matchesKey($WeakHashMap$Entry* e, Object$* key) {
	if ($nc(e)->refersTo(key)) {
		return true;
	}
	$var($Object, k, $nc(e)->get());
	return k != nullptr && $nc($of(key))->equals(k);
}

int32_t WeakHashMap::hash(Object$* k) {
	int32_t h = $nc($of(k))->hashCode();
	h ^= ((int32_t)((uint32_t)h >> 20)) ^ ((int32_t)((uint32_t)h >> 12));
	return (h ^ ((int32_t)((uint32_t)h >> 7))) ^ ((int32_t)((uint32_t)h >> 4));
}

int32_t WeakHashMap::indexFor(int32_t h, int32_t length) {
	$init(WeakHashMap);
	return (int32_t)(h & (uint32_t)(length - 1));
}

void WeakHashMap::expungeStaleEntries() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Object, x, nullptr);
		for (; ($assign(x, $nc(this->queue)->poll())) != nullptr;) {
			$synchronized(this->queue) {
				$var($WeakHashMap$Entry, e, $cast($WeakHashMap$Entry, x));
				int32_t i = indexFor($nc(e)->hash, $nc(this->table)->length);
				$var($WeakHashMap$Entry, prev, $nc(this->table)->get(i));
				$var($WeakHashMap$Entry, p, prev);
				while (p != nullptr) {
					$var($WeakHashMap$Entry, next, p->next);
					if (p == e) {
						if (prev == e) {
							$nc(this->table)->set(i, next);
						} else {
							$set($nc(prev), next, next);
						}
						$set($nc(e), value, nullptr);
						--this->size$;
						break;
					}
					$assign(prev, p);
					$assign(p, next);
				}
			}
		}
	}
}

$WeakHashMap$EntryArray* WeakHashMap::getTable() {
	expungeStaleEntries();
	return this->table;
}

int32_t WeakHashMap::size() {
	if (this->size$ == 0) {
		return 0;
	}
	expungeStaleEntries();
	return this->size$;
}

bool WeakHashMap::isEmpty() {
	return size() == 0;
}

$Object* WeakHashMap::get(Object$* key) {
	$useLocalCurrentObjectStackCache();
	$var($Object, k, maskNull(key));
	int32_t h = hash(k);
	$var($WeakHashMap$EntryArray, tab, getTable());
	int32_t index = indexFor(h, $nc(tab)->length);
	$var($WeakHashMap$Entry, e, $nc(tab)->get(index));
	while (e != nullptr) {
		if (e->hash == h && matchesKey(e, k)) {
			return $of(e->value);
		}
		$assign(e, e->next);
	}
	return $of(nullptr);
}

bool WeakHashMap::containsKey(Object$* key) {
	return getEntry(key) != nullptr;
}

$WeakHashMap$Entry* WeakHashMap::getEntry(Object$* key) {
	$useLocalCurrentObjectStackCache();
	$var($Object, k, maskNull(key));
	int32_t h = hash(k);
	$var($WeakHashMap$EntryArray, tab, getTable());
	int32_t index = indexFor(h, $nc(tab)->length);
	$var($WeakHashMap$Entry, e, $nc(tab)->get(index));
	while (e != nullptr && !(e->hash == h && matchesKey(e, k))) {
		$assign(e, e->next);
	}
	return e;
}

$Object* WeakHashMap::put(Object$* key, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$var($Object, k, maskNull(key));
	int32_t h = hash(k);
	$var($WeakHashMap$EntryArray, tab, getTable());
	int32_t i = indexFor(h, $nc(tab)->length);
	{
		$var($WeakHashMap$Entry, e, $nc(tab)->get(i));
		for (; e != nullptr; $assign(e, $nc(e)->next)) {
			if (h == e->hash && matchesKey(e, k)) {
				$var($Object, oldValue, e->value);
				if (!$equals(value, oldValue)) {
					$set(e, value, value);
				}
				return $of(oldValue);
			}
		}
	}
	++this->modCount;
	$var($WeakHashMap$Entry, e, tab->get(i));
	tab->set(i, $$new($WeakHashMap$Entry, k, value, this->queue, h, e));
	if (++this->size$ >= this->threshold) {
		resize(tab->length * 2);
	}
	return $of(nullptr);
}

void WeakHashMap::resize(int32_t newCapacity) {
	$useLocalCurrentObjectStackCache();
	$var($WeakHashMap$EntryArray, oldTable, getTable());
	int32_t oldCapacity = $nc(oldTable)->length;
	if (oldCapacity == WeakHashMap::MAXIMUM_CAPACITY) {
		this->threshold = $Integer::MAX_VALUE;
		return;
	}
	$var($WeakHashMap$EntryArray, newTable, this->newTable(newCapacity));
	transfer(oldTable, newTable);
	$set(this, table, newTable);
	if (this->size$ >= this->threshold / 2) {
		this->threshold = $cast(int32_t, (newCapacity * this->loadFactor));
	} else {
		expungeStaleEntries();
		transfer(newTable, oldTable);
		$set(this, table, oldTable);
	}
}

void WeakHashMap::transfer($WeakHashMap$EntryArray* src, $WeakHashMap$EntryArray* dest) {
	$useLocalCurrentObjectStackCache();
	for (int32_t j = 0; j < $nc(src)->length; ++j) {
		$var($WeakHashMap$Entry, e, src->get(j));
		src->set(j, nullptr);
		while (e != nullptr) {
			$var($WeakHashMap$Entry, next, e->next);
			if (e->refersTo(nullptr)) {
				$set(e, next, nullptr);
				$set(e, value, nullptr);
				--this->size$;
			} else {
				int32_t i = indexFor(e->hash, $nc(dest)->length);
				$set(e, next, $nc(dest)->get(i));
				dest->set(i, e);
			}
			$assign(e, next);
		}
	}
}

void WeakHashMap::putAll($Map* m) {
	$useLocalCurrentObjectStackCache();
	int32_t numKeysToBeAdded = $nc(m)->size();
	if (numKeysToBeAdded == 0) {
		return;
	}
	if (numKeysToBeAdded > this->threshold) {
		int32_t targetCapacity = $cast(int32_t, (numKeysToBeAdded / this->loadFactor + 1));
		if (targetCapacity > WeakHashMap::MAXIMUM_CAPACITY) {
			targetCapacity = WeakHashMap::MAXIMUM_CAPACITY;
		}
		int32_t newCapacity = $nc(this->table)->length;
		while (newCapacity < targetCapacity) {
			newCapacity <<= 1;
		}
		if (newCapacity > $nc(this->table)->length) {
			resize(newCapacity);
		}
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

$Object* WeakHashMap::remove(Object$* key) {
	$useLocalCurrentObjectStackCache();
	$var($Object, k, maskNull(key));
	int32_t h = hash(k);
	$var($WeakHashMap$EntryArray, tab, getTable());
	int32_t i = indexFor(h, $nc(tab)->length);
	$var($WeakHashMap$Entry, prev, $nc(tab)->get(i));
	$var($WeakHashMap$Entry, e, prev);
	while (e != nullptr) {
		$var($WeakHashMap$Entry, next, e->next);
		if (h == e->hash && matchesKey(e, k)) {
			++this->modCount;
			--this->size$;
			if (prev == e) {
				tab->set(i, next);
			} else {
				$set($nc(prev), next, next);
			}
			return $of(e->value);
		}
		$assign(prev, e);
		$assign(e, next);
	}
	return $of(nullptr);
}

bool WeakHashMap::removeMapping(Object$* o) {
	$useLocalCurrentObjectStackCache();
	$var($Map$Entry, entry, nullptr);
	bool var$0 = $instanceOf($Map$Entry, o);
	if (var$0) {
		$assign(entry, $cast($Map$Entry, o));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	$var($WeakHashMap$EntryArray, tab, getTable());
	$var($Object, k, maskNull($($nc(entry)->getKey())));
	int32_t h = hash(k);
	int32_t i = indexFor(h, $nc(tab)->length);
	$var($WeakHashMap$Entry, prev, $nc(tab)->get(i));
	$var($WeakHashMap$Entry, e, prev);
	while (e != nullptr) {
		$var($WeakHashMap$Entry, next, e->next);
		if (h == e->hash && e->equals(entry)) {
			++this->modCount;
			--this->size$;
			if (prev == e) {
				tab->set(i, next);
			} else {
				$set($nc(prev), next, next);
			}
			return true;
		}
		$assign(prev, e);
		$assign(e, next);
	}
	return false;
}

void WeakHashMap::clear() {
	while ($nc(this->queue)->poll() != nullptr) {
	}
	++this->modCount;
	$Arrays::fill(this->table, ($Object*)nullptr);
	this->size$ = 0;
	while ($nc(this->queue)->poll() != nullptr) {
	}
}

bool WeakHashMap::containsValue(Object$* value) {
	$useLocalCurrentObjectStackCache();
	if (value == nullptr) {
		return containsNullValue();
	}
	$var($WeakHashMap$EntryArray, tab, getTable());
	for (int32_t i = $nc(tab)->length; i-- > 0;) {
		{
			$var($WeakHashMap$Entry, e, tab->get(i));
			for (; e != nullptr; $assign(e, $nc(e)->next)) {
				if ($nc($of(value))->equals(e->value)) {
					return true;
				}
			}
		}
	}
	return false;
}

bool WeakHashMap::containsNullValue() {
	$useLocalCurrentObjectStackCache();
	$var($WeakHashMap$EntryArray, tab, getTable());
	for (int32_t i = $nc(tab)->length; i-- > 0;) {
		{
			$var($WeakHashMap$Entry, e, tab->get(i));
			for (; e != nullptr; $assign(e, $nc(e)->next)) {
				if (e->value == nullptr) {
					return true;
				}
			}
		}
	}
	return false;
}

$Set* WeakHashMap::keySet() {
	$var($Set, ks, this->$AbstractMap::keySet$);
	if (ks == nullptr) {
		$assign(ks, $new($WeakHashMap$KeySet, this));
		$set(this, keySet$, ks);
	}
	return ks;
}

$Collection* WeakHashMap::values() {
	$var($Collection, vs, this->$AbstractMap::values$);
	if (vs == nullptr) {
		$assign(vs, $new($WeakHashMap$Values, this));
		$set(this, values$, vs);
	}
	return vs;
}

$Set* WeakHashMap::entrySet() {
	$var($Set, es, this->entrySet$);
	return es != nullptr ? es : ($set(this, entrySet$, $new($WeakHashMap$EntrySet, this)));
}

void WeakHashMap::forEach($BiConsumer* action) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(action);
	int32_t expectedModCount = this->modCount;
	$var($WeakHashMap$EntryArray, tab, getTable());
	{
		$var($WeakHashMap$EntryArray, arr$, tab);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($WeakHashMap$Entry, entry, arr$->get(i$));
			{
				while (entry != nullptr) {
					$var($Object, key, entry->get());
					if (key != nullptr) {
						action->accept($(WeakHashMap::unmaskNull(key)), entry->value);
					}
					$assign(entry, entry->next);
					if (expectedModCount != this->modCount) {
						$throwNew($ConcurrentModificationException);
					}
				}
			}
		}
	}
}

void WeakHashMap::replaceAll($BiFunction* function) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(function);
	int32_t expectedModCount = this->modCount;
	$var($WeakHashMap$EntryArray, tab, getTable());
	{
		$var($WeakHashMap$EntryArray, arr$, tab);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($WeakHashMap$Entry, entry, arr$->get(i$));
			{
				while (entry != nullptr) {
					$var($Object, key, entry->get());
					if (key != nullptr) {
						$set(entry, value, function->apply($(WeakHashMap::unmaskNull(key)), entry->value));
					}
					$assign(entry, entry->next);
					if (expectedModCount != this->modCount) {
						$throwNew($ConcurrentModificationException);
					}
				}
			}
		}
	}
}

void clinit$WeakHashMap($Class* class$) {
	WeakHashMap::DEFAULT_LOAD_FACTOR = 0.75f;
	$assignStatic(WeakHashMap::NULL_KEY, $new($Object));
}

WeakHashMap::WeakHashMap() {
}

$Class* WeakHashMap::load$($String* name, bool initialize) {
	$loadClass(WeakHashMap, name, initialize, &_WeakHashMap_ClassInfo_, clinit$WeakHashMap, allocate$WeakHashMap);
	return class$;
}

$Class* WeakHashMap::class$ = nullptr;

	} // util
} // java