#include <java/util/HashMap.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Comparable.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/lang/reflect/Array.h>
#include <java/lang/reflect/ParameterizedType.h>
#include <java/lang/reflect/Type.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/HashMap$EntrySet.h>
#include <java/util/HashMap$KeySet.h>
#include <java/util/HashMap$Node.h>
#include <java/util/HashMap$TreeNode.h>
#include <java/util/HashMap$Values.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <jdk/internal/access/JavaObjectInputStreamAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef DEFAULT_INITIAL_CAPACITY
#undef DEFAULT_LOAD_FACTOR
#undef MAXIMUM_CAPACITY
#undef MAX_VALUE
#undef MIN_TREEIFY_CAPACITY
#undef TREEIFY_THRESHOLD
#undef UNTREEIFY_THRESHOLD

using $TypeArray = $Array<::java::lang::reflect::Type>;
using $HashMap$NodeArray = $Array<::java::util::HashMap$Node>;
using $Map$EntryArray = $Array<::java::util::Map$Entry>;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Comparable = ::java::lang::Comparable;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $1Array = ::java::lang::reflect::Array;
using $ParameterizedType = ::java::lang::reflect::ParameterizedType;
using $Type = ::java::lang::reflect::Type;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $HashMap$EntrySet = ::java::util::HashMap$EntrySet;
using $HashMap$KeySet = ::java::util::HashMap$KeySet;
using $HashMap$Node = ::java::util::HashMap$Node;
using $HashMap$TreeNode = ::java::util::HashMap$TreeNode;
using $HashMap$Values = ::java::util::HashMap$Values;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;
using $JavaObjectInputStreamAccess = ::jdk::internal::access::JavaObjectInputStreamAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace util {

$FieldInfo _HashMap_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HashMap, serialVersionUID)},
	{"DEFAULT_INITIAL_CAPACITY", "I", nullptr, $STATIC | $FINAL, $constField(HashMap, DEFAULT_INITIAL_CAPACITY)},
	{"MAXIMUM_CAPACITY", "I", nullptr, $STATIC | $FINAL, $constField(HashMap, MAXIMUM_CAPACITY)},
	{"DEFAULT_LOAD_FACTOR", "F", nullptr, $STATIC | $FINAL, $staticField(HashMap, DEFAULT_LOAD_FACTOR)},
	{"TREEIFY_THRESHOLD", "I", nullptr, $STATIC | $FINAL, $constField(HashMap, TREEIFY_THRESHOLD)},
	{"UNTREEIFY_THRESHOLD", "I", nullptr, $STATIC | $FINAL, $constField(HashMap, UNTREEIFY_THRESHOLD)},
	{"MIN_TREEIFY_CAPACITY", "I", nullptr, $STATIC | $FINAL, $constField(HashMap, MIN_TREEIFY_CAPACITY)},
	{"table", "[Ljava/util/HashMap$Node;", "[Ljava/util/HashMap$Node<TK;TV;>;", $TRANSIENT, $field(HashMap, table)},
	{"entrySet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $TRANSIENT, $field(HashMap, entrySet$)},
	{"size", "I", nullptr, $TRANSIENT, $field(HashMap, size$)},
	{"modCount", "I", nullptr, $TRANSIENT, $field(HashMap, modCount)},
	{"threshold", "I", nullptr, 0, $field(HashMap, threshold)},
	{"loadFactor", "F", nullptr, $FINAL, $field(HashMap, loadFactor$)},
	{}
};

