#include <java/util/concurrent/ConcurrentSkipListMap.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Comparable.h>
#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/AbstractMap$SimpleImmutableEntry.h>
#include <java/util/AbstractMap.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/NavigableMap.h>
#include <java/util/NavigableSet.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/Set.h>
#include <java/util/SortedMap.h>
#include <java/util/concurrent/ConcurrentNavigableMap.h>
#include <java/util/concurrent/ConcurrentSkipListMap$EntrySet.h>
#include <java/util/concurrent/ConcurrentSkipListMap$EntrySpliterator.h>
#include <java/util/concurrent/ConcurrentSkipListMap$Index.h>
#include <java/util/concurrent/ConcurrentSkipListMap$KeySet.h>
#include <java/util/concurrent/ConcurrentSkipListMap$KeySpliterator.h>
#include <java/util/concurrent/ConcurrentSkipListMap$Node.h>
#include <java/util/concurrent/ConcurrentSkipListMap$SubMap.h>
#include <java/util/concurrent/ConcurrentSkipListMap$ValueSpliterator.h>
#include <java/util/concurrent/ConcurrentSkipListMap$Values.h>
#include <java/util/concurrent/ThreadLocalRandom.h>
#include <java/util/concurrent/atomic/LongAdder.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <jcpp.h>

#undef ADDER
#undef EQ
#undef GT
#undef HEAD
#undef LT
#undef MAX_VALUE
#undef NEXT
#undef RIGHT
#undef VAL

using $ConcurrentSkipListMap$IndexArray = $Array<::java::util::concurrent::ConcurrentSkipListMap$Index>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Comparable = ::java::lang::Comparable;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $AbstractMap = ::java::util::AbstractMap;
using $AbstractMap$SimpleImmutableEntry = ::java::util::AbstractMap$SimpleImmutableEntry;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Comparator = ::java::util::Comparator;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $NavigableMap = ::java::util::NavigableMap;
using $NavigableSet = ::java::util::NavigableSet;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $Set = ::java::util::Set;
using $SortedMap = ::java::util::SortedMap;
using $ConcurrentNavigableMap = ::java::util::concurrent::ConcurrentNavigableMap;
using $ConcurrentSkipListMap$EntrySet = ::java::util::concurrent::ConcurrentSkipListMap$EntrySet;
using $ConcurrentSkipListMap$EntrySpliterator = ::java::util::concurrent::ConcurrentSkipListMap$EntrySpliterator;
using $ConcurrentSkipListMap$Index = ::java::util::concurrent::ConcurrentSkipListMap$Index;
using $ConcurrentSkipListMap$KeySet = ::java::util::concurrent::ConcurrentSkipListMap$KeySet;
using $ConcurrentSkipListMap$KeySpliterator = ::java::util::concurrent::ConcurrentSkipListMap$KeySpliterator;
using $ConcurrentSkipListMap$Node = ::java::util::concurrent::ConcurrentSkipListMap$Node;
using $ConcurrentSkipListMap$SubMap = ::java::util::concurrent::ConcurrentSkipListMap$SubMap;
using $ConcurrentSkipListMap$ValueSpliterator = ::java::util::concurrent::ConcurrentSkipListMap$ValueSpliterator;
using $ConcurrentSkipListMap$Values = ::java::util::concurrent::ConcurrentSkipListMap$Values;
using $ThreadLocalRandom = ::java::util::concurrent::ThreadLocalRandom;
using $LongAdder = ::java::util::concurrent::atomic::LongAdder;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _ConcurrentSkipListMap_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConcurrentSkipListMap, serialVersionUID)},
	{"comparator", "Ljava/util/Comparator;", "Ljava/util/Comparator<-TK;>;", $FINAL, $field(ConcurrentSkipListMap, comparator$)},
	{"head", "Ljava/util/concurrent/ConcurrentSkipListMap$Index;", "Ljava/util/concurrent/ConcurrentSkipListMap$Index<TK;TV;>;", $PRIVATE | $TRANSIENT, $field(ConcurrentSkipListMap, head)},
	{"adder", "Ljava/util/concurrent/atomic/LongAdder;", nullptr, $PRIVATE | $TRANSIENT, $field(ConcurrentSkipListMap, adder)},
	{"keySet", "Ljava/util/concurrent/ConcurrentSkipListMap$KeySet;", "Ljava/util/concurrent/ConcurrentSkipListMap$KeySet<TK;TV;>;", $PRIVATE | $TRANSIENT, $field(ConcurrentSkipListMap, keySet$)},
	{"values", "Ljava/util/concurrent/ConcurrentSkipListMap$Values;", "Ljava/util/concurrent/ConcurrentSkipListMap$Values<TK;TV;>;", $PRIVATE | $TRANSIENT, $field(ConcurrentSkipListMap, values$)},
	{"entrySet", "Ljava/util/concurrent/ConcurrentSkipListMap$EntrySet;", "Ljava/util/concurrent/ConcurrentSkipListMap$EntrySet<TK;TV;>;", $PRIVATE | $TRANSIENT, $field(ConcurrentSkipListMap, entrySet$)},
	{"descendingMap", "Ljava/util/concurrent/ConcurrentSkipListMap$SubMap;", "Ljava/util/concurrent/ConcurrentSkipListMap$SubMap<TK;TV;>;", $PRIVATE | $TRANSIENT, $field(ConcurrentSkipListMap, descendingMap$)},
	{"EQ", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConcurrentSkipListMap, EQ)},
	{"LT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConcurrentSkipListMap, LT)},
	{"GT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConcurrentSkipListMap, GT)},
	{"HEAD", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ConcurrentSkipListMap, HEAD)},
	{"ADDER", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ConcurrentSkipListMap, ADDER)},
	{"NEXT", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ConcurrentSkipListMap, NEXT)},
	{"VAL", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ConcurrentSkipListMap, VAL)},
	{"RIGHT", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ConcurrentSkipListMap, RIGHT)},
	{}
};

