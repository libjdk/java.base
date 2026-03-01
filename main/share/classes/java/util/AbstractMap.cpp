#include <java/util/AbstractMap.h>

#include <java/lang/ClassCastException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/util/AbstractMap$1.h>
#include <java/util/AbstractMap$2.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $AbstractMap$1 = ::java::util::AbstractMap$1;
using $AbstractMap$2 = ::java::util::AbstractMap$2;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;

namespace java {
	namespace util {

$FieldInfo _AbstractMap_FieldInfo_[] = {
	{"keySet", "Ljava/util/Set;", "Ljava/util/Set<TK;>;", $TRANSIENT, $field(AbstractMap, keySet$)},
	{"values", "Ljava/util/Collection;", "Ljava/util/Collection<TV;>;", $TRANSIENT, $field(AbstractMap, values$)},
	{}
};

$MethodInfo _AbstractMap_MethodInfo_[] = {
	{"entrySet", "()Ljava/util/Set;", nullptr, $PUBLIC | $ABSTRACT},
	{"<init>", "()V", nullptr, $PROTECTED, $method(AbstractMap, init$, void)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(AbstractMap, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(AbstractMap, clone, $Object*), "java.lang.CloneNotSupportedException"},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(AbstractMap, containsKey, bool, Object$*)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(AbstractMap, containsValue, bool, Object$*)},
	{"eq", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(AbstractMap, eq, bool, Object$*, Object$*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(AbstractMap, equals, bool, Object$*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(AbstractMap, get, $Object*, Object$*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(AbstractMap, hashCode, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(AbstractMap, isEmpty, bool)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<TK;>;", $PUBLIC, $virtualMethod(AbstractMap, keySet, $Set*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(AbstractMap, put, $Object*, Object$*, Object$*)},
	{"putAll", "(Ljava/util/Map;)V", "(Ljava/util/Map<+TK;+TV;>;)V", $PUBLIC, $virtualMethod(AbstractMap, putAll, void, $Map*)},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(AbstractMap, remove, $Object*, Object$*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(AbstractMap, size, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AbstractMap, toString, $String*)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<TV;>;", $PUBLIC, $virtualMethod(AbstractMap, values, $Collection*)},
	{}
};

$InnerClassInfo _AbstractMap_InnerClassesInfo_[] = {
	{"java.util.AbstractMap$SimpleImmutableEntry", "java.util.AbstractMap", "SimpleImmutableEntry", $PUBLIC | $STATIC},
	{"java.util.AbstractMap$SimpleEntry", "java.util.AbstractMap", "SimpleEntry", $PUBLIC | $STATIC},
	{"java.util.AbstractMap$2", nullptr, nullptr, 0},
	{"java.util.AbstractMap$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _AbstractMap_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.util.AbstractMap",
	"java.lang.Object",
	"java.util.Map",
	_AbstractMap_FieldInfo_,
	_AbstractMap_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/Map<TK;TV;>;",
	nullptr,
	_AbstractMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.AbstractMap$SimpleImmutableEntry,java.util.AbstractMap$SimpleEntry,java.util.AbstractMap$2,java.util.AbstractMap$2$1,java.util.AbstractMap$1,java.util.AbstractMap$1$1"
};

$Object* allocate$AbstractMap($Class* clazz) {
	return $of($alloc(AbstractMap));
}

void AbstractMap::init$() {
}

int32_t AbstractMap::size() {
	return $nc($(entrySet()))->size();
}

bool AbstractMap::isEmpty() {
	return size() == 0;
}

bool AbstractMap::containsValue(Object$* value) {
	$useLocalCurrentObjectStackCache();
	$var($Iterator, i, $nc($(entrySet()))->iterator());
	if (value == nullptr) {
		while ($nc(i)->hasNext()) {
			$var($Map$Entry, e, $cast($Map$Entry, i->next()));
			if ($nc(e)->getValue() == nullptr) {
				return true;
			}
		}
	} else {
		while ($nc(i)->hasNext()) {
			$var($Map$Entry, e, $cast($Map$Entry, i->next()));
			if ($nc($of(value))->equals($($nc(e)->getValue()))) {
				return true;
			}
		}
	}
	return false;
}

bool AbstractMap::containsKey(Object$* key) {
	$useLocalCurrentObjectStackCache();
	$var($Iterator, i, $nc($(entrySet()))->iterator());
	if (key == nullptr) {
		while ($nc(i)->hasNext()) {
			$var($Map$Entry, e, $cast($Map$Entry, i->next()));
			if ($nc(e)->getKey() == nullptr) {
				return true;
			}
		}
	} else {
		while ($nc(i)->hasNext()) {
			$var($Map$Entry, e, $cast($Map$Entry, i->next()));
			if ($nc($of(key))->equals($($nc(e)->getKey()))) {
				return true;
			}
		}
	}
	return false;
}

$Object* AbstractMap::get(Object$* key) {
	$useLocalCurrentObjectStackCache();
	$var($Iterator, i, $nc($(entrySet()))->iterator());
	if (key == nullptr) {
		while ($nc(i)->hasNext()) {
			$var($Map$Entry, e, $cast($Map$Entry, i->next()));
			if ($nc(e)->getKey() == nullptr) {
				return $of(e->getValue());
			}
		}
	} else {
		while ($nc(i)->hasNext()) {
			$var($Map$Entry, e, $cast($Map$Entry, i->next()));
			if ($nc($of(key))->equals($($nc(e)->getKey()))) {
				return $of($nc(e)->getValue());
			}
		}
	}
	return $of(nullptr);
}

$Object* AbstractMap::put(Object$* key, Object$* value) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Object* AbstractMap::remove(Object$* key) {
	$useLocalCurrentObjectStackCache();
	$var($Iterator, i, $nc($(entrySet()))->iterator());
	$var($Map$Entry, correctEntry, nullptr);
	if (key == nullptr) {
		while (correctEntry == nullptr && $nc(i)->hasNext()) {
			$var($Map$Entry, e, $cast($Map$Entry, i->next()));
			if ($nc(e)->getKey() == nullptr) {
				$assign(correctEntry, e);
			}
		}
	} else {
		while (correctEntry == nullptr && $nc(i)->hasNext()) {
			$var($Map$Entry, e, $cast($Map$Entry, i->next()));
			if ($nc($of(key))->equals($($nc(e)->getKey()))) {
				$assign(correctEntry, e);
			}
		}
	}
	$var($Object, oldValue, nullptr);
	if (correctEntry != nullptr) {
		$assign(oldValue, correctEntry->getValue());
		$nc(i)->remove();
	}
	return $of(oldValue);
}

void AbstractMap::putAll($Map* m) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(m)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			$var($Object, var$0, $nc(e)->getKey());
			put(var$0, $(e->getValue()));
		}
	}
}

void AbstractMap::clear() {
	$nc($(entrySet()))->clear();
}

$Set* AbstractMap::keySet() {
	$var($Set, ks, this->keySet$);
	if (ks == nullptr) {
		$assign(ks, $new($AbstractMap$1, this));
		$set(this, keySet$, ks);
	}
	return ks;
}

$Collection* AbstractMap::values() {
	$var($Collection, vals, this->values$);
	if (vals == nullptr) {
		$assign(vals, $new($AbstractMap$2, this));
		$set(this, values$, vals);
	}
	return vals;
}

bool AbstractMap::equals(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if ($equals(o, this)) {
		return true;
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
	int32_t var$1 = $nc(m)->size();
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
						bool var$2 = $nc(m)->get(key) == nullptr;
						if (!(var$2 && m->containsKey(key))) {
							return false;
						}
					} else if (!$nc($of(value))->equals($($nc(m)->get(key)))) {
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

int32_t AbstractMap::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t h = 0;
	{
		$var($Iterator, i$, $nc($(entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			h += $nc(entry)->hashCode();
		}
	}
	return h;
}

$String* AbstractMap::toString() {
	$useLocalCurrentObjectStackCache();
	$var($Iterator, i, $nc($(entrySet()))->iterator());
	if (!$nc(i)->hasNext()) {
		return "{}"_s;
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append(u'{');
	for (;;) {
		$var($Map$Entry, e, $cast($Map$Entry, $nc(i)->next()));
		$var($Object, key, $nc(e)->getKey());
		$var($Object, value, e->getValue());
		sb->append($equals(key, this) ? $of("(this Map)"_s) : key);
		sb->append(u'=');
		sb->append($equals(value, this) ? $of("(this Map)"_s) : value);
		if (!i->hasNext()) {
			return sb->append(u'}')->toString();
		}
		sb->append(u',')->append(u' ');
	}
}

$Object* AbstractMap::clone() {
	$var(AbstractMap, result, $cast(AbstractMap, $Map::clone()));
	$set($nc(result), keySet$, nullptr);
	$set(result, values$, nullptr);
	return $of(result);
}

bool AbstractMap::eq(Object$* o1, Object$* o2) {
	$init(AbstractMap);
	return o1 == nullptr ? o2 == nullptr : $nc($of(o1))->equals(o2);
}

AbstractMap::AbstractMap() {
}

$Class* AbstractMap::load$($String* name, bool initialize) {
	$loadClass(AbstractMap, name, initialize, &_AbstractMap_ClassInfo_, allocate$AbstractMap);
	return class$;
}

$Class* AbstractMap::class$ = nullptr;

	} // util
} // java