$MethodInfo _HashMap_MethodInfo_[] = {
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(IF)V", nullptr, $PUBLIC, $method(HashMap, init$, void, int32_t, float)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(HashMap, init$, void, int32_t)},
	{"<init>", "()V", nullptr, $PUBLIC, $method(HashMap, init$, void)},
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<+TK;+TV;>;)V", $PUBLIC, $method(HashMap, init$, void, $Map*)},
	{"afterNodeAccess", "(Ljava/util/HashMap$Node;)V", "(Ljava/util/HashMap$Node<TK;TV;>;)V", 0, $virtualMethod(HashMap, afterNodeAccess, void, $HashMap$Node*)},
	{"afterNodeInsertion", "(Z)V", nullptr, 0, $virtualMethod(HashMap, afterNodeInsertion, void, bool)},
	{"afterNodeRemoval", "(Ljava/util/HashMap$Node;)V", "(Ljava/util/HashMap$Node<TK;TV;>;)V", 0, $virtualMethod(HashMap, afterNodeRemoval, void, $HashMap$Node*)},
	{"capacity", "()I", nullptr, $FINAL, $method(HashMap, capacity, int32_t)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(HashMap, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HashMap, clone, $Object*)},
	{"comparableClassFor", "(Ljava/lang/Object;)Ljava/lang/Class;", "(Ljava/lang/Object;)Ljava/lang/Class<*>;", $STATIC, $staticMethod(HashMap, comparableClassFor, $Class*, Object$*)},
	{"compareComparables", "(Ljava/lang/Class;Ljava/lang/Object;Ljava/lang/Object;)I", "(Ljava/lang/Class<*>;Ljava/lang/Object;Ljava/lang/Object;)I", $STATIC, $staticMethod(HashMap, compareComparables, int32_t, $Class*, Object$*, Object$*)},
	{"compute", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(TK;Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)TV;", $PUBLIC, $virtualMethod(HashMap, compute, $Object*, Object$*, $BiFunction*)},
	{"computeIfAbsent", "(Ljava/lang/Object;Ljava/util/function/Function;)Ljava/lang/Object;", "(TK;Ljava/util/function/Function<-TK;+TV;>;)TV;", $PUBLIC, $virtualMethod(HashMap, computeIfAbsent, $Object*, Object$*, $Function*)},
	{"computeIfPresent", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(TK;Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)TV;", $PUBLIC, $virtualMethod(HashMap, computeIfPresent, $Object*, Object$*, $BiFunction*)},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(HashMap, containsKey, bool, Object$*)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(HashMap, containsValue, bool, Object$*)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(HashMap, entrySet, $Set*)},
	{"forEach", "(Ljava/util/function/BiConsumer;)V", "(Ljava/util/function/BiConsumer<-TK;-TV;>;)V", $PUBLIC, $virtualMethod(HashMap, forEach, void, $BiConsumer*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(HashMap, get, $Object*, Object$*)},
	{"getNode", "(Ljava/lang/Object;)Ljava/util/HashMap$Node;", "(Ljava/lang/Object;)Ljava/util/HashMap$Node<TK;TV;>;", $FINAL, $method(HashMap, getNode, $HashMap$Node*, Object$*)},
	{"getOrDefault", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;TV;)TV;", $PUBLIC, $virtualMethod(HashMap, getOrDefault, $Object*, Object$*, Object$*)},
	{"hash", "(Ljava/lang/Object;)I", nullptr, $STATIC | $FINAL, $staticMethod(HashMap, hash, int32_t, Object$*)},
	{"internalWriteEntries", "(Ljava/io/ObjectOutputStream;)V", nullptr, 0, $virtualMethod(HashMap, internalWriteEntries, void, $ObjectOutputStream*), "java.io.IOException"},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(HashMap, isEmpty, bool)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<TK;>;", $PUBLIC, $virtualMethod(HashMap, keySet, $Set*)},
	{"keysToArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", 0, $virtualMethod(HashMap, keysToArray, $ObjectArray*, $ObjectArray*)},
	{"loadFactor", "()F", nullptr, $FINAL, $method(HashMap, loadFactor, float)},
	{"merge", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(TK;TV;Ljava/util/function/BiFunction<-TV;-TV;+TV;>;)TV;", $PUBLIC, $virtualMethod(HashMap, merge, $Object*, Object$*, Object$*, $BiFunction*)},
	{"newNode", "(ILjava/lang/Object;Ljava/lang/Object;Ljava/util/HashMap$Node;)Ljava/util/HashMap$Node;", "(ITK;TV;Ljava/util/HashMap$Node<TK;TV;>;)Ljava/util/HashMap$Node<TK;TV;>;", 0, $virtualMethod(HashMap, newNode, $HashMap$Node*, int32_t, Object$*, Object$*, $HashMap$Node*)},
	{"newTreeNode", "(ILjava/lang/Object;Ljava/lang/Object;Ljava/util/HashMap$Node;)Ljava/util/HashMap$TreeNode;", "(ITK;TV;Ljava/util/HashMap$Node<TK;TV;>;)Ljava/util/HashMap$TreeNode<TK;TV;>;", 0, $virtualMethod(HashMap, newTreeNode, $HashMap$TreeNode*, int32_t, Object$*, Object$*, $HashMap$Node*)},
	{"prepareArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $FINAL, $method(HashMap, prepareArray, $ObjectArray*, $ObjectArray*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(HashMap, put, $Object*, Object$*, Object$*)},
	{"putAll", "(Ljava/util/Map;)V", "(Ljava/util/Map<+TK;+TV;>;)V", $PUBLIC, $virtualMethod(HashMap, putAll, void, $Map*)},
	{"putIfAbsent", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(HashMap, putIfAbsent, $Object*, Object$*, Object$*)},
	{"putMapEntries", "(Ljava/util/Map;Z)V", "(Ljava/util/Map<+TK;+TV;>;Z)V", $FINAL, $method(HashMap, putMapEntries, void, $Map*, bool)},
	{"putVal", "(ILjava/lang/Object;Ljava/lang/Object;ZZ)Ljava/lang/Object;", "(ITK;TV;ZZ)TV;", $FINAL, $method(HashMap, putVal, $Object*, int32_t, Object$*, Object$*, bool, bool)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(HashMap, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"reinitialize", "()V", nullptr, 0, $virtualMethod(HashMap, reinitialize, void)},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(HashMap, remove, $Object*, Object$*)},
	{"remove", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(HashMap, remove, bool, Object$*, Object$*)},
	{"removeNode", "(ILjava/lang/Object;Ljava/lang/Object;ZZ)Ljava/util/HashMap$Node;", "(ILjava/lang/Object;Ljava/lang/Object;ZZ)Ljava/util/HashMap$Node<TK;TV;>;", $FINAL, $method(HashMap, removeNode, $HashMap$Node*, int32_t, Object$*, Object$*, bool, bool)},
	{"replace", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z", "(TK;TV;TV;)Z", $PUBLIC, $virtualMethod(HashMap, replace, bool, Object$*, Object$*, Object$*)},
	{"replace", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(HashMap, replace, $Object*, Object$*, Object$*)},
	{"replaceAll", "(Ljava/util/function/BiFunction;)V", "(Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)V", $PUBLIC, $virtualMethod(HashMap, replaceAll, void, $BiFunction*)},
	{"replacementNode", "(Ljava/util/HashMap$Node;Ljava/util/HashMap$Node;)Ljava/util/HashMap$Node;", "(Ljava/util/HashMap$Node<TK;TV;>;Ljava/util/HashMap$Node<TK;TV;>;)Ljava/util/HashMap$Node<TK;TV;>;", 0, $virtualMethod(HashMap, replacementNode, $HashMap$Node*, $HashMap$Node*, $HashMap$Node*)},
	{"replacementTreeNode", "(Ljava/util/HashMap$Node;Ljava/util/HashMap$Node;)Ljava/util/HashMap$TreeNode;", "(Ljava/util/HashMap$Node<TK;TV;>;Ljava/util/HashMap$Node<TK;TV;>;)Ljava/util/HashMap$TreeNode<TK;TV;>;", 0, $virtualMethod(HashMap, replacementTreeNode, $HashMap$TreeNode*, $HashMap$Node*, $HashMap$Node*)},
	{"resize", "()[Ljava/util/HashMap$Node;", "()[Ljava/util/HashMap$Node<TK;TV;>;", $FINAL, $method(HashMap, resize, $HashMap$NodeArray*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(HashMap, size, int32_t)},
	{"tableSizeFor", "(I)I", nullptr, $STATIC | $FINAL, $staticMethod(HashMap, tableSizeFor, int32_t, int32_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"treeifyBin", "([Ljava/util/HashMap$Node;I)V", "([Ljava/util/HashMap$Node<TK;TV;>;I)V", $FINAL, $method(HashMap, treeifyBin, void, $HashMap$NodeArray*, int32_t)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<TV;>;", $PUBLIC, $virtualMethod(HashMap, values, $Collection*)},
	{"valuesToArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", 0, $virtualMethod(HashMap, valuesToArray, $ObjectArray*, $ObjectArray*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(HashMap, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _HashMap_InnerClassesInfo_[] = {
	{"java.util.HashMap$TreeNode", "java.util.HashMap", "TreeNode", $STATIC | $FINAL},
	{"java.util.HashMap$EntrySpliterator", "java.util.HashMap", "EntrySpliterator", $STATIC | $FINAL},
	{"java.util.HashMap$ValueSpliterator", "java.util.HashMap", "ValueSpliterator", $STATIC | $FINAL},
	{"java.util.HashMap$KeySpliterator", "java.util.HashMap", "KeySpliterator", $STATIC | $FINAL},
	{"java.util.HashMap$HashMapSpliterator", "java.util.HashMap", "HashMapSpliterator", $STATIC},
	{"java.util.HashMap$EntryIterator", "java.util.HashMap", "EntryIterator", $FINAL},
	{"java.util.HashMap$ValueIterator", "java.util.HashMap", "ValueIterator", $FINAL},
	{"java.util.HashMap$KeyIterator", "java.util.HashMap", "KeyIterator", $FINAL},
	{"java.util.HashMap$HashIterator", "java.util.HashMap", "HashIterator", $ABSTRACT},
	{"java.util.HashMap$EntrySet", "java.util.HashMap", "EntrySet", $FINAL},
	{"java.util.HashMap$Values", "java.util.HashMap", "Values", $FINAL},
	{"java.util.HashMap$KeySet", "java.util.HashMap", "KeySet", $FINAL},
	{"java.util.HashMap$Node", "java.util.HashMap", "Node", $STATIC},
	{}
};

$ClassInfo _HashMap_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.HashMap",
	"java.util.AbstractMap",
	"java.lang.Cloneable,java.io.Serializable",
	_HashMap_FieldInfo_,
	_HashMap_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/AbstractMap<TK;TV;>;Ljava/util/Map<TK;TV;>;Ljava/lang/Cloneable;Ljava/io/Serializable;",
	nullptr,
	_HashMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.HashMap$TreeNode,java.util.HashMap$EntrySpliterator,java.util.HashMap$ValueSpliterator,java.util.HashMap$KeySpliterator,java.util.HashMap$HashMapSpliterator,java.util.HashMap$EntryIterator,java.util.HashMap$ValueIterator,java.util.HashMap$KeyIterator,java.util.HashMap$HashIterator,java.util.HashMap$EntrySet,java.util.HashMap$Values,java.util.HashMap$KeySet,java.util.HashMap$Node"
};

$Object* allocate$HashMap($Class* clazz) {
	return $of($alloc(HashMap));
}

bool HashMap::equals(Object$* o) {
	 return this->$AbstractMap::equals(o);
}

int32_t HashMap::hashCode() {
	 return this->$AbstractMap::hashCode();
}

$String* HashMap::toString() {
	 return this->$AbstractMap::toString();
}

void HashMap::finalize() {
	this->$AbstractMap::finalize();
}

float HashMap::DEFAULT_LOAD_FACTOR = 0.0;

int32_t HashMap::hash(Object$* key) {
	$init(HashMap);
	int32_t h = 0;
	return (key == nullptr) ? 0 : (h = $nc($of(key))->hashCode()) ^ ((int32_t)((uint32_t)h >> 16));
}

$Class* HashMap::comparableClassFor(Object$* x) {
	$init(HashMap);
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($Comparable, x)) {
		$Class* c = nullptr;
		$var($TypeArray, ts, nullptr);
		$var($TypeArray, as, nullptr);
		$var($ParameterizedType, p, nullptr);
		if ((c = $nc($of(x))->getClass()) == $String::class$) {
			return c;
		}
		if (($assign(ts, $nc(c)->getGenericInterfaces())) != nullptr) {
			{
				$var($TypeArray, arr$, ts);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($Type, t, arr$->get(i$));
					{
						$load($Comparable);
						bool var$0 = ($instanceOf($ParameterizedType, t)) && ($equals($nc(($assign(p, $cast($ParameterizedType, t))))->getRawType(), $Comparable::class$));
						if (var$0 && ($assign(as, $nc(p)->getActualTypeArguments())) != nullptr && $nc(as)->length == 1 && $equals(as->get(0), c)) {
							return c;
						}
					}
				}
			}
		}
	}
	return nullptr;
}

int32_t HashMap::compareComparables($Class* kc, Object$* k, Object$* x) {
	$init(HashMap);
	return (x == nullptr || $nc($of(x))->getClass() != kc ? 0 : $nc(($cast($Comparable, k)))->compareTo(x));
}

int32_t HashMap::tableSizeFor(int32_t cap) {
	$init(HashMap);
	int32_t n = $usr(-1, $Integer::numberOfLeadingZeros(cap - 1));
	return (n < 0) ? 1 : (n >= HashMap::MAXIMUM_CAPACITY) ? HashMap::MAXIMUM_CAPACITY : n + 1;
}

void HashMap::init$(int32_t initialCapacity, float loadFactor) {
	$useLocalCurrentObjectStackCache();
	$AbstractMap::init$();
	if (initialCapacity < 0) {
		$throwNew($IllegalArgumentException, $$str({"Illegal initial capacity: "_s, $$str(initialCapacity)}));
	}
	if (initialCapacity > HashMap::MAXIMUM_CAPACITY) {
		initialCapacity = HashMap::MAXIMUM_CAPACITY;
	}
	if (loadFactor <= 0 || $Float::isNaN(loadFactor)) {
		$throwNew($IllegalArgumentException, $$str({"Illegal load factor: "_s, $$str(loadFactor)}));
	}
	this->loadFactor$ = loadFactor;
	this->threshold = tableSizeFor(initialCapacity);
}

void HashMap::init$(int32_t initialCapacity) {
	HashMap::init$(initialCapacity, HashMap::DEFAULT_LOAD_FACTOR);
}

void HashMap::init$() {
	$AbstractMap::init$();
	this->loadFactor$ = HashMap::DEFAULT_LOAD_FACTOR;
}

void HashMap::init$($Map* m) {
	$AbstractMap::init$();
	this->loadFactor$ = HashMap::DEFAULT_LOAD_FACTOR;
	putMapEntries(m, false);
}

void HashMap::putMapEntries($Map* m, bool evict) {
	$useLocalCurrentObjectStackCache();
	int32_t s = $nc(m)->size();
	if (s > 0) {
		if (this->table == nullptr) {
			float ft = ((float)s / this->loadFactor$) + 1.0f;
			int32_t t = ((ft < (float)HashMap::MAXIMUM_CAPACITY) ? $cast(int32_t, ft) : HashMap::MAXIMUM_CAPACITY);
			if (t > this->threshold) {
				this->threshold = tableSizeFor(t);
			}
		} else {
			while (s > this->threshold && $nc(this->table)->length < HashMap::MAXIMUM_CAPACITY) {
				resize();
			}
		}
		{
			$var($Iterator, i$, $nc($(m->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
				{
					$var($Object, key, $nc(e)->getKey());
					$var($Object, value, e->getValue());
					putVal(hash(key), key, value, false, evict);
				}
			}
		}
	}
}

int32_t HashMap::size() {
	return this->size$;
}

bool HashMap::isEmpty() {
	return this->size$ == 0;
}

$Object* HashMap::get(Object$* key) {
	$var($HashMap$Node, e, nullptr);
	return $of(($assign(e, getNode(key))) == nullptr ? ($Object*)nullptr : $nc(e)->value);
}

$HashMap$Node* HashMap::getNode(Object$* key) {
	$useLocalCurrentObjectStackCache();
	$var($HashMap$NodeArray, tab, nullptr);
	$var($HashMap$Node, first, nullptr);
	$var($HashMap$Node, e, nullptr);
	int32_t n = 0;
	int32_t hash = 0;
	$var($Object, k, nullptr);
	bool var$1 = ($assign(tab, this->table)) != nullptr;
	bool var$0 = var$1 && (n = $nc(tab)->length) > 0;
	if (var$0 && ($assign(first, tab->get((int32_t)((n - 1) & (uint32_t)(hash = HashMap::hash(key)))))) != nullptr) {
		bool var$2 = $nc(first)->hash == hash;
		if (var$2) {
			bool var$3 = $equals($assign(k, first->key), key);
			var$2 = (var$3 || (key != nullptr && $of(key)->equals(k)));
		}
		if (var$2) {
			return first;
		}
		if (($assign(e, $nc(first)->next)) != nullptr) {
			if ($instanceOf($HashMap$TreeNode, first)) {
				return $nc(($cast($HashMap$TreeNode, first)))->getTreeNode(hash, key);
			}
			do {
				bool var$4 = $nc(e)->hash == hash;
				if (var$4) {
					bool var$5 = $equals($assign(k, e->key), key);
					var$4 = (var$5 || (key != nullptr && $of(key)->equals(k)));
				}
				if (var$4) {
					return e;
				}
			} while (($assign(e, $nc(e)->next)) != nullptr);
		}
	}
	return nullptr;
}

bool HashMap::containsKey(Object$* key) {
	return getNode(key) != nullptr;
}

$Object* HashMap::put(Object$* key, Object$* value) {
	return $of(putVal(hash(key), key, value, false, true));
}

$Object* HashMap::putVal(int32_t hash, Object$* key, Object$* value, bool onlyIfAbsent, bool evict) {
	$useLocalCurrentObjectStackCache();
	$var($HashMap$NodeArray, tab, nullptr);
	$var($HashMap$Node, p, nullptr);
	int32_t n = 0;
	int32_t i = 0;
	bool var$0 = ($assign(tab, this->table)) == nullptr;
	if (var$0 || (n = $nc(tab)->length) == 0) {
		n = $nc(($assign(tab, resize())))->length;
	}
	if (($assign(p, $nc(tab)->get(i = (int32_t)((n - 1) & (uint32_t)hash)))) == nullptr) {
		tab->set(i, $(newNode(hash, key, value, nullptr)));
	} else {
		$var($HashMap$Node, e, nullptr);
		$var($Object, k, nullptr);
		bool var$1 = $nc(p)->hash == hash;
		if (var$1) {
			bool var$2 = $equals($assign(k, p->key), key);
			var$1 = (var$2 || (key != nullptr && $of(key)->equals(k)));
		}
		if (var$1) {
			$assign(e, p);
		} else if ($instanceOf($HashMap$TreeNode, p)) {
			$assign(e, $nc(($cast($HashMap$TreeNode, p)))->putTreeVal(this, tab, hash, key, value));
		} else {
			for (int32_t binCount = 0;; ++binCount) {
				if (($assign(e, $nc(p)->next)) == nullptr) {
					$set(p, next, newNode(hash, key, value, nullptr));
					if (binCount >= HashMap::TREEIFY_THRESHOLD - 1) {
						treeifyBin(tab, hash);
					}
					break;
				}
				bool var$3 = $nc(e)->hash == hash;
				if (var$3) {
					bool var$4 = $equals($assign(k, e->key), key);
					var$3 = (var$4 || (key != nullptr && $of(key)->equals(k)));
				}
				if (var$3) {
					break;
				}
				$assign(p, e);
			}
		}
		if (e != nullptr) {
			$var($Object, oldValue, e->value);
			if (!onlyIfAbsent || oldValue == nullptr) {
				$set(e, value, value);
			}
			afterNodeAccess(e);
			return $of(oldValue);
		}
	}
	++this->modCount;
	if (++this->size$ > this->threshold) {
		resize();
	}
	afterNodeInsertion(evict);
	return $of(nullptr);
}

$HashMap$NodeArray* HashMap::resize() {
	$useLocalCurrentObjectStackCache();
	$var($HashMap$NodeArray, oldTab, this->table);
	int32_t oldCap = (oldTab == nullptr) ? 0 : $nc(oldTab)->length;
	int32_t oldThr = this->threshold;
	int32_t newCap = 0;
	int32_t newThr = 0;
	if (oldCap > 0) {
		if (oldCap >= HashMap::MAXIMUM_CAPACITY) {
			this->threshold = $Integer::MAX_VALUE;
			return oldTab;
		} else if ((newCap = oldCap << 1) < HashMap::MAXIMUM_CAPACITY && oldCap >= HashMap::DEFAULT_INITIAL_CAPACITY) {
			newThr = oldThr << 1;
		}
	} else if (oldThr > 0) {
		newCap = oldThr;
	} else {
		newCap = HashMap::DEFAULT_INITIAL_CAPACITY;
		newThr = $cast(int32_t, (HashMap::DEFAULT_LOAD_FACTOR * HashMap::DEFAULT_INITIAL_CAPACITY));
	}
	if (newThr == 0) {
		float ft = (float)newCap * this->loadFactor$;
		newThr = (newCap < HashMap::MAXIMUM_CAPACITY && ft < (float)HashMap::MAXIMUM_CAPACITY ? $cast(int32_t, ft) : $Integer::MAX_VALUE);
	}
	this->threshold = newThr;
	$var($HashMap$NodeArray, newTab, $new($HashMap$NodeArray, newCap));
	$set(this, table, newTab);
	if (oldTab != nullptr) {
		for (int32_t j = 0; j < oldCap; ++j) {
			$var($HashMap$Node, e, nullptr);
			if (($assign(e, oldTab->get(j))) != nullptr) {
				oldTab->set(j, nullptr);
				if ($nc(e)->next == nullptr) {
					newTab->set((int32_t)(e->hash & (uint32_t)(newCap - 1)), e);
				} else if ($instanceOf($HashMap$TreeNode, e)) {
					$nc(($cast($HashMap$TreeNode, e)))->split(this, newTab, j, oldCap);
				} else {
					$var($HashMap$Node, loHead, nullptr);
					$var($HashMap$Node, loTail, nullptr);
					$var($HashMap$Node, hiHead, nullptr);
					$var($HashMap$Node, hiTail, nullptr);
					$var($HashMap$Node, next, nullptr);
					do {
						$assign(next, e->next);
						if (((int32_t)(e->hash & (uint32_t)oldCap)) == 0) {
							if (loTail == nullptr) {
								$assign(loHead, e);
							} else {
								$set($nc(loTail), next, e);
							}
							$assign(loTail, e);
						} else {
							if (hiTail == nullptr) {
								$assign(hiHead, e);
							} else {
								$set($nc(hiTail), next, e);
							}
							$assign(hiTail, e);
						}
					} while (($assign(e, next)) != nullptr);
					if (loTail != nullptr) {
						$set(loTail, next, nullptr);
						newTab->set(j, loHead);
					}
					if (hiTail != nullptr) {
						$set(hiTail, next, nullptr);
						newTab->set(j + oldCap, hiHead);
					}
				}
			}
		}
	}
	return newTab;
}

void HashMap::treeifyBin($HashMap$NodeArray* tab, int32_t hash) {
	$useLocalCurrentObjectStackCache();
	int32_t n = 0;
	int32_t index = 0;
	$var($HashMap$Node, e, nullptr);
	if (tab == nullptr || (n = $nc(tab)->length) < HashMap::MIN_TREEIFY_CAPACITY) {
		resize();
	} else if (($assign(e, tab->get(index = (int32_t)((n - 1) & (uint32_t)hash)))) != nullptr) {
		$var($HashMap$TreeNode, hd, nullptr);
		$var($HashMap$TreeNode, tl, nullptr);
		do {
			$var($HashMap$TreeNode, p, replacementTreeNode(e, nullptr));
			if (tl == nullptr) {
				$assign(hd, p);
			} else {
				$set($nc(p), prev, tl);
				$set($nc(tl), next, p);
			}
			$assign(tl, p);
		} while (($assign(e, $nc(e)->next)) != nullptr);
		if ((tab->set(index, hd)) != nullptr) {
			$nc(hd)->treeify(tab);
		}
	}
}

void HashMap::putAll($Map* m) {
	putMapEntries(m, true);
}

$Object* HashMap::remove(Object$* key) {
	$var($HashMap$Node, e, nullptr);
	return $of(($assign(e, removeNode(hash(key), key, nullptr, false, true))) == nullptr ? ($Object*)nullptr : $nc(e)->value);
}

$HashMap$Node* HashMap::removeNode(int32_t hash, Object$* key, Object$* value, bool matchValue, bool movable) {
	$useLocalCurrentObjectStackCache();
	$var($HashMap$NodeArray, tab, nullptr);
	$var($HashMap$Node, p, nullptr);
	int32_t n = 0;
	int32_t index = 0;
	bool var$1 = ($assign(tab, this->table)) != nullptr;
	bool var$0 = var$1 && (n = $nc(tab)->length) > 0;
	if (var$0 && ($assign(p, tab->get(index = (int32_t)((n - 1) & (uint32_t)hash)))) != nullptr) {
		$var($HashMap$Node, node, nullptr);
		$var($HashMap$Node, e, nullptr);
		$var($Object, k, nullptr);
		$var($Object, v, nullptr);
		bool var$2 = $nc(p)->hash == hash;
		if (var$2) {
			bool var$3 = $equals($assign(k, p->key), key);
			var$2 = (var$3 || (key != nullptr && $of(key)->equals(k)));
		}
		if (var$2) {
			$assign(node, p);
		} else if (($assign(e, $nc(p)->next)) != nullptr) {
			if ($instanceOf($HashMap$TreeNode, p)) {
				$assign(node, $nc(($cast($HashMap$TreeNode, p)))->getTreeNode(hash, key));
			} else {
				do {
					bool var$4 = $nc(e)->hash == hash;
					if (var$4) {
						bool var$5 = $equals($assign(k, e->key), key);
						var$4 = (var$5 || (key != nullptr && $of(key)->equals(k)));
					}
					if (var$4) {
						$assign(node, e);
						break;
					}
					$assign(p, e);
				} while (($assign(e, $nc(e)->next)) != nullptr);
			}
		}
		bool var$6 = node != nullptr;
		if (var$6) {
			bool var$7 = !matchValue || $equals($assign(v, $nc(node)->value), value);
			var$6 = (var$7 || (value != nullptr && $of(value)->equals(v)));
		}
		if (var$6) {
			if ($instanceOf($HashMap$TreeNode, node)) {
				$nc(($cast($HashMap$TreeNode, node)))->removeTreeNode(this, tab, movable);
			} else if (node == p) {
				tab->set(index, $nc(node)->next);
			} else {
				$set($nc(p), next, $nc(node)->next);
			}
			++this->modCount;
			--this->size$;
			afterNodeRemoval(node);
			return node;
		}
	}
	return nullptr;
}

void HashMap::clear() {
	$var($HashMap$NodeArray, tab, nullptr);
	++this->modCount;
	if (($assign(tab, this->table)) != nullptr && this->size$ > 0) {
		this->size$ = 0;
		for (int32_t i = 0; i < $nc(tab)->length; ++i) {
			tab->set(i, nullptr);
		}
	}
}

bool HashMap::containsValue(Object$* value) {
	$useLocalCurrentObjectStackCache();
	$var($HashMap$NodeArray, tab, nullptr);
	$var($Object, v, nullptr);
	if (($assign(tab, this->table)) != nullptr && this->size$ > 0) {
		{
			$var($HashMap$NodeArray, arr$, tab);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($HashMap$Node, e, arr$->get(i$));
				{
					for (; e != nullptr; $assign(e, $nc(e)->next)) {
						bool var$0 = $equals($assign(v, e->value), value);
						if (var$0 || (value != nullptr && $of(value)->equals(v))) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

$Set* HashMap::keySet() {
	$var($Set, ks, this->$AbstractMap::keySet$);
	if (ks == nullptr) {
		$assign(ks, $new($HashMap$KeySet, this));
		$set(this, keySet$, ks);
	}
	return ks;
}

$ObjectArray* HashMap::prepareArray($ObjectArray* a) {
	int32_t size = this->size$;
	if ($nc(a)->length < size) {
		return $cast($ObjectArray, $1Array::newInstance($of(a)->getClass()->getComponentType(), size));
	}
	if ($nc(a)->length > size) {
		a->set(size, nullptr);
	}
	return a;
}

$ObjectArray* HashMap::keysToArray($ObjectArray* a) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, r, a);
	$var($HashMap$NodeArray, tab, nullptr);
	int32_t idx = 0;
	if (this->size$ > 0 && ($assign(tab, this->table)) != nullptr) {
		{
			$var($HashMap$NodeArray, arr$, tab);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($HashMap$Node, e, arr$->get(i$));
				{
					for (; e != nullptr; $assign(e, $nc(e)->next)) {
						$nc(r)->set(idx++, e->key);
					}
				}
			}
		}
	}
	return a;
}

$ObjectArray* HashMap::valuesToArray($ObjectArray* a) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, r, a);
	$var($HashMap$NodeArray, tab, nullptr);
	int32_t idx = 0;
	if (this->size$ > 0 && ($assign(tab, this->table)) != nullptr) {
		{
			$var($HashMap$NodeArray, arr$, tab);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($HashMap$Node, e, arr$->get(i$));
				{
					for (; e != nullptr; $assign(e, $nc(e)->next)) {
						$nc(r)->set(idx++, e->value);
					}
				}
			}
		}
	}
	return a;
}

$Collection* HashMap::values() {
	$var($Collection, vs, this->$AbstractMap::values$);
	if (vs == nullptr) {
		$assign(vs, $new($HashMap$Values, this));
		$set(this, values$, vs);
	}
	return vs;
}

$Set* HashMap::entrySet() {
	$var($Set, es, nullptr);
	return ($assign(es, this->entrySet$)) == nullptr ? ($set(this, entrySet$, $new($HashMap$EntrySet, this))) : es;
}

$Object* HashMap::getOrDefault(Object$* key, Object$* defaultValue) {
	$var($HashMap$Node, e, nullptr);
	return $of(($assign(e, getNode(key))) == nullptr ? $of(defaultValue) : $nc(e)->value);
}

$Object* HashMap::putIfAbsent(Object$* key, Object$* value) {
	return $of(putVal(hash(key), key, value, true, true));
}

bool HashMap::remove(Object$* key, Object$* value) {
	return removeNode(hash(key), key, value, true, true) != nullptr;
}

bool HashMap::replace(Object$* key, Object$* oldValue, Object$* newValue) {
	$useLocalCurrentObjectStackCache();
	$var($HashMap$Node, e, nullptr);
	$var($Object, v, nullptr);
	bool var$0 = ($assign(e, getNode(key))) != nullptr;
	if (var$0) {
		bool var$1 = $equals($assign(v, $nc(e)->value), oldValue);
		var$0 = (var$1 || (v != nullptr && $of(v)->equals(oldValue)));
	}
	if (var$0) {
		$set($nc(e), value, newValue);
		afterNodeAccess(e);
		return true;
	}
	return false;
}

$Object* HashMap::replace(Object$* key, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$var($HashMap$Node, e, nullptr);
	if (($assign(e, getNode(key))) != nullptr) {
		$var($Object, oldValue, $nc(e)->value);
		$set(e, value, value);
		afterNodeAccess(e);
		return $of(oldValue);
	}
	return $of(nullptr);
}

$Object* HashMap::computeIfAbsent(Object$* key, $Function* mappingFunction) {
	$useLocalCurrentObjectStackCache();
	if (mappingFunction == nullptr) {
		$throwNew($NullPointerException);
	}
	int32_t hash = HashMap::hash(key);
	$var($HashMap$NodeArray, tab, nullptr);
	$var($HashMap$Node, first, nullptr);
	int32_t n = 0;
	int32_t i = 0;
	int32_t binCount = 0;
	$var($HashMap$TreeNode, t, nullptr);
	$var($HashMap$Node, old, nullptr);
	bool var$0 = this->size$ > this->threshold || ($assign(tab, this->table)) == nullptr;
	if (var$0 || (n = $nc(tab)->length) == 0) {
		n = $nc(($assign(tab, resize())))->length;
	}
	if (($assign(first, $nc(tab)->get(i = (int32_t)((n - 1) & (uint32_t)hash)))) != nullptr) {
		if ($instanceOf($HashMap$TreeNode, first)) {
			$assign(old, $nc(($assign(t, $cast($HashMap$TreeNode, first))))->getTreeNode(hash, key));
		} else {
			$var($HashMap$Node, e, first);
			$var($Object, k, nullptr);
			do {
				bool var$1 = $nc(e)->hash == hash;
				if (var$1) {
					bool var$2 = $equals($assign(k, e->key), key);
					var$1 = (var$2 || (key != nullptr && $of(key)->equals(k)));
				}
				if (var$1) {
					$assign(old, e);
					break;
				}
				++binCount;
			} while (($assign(e, $nc(e)->next)) != nullptr);
		}
		$var($Object, oldValue, nullptr);
		if (old != nullptr && ($assign(oldValue, old->value)) != nullptr) {
			afterNodeAccess(old);
			return $of(oldValue);
		}
	}
	int32_t mc = this->modCount;
	$var($Object, v, $nc(mappingFunction)->apply(key));
	if (mc != this->modCount) {
		$throwNew($ConcurrentModificationException);
	}
	if (v == nullptr) {
		return $of(nullptr);
	} else if (old != nullptr) {
		$set(old, value, v);
		afterNodeAccess(old);
		return $of(v);
	} else if (t != nullptr) {
		t->putTreeVal(this, tab, hash, key, v);
	} else {
		$nc(tab)->set(i, $(newNode(hash, key, v, first)));
		if (binCount >= HashMap::TREEIFY_THRESHOLD - 1) {
			treeifyBin(tab, hash);
		}
	}
	this->modCount = mc + 1;
	++this->size$;
	afterNodeInsertion(true);
	return $of(v);
}

$Object* HashMap::computeIfPresent(Object$* key, $BiFunction* remappingFunction) {
	$useLocalCurrentObjectStackCache();
	if (remappingFunction == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($HashMap$Node, e, nullptr);
	$var($Object, oldValue, nullptr);
	if (($assign(e, getNode(key))) != nullptr && ($assign(oldValue, $nc(e)->value)) != nullptr) {
		int32_t mc = this->modCount;
		$var($Object, v, $nc(remappingFunction)->apply(key, oldValue));
		if (mc != this->modCount) {
			$throwNew($ConcurrentModificationException);
		}
		if (v != nullptr) {
			$set(e, value, v);
			afterNodeAccess(e);
			return $of(v);
		} else {
			int32_t hash = HashMap::hash(key);
			removeNode(hash, key, nullptr, false, true);
		}
	}
	return $of(nullptr);
}

$Object* HashMap::compute(Object$* key, $BiFunction* remappingFunction) {
	$useLocalCurrentObjectStackCache();
	if (remappingFunction == nullptr) {
		$throwNew($NullPointerException);
	}
	int32_t hash = HashMap::hash(key);
	$var($HashMap$NodeArray, tab, nullptr);
	$var($HashMap$Node, first, nullptr);
	int32_t n = 0;
	int32_t i = 0;
	int32_t binCount = 0;
	$var($HashMap$TreeNode, t, nullptr);
	$var($HashMap$Node, old, nullptr);
	bool var$0 = this->size$ > this->threshold || ($assign(tab, this->table)) == nullptr;
	if (var$0 || (n = $nc(tab)->length) == 0) {
		n = $nc(($assign(tab, resize())))->length;
	}
	if (($assign(first, $nc(tab)->get(i = (int32_t)((n - 1) & (uint32_t)hash)))) != nullptr) {
		if ($instanceOf($HashMap$TreeNode, first)) {
			$assign(old, $nc(($assign(t, $cast($HashMap$TreeNode, first))))->getTreeNode(hash, key));
		} else {
			$var($HashMap$Node, e, first);
			$var($Object, k, nullptr);
			do {
				bool var$1 = $nc(e)->hash == hash;
				if (var$1) {
					bool var$2 = $equals($assign(k, e->key), key);
					var$1 = (var$2 || (key != nullptr && $of(key)->equals(k)));
				}
				if (var$1) {
					$assign(old, e);
					break;
				}
				++binCount;
			} while (($assign(e, $nc(e)->next)) != nullptr);
		}
	}
	$var($Object, oldValue, (old == nullptr) ? ($Object*)nullptr : $nc(old)->value);
	int32_t mc = this->modCount;
	$var($Object, v, $nc(remappingFunction)->apply(key, oldValue));
	if (mc != this->modCount) {
		$throwNew($ConcurrentModificationException);
	}
	if (old != nullptr) {
		if (v != nullptr) {
			$set(old, value, v);
			afterNodeAccess(old);
		} else {
			removeNode(hash, key, nullptr, false, true);
		}
	} else if (v != nullptr) {
		if (t != nullptr) {
			t->putTreeVal(this, tab, hash, key, v);
		} else {
			$nc(tab)->set(i, $(newNode(hash, key, v, first)));
			if (binCount >= HashMap::TREEIFY_THRESHOLD - 1) {
				treeifyBin(tab, hash);
			}
		}
		this->modCount = mc + 1;
		++this->size$;
		afterNodeInsertion(true);
	}
	return $of(v);
}

$Object* HashMap::merge(Object$* key, Object$* value, $BiFunction* remappingFunction) {
	$useLocalCurrentObjectStackCache();
	if (value == nullptr || remappingFunction == nullptr) {
		$throwNew($NullPointerException);
	}
	int32_t hash = HashMap::hash(key);
	$var($HashMap$NodeArray, tab, nullptr);
	$var($HashMap$Node, first, nullptr);
	int32_t n = 0;
	int32_t i = 0;
	int32_t binCount = 0;
	$var($HashMap$TreeNode, t, nullptr);
	$var($HashMap$Node, old, nullptr);
	bool var$0 = this->size$ > this->threshold || ($assign(tab, this->table)) == nullptr;
	if (var$0 || (n = $nc(tab)->length) == 0) {
		n = $nc(($assign(tab, resize())))->length;
	}
	if (($assign(first, $nc(tab)->get(i = (int32_t)((n - 1) & (uint32_t)hash)))) != nullptr) {
		if ($instanceOf($HashMap$TreeNode, first)) {
			$assign(old, $nc(($assign(t, $cast($HashMap$TreeNode, first))))->getTreeNode(hash, key));
		} else {
			$var($HashMap$Node, e, first);
			$var($Object, k, nullptr);
			do {
				bool var$1 = $nc(e)->hash == hash;
				if (var$1) {
					bool var$2 = $equals($assign(k, e->key), key);
					var$1 = (var$2 || (key != nullptr && $of(key)->equals(k)));
				}
				if (var$1) {
					$assign(old, e);
					break;
				}
				++binCount;
			} while (($assign(e, $nc(e)->next)) != nullptr);
		}
	}
	if (old != nullptr) {
		$var($Object, v, nullptr);
		if (old->value != nullptr) {
			int32_t mc = this->modCount;
			$assign(v, $nc(remappingFunction)->apply(old->value, value));
			if (mc != this->modCount) {
				$throwNew($ConcurrentModificationException);
			}
		} else {
			$assign(v, value);
		}
		if (v != nullptr) {
			$set(old, value, v);
			afterNodeAccess(old);
		} else {
			removeNode(hash, key, nullptr, false, true);
		}
		return $of(v);
	} else {
		if (t != nullptr) {
			t->putTreeVal(this, tab, hash, key, value);
		} else {
			$nc(tab)->set(i, $(newNode(hash, key, value, first)));
			if (binCount >= HashMap::TREEIFY_THRESHOLD - 1) {
				treeifyBin(tab, hash);
			}
		}
		++this->modCount;
		++this->size$;
		afterNodeInsertion(true);
		return $of(value);
	}
}

void HashMap::forEach($BiConsumer* action) {
	$useLocalCurrentObjectStackCache();
	$var($HashMap$NodeArray, tab, nullptr);
	if (action == nullptr) {
		$throwNew($NullPointerException);
	}
	if (this->size$ > 0 && ($assign(tab, this->table)) != nullptr) {
		int32_t mc = this->modCount;
		{
			$var($HashMap$NodeArray, arr$, tab);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($HashMap$Node, e, arr$->get(i$));
				{
					for (; e != nullptr; $assign(e, $nc(e)->next)) {
						$nc(action)->accept(e->key, e->value);
					}
				}
			}
		}
		if (this->modCount != mc) {
			$throwNew($ConcurrentModificationException);
		}
	}
}

void HashMap::replaceAll($BiFunction* function) {
	$useLocalCurrentObjectStackCache();
	$var($HashMap$NodeArray, tab, nullptr);
	if (function == nullptr) {
		$throwNew($NullPointerException);
	}
	if (this->size$ > 0 && ($assign(tab, this->table)) != nullptr) {
		int32_t mc = this->modCount;
		{
			$var($HashMap$NodeArray, arr$, tab);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($HashMap$Node, e, arr$->get(i$));
				{
					for (; e != nullptr; $assign(e, $nc(e)->next)) {
						$set(e, value, $nc(function)->apply(e->key, e->value));
					}
				}
			}
		}
		if (this->modCount != mc) {
			$throwNew($ConcurrentModificationException);
		}
	}
}

$Object* HashMap::clone() {
	$var(HashMap, result, nullptr);
	try {
		$assign(result, $cast(HashMap, $AbstractMap::clone()));
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$nc(result)->reinitialize();
	result->putMapEntries(this, false);
	return $of(result);
}

float HashMap::loadFactor() {
	return this->loadFactor$;
}

int32_t HashMap::capacity() {
	return (this->table != nullptr) ? $nc(this->table)->length : (this->threshold > 0) ? this->threshold : HashMap::DEFAULT_INITIAL_CAPACITY;
}

void HashMap::writeObject($ObjectOutputStream* s) {
	int32_t buckets = capacity();
	$nc(s)->defaultWriteObject();
	s->writeInt(buckets);
	s->writeInt(this->size$);
	internalWriteEntries(s);
}

void HashMap::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	reinitialize();
	if (this->loadFactor$ <= 0 || $Float::isNaN(this->loadFactor$)) {
		$throwNew($InvalidObjectException, $$str({"Illegal load factor: "_s, $$str(this->loadFactor$)}));
	}
	s->readInt();
	int32_t mappings = s->readInt();
	if (mappings < 0) {
		$throwNew($InvalidObjectException, $$str({"Illegal mappings count: "_s, $$str(mappings)}));
	} else if (mappings > 0) {
		float lf = $Math::min($Math::max(0.25f, this->loadFactor$), 4.0f);
		float fc = (float)mappings / lf + 1.0f;
		int32_t cap = ((fc < HashMap::DEFAULT_INITIAL_CAPACITY) ? HashMap::DEFAULT_INITIAL_CAPACITY : (fc >= HashMap::MAXIMUM_CAPACITY) ? HashMap::MAXIMUM_CAPACITY : tableSizeFor($cast(int32_t, fc)));
		float ft = (float)cap * lf;
		this->threshold = ((cap < HashMap::MAXIMUM_CAPACITY && ft < HashMap::MAXIMUM_CAPACITY) ? $cast(int32_t, ft) : $Integer::MAX_VALUE);
		$load($Map$EntryArray);
		$nc($($SharedSecrets::getJavaObjectInputStreamAccess()))->checkArray(s, $getClass($Map$EntryArray), cap);
		$var($HashMap$NodeArray, tab, $new($HashMap$NodeArray, cap));
		$set(this, table, tab);
		for (int32_t i = 0; i < mappings; ++i) {
			$var($Object, key, s->readObject());
			$var($Object, value, s->readObject());
			putVal(hash(key), key, value, false, false);
		}
	}
}

$HashMap$Node* HashMap::newNode(int32_t hash, Object$* key, Object$* value, $HashMap$Node* next) {
	return $new($HashMap$Node, hash, key, value, next);
}

$HashMap$Node* HashMap::replacementNode($HashMap$Node* p, $HashMap$Node* next) {
	return $new($HashMap$Node, $nc(p)->hash, p->key, p->value, next);
}

$HashMap$TreeNode* HashMap::newTreeNode(int32_t hash, Object$* key, Object$* value, $HashMap$Node* next) {
	return $new($HashMap$TreeNode, hash, key, value, next);
}

$HashMap$TreeNode* HashMap::replacementTreeNode($HashMap$Node* p, $HashMap$Node* next) {
	return $new($HashMap$TreeNode, $nc(p)->hash, p->key, p->value, next);
}

void HashMap::reinitialize() {
	$set(this, table, nullptr);
	$set(this, entrySet$, nullptr);
	$set(this, keySet$, nullptr);
	$set(this, values$, nullptr);
	this->modCount = 0;
	this->threshold = 0;
	this->size$ = 0;
}

void HashMap::afterNodeAccess($HashMap$Node* p) {
}

void HashMap::afterNodeInsertion(bool evict) {
}

void HashMap::afterNodeRemoval($HashMap$Node* p) {
}

void HashMap::internalWriteEntries($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$var($HashMap$NodeArray, tab, nullptr);
	if (this->size$ > 0 && ($assign(tab, this->table)) != nullptr) {
		{
			$var($HashMap$NodeArray, arr$, tab);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($HashMap$Node, e, arr$->get(i$));
				{
					for (; e != nullptr; $assign(e, $nc(e)->next)) {
						$nc(s)->writeObject(e->key);
						s->writeObject(e->value);
					}
				}
			}
		}
	}
}

HashMap::HashMap() {
}

void clinit$HashMap($Class* class$) {
	HashMap::DEFAULT_LOAD_FACTOR = 0.75f;
}

$Class* HashMap::load$($String* name, bool initialize) {
	$loadClass(HashMap, name, initialize, &_HashMap_ClassInfo_, clinit$HashMap, allocate$HashMap);
	return class$;
}

$Class* HashMap::class$ = nullptr;

	} // util
} // java