$MethodInfo _ConcurrentSkipListMap_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PUBLIC, $method(ConcurrentSkipListMap, init$, void)},
	{"<init>", "(Ljava/util/Comparator;)V", "(Ljava/util/Comparator<-TK;>;)V", $PUBLIC, $method(ConcurrentSkipListMap, init$, void, $Comparator*)},
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<+TK;+TV;>;)V", $PUBLIC, $method(ConcurrentSkipListMap, init$, void, $Map*)},
	{"<init>", "(Ljava/util/SortedMap;)V", "(Ljava/util/SortedMap<TK;+TV;>;)V", $PUBLIC, $method(ConcurrentSkipListMap, init$, void, $SortedMap*)},
	{"addCount", "(J)V", nullptr, $PRIVATE, $method(ConcurrentSkipListMap, addCount, void, int64_t)},
	{"addIndices", "(Ljava/util/concurrent/ConcurrentSkipListMap$Index;ILjava/util/concurrent/ConcurrentSkipListMap$Index;Ljava/util/Comparator;)Z", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/concurrent/ConcurrentSkipListMap$Index<TK;TV;>;ILjava/util/concurrent/ConcurrentSkipListMap$Index<TK;TV;>;Ljava/util/Comparator<-TK;>;)Z", $STATIC, $staticMethod(ConcurrentSkipListMap, addIndices, bool, $ConcurrentSkipListMap$Index*, int32_t, $ConcurrentSkipListMap$Index*, $Comparator*)},
	{"baseHead", "()Ljava/util/concurrent/ConcurrentSkipListMap$Node;", "()Ljava/util/concurrent/ConcurrentSkipListMap$Node<TK;TV;>;", $FINAL, $method(ConcurrentSkipListMap, baseHead, $ConcurrentSkipListMap$Node*)},
	{"buildFromSorted", "(Ljava/util/SortedMap;)V", "(Ljava/util/SortedMap<TK;+TV;>;)V", $PRIVATE, $method(ConcurrentSkipListMap, buildFromSorted, void, $SortedMap*)},
	{"ceilingEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, ceilingEntry, $Map$Entry*, Object$*)},
	{"ceilingKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, ceilingKey, $Object*, Object$*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap, clear, void)},
	{"clone", "()Ljava/util/concurrent/ConcurrentSkipListMap;", "()Ljava/util/concurrent/ConcurrentSkipListMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, clone, $Object*)},
	{"comparator", "()Ljava/util/Comparator;", "()Ljava/util/Comparator<-TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, comparator, $Comparator*)},
	{"compute", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(TK;Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, compute, $Object*, Object$*, $BiFunction*)},
	{"computeIfAbsent", "(Ljava/lang/Object;Ljava/util/function/Function;)Ljava/lang/Object;", "(TK;Ljava/util/function/Function<-TK;+TV;>;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, computeIfAbsent, $Object*, Object$*, $Function*)},
	{"computeIfPresent", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(TK;Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, computeIfPresent, $Object*, Object$*, $BiFunction*)},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap, containsKey, bool, Object$*)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap, containsValue, bool, Object$*)},
	{"cpr", "(Ljava/util/Comparator;Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $STATIC, $staticMethod(ConcurrentSkipListMap, cpr, int32_t, $Comparator*, Object$*, Object$*)},
	{"descendingKeySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, descendingKeySet, $NavigableSet*)},
	{"descendingMap", "()Ljava/util/concurrent/ConcurrentNavigableMap;", "()Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, descendingMap, $NavigableMap*)},
	{"doGet", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PRIVATE, $method(ConcurrentSkipListMap, doGet, $Object*, Object$*)},
	{"doPut", "(Ljava/lang/Object;Ljava/lang/Object;Z)Ljava/lang/Object;", "(TK;TV;Z)TV;", $PRIVATE, $method(ConcurrentSkipListMap, doPut, $Object*, Object$*, Object$*, bool)},
	{"doRemove", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/lang/Object;)TV;", $FINAL, $method(ConcurrentSkipListMap, doRemove, $Object*, Object$*, Object$*)},
	{"doRemoveFirstEntry", "()Ljava/util/AbstractMap$SimpleImmutableEntry;", "()Ljava/util/AbstractMap$SimpleImmutableEntry<TK;TV;>;", $PRIVATE, $method(ConcurrentSkipListMap, doRemoveFirstEntry, $AbstractMap$SimpleImmutableEntry*)},
	{"doRemoveLastEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PRIVATE, $method(ConcurrentSkipListMap, doRemoveLastEntry, $Map$Entry*)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, entrySet, $Set*)},
	{"entrySpliterator", "()Ljava/util/concurrent/ConcurrentSkipListMap$EntrySpliterator;", "()Ljava/util/concurrent/ConcurrentSkipListMap$EntrySpliterator<TK;TV;>;", $FINAL, $method(ConcurrentSkipListMap, entrySpliterator, $ConcurrentSkipListMap$EntrySpliterator*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap, equals, bool, Object$*)},
	{"findFirst", "()Ljava/util/concurrent/ConcurrentSkipListMap$Node;", "()Ljava/util/concurrent/ConcurrentSkipListMap$Node<TK;TV;>;", $FINAL, $method(ConcurrentSkipListMap, findFirst, $ConcurrentSkipListMap$Node*)},
	{"findFirstEntry", "()Ljava/util/AbstractMap$SimpleImmutableEntry;", "()Ljava/util/AbstractMap$SimpleImmutableEntry<TK;TV;>;", $FINAL, $method(ConcurrentSkipListMap, findFirstEntry, $AbstractMap$SimpleImmutableEntry*)},
	{"findLast", "()Ljava/util/concurrent/ConcurrentSkipListMap$Node;", "()Ljava/util/concurrent/ConcurrentSkipListMap$Node<TK;TV;>;", $FINAL, $method(ConcurrentSkipListMap, findLast, $ConcurrentSkipListMap$Node*)},
	{"findLastEntry", "()Ljava/util/AbstractMap$SimpleImmutableEntry;", "()Ljava/util/AbstractMap$SimpleImmutableEntry<TK;TV;>;", $FINAL, $method(ConcurrentSkipListMap, findLastEntry, $AbstractMap$SimpleImmutableEntry*)},
	{"findNear", "(Ljava/lang/Object;ILjava/util/Comparator;)Ljava/util/concurrent/ConcurrentSkipListMap$Node;", "(TK;ILjava/util/Comparator<-TK;>;)Ljava/util/concurrent/ConcurrentSkipListMap$Node<TK;TV;>;", $FINAL, $method(ConcurrentSkipListMap, findNear, $ConcurrentSkipListMap$Node*, Object$*, int32_t, $Comparator*)},
	{"findNearEntry", "(Ljava/lang/Object;ILjava/util/Comparator;)Ljava/util/AbstractMap$SimpleImmutableEntry;", "(TK;ILjava/util/Comparator<-TK;>;)Ljava/util/AbstractMap$SimpleImmutableEntry<TK;TV;>;", $FINAL, $method(ConcurrentSkipListMap, findNearEntry, $AbstractMap$SimpleImmutableEntry*, Object$*, int32_t, $Comparator*)},
	{"findNode", "(Ljava/lang/Object;)Ljava/util/concurrent/ConcurrentSkipListMap$Node;", "(Ljava/lang/Object;)Ljava/util/concurrent/ConcurrentSkipListMap$Node<TK;TV;>;", $PRIVATE, $method(ConcurrentSkipListMap, findNode, $ConcurrentSkipListMap$Node*, Object$*)},
	{"findPredecessor", "(Ljava/lang/Object;Ljava/util/Comparator;)Ljava/util/concurrent/ConcurrentSkipListMap$Node;", "(Ljava/lang/Object;Ljava/util/Comparator<-TK;>;)Ljava/util/concurrent/ConcurrentSkipListMap$Node<TK;TV;>;", $PRIVATE, $method(ConcurrentSkipListMap, findPredecessor, $ConcurrentSkipListMap$Node*, Object$*, $Comparator*)},
	{"firstEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, firstEntry, $Map$Entry*)},
	{"firstKey", "()Ljava/lang/Object;", "()TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, firstKey, $Object*)},
	{"floorEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, floorEntry, $Map$Entry*, Object$*)},
	{"floorKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, floorKey, $Object*, Object$*)},
	{"forEach", "(Ljava/util/function/BiConsumer;)V", "(Ljava/util/function/BiConsumer<-TK;-TV;>;)V", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, forEach, void, $BiConsumer*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, get, $Object*, Object$*)},
	{"getAdderCount", "()J", nullptr, $FINAL, $method(ConcurrentSkipListMap, getAdderCount, int64_t)},
	{"getOrDefault", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;TV;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, getOrDefault, $Object*, Object$*, Object$*)},
	{"headMap", "(Ljava/lang/Object;Z)Ljava/util/concurrent/ConcurrentNavigableMap;", "(TK;Z)Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, headMap, $NavigableMap*, Object$*, bool)},
	{"headMap", "(Ljava/lang/Object;)Ljava/util/concurrent/ConcurrentNavigableMap;", "(TK;)Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, headMap, $SortedMap*, Object$*)},
	{"higherEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, higherEntry, $Map$Entry*, Object$*)},
	{"higherKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, higherKey, $Object*, Object$*)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap, isEmpty, bool)},
	{"keySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, keySet, $Set*)},
	{"keySpliterator", "()Ljava/util/concurrent/ConcurrentSkipListMap$KeySpliterator;", "()Ljava/util/concurrent/ConcurrentSkipListMap$KeySpliterator<TK;TV;>;", $FINAL, $method(ConcurrentSkipListMap, keySpliterator, $ConcurrentSkipListMap$KeySpliterator*)},
	{"lastEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, lastEntry, $Map$Entry*)},
	{"lastKey", "()Ljava/lang/Object;", "()TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, lastKey, $Object*)},
	{"lowerEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, lowerEntry, $Map$Entry*, Object$*)},
	{"lowerKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, lowerKey, $Object*, Object$*)},
	{"merge", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(TK;TV;Ljava/util/function/BiFunction<-TV;-TV;+TV;>;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, merge, $Object*, Object$*, Object$*, $BiFunction*)},
	{"navigableKeySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, navigableKeySet, $NavigableSet*)},
	{"pollFirstEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, pollFirstEntry, $Map$Entry*)},
	{"pollLastEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, pollLastEntry, $Map$Entry*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, put, $Object*, Object$*, Object$*)},
	{"*putAll", "(Ljava/util/Map;)V", nullptr, $PUBLIC},
	{"putIfAbsent", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, putIfAbsent, $Object*, Object$*, Object$*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(ConcurrentSkipListMap, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, remove, $Object*, Object$*)},
	{"remove", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap, remove, bool, Object$*, Object$*)},
	{"removeEntryIf", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-Ljava/util/Map$Entry<TK;TV;>;>;)Z", 0, $virtualMethod(ConcurrentSkipListMap, removeEntryIf, bool, $Predicate*)},
	{"removeValueIf", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TV;>;)Z", 0, $virtualMethod(ConcurrentSkipListMap, removeValueIf, bool, $Predicate*)},
	{"replace", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z", "(TK;TV;TV;)Z", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, replace, bool, Object$*, Object$*, Object$*)},
	{"replace", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, replace, $Object*, Object$*, Object$*)},
	{"replaceAll", "(Ljava/util/function/BiFunction;)V", "(Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)V", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, replaceAll, void, $BiFunction*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap, size, int32_t)},
	{"subMap", "(Ljava/lang/Object;ZLjava/lang/Object;Z)Ljava/util/concurrent/ConcurrentNavigableMap;", "(TK;ZTK;Z)Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, subMap, $NavigableMap*, Object$*, bool, Object$*, bool)},
	{"subMap", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/concurrent/ConcurrentNavigableMap;", "(TK;TK;)Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, subMap, $SortedMap*, Object$*, Object$*)},
	{"tailMap", "(Ljava/lang/Object;Z)Ljava/util/concurrent/ConcurrentNavigableMap;", "(TK;Z)Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, tailMap, $NavigableMap*, Object$*, bool)},
	{"tailMap", "(Ljava/lang/Object;)Ljava/util/concurrent/ConcurrentNavigableMap;", "(TK;)Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, tailMap, $SortedMap*, Object$*)},
	{"toList", "(Ljava/util/Collection;)Ljava/util/List;", "<E:Ljava/lang/Object;>(Ljava/util/Collection<TE;>;)Ljava/util/List<TE;>;", $STATIC | $FINAL, $staticMethod(ConcurrentSkipListMap, toList, $List*, $Collection*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tryReduceLevel", "()V", nullptr, $PRIVATE, $method(ConcurrentSkipListMap, tryReduceLevel, void)},
	{"unlinkNode", "(Ljava/util/concurrent/ConcurrentSkipListMap$Node;Ljava/util/concurrent/ConcurrentSkipListMap$Node;)V", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/concurrent/ConcurrentSkipListMap$Node<TK;TV;>;Ljava/util/concurrent/ConcurrentSkipListMap$Node<TK;TV;>;)V", $STATIC, $staticMethod(ConcurrentSkipListMap, unlinkNode, void, $ConcurrentSkipListMap$Node*, $ConcurrentSkipListMap$Node*)},
	{"valueSpliterator", "()Ljava/util/concurrent/ConcurrentSkipListMap$ValueSpliterator;", "()Ljava/util/concurrent/ConcurrentSkipListMap$ValueSpliterator<TK;TV;>;", $FINAL, $method(ConcurrentSkipListMap, valueSpliterator, $ConcurrentSkipListMap$ValueSpliterator*)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap, values, $Collection*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(ConcurrentSkipListMap, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ConcurrentSkipListMap_InnerClassesInfo_[] = {
	{"java.util.concurrent.ConcurrentSkipListMap$EntrySpliterator", "java.util.concurrent.ConcurrentSkipListMap", "EntrySpliterator", $STATIC | $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$ValueSpliterator", "java.util.concurrent.ConcurrentSkipListMap", "ValueSpliterator", $STATIC | $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$KeySpliterator", "java.util.concurrent.ConcurrentSkipListMap", "KeySpliterator", $STATIC | $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$CSLMSpliterator", "java.util.concurrent.ConcurrentSkipListMap", "CSLMSpliterator", $STATIC | $ABSTRACT},
	{"java.util.concurrent.ConcurrentSkipListMap$SubMap", "java.util.concurrent.ConcurrentSkipListMap", "SubMap", $STATIC | $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$EntrySet", "java.util.concurrent.ConcurrentSkipListMap", "EntrySet", $STATIC | $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$Values", "java.util.concurrent.ConcurrentSkipListMap", "Values", $STATIC | $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$KeySet", "java.util.concurrent.ConcurrentSkipListMap", "KeySet", $STATIC | $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$EntryIterator", "java.util.concurrent.ConcurrentSkipListMap", "EntryIterator", $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$KeyIterator", "java.util.concurrent.ConcurrentSkipListMap", "KeyIterator", $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$ValueIterator", "java.util.concurrent.ConcurrentSkipListMap", "ValueIterator", $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$Iter", "java.util.concurrent.ConcurrentSkipListMap", "Iter", $ABSTRACT},
	{"java.util.concurrent.ConcurrentSkipListMap$Index", "java.util.concurrent.ConcurrentSkipListMap", "Index", $STATIC | $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$Node", "java.util.concurrent.ConcurrentSkipListMap", "Node", $STATIC | $FINAL},
	{}
};

$ClassInfo _ConcurrentSkipListMap_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.ConcurrentSkipListMap",
	"java.util.AbstractMap",
	"java.util.concurrent.ConcurrentNavigableMap,java.lang.Cloneable,java.io.Serializable",
	_ConcurrentSkipListMap_FieldInfo_,
	_ConcurrentSkipListMap_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/AbstractMap<TK;TV;>;Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;Ljava/lang/Cloneable;Ljava/io/Serializable;",
	nullptr,
	_ConcurrentSkipListMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.ConcurrentSkipListMap$EntrySpliterator,java.util.concurrent.ConcurrentSkipListMap$ValueSpliterator,java.util.concurrent.ConcurrentSkipListMap$KeySpliterator,java.util.concurrent.ConcurrentSkipListMap$CSLMSpliterator,java.util.concurrent.ConcurrentSkipListMap$SubMap,java.util.concurrent.ConcurrentSkipListMap$SubMap$SubMapEntryIterator,java.util.concurrent.ConcurrentSkipListMap$SubMap$SubMapKeyIterator,java.util.concurrent.ConcurrentSkipListMap$SubMap$SubMapValueIterator,java.util.concurrent.ConcurrentSkipListMap$SubMap$SubMapIter,java.util.concurrent.ConcurrentSkipListMap$EntrySet,java.util.concurrent.ConcurrentSkipListMap$Values,java.util.concurrent.ConcurrentSkipListMap$KeySet,java.util.concurrent.ConcurrentSkipListMap$EntryIterator,java.util.concurrent.ConcurrentSkipListMap$KeyIterator,java.util.concurrent.ConcurrentSkipListMap$ValueIterator,java.util.concurrent.ConcurrentSkipListMap$Iter,java.util.concurrent.ConcurrentSkipListMap$Index,java.util.concurrent.ConcurrentSkipListMap$Node"
};

$Object* allocate$ConcurrentSkipListMap($Class* clazz) {
	return $of($alloc(ConcurrentSkipListMap));
}

void ConcurrentSkipListMap::putAll($Map* m) {
	this->$AbstractMap::putAll(m);
}

int32_t ConcurrentSkipListMap::hashCode() {
	 return this->$AbstractMap::hashCode();
}

$String* ConcurrentSkipListMap::toString() {
	 return this->$AbstractMap::toString();
}

void ConcurrentSkipListMap::finalize() {
	this->$AbstractMap::finalize();
}

$VarHandle* ConcurrentSkipListMap::HEAD = nullptr;
$VarHandle* ConcurrentSkipListMap::ADDER = nullptr;
$VarHandle* ConcurrentSkipListMap::NEXT = nullptr;
$VarHandle* ConcurrentSkipListMap::VAL = nullptr;
$VarHandle* ConcurrentSkipListMap::RIGHT = nullptr;

int32_t ConcurrentSkipListMap::cpr($Comparator* c, Object$* x, Object$* y) {
	$init(ConcurrentSkipListMap);
	return (c != nullptr) ? $nc(c)->compare(x, y) : $nc(($cast($Comparable, x)))->compareTo(y);
}

$ConcurrentSkipListMap$Node* ConcurrentSkipListMap::baseHead() {
	$var($ConcurrentSkipListMap$Index, h, nullptr);
	$VarHandle::acquireFence();
	return (($assign(h, this->head)) == nullptr) ? ($ConcurrentSkipListMap$Node*)nullptr : $nc(h)->node;
}

void ConcurrentSkipListMap::unlinkNode($ConcurrentSkipListMap$Node* b, $ConcurrentSkipListMap$Node* n) {
	$init(ConcurrentSkipListMap);
	$useLocalCurrentObjectStackCache();
	if (b != nullptr && n != nullptr) {
		$var($ConcurrentSkipListMap$Node, f, nullptr);
		$var($ConcurrentSkipListMap$Node, p, nullptr);
		for (;;) {
			bool var$0 = ($assign(f, n->next)) != nullptr;
			if (var$0 && $nc(f)->key == nullptr) {
				$assign(p, f->next);
				break;
			} else {
				if ($nc(ConcurrentSkipListMap::NEXT)->compareAndSet($$new($ObjectArray, {$of(n), $of(f), $of($$new($ConcurrentSkipListMap$Node, nullptr, nullptr, f))}))) {
					$assign(p, f);
					break;
				}
			}
		}
		$nc(ConcurrentSkipListMap::NEXT)->compareAndSet($$new($ObjectArray, {$of(b), $of(n), $of(p)}));
	}
}

void ConcurrentSkipListMap::addCount(int64_t c) {
	$useLocalCurrentObjectStackCache();
	$var($LongAdder, a, nullptr);
	bool var$0 = false;
	do {
		var$0 = ($assign(a, this->adder)) == nullptr;
	} while (var$0 && !$nc(ConcurrentSkipListMap::ADDER)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $of(($assign(a, $new($LongAdder))))})));
	$nc(a)->add(c);
}

int64_t ConcurrentSkipListMap::getAdderCount() {
	$useLocalCurrentObjectStackCache();
	$var($LongAdder, a, nullptr);
	int64_t c = 0;
	bool var$0 = false;
	do {
		var$0 = ($assign(a, this->adder)) == nullptr;
	} while (var$0 && !$nc(ConcurrentSkipListMap::ADDER)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $of(($assign(a, $new($LongAdder))))})));
	return ((c = $nc(a)->sum()) <= (int64_t)0) ? (int64_t)0 : c;
}

$ConcurrentSkipListMap$Node* ConcurrentSkipListMap::findPredecessor(Object$* key, $Comparator* cmp) {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentSkipListMap$Index, q, nullptr);
	$VarHandle::acquireFence();
	if (($assign(q, this->head)) == nullptr || key == nullptr) {
		return nullptr;
	} else {
		{
			$var($ConcurrentSkipListMap$Index, r, nullptr);
			$var($ConcurrentSkipListMap$Index, d, nullptr);
			for (;;) {
				while (($assign(r, $nc(q)->right)) != nullptr) {
					$var($ConcurrentSkipListMap$Node, p, nullptr);
					$var($Object, k, nullptr);
					bool var$1 = ($assign(p, $nc(r)->node)) == nullptr;
					bool var$0 = var$1 || ($assign(k, $nc(p)->key)) == nullptr;
					if (var$0 || $nc(p)->val == nullptr) {
						$nc(ConcurrentSkipListMap::RIGHT)->compareAndSet($$new($ObjectArray, {$of(q), $of(r), $of($nc(r)->right)}));
					} else if (cpr(cmp, key, k) > 0) {
						$assign(q, r);
					} else {
						break;
					}
				}
				if (($assign(d, $nc(q)->down)) != nullptr) {
					$assign(q, d);
				} else {
					return q->node;
				}
			}
		}
	}
}

$ConcurrentSkipListMap$Node* ConcurrentSkipListMap::findNode(Object$* key) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Comparator, cmp, this->comparator$);
	$var($ConcurrentSkipListMap$Node, b, nullptr);
	bool outer$break = false;
	while (($assign(b, findPredecessor(key, cmp))) != nullptr) {
		for (;;) {
			$var($ConcurrentSkipListMap$Node, n, nullptr);
			$var($Object, k, nullptr);
			$var($Object, v, nullptr);
			int32_t c = 0;
			if (($assign(n, $nc(b)->next)) == nullptr) {
				outer$break = true;
				break;
			} else if (($assign(k, $nc(n)->key)) == nullptr) {
				break;
			} else if (($assign(v, n->val)) == nullptr) {
				unlinkNode(b, n);
			} else if ((c = cpr(cmp, key, k)) > 0) {
				$assign(b, n);
			} else if (c == 0) {
				return n;
			} else {
				outer$break = true;
				break;
			}
		}
		if (outer$break) {
			break;
		}
	}
	return nullptr;
}

$Object* ConcurrentSkipListMap::doGet(Object$* key) {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentSkipListMap$Index, q, nullptr);
	$VarHandle::acquireFence();
	if (key == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Comparator, cmp, this->comparator$);
	$var($Object, result, nullptr);
	if (($assign(q, this->head)) != nullptr) {
		bool outer$break = false;
		{
			$var($ConcurrentSkipListMap$Index, r, nullptr);
			$var($ConcurrentSkipListMap$Index, d, nullptr);
			for (;;) {
				while (($assign(r, $nc(q)->right)) != nullptr) {
					$var($ConcurrentSkipListMap$Node, p, nullptr);
					$var($Object, k, nullptr);
					$var($Object, v, nullptr);
					int32_t c = 0;
					bool var$1 = ($assign(p, $nc(r)->node)) == nullptr;
					bool var$0 = var$1 || ($assign(k, $nc(p)->key)) == nullptr;
					if (var$0 || ($assign(v, $nc(p)->val)) == nullptr) {
						$nc(ConcurrentSkipListMap::RIGHT)->compareAndSet($$new($ObjectArray, {$of(q), $of(r), $of($nc(r)->right)}));
					} else if ((c = cpr(cmp, key, k)) > 0) {
						$assign(q, r);
					} else if (c == 0) {
						$assign(result, v);
						outer$break = true;
						break;
					} else {
						break;
					}
				}
				if (outer$break) {
					break;
				}
				if (($assign(d, $nc(q)->down)) != nullptr) {
					$assign(q, d);
				} else {
					$var($ConcurrentSkipListMap$Node, b, nullptr);
					$var($ConcurrentSkipListMap$Node, n, nullptr);
					if (($assign(b, q->node)) != nullptr) {
						while (($assign(n, $nc(b)->next)) != nullptr) {
							$var($Object, v, nullptr);
							int32_t c = 0;
							$var($Object, k, $nc(n)->key);
							if (($assign(v, n->val)) == nullptr || k == nullptr || (c = cpr(cmp, key, k)) > 0) {
								$assign(b, n);
							} else {
								if (c == 0) {
									$assign(result, v);
								}
								break;
							}
						}
					}
					break;
				}
			}
		}
	}
	return $of(result);
}

$Object* ConcurrentSkipListMap::doPut(Object$* key, Object$* value, bool onlyIfAbsent) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Comparator, cmp, this->comparator$);
	for (;;) {
		$var($ConcurrentSkipListMap$Index, h, nullptr);
		$var($ConcurrentSkipListMap$Node, b, nullptr);
		$VarHandle::acquireFence();
		int32_t levels = 0;
		if (($assign(h, this->head)) == nullptr) {
			$var($ConcurrentSkipListMap$Node, base, $new($ConcurrentSkipListMap$Node, nullptr, nullptr, nullptr));
			$assign(h, $new($ConcurrentSkipListMap$Index, base, nullptr, nullptr));
			$assign(b, ($nc(ConcurrentSkipListMap::HEAD)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $of(h)}))) ? base : ($ConcurrentSkipListMap$Node*)nullptr);
		} else {
			{
				$var($ConcurrentSkipListMap$Index, q, h);
				$var($ConcurrentSkipListMap$Index, r, nullptr);
				$var($ConcurrentSkipListMap$Index, d, nullptr);
				for (;;) {
					while (($assign(r, $nc(q)->right)) != nullptr) {
						$var($ConcurrentSkipListMap$Node, p, nullptr);
						$var($Object, k, nullptr);
						bool var$1 = ($assign(p, $nc(r)->node)) == nullptr;
						bool var$0 = var$1 || ($assign(k, $nc(p)->key)) == nullptr;
						if (var$0 || $nc(p)->val == nullptr) {
							$nc(ConcurrentSkipListMap::RIGHT)->compareAndSet($$new($ObjectArray, {$of(q), $of(r), $of($nc(r)->right)}));
						} else if (cpr(cmp, key, k) > 0) {
							$assign(q, r);
						} else {
							break;
						}
					}
					if (($assign(d, $nc(q)->down)) != nullptr) {
						++levels;
						$assign(q, d);
					} else {
						$assign(b, q->node);
						break;
					}
				}
			}
		}
		if (b != nullptr) {
			$var($ConcurrentSkipListMap$Node, z, nullptr);
			for (;;) {
				$var($ConcurrentSkipListMap$Node, n, nullptr);
				$var($ConcurrentSkipListMap$Node, p, nullptr);
				$var($Object, k, nullptr);
				$var($Object, v, nullptr);
				int32_t c = 0;
				if (($assign(n, b->next)) == nullptr) {
					if (b->key == nullptr) {
						cpr(cmp, key, key);
					}
					c = -1;
				} else if (($assign(k, $nc(n)->key)) == nullptr) {
					break;
				} else if (($assign(v, n->val)) == nullptr) {
					unlinkNode(b, n);
					c = 1;
				} else if ((c = cpr(cmp, key, k)) > 0) {
					$assign(b, n);
				} else if (c == 0 && (onlyIfAbsent || $nc(ConcurrentSkipListMap::VAL)->compareAndSet($$new($ObjectArray, {$of(n), v, value})))) {
					return $of(v);
				}
				if (c < 0 && $nc(ConcurrentSkipListMap::NEXT)->compareAndSet($$new($ObjectArray, {$of(b), $of(n), $of(($assign(p, $new($ConcurrentSkipListMap$Node, key, value, n))))}))) {
					$assign(z, p);
					break;
				}
			}
			if (z != nullptr) {
				int32_t lr = $ThreadLocalRandom::nextSecondarySeed();
				if (((int32_t)(lr & (uint32_t)3)) == 0) {
					int32_t hr = $ThreadLocalRandom::nextSecondarySeed();
					int64_t rnd = ((int64_t)hr << 32) | ((int64_t)((int64_t)lr & (uint64_t)(int64_t)0x00000000FFFFFFFF));
					int32_t skips = levels;
					$var($ConcurrentSkipListMap$Index, x, nullptr);
					for (;;) {
						$assign(x, $new($ConcurrentSkipListMap$Index, z, x, nullptr));
						if (rnd >= (int64_t)0 || --skips < 0) {
							break;
						} else {
							rnd <<= 1;
						}
					}
					if (addIndices(h, skips, x, cmp) && skips < 0 && this->head == h) {
						$var($ConcurrentSkipListMap$Index, hx, $new($ConcurrentSkipListMap$Index, z, x, nullptr));
						$var($ConcurrentSkipListMap$Index, nh, $new($ConcurrentSkipListMap$Index, $nc(h)->node, h, hx));
						$nc(ConcurrentSkipListMap::HEAD)->compareAndSet($$new($ObjectArray, {$of(this), $of(h), $of(nh)}));
					}
					if (z->val == nullptr) {
						findPredecessor(key, cmp);
					}
				}
				addCount(1);
				return $of(nullptr);
			}
		}
	}
}

bool ConcurrentSkipListMap::addIndices($ConcurrentSkipListMap$Index* q$renamed, int32_t skips, $ConcurrentSkipListMap$Index* x, $Comparator* cmp) {
	$init(ConcurrentSkipListMap);
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentSkipListMap$Index, q, q$renamed);
	$var($ConcurrentSkipListMap$Node, z, nullptr);
	$var($Object, key, nullptr);
	bool var$0 = x != nullptr && ($assign(z, x->node)) != nullptr;
	if (var$0 && ($assign(key, $nc(z)->key)) != nullptr && q != nullptr) {
		bool retrying = false;
		for (;;) {
			$var($ConcurrentSkipListMap$Index, r, nullptr);
			$var($ConcurrentSkipListMap$Index, d, nullptr);
			int32_t c = 0;
			if (($assign(r, q->right)) != nullptr) {
				$var($ConcurrentSkipListMap$Node, p, nullptr);
				$var($Object, k, nullptr);
				bool var$2 = ($assign(p, $nc(r)->node)) == nullptr;
				bool var$1 = var$2 || ($assign(k, $nc(p)->key)) == nullptr;
				if (var$1 || $nc(p)->val == nullptr) {
					$nc(ConcurrentSkipListMap::RIGHT)->compareAndSet($$new($ObjectArray, {$of(q), $of(r), $of($nc(r)->right)}));
					c = 0;
				} else if ((c = cpr(cmp, key, k)) > 0) {
					$assign(q, r);
				} else if (c == 0) {
					break;
				}
			} else {
				c = -1;
			}
			if (c < 0) {
				if (($assign(d, q->down)) != nullptr && skips > 0) {
					--skips;
					$assign(q, d);
				} else if (d != nullptr && !retrying && !addIndices(d, 0, x->down, cmp)) {
					break;
				} else {
					$set(x, right, r);
					if ($nc(ConcurrentSkipListMap::RIGHT)->compareAndSet($$new($ObjectArray, {$of(q), $of(r), $of(x)}))) {
						return true;
					} else {
						retrying = true;
					}
				}
			}
		}
	}
	return false;
}

$Object* ConcurrentSkipListMap::doRemove(Object$* key, Object$* value) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Comparator, cmp, this->comparator$);
	$var($Object, result, nullptr);
	$var($ConcurrentSkipListMap$Node, b, nullptr);
	bool outer$break = false;
	while (($assign(b, findPredecessor(key, cmp))) != nullptr && result == nullptr) {
		for (;;) {
			$var($ConcurrentSkipListMap$Node, n, nullptr);
			$var($Object, k, nullptr);
			$var($Object, v, nullptr);
			int32_t c = 0;
			if (($assign(n, $nc(b)->next)) == nullptr) {
				outer$break = true;
				break;
			} else if (($assign(k, $nc(n)->key)) == nullptr) {
				break;
			} else if (($assign(v, n->val)) == nullptr) {
				unlinkNode(b, n);
			} else if ((c = cpr(cmp, key, k)) > 0) {
				$assign(b, n);
			} else if (c < 0) {
				outer$break = true;
				break;
			} else if (value != nullptr && !$of(value)->equals(v)) {
				outer$break = true;
				break;
			} else if ($nc(ConcurrentSkipListMap::VAL)->compareAndSet($$new($ObjectArray, {$of(n), v, ($Object*)nullptr}))) {
				$assign(result, v);
				unlinkNode(b, n);
				break;
			}
		}
		if (outer$break) {
			break;
		}
	}
	if (result != nullptr) {
		tryReduceLevel();
		addCount(-1);
	}
	return $of(result);
}

void ConcurrentSkipListMap::tryReduceLevel() {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentSkipListMap$Index, h, nullptr);
	$var($ConcurrentSkipListMap$Index, d, nullptr);
	$var($ConcurrentSkipListMap$Index, e, nullptr);
	bool var$5 = ($assign(h, this->head)) != nullptr;
	bool var$4 = var$5 && $nc(h)->right == nullptr;
	bool var$3 = var$4 && ($assign(d, h->down)) != nullptr;
	bool var$2 = var$3 && $nc(d)->right == nullptr;
	bool var$1 = var$2 && ($assign(e, d->down)) != nullptr;
	bool var$0 = var$1 && $nc(e)->right == nullptr;
	if (var$0 && $nc(ConcurrentSkipListMap::HEAD)->compareAndSet($$new($ObjectArray, {$of(this), $of(h), $of(d)})) && h->right != nullptr) {
		$nc(ConcurrentSkipListMap::HEAD)->compareAndSet($$new($ObjectArray, {$of(this), $of(d), $of(h)}));
	}
}

$ConcurrentSkipListMap$Node* ConcurrentSkipListMap::findFirst() {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentSkipListMap$Node, b, nullptr);
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	if (($assign(b, baseHead())) != nullptr) {
		while (($assign(n, $nc(b)->next)) != nullptr) {
			if ($nc(n)->val == nullptr) {
				unlinkNode(b, n);
			} else {
				return n;
			}
		}
	}
	return nullptr;
}

$AbstractMap$SimpleImmutableEntry* ConcurrentSkipListMap::findFirstEntry() {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentSkipListMap$Node, b, nullptr);
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	$var($Object, v, nullptr);
	if (($assign(b, baseHead())) != nullptr) {
		while (($assign(n, $nc(b)->next)) != nullptr) {
			if (($assign(v, $nc(n)->val)) == nullptr) {
				unlinkNode(b, n);
			} else {
				return $new($AbstractMap$SimpleImmutableEntry, n->key, v);
			}
		}
	}
	return nullptr;
}

$AbstractMap$SimpleImmutableEntry* ConcurrentSkipListMap::doRemoveFirstEntry() {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentSkipListMap$Node, b, nullptr);
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	$var($Object, v, nullptr);
	if (($assign(b, baseHead())) != nullptr) {
		while (($assign(n, $nc(b)->next)) != nullptr) {
			bool var$0 = ($assign(v, $nc(n)->val)) == nullptr;
			if (var$0 || $nc(ConcurrentSkipListMap::VAL)->compareAndSet($$new($ObjectArray, {$of(n), v, ($Object*)nullptr}))) {
				$var($Object, k, $nc(n)->key);
				unlinkNode(b, n);
				if (v != nullptr) {
					tryReduceLevel();
					findPredecessor(k, this->comparator$);
					addCount(-1);
					return $new($AbstractMap$SimpleImmutableEntry, k, v);
				}
			}
		}
	}
	return nullptr;
}

$ConcurrentSkipListMap$Node* ConcurrentSkipListMap::findLast() {
	$useLocalCurrentObjectStackCache();
	bool outer$break = false;
	for (;;) {
		$var($ConcurrentSkipListMap$Index, q, nullptr);
		$var($ConcurrentSkipListMap$Node, b, nullptr);
		$VarHandle::acquireFence();
		if (($assign(q, this->head)) == nullptr) {
			break;
		}
		{
			$var($ConcurrentSkipListMap$Index, r, nullptr);
			$var($ConcurrentSkipListMap$Index, d, nullptr);
			for (;;) {
				while (($assign(r, $nc(q)->right)) != nullptr) {
					$var($ConcurrentSkipListMap$Node, p, nullptr);
					bool var$0 = ($assign(p, $nc(r)->node)) == nullptr;
					if (var$0 || $nc(p)->val == nullptr) {
						$nc(ConcurrentSkipListMap::RIGHT)->compareAndSet($$new($ObjectArray, {$of(q), $of(r), $of($nc(r)->right)}));
					} else {
						$assign(q, r);
					}
				}
				if (($assign(d, $nc(q)->down)) != nullptr) {
					$assign(q, d);
				} else {
					$assign(b, q->node);
					break;
				}
			}
		}
		if (b != nullptr) {
			for (;;) {
				$var($ConcurrentSkipListMap$Node, n, nullptr);
				if (($assign(n, b->next)) == nullptr) {
					if (b->key == nullptr) {
						outer$break = true;
						break;
					} else {
						return b;
					}
				} else if ($nc(n)->key == nullptr) {
					break;
				} else if (n->val == nullptr) {
					unlinkNode(b, n);
				} else {
					$assign(b, n);
				}
			}
			if (outer$break) {
				break;
			}
		}
	}
	return nullptr;
}

$AbstractMap$SimpleImmutableEntry* ConcurrentSkipListMap::findLastEntry() {
	$useLocalCurrentObjectStackCache();
	for (;;) {
		$var($ConcurrentSkipListMap$Node, n, nullptr);
		$var($Object, v, nullptr);
		if (($assign(n, findLast())) == nullptr) {
			return nullptr;
		}
		if (($assign(v, $nc(n)->val)) != nullptr) {
			return $new($AbstractMap$SimpleImmutableEntry, n->key, v);
		}
	}
}

$Map$Entry* ConcurrentSkipListMap::doRemoveLastEntry() {
	$useLocalCurrentObjectStackCache();
	bool outer$break = false;
	for (;;) {
		$var($ConcurrentSkipListMap$Index, q, nullptr);
		$var($ConcurrentSkipListMap$Node, b, nullptr);
		$VarHandle::acquireFence();
		if (($assign(q, this->head)) == nullptr) {
			break;
		}
		for (;;) {
			$var($ConcurrentSkipListMap$Index, d, nullptr);
			$var($ConcurrentSkipListMap$Index, r, nullptr);
			$var($ConcurrentSkipListMap$Node, p, nullptr);
			while (($assign(r, $nc(q)->right)) != nullptr) {
				bool var$0 = ($assign(p, $nc(r)->node)) == nullptr;
				if (var$0 || $nc(p)->val == nullptr) {
					$nc(ConcurrentSkipListMap::RIGHT)->compareAndSet($$new($ObjectArray, {$of(q), $of(r), $of($nc(r)->right)}));
				} else if (p->next != nullptr) {
					$assign(q, r);
				} else {
					break;
				}
			}
			if (($assign(d, $nc(q)->down)) != nullptr) {
				$assign(q, d);
			} else {
				$assign(b, q->node);
				break;
			}
		}
		if (b != nullptr) {
			for (;;) {
				$var($ConcurrentSkipListMap$Node, n, nullptr);
				$var($Object, k, nullptr);
				$var($Object, v, nullptr);
				if (($assign(n, b->next)) == nullptr) {
					if (b->key == nullptr) {
						outer$break = true;
						break;
					} else {
						break;
					}
				} else if (($assign(k, $nc(n)->key)) == nullptr) {
					break;
				} else if (($assign(v, n->val)) == nullptr) {
					unlinkNode(b, n);
				} else if (n->next != nullptr) {
					$assign(b, n);
				} else if ($nc(ConcurrentSkipListMap::VAL)->compareAndSet($$new($ObjectArray, {$of(n), v, ($Object*)nullptr}))) {
					unlinkNode(b, n);
					tryReduceLevel();
					findPredecessor(k, this->comparator$);
					addCount(-1);
					return $new($AbstractMap$SimpleImmutableEntry, k, v);
				}
			}
			if (outer$break) {
				break;
			}
		}
	}
	return nullptr;
}

$ConcurrentSkipListMap$Node* ConcurrentSkipListMap::findNear(Object$* key, int32_t rel, $Comparator* cmp) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($ConcurrentSkipListMap$Node, result, nullptr);
	bool outer$break = false;
	{
		$var($ConcurrentSkipListMap$Node, b, nullptr);
		for (;;) {
			if (($assign(b, findPredecessor(key, cmp))) == nullptr) {
				$assign(result, nullptr);
				break;
			}
			for (;;) {
				$var($ConcurrentSkipListMap$Node, n, nullptr);
				$var($Object, k, nullptr);
				int32_t c = 0;
				if (($assign(n, $nc(b)->next)) == nullptr) {
					$assign(result, (((int32_t)(rel & (uint32_t)ConcurrentSkipListMap::LT)) != 0 && b->key != nullptr) ? b : ($ConcurrentSkipListMap$Node*)nullptr);
					outer$break = true;
					break;
				} else if (($assign(k, $nc(n)->key)) == nullptr) {
					break;
				} else if (n->val == nullptr) {
					unlinkNode(b, n);
				} else {
					bool var$1 = ((c = cpr(cmp, key, k)) == 0 && ((int32_t)(rel & (uint32_t)ConcurrentSkipListMap::EQ)) != 0);
					if (var$1 || (c < 0 && ((int32_t)(rel & (uint32_t)ConcurrentSkipListMap::LT)) == 0)) {
						$assign(result, n);
						outer$break = true;
						break;
					} else if (c <= 0 && ((int32_t)(rel & (uint32_t)ConcurrentSkipListMap::LT)) != 0) {
						$assign(result, (b->key != nullptr) ? b : ($ConcurrentSkipListMap$Node*)nullptr);
						outer$break = true;
						break;
					} else {
						$assign(b, n);
					}
				}
			}
			if (outer$break) {
				break;
			}
		}
	}
	return result;
}

$AbstractMap$SimpleImmutableEntry* ConcurrentSkipListMap::findNearEntry(Object$* key, int32_t rel, $Comparator* cmp) {
	$useLocalCurrentObjectStackCache();
	for (;;) {
		$var($ConcurrentSkipListMap$Node, n, nullptr);
		$var($Object, v, nullptr);
		if (($assign(n, findNear(key, rel, cmp))) == nullptr) {
			return nullptr;
		}
		if (($assign(v, $nc(n)->val)) != nullptr) {
			return $new($AbstractMap$SimpleImmutableEntry, n->key, v);
		}
	}
}

void ConcurrentSkipListMap::init$() {
	$AbstractMap::init$();
	$set(this, comparator$, nullptr);
}

void ConcurrentSkipListMap::init$($Comparator* comparator) {
	$AbstractMap::init$();
	$set(this, comparator$, comparator);
}

void ConcurrentSkipListMap::init$($Map* m) {
	$AbstractMap::init$();
	$set(this, comparator$, nullptr);
	putAll(m);
}

void ConcurrentSkipListMap::init$($SortedMap* m) {
	$AbstractMap::init$();
	$set(this, comparator$, $nc(m)->comparator());
	buildFromSorted(m);
}

$Object* ConcurrentSkipListMap::clone() {
	try {
		$var(ConcurrentSkipListMap, clone, $cast(ConcurrentSkipListMap, $AbstractMap::clone()));
		$set($nc(clone), keySet$, nullptr);
		$set(clone, entrySet$, nullptr);
		$set(clone, values$, nullptr);
		$set(clone, descendingMap$, nullptr);
		$set(clone, adder, nullptr);
		clone->buildFromSorted(this);
		return $of(clone);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

void ConcurrentSkipListMap::buildFromSorted($SortedMap* map) {
	$useLocalCurrentObjectStackCache();
	if (map == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Iterator, it, $nc($($nc(map)->entrySet()))->iterator());
	$var($ConcurrentSkipListMap$IndexArray, preds, $new($ConcurrentSkipListMap$IndexArray, 64));
	$var($ConcurrentSkipListMap$Node, bp, $new($ConcurrentSkipListMap$Node, nullptr, nullptr, nullptr));
	$var($ConcurrentSkipListMap$Index, h, preds->set(0, $$new($ConcurrentSkipListMap$Index, bp, nullptr, nullptr)));
	int64_t count = 0;
	while ($nc(it)->hasNext()) {
		$var($Map$Entry, e, $cast($Map$Entry, it->next()));
		$var($Object, k, $nc(e)->getKey());
		$var($Object, v, e->getValue());
		if (k == nullptr || v == nullptr) {
			$throwNew($NullPointerException);
		}
		$var($ConcurrentSkipListMap$Node, z, $new($ConcurrentSkipListMap$Node, k, v, nullptr));
		$assign(bp, ($set($nc(bp), next, z)));
		if (((int64_t)(++count & (uint64_t)(int64_t)3)) == (int64_t)0) {
			int64_t m = (int64_t)((uint64_t)count >> 2);
			int32_t i = 0;
			$var($ConcurrentSkipListMap$Index, idx, nullptr);
			$var($ConcurrentSkipListMap$Index, q, nullptr);
			do {
				$assign(idx, $new($ConcurrentSkipListMap$Index, z, idx, nullptr));
				if (($assign(q, preds->get(i))) == nullptr) {
					preds->set(i, $assign(h, $new($ConcurrentSkipListMap$Index, $nc(h)->node, h, idx)));
				} else {
					preds->set(i, $set($nc(q), right, idx));
				}
			} while (++i < preds->length && ((int64_t)(($usrAssign(m, 1)) & (uint64_t)(int64_t)1)) != (int64_t)0);
		}
	}
	if (count != (int64_t)0) {
		$VarHandle::releaseFence();
		addCount(count);
		$set(this, head, h);
		$VarHandle::fullFence();
	}
}

void ConcurrentSkipListMap::writeObject($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultWriteObject();
	$var($ConcurrentSkipListMap$Node, b, nullptr);
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	$var($Object, v, nullptr);
	if (($assign(b, baseHead())) != nullptr) {
		while (($assign(n, $nc(b)->next)) != nullptr) {
			if (($assign(v, $nc(n)->val)) != nullptr) {
				s->writeObject(n->key);
				s->writeObject(v);
			}
			$assign(b, n);
		}
	}
	s->writeObject(nullptr);
}

void ConcurrentSkipListMap::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	$var($ConcurrentSkipListMap$IndexArray, preds, $new($ConcurrentSkipListMap$IndexArray, 64));
	$var($ConcurrentSkipListMap$Node, bp, $new($ConcurrentSkipListMap$Node, nullptr, nullptr, nullptr));
	$var($ConcurrentSkipListMap$Index, h, preds->set(0, $$new($ConcurrentSkipListMap$Index, bp, nullptr, nullptr)));
	$var($Comparator, cmp, this->comparator$);
	$var($Object, prevKey, nullptr);
	int64_t count = 0;
	for (;;) {
		$var($Object, k, s->readObject());
		if (k == nullptr) {
			break;
		}
		$var($Object, v, s->readObject());
		if (v == nullptr) {
			$throwNew($NullPointerException);
		}
		if (prevKey != nullptr && cpr(cmp, prevKey, k) > 0) {
			$throwNew($IllegalStateException, "out of order"_s);
		}
		$assign(prevKey, k);
		$var($ConcurrentSkipListMap$Node, z, $new($ConcurrentSkipListMap$Node, k, v, nullptr));
		$assign(bp, ($set(bp, next, z)));
		if (((int64_t)(++count & (uint64_t)(int64_t)3)) == (int64_t)0) {
			int64_t m = (int64_t)((uint64_t)count >> 2);
			int32_t i = 0;
			$var($ConcurrentSkipListMap$Index, idx, nullptr);
			$var($ConcurrentSkipListMap$Index, q, nullptr);
			do {
				$assign(idx, $new($ConcurrentSkipListMap$Index, z, idx, nullptr));
				if (($assign(q, preds->get(i))) == nullptr) {
					preds->set(i, $assign(h, $new($ConcurrentSkipListMap$Index, $nc(h)->node, h, idx)));
				} else {
					preds->set(i, $set($nc(q), right, idx));
				}
			} while (++i < preds->length && ((int64_t)(($usrAssign(m, 1)) & (uint64_t)(int64_t)1)) != (int64_t)0);
		}
	}
	if (count != (int64_t)0) {
		$VarHandle::releaseFence();
		addCount(count);
		$set(this, head, h);
		$VarHandle::fullFence();
	}
}

bool ConcurrentSkipListMap::containsKey(Object$* key) {
	return doGet(key) != nullptr;
}

$Object* ConcurrentSkipListMap::get(Object$* key) {
	return $of(doGet(key));
}

$Object* ConcurrentSkipListMap::getOrDefault(Object$* key, Object$* defaultValue) {
	$var($Object, v, nullptr);
	return $of(($assign(v, doGet(key))) == nullptr ? $of(defaultValue) : v);
}

$Object* ConcurrentSkipListMap::put(Object$* key, Object$* value) {
	if (value == nullptr) {
		$throwNew($NullPointerException);
	}
	return $of(doPut(key, value, false));
}

$Object* ConcurrentSkipListMap::remove(Object$* key) {
	return $of(doRemove(key, nullptr));
}

bool ConcurrentSkipListMap::containsValue(Object$* value) {
	$useLocalCurrentObjectStackCache();
	if (value == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($ConcurrentSkipListMap$Node, b, nullptr);
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	$var($Object, v, nullptr);
	if (($assign(b, baseHead())) != nullptr) {
		while (($assign(n, $nc(b)->next)) != nullptr) {
			bool var$0 = ($assign(v, $nc(n)->val)) != nullptr;
			if (var$0 && $nc($of(value))->equals(v)) {
				return true;
			} else {
				$assign(b, n);
			}
		}
	}
	return false;
}

int32_t ConcurrentSkipListMap::size() {
	int64_t c = 0;
	return ((baseHead() == nullptr) ? 0 : ((c = getAdderCount()) >= $Integer::MAX_VALUE) ? $Integer::MAX_VALUE : (int32_t)c);
}

bool ConcurrentSkipListMap::isEmpty() {
	return findFirst() == nullptr;
}

void ConcurrentSkipListMap::clear() {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentSkipListMap$Index, h, nullptr);
	$var($ConcurrentSkipListMap$Index, r, nullptr);
	$var($ConcurrentSkipListMap$Index, d, nullptr);
	$var($ConcurrentSkipListMap$Node, b, nullptr);
	$VarHandle::acquireFence();
	while (($assign(h, this->head)) != nullptr) {
		if (($assign(r, $nc(h)->right)) != nullptr) {
			$nc(ConcurrentSkipListMap::RIGHT)->compareAndSet($$new($ObjectArray, {$of(h), $of(r), ($Object*)nullptr}));
		} else if (($assign(d, h->down)) != nullptr) {
			$nc(ConcurrentSkipListMap::HEAD)->compareAndSet($$new($ObjectArray, {$of(this), $of(h), $of(d)}));
		} else {
			int64_t count = 0;
			if (($assign(b, h->node)) != nullptr) {
				$var($ConcurrentSkipListMap$Node, n, nullptr);
				$var($Object, v, nullptr);
				while (($assign(n, $nc(b)->next)) != nullptr) {
					bool var$0 = ($assign(v, $nc(n)->val)) != nullptr;
					if (var$0 && $nc(ConcurrentSkipListMap::VAL)->compareAndSet($$new($ObjectArray, {$of(n), v, ($Object*)nullptr}))) {
						--count;
						$assign(v, nullptr);
					}
					if (v == nullptr) {
						unlinkNode(b, n);
					}
				}
			}
			if (count != (int64_t)0) {
				addCount(count);
			} else {
				break;
			}
		}
	}
}

$Object* ConcurrentSkipListMap::computeIfAbsent(Object$* key, $Function* mappingFunction) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr || mappingFunction == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Object, v, nullptr);
	$var($Object, p, nullptr);
	$var($Object, r, nullptr);
	bool var$0 = ($assign(v, doGet(key))) == nullptr;
	if (var$0 && ($assign(r, $nc(mappingFunction)->apply(key))) != nullptr) {
		$assign(v, ($assign(p, doPut(key, r, true))) == nullptr ? r : p);
	}
	return $of(v);
}

$Object* ConcurrentSkipListMap::computeIfPresent(Object$* key, $BiFunction* remappingFunction) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr || remappingFunction == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	$var($Object, v, nullptr);
	while (($assign(n, findNode(key))) != nullptr) {
		if (($assign(v, $nc(n)->val)) != nullptr) {
			$var($Object, r, $nc(remappingFunction)->apply(key, v));
			if (r != nullptr) {
				if ($nc(ConcurrentSkipListMap::VAL)->compareAndSet($$new($ObjectArray, {$of(n), v, r}))) {
					return $of(r);
				}
			} else if (doRemove(key, v) != nullptr) {
				break;
			}
		}
	}
	return $of(nullptr);
}

$Object* ConcurrentSkipListMap::compute(Object$* key, $BiFunction* remappingFunction) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr || remappingFunction == nullptr) {
		$throwNew($NullPointerException);
	}
	for (;;) {
		$var($ConcurrentSkipListMap$Node, n, nullptr);
		$var($Object, v, nullptr);
		$var($Object, r, nullptr);
		if (($assign(n, findNode(key))) == nullptr) {
			if (($assign(r, $nc(remappingFunction)->apply(key, nullptr))) == nullptr) {
				break;
			}
			if (doPut(key, r, true) == nullptr) {
				return $of(r);
			}
		} else if (($assign(v, $nc(n)->val)) != nullptr) {
			if (($assign(r, $nc(remappingFunction)->apply(key, v))) != nullptr) {
				if ($nc(ConcurrentSkipListMap::VAL)->compareAndSet($$new($ObjectArray, {$of(n), v, r}))) {
					return $of(r);
				}
			} else if (doRemove(key, v) != nullptr) {
				break;
			}
		}
	}
	return $of(nullptr);
}

