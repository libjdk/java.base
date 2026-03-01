#include <java/util/LinkedHashMap.h>

#include <java/io/ObjectOutputStream.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/HashMap$Node.h>
#include <java/util/HashMap$TreeNode.h>
#include <java/util/HashMap.h>
#include <java/util/LinkedHashMap$Entry.h>
#include <java/util/LinkedHashMap$LinkedEntrySet.h>
#include <java/util/LinkedHashMap$LinkedKeySet.h>
#include <java/util/LinkedHashMap$LinkedValues.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <jcpp.h>

using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $HashMap = ::java::util::HashMap;
using $HashMap$Node = ::java::util::HashMap$Node;
using $HashMap$TreeNode = ::java::util::HashMap$TreeNode;
using $LinkedHashMap$Entry = ::java::util::LinkedHashMap$Entry;
using $LinkedHashMap$LinkedEntrySet = ::java::util::LinkedHashMap$LinkedEntrySet;
using $LinkedHashMap$LinkedKeySet = ::java::util::LinkedHashMap$LinkedKeySet;
using $LinkedHashMap$LinkedValues = ::java::util::LinkedHashMap$LinkedValues;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;

namespace java {
	namespace util {

$FieldInfo _LinkedHashMap_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinkedHashMap, serialVersionUID)},
	{"head", "Ljava/util/LinkedHashMap$Entry;", "Ljava/util/LinkedHashMap$Entry<TK;TV;>;", $TRANSIENT, $field(LinkedHashMap, head)},
	{"tail", "Ljava/util/LinkedHashMap$Entry;", "Ljava/util/LinkedHashMap$Entry<TK;TV;>;", $TRANSIENT, $field(LinkedHashMap, tail)},
	{"accessOrder", "Z", nullptr, $FINAL, $field(LinkedHashMap, accessOrder)},
	{}
};

