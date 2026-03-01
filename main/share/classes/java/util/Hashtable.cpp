#include <java/util/Hashtable.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/StreamCorruptedException.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/Dictionary.h>
#include <java/util/Enumeration.h>
#include <java/util/Hashtable$Entry.h>
#include <java/util/Hashtable$EntrySet.h>
#include <java/util/Hashtable$Enumerator.h>
#include <java/util/Hashtable$KeySet.h>
#include <java/util/Hashtable$ValueCollection.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <jdk/internal/access/JavaObjectInputStreamAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef ENTRIES
#undef KEYS
#undef MAX_ARRAY_SIZE
#undef VALUES

using $Hashtable$EntryArray = $Array<::java::util::Hashtable$Entry>;
using $Map$EntryArray = $Array<::java::util::Map$Entry>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $StreamCorruptedException = ::java::io::StreamCorruptedException;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Void = ::java::lang::Void;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $Dictionary = ::java::util::Dictionary;
using $Enumeration = ::java::util::Enumeration;
using $Hashtable$Entry = ::java::util::Hashtable$Entry;
using $Hashtable$EntrySet = ::java::util::Hashtable$EntrySet;
using $Hashtable$Enumerator = ::java::util::Hashtable$Enumerator;
using $Hashtable$KeySet = ::java::util::Hashtable$KeySet;
using $Hashtable$ValueCollection = ::java::util::Hashtable$ValueCollection;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;
using $JavaObjectInputStreamAccess = ::jdk::internal::access::JavaObjectInputStreamAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace util {

$FieldInfo _Hashtable_FieldInfo_[] = {
	{"table", "[Ljava/util/Hashtable$Entry;", "[Ljava/util/Hashtable$Entry<**>;", $PRIVATE | $TRANSIENT, $field(Hashtable, table)},
	{"count", "I", nullptr, $PRIVATE | $TRANSIENT, $field(Hashtable, count)},
	{"threshold", "I", nullptr, $PRIVATE, $field(Hashtable, threshold)},
	{"loadFactor", "F", nullptr, $PRIVATE, $field(Hashtable, loadFactor)},
	{"modCount", "I", nullptr, $PRIVATE | $TRANSIENT, $field(Hashtable, modCount)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Hashtable, serialVersionUID)},
	{"MAX_ARRAY_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Hashtable, MAX_ARRAY_SIZE)},
	{"keySet", "Ljava/util/Set;", "Ljava/util/Set<TK;>;", $PRIVATE | $VOLATILE | $TRANSIENT, $field(Hashtable, keySet$)},
	{"entrySet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PRIVATE | $VOLATILE | $TRANSIENT, $field(Hashtable, entrySet$)},
	{"values", "Ljava/util/Collection;", "Ljava/util/Collection<TV;>;", $PRIVATE | $VOLATILE | $TRANSIENT, $field(Hashtable, values$)},
	{"KEYS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Hashtable, KEYS)},
	{"VALUES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Hashtable, VALUES)},
	{"ENTRIES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Hashtable, ENTRIES)},
	{}
};

$MethodInfo _Hashtable_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(IF)V", nullptr, $PUBLIC, $method(Hashtable, init$, void, int32_t, float)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(Hashtable, init$, void, int32_t)},
	{"<init>", "()V", nullptr, $PUBLIC, $method(Hashtable, init$, void)},
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<+TK;+TV;>;)V", $PUBLIC, $method(Hashtable, init$, void, $Map*)},
	{"<init>", "(Ljava/lang/Void;)V", nullptr, 0, $method(Hashtable, init$, void, $Void*)},
	{"addEntry", "(ILjava/lang/Object;Ljava/lang/Object;I)V", "(ITK;TV;I)V", $PRIVATE, $method(Hashtable, addEntry, void, int32_t, Object$*, Object$*, int32_t)},
	{"clear", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, clone, $Object*)},
	{"cloneHashtable", "()Ljava/util/Hashtable;", "()Ljava/util/Hashtable<**>;", $FINAL, $method(Hashtable, cloneHashtable, Hashtable*)},
	{"compute", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(TK;Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)TV;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, compute, $Object*, Object$*, $BiFunction*)},
	{"computeIfAbsent", "(Ljava/lang/Object;Ljava/util/function/Function;)Ljava/lang/Object;", "(TK;Ljava/util/function/Function<-TK;+TV;>;)TV;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, computeIfAbsent, $Object*, Object$*, $Function*)},
	{"computeIfPresent", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(TK;Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)TV;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, computeIfPresent, $Object*, Object$*, $BiFunction*)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, contains, bool, Object$*)},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, containsKey, bool, Object$*)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Hashtable, containsValue, bool, Object$*)},
	{"defaultWriteHashtable", "(Ljava/io/ObjectOutputStream;IF)V", nullptr, $FINAL, $method(Hashtable, defaultWriteHashtable, void, $ObjectOutputStream*, int32_t, float), "java.io.IOException"},
	{"elements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<TV;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, elements, $Enumeration*)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(Hashtable, entrySet, $Set*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, equals, bool, Object$*)},
	{"forEach", "(Ljava/util/function/BiConsumer;)V", "(Ljava/util/function/BiConsumer<-TK;-TV;>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, forEach, void, $BiConsumer*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, get, $Object*, Object$*)},
	{"getEnumeration", "(I)Ljava/util/Enumeration;", "<T:Ljava/lang/Object;>(I)Ljava/util/Enumeration<TT;>;", $PRIVATE, $method(Hashtable, getEnumeration, $Enumeration*, int32_t)},
	{"getIterator", "(I)Ljava/util/Iterator;", "<T:Ljava/lang/Object;>(I)Ljava/util/Iterator<TT;>;", $PRIVATE, $method(Hashtable, getIterator, $Iterator*, int32_t)},
	{"getOrDefault", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;TV;)TV;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, getOrDefault, $Object*, Object$*, Object$*)},
	{"hashCode", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, hashCode, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, isEmpty, bool)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<TK;>;", $PUBLIC, $virtualMethod(Hashtable, keySet, $Set*)},
	{"keys", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<TK;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, keys, $Enumeration*)},
	{"merge", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(TK;TV;Ljava/util/function/BiFunction<-TV;-TV;+TV;>;)TV;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, merge, $Object*, Object$*, Object$*, $BiFunction*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, put, $Object*, Object$*, Object$*)},
	{"putAll", "(Ljava/util/Map;)V", "(Ljava/util/Map<+TK;+TV;>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, putAll, void, $Map*)},
	{"putIfAbsent", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, putIfAbsent, $Object*, Object$*, Object$*)},
	{"readHashtable", "(Ljava/io/ObjectInputStream;)V", nullptr, 0, $virtualMethod(Hashtable, readHashtable, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(Hashtable, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"reconstitutionPut", "([Ljava/util/Hashtable$Entry;Ljava/lang/Object;Ljava/lang/Object;)V", "([Ljava/util/Hashtable$Entry<**>;TK;TV;)V", $PRIVATE, $method(Hashtable, reconstitutionPut, void, $Hashtable$EntryArray*, Object$*, Object$*), "java.io.StreamCorruptedException"},
	{"rehash", "()V", nullptr, $PROTECTED, $virtualMethod(Hashtable, rehash, void)},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, remove, $Object*, Object$*)},
	{"remove", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, remove, bool, Object$*, Object$*)},
	{"replace", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z", "(TK;TV;TV;)Z", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, replace, bool, Object$*, Object$*, Object$*)},
	{"replace", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, replace, $Object*, Object$*, Object$*)},
	{"replaceAll", "(Ljava/util/function/BiFunction;)V", "(Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, replaceAll, void, $BiFunction*)},
	{"size", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, size, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Hashtable, toString, $String*)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<TV;>;", $PUBLIC, $virtualMethod(Hashtable, values, $Collection*)},
	{"writeHashtable", "(Ljava/io/ObjectOutputStream;)V", nullptr, 0, $virtualMethod(Hashtable, writeHashtable, void, $ObjectOutputStream*), "java.io.IOException"},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(Hashtable, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _Hashtable_InnerClassesInfo_[] = {
	{"java.util.Hashtable$Enumerator", "java.util.Hashtable", "Enumerator", $PRIVATE},
	{"java.util.Hashtable$Entry", "java.util.Hashtable", "Entry", $PRIVATE | $STATIC},
	{"java.util.Hashtable$ValueCollection", "java.util.Hashtable", "ValueCollection", $PRIVATE},
	{"java.util.Hashtable$EntrySet", "java.util.Hashtable", "EntrySet", $PRIVATE},
	{"java.util.Hashtable$KeySet", "java.util.Hashtable", "KeySet", $PRIVATE},
	{}
};

$ClassInfo _Hashtable_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.Hashtable",
	"java.util.Dictionary",
	"java.util.Map,java.lang.Cloneable,java.io.Serializable",
	_Hashtable_FieldInfo_,
	_Hashtable_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/Dictionary<TK;TV;>;Ljava/util/Map<TK;TV;>;Ljava/lang/Cloneable;Ljava/io/Serializable;",
	nullptr,
	_Hashtable_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.Hashtable$Enumerator,java.util.Hashtable$Entry,java.util.Hashtable$ValueCollection,java.util.Hashtable$EntrySet,java.util.Hashtable$KeySet"
};

$Object* allocate$Hashtable($Class* clazz) {
	return $of($alloc(Hashtable));
}

void Hashtable::finalize() {
	this->$Dictionary::finalize();
}

void Hashtable::init$(int32_t initialCapacity, float loadFactor) {
	$useLocalCurrentObjectStackCache();
	$Dictionary::init$();
	this->modCount = 0;
	if (initialCapacity < 0) {
		$throwNew($IllegalArgumentException, $$str({"Illegal Capacity: "_s, $$str(initialCapacity)}));
	}
	if (loadFactor <= 0 || $Float::isNaN(loadFactor)) {
		$throwNew($IllegalArgumentException, $$str({"Illegal Load: "_s, $$str(loadFactor)}));
	}
	if (initialCapacity == 0) {
		initialCapacity = 1;
	}
	this->loadFactor = loadFactor;
	$set(this, table, $new($Hashtable$EntryArray, initialCapacity));
	this->threshold = $cast(int32_t, $Math::min(initialCapacity * loadFactor, (float)(Hashtable::MAX_ARRAY_SIZE + 1)));
}

void Hashtable::init$(int32_t initialCapacity) {
	Hashtable::init$(initialCapacity, 0.75f);
}

void Hashtable::init$() {
	Hashtable::init$(11, 0.75f);
}

void Hashtable::init$($Map* t) {
	Hashtable::init$($Math::max(2 * $nc(t)->size(), 11), 0.75f);
	putAll(t);
}

void Hashtable::init$($Void* dummy) {
	$Dictionary::init$();
	this->modCount = 0;
}

int32_t Hashtable::size() {
	$synchronized(this) {
		return this->count;
	}
}

bool Hashtable::isEmpty() {
	$synchronized(this) {
		return this->count == 0;
	}
}

$Enumeration* Hashtable::keys() {
	$synchronized(this) {
		return this->getEnumeration(Hashtable::KEYS);
	}
}

$Enumeration* Hashtable::elements() {
	$synchronized(this) {
		return this->getEnumeration(Hashtable::VALUES);
	}
}

bool Hashtable::contains(Object$* value) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (value == nullptr) {
			$throwNew($NullPointerException);
		}
		$var($Hashtable$EntryArray, tab, this->table);
		for (int32_t i = $nc(tab)->length; i-- > 0;) {
			{
				$var($Hashtable$Entry, e, tab->get(i));
				for (; e != nullptr; $assign(e, $nc(e)->next)) {
					if ($nc($of(e->value))->equals(value)) {
						return true;
					}
				}
			}
		}
		return false;
	}
}