$Object* ConcurrentSkipListMap::merge(Object$* key, Object$* value, $BiFunction* remappingFunction) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr || value == nullptr || remappingFunction == nullptr) {
		$throwNew($NullPointerException);
	}
	for (;;) {
		$var($ConcurrentSkipListMap$Node, n, nullptr);
		$var($Object, v, nullptr);
		$var($Object, r, nullptr);
		if (($assign(n, findNode(key))) == nullptr) {
			if (doPut(key, value, true) == nullptr) {
				return $of(value);
			}
		} else if (($assign(v, $nc(n)->val)) != nullptr) {
			if (($assign(r, $nc(remappingFunction)->apply(v, value))) != nullptr) {
				if ($nc(ConcurrentSkipListMap::VAL)->compareAndSet($$new($ObjectArray, {$of(n), v, r}))) {
					return $of(r);
				}
			} else if (doRemove(key, v) != nullptr) {
				return $of(nullptr);
			}
		}
	}
}

$Set* ConcurrentSkipListMap::keySet() {
	$var($ConcurrentSkipListMap$KeySet, ks, nullptr);
	if (($assign(ks, this->keySet$)) != nullptr) {
		return static_cast<$Set*>(static_cast<$AbstractSet*>(ks));
	}
	return static_cast<$Set*>(static_cast<$AbstractSet*>(($set(this, keySet$, $new($ConcurrentSkipListMap$KeySet, this)))));
}