$MethodInfo _LinkedHashMap_MethodInfo_[] = {
	{"<init>", "(IF)V", nullptr, $PUBLIC, $method(LinkedHashMap, init$, void, int32_t, float)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(LinkedHashMap, init$, void, int32_t)},
	{"<init>", "()V", nullptr, $PUBLIC, $method(LinkedHashMap, init$, void)},
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<+TK;+TV;>;)V", $PUBLIC, $method(LinkedHashMap, init$, void, $Map*)},
	{"<init>", "(IFZ)V", nullptr, $PUBLIC, $method(LinkedHashMap, init$, void, int32_t, float, bool)},
	{"afterNodeAccess", "(Ljava/util/HashMap$Node;)V", "(Ljava/util/HashMap$Node<TK;TV;>;)V", 0, $virtualMethod(LinkedHashMap, afterNodeAccess, void, $HashMap$Node*)},
	{"afterNodeInsertion", "(Z)V", nullptr, 0, $virtualMethod(LinkedHashMap, afterNodeInsertion, void, bool)},
	{"afterNodeRemoval", "(Ljava/util/HashMap$Node;)V", "(Ljava/util/HashMap$Node<TK;TV;>;)V", 0, $virtualMethod(LinkedHashMap, afterNodeRemoval, void, $HashMap$Node*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(LinkedHashMap, clear, void)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LinkedHashMap, containsValue, bool, Object$*)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(LinkedHashMap, entrySet, $Set*)},
	{"forEach", "(Ljava/util/function/BiConsumer;)V", "(Ljava/util/function/BiConsumer<-TK;-TV;>;)V", $PUBLIC, $virtualMethod(LinkedHashMap, forEach, void, $BiConsumer*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(LinkedHashMap, get, $Object*, Object$*)},
	{"getOrDefault", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;TV;)TV;", $PUBLIC, $virtualMethod(LinkedHashMap, getOrDefault, $Object*, Object$*, Object$*)},
	{"internalWriteEntries", "(Ljava/io/ObjectOutputStream;)V", nullptr, 0, $virtualMethod(LinkedHashMap, internalWriteEntries, void, $ObjectOutputStream*), "java.io.IOException"},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<TK;>;", $PUBLIC, $virtualMethod(LinkedHashMap, keySet, $Set*)},
	{"keysToArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $FINAL, $virtualMethod(LinkedHashMap, keysToArray, $ObjectArray*, $ObjectArray*)},
	{"linkNodeLast", "(Ljava/util/LinkedHashMap$Entry;)V", "(Ljava/util/LinkedHashMap$Entry<TK;TV;>;)V", $PRIVATE, $method(LinkedHashMap, linkNodeLast, void, $LinkedHashMap$Entry*)},
	{"newNode", "(ILjava/lang/Object;Ljava/lang/Object;Ljava/util/HashMap$Node;)Ljava/util/HashMap$Node;", "(ITK;TV;Ljava/util/HashMap$Node<TK;TV;>;)Ljava/util/HashMap$Node<TK;TV;>;", 0, $virtualMethod(LinkedHashMap, newNode, $HashMap$Node*, int32_t, Object$*, Object$*, $HashMap$Node*)},
	{"newTreeNode", "(ILjava/lang/Object;Ljava/lang/Object;Ljava/util/HashMap$Node;)Ljava/util/HashMap$TreeNode;", "(ITK;TV;Ljava/util/HashMap$Node<TK;TV;>;)Ljava/util/HashMap$TreeNode<TK;TV;>;", 0, $virtualMethod(LinkedHashMap, newTreeNode, $HashMap$TreeNode*, int32_t, Object$*, Object$*, $HashMap$Node*)},
	{"reinitialize", "()V", nullptr, 0, $virtualMethod(LinkedHashMap, reinitialize, void)},
	{"removeEldestEntry", "(Ljava/util/Map$Entry;)Z", "(Ljava/util/Map$Entry<TK;TV;>;)Z", $PROTECTED, $virtualMethod(LinkedHashMap, removeEldestEntry, bool, $Map$Entry*)},
	{"replaceAll", "(Ljava/util/function/BiFunction;)V", "(Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)V", $PUBLIC, $virtualMethod(LinkedHashMap, replaceAll, void, $BiFunction*)},
	{"replacementNode", "(Ljava/util/HashMap$Node;Ljava/util/HashMap$Node;)Ljava/util/HashMap$Node;", "(Ljava/util/HashMap$Node<TK;TV;>;Ljava/util/HashMap$Node<TK;TV;>;)Ljava/util/HashMap$Node<TK;TV;>;", 0, $virtualMethod(LinkedHashMap, replacementNode, $HashMap$Node*, $HashMap$Node*, $HashMap$Node*)},
	{"replacementTreeNode", "(Ljava/util/HashMap$Node;Ljava/util/HashMap$Node;)Ljava/util/HashMap$TreeNode;", "(Ljava/util/HashMap$Node<TK;TV;>;Ljava/util/HashMap$Node<TK;TV;>;)Ljava/util/HashMap$TreeNode<TK;TV;>;", 0, $virtualMethod(LinkedHashMap, replacementTreeNode, $HashMap$TreeNode*, $HashMap$Node*, $HashMap$Node*)},
	{"transferLinks", "(Ljava/util/LinkedHashMap$Entry;Ljava/util/LinkedHashMap$Entry;)V", "(Ljava/util/LinkedHashMap$Entry<TK;TV;>;Ljava/util/LinkedHashMap$Entry<TK;TV;>;)V", $PRIVATE, $method(LinkedHashMap, transferLinks, void, $LinkedHashMap$Entry*, $LinkedHashMap$Entry*)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<TV;>;", $PUBLIC, $virtualMethod(LinkedHashMap, values, $Collection*)},
	{"valuesToArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $FINAL, $virtualMethod(LinkedHashMap, valuesToArray, $ObjectArray*, $ObjectArray*)},
	{}
};

$InnerClassInfo _LinkedHashMap_InnerClassesInfo_[] = {
	{"java.util.LinkedHashMap$LinkedEntryIterator", "java.util.LinkedHashMap", "LinkedEntryIterator", $FINAL},
	{"java.util.LinkedHashMap$LinkedValueIterator", "java.util.LinkedHashMap", "LinkedValueIterator", $FINAL},
	{"java.util.LinkedHashMap$LinkedKeyIterator", "java.util.LinkedHashMap", "LinkedKeyIterator", $FINAL},
	{"java.util.LinkedHashMap$LinkedHashIterator", "java.util.LinkedHashMap", "LinkedHashIterator", $ABSTRACT},
	{"java.util.LinkedHashMap$LinkedEntrySet", "java.util.LinkedHashMap", "LinkedEntrySet", $FINAL},
	{"java.util.LinkedHashMap$LinkedValues", "java.util.LinkedHashMap", "LinkedValues", $FINAL},
	{"java.util.LinkedHashMap$LinkedKeySet", "java.util.LinkedHashMap", "LinkedKeySet", $FINAL},
	{"java.util.LinkedHashMap$Entry", "java.util.LinkedHashMap", "Entry", $STATIC},
	{}
};

$ClassInfo _LinkedHashMap_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.LinkedHashMap",
	"java.util.HashMap",
	nullptr,
	_LinkedHashMap_FieldInfo_,
	_LinkedHashMap_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/HashMap<TK;TV;>;Ljava/util/Map<TK;TV;>;",
	nullptr,
	_LinkedHashMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.LinkedHashMap$LinkedEntryIterator,java.util.LinkedHashMap$LinkedValueIterator,java.util.LinkedHashMap$LinkedKeyIterator,java.util.LinkedHashMap$LinkedHashIterator,java.util.LinkedHashMap$LinkedEntrySet,java.util.LinkedHashMap$LinkedValues,java.util.LinkedHashMap$LinkedKeySet,java.util.LinkedHashMap$Entry"
};

$Object* allocate$LinkedHashMap($Class* clazz) {
	return $of($alloc(LinkedHashMap));
}

void LinkedHashMap::linkNodeLast($LinkedHashMap$Entry* p) {
	$var($LinkedHashMap$Entry, last, this->tail);
	$set(this, tail, p);
	if (last == nullptr) {
		$set(this, head, p);
	} else {
		$set($nc(p), before, last);
		$set($nc(last), after, p);
	}
}

void LinkedHashMap::transferLinks($LinkedHashMap$Entry* src, $LinkedHashMap$Entry* dst) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedHashMap$Entry, b, $set($nc(dst), before, $nc(src)->before));
	$var($LinkedHashMap$Entry, a, $set(dst, after, src->after));
	if (b == nullptr) {
		$set(this, head, dst);
	} else {
		$set($nc(b), after, dst);
	}
	if (a == nullptr) {
		$set(this, tail, dst);
	} else {
		$set($nc(a), before, dst);
	}
}