bool Hashtable::containsValue(Object$* value) {
	return contains(value);
}

bool Hashtable::containsKey(Object$* key) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($Hashtable$EntryArray, tab, this->table);
		int32_t hash = $nc($of(key))->hashCode();
		int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
		{
			$var($Hashtable$Entry, e, tab->get(index));
			for (; e != nullptr; $assign(e, $nc(e)->next)) {
				if ((e->hash == hash) && $nc($of(e->key))->equals(key)) {
					return true;
				}
			}
		}
		return false;
	}
}

$Object* Hashtable::get(Object$* key) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($Hashtable$EntryArray, tab, this->table);
		int32_t hash = $nc($of(key))->hashCode();
		int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
		{
			$var($Hashtable$Entry, e, tab->get(index));
			for (; e != nullptr; $assign(e, $nc(e)->next)) {
				if ((e->hash == hash) && $nc($of(e->key))->equals(key)) {
					return $of(e->value);
				}
			}
		}
		return $of(nullptr);
	}
}

void Hashtable::rehash() {
	$useLocalCurrentObjectStackCache();
	int32_t oldCapacity = $nc(this->table)->length;
	$var($Hashtable$EntryArray, oldMap, this->table);
	int32_t newCapacity = (oldCapacity << 1) + 1;
	if (newCapacity - Hashtable::MAX_ARRAY_SIZE > 0) {
		if (oldCapacity == Hashtable::MAX_ARRAY_SIZE) {
			return;
		}
		newCapacity = Hashtable::MAX_ARRAY_SIZE;
	}
	$var($Hashtable$EntryArray, newMap, $new($Hashtable$EntryArray, newCapacity));
	++this->modCount;
	this->threshold = $cast(int32_t, $Math::min(newCapacity * this->loadFactor, (float)(Hashtable::MAX_ARRAY_SIZE + 1)));
	$set(this, table, newMap);
	for (int32_t i = oldCapacity; i-- > 0;) {
		{
			$var($Hashtable$Entry, old, $nc(oldMap)->get(i));
			for (; old != nullptr;) {
				$var($Hashtable$Entry, e, old);
				$assign(old, old->next);
				int32_t index = $mod(((int32_t)(e->hash & (uint32_t)0x7FFFFFFF)), newCapacity);
				$set(e, next, newMap->get(index));
				newMap->set(index, e);
			}
		}
	}
}