$NavigableSet* ConcurrentSkipListMap::navigableKeySet() {
	$var($ConcurrentSkipListMap$KeySet, ks, nullptr);
	if (($assign(ks, this->keySet$)) != nullptr) {
		return ks;
	}
	return ($set(this, keySet$, $new($ConcurrentSkipListMap$KeySet, this)));
}

$Collection* ConcurrentSkipListMap::values() {
	$var($ConcurrentSkipListMap$Values, vs, nullptr);
	if (($assign(vs, this->values$)) != nullptr) {
		return vs;
	}
	return ($set(this, values$, $new($ConcurrentSkipListMap$Values, this)));
}

$Set* ConcurrentSkipListMap::entrySet() {
	$var($ConcurrentSkipListMap$EntrySet, es, nullptr);
	if (($assign(es, this->entrySet$)) != nullptr) {
		return es;
	}
	return ($set(this, entrySet$, $new($ConcurrentSkipListMap$EntrySet, this)));
}

$NavigableMap* ConcurrentSkipListMap::descendingMap() {
	$var($ConcurrentNavigableMap, dm, nullptr);
	if (($assign(dm, this->descendingMap$)) != nullptr) {
		return dm;
	}
	return ($set(this, descendingMap$, $new($ConcurrentSkipListMap$SubMap, this, nullptr, false, nullptr, false, true)));
}

