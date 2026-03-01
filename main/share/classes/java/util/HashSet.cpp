#include <java/util/HashSet.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/HashMap$KeySpliterator.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/Spliterator.h>
#include <jdk/internal/access/JavaObjectInputStreamAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef MAXIMUM_CAPACITY
#undef PRESENT

using $Map$EntryArray = $Array<::java::util::Map$Entry>;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $HashMap$KeySpliterator = ::java::util::HashMap$KeySpliterator;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $Set = ::java::util::Set;
using $Spliterator = ::java::util::Spliterator;
using $JavaObjectInputStreamAccess = ::jdk::internal::access::JavaObjectInputStreamAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace util {

$FieldInfo _HashSet_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(HashSet, serialVersionUID)},
	{"map", "Ljava/util/HashMap;", "Ljava/util/HashMap<TE;Ljava/lang/Object;>;", $PRIVATE | $TRANSIENT, $field(HashSet, map)},
	{"PRESENT", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HashSet, PRESENT)},
	{}
};

$MethodInfo _HashSet_MethodInfo_[] = {
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PUBLIC, $method(HashSet, init$, void)},
	{"<init>", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PUBLIC, $method(HashSet, init$, void, $Collection*)},
	{"<init>", "(IF)V", nullptr, $PUBLIC, $method(HashSet, init$, void, int32_t, float)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(HashSet, init$, void, int32_t)},
	{"<init>", "(IFZ)V", nullptr, 0, $method(HashSet, init$, void, int32_t, float, bool)},
	{"add", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(HashSet, add, bool, Object$*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(HashSet, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HashSet, clone, $Object*)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(HashSet, contains, bool, Object$*)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(HashSet, isEmpty, bool)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(HashSet, iterator, $Iterator*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(HashSet, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(HashSet, remove, bool, Object$*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(HashSet, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(HashSet, spliterator, $Spliterator*)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HashSet, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(HashSet, toArray, $ObjectArray*, $ObjectArray*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(HashSet, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _HashSet_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.HashSet",
	"java.util.AbstractSet",
	"java.lang.Cloneable,java.io.Serializable",
	_HashSet_FieldInfo_,
	_HashSet_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/util/AbstractSet<TE;>;Ljava/util/Set<TE;>;Ljava/lang/Cloneable;Ljava/io/Serializable;"
};

$Object* allocate$HashSet($Class* clazz) {
	return $of($alloc(HashSet));
}

bool HashSet::equals(Object$* o) {
	 return this->$AbstractSet::equals(o);
}

int32_t HashSet::hashCode() {
	 return this->$AbstractSet::hashCode();
}

$String* HashSet::toString() {
	 return this->$AbstractSet::toString();
}

void HashSet::finalize() {
	this->$AbstractSet::finalize();
}

$Object* HashSet::PRESENT = nullptr;

void HashSet::init$() {
	$AbstractSet::init$();
	$set(this, map, $new($HashMap));
}

void HashSet::init$($Collection* c) {
	$AbstractSet::init$();
	$set(this, map, $new($HashMap, $Math::max($cast(int32_t, ($nc(c)->size() / 0.75f)) + 1, 16)));
	addAll(c);
}

void HashSet::init$(int32_t initialCapacity, float loadFactor) {
	$AbstractSet::init$();
	$set(this, map, $new($HashMap, initialCapacity, loadFactor));
}

void HashSet::init$(int32_t initialCapacity) {
	$AbstractSet::init$();
	$set(this, map, $new($HashMap, initialCapacity));
}

void HashSet::init$(int32_t initialCapacity, float loadFactor, bool dummy) {
	$AbstractSet::init$();
	$set(this, map, $new($LinkedHashMap, initialCapacity, loadFactor));
}

$Iterator* HashSet::iterator() {
	return $nc($($nc(this->map)->keySet()))->iterator();
}

int32_t HashSet::size() {
	return $nc(this->map)->size();
}

bool HashSet::isEmpty() {
	return $nc(this->map)->isEmpty();
}

bool HashSet::contains(Object$* o) {
	return $nc(this->map)->containsKey(o);
}

bool HashSet::add(Object$* e) {
	return $nc(this->map)->put(e, HashSet::PRESENT) == nullptr;
}

bool HashSet::remove(Object$* o) {
	return $equals($nc(this->map)->remove(o), HashSet::PRESENT);
}

void HashSet::clear() {
	$nc(this->map)->clear();
}

$Object* HashSet::clone() {
	try {
		$var(HashSet, newSet, $cast(HashSet, $AbstractSet::clone()));
		$set($nc(newSet), map, $cast($HashMap, $nc(this->map)->clone()));
		return $of(newSet);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void HashSet::writeObject($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultWriteObject();
	s->writeInt($nc(this->map)->capacity());
	s->writeFloat($nc(this->map)->loadFactor());
	s->writeInt($nc(this->map)->size());
	{
		$var($Iterator, i$, $nc($($nc(this->map)->keySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, e, i$->next());
			s->writeObject(e);
		}
	}
}

void HashSet::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	int32_t capacity = s->readInt();
	if (capacity < 0) {
		$throwNew($InvalidObjectException, $$str({"Illegal capacity: "_s, $$str(capacity)}));
	}
	float loadFactor = s->readFloat();
	if (loadFactor <= 0 || $Float::isNaN(loadFactor)) {
		$throwNew($InvalidObjectException, $$str({"Illegal load factor: "_s, $$str(loadFactor)}));
	}
	int32_t size = s->readInt();
	if (size < 0) {
		$throwNew($InvalidObjectException, $$str({"Illegal size: "_s, $$str(size)}));
	}
	capacity = $cast(int32_t, $Math::min(size * $Math::min(1 / loadFactor, 4.0f), (float)$HashMap::MAXIMUM_CAPACITY));
	$load($Map$EntryArray);
	$nc($($SharedSecrets::getJavaObjectInputStreamAccess()))->checkArray(s, $getClass($Map$EntryArray), $HashMap::tableSizeFor(capacity));
	$set(this, map, $instanceOf($LinkedHashSet, this) ? static_cast<$HashMap*>($new($LinkedHashMap, capacity, loadFactor)) : $new($HashMap, capacity, loadFactor));
	for (int32_t i = 0; i < size; ++i) {
		$var($Object, e, s->readObject());
		$nc(this->map)->put(e, HashSet::PRESENT);
	}
}

$Spliterator* HashSet::spliterator() {
	return $new($HashMap$KeySpliterator, this->map, 0, -1, 0, 0);
}

$ObjectArray* HashSet::toArray() {
	return $nc(this->map)->keysToArray($$new($ObjectArray, $nc(this->map)->size()));
}

$ObjectArray* HashSet::toArray($ObjectArray* a) {
	return $nc(this->map)->keysToArray($($nc(this->map)->prepareArray(a)));
}

void clinit$HashSet($Class* class$) {
	$assignStatic(HashSet::PRESENT, $new($Object));
}

HashSet::HashSet() {
}

$Class* HashSet::load$($String* name, bool initialize) {
	$loadClass(HashSet, name, initialize, &_HashSet_ClassInfo_, clinit$HashSet, allocate$HashSet);
	return class$;
}

$Class* HashSet::class$ = nullptr;

	} // util
} // java