void Hashtable::addEntry(int32_t hash, Object$* key, Object$* value, int32_t index) {
	$useLocalCurrentObjectStackCache();
	$var($Hashtable$EntryArray, tab, this->table);
	if (this->count >= this->threshold) {
		rehash();
		$assign(tab, this->table);
		hash = $nc($of(key))->hashCode();
		index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
	}
	$var($Hashtable$Entry, e, $nc(tab)->get(index));
	tab->set(index, $$new($Hashtable$Entry, hash, key, value, e));
	++this->count;
	++this->modCount;
}

$Object* Hashtable::put(Object$* key, Object$* value) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (value == nullptr) {
			$throwNew($NullPointerException);
		}
		$var($Hashtable$EntryArray, tab, this->table);
		int32_t hash = $nc($of(key))->hashCode();
		int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
		$var($Hashtable$Entry, entry, tab->get(index));
		for (; entry != nullptr; $assign(entry, $nc(entry)->next)) {
			if ((entry->hash == hash) && $nc($of(entry->key))->equals(key)) {
				$var($Object, old, entry->value);
				$set(entry, value, value);
				return $of(old);
			}
		}
		addEntry(hash, key, value, index);
		return $of(nullptr);
	}
}

$Object* Hashtable::remove(Object$* key) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($Hashtable$EntryArray, tab, this->table);
		int32_t hash = $nc($of(key))->hashCode();
		int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
		$var($Hashtable$Entry, e, tab->get(index));
		{
			$var($Hashtable$Entry, prev, nullptr);
			for (; e != nullptr; $assign(prev, e), $assign(e, $nc(e)->next)) {
				if ((e->hash == hash) && $nc($of(e->key))->equals(key)) {
					if (prev != nullptr) {
						$set(prev, next, e->next);
					} else {
						tab->set(index, e->next);
					}
					++this->modCount;
					--this->count;
					$var($Object, oldValue, e->value);
					$set(e, value, nullptr);
					return $of(oldValue);
				}
			}
		}
		return $of(nullptr);
	}
}