$NavigableSet* ConcurrentSkipListMap::descendingKeySet() {
	return $nc($($cast($ConcurrentNavigableMap, descendingMap())))->navigableKeySet();
}

bool ConcurrentSkipListMap::equals(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if ($equals(o, this)) {
		return true;
	}
	if (!($instanceOf($Map, o))) {
		return false;
	}
	$var($Map, m, $cast($Map, o));
	try {
		$var($Comparator, cmp, this->comparator$);
		$var($Iterator, it, $nc($($nc(m)->entrySet()))->iterator());
		if ($instanceOf($SortedMap, m) && $nc(($cast($SortedMap, m)))->comparator() == cmp) {
			$var($ConcurrentSkipListMap$Node, b, nullptr);
			$var($ConcurrentSkipListMap$Node, n, nullptr);
			if (($assign(b, baseHead())) != nullptr) {
				while (($assign(n, $nc(b)->next)) != nullptr) {
					$var($Object, k, nullptr);
					$var($Object, v, nullptr);
					if (($assign(v, $nc(n)->val)) != nullptr && ($assign(k, n->key)) != nullptr) {
						if (!$nc(it)->hasNext()) {
							return false;
						}
						$var($Map$Entry, e, $cast($Map$Entry, $nc(it)->next()));
						$var($Object, mk, $nc(e)->getKey());
						$var($Object, mv, e->getValue());
						if (mk == nullptr || mv == nullptr) {
							return false;
						}
						try {
							if (cpr(cmp, k, mk) != 0) {
								return false;
							}
						} catch ($ClassCastException& cce) {
							return false;
						}
						if (!$nc($of(mv))->equals(v)) {
							return false;
						}
					}
					$assign(b, n);
				}
			}
			return !$nc(it)->hasNext();
		} else {
			while ($nc(it)->hasNext()) {
				$var($Object, v, nullptr);
				$var($Map$Entry, e, $cast($Map$Entry, it->next()));
				$var($Object, mk, $nc(e)->getKey());
				$var($Object, mv, e->getValue());
				bool var$0 = mk == nullptr || mv == nullptr || ($assign(v, get(mk))) == nullptr;
				if (var$0 || !$nc($of(v))->equals(mv)) {
					return false;
				}
			}
			$var($ConcurrentSkipListMap$Node, b, nullptr);
			$var($ConcurrentSkipListMap$Node, n, nullptr);
			if (($assign(b, baseHead())) != nullptr) {
				$var($Object, k, nullptr);
				$var($Object, v, nullptr);
				$var($Object, mv, nullptr);
				while (($assign(n, $nc(b)->next)) != nullptr) {
					bool var$1 = ($assign(v, $nc(n)->val)) != nullptr && ($assign(k, n->key)) != nullptr;
					if (var$1) {
						bool var$2 = ($assign(mv, m->get(k))) == nullptr;
						var$1 = (var$2 || !$nc($of(mv))->equals(v));
					}
					if (var$1) {
						return false;
					}
					$assign(b, n);
				}
			}
			return true;
		}
	} catch ($ClassCastException& unused) {
		return false;
	} catch ($NullPointerException& unused) {
		return false;
	}
	$shouldNotReachHere();
}