void LinkedHashMap::reinitialize() {
	$HashMap::reinitialize();
	$set(this, head, ($set(this, tail, nullptr)));
}

$HashMap$Node* LinkedHashMap::newNode(int32_t hash, Object$* key, Object$* value, $HashMap$Node* e) {
	$var($LinkedHashMap$Entry, p, $new($LinkedHashMap$Entry, hash, key, value, e));
	linkNodeLast(p);
	return p;
}

$HashMap$Node* LinkedHashMap::replacementNode($HashMap$Node* p, $HashMap$Node* next) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedHashMap$Entry, q, $cast($LinkedHashMap$Entry, p));
	$var($LinkedHashMap$Entry, t, $new($LinkedHashMap$Entry, $nc(q)->hash, q->key, q->value, next));
	transferLinks(q, t);
	return t;
}

$HashMap$TreeNode* LinkedHashMap::newTreeNode(int32_t hash, Object$* key, Object$* value, $HashMap$Node* next) {
	$var($HashMap$TreeNode, p, $new($HashMap$TreeNode, hash, key, value, next));
	linkNodeLast(p);
	return p;
}

$HashMap$TreeNode* LinkedHashMap::replacementTreeNode($HashMap$Node* p, $HashMap$Node* next) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedHashMap$Entry, q, $cast($LinkedHashMap$Entry, p));
	$var($HashMap$TreeNode, t, $new($HashMap$TreeNode, $nc(q)->hash, q->key, q->value, next));
	transferLinks(q, t);
	return t;
}