void Hashtable::putAll($Map* t) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		{
			$var($Iterator, i$, $nc($($nc(t)->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
				$var($Object, var$0, $nc(e)->getKey());
				put(var$0, $(e->getValue()));
			}
		}
	}
}

void Hashtable::clear() {
	$synchronized(this) {
		$var($Hashtable$EntryArray, tab, this->table);
		for (int32_t index = $nc(tab)->length; --index >= 0;) {
			tab->set(index, nullptr);
		}
		++this->modCount;
		this->count = 0;
	}
}

$Object* Hashtable::clone() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var(Hashtable, t, cloneHashtable());
		$set($nc(t), table, $new($Hashtable$EntryArray, $nc(this->table)->length));
		for (int32_t i = $nc(this->table)->length; i-- > 0;) {
			$nc(t->table)->set(i, ($nc(this->table)->get(i) != nullptr) ? $cast($Hashtable$Entry, $($nc($nc(this->table)->get(i))->clone())) : ($Hashtable$Entry*)nullptr);
		}
		$set(t, keySet$, nullptr);
		$set(t, entrySet$, nullptr);
		$set(t, values$, nullptr);
		t->modCount = 0;
		return $of(t);
	}
}

Hashtable* Hashtable::cloneHashtable() {
	try {
		return $cast(Hashtable, $Dictionary::clone());
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$String* Hashtable::toString() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		int32_t max = size() - 1;
		if (max == -1) {
			return "{}"_s;
		}
		$var($StringBuilder, sb, $new($StringBuilder));
		$var($Iterator, it, $nc($(entrySet()))->iterator());
		sb->append(u'{');
		for (int32_t i = 0;; ++i) {
			$var($Map$Entry, e, $cast($Map$Entry, $nc(it)->next()));
			$var($Object, key, $nc(e)->getKey());
			$var($Object, value, e->getValue());
			sb->append($equals(key, this) ? "(this Map)"_s : $($nc($of(key))->toString()));
			sb->append(u'=');
			sb->append($equals(value, this) ? "(this Map)"_s : $($nc($of(value))->toString()));
			if (i == max) {
				return sb->append(u'}')->toString();
			}
			sb->append(", "_s);
		}
	}
}