$Object* ConcurrentSkipListMap::putIfAbsent(Object$* key, Object$* value) {
	if (value == nullptr) {
		$throwNew($NullPointerException);
	}
	return $of(doPut(key, value, true));
}

bool ConcurrentSkipListMap::remove(Object$* key, Object$* value) {
	if (key == nullptr) {
		$throwNew($NullPointerException);
	}
	return value != nullptr && doRemove(key, value) != nullptr;
}

bool ConcurrentSkipListMap::replace(Object$* key, Object$* oldValue, Object$* newValue) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr || oldValue == nullptr || newValue == nullptr) {
		$throwNew($NullPointerException);
	}
	for (;;) {
		$var($ConcurrentSkipListMap$Node, n, nullptr);
		$var($Object, v, nullptr);
		if (($assign(n, findNode(key))) == nullptr) {
			return false;
		}
		if (($assign(v, $nc(n)->val)) != nullptr) {
			if (!$nc($of(oldValue))->equals(v)) {
				return false;
			}
			if ($nc(ConcurrentSkipListMap::VAL)->compareAndSet($$new($ObjectArray, {$of(n), v, newValue}))) {
				return true;
			}
		}
	}
}

$Object* ConcurrentSkipListMap::replace(Object$* key, Object$* value) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr || value == nullptr) {
		$throwNew($NullPointerException);
	}
	for (;;) {
		$var($ConcurrentSkipListMap$Node, n, nullptr);
		$var($Object, v, nullptr);
		if (($assign(n, findNode(key))) == nullptr) {
			return $of(nullptr);
		}
		bool var$0 = ($assign(v, $nc(n)->val)) != nullptr;
		if (var$0 && $nc(ConcurrentSkipListMap::VAL)->compareAndSet($$new($ObjectArray, {$of(n), v, value}))) {
			return $of(v);
		}
	}
}

