#include <java/util/Collections.h>

#include <java/lang/Comparable.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/reflect/Array.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections$1.h>
#include <java/util/Collections$2.h>
#include <java/util/Collections$3.h>
#include <java/util/Collections$AsLIFOQueue.h>
#include <java/util/Collections$CheckedCollection.h>
#include <java/util/Collections$CheckedList.h>
#include <java/util/Collections$CheckedMap.h>
#include <java/util/Collections$CheckedNavigableMap.h>
#include <java/util/Collections$CheckedNavigableSet.h>
#include <java/util/Collections$CheckedQueue.h>
#include <java/util/Collections$CheckedRandomAccessList.h>
#include <java/util/Collections$CheckedSet.h>
#include <java/util/Collections$CheckedSortedMap.h>
#include <java/util/Collections$CheckedSortedSet.h>
#include <java/util/Collections$CopiesList.h>
#include <java/util/Collections$EmptyEnumeration.h>
#include <java/util/Collections$EmptyIterator.h>
#include <java/util/Collections$EmptyList.h>
#include <java/util/Collections$EmptyListIterator.h>
#include <java/util/Collections$EmptyMap.h>
#include <java/util/Collections$EmptySet.h>
#include <java/util/Collections$ReverseComparator.h>
#include <java/util/Collections$ReverseComparator2.h>
#include <java/util/Collections$SetFromMap.h>
#include <java/util/Collections$SingletonList.h>
#include <java/util/Collections$SingletonMap.h>
#include <java/util/Collections$SingletonSet.h>
#include <java/util/Collections$SynchronizedCollection.h>
#include <java/util/Collections$SynchronizedList.h>
#include <java/util/Collections$SynchronizedMap.h>
#include <java/util/Collections$SynchronizedNavigableMap.h>
#include <java/util/Collections$SynchronizedNavigableSet.h>
#include <java/util/Collections$SynchronizedRandomAccessList.h>
#include <java/util/Collections$SynchronizedSet.h>
#include <java/util/Collections$SynchronizedSortedMap.h>
#include <java/util/Collections$SynchronizedSortedSet.h>
#include <java/util/Collections$UnmodifiableCollection.h>
#include <java/util/Collections$UnmodifiableList.h>
#include <java/util/Collections$UnmodifiableMap.h>
#include <java/util/Collections$UnmodifiableNavigableMap$EmptyNavigableMap.h>
#include <java/util/Collections$UnmodifiableNavigableMap.h>
#include <java/util/Collections$UnmodifiableNavigableSet.h>
#include <java/util/Collections$UnmodifiableRandomAccessList.h>
#include <java/util/Collections$UnmodifiableSet.h>
#include <java/util/Collections$UnmodifiableSortedMap.h>
#include <java/util/Collections$UnmodifiableSortedSet.h>
#include <java/util/Comparator.h>
#include <java/util/Comparators$NaturalOrderComparator.h>
#include <java/util/Deque.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/ListIterator.h>
#include <java/util/Map.h>
#include <java/util/NavigableMap.h>
#include <java/util/NavigableSet.h>
#include <java/util/Objects.h>
#include <java/util/Queue.h>
#include <java/util/Random.h>
#include <java/util/RandomAccess.h>
#include <java/util/Set.h>
#include <java/util/SortedMap.h>
#include <java/util/SortedSet.h>
#include <java/util/Spliterator.h>
#include <jcpp.h>

#undef BINARYSEARCH_THRESHOLD
#undef COPY_THRESHOLD
#undef EMPTY_ENUMERATION
#undef EMPTY_ITERATOR
#undef EMPTY_LIST
#undef EMPTY_MAP
#undef EMPTY_NAVIGABLE_MAP
#undef EMPTY_NAVIGABLE_SET
#undef EMPTY_SET
#undef FILL_THRESHOLD
#undef INDEXOFSUBLIST_THRESHOLD
#undef INSTANCE
#undef REPLACEALL_THRESHOLD
#undef REVERSE_ORDER
#undef REVERSE_THRESHOLD
#undef ROTATE_THRESHOLD
#undef SHUFFLE_THRESHOLD

using $ClassInfo = ::java::lang::ClassInfo;
using $Comparable = ::java::lang::Comparable;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $1Array = ::java::lang::reflect::Array;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections$1 = ::java::util::Collections$1;
using $Collections$2 = ::java::util::Collections$2;
using $Collections$3 = ::java::util::Collections$3;
using $Collections$AsLIFOQueue = ::java::util::Collections$AsLIFOQueue;
using $Collections$CheckedCollection = ::java::util::Collections$CheckedCollection;
using $Collections$CheckedList = ::java::util::Collections$CheckedList;
using $Collections$CheckedMap = ::java::util::Collections$CheckedMap;
using $Collections$CheckedNavigableMap = ::java::util::Collections$CheckedNavigableMap;
using $Collections$CheckedNavigableSet = ::java::util::Collections$CheckedNavigableSet;
using $Collections$CheckedQueue = ::java::util::Collections$CheckedQueue;
using $Collections$CheckedRandomAccessList = ::java::util::Collections$CheckedRandomAccessList;
using $Collections$CheckedSet = ::java::util::Collections$CheckedSet;
using $Collections$CheckedSortedMap = ::java::util::Collections$CheckedSortedMap;
using $Collections$CheckedSortedSet = ::java::util::Collections$CheckedSortedSet;
using $Collections$CopiesList = ::java::util::Collections$CopiesList;
using $Collections$EmptyEnumeration = ::java::util::Collections$EmptyEnumeration;
using $Collections$EmptyIterator = ::java::util::Collections$EmptyIterator;
using $Collections$EmptyList = ::java::util::Collections$EmptyList;
using $Collections$EmptyListIterator = ::java::util::Collections$EmptyListIterator;
using $Collections$EmptyMap = ::java::util::Collections$EmptyMap;
using $Collections$EmptySet = ::java::util::Collections$EmptySet;
using $Collections$ReverseComparator = ::java::util::Collections$ReverseComparator;
using $Collections$ReverseComparator2 = ::java::util::Collections$ReverseComparator2;
using $Collections$SetFromMap = ::java::util::Collections$SetFromMap;
using $Collections$SingletonList = ::java::util::Collections$SingletonList;
using $Collections$SingletonMap = ::java::util::Collections$SingletonMap;
using $Collections$SingletonSet = ::java::util::Collections$SingletonSet;
using $Collections$SynchronizedCollection = ::java::util::Collections$SynchronizedCollection;
using $Collections$SynchronizedList = ::java::util::Collections$SynchronizedList;
using $Collections$SynchronizedMap = ::java::util::Collections$SynchronizedMap;
using $Collections$SynchronizedNavigableMap = ::java::util::Collections$SynchronizedNavigableMap;
using $Collections$SynchronizedNavigableSet = ::java::util::Collections$SynchronizedNavigableSet;
using $Collections$SynchronizedRandomAccessList = ::java::util::Collections$SynchronizedRandomAccessList;
using $Collections$SynchronizedSet = ::java::util::Collections$SynchronizedSet;
using $Collections$SynchronizedSortedMap = ::java::util::Collections$SynchronizedSortedMap;
using $Collections$SynchronizedSortedSet = ::java::util::Collections$SynchronizedSortedSet;
using $Collections$UnmodifiableCollection = ::java::util::Collections$UnmodifiableCollection;
using $Collections$UnmodifiableList = ::java::util::Collections$UnmodifiableList;
using $Collections$UnmodifiableMap = ::java::util::Collections$UnmodifiableMap;
using $Collections$UnmodifiableNavigableMap = ::java::util::Collections$UnmodifiableNavigableMap;
using $Collections$UnmodifiableNavigableSet = ::java::util::Collections$UnmodifiableNavigableSet;
using $Collections$UnmodifiableRandomAccessList = ::java::util::Collections$UnmodifiableRandomAccessList;
using $Collections$UnmodifiableSet = ::java::util::Collections$UnmodifiableSet;
using $Collections$UnmodifiableSortedMap = ::java::util::Collections$UnmodifiableSortedMap;
using $Collections$UnmodifiableSortedSet = ::java::util::Collections$UnmodifiableSortedSet;
using $Comparator = ::java::util::Comparator;
using $Comparators$NaturalOrderComparator = ::java::util::Comparators$NaturalOrderComparator;
using $Deque = ::java::util::Deque;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $ListIterator = ::java::util::ListIterator;
using $Map = ::java::util::Map;
using $NavigableMap = ::java::util::NavigableMap;
using $NavigableSet = ::java::util::NavigableSet;
using $Objects = ::java::util::Objects;
using $Queue = ::java::util::Queue;
using $Random = ::java::util::Random;
using $RandomAccess = ::java::util::RandomAccess;
using $Set = ::java::util::Set;
using $SortedMap = ::java::util::SortedMap;
using $SortedSet = ::java::util::SortedSet;
using $Spliterator = ::java::util::Spliterator;