$Enumeration* Hashtable::getEnumeration(int32_t type) {
	if (this->count == 0) {
		return $Collections::emptyEnumeration();
	} else {
		return $new($Hashtable$Enumerator, this, type, false);
	}
}

$Iterator* Hashtable::getIterator(int32_t type) {
	if (this->count == 0) {
		return $Collections::emptyIterator();
	} else {
		return $new($Hashtable$Enumerator, this, type, true);
	}
}

$Set* Hashtable::keySet() {
	if (this->keySet$ == nullptr) {
		$set(this, keySet$, $Collections::synchronizedSet($$new($Hashtable$KeySet, this), this));
	}
	return this->keySet$;
}

$Set* Hashtable::entrySet() {
	if (this->entrySet$ == nullptr) {
		$set(this, entrySet$, $Collections::synchronizedSet($$new($Hashtable$EntrySet, this), this));
	}
	return this->entrySet$;
}

$Collection* Hashtable::values() {
	if (this->values$ == nullptr) {
		$set(this, values$, $Collections::synchronizedCollection($$new($Hashtable$ValueCollection, this), this));
	}
	return this->values$;
}

bool Hashtable::equals(Object$* o) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if ($equals(o, this)) {
			return true;
		}
		$var($Map, t, nullptr);
		bool var$0 = $instanceOf($Map, o);
		if (var$0) {
			$assign(t, $cast($Map, o));
			var$0 = true;
		}
		if (!(var$0)) {
			return false;
		}
		int32_t var$1 = $nc(t)->size();
		if (var$1 != size()) {
			return false;
		}
		try {
			{
				$var($Iterator, i$, $nc($(entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
					{
						$var($Object, key, $nc(e)->getKey());
						$var($Object, value, e->getValue());
						if (value == nullptr) {
							bool var$2 = $nc(t)->get(key) == nullptr;
							if (!(var$2 && t->containsKey(key))) {
								return false;
							}
						} else if (!$nc($of(value))->equals($($nc(t)->get(key)))) {
							return false;
						}
					}
				}
			}
		} catch ($ClassCastException& unused) {
			return false;
		} catch ($NullPointerException& unused) {
			return false;
		}
		return true;
	}
}

int32_t Hashtable::hashCode() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		int32_t h = 0;
		if (this->count == 0 || this->loadFactor < 0) {
			return h;
		}
		this->loadFactor = -this->loadFactor;
		$var($Hashtable$EntryArray, tab, this->table);
		{
			$var($Hashtable$EntryArray, arr$, tab);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Hashtable$Entry, entry, arr$->get(i$));
				{
					while (entry != nullptr) {
						h += entry->hashCode();
						$assign(entry, entry->next);
					}
				}
			}
		}
		this->loadFactor = -this->loadFactor;
		return h;
	}
}

