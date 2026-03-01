#include <java/util/EnumMap.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Enum.h>
#include <java/util/AbstractMap.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/EnumMap$1.h>
#include <java/util/EnumMap$EntrySet.h>
#include <java/util/EnumMap$KeySet.h>
#include <java/util/EnumMap$Values.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef NULL

using $EnumArray = $Array<::java::lang::Enum>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractMap = ::java::util::AbstractMap;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $EnumMap$1 = ::java::util::EnumMap$1;
using $EnumMap$EntrySet = ::java::util::EnumMap$EntrySet;
using $EnumMap$KeySet = ::java::util::EnumMap$KeySet;
using $EnumMap$Values = ::java::util::EnumMap$Values;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace util {

$FieldInfo _EnumMap_FieldInfo_[] = {
	{"keyType", "Ljava/lang/Class;", "Ljava/lang/Class<TK;>;", $PRIVATE | $FINAL, $field(EnumMap, keyType)},
	{"keyUniverse", "[Ljava/lang/Enum;", "[TK;", $PRIVATE | $TRANSIENT, $field(EnumMap, keyUniverse)},
	{"vals", "[Ljava/lang/Object;", nullptr, $PRIVATE | $TRANSIENT, $field(EnumMap, vals)},
	{"size", "I", nullptr, $PRIVATE | $TRANSIENT, $field(EnumMap, size$)},
	{"NULL", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(EnumMap, NULL)},
	{"entrySet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PRIVATE | $TRANSIENT, $field(EnumMap, entrySet$)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(EnumMap, serialVersionUID)},
	{}
};

$MethodInfo _EnumMap_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<TK;>;)V", $PUBLIC, $method(EnumMap, init$, void, $Class*)},
	{"<init>", "(Ljava/util/EnumMap;)V", "(Ljava/util/EnumMap<TK;+TV;>;)V", $PUBLIC, $method(EnumMap, init$, void, EnumMap*)},
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<TK;+TV;>;)V", $PUBLIC, $method(EnumMap, init$, void, $Map*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(EnumMap, clear, void)},
	{"clone", "()Ljava/util/EnumMap;", "()Ljava/util/EnumMap<TK;TV;>;", $PUBLIC, $virtualMethod(EnumMap, clone, $Object*)},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(EnumMap, containsKey, bool, Object$*)},
	{"containsMapping", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PRIVATE, $method(EnumMap, containsMapping, bool, Object$*, Object$*)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(EnumMap, containsValue, bool, Object$*)},
	{"entryHashCode", "(I)I", nullptr, $PRIVATE, $method(EnumMap, entryHashCode, int32_t, int32_t)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(EnumMap, entrySet, $Set*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(EnumMap, equals, bool, Object$*)},
	{"equals", "(Ljava/util/EnumMap;)Z", "(Ljava/util/EnumMap<**>;)Z", $PRIVATE, $method(EnumMap, equals, bool, EnumMap*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(EnumMap, get, $Object*, Object$*)},
	{"getKeyUniverse", "(Ljava/lang/Class;)[Ljava/lang/Enum;", "<K:Ljava/lang/Enum<TK;>;>(Ljava/lang/Class<TK;>;)[TK;", $PRIVATE | $STATIC, $staticMethod(EnumMap, getKeyUniverse, $EnumArray*, $Class*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(EnumMap, hashCode, int32_t)},
	{"isValidKey", "(Ljava/lang/Object;)Z", nullptr, $PRIVATE, $method(EnumMap, isValidKey, bool, Object$*)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<TK;>;", $PUBLIC, $virtualMethod(EnumMap, keySet, $Set*)},
	{"maskNull", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(EnumMap, maskNull, $Object*, Object$*)},
	{"put", "(Ljava/lang/Enum;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(EnumMap, put, $Object*, $Enum*, Object$*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(EnumMap, put, $Object*, Object$*, Object$*)},
	{"putAll", "(Ljava/util/Map;)V", "(Ljava/util/Map<+TK;+TV;>;)V", $PUBLIC, $virtualMethod(EnumMap, putAll, void, $Map*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(EnumMap, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(EnumMap, remove, $Object*, Object$*)},
	{"removeMapping", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PRIVATE, $method(EnumMap, removeMapping, bool, Object$*, Object$*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(EnumMap, size, int32_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"typeCheck", "(Ljava/lang/Enum;)V", "(TK;)V", $PRIVATE, $method(EnumMap, typeCheck, void, $Enum*)},
	{"unmaskNull", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PRIVATE, $method(EnumMap, unmaskNull, $Object*, Object$*)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<TV;>;", $PUBLIC, $virtualMethod(EnumMap, values, $Collection*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(EnumMap, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _EnumMap_InnerClassesInfo_[] = {
	{"java.util.EnumMap$EntryIterator", "java.util.EnumMap", "EntryIterator", $PRIVATE},
	{"java.util.EnumMap$ValueIterator", "java.util.EnumMap", "ValueIterator", $PRIVATE},
	{"java.util.EnumMap$KeyIterator", "java.util.EnumMap", "KeyIterator", $PRIVATE},
	{"java.util.EnumMap$EnumMapIterator", "java.util.EnumMap", "EnumMapIterator", $PRIVATE | $ABSTRACT},
	{"java.util.EnumMap$EntrySet", "java.util.EnumMap", "EntrySet", $PRIVATE},
	{"java.util.EnumMap$Values", "java.util.EnumMap", "Values", $PRIVATE},
	{"java.util.EnumMap$KeySet", "java.util.EnumMap", "KeySet", $PRIVATE},
	{"java.util.EnumMap$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _EnumMap_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.EnumMap",
	"java.util.AbstractMap",
	"java.io.Serializable,java.lang.Cloneable",
	_EnumMap_FieldInfo_,
	_EnumMap_MethodInfo_,
	"<K:Ljava/lang/Enum<TK;>;V:Ljava/lang/Object;>Ljava/util/AbstractMap<TK;TV;>;Ljava/io/Serializable;Ljava/lang/Cloneable;",
	nullptr,
	_EnumMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.EnumMap$EntryIterator,java.util.EnumMap$EntryIterator$Entry,java.util.EnumMap$ValueIterator,java.util.EnumMap$KeyIterator,java.util.EnumMap$EnumMapIterator,java.util.EnumMap$EntrySet,java.util.EnumMap$Values,java.util.EnumMap$KeySet,java.util.EnumMap$1"
};

$Object* allocate$EnumMap($Class* clazz) {
	return $of($alloc(EnumMap));
}

$String* EnumMap::toString() {
	 return this->$AbstractMap::toString();
}

void EnumMap::finalize() {
	this->$AbstractMap::finalize();
}

$Object* EnumMap::NULL = nullptr;

$Object* EnumMap::maskNull(Object$* value) {
	return $of((value == nullptr ? EnumMap::NULL : $of(value)));
}

$Object* EnumMap::unmaskNull(Object$* value) {
	return $of(($equals(value, EnumMap::NULL) ? ($Object*)nullptr : $of(value)));
}

void EnumMap::init$($Class* keyType) {
	$AbstractMap::init$();
	this->size$ = 0;
	$set(this, keyType, keyType);
	$set(this, keyUniverse, getKeyUniverse(keyType));
	$set(this, vals, $new($ObjectArray, $nc(this->keyUniverse)->length));
}

void EnumMap::init$(EnumMap* m) {
	$AbstractMap::init$();
	this->size$ = 0;
	$set(this, keyType, $nc(m)->keyType);
	$set(this, keyUniverse, m->keyUniverse);
	$set(this, vals, $cast($ObjectArray, $nc(m->vals)->clone()));
	this->size$ = m->size$;
}

void EnumMap::init$($Map* m) {
	$useLocalCurrentObjectStackCache();
	$AbstractMap::init$();
	this->size$ = 0;
	if ($instanceOf(EnumMap, m)) {
		$var(EnumMap, em, $cast(EnumMap, m));
		$set(this, keyType, $nc(em)->keyType);
		$set(this, keyUniverse, em->keyUniverse);
		$set(this, vals, $cast($ObjectArray, $nc(em->vals)->clone()));
		this->size$ = em->size$;
	} else {
		if ($nc(m)->isEmpty()) {
			$throwNew($IllegalArgumentException, "Specified map is empty"_s);
		}
		$set(this, keyType, $nc(($cast($Enum, $($nc($($nc($($nc(m)->keySet()))->iterator()))->next()))))->getDeclaringClass());
		$set(this, keyUniverse, getKeyUniverse(this->keyType));
		$set(this, vals, $new($ObjectArray, $nc(this->keyUniverse)->length));
		putAll(m);
	}
}

int32_t EnumMap::size() {
	return this->size$;
}

bool EnumMap::containsValue(Object$* value$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, value$renamed);
	$assign(value, maskNull(value));
	{
		$var($ObjectArray, arr$, this->vals);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, val, arr$->get(i$));
			if ($nc($of(value))->equals(val)) {
				return true;
			}
		}
	}
	return false;
}

bool EnumMap::containsKey(Object$* key) {
	bool var$0 = isValidKey(key);
	return var$0 && $nc(this->vals)->get($nc(($cast($Enum, key)))->ordinal()) != nullptr;
}

bool EnumMap::containsMapping(Object$* key, Object$* value) {
	bool var$0 = isValidKey(key);
	return var$0 && $nc($of($(maskNull(value))))->equals($nc(this->vals)->get($nc(($cast($Enum, key)))->ordinal()));
}

$Object* EnumMap::get(Object$* key) {
	return $of((isValidKey(key) ? unmaskNull($nc(this->vals)->get($nc(($cast($Enum, key)))->ordinal())) : ($Object*)nullptr));
}

$Object* EnumMap::put($Enum* key, Object$* value) {
	$useLocalCurrentObjectStackCache();
	typeCheck(key);
	int32_t index = $nc(key)->ordinal();
	$var($Object0, oldValue, $nc(this->vals)->get(index));
	$nc(this->vals)->set(index, $(maskNull(value)));
	if (oldValue == nullptr) {
		++this->size$;
	}
	return $of(unmaskNull(oldValue));
}

$Object* EnumMap::remove(Object$* key) {
	if (!isValidKey(key)) {
		return $of(nullptr);
	}
	int32_t index = $nc(($cast($Enum, key)))->ordinal();
	$var($Object0, oldValue, $nc(this->vals)->get(index));
	$nc(this->vals)->set(index, nullptr);
	if (oldValue != nullptr) {
		--this->size$;
	}
	return $of(unmaskNull(oldValue));
}

bool EnumMap::removeMapping(Object$* key, Object$* value) {
	if (!isValidKey(key)) {
		return false;
	}
	int32_t index = $nc(($cast($Enum, key)))->ordinal();
	if ($nc($of($(maskNull(value))))->equals($nc(this->vals)->get(index))) {
		$nc(this->vals)->set(index, nullptr);
		--this->size$;
		return true;
	}
	return false;
}

bool EnumMap::isValidKey(Object$* key) {
	if (key == nullptr) {
		return false;
	}
	$Class* keyClass = $nc($of(key))->getClass();
	return keyClass == this->keyType || $nc(keyClass)->getSuperclass() == this->keyType;
}

void EnumMap::putAll($Map* m) {
	$useLocalCurrentObjectStackCache();
	{
		$var(EnumMap, em, nullptr);
		bool var$0 = $instanceOf(EnumMap, m);
		if (var$0) {
			$assign(em, $cast(EnumMap, m));
			var$0 = true;
		}
		if (var$0) {
			if ($nc(em)->keyType != this->keyType) {
				if (em->isEmpty()) {
					return;
				}
				$throwNew($ClassCastException, $$str({em->keyType, " != "_s, this->keyType}));
			}
			for (int32_t i = 0; i < $nc(this->keyUniverse)->length; ++i) {
				$var($Object0, emValue, $nc($nc(em)->vals)->get(i));
				if (emValue != nullptr) {
					if ($nc(this->vals)->get(i) == nullptr) {
						++this->size$;
					}
					$nc(this->vals)->set(i, emValue);
				}
			}
		} else {
			$AbstractMap::putAll(m);
		}
	}
}

void EnumMap::clear() {
	$Arrays::fill(this->vals, ($Object*)nullptr);
	this->size$ = 0;
}

$Set* EnumMap::keySet() {
	$var($Set, ks, this->$AbstractMap::keySet$);
	if (ks == nullptr) {
		$assign(ks, $new($EnumMap$KeySet, this));
		$set(this, keySet$, ks);
	}
	return ks;
}

$Collection* EnumMap::values() {
	$var($Collection, vs, this->$AbstractMap::values$);
	if (vs == nullptr) {
		$assign(vs, $new($EnumMap$Values, this));
		$set(this, values$, vs);
	}
	return vs;
}

$Set* EnumMap::entrySet() {
	$var($Set, es, this->entrySet$);
	if (es != nullptr) {
		return es;
	} else {
		return $set(this, entrySet$, $new($EnumMap$EntrySet, this));
	}
}

bool EnumMap::equals(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, o)) {
		return true;
	}
	if ($instanceOf(EnumMap, o)) {
		return equals($cast(EnumMap, o));
	}
	$var($Map, m, nullptr);
	bool var$0 = $instanceOf($Map, o);
	if (var$0) {
		$assign(m, $cast($Map, o));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	if (this->size$ != $nc(m)->size()) {
		return false;
	}
	for (int32_t i = 0; i < $nc(this->keyUniverse)->length; ++i) {
		if (nullptr != $nc(this->vals)->get(i)) {
			$var($Enum, key, $nc(this->keyUniverse)->get(i));
			$var($Object, value, unmaskNull($nc(this->vals)->get(i)));
			if (nullptr == value) {
				bool var$1 = (nullptr == $nc(m)->get(key));
				if (!(var$1 && m->containsKey(key))) {
					return false;
				}
			} else if (!$nc($of(value))->equals($($nc(m)->get(key)))) {
				return false;
			}
		}
	}
	return true;
}

bool EnumMap::equals(EnumMap* em) {
	$useLocalCurrentObjectStackCache();
	if ($nc(em)->size$ != this->size$) {
		return false;
	}
	if ($nc(em)->keyType != this->keyType) {
		return this->size$ == 0;
	}
	for (int32_t i = 0; i < $nc(this->keyUniverse)->length; ++i) {
		$var($Object0, ourValue, $nc(this->vals)->get(i));
		$var($Object0, hisValue, $nc($nc(em)->vals)->get(i));
		if (!$equals(hisValue, ourValue) && (hisValue == nullptr || !$nc($of(hisValue))->equals(ourValue))) {
			return false;
		}
	}
	return true;
}

int32_t EnumMap::hashCode() {
	int32_t h = 0;
	for (int32_t i = 0; i < $nc(this->keyUniverse)->length; ++i) {
		if (nullptr != $nc(this->vals)->get(i)) {
			h += entryHashCode(i);
		}
	}
	return h;
}

int32_t EnumMap::entryHashCode(int32_t index) {
	int32_t var$0 = $nc($nc(this->keyUniverse)->get(index))->hashCode();
	return (var$0 ^ $nc($of($nc(this->vals)->get(index)))->hashCode());
}

$Object* EnumMap::clone() {
	$var(EnumMap, result, nullptr);
	try {
		$assign(result, $cast(EnumMap, $AbstractMap::clone()));
	} catch ($CloneNotSupportedException& e) {
		$throwNew($AssertionError);
	}
	$set($nc(result), vals, $cast($ObjectArray, $nc(result->vals)->clone()));
	$set(result, entrySet$, nullptr);
	return $of(result);
}

void EnumMap::typeCheck($Enum* key) {
	$Class* keyClass = $nc($of(key))->getClass();
	if (keyClass != this->keyType && $nc(keyClass)->getSuperclass() != this->keyType) {
		$throwNew($ClassCastException, $$str({keyClass, " != "_s, this->keyType}));
	}
}

$EnumArray* EnumMap::getKeyUniverse($Class* keyType) {
	$init(EnumMap);
	return $nc($($SharedSecrets::getJavaLangAccess()))->getEnumConstantsShared(keyType);
}

void EnumMap::writeObject($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultWriteObject();
	s->writeInt(this->size$);
	int32_t entriesToBeWritten = this->size$;
	for (int32_t i = 0; entriesToBeWritten > 0; ++i) {
		if (nullptr != $nc(this->vals)->get(i)) {
			s->writeObject($nc(this->keyUniverse)->get(i));
			s->writeObject($(unmaskNull($nc(this->vals)->get(i))));
			--entriesToBeWritten;
		}
	}
}

void EnumMap::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	$set(this, keyUniverse, getKeyUniverse(this->keyType));
	$set(this, vals, $new($ObjectArray, $nc(this->keyUniverse)->length));
	int32_t size = s->readInt();
	for (int32_t i = 0; i < size; ++i) {
		$var($Enum, key, $cast($Enum, s->readObject()));
		$var($Object, value, s->readObject());
		put(key, value);
	}
}

$Object* EnumMap::put(Object$* key, Object$* value) {
	return $of(this->put($cast($Enum, key), value));
}

void clinit$EnumMap($Class* class$) {
	$assignStatic(EnumMap::NULL, $new($EnumMap$1));
}

EnumMap::EnumMap() {
}

$Class* EnumMap::load$($String* name, bool initialize) {
	$loadClass(EnumMap, name, initialize, &_EnumMap_ClassInfo_, clinit$EnumMap, allocate$EnumMap);
	return class$;
}

$Class* EnumMap::class$ = nullptr;

	} // util
} // java