#include <java/util/concurrent/ConcurrentSkipListSet.h>

#include <java/io/Serializable.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InternalError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Field.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/NavigableMap.h>
#include <java/util/NavigableSet.h>
#include <java/util/Set.h>
#include <java/util/SortedMap.h>
#include <java/util/SortedSet.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/ConcurrentNavigableMap.h>
#include <java/util/concurrent/ConcurrentSkipListMap$KeySpliterator.h>
#include <java/util/concurrent/ConcurrentSkipListMap$SubMap$SubMapKeyIterator.h>
#include <java/util/concurrent/ConcurrentSkipListMap$SubMap.h>
#include <java/util/concurrent/ConcurrentSkipListMap.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef TRUE

using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Field = ::java::lang::reflect::Field;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $Comparator = ::java::util::Comparator;
using $Iterator = ::java::util::Iterator;
using $Map$Entry = ::java::util::Map$Entry;
using $NavigableSet = ::java::util::NavigableSet;
using $Set = ::java::util::Set;
using $SortedMap = ::java::util::SortedMap;
using $SortedSet = ::java::util::SortedSet;
using $Spliterator = ::java::util::Spliterator;
using $ConcurrentNavigableMap = ::java::util::concurrent::ConcurrentNavigableMap;
using $ConcurrentSkipListMap = ::java::util::concurrent::ConcurrentSkipListMap;
using $ConcurrentSkipListMap$SubMap = ::java::util::concurrent::ConcurrentSkipListMap$SubMap;
using $ConcurrentSkipListMap$SubMap$SubMapKeyIterator = ::java::util::concurrent::ConcurrentSkipListMap$SubMap$SubMapKeyIterator;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace util {
		namespace concurrent {

class ConcurrentSkipListSet$$Lambda$lambda$setMap$0 : public $PrivilegedAction {
	$class(ConcurrentSkipListSet$$Lambda$lambda$setMap$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(ConcurrentSkipListSet::lambda$setMap$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ConcurrentSkipListSet$$Lambda$lambda$setMap$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ConcurrentSkipListSet$$Lambda$lambda$setMap$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ConcurrentSkipListSet$$Lambda$lambda$setMap$0, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListSet$$Lambda$lambda$setMap$0, run, $Object*)},
	{}
};
$ClassInfo ConcurrentSkipListSet$$Lambda$lambda$setMap$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.concurrent.ConcurrentSkipListSet$$Lambda$lambda$setMap$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* ConcurrentSkipListSet$$Lambda$lambda$setMap$0::load$($String* name, bool initialize) {
	$loadClass(ConcurrentSkipListSet$$Lambda$lambda$setMap$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ConcurrentSkipListSet$$Lambda$lambda$setMap$0::class$ = nullptr;

$FieldInfo _ConcurrentSkipListSet_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConcurrentSkipListSet, serialVersionUID)},
	{"m", "Ljava/util/concurrent/ConcurrentNavigableMap;", "Ljava/util/concurrent/ConcurrentNavigableMap<TE;Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(ConcurrentSkipListSet, m)},
	{}
};

$MethodInfo _ConcurrentSkipListSet_MethodInfo_[] = {
	{"*addAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"*containsAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEach", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PUBLIC, $method(ConcurrentSkipListSet, init$, void)},
	{"<init>", "(Ljava/util/Comparator;)V", "(Ljava/util/Comparator<-TE;>;)V", $PUBLIC, $method(ConcurrentSkipListSet, init$, void, $Comparator*)},
	{"<init>", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PUBLIC, $method(ConcurrentSkipListSet, init$, void, $Collection*)},
	{"<init>", "(Ljava/util/SortedSet;)V", "(Ljava/util/SortedSet<TE;>;)V", $PUBLIC, $method(ConcurrentSkipListSet, init$, void, $SortedSet*)},
	{"<init>", "(Ljava/util/concurrent/ConcurrentNavigableMap;)V", "(Ljava/util/concurrent/ConcurrentNavigableMap<TE;Ljava/lang/Object;>;)V", 0, $method(ConcurrentSkipListSet, init$, void, $ConcurrentNavigableMap*)},
	{"add", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, add, bool, Object$*)},
	{"ceiling", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TE;)TE;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, ceiling, $Object*, Object$*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListSet, clear, void)},
	{"clone", "()Ljava/util/concurrent/ConcurrentSkipListSet;", "()Ljava/util/concurrent/ConcurrentSkipListSet<TE;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, clone, $Object*)},
	{"comparator", "()Ljava/util/Comparator;", "()Ljava/util/Comparator<-TE;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, comparator, $Comparator*)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListSet, contains, bool, Object$*)},
	{"descendingIterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, descendingIterator, $Iterator*)},
	{"descendingSet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TE;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, descendingSet, $NavigableSet*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListSet, equals, bool, Object$*)},
	{"first", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, first, $Object*)},
	{"floor", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TE;)TE;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, floor, $Object*, Object$*)},
	{"headSet", "(Ljava/lang/Object;Z)Ljava/util/NavigableSet;", "(TE;Z)Ljava/util/NavigableSet<TE;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, headSet, $NavigableSet*, Object$*, bool)},
	{"headSet", "(Ljava/lang/Object;)Ljava/util/NavigableSet;", "(TE;)Ljava/util/NavigableSet<TE;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, headSet, $SortedSet*, Object$*)},
	{"higher", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TE;)TE;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, higher, $Object*, Object$*)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListSet, isEmpty, bool)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, iterator, $Iterator*)},
	{"lambda$setMap$0", "()Ljava/lang/reflect/Field;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ConcurrentSkipListSet, lambda$setMap$0, $Field*)},
	{"last", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, last, $Object*)},
	{"lower", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TE;)TE;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, lower, $Object*, Object$*)},
	{"*parallelStream", "()Ljava/util/stream/Stream;", nullptr, $PUBLIC | $ABSTRACT},
	{"pollFirst", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, pollFirst, $Object*)},
	{"pollLast", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, pollLast, $Object*)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListSet, remove, bool, Object$*)},
	{"removeAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, removeAll, bool, $Collection*)},
	{"*removeIf", "(Ljava/util/function/Predicate;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*retainAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"setMap", "(Ljava/util/concurrent/ConcurrentNavigableMap;)V", "(Ljava/util/concurrent/ConcurrentNavigableMap<TE;Ljava/lang/Object;>;)V", $PRIVATE, $method(ConcurrentSkipListSet, setMap, void, $ConcurrentNavigableMap*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListSet, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, spliterator, $Spliterator*)},
	{"*stream", "()Ljava/util/stream/Stream;", nullptr, $PUBLIC | $ABSTRACT},
	{"subSet", "(Ljava/lang/Object;ZLjava/lang/Object;Z)Ljava/util/NavigableSet;", "(TE;ZTE;Z)Ljava/util/NavigableSet<TE;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, subSet, $NavigableSet*, Object$*, bool, Object$*, bool)},
	{"subSet", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/NavigableSet;", "(TE;TE;)Ljava/util/NavigableSet<TE;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, subSet, $SortedSet*, Object$*, Object$*)},
	{"tailSet", "(Ljava/lang/Object;Z)Ljava/util/NavigableSet;", "(TE;Z)Ljava/util/NavigableSet<TE;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, tailSet, $NavigableSet*, Object$*, bool)},
	{"tailSet", "(Ljava/lang/Object;)Ljava/util/NavigableSet;", "(TE;)Ljava/util/NavigableSet<TE;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListSet, tailSet, $SortedSet*, Object$*)},
	{"*toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*toArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _ConcurrentSkipListSet_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.ConcurrentSkipListSet",
	"java.util.AbstractSet",
	"java.util.NavigableSet,java.lang.Cloneable,java.io.Serializable",
	_ConcurrentSkipListSet_FieldInfo_,
	_ConcurrentSkipListSet_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/util/AbstractSet<TE;>;Ljava/util/NavigableSet<TE;>;Ljava/lang/Cloneable;Ljava/io/Serializable;"
};

$Object* allocate$ConcurrentSkipListSet($Class* clazz) {
	return $of($alloc(ConcurrentSkipListSet));
}

int32_t ConcurrentSkipListSet::hashCode() {
	 return this->$AbstractSet::hashCode();
}

$ObjectArray* ConcurrentSkipListSet::toArray() {
	 return this->$AbstractSet::toArray();
}

$ObjectArray* ConcurrentSkipListSet::toArray($ObjectArray* a) {
	 return this->$AbstractSet::toArray(a);
}

bool ConcurrentSkipListSet::containsAll($Collection* c) {
	 return this->$AbstractSet::containsAll(c);
}

bool ConcurrentSkipListSet::addAll($Collection* c) {
	 return this->$AbstractSet::addAll(c);
}

bool ConcurrentSkipListSet::retainAll($Collection* c) {
	 return this->$AbstractSet::retainAll(c);
}

$String* ConcurrentSkipListSet::toString() {
	 return this->$AbstractSet::toString();
}

$ObjectArray* ConcurrentSkipListSet::toArray($IntFunction* generator) {
	 return this->$AbstractSet::toArray(generator);
}

bool ConcurrentSkipListSet::removeIf($Predicate* filter) {
	 return this->$AbstractSet::removeIf(filter);
}

$Stream* ConcurrentSkipListSet::stream() {
	 return this->$AbstractSet::stream();
}

$Stream* ConcurrentSkipListSet::parallelStream() {
	 return this->$AbstractSet::parallelStream();
}

void ConcurrentSkipListSet::forEach($Consumer* action) {
	this->$AbstractSet::forEach(action);
}

void ConcurrentSkipListSet::finalize() {
	this->$AbstractSet::finalize();
}

void ConcurrentSkipListSet::init$() {
	$AbstractSet::init$();
	$set(this, m, $new($ConcurrentSkipListMap));
}

void ConcurrentSkipListSet::init$($Comparator* comparator) {
	$AbstractSet::init$();
	$set(this, m, $new($ConcurrentSkipListMap, comparator));
}

void ConcurrentSkipListSet::init$($Collection* c) {
	$AbstractSet::init$();
	$set(this, m, $new($ConcurrentSkipListMap));
	addAll(c);
}

void ConcurrentSkipListSet::init$($SortedSet* s) {
	$AbstractSet::init$();
	$set(this, m, $new($ConcurrentSkipListMap, $($nc(s)->comparator())));
	addAll(s);
}

void ConcurrentSkipListSet::init$($ConcurrentNavigableMap* m) {
	$AbstractSet::init$();
	$set(this, m, m);
}

$Object* ConcurrentSkipListSet::clone() {
	$useLocalCurrentObjectStackCache();
	try {
		$var(ConcurrentSkipListSet, clone, $cast(ConcurrentSkipListSet, $AbstractSet::clone()));
		$nc(clone)->setMap($$new($ConcurrentSkipListMap, static_cast<$SortedMap*>(this->m)));
		return $of(clone);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

int32_t ConcurrentSkipListSet::size() {
	return $nc(this->m)->size();
}

bool ConcurrentSkipListSet::isEmpty() {
	return $nc(this->m)->isEmpty();
}

bool ConcurrentSkipListSet::contains(Object$* o) {
	return $nc(this->m)->containsKey(o);
}

bool ConcurrentSkipListSet::add(Object$* e) {
	$init($Boolean);
	return $nc(this->m)->putIfAbsent(e, $Boolean::TRUE) == nullptr;
}

bool ConcurrentSkipListSet::remove(Object$* o) {
	$init($Boolean);
	return $nc(this->m)->remove(o, $Boolean::TRUE);
}

void ConcurrentSkipListSet::clear() {
	$nc(this->m)->clear();
}

$Iterator* ConcurrentSkipListSet::iterator() {
	return $nc($($nc(this->m)->navigableKeySet()))->iterator();
}

$Iterator* ConcurrentSkipListSet::descendingIterator() {
	return $nc($($nc(this->m)->descendingKeySet()))->iterator();
}

bool ConcurrentSkipListSet::equals(Object$* o) {
	if ($equals(o, this)) {
		return true;
	}
	if (!($instanceOf($Set, o))) {
		return false;
	}
	$var($Collection, c, $cast($Collection, o));
	try {
		bool var$0 = containsAll(c);
		return var$0 && $nc(c)->containsAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this))));
	} catch ($ClassCastException& unused) {
		return false;
	} catch ($NullPointerException& unused) {
		return false;
	}
	$shouldNotReachHere();
}

bool ConcurrentSkipListSet::removeAll($Collection* c) {
	$useLocalCurrentObjectStackCache();
	bool modified = false;
	{
		$var($Iterator, i$, $nc(c)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, e, i$->next());
			if (remove(e)) {
				modified = true;
			}
		}
	}
	return modified;
}

$Object* ConcurrentSkipListSet::lower(Object$* e) {
	return $of($nc(this->m)->lowerKey(e));
}

$Object* ConcurrentSkipListSet::floor(Object$* e) {
	return $of($nc(this->m)->floorKey(e));
}

$Object* ConcurrentSkipListSet::ceiling(Object$* e) {
	return $of($nc(this->m)->ceilingKey(e));
}

$Object* ConcurrentSkipListSet::higher(Object$* e) {
	return $of($nc(this->m)->higherKey(e));
}

$Object* ConcurrentSkipListSet::pollFirst() {
	$var($Map$Entry, e, $nc(this->m)->pollFirstEntry());
	return $of((e == nullptr) ? ($Object*)nullptr : $nc(e)->getKey());
}

$Object* ConcurrentSkipListSet::pollLast() {
	$var($Map$Entry, e, $nc(this->m)->pollLastEntry());
	return $of((e == nullptr) ? ($Object*)nullptr : $nc(e)->getKey());
}

$Comparator* ConcurrentSkipListSet::comparator() {
	return $nc(this->m)->comparator();
}

$Object* ConcurrentSkipListSet::first() {
	return $of($nc(this->m)->firstKey());
}

$Object* ConcurrentSkipListSet::last() {
	return $of($nc(this->m)->lastKey());
}

$NavigableSet* ConcurrentSkipListSet::subSet(Object$* fromElement, bool fromInclusive, Object$* toElement, bool toInclusive) {
	return $new(ConcurrentSkipListSet, $($cast($ConcurrentNavigableMap, $nc(this->m)->subMap(fromElement, fromInclusive, toElement, toInclusive))));
}

$NavigableSet* ConcurrentSkipListSet::headSet(Object$* toElement, bool inclusive) {
	return $new(ConcurrentSkipListSet, $($cast($ConcurrentNavigableMap, $nc(this->m)->headMap(toElement, inclusive))));
}

$NavigableSet* ConcurrentSkipListSet::tailSet(Object$* fromElement, bool inclusive) {
	return $new(ConcurrentSkipListSet, $($cast($ConcurrentNavigableMap, $nc(this->m)->tailMap(fromElement, inclusive))));
}

$SortedSet* ConcurrentSkipListSet::subSet(Object$* fromElement, Object$* toElement) {
	return subSet(fromElement, true, toElement, false);
}

$SortedSet* ConcurrentSkipListSet::headSet(Object$* toElement) {
	return headSet(toElement, false);
}

$SortedSet* ConcurrentSkipListSet::tailSet(Object$* fromElement) {
	return tailSet(fromElement, true);
}

$NavigableSet* ConcurrentSkipListSet::descendingSet() {
	return $new(ConcurrentSkipListSet, $($cast($ConcurrentNavigableMap, $nc(this->m)->descendingMap())));
}

$Spliterator* ConcurrentSkipListSet::spliterator() {
	return ($instanceOf($ConcurrentSkipListMap, this->m)) ? static_cast<$Spliterator*>($nc(($cast($ConcurrentSkipListMap, this->m)))->keySpliterator()) : static_cast<$Spliterator*>($new($ConcurrentSkipListMap$SubMap$SubMapKeyIterator, static_cast<$ConcurrentSkipListMap$SubMap*>($nc(($cast($ConcurrentSkipListMap$SubMap, this->m))))));
}

void ConcurrentSkipListSet::setMap($ConcurrentNavigableMap* map) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Field, mapField, $cast($Field, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(ConcurrentSkipListSet$$Lambda$lambda$setMap$0)))));
	try {
		$nc(mapField)->set(this, map);
	} catch ($IllegalAccessException& e) {
		$throwNew($Error, static_cast<$Throwable*>(e));
	}
}

$Field* ConcurrentSkipListSet::lambda$setMap$0() {
	$init(ConcurrentSkipListSet);
	$beforeCallerSensitive();
	try {
		$var($Field, f, ConcurrentSkipListSet::class$->getDeclaredField("m"_s));
		$nc(f)->setAccessible(true);
		return f;
	} catch ($ReflectiveOperationException& e) {
		$throwNew($Error, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

ConcurrentSkipListSet::ConcurrentSkipListSet() {
}

$Class* ConcurrentSkipListSet::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ConcurrentSkipListSet$$Lambda$lambda$setMap$0::classInfo$.name)) {
			return ConcurrentSkipListSet$$Lambda$lambda$setMap$0::load$(name, initialize);
		}
	}
	$loadClass(ConcurrentSkipListSet, name, initialize, &_ConcurrentSkipListSet_ClassInfo_, allocate$ConcurrentSkipListSet);
	return class$;
}

$Class* ConcurrentSkipListSet::class$ = nullptr;

		} // concurrent
	} // util
} // java