$Object* Hashtable::getOrDefault(Object$* key, Object$* defaultValue) {
	$synchronized(this) {
		$var($Object, result, get(key));
		return $of((nullptr == result) ? $of(defaultValue) : result);
	}
}

void Hashtable::forEach($BiConsumer* action) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Objects::requireNonNull(action);
		int32_t expectedModCount = this->modCount;
		$var($Hashtable$EntryArray, tab, this->table);
		{
			$var($Hashtable$EntryArray, arr$, tab);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Hashtable$Entry, entry, arr$->get(i$));
				{
					while (entry != nullptr) {
						action->accept(entry->key, entry->value);
						$assign(entry, entry->next);
						if (expectedModCount != this->modCount) {
							$throwNew($ConcurrentModificationException);
						}
					}
				}
			}
		}
	}
}

void Hashtable::replaceAll($BiFunction* function) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Objects::requireNonNull(function);
		int32_t expectedModCount = this->modCount;
		$var($Hashtable$EntryArray, tab, this->table);
		{
			$var($Hashtable$EntryArray, arr$, tab);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Hashtable$Entry, entry, arr$->get(i$));
				{
					while (entry != nullptr) {
						$set(entry, value, $Objects::requireNonNull($(function->apply(entry->key, entry->value))));
						$assign(entry, entry->next);
						if (expectedModCount != this->modCount) {
							$throwNew($ConcurrentModificationException);
						}
					}
				}
			}
		}
	}
}

$Object* Hashtable::putIfAbsent(Object$* key, Object$* value) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Objects::requireNonNull(value);
		$var($Hashtable$EntryArray, tab, this->table);
		int32_t hash = $nc($of(key))->hashCode();
		int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
		$var($Hashtable$Entry, entry, tab->get(index));
		for (; entry != nullptr; $assign(entry, $nc(entry)->next)) {
			if ((entry->hash == hash) && $nc($of(entry->key))->equals(key)) {
				$var($Object, old, entry->value);
				if (old == nullptr) {
					$set(entry, value, value);
				}
				return $of(old);
			}
		}
		addEntry(hash, key, value, index);
		return $of(nullptr);
	}
}

bool Hashtable::remove(Object$* key, Object$* value) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Objects::requireNonNull(value);
		$var($Hashtable$EntryArray, tab, this->table);
		int32_t hash = $nc($of(key))->hashCode();
		int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
		$var($Hashtable$Entry, e, tab->get(index));
		{
			$var($Hashtable$Entry, prev, nullptr);
			for (; e != nullptr; $assign(prev, e), $assign(e, $nc(e)->next)) {
				bool var$0 = (e->hash == hash) && $nc($of(e->key))->equals(key);
				if (var$0 && $nc($of(e->value))->equals(value)) {
					if (prev != nullptr) {
						$set(prev, next, e->next);
					} else {
						tab->set(index, e->next);
					}
					$set(e, value, nullptr);
					++this->modCount;
					--this->count;
					return true;
				}
			}
		}
		return false;
	}
}

bool Hashtable::replace(Object$* key, Object$* oldValue, Object$* newValue) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Objects::requireNonNull(oldValue);
		$Objects::requireNonNull(newValue);
		$var($Hashtable$EntryArray, tab, this->table);
		int32_t hash = $nc($of(key))->hashCode();
		int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
		$var($Hashtable$Entry, e, tab->get(index));
		for (; e != nullptr; $assign(e, $nc(e)->next)) {
			if ((e->hash == hash) && $nc($of(e->key))->equals(key)) {
				if ($nc($of(e->value))->equals(oldValue)) {
					$set(e, value, newValue);
					return true;
				} else {
					return false;
				}
			}
		}
		return false;
	}
}

$Object* Hashtable::replace(Object$* key, Object$* value) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Objects::requireNonNull(value);
		$var($Hashtable$EntryArray, tab, this->table);
		int32_t hash = $nc($of(key))->hashCode();
		int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
		$var($Hashtable$Entry, e, tab->get(index));
		for (; e != nullptr; $assign(e, $nc(e)->next)) {
			if ((e->hash == hash) && $nc($of(e->key))->equals(key)) {
				$var($Object, oldValue, e->value);
				$set(e, value, value);
				return $of(oldValue);
			}
		}
		return $of(nullptr);
	}
}