$Comparator* ConcurrentSkipListMap::comparator() {
	return this->comparator$;
}

$Object* ConcurrentSkipListMap::firstKey() {
	$var($ConcurrentSkipListMap$Node, n, findFirst());
	if (n == nullptr) {
		$throwNew($NoSuchElementException);
	}
	return $of($nc(n)->key);
}

$Object* ConcurrentSkipListMap::lastKey() {
	$var($ConcurrentSkipListMap$Node, n, findLast());
	if (n == nullptr) {
		$throwNew($NoSuchElementException);
	}
	return $of($nc(n)->key);
}

$NavigableMap* ConcurrentSkipListMap::subMap(Object$* fromKey, bool fromInclusive, Object$* toKey, bool toInclusive) {
	if (fromKey == nullptr || toKey == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($ConcurrentSkipListMap$SubMap, this, fromKey, fromInclusive, toKey, toInclusive, false);
}

$NavigableMap* ConcurrentSkipListMap::headMap(Object$* toKey, bool inclusive) {
	if (toKey == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($ConcurrentSkipListMap$SubMap, this, nullptr, false, toKey, inclusive, false);
}

$NavigableMap* ConcurrentSkipListMap::tailMap(Object$* fromKey, bool inclusive) {
	if (fromKey == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($ConcurrentSkipListMap$SubMap, this, fromKey, inclusive, nullptr, false, false);
}

$SortedMap* ConcurrentSkipListMap::subMap(Object$* fromKey, Object$* toKey) {
	return subMap(fromKey, true, toKey, false);
}

$SortedMap* ConcurrentSkipListMap::headMap(Object$* toKey) {
	return headMap(toKey, false);
}

$SortedMap* ConcurrentSkipListMap::tailMap(Object$* fromKey) {
	return tailMap(fromKey, true);
}

$Map$Entry* ConcurrentSkipListMap::lowerEntry(Object$* key) {
	return findNearEntry(key, ConcurrentSkipListMap::LT, this->comparator$);
}

$Object* ConcurrentSkipListMap::lowerKey(Object$* key) {
	$var($ConcurrentSkipListMap$Node, n, findNear(key, ConcurrentSkipListMap::LT, this->comparator$));
	return $of((n == nullptr) ? ($Object*)nullptr : $nc(n)->key);
}

$Map$Entry* ConcurrentSkipListMap::floorEntry(Object$* key) {
	return findNearEntry(key, ConcurrentSkipListMap::LT | ConcurrentSkipListMap::EQ, this->comparator$);
}

$Object* ConcurrentSkipListMap::floorKey(Object$* key) {
	$var($ConcurrentSkipListMap$Node, n, findNear(key, ConcurrentSkipListMap::LT | ConcurrentSkipListMap::EQ, this->comparator$));
	return $of((n == nullptr) ? ($Object*)nullptr : $nc(n)->key);
}

$Map$Entry* ConcurrentSkipListMap::ceilingEntry(Object$* key) {
	return findNearEntry(key, ConcurrentSkipListMap::GT | ConcurrentSkipListMap::EQ, this->comparator$);
}

$Object* ConcurrentSkipListMap::ceilingKey(Object$* key) {
	$var($ConcurrentSkipListMap$Node, n, findNear(key, ConcurrentSkipListMap::GT | ConcurrentSkipListMap::EQ, this->comparator$));
	return $of((n == nullptr) ? ($Object*)nullptr : $nc(n)->key);
}

$Map$Entry* ConcurrentSkipListMap::higherEntry(Object$* key) {
	return findNearEntry(key, ConcurrentSkipListMap::GT, this->comparator$);
}

$Object* ConcurrentSkipListMap::higherKey(Object$* key) {
	$var($ConcurrentSkipListMap$Node, n, findNear(key, ConcurrentSkipListMap::GT, this->comparator$));
	return $of((n == nullptr) ? ($Object*)nullptr : $nc(n)->key);
}

$Map$Entry* ConcurrentSkipListMap::firstEntry() {
	return findFirstEntry();
}

$Map$Entry* ConcurrentSkipListMap::lastEntry() {
	return findLastEntry();
}

$Map$Entry* ConcurrentSkipListMap::pollFirstEntry() {
	return doRemoveFirstEntry();
}

$Map$Entry* ConcurrentSkipListMap::pollLastEntry() {
	return doRemoveLastEntry();
}

$List* ConcurrentSkipListMap::toList($Collection* c) {
	$init(ConcurrentSkipListMap);
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, list, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(c)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, e, i$->next());
			list->add(e);
		}
	}
	return list;
}