void LinkedHashMap::afterNodeRemoval($HashMap$Node* e) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedHashMap$Entry, p, $cast($LinkedHashMap$Entry, e));
	$var($LinkedHashMap$Entry, b, $nc(p)->before);
	$var($LinkedHashMap$Entry, a, p->after);
	$set(p, before, ($set(p, after, nullptr)));
	if (b == nullptr) {
		$set(this, head, a);
	} else {
		$set($nc(b), after, a);
	}
	if (a == nullptr) {
		$set(this, tail, b);
	} else {
		$set($nc(a), before, b);
	}
}

void LinkedHashMap::afterNodeInsertion(bool evict) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedHashMap$Entry, first, nullptr);
	bool var$0 = evict && ($assign(first, this->head)) != nullptr;
	if (var$0 && removeEldestEntry(first)) {
		$var($Object, key, $nc(first)->key);
		removeNode(hash(key), key, nullptr, false, true);
	}
}

void LinkedHashMap::afterNodeAccess($HashMap$Node* e) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedHashMap$Entry, last, nullptr);
	if (this->accessOrder && !$equals($assign(last, this->tail), e)) {
		$var($LinkedHashMap$Entry, p, $cast($LinkedHashMap$Entry, e));
		$var($LinkedHashMap$Entry, b, $nc(p)->before);
		$var($LinkedHashMap$Entry, a, p->after);
		$set(p, after, nullptr);
		if (b == nullptr) {
			$set(this, head, a);
		} else {
			$set($nc(b), after, a);
		}
		if (a != nullptr) {
			$set(a, before, b);
		} else {
			$assign(last, b);
		}
		if (last == nullptr) {
			$set(this, head, p);
		} else {
			$set(p, before, last);
			$set($nc(last), after, p);
		}
		$set(this, tail, p);
		++this->modCount;
	}
}

void LinkedHashMap::internalWriteEntries($ObjectOutputStream* s) {
	{
		$var($LinkedHashMap$Entry, e, this->head);
		for (; e != nullptr; $assign(e, $nc(e)->after)) {
			$nc(s)->writeObject(e->key);
			s->writeObject(e->value);
		}
	}
}

void LinkedHashMap::init$(int32_t initialCapacity, float loadFactor) {
	$HashMap::init$(initialCapacity, loadFactor);
	this->accessOrder = false;
}

void LinkedHashMap::init$(int32_t initialCapacity) {
	$HashMap::init$(initialCapacity);
	this->accessOrder = false;
}

void LinkedHashMap::init$() {
	$HashMap::init$();
	this->accessOrder = false;
}

void LinkedHashMap::init$($Map* m) {
	$HashMap::init$();
	this->accessOrder = false;
	putMapEntries(m, false);
}

void LinkedHashMap::init$(int32_t initialCapacity, float loadFactor, bool accessOrder) {
	$HashMap::init$(initialCapacity, loadFactor);
	this->accessOrder = accessOrder;
}

bool LinkedHashMap::containsValue(Object$* value) {
	$useLocalCurrentObjectStackCache();
	{
		$var($LinkedHashMap$Entry, e, this->head);
		for (; e != nullptr; $assign(e, $nc(e)->after)) {
			$var($Object, v, e->value);
			if ($equals(v, value) || (value != nullptr && $of(value)->equals(v))) {
				return true;
			}
		}
	}
	return false;
}