$Object* Hashtable::computeIfAbsent(Object$* key, $Function* mappingFunction) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Objects::requireNonNull(mappingFunction);
		$var($Hashtable$EntryArray, tab, this->table);
		int32_t hash = $nc($of(key))->hashCode();
		int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
		$var($Hashtable$Entry, e, tab->get(index));
		for (; e != nullptr; $assign(e, $nc(e)->next)) {
			if (e->hash == hash && $nc($of(e->key))->equals(key)) {
				return $of(e->value);
			}
		}
		int32_t mc = this->modCount;
		$var($Object, newValue, mappingFunction->apply(key));
		if (mc != this->modCount) {
			$throwNew($ConcurrentModificationException);
		}
		if (newValue != nullptr) {
			addEntry(hash, key, newValue, index);
		}
		return $of(newValue);
	}
}

$Object* Hashtable::computeIfPresent(Object$* key, $BiFunction* remappingFunction) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Objects::requireNonNull(remappingFunction);
		$var($Hashtable$EntryArray, tab, this->table);
		int32_t hash = $nc($of(key))->hashCode();
		int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
		$var($Hashtable$Entry, e, tab->get(index));
		{
			$var($Hashtable$Entry, prev, nullptr);
			for (; e != nullptr; $assign(prev, e), $assign(e, $nc(e)->next)) {
				if (e->hash == hash && $nc($of(e->key))->equals(key)) {
					int32_t mc = this->modCount;
					$var($Object, newValue, remappingFunction->apply(key, e->value));
					if (mc != this->modCount) {
						$throwNew($ConcurrentModificationException);
					}
					if (newValue == nullptr) {
						if (prev != nullptr) {
							$set(prev, next, e->next);
						} else {
							tab->set(index, e->next);
						}
						this->modCount = mc + 1;
						--this->count;
					} else {
						$set(e, value, newValue);
					}
					return $of(newValue);
				}
			}
		}
		return $of(nullptr);
	}
}

$Object* Hashtable::compute(Object$* key, $BiFunction* remappingFunction) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Objects::requireNonNull(remappingFunction);
		$var($Hashtable$EntryArray, tab, this->table);
		int32_t hash = $nc($of(key))->hashCode();
		int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
		$var($Hashtable$Entry, e, tab->get(index));
		{
			$var($Hashtable$Entry, prev, nullptr);
			for (; e != nullptr; $assign(prev, e), $assign(e, $nc(e)->next)) {
				if (e->hash == hash && $Objects::equals(e->key, key)) {
					int32_t mc = this->modCount;
					$var($Object, newValue, remappingFunction->apply(key, e->value));
					if (mc != this->modCount) {
						$throwNew($ConcurrentModificationException);
					}
					if (newValue == nullptr) {
						if (prev != nullptr) {
							$set(prev, next, e->next);
						} else {
							tab->set(index, e->next);
						}
						this->modCount = mc + 1;
						--this->count;
					} else {
						$set(e, value, newValue);
					}
					return $of(newValue);
				}
			}
		}
		int32_t mc = this->modCount;
		$var($Object, newValue, remappingFunction->apply(key, nullptr));
		if (mc != this->modCount) {
			$throwNew($ConcurrentModificationException);
		}
		if (newValue != nullptr) {
			addEntry(hash, key, newValue, index);
		}
		return $of(newValue);
	}
}

$Object* Hashtable::merge(Object$* key, Object$* value, $BiFunction* remappingFunction) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Objects::requireNonNull(remappingFunction);
		$var($Hashtable$EntryArray, tab, this->table);
		int32_t hash = $nc($of(key))->hashCode();
		int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
		$var($Hashtable$Entry, e, tab->get(index));
		{
			$var($Hashtable$Entry, prev, nullptr);
			for (; e != nullptr; $assign(prev, e), $assign(e, $nc(e)->next)) {
				if (e->hash == hash && $nc($of(e->key))->equals(key)) {
					int32_t mc = this->modCount;
					$var($Object, newValue, remappingFunction->apply(e->value, value));
					if (mc != this->modCount) {
						$throwNew($ConcurrentModificationException);
					}
					if (newValue == nullptr) {
						if (prev != nullptr) {
							$set(prev, next, e->next);
						} else {
							tab->set(index, e->next);
						}
						this->modCount = mc + 1;
						--this->count;
					} else {
						$set(e, value, newValue);
					}
					return $of(newValue);
				}
			}
		}
		if (value != nullptr) {
			addEntry(hash, key, value, index);
		}
		return $of(value);
	}
}