void ConcurrentSkipListMap::forEach($BiConsumer* action) {
	$useLocalCurrentObjectStackCache();
	if (action == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($ConcurrentSkipListMap$Node, b, nullptr);
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	$var($Object, v, nullptr);
	if (($assign(b, baseHead())) != nullptr) {
		while (($assign(n, $nc(b)->next)) != nullptr) {
			if (($assign(v, $nc(n)->val)) != nullptr) {
				$nc(action)->accept(n->key, v);
			}
			$assign(b, n);
		}
	}
}

void ConcurrentSkipListMap::replaceAll($BiFunction* function) {
	$useLocalCurrentObjectStackCache();
	if (function == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($ConcurrentSkipListMap$Node, b, nullptr);
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	$var($Object, v, nullptr);
	if (($assign(b, baseHead())) != nullptr) {
		while (($assign(n, $nc(b)->next)) != nullptr) {
			while (($assign(v, $nc(n)->val)) != nullptr) {
				$var($Object, r, $nc(function)->apply(n->key, v));
				if (r == nullptr) {
					$throwNew($NullPointerException);
				}
				if ($nc(ConcurrentSkipListMap::VAL)->compareAndSet($$new($ObjectArray, {$of(n), v, r}))) {
					break;
				}
			}
			$assign(b, n);
		}
	}
}

bool ConcurrentSkipListMap::removeEntryIf($Predicate* function) {
	$useLocalCurrentObjectStackCache();
	if (function == nullptr) {
		$throwNew($NullPointerException);
	}
	bool removed = false;
	$var($ConcurrentSkipListMap$Node, b, nullptr);
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	$var($Object, v, nullptr);
	if (($assign(b, baseHead())) != nullptr) {
		while (($assign(n, $nc(b)->next)) != nullptr) {
			if (($assign(v, $nc(n)->val)) != nullptr) {
				$var($Object, k, n->key);
				$var($Map$Entry, e, $new($AbstractMap$SimpleImmutableEntry, k, v));
				bool var$0 = $nc(function)->test(e);
				if (var$0 && remove(k, v)) {
					removed = true;
				}
			}
			$assign(b, n);
		}
	}
	return removed;
}

bool ConcurrentSkipListMap::removeValueIf($Predicate* function) {
	$useLocalCurrentObjectStackCache();
	if (function == nullptr) {
		$throwNew($NullPointerException);
	}
	bool removed = false;
	$var($ConcurrentSkipListMap$Node, b, nullptr);
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	$var($Object, v, nullptr);
	if (($assign(b, baseHead())) != nullptr) {
		while (($assign(n, $nc(b)->next)) != nullptr) {
			bool var$1 = ($assign(v, $nc(n)->val)) != nullptr;
			bool var$0 = var$1 && $nc(function)->test(v);
			if (var$0 && remove(n->key, v)) {
				removed = true;
			}
			$assign(b, n);
		}
	}
	return removed;
}

$ConcurrentSkipListMap$KeySpliterator* ConcurrentSkipListMap::keySpliterator() {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentSkipListMap$Index, h, nullptr);
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	int64_t est = 0;
	$VarHandle::acquireFence();
	if (($assign(h, this->head)) == nullptr) {
		$assign(n, nullptr);
		est = 0;
	} else {
		$assign(n, $nc(h)->node);
		est = getAdderCount();
	}
	return $new($ConcurrentSkipListMap$KeySpliterator, this->comparator$, h, n, nullptr, est);
}

$ConcurrentSkipListMap$ValueSpliterator* ConcurrentSkipListMap::valueSpliterator() {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentSkipListMap$Index, h, nullptr);
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	int64_t est = 0;
	$VarHandle::acquireFence();
	if (($assign(h, this->head)) == nullptr) {
		$assign(n, nullptr);
		est = 0;
	} else {
		$assign(n, $nc(h)->node);
		est = getAdderCount();
	}
	return $new($ConcurrentSkipListMap$ValueSpliterator, this->comparator$, h, n, nullptr, est);
}

$ConcurrentSkipListMap$EntrySpliterator* ConcurrentSkipListMap::entrySpliterator() {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentSkipListMap$Index, h, nullptr);
	$var($ConcurrentSkipListMap$Node, n, nullptr);
	int64_t est = 0;
	$VarHandle::acquireFence();
	if (($assign(h, this->head)) == nullptr) {
		$assign(n, nullptr);
		est = 0;
	} else {
		$assign(n, $nc(h)->node);
		est = getAdderCount();
	}
	return $new($ConcurrentSkipListMap$EntrySpliterator, this->comparator$, h, n, nullptr, est);
}

void clinit$ConcurrentSkipListMap($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$load($ConcurrentSkipListMap$Index);
			$assignStatic(ConcurrentSkipListMap::HEAD, $nc(l)->findVarHandle(ConcurrentSkipListMap::class$, "head"_s, $ConcurrentSkipListMap$Index::class$));
			$load($LongAdder);
			$assignStatic(ConcurrentSkipListMap::ADDER, l->findVarHandle(ConcurrentSkipListMap::class$, "adder"_s, $LongAdder::class$));
			$load($ConcurrentSkipListMap$Node);
			$assignStatic(ConcurrentSkipListMap::NEXT, l->findVarHandle($ConcurrentSkipListMap$Node::class$, "next"_s, $ConcurrentSkipListMap$Node::class$));
			$assignStatic(ConcurrentSkipListMap::VAL, l->findVarHandle($ConcurrentSkipListMap$Node::class$, "val"_s, $Object::class$));
			$assignStatic(ConcurrentSkipListMap::RIGHT, l->findVarHandle($ConcurrentSkipListMap$Index::class$, "right"_s, $ConcurrentSkipListMap$Index::class$));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

ConcurrentSkipListMap::ConcurrentSkipListMap() {
}

$Class* ConcurrentSkipListMap::load$($String* name, bool initialize) {
	$loadClass(ConcurrentSkipListMap, name, initialize, &_ConcurrentSkipListMap_ClassInfo_, clinit$ConcurrentSkipListMap, allocate$ConcurrentSkipListMap);
	return class$;
}

$Class* ConcurrentSkipListMap::class$ = nullptr;

		} // concurrent
	} // util
} // java