$Object* LinkedHashMap::get(Object$* key) {
	$var($HashMap$Node, e, nullptr);
	if (($assign(e, getNode(key))) == nullptr) {
		return $of(nullptr);
	}
	if (this->accessOrder) {
		afterNodeAccess(e);
	}
	return $of($nc(e)->value);
}

$Object* LinkedHashMap::getOrDefault(Object$* key, Object$* defaultValue) {
	$var($HashMap$Node, e, nullptr);
	if (($assign(e, getNode(key))) == nullptr) {
		return $of(defaultValue);
	}
	if (this->accessOrder) {
		afterNodeAccess(e);
	}
	return $of($nc(e)->value);
}

void LinkedHashMap::clear() {
	$HashMap::clear();
	$set(this, head, ($set(this, tail, nullptr)));
}

bool LinkedHashMap::removeEldestEntry($Map$Entry* eldest) {
	return false;
}

$Set* LinkedHashMap::keySet() {
	$var($Set, ks, this->$AbstractMap::keySet$);
	if (ks == nullptr) {
		$assign(ks, $new($LinkedHashMap$LinkedKeySet, this));
		$set(this, keySet$, ks);
	}
	return ks;
}

$ObjectArray* LinkedHashMap::keysToArray($ObjectArray* a) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, r, a);
	int32_t idx = 0;
	{
		$var($LinkedHashMap$Entry, e, this->head);
		for (; e != nullptr; $assign(e, $nc(e)->after)) {
			$nc(r)->set(idx++, e->key);
		}
	}
	return a;
}

$ObjectArray* LinkedHashMap::valuesToArray($ObjectArray* a) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, r, a);
	int32_t idx = 0;
	{
		$var($LinkedHashMap$Entry, e, this->head);
		for (; e != nullptr; $assign(e, $nc(e)->after)) {
			$nc(r)->set(idx++, e->value);
		}
	}
	return a;
}

$Collection* LinkedHashMap::values() {
	$var($Collection, vs, this->$AbstractMap::values$);
	if (vs == nullptr) {
		$assign(vs, $new($LinkedHashMap$LinkedValues, this));
		$set(this, values$, vs);
	}
	return vs;
}

$Set* LinkedHashMap::entrySet() {
	$var($Set, es, nullptr);
	return ($assign(es, this->$HashMap::entrySet$)) == nullptr ? ($set(this, entrySet$, $new($LinkedHashMap$LinkedEntrySet, this))) : es;
}

void LinkedHashMap::forEach($BiConsumer* action) {
	if (action == nullptr) {
		$throwNew($NullPointerException);
	}
	int32_t mc = this->modCount;
	{
		$var($LinkedHashMap$Entry, e, this->head);
		for (; e != nullptr; $assign(e, $nc(e)->after)) {
			$nc(action)->accept(e->key, e->value);
		}
	}
	if (this->modCount != mc) {
		$throwNew($ConcurrentModificationException);
	}
}

void LinkedHashMap::replaceAll($BiFunction* function) {
	if (function == nullptr) {
		$throwNew($NullPointerException);
	}
	int32_t mc = this->modCount;
	{
		$var($LinkedHashMap$Entry, e, this->head);
		for (; e != nullptr; $assign(e, $nc(e)->after)) {
			$set(e, value, $nc(function)->apply(e->key, e->value));
		}
	}
	if (this->modCount != mc) {
		$throwNew($ConcurrentModificationException);
	}
}

LinkedHashMap::LinkedHashMap() {
}

$Class* LinkedHashMap::load$($String* name, bool initialize) {
	$loadClass(LinkedHashMap, name, initialize, &_LinkedHashMap_ClassInfo_, allocate$LinkedHashMap);
	return class$;
}

$Class* LinkedHashMap::class$ = nullptr;

	} // util
} // java