void Hashtable::writeObject($ObjectOutputStream* s) {
	writeHashtable(s);
}

void Hashtable::writeHashtable($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$var($Hashtable$Entry, entryStack, nullptr);
	$synchronized(this) {
		$nc(s)->defaultWriteObject();
		s->writeInt($nc(this->table)->length);
		s->writeInt(this->count);
		{
			$var($Hashtable$EntryArray, arr$, this->table);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Hashtable$Entry, entry, arr$->get(i$));
				{
					while (entry != nullptr) {
						$assign(entryStack, $new($Hashtable$Entry, 0, entry->key, entry->value, entryStack));
						$assign(entry, entry->next);
					}
				}
			}
		}
	}
	while (entryStack != nullptr) {
		$nc(s)->writeObject(entryStack->key);
		s->writeObject(entryStack->value);
		$assign(entryStack, entryStack->next);
	}
}

void Hashtable::defaultWriteHashtable($ObjectOutputStream* s, int32_t length, float loadFactor) {
	this->threshold = $cast(int32_t, $Math::min(length * loadFactor, (float)(Hashtable::MAX_ARRAY_SIZE + 1)));
	this->loadFactor = loadFactor;
	$nc(s)->defaultWriteObject();
}

void Hashtable::readObject($ObjectInputStream* s) {
	readHashtable(s);
}

void Hashtable::readHashtable($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	if (this->loadFactor <= 0 || $Float::isNaN(this->loadFactor)) {
		$throwNew($StreamCorruptedException, $$str({"Illegal Load: "_s, $$str(this->loadFactor)}));
	}
	int32_t origlength = s->readInt();
	int32_t elements = s->readInt();
	if (elements < 0) {
		$throwNew($StreamCorruptedException, $$str({"Illegal # of Elements: "_s, $$str(elements)}));
	}
	origlength = $Math::max(origlength, $cast(int32_t, (elements / this->loadFactor)) + 1);
	int32_t length = $cast(int32_t, ((elements + elements / 20) / this->loadFactor)) + 3;
	if (length > elements && ((int32_t)(length & (uint32_t)1)) == 0) {
		--length;
	}
	length = $Math::min(length, origlength);
	if (length < 0) {
		length = origlength;
	}
	$load($Map$EntryArray);
	$nc($($SharedSecrets::getJavaObjectInputStreamAccess()))->checkArray(s, $getClass($Map$EntryArray), length);
	$set(this, table, $new($Hashtable$EntryArray, length));
	this->threshold = $cast(int32_t, $Math::min(length * this->loadFactor, (float)(Hashtable::MAX_ARRAY_SIZE + 1)));
	this->count = 0;
	for (; elements > 0; --elements) {
		$var($Object, key, s->readObject());
		$var($Object, value, s->readObject());
		reconstitutionPut(this->table, key, value);
	}
}

void Hashtable::reconstitutionPut($Hashtable$EntryArray* tab, Object$* key, Object$* value) {
	$useLocalCurrentObjectStackCache();
	if (value == nullptr) {
		$throwNew($StreamCorruptedException);
	}
	int32_t hash = $nc($of(key))->hashCode();
	int32_t index = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(tab)->length);
	{
		$var($Hashtable$Entry, e, tab->get(index));
		for (; e != nullptr; $assign(e, $nc(e)->next)) {
			if ((e->hash == hash) && $nc($of(e->key))->equals(key)) {
				$throwNew($StreamCorruptedException);
			}
		}
	}
	$var($Hashtable$Entry, e, tab->get(index));
	tab->set(index, $$new($Hashtable$Entry, hash, key, value, e));
	++this->count;
}

Hashtable::Hashtable() {
}

$Class* Hashtable::load$($String* name, bool initialize) {
	$loadClass(Hashtable, name, initialize, &_Hashtable_ClassInfo_, allocate$Hashtable);
	return class$;
}

$Class* Hashtable::class$ = nullptr;

	} // util
} // java