namespace java {
	namespace util {

$CompoundAttribute _Collections_MethodAnnotations_addAll1[] = {
	{"Ljava/lang/SafeVarargs;", nullptr},
	{}
};

$FieldInfo _Collections_FieldInfo_[] = {
	{"BINARYSEARCH_THRESHOLD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Collections, BINARYSEARCH_THRESHOLD)},
	{"REVERSE_THRESHOLD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Collections, REVERSE_THRESHOLD)},
	{"SHUFFLE_THRESHOLD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Collections, SHUFFLE_THRESHOLD)},
	{"FILL_THRESHOLD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Collections, FILL_THRESHOLD)},
	{"ROTATE_THRESHOLD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Collections, ROTATE_THRESHOLD)},
	{"COPY_THRESHOLD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Collections, COPY_THRESHOLD)},
	{"REPLACEALL_THRESHOLD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Collections, REPLACEALL_THRESHOLD)},
	{"INDEXOFSUBLIST_THRESHOLD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Collections, INDEXOFSUBLIST_THRESHOLD)},
	{"r", "Ljava/util/Random;", nullptr, $PRIVATE | $STATIC, $staticField(Collections, r)},
	{"EMPTY_SET", "Ljava/util/Set;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Collections, EMPTY_SET)},
	{"EMPTY_LIST", "Ljava/util/List;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Collections, EMPTY_LIST)},
	{"EMPTY_MAP", "Ljava/util/Map;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Collections, EMPTY_MAP)},
	{}
};

$MethodInfo _Collections_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Collections, init$, void)},
	{"addAll", "(Ljava/util/Collection;[Ljava/lang/Object;)Z", "<T:Ljava/lang/Object;>(Ljava/util/Collection<-TT;>;[TT;)Z", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(Collections, addAll, bool, $Collection*, $ObjectArray*), nullptr, nullptr, _Collections_MethodAnnotations_addAll1},
	{"asLifoQueue", "(Ljava/util/Deque;)Ljava/util/Queue;", "<T:Ljava/lang/Object;>(Ljava/util/Deque<TT;>;)Ljava/util/Queue<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, asLifoQueue, $Queue*, $Deque*)},
	{"binarySearch", "(Ljava/util/List;Ljava/lang/Object;)I", "<T:Ljava/lang/Object;>(Ljava/util/List<+Ljava/lang/Comparable<-TT;>;>;TT;)I", $PUBLIC | $STATIC, $staticMethod(Collections, binarySearch, int32_t, $List*, Object$*)},
	{"binarySearch", "(Ljava/util/List;Ljava/lang/Object;Ljava/util/Comparator;)I", "<T:Ljava/lang/Object;>(Ljava/util/List<+TT;>;TT;Ljava/util/Comparator<-TT;>;)I", $PUBLIC | $STATIC, $staticMethod(Collections, binarySearch, int32_t, $List*, Object$*, $Comparator*)},
	{"checkedCollection", "(Ljava/util/Collection;Ljava/lang/Class;)Ljava/util/Collection;", "<E:Ljava/lang/Object;>(Ljava/util/Collection<TE;>;Ljava/lang/Class<TE;>;)Ljava/util/Collection<TE;>;", $PUBLIC | $STATIC, $staticMethod(Collections, checkedCollection, $Collection*, $Collection*, $Class*)},
	{"checkedList", "(Ljava/util/List;Ljava/lang/Class;)Ljava/util/List;", "<E:Ljava/lang/Object;>(Ljava/util/List<TE;>;Ljava/lang/Class<TE;>;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(Collections, checkedList, $List*, $List*, $Class*)},
	{"checkedMap", "(Ljava/util/Map;Ljava/lang/Class;Ljava/lang/Class;)Ljava/util/Map;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/Map<TK;TV;>;Ljava/lang/Class<TK;>;Ljava/lang/Class<TV;>;)Ljava/util/Map<TK;TV;>;", $PUBLIC | $STATIC, $staticMethod(Collections, checkedMap, $Map*, $Map*, $Class*, $Class*)},
	{"checkedNavigableMap", "(Ljava/util/NavigableMap;Ljava/lang/Class;Ljava/lang/Class;)Ljava/util/NavigableMap;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/NavigableMap<TK;TV;>;Ljava/lang/Class<TK;>;Ljava/lang/Class<TV;>;)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC | $STATIC, $staticMethod(Collections, checkedNavigableMap, $NavigableMap*, $NavigableMap*, $Class*, $Class*)},
	{"checkedNavigableSet", "(Ljava/util/NavigableSet;Ljava/lang/Class;)Ljava/util/NavigableSet;", "<E:Ljava/lang/Object;>(Ljava/util/NavigableSet<TE;>;Ljava/lang/Class<TE;>;)Ljava/util/NavigableSet<TE;>;", $PUBLIC | $STATIC, $staticMethod(Collections, checkedNavigableSet, $NavigableSet*, $NavigableSet*, $Class*)},
	{"checkedQueue", "(Ljava/util/Queue;Ljava/lang/Class;)Ljava/util/Queue;", "<E:Ljava/lang/Object;>(Ljava/util/Queue<TE;>;Ljava/lang/Class<TE;>;)Ljava/util/Queue<TE;>;", $PUBLIC | $STATIC, $staticMethod(Collections, checkedQueue, $Queue*, $Queue*, $Class*)},
	{"checkedSet", "(Ljava/util/Set;Ljava/lang/Class;)Ljava/util/Set;", "<E:Ljava/lang/Object;>(Ljava/util/Set<TE;>;Ljava/lang/Class<TE;>;)Ljava/util/Set<TE;>;", $PUBLIC | $STATIC, $staticMethod(Collections, checkedSet, $Set*, $Set*, $Class*)},
	{"checkedSortedMap", "(Ljava/util/SortedMap;Ljava/lang/Class;Ljava/lang/Class;)Ljava/util/SortedMap;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/SortedMap<TK;TV;>;Ljava/lang/Class<TK;>;Ljava/lang/Class<TV;>;)Ljava/util/SortedMap<TK;TV;>;", $PUBLIC | $STATIC, $staticMethod(Collections, checkedSortedMap, $SortedMap*, $SortedMap*, $Class*, $Class*)},
	{"checkedSortedSet", "(Ljava/util/SortedSet;Ljava/lang/Class;)Ljava/util/SortedSet;", "<E:Ljava/lang/Object;>(Ljava/util/SortedSet<TE;>;Ljava/lang/Class<TE;>;)Ljava/util/SortedSet<TE;>;", $PUBLIC | $STATIC, $staticMethod(Collections, checkedSortedSet, $SortedSet*, $SortedSet*, $Class*)},
	{"copy", "(Ljava/util/List;Ljava/util/List;)V", "<T:Ljava/lang/Object;>(Ljava/util/List<-TT;>;Ljava/util/List<+TT;>;)V", $PUBLIC | $STATIC, $staticMethod(Collections, copy, void, $List*, $List*)},
	{"disjoint", "(Ljava/util/Collection;Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;Ljava/util/Collection<*>;)Z", $PUBLIC | $STATIC, $staticMethod(Collections, disjoint, bool, $Collection*, $Collection*)},
	{"emptyEnumeration", "()Ljava/util/Enumeration;", "<T:Ljava/lang/Object;>()Ljava/util/Enumeration<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, emptyEnumeration, $Enumeration*)},
	{"emptyIterator", "()Ljava/util/Iterator;", "<T:Ljava/lang/Object;>()Ljava/util/Iterator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, emptyIterator, $Iterator*)},
	{"emptyList", "()Ljava/util/List;", "<T:Ljava/lang/Object;>()Ljava/util/List<TT;>;", $PUBLIC | $STATIC | $FINAL, $staticMethod(Collections, emptyList, $List*)},
	{"emptyListIterator", "()Ljava/util/ListIterator;", "<T:Ljava/lang/Object;>()Ljava/util/ListIterator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, emptyListIterator, $ListIterator*)},
	{"emptyMap", "()Ljava/util/Map;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>()Ljava/util/Map<TK;TV;>;", $PUBLIC | $STATIC | $FINAL, $staticMethod(Collections, emptyMap, $Map*)},
	{"emptyNavigableMap", "()Ljava/util/NavigableMap;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>()Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC | $STATIC | $FINAL, $staticMethod(Collections, emptyNavigableMap, $NavigableMap*)},
	{"emptyNavigableSet", "()Ljava/util/NavigableSet;", "<E:Ljava/lang/Object;>()Ljava/util/NavigableSet<TE;>;", $PUBLIC | $STATIC, $staticMethod(Collections, emptyNavigableSet, $NavigableSet*)},
	{"emptySet", "()Ljava/util/Set;", "<T:Ljava/lang/Object;>()Ljava/util/Set<TT;>;", $PUBLIC | $STATIC | $FINAL, $staticMethod(Collections, emptySet, $Set*)},
	{"emptySortedMap", "()Ljava/util/SortedMap;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>()Ljava/util/SortedMap<TK;TV;>;", $PUBLIC | $STATIC | $FINAL, $staticMethod(Collections, emptySortedMap, $SortedMap*)},
	{"emptySortedSet", "()Ljava/util/SortedSet;", "<E:Ljava/lang/Object;>()Ljava/util/SortedSet<TE;>;", $PUBLIC | $STATIC, $staticMethod(Collections, emptySortedSet, $SortedSet*)},
	{"enumeration", "(Ljava/util/Collection;)Ljava/util/Enumeration;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<TT;>;)Ljava/util/Enumeration<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, enumeration, $Enumeration*, $Collection*)},
	{"eq", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $STATIC, $staticMethod(Collections, eq, bool, Object$*, Object$*)},
	{"fill", "(Ljava/util/List;Ljava/lang/Object;)V", "<T:Ljava/lang/Object;>(Ljava/util/List<-TT;>;TT;)V", $PUBLIC | $STATIC, $staticMethod(Collections, fill, void, $List*, Object$*)},
	{"frequency", "(Ljava/util/Collection;Ljava/lang/Object;)I", "(Ljava/util/Collection<*>;Ljava/lang/Object;)I", $PUBLIC | $STATIC, $staticMethod(Collections, frequency, int32_t, $Collection*, Object$*)},
	{"get", "(Ljava/util/ListIterator;I)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/util/ListIterator<+TT;>;I)TT;", $PRIVATE | $STATIC, $staticMethod(Collections, get, $Object*, $ListIterator*, int32_t)},
	{"indexOfSubList", "(Ljava/util/List;Ljava/util/List;)I", "(Ljava/util/List<*>;Ljava/util/List<*>;)I", $PUBLIC | $STATIC, $staticMethod(Collections, indexOfSubList, int32_t, $List*, $List*)},
	{"indexedBinarySearch", "(Ljava/util/List;Ljava/lang/Object;)I", "<T:Ljava/lang/Object;>(Ljava/util/List<+Ljava/lang/Comparable<-TT;>;>;TT;)I", $PRIVATE | $STATIC, $staticMethod(Collections, indexedBinarySearch, int32_t, $List*, Object$*)},
	{"indexedBinarySearch", "(Ljava/util/List;Ljava/lang/Object;Ljava/util/Comparator;)I", "<T:Ljava/lang/Object;>(Ljava/util/List<+TT;>;TT;Ljava/util/Comparator<-TT;>;)I", $PRIVATE | $STATIC, $staticMethod(Collections, indexedBinarySearch, int32_t, $List*, Object$*, $Comparator*)},
	{"iteratorBinarySearch", "(Ljava/util/List;Ljava/lang/Object;)I", "<T:Ljava/lang/Object;>(Ljava/util/List<+Ljava/lang/Comparable<-TT;>;>;TT;)I", $PRIVATE | $STATIC, $staticMethod(Collections, iteratorBinarySearch, int32_t, $List*, Object$*)},
	{"iteratorBinarySearch", "(Ljava/util/List;Ljava/lang/Object;Ljava/util/Comparator;)I", "<T:Ljava/lang/Object;>(Ljava/util/List<+TT;>;TT;Ljava/util/Comparator<-TT;>;)I", $PRIVATE | $STATIC, $staticMethod(Collections, iteratorBinarySearch, int32_t, $List*, Object$*, $Comparator*)},
	{"lastIndexOfSubList", "(Ljava/util/List;Ljava/util/List;)I", "(Ljava/util/List<*>;Ljava/util/List<*>;)I", $PUBLIC | $STATIC, $staticMethod(Collections, lastIndexOfSubList, int32_t, $List*, $List*)},
	{"list", "(Ljava/util/Enumeration;)Ljava/util/ArrayList;", "<T:Ljava/lang/Object;>(Ljava/util/Enumeration<TT;>;)Ljava/util/ArrayList<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, list, $ArrayList*, $Enumeration*)},
	{"max", "(Ljava/util/Collection;)Ljava/lang/Object;", "<T:Ljava/lang/Object;:Ljava/lang/Comparable<-TT;>;>(Ljava/util/Collection<+TT;>;)TT;", $PUBLIC | $STATIC, $staticMethod(Collections, max, $Object*, $Collection*)},
	{"max", "(Ljava/util/Collection;Ljava/util/Comparator;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<+TT;>;Ljava/util/Comparator<-TT;>;)TT;", $PUBLIC | $STATIC, $staticMethod(Collections, max, $Object*, $Collection*, $Comparator*)},
	{"min", "(Ljava/util/Collection;)Ljava/lang/Object;", "<T:Ljava/lang/Object;:Ljava/lang/Comparable<-TT;>;>(Ljava/util/Collection<+TT;>;)TT;", $PUBLIC | $STATIC, $staticMethod(Collections, min, $Object*, $Collection*)},
	{"min", "(Ljava/util/Collection;Ljava/util/Comparator;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<+TT;>;Ljava/util/Comparator<-TT;>;)TT;", $PUBLIC | $STATIC, $staticMethod(Collections, min, $Object*, $Collection*, $Comparator*)},
	{"nCopies", "(ILjava/lang/Object;)Ljava/util/List;", "<T:Ljava/lang/Object;>(ITT;)Ljava/util/List<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, nCopies, $List*, int32_t, Object$*)},
	{"newSetFromMap", "(Ljava/util/Map;)Ljava/util/Set;", "<E:Ljava/lang/Object;>(Ljava/util/Map<TE;Ljava/lang/Boolean;>;)Ljava/util/Set<TE;>;", $PUBLIC | $STATIC, $staticMethod(Collections, newSetFromMap, $Set*, $Map*)},
	{"replaceAll", "(Ljava/util/List;Ljava/lang/Object;Ljava/lang/Object;)Z", "<T:Ljava/lang/Object;>(Ljava/util/List<TT;>;TT;TT;)Z", $PUBLIC | $STATIC, $staticMethod(Collections, replaceAll, bool, $List*, Object$*, Object$*)},
	{"reverse", "(Ljava/util/List;)V", "(Ljava/util/List<*>;)V", $PUBLIC | $STATIC, $staticMethod(Collections, reverse, void, $List*)},
	{"reverseOrder", "()Ljava/util/Comparator;", "<T:Ljava/lang/Object;>()Ljava/util/Comparator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, reverseOrder, $Comparator*)},
	{"reverseOrder", "(Ljava/util/Comparator;)Ljava/util/Comparator;", "<T:Ljava/lang/Object;>(Ljava/util/Comparator<TT;>;)Ljava/util/Comparator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, reverseOrder, $Comparator*, $Comparator*)},
	{"rotate", "(Ljava/util/List;I)V", "(Ljava/util/List<*>;I)V", $PUBLIC | $STATIC, $staticMethod(Collections, rotate, void, $List*, int32_t)},
	{"rotate1", "(Ljava/util/List;I)V", "<T:Ljava/lang/Object;>(Ljava/util/List<TT;>;I)V", $PRIVATE | $STATIC, $staticMethod(Collections, rotate1, void, $List*, int32_t)},
	{"rotate2", "(Ljava/util/List;I)V", "(Ljava/util/List<*>;I)V", $PRIVATE | $STATIC, $staticMethod(Collections, rotate2, void, $List*, int32_t)},
	{"shuffle", "(Ljava/util/List;)V", "(Ljava/util/List<*>;)V", $PUBLIC | $STATIC, $staticMethod(Collections, shuffle, void, $List*)},
	{"shuffle", "(Ljava/util/List;Ljava/util/Random;)V", "(Ljava/util/List<*>;Ljava/util/Random;)V", $PUBLIC | $STATIC, $staticMethod(Collections, shuffle, void, $List*, $Random*)},
	{"singleton", "(Ljava/lang/Object;)Ljava/util/Set;", "<T:Ljava/lang/Object;>(TT;)Ljava/util/Set<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, singleton, $Set*, Object$*)},
	{"singletonIterator", "(Ljava/lang/Object;)Ljava/util/Iterator;", "<E:Ljava/lang/Object;>(TE;)Ljava/util/Iterator<TE;>;", $STATIC, $staticMethod(Collections, singletonIterator, $Iterator*, Object$*)},
	{"singletonList", "(Ljava/lang/Object;)Ljava/util/List;", "<T:Ljava/lang/Object;>(TT;)Ljava/util/List<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, singletonList, $List*, Object$*)},
	{"singletonMap", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/Map;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(TK;TV;)Ljava/util/Map<TK;TV;>;", $PUBLIC | $STATIC, $staticMethod(Collections, singletonMap, $Map*, Object$*, Object$*)},
	{"singletonSpliterator", "(Ljava/lang/Object;)Ljava/util/Spliterator;", "<T:Ljava/lang/Object;>(TT;)Ljava/util/Spliterator<TT;>;", $STATIC, $staticMethod(Collections, singletonSpliterator, $Spliterator*, Object$*)},
	{"sort", "(Ljava/util/List;)V", "<T::Ljava/lang/Comparable<-TT;>;>(Ljava/util/List<TT;>;)V", $PUBLIC | $STATIC, $staticMethod(Collections, sort, void, $List*)},
	{"sort", "(Ljava/util/List;Ljava/util/Comparator;)V", "<T:Ljava/lang/Object;>(Ljava/util/List<TT;>;Ljava/util/Comparator<-TT;>;)V", $PUBLIC | $STATIC, $staticMethod(Collections, sort, void, $List*, $Comparator*)},
	{"swap", "(Ljava/util/List;II)V", "(Ljava/util/List<*>;II)V", $PUBLIC | $STATIC, $staticMethod(Collections, swap, void, $List*, int32_t, int32_t)},
	{"swap", "([Ljava/lang/Object;II)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Collections, swap, void, $ObjectArray*, int32_t, int32_t)},
	{"synchronizedCollection", "(Ljava/util/Collection;)Ljava/util/Collection;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<TT;>;)Ljava/util/Collection<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, synchronizedCollection, $Collection*, $Collection*)},
	{"synchronizedCollection", "(Ljava/util/Collection;Ljava/lang/Object;)Ljava/util/Collection;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<TT;>;Ljava/lang/Object;)Ljava/util/Collection<TT;>;", $STATIC, $staticMethod(Collections, synchronizedCollection, $Collection*, $Collection*, Object$*)},
	{"synchronizedList", "(Ljava/util/List;)Ljava/util/List;", "<T:Ljava/lang/Object;>(Ljava/util/List<TT;>;)Ljava/util/List<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, synchronizedList, $List*, $List*)},
	{"synchronizedList", "(Ljava/util/List;Ljava/lang/Object;)Ljava/util/List;", "<T:Ljava/lang/Object;>(Ljava/util/List<TT;>;Ljava/lang/Object;)Ljava/util/List<TT;>;", $STATIC, $staticMethod(Collections, synchronizedList, $List*, $List*, Object$*)},
	{"synchronizedMap", "(Ljava/util/Map;)Ljava/util/Map;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/Map<TK;TV;>;)Ljava/util/Map<TK;TV;>;", $PUBLIC | $STATIC, $staticMethod(Collections, synchronizedMap, $Map*, $Map*)},
	{"synchronizedNavigableMap", "(Ljava/util/NavigableMap;)Ljava/util/NavigableMap;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/NavigableMap<TK;TV;>;)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC | $STATIC, $staticMethod(Collections, synchronizedNavigableMap, $NavigableMap*, $NavigableMap*)},
	{"synchronizedNavigableSet", "(Ljava/util/NavigableSet;)Ljava/util/NavigableSet;", "<T:Ljava/lang/Object;>(Ljava/util/NavigableSet<TT;>;)Ljava/util/NavigableSet<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, synchronizedNavigableSet, $NavigableSet*, $NavigableSet*)},
	{"synchronizedSet", "(Ljava/util/Set;)Ljava/util/Set;", "<T:Ljava/lang/Object;>(Ljava/util/Set<TT;>;)Ljava/util/Set<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, synchronizedSet, $Set*, $Set*)},
	{"synchronizedSet", "(Ljava/util/Set;Ljava/lang/Object;)Ljava/util/Set;", "<T:Ljava/lang/Object;>(Ljava/util/Set<TT;>;Ljava/lang/Object;)Ljava/util/Set<TT;>;", $STATIC, $staticMethod(Collections, synchronizedSet, $Set*, $Set*, Object$*)},
	{"synchronizedSortedMap", "(Ljava/util/SortedMap;)Ljava/util/SortedMap;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/SortedMap<TK;TV;>;)Ljava/util/SortedMap<TK;TV;>;", $PUBLIC | $STATIC, $staticMethod(Collections, synchronizedSortedMap, $SortedMap*, $SortedMap*)},
	{"synchronizedSortedSet", "(Ljava/util/SortedSet;)Ljava/util/SortedSet;", "<T:Ljava/lang/Object;>(Ljava/util/SortedSet<TT;>;)Ljava/util/SortedSet<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, synchronizedSortedSet, $SortedSet*, $SortedSet*)},
	{"unmodifiableCollection", "(Ljava/util/Collection;)Ljava/util/Collection;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<+TT;>;)Ljava/util/Collection<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, unmodifiableCollection, $Collection*, $Collection*)},
	{"unmodifiableList", "(Ljava/util/List;)Ljava/util/List;", "<T:Ljava/lang/Object;>(Ljava/util/List<+TT;>;)Ljava/util/List<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, unmodifiableList, $List*, $List*)},
	{"unmodifiableMap", "(Ljava/util/Map;)Ljava/util/Map;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/Map<+TK;+TV;>;)Ljava/util/Map<TK;TV;>;", $PUBLIC | $STATIC, $staticMethod(Collections, unmodifiableMap, $Map*, $Map*)},
	{"unmodifiableNavigableMap", "(Ljava/util/NavigableMap;)Ljava/util/NavigableMap;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/NavigableMap<TK;+TV;>;)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC | $STATIC, $staticMethod(Collections, unmodifiableNavigableMap, $NavigableMap*, $NavigableMap*)},
	{"unmodifiableNavigableSet", "(Ljava/util/NavigableSet;)Ljava/util/NavigableSet;", "<T:Ljava/lang/Object;>(Ljava/util/NavigableSet<TT;>;)Ljava/util/NavigableSet<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, unmodifiableNavigableSet, $NavigableSet*, $NavigableSet*)},
	{"unmodifiableSet", "(Ljava/util/Set;)Ljava/util/Set;", "<T:Ljava/lang/Object;>(Ljava/util/Set<+TT;>;)Ljava/util/Set<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, unmodifiableSet, $Set*, $Set*)},
	{"unmodifiableSortedMap", "(Ljava/util/SortedMap;)Ljava/util/SortedMap;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/SortedMap<TK;+TV;>;)Ljava/util/SortedMap<TK;TV;>;", $PUBLIC | $STATIC, $staticMethod(Collections, unmodifiableSortedMap, $SortedMap*, $SortedMap*)},
	{"unmodifiableSortedSet", "(Ljava/util/SortedSet;)Ljava/util/SortedSet;", "<T:Ljava/lang/Object;>(Ljava/util/SortedSet<TT;>;)Ljava/util/SortedSet<TT;>;", $PUBLIC | $STATIC, $staticMethod(Collections, unmodifiableSortedSet, $SortedSet*, $SortedSet*)},
	{"zeroLengthArray", "(Ljava/lang/Class;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/lang/Class<TT;>;)[TT;", $STATIC, $staticMethod(Collections, zeroLengthArray, $ObjectArray*, $Class*)},
	{}
};

$InnerClassInfo _Collections_InnerClassesInfo_[] = {
	{"java.util.Collections$AsLIFOQueue", "java.util.Collections", "AsLIFOQueue", $STATIC},
	{"java.util.Collections$SetFromMap", "java.util.Collections", "SetFromMap", $PRIVATE | $STATIC},
	{"java.util.Collections$ReverseComparator2", "java.util.Collections", "ReverseComparator2", $PRIVATE | $STATIC},
	{"java.util.Collections$ReverseComparator", "java.util.Collections", "ReverseComparator", $PRIVATE | $STATIC},
	{"java.util.Collections$CopiesList", "java.util.Collections", "CopiesList", $PRIVATE | $STATIC},
	{"java.util.Collections$SingletonMap", "java.util.Collections", "SingletonMap", $PRIVATE | $STATIC},
	{"java.util.Collections$SingletonList", "java.util.Collections", "SingletonList", $PRIVATE | $STATIC},
	{"java.util.Collections$SingletonSet", "java.util.Collections", "SingletonSet", $PRIVATE | $STATIC},
	{"java.util.Collections$EmptyMap", "java.util.Collections", "EmptyMap", $PRIVATE | $STATIC},
	{"java.util.Collections$EmptyList", "java.util.Collections", "EmptyList", $PRIVATE | $STATIC},
	{"java.util.Collections$EmptySet", "java.util.Collections", "EmptySet", $PRIVATE | $STATIC},
	{"java.util.Collections$EmptyEnumeration", "java.util.Collections", "EmptyEnumeration", $PRIVATE | $STATIC},
	{"java.util.Collections$EmptyListIterator", "java.util.Collections", "EmptyListIterator", $PRIVATE | $STATIC},
	{"java.util.Collections$EmptyIterator", "java.util.Collections", "EmptyIterator", $PRIVATE | $STATIC},
	{"java.util.Collections$CheckedNavigableMap", "java.util.Collections", "CheckedNavigableMap", $STATIC},
	{"java.util.Collections$CheckedSortedMap", "java.util.Collections", "CheckedSortedMap", $STATIC},
	{"java.util.Collections$CheckedMap", "java.util.Collections", "CheckedMap", $PRIVATE | $STATIC},
	{"java.util.Collections$CheckedRandomAccessList", "java.util.Collections", "CheckedRandomAccessList", $STATIC},
	{"java.util.Collections$CheckedList", "java.util.Collections", "CheckedList", $STATIC},
	{"java.util.Collections$CheckedNavigableSet", "java.util.Collections", "CheckedNavigableSet", $STATIC},
	{"java.util.Collections$CheckedSortedSet", "java.util.Collections", "CheckedSortedSet", $STATIC},
	{"java.util.Collections$CheckedSet", "java.util.Collections", "CheckedSet", $STATIC},
	{"java.util.Collections$CheckedQueue", "java.util.Collections", "CheckedQueue", $STATIC},
	{"java.util.Collections$CheckedCollection", "java.util.Collections", "CheckedCollection", $STATIC},
	{"java.util.Collections$SynchronizedNavigableMap", "java.util.Collections", "SynchronizedNavigableMap", $STATIC},
	{"java.util.Collections$SynchronizedSortedMap", "java.util.Collections", "SynchronizedSortedMap", $STATIC},
	{"java.util.Collections$SynchronizedMap", "java.util.Collections", "SynchronizedMap", $PRIVATE | $STATIC},
	{"java.util.Collections$SynchronizedRandomAccessList", "java.util.Collections", "SynchronizedRandomAccessList", $STATIC},
	{"java.util.Collections$SynchronizedList", "java.util.Collections", "SynchronizedList", $STATIC},
	{"java.util.Collections$SynchronizedNavigableSet", "java.util.Collections", "SynchronizedNavigableSet", $STATIC},
	{"java.util.Collections$SynchronizedSortedSet", "java.util.Collections", "SynchronizedSortedSet", $STATIC},
	{"java.util.Collections$SynchronizedSet", "java.util.Collections", "SynchronizedSet", $STATIC},
	{"java.util.Collections$SynchronizedCollection", "java.util.Collections", "SynchronizedCollection", $STATIC},
	{"java.util.Collections$UnmodifiableNavigableMap", "java.util.Collections", "UnmodifiableNavigableMap", $STATIC},
	{"java.util.Collections$UnmodifiableSortedMap", "java.util.Collections", "UnmodifiableSortedMap", $STATIC},
	{"java.util.Collections$UnmodifiableMap", "java.util.Collections", "UnmodifiableMap", $PRIVATE | $STATIC},
	{"java.util.Collections$UnmodifiableRandomAccessList", "java.util.Collections", "UnmodifiableRandomAccessList", $STATIC},
	{"java.util.Collections$UnmodifiableList", "java.util.Collections", "UnmodifiableList", $STATIC},
	{"java.util.Collections$UnmodifiableNavigableSet", "java.util.Collections", "UnmodifiableNavigableSet", $STATIC},
	{"java.util.Collections$UnmodifiableSortedSet", "java.util.Collections", "UnmodifiableSortedSet", $STATIC},
	{"java.util.Collections$UnmodifiableSet", "java.util.Collections", "UnmodifiableSet", $STATIC},
	{"java.util.Collections$UnmodifiableCollection", "java.util.Collections", "UnmodifiableCollection", $STATIC},
	{"java.util.Collections$3", nullptr, nullptr, 0},
	{"java.util.Collections$2", nullptr, nullptr, 0},
	{"java.util.Collections$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Collections_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.Collections",
	"java.lang.Object",
	nullptr,
	_Collections_FieldInfo_,
	_Collections_MethodInfo_,
	nullptr,
	nullptr,
	_Collections_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.Collections$AsLIFOQueue,java.util.Collections$SetFromMap,java.util.Collections$ReverseComparator2,java.util.Collections$ReverseComparator,java.util.Collections$CopiesList,java.util.Collections$SingletonMap,java.util.Collections$SingletonList,java.util.Collections$SingletonSet,java.util.Collections$EmptyMap,java.util.Collections$EmptyList,java.util.Collections$EmptySet,java.util.Collections$EmptyEnumeration,java.util.Collections$EmptyListIterator,java.util.Collections$EmptyIterator,java.util.Collections$CheckedNavigableMap,java.util.Collections$CheckedSortedMap,java.util.Collections$CheckedMap,java.util.Collections$CheckedMap$CheckedEntrySet,java.util.Collections$CheckedMap$CheckedEntrySet$CheckedEntry,java.util.Collections$CheckedMap$CheckedEntrySet$1,java.util.Collections$CheckedRandomAccessList,java.util.Collections$CheckedList,java.util.Collections$CheckedList$1,java.util.Collections$CheckedNavigableSet,java.util.Collections$CheckedSortedSet,java.util.Collections$CheckedSet,java.util.Collections$CheckedQueue,java.util.Collections$CheckedCollection,java.util.Collections$CheckedCollection$1,java.util.Collections$SynchronizedNavigableMap,java.util.Collections$SynchronizedSortedMap,java.util.Collections$SynchronizedMap,java.util.Collections$SynchronizedRandomAccessList,java.util.Collections$SynchronizedList,java.util.Collections$SynchronizedNavigableSet,java.util.Collections$SynchronizedSortedSet,java.util.Collections$SynchronizedSet,java.util.Collections$SynchronizedCollection,java.util.Collections$UnmodifiableNavigableMap,java.util.Collections$UnmodifiableNavigableMap$EmptyNavigableMap,java.util.Collections$UnmodifiableSortedMap,java.util.Collections$UnmodifiableMap,java.util.Collections$UnmodifiableMap$UnmodifiableEntrySet,java.util.Collections$UnmodifiableMap$UnmodifiableEntrySet$UnmodifiableEntry,java.util.Collections$UnmodifiableMap$UnmodifiableEntrySet$UnmodifiableEntrySetSpliterator,java.util.Collections$UnmodifiableMap$UnmodifiableEntrySet$1,java.util.Collections$UnmodifiableRandomAccessList,java.util.Collections$UnmodifiableList,java.util.Collections$UnmodifiableList$1,java.util.Collections$UnmodifiableNavigableSet,java.util.Collections$UnmodifiableNavigableSet$EmptyNavigableSet,java.util.Collections$UnmodifiableSortedSet,java.util.Collections$UnmodifiableSet,java.util.Collections$UnmodifiableCollection,java.util.Collections$UnmodifiableCollection$1,java.util.Collections$3,java.util.Collections$2,java.util.Collections$1"
};

$Object* allocate$Collections($Class* clazz) {
	return $of($alloc(Collections));
}

$Random* Collections::r = nullptr;
$Set* Collections::EMPTY_SET = nullptr;
$List* Collections::EMPTY_LIST = nullptr;
$Map* Collections::EMPTY_MAP = nullptr;

void Collections::init$() {
}

void Collections::sort($List* list) {
	$init(Collections);
	$nc(list)->sort(nullptr);
}

void Collections::sort($List* list, $Comparator* c) {
	$init(Collections);
	$nc(list)->sort(c);
}

int32_t Collections::binarySearch($List* list, Object$* key) {
	$init(Collections);
	if ($instanceOf($RandomAccess, list) || $nc(list)->size() < Collections::BINARYSEARCH_THRESHOLD) {
		return Collections::indexedBinarySearch(list, key);
	} else {
		return Collections::iteratorBinarySearch(list, key);
	}
}

int32_t Collections::indexedBinarySearch($List* list, Object$* key) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	int32_t low = 0;
	int32_t high = $nc(list)->size() - 1;
	while (low <= high) {
		int32_t mid = (int32_t)((uint32_t)(low + high) >> 1);
		$var($Comparable, midVal, $cast($Comparable, list->get(mid)));
		int32_t cmp = $nc(midVal)->compareTo(key);
		if (cmp < 0) {
			low = mid + 1;
		} else if (cmp > 0) {
			high = mid - 1;
		} else {
			return mid;
		}
	}
	return -(low + 1);
}

int32_t Collections::iteratorBinarySearch($List* list, Object$* key) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	int32_t low = 0;
	int32_t high = $nc(list)->size() - 1;
	$var($ListIterator, i, list->listIterator());
	while (low <= high) {
		int32_t mid = (int32_t)((uint32_t)(low + high) >> 1);
		$var($Comparable, midVal, $cast($Comparable, get(i, mid)));
		int32_t cmp = $nc(midVal)->compareTo(key);
		if (cmp < 0) {
			low = mid + 1;
		} else if (cmp > 0) {
			high = mid - 1;
		} else {
			return mid;
		}
	}
	return -(low + 1);
}

$Object* Collections::get($ListIterator* i, int32_t index) {
	$init(Collections);
	$var($Object, obj, nullptr);
	int32_t pos = $nc(i)->nextIndex();
	if (pos <= index) {
		do {
			$assign(obj, i->next());
		} while (pos++ < index);
	} else {
		do {
			$assign(obj, i->previous());
		} while (--pos > index);
	}
	return $of(obj);
}

int32_t Collections::binarySearch($List* list, Object$* key, $Comparator* c) {
	$init(Collections);
	if (c == nullptr) {
		return binarySearch(list, key);
	}
	if ($instanceOf($RandomAccess, list) || $nc(list)->size() < Collections::BINARYSEARCH_THRESHOLD) {
		return Collections::indexedBinarySearch(list, key, c);
	} else {
		return Collections::iteratorBinarySearch(list, key, c);
	}
}

int32_t Collections::indexedBinarySearch($List* l, Object$* key, $Comparator* c) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	int32_t low = 0;
	int32_t high = $nc(l)->size() - 1;
	while (low <= high) {
		int32_t mid = (int32_t)((uint32_t)(low + high) >> 1);
		$var($Object, midVal, l->get(mid));
		int32_t cmp = $nc(c)->compare(midVal, key);
		if (cmp < 0) {
			low = mid + 1;
		} else if (cmp > 0) {
			high = mid - 1;
		} else {
			return mid;
		}
	}
	return -(low + 1);
}

int32_t Collections::iteratorBinarySearch($List* l, Object$* key, $Comparator* c) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	int32_t low = 0;
	int32_t high = $nc(l)->size() - 1;
	$var($ListIterator, i, l->listIterator());
	while (low <= high) {
		int32_t mid = (int32_t)((uint32_t)(low + high) >> 1);
		$var($Object, midVal, get(i, mid));
		int32_t cmp = $nc(c)->compare(midVal, key);
		if (cmp < 0) {
			low = mid + 1;
		} else if (cmp > 0) {
			high = mid - 1;
		} else {
			return mid;
		}
	}
	return -(low + 1);
}

void Collections::reverse($List* list) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	int32_t size = $nc(list)->size();
	if (size < Collections::REVERSE_THRESHOLD || $instanceOf($RandomAccess, list)) {
		{
			int32_t i = 0;
			int32_t mid = size >> 1;
			int32_t j = size - 1;
			for (; i < mid; ++i, --j) {
				swap(list, i, j);
			}
		}
	} else {
		$var($ListIterator, fwd, list->listIterator());
		$var($ListIterator, rev, list->listIterator(size));
		{
			int32_t i = 0;
			int32_t mid = list->size() >> 1;
			for (; i < mid; ++i) {
				$var($Object, tmp, $nc(fwd)->next());
				fwd->set($($nc(rev)->previous()));
				$nc(rev)->set(tmp);
			}
		}
	}
}

void Collections::shuffle($List* list) {
	$init(Collections);
	$var($Random, rnd, Collections::r);
	if (rnd == nullptr) {
		$assignStatic(Collections::r, ($assign(rnd, $new($Random))));
	}
	shuffle(list, rnd);
}

void Collections::shuffle($List* list, $Random* rnd) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	int32_t size = $nc(list)->size();
	if (size < Collections::SHUFFLE_THRESHOLD || $instanceOf($RandomAccess, list)) {
		for (int32_t i = size; i > 1; --i) {
			swap(list, i - 1, $nc(rnd)->nextInt(i));
		}
	} else {
		$var($ObjectArray, arr, list->toArray());
		for (int32_t i = size; i > 1; --i) {
			swap(arr, i - 1, $nc(rnd)->nextInt(i));
		}
		$var($ListIterator, it, list->listIterator());
		{
			$var($ObjectArray, arr$, arr);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Object0, e, arr$->get(i$));
				{
					$nc(it)->next();
					it->set(e);
				}
			}
		}
	}
}

void Collections::swap($List* list, int32_t i, int32_t j) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	$var($List, l, list);
	$nc(l)->set(i, $(l->set(j, $(l->get(i)))));
}

void Collections::swap($ObjectArray* arr, int32_t i, int32_t j) {
	$init(Collections);
	$var($Object0, tmp, $nc(arr)->get(i));
	arr->set(i, arr->get(j));
	arr->set(j, tmp);
}

void Collections::fill($List* list, Object$* obj) {
	$init(Collections);
	int32_t size = $nc(list)->size();
	if (size < Collections::FILL_THRESHOLD || $instanceOf($RandomAccess, list)) {
		for (int32_t i = 0; i < size; ++i) {
			list->set(i, obj);
		}
	} else {
		$var($ListIterator, itr, list->listIterator());
		for (int32_t i = 0; i < size; ++i) {
			$nc(itr)->next();
			itr->set(obj);
		}
	}
}

void Collections::copy($List* dest, $List* src) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	int32_t srcSize = $nc(src)->size();
	if (srcSize > $nc(dest)->size()) {
		$throwNew($IndexOutOfBoundsException, "Source does not fit in dest"_s);
	}
	if (srcSize < Collections::COPY_THRESHOLD || ($instanceOf($RandomAccess, src) && $instanceOf($RandomAccess, dest))) {
		for (int32_t i = 0; i < srcSize; ++i) {
			$nc(dest)->set(i, $(src->get(i)));
		}
	} else {
		$var($ListIterator, di, $nc(dest)->listIterator());
		$var($ListIterator, si, src->listIterator());
		for (int32_t i = 0; i < srcSize; ++i) {
			$nc(di)->next();
			di->set($($nc(si)->next()));
		}
	}
}

$Object* Collections::min($Collection* coll) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	$var($Iterator, i, $nc(coll)->iterator());
	$var($Object, candidate, $nc(i)->next());
	while (i->hasNext()) {
		$var($Object, next, i->next());
		if ($nc(($cast($Comparable, next)))->compareTo(candidate) < 0) {
			$assign(candidate, next);
		}
	}
	return $of(candidate);
}

$Object* Collections::min($Collection* coll, $Comparator* comp) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	if (comp == nullptr) {
		return $of(min(coll));
	}
	$var($Iterator, i, $nc(coll)->iterator());
	$var($Object, candidate, $nc(i)->next());
	while (i->hasNext()) {
		$var($Object, next, i->next());
		if ($nc(comp)->compare(next, candidate) < 0) {
			$assign(candidate, next);
		}
	}
	return $of(candidate);
}

$Object* Collections::max($Collection* coll) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	$var($Iterator, i, $nc(coll)->iterator());
	$var($Object, candidate, $nc(i)->next());
	while (i->hasNext()) {
		$var($Object, next, i->next());
		if ($nc(($cast($Comparable, next)))->compareTo(candidate) > 0) {
			$assign(candidate, next);
		}
	}
	return $of(candidate);
}

$Object* Collections::max($Collection* coll, $Comparator* comp) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	if (comp == nullptr) {
		return $of(max(coll));
	}
	$var($Iterator, i, $nc(coll)->iterator());
	$var($Object, candidate, $nc(i)->next());
	while (i->hasNext()) {
		$var($Object, next, i->next());
		if ($nc(comp)->compare(next, candidate) > 0) {
			$assign(candidate, next);
		}
	}
	return $of(candidate);
}

void Collections::rotate($List* list, int32_t distance) {
	$init(Collections);
	if ($instanceOf($RandomAccess, list) || $nc(list)->size() < Collections::ROTATE_THRESHOLD) {
		rotate1(list, distance);
	} else {
		rotate2(list, distance);
	}
}

void Collections::rotate1($List* list, int32_t distance) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	int32_t size = $nc(list)->size();
	if (size == 0) {
		return;
	}
	distance = $mod(distance, size);
	if (distance < 0) {
		distance += size;
	}
	if (distance == 0) {
		return;
	}
	{
		int32_t cycleStart = 0;
		int32_t nMoved = 0;
		for (; nMoved != size; ++cycleStart) {
			$var($Object, displaced, list->get(cycleStart));
			int32_t i = cycleStart;
			do {
				i += distance;
				if (i >= size) {
					i -= size;
				}
				$assign(displaced, list->set(i, displaced));
				++nMoved;
			} while (i != cycleStart);
		}
	}
}

void Collections::rotate2($List* list, int32_t distance) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	int32_t size = $nc(list)->size();
	if (size == 0) {
		return;
	}
	int32_t mid = $mod(-distance, size);
	if (mid < 0) {
		mid += size;
	}
	if (mid == 0) {
		return;
	}
	reverse($(list->subList(0, mid)));
	reverse($(list->subList(mid, size)));
	reverse(list);
}

bool Collections::replaceAll($List* list, Object$* oldVal, Object$* newVal) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	bool result = false;
	int32_t size = $nc(list)->size();
	if (size < Collections::REPLACEALL_THRESHOLD || $instanceOf($RandomAccess, list)) {
		if (oldVal == nullptr) {
			for (int32_t i = 0; i < size; ++i) {
				if (list->get(i) == nullptr) {
					list->set(i, newVal);
					result = true;
				}
			}
		} else {
			for (int32_t i = 0; i < size; ++i) {
				if ($nc($of(oldVal))->equals($(list->get(i)))) {
					list->set(i, newVal);
					result = true;
				}
			}
		}
	} else {
		$var($ListIterator, itr, list->listIterator());
		if (oldVal == nullptr) {
			for (int32_t i = 0; i < size; ++i) {
				if ($nc(itr)->next() == nullptr) {
					itr->set(newVal);
					result = true;
				}
			}
		} else {
			for (int32_t i = 0; i < size; ++i) {
				if ($nc($of(oldVal))->equals($($nc(itr)->next()))) {
					$nc(itr)->set(newVal);
					result = true;
				}
			}
		}
	}
	return result;
}

int32_t Collections::indexOfSubList($List* source, $List* target) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	int32_t sourceSize = $nc(source)->size();
	int32_t targetSize = $nc(target)->size();
	int32_t maxCandidate = sourceSize - targetSize;
	if (sourceSize < Collections::INDEXOFSUBLIST_THRESHOLD || ($instanceOf($RandomAccess, source) && $instanceOf($RandomAccess, target))) {
		bool nextCand$continue = false;
		for (int32_t candidate = 0; candidate <= maxCandidate; ++candidate) {
			{
				int32_t i = 0;
				int32_t j = candidate;
				for (; i < targetSize; ++i, ++j) {
					$var($Object, var$0, target->get(i));
					if (!eq(var$0, $(source->get(j)))) {
						nextCand$continue = true;
						break;
					}
				}
				if (nextCand$continue) {
					nextCand$continue = false;
					continue;
				}
			}
			return candidate;
		}
	} else {
		$var($ListIterator, si, source->listIterator());
		bool nextCand$continue = false;
		for (int32_t candidate = 0; candidate <= maxCandidate; ++candidate) {
			$var($ListIterator, ti, target->listIterator());
			for (int32_t i = 0; i < targetSize; ++i) {
				$var($Object, var$1, $nc(ti)->next());
				if (!eq(var$1, $($nc(si)->next()))) {
					for (int32_t j = 0; j < i; ++j) {
						$nc(si)->previous();
					}
					nextCand$continue = true;
					break;
				}
			}
			if (nextCand$continue) {
				nextCand$continue = false;
				continue;
			}
			return candidate;
		}
	}
	return -1;
}

int32_t Collections::lastIndexOfSubList($List* source, $List* target) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	int32_t sourceSize = $nc(source)->size();
	int32_t targetSize = $nc(target)->size();
	int32_t maxCandidate = sourceSize - targetSize;
	if (sourceSize < Collections::INDEXOFSUBLIST_THRESHOLD || $instanceOf($RandomAccess, source)) {
		bool nextCand$continue = false;
		for (int32_t candidate = maxCandidate; candidate >= 0; --candidate) {
			{
				int32_t i = 0;
				int32_t j = candidate;
				for (; i < targetSize; ++i, ++j) {
					$var($Object, var$0, target->get(i));
					if (!eq(var$0, $(source->get(j)))) {
						nextCand$continue = true;
						break;
					}
				}
				if (nextCand$continue) {
					nextCand$continue = false;
					continue;
				}
			}
			return candidate;
		}
	} else {
		if (maxCandidate < 0) {
			return -1;
		}
		$var($ListIterator, si, source->listIterator(maxCandidate));
		bool nextCand$continue = false;
		for (int32_t candidate = maxCandidate; candidate >= 0; --candidate) {
			$var($ListIterator, ti, target->listIterator());
			for (int32_t i = 0; i < targetSize; ++i) {
				$var($Object, var$1, $nc(ti)->next());
				if (!eq(var$1, $($nc(si)->next()))) {
					if (candidate != 0) {
						for (int32_t j = 0; j <= i + 1; ++j) {
							$nc(si)->previous();
						}
					}
					nextCand$continue = true;
					break;
				}
			}
			if (nextCand$continue) {
				nextCand$continue = false;
				continue;
			}
			return candidate;
		}
	}
	return -1;
}

$Collection* Collections::unmodifiableCollection($Collection* c) {
	$init(Collections);
	$load($Collections$UnmodifiableCollection);
	if ($nc($of(c))->getClass() == $Collections$UnmodifiableCollection::class$) {
		return c;
	}
	return $new($Collections$UnmodifiableCollection, c);
}

$Set* Collections::unmodifiableSet($Set* s) {
	$init(Collections);
	$load($Collections$UnmodifiableSet);
	if ($nc($of(s))->getClass() == $Collections$UnmodifiableSet::class$) {
		return s;
	}
	return $new($Collections$UnmodifiableSet, s);
}

$SortedSet* Collections::unmodifiableSortedSet($SortedSet* s) {
	$init(Collections);
	$load($Collections$UnmodifiableSortedSet);
	if ($nc($of(s))->getClass() == $Collections$UnmodifiableSortedSet::class$) {
		return s;
	}
	return $new($Collections$UnmodifiableSortedSet, s);
}

$NavigableSet* Collections::unmodifiableNavigableSet($NavigableSet* s) {
	$init(Collections);
	$load($Collections$UnmodifiableNavigableSet);
	if ($nc($of(s))->getClass() == $Collections$UnmodifiableNavigableSet::class$) {
		return s;
	}
	return $new($Collections$UnmodifiableNavigableSet, s);
}

$List* Collections::unmodifiableList($List* list) {
	$init(Collections);
	$load($Collections$UnmodifiableList);
	bool var$0 = $nc($of(list))->getClass() == $Collections$UnmodifiableList::class$;
	$load($Collections$UnmodifiableRandomAccessList);
	if (var$0 || $nc($of(list))->getClass() == $Collections$UnmodifiableRandomAccessList::class$) {
		return list;
	}
	return ($instanceOf($RandomAccess, list) ? static_cast<$List*>($new($Collections$UnmodifiableRandomAccessList, list)) : static_cast<$List*>($new($Collections$UnmodifiableList, list)));
}

$Map* Collections::unmodifiableMap($Map* m) {
	$init(Collections);
	$load($Collections$UnmodifiableMap);
	if ($nc($of(m))->getClass() == $Collections$UnmodifiableMap::class$) {
		return m;
	}
	return $new($Collections$UnmodifiableMap, m);
}

$SortedMap* Collections::unmodifiableSortedMap($SortedMap* m) {
	$init(Collections);
	$load($Collections$UnmodifiableSortedMap);
	if ($nc($of(m))->getClass() == $Collections$UnmodifiableSortedMap::class$) {
		return m;
	}
	return $new($Collections$UnmodifiableSortedMap, m);
}

$NavigableMap* Collections::unmodifiableNavigableMap($NavigableMap* m) {
	$init(Collections);
	$load($Collections$UnmodifiableNavigableMap);
	if ($nc($of(m))->getClass() == $Collections$UnmodifiableNavigableMap::class$) {
		return m;
	}
	return $new($Collections$UnmodifiableNavigableMap, m);
}

$Collection* Collections::synchronizedCollection($Collection* c) {
	$init(Collections);
	return $new($Collections$SynchronizedCollection, c);
}

$Collection* Collections::synchronizedCollection($Collection* c, Object$* mutex) {
	$init(Collections);
	return $new($Collections$SynchronizedCollection, c, mutex);
}

$Set* Collections::synchronizedSet($Set* s) {
	$init(Collections);
	return $new($Collections$SynchronizedSet, s);
}

$Set* Collections::synchronizedSet($Set* s, Object$* mutex) {
	$init(Collections);
	return $new($Collections$SynchronizedSet, s, mutex);
}

$SortedSet* Collections::synchronizedSortedSet($SortedSet* s) {
	$init(Collections);
	return $new($Collections$SynchronizedSortedSet, s);
}

$NavigableSet* Collections::synchronizedNavigableSet($NavigableSet* s) {
	$init(Collections);
	return $new($Collections$SynchronizedNavigableSet, s);
}

$List* Collections::synchronizedList($List* list) {
	$init(Collections);
	return ($instanceOf($RandomAccess, list) ? static_cast<$List*>($new($Collections$SynchronizedRandomAccessList, list)) : static_cast<$List*>($new($Collections$SynchronizedList, list)));
}

$List* Collections::synchronizedList($List* list, Object$* mutex) {
	$init(Collections);
	return ($instanceOf($RandomAccess, list) ? static_cast<$List*>($new($Collections$SynchronizedRandomAccessList, list, mutex)) : static_cast<$List*>($new($Collections$SynchronizedList, list, mutex)));
}

$Map* Collections::synchronizedMap($Map* m) {
	$init(Collections);
	return $new($Collections$SynchronizedMap, m);
}

$SortedMap* Collections::synchronizedSortedMap($SortedMap* m) {
	$init(Collections);
	return $new($Collections$SynchronizedSortedMap, m);
}

$NavigableMap* Collections::synchronizedNavigableMap($NavigableMap* m) {
	$init(Collections);
	return $new($Collections$SynchronizedNavigableMap, m);
}

$Collection* Collections::checkedCollection($Collection* c, $Class* type) {
	$init(Collections);
	return $new($Collections$CheckedCollection, c, type);
}

$ObjectArray* Collections::zeroLengthArray($Class* type) {
	$init(Collections);
	return $cast($ObjectArray, $1Array::newInstance(type, 0));
}

$Queue* Collections::checkedQueue($Queue* queue, $Class* type) {
	$init(Collections);
	return $new($Collections$CheckedQueue, queue, type);
}

$Set* Collections::checkedSet($Set* s, $Class* type) {
	$init(Collections);
	return $new($Collections$CheckedSet, s, type);
}

$SortedSet* Collections::checkedSortedSet($SortedSet* s, $Class* type) {
	$init(Collections);
	return $new($Collections$CheckedSortedSet, s, type);
}

$NavigableSet* Collections::checkedNavigableSet($NavigableSet* s, $Class* type) {
	$init(Collections);
	return $new($Collections$CheckedNavigableSet, s, type);
}

$List* Collections::checkedList($List* list, $Class* type) {
	$init(Collections);
	return ($instanceOf($RandomAccess, list) ? static_cast<$List*>($new($Collections$CheckedRandomAccessList, list, type)) : static_cast<$List*>($new($Collections$CheckedList, list, type)));
}

$Map* Collections::checkedMap($Map* m, $Class* keyType, $Class* valueType) {
	$init(Collections);
	return $new($Collections$CheckedMap, m, keyType, valueType);
}

$SortedMap* Collections::checkedSortedMap($SortedMap* m, $Class* keyType, $Class* valueType) {
	$init(Collections);
	return $new($Collections$CheckedSortedMap, m, keyType, valueType);
}

$NavigableMap* Collections::checkedNavigableMap($NavigableMap* m, $Class* keyType, $Class* valueType) {
	$init(Collections);
	return $new($Collections$CheckedNavigableMap, m, keyType, valueType);
}

$Iterator* Collections::emptyIterator() {
	$init(Collections);
	$init($Collections$EmptyIterator);
	return static_cast<$Iterator*>($Collections$EmptyIterator::EMPTY_ITERATOR);
}

$ListIterator* Collections::emptyListIterator() {
	$init(Collections);
	$init($Collections$EmptyListIterator);
	return static_cast<$ListIterator*>($Collections$EmptyListIterator::EMPTY_ITERATOR);
}

$Enumeration* Collections::emptyEnumeration() {
	$init(Collections);
	$init($Collections$EmptyEnumeration);
	return static_cast<$Enumeration*>($Collections$EmptyEnumeration::EMPTY_ENUMERATION);
}

$Set* Collections::emptySet() {
	$init(Collections);
	return Collections::EMPTY_SET;
}

$SortedSet* Collections::emptySortedSet() {
	$init(Collections);
	$init($Collections$UnmodifiableNavigableSet);
	return static_cast<$SortedSet*>($Collections$UnmodifiableNavigableSet::EMPTY_NAVIGABLE_SET);
}

$NavigableSet* Collections::emptyNavigableSet() {
	$init(Collections);
	$init($Collections$UnmodifiableNavigableSet);
	return $Collections$UnmodifiableNavigableSet::EMPTY_NAVIGABLE_SET;
}

$List* Collections::emptyList() {
	$init(Collections);
	return Collections::EMPTY_LIST;
}

$Map* Collections::emptyMap() {
	$init(Collections);
	return Collections::EMPTY_MAP;
}

$SortedMap* Collections::emptySortedMap() {
	$init(Collections);
	$init($Collections$UnmodifiableNavigableMap);
	return static_cast<$SortedMap*>(static_cast<$Collections$UnmodifiableSortedMap*>(static_cast<$Collections$UnmodifiableNavigableMap*>($Collections$UnmodifiableNavigableMap::EMPTY_NAVIGABLE_MAP)));
}

$NavigableMap* Collections::emptyNavigableMap() {
	$init(Collections);
	$init($Collections$UnmodifiableNavigableMap);
	return static_cast<$NavigableMap*>($Collections$UnmodifiableNavigableMap::EMPTY_NAVIGABLE_MAP);
}

$Set* Collections::singleton(Object$* o) {
	$init(Collections);
	return $new($Collections$SingletonSet, o);
}

$Iterator* Collections::singletonIterator(Object$* e) {
	$init(Collections);
	return $new($Collections$1, e);
}

$Spliterator* Collections::singletonSpliterator(Object$* element) {
	$init(Collections);
	return $new($Collections$2, element);
}

$List* Collections::singletonList(Object$* o) {
	$init(Collections);
	return $new($Collections$SingletonList, o);
}

$Map* Collections::singletonMap(Object$* key, Object$* value) {
	$init(Collections);
	return $new($Collections$SingletonMap, key, value);
}

$List* Collections::nCopies(int32_t n, Object$* o) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	if (n < 0) {
		$throwNew($IllegalArgumentException, $$str({"List length = "_s, $$str(n)}));
	}
	return $new($Collections$CopiesList, n, o);
}

$Comparator* Collections::reverseOrder() {
	$init(Collections);
	$init($Collections$ReverseComparator);
	return static_cast<$Comparator*>($Collections$ReverseComparator::REVERSE_ORDER);
}

$Comparator* Collections::reverseOrder($Comparator* cmp) {
	$init(Collections);
	if (cmp == nullptr) {
		$init($Collections$ReverseComparator);
		return static_cast<$Comparator*>($Collections$ReverseComparator::REVERSE_ORDER);
	} else {
		$init($Collections$ReverseComparator);
		if ($equals(cmp, $Collections$ReverseComparator::REVERSE_ORDER)) {
			$init($Comparators$NaturalOrderComparator);
			return static_cast<$Comparator*>($Comparators$NaturalOrderComparator::INSTANCE);
		} else {
			$init($Comparators$NaturalOrderComparator);
			if ($equals(cmp, $Comparators$NaturalOrderComparator::INSTANCE)) {
				return static_cast<$Comparator*>($Collections$ReverseComparator::REVERSE_ORDER);
			} else if ($instanceOf($Collections$ReverseComparator2, cmp)) {
				return $nc(($cast($Collections$ReverseComparator2, cmp)))->cmp;
			} else {
				return $new($Collections$ReverseComparator2, cmp);
			}
		}
	}
}

$Enumeration* Collections::enumeration($Collection* c) {
	$init(Collections);
	return $new($Collections$3, c);
}

$ArrayList* Collections::list($Enumeration* e) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, l, $new($ArrayList));
	while ($nc(e)->hasMoreElements()) {
		l->add($(e->nextElement()));
	}
	return l;
}

bool Collections::eq(Object$* o1, Object$* o2) {
	$init(Collections);
	return o1 == nullptr ? o2 == nullptr : $nc($of(o1))->equals(o2);
}

int32_t Collections::frequency($Collection* c, Object$* o) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	int32_t result = 0;
	if (o == nullptr) {
		{
			$var($Iterator, i$, $nc(c)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Object, e, i$->next());
				if (e == nullptr) {
					++result;
				}
			}
		}
	} else {
		{
			$var($Iterator, i$, $nc(c)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Object, e, i$->next());
				if ($nc($of(o))->equals(e)) {
					++result;
				}
			}
		}
	}
	return result;
}

bool Collections::disjoint($Collection* c1, $Collection* c2) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	$var($Collection, contains, c2);
	$var($Collection, iterate, c1);
	if ($instanceOf($Set, c1)) {
		$assign(iterate, c2);
		$assign(contains, c1);
	} else if (!($instanceOf($Set, c2))) {
		int32_t c1size = $nc(c1)->size();
		int32_t c2size = $nc(c2)->size();
		if (c1size == 0 || c2size == 0) {
			return true;
		}
		if (c1size > c2size) {
			$assign(iterate, c2);
			$assign(contains, c1);
		}
	}
	{
		$var($Iterator, i$, $nc(iterate)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, e, i$->next());
			{
				if ($nc(contains)->contains(e)) {
					return false;
				}
			}
		}
	}
	return true;
}

bool Collections::addAll($Collection* c, $ObjectArray* elements) {
	$init(Collections);
	$useLocalCurrentObjectStackCache();
	bool result = false;
	{
		$var($ObjectArray, arr$, elements);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, element, arr$->get(i$));
			result |= $nc(c)->add(element);
		}
	}
	return result;
}

$Set* Collections::newSetFromMap($Map* map) {
	$init(Collections);
	return $new($Collections$SetFromMap, map);
}

$Queue* Collections::asLifoQueue($Deque* deque) {
	$init(Collections);
	return $new($Collections$AsLIFOQueue, $cast($Deque, $Objects::requireNonNull(deque)));
}

void clinit$Collections($Class* class$) {
	$assignStatic(Collections::EMPTY_SET, $new($Collections$EmptySet));
	$assignStatic(Collections::EMPTY_LIST, $new($Collections$EmptyList));
	$assignStatic(Collections::EMPTY_MAP, $new($Collections$EmptyMap));
}

Collections::Collections() {
}

$Class* Collections::load$($String* name, bool initialize) {
	$loadClass(Collections, name, initialize, &_Collections_ClassInfo_, clinit$Collections, allocate$Collections);
	return class$;
}

$Class* Collections::class$ = nullptr;

	} // util
} // java