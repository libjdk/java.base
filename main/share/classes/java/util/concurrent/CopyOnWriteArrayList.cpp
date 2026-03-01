#include <java/util/concurrent/CopyOnWriteArrayList.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/lang/reflect/Field.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Comparator.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/ListIterator.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/concurrent/CopyOnWriteArrayList$COWIterator.h>
#include <java/util/concurrent/CopyOnWriteArrayList$COWSubList.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/UnaryOperator.h>
#include <jdk/internal/access/JavaObjectInputStreamAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef IMMUTABLE
#undef ORDERED

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $Field = ::java::lang::reflect::Field;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Comparator = ::java::util::Comparator;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $ListIterator = ::java::util::ListIterator;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;
using $Spliterators = ::java::util::Spliterators;
using $CopyOnWriteArrayList$COWIterator = ::java::util::concurrent::CopyOnWriteArrayList$COWIterator;
using $CopyOnWriteArrayList$COWSubList = ::java::util::concurrent::CopyOnWriteArrayList$COWSubList;
using $Consumer = ::java::util::function::Consumer;
using $Predicate = ::java::util::function::Predicate;
using $UnaryOperator = ::java::util::function::UnaryOperator;
using $JavaObjectInputStreamAccess = ::jdk::internal::access::JavaObjectInputStreamAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace util {
		namespace concurrent {

class CopyOnWriteArrayList$$Lambda$lambda$removeAll$0 : public $Predicate {
	$class(CopyOnWriteArrayList$$Lambda$lambda$removeAll$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Collection* c) {
		$set(this, c, c);
	}
	virtual bool test(Object$* e) override {
		 return CopyOnWriteArrayList::lambda$removeAll$0(c, e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CopyOnWriteArrayList$$Lambda$lambda$removeAll$0>());
	}
	$Collection* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CopyOnWriteArrayList$$Lambda$lambda$removeAll$0::fieldInfos[2] = {
	{"c", "Ljava/util/Collection;", nullptr, $PUBLIC, $field(CopyOnWriteArrayList$$Lambda$lambda$removeAll$0, c)},
	{}
};
$MethodInfo CopyOnWriteArrayList$$Lambda$lambda$removeAll$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(CopyOnWriteArrayList$$Lambda$lambda$removeAll$0, init$, void, $Collection*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList$$Lambda$lambda$removeAll$0, test, bool, Object$*)},
	{}
};
$ClassInfo CopyOnWriteArrayList$$Lambda$lambda$removeAll$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.concurrent.CopyOnWriteArrayList$$Lambda$lambda$removeAll$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* CopyOnWriteArrayList$$Lambda$lambda$removeAll$0::load$($String* name, bool initialize) {
	$loadClass(CopyOnWriteArrayList$$Lambda$lambda$removeAll$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CopyOnWriteArrayList$$Lambda$lambda$removeAll$0::class$ = nullptr;

class CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1 : public $Predicate {
	$class(CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Collection* c) {
		$set(this, c, c);
	}
	virtual bool test(Object$* e) override {
		 return CopyOnWriteArrayList::lambda$retainAll$1(c, e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1>());
	}
	$Collection* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1::fieldInfos[2] = {
	{"c", "Ljava/util/Collection;", nullptr, $PUBLIC, $field(CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1, c)},
	{}
};
$MethodInfo CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1, init$, void, $Collection*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1, test, bool, Object$*)},
	{}
};
$ClassInfo CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.concurrent.CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1::load$($String* name, bool initialize) {
	$loadClass(CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1::class$ = nullptr;

class CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2 : public $PrivilegedAction {
	$class(CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(CopyOnWriteArrayList::lambda$resetLock$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2, run, $Object*)},
	{}
};
$ClassInfo CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.concurrent.CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2::load$($String* name, bool initialize) {
	$loadClass(CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2::class$ = nullptr;

$FieldInfo _CopyOnWriteArrayList_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CopyOnWriteArrayList, serialVersionUID)},
	{"lock", "Ljava/lang/Object;", nullptr, $FINAL | $TRANSIENT, $field(CopyOnWriteArrayList, lock)},
	{"array", "[Ljava/lang/Object;", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(CopyOnWriteArrayList, array)},
	{}
};

$MethodInfo _CopyOnWriteArrayList_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "()V", nullptr, $PUBLIC, $method(CopyOnWriteArrayList, init$, void)},
	{"<init>", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PUBLIC, $method(CopyOnWriteArrayList, init$, void, $Collection*)},
	{"<init>", "([Ljava/lang/Object;)V", "([TE;)V", $PUBLIC, $method(CopyOnWriteArrayList, init$, void, $ObjectArray*)},
	{"add", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, add, bool, Object$*)},
	{"add", "(ILjava/lang/Object;)V", "(ITE;)V", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, add, void, int32_t, Object$*)},
	{"addAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<+TE;>;)Z", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, addAll, bool, $Collection*)},
	{"addAll", "(ILjava/util/Collection;)Z", "(ILjava/util/Collection<+TE;>;)Z", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, addAll, bool, int32_t, $Collection*)},
	{"addAllAbsent", "(Ljava/util/Collection;)I", "(Ljava/util/Collection<+TE;>;)I", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, addAllAbsent, int32_t, $Collection*)},
	{"addIfAbsent", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, addIfAbsent, bool, Object$*)},
	{"addIfAbsent", "(Ljava/lang/Object;[Ljava/lang/Object;)Z", "(TE;[Ljava/lang/Object;)Z", $PRIVATE, $method(CopyOnWriteArrayList, addIfAbsent, bool, Object$*, $ObjectArray*)},
	{"bulkRemove", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PRIVATE, $method(CopyOnWriteArrayList, bulkRemove, bool, $Predicate*)},
	{"bulkRemove", "(Ljava/util/function/Predicate;II)Z", "(Ljava/util/function/Predicate<-TE;>;II)Z", 0, $virtualMethod(CopyOnWriteArrayList, bulkRemove, bool, $Predicate*, int32_t, int32_t)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList, clone, $Object*)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList, contains, bool, Object$*)},
	{"containsAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, containsAll, bool, $Collection*)},
	{"elementAt", "([Ljava/lang/Object;I)Ljava/lang/Object;", "<E:Ljava/lang/Object;>([Ljava/lang/Object;I)TE;", $STATIC, $staticMethod(CopyOnWriteArrayList, elementAt, $Object*, $ObjectArray*, int32_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList, equals, bool, Object$*)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TE;>;)V", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, forEach, void, $Consumer*)},
	{"get", "(I)Ljava/lang/Object;", "(I)TE;", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, get, $Object*, int32_t)},
	{"getArray", "()[Ljava/lang/Object;", nullptr, $FINAL, $method(CopyOnWriteArrayList, getArray, $ObjectArray*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList, hashCode, int32_t)},
	{"hashCodeOfRange", "([Ljava/lang/Object;II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CopyOnWriteArrayList, hashCodeOfRange, int32_t, $ObjectArray*, int32_t, int32_t)},
	{"indexOf", "(Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList, indexOf, int32_t, Object$*)},
	{"indexOf", "(Ljava/lang/Object;I)I", "(TE;I)I", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, indexOf, int32_t, Object$*, int32_t)},
	{"indexOfRange", "(Ljava/lang/Object;[Ljava/lang/Object;II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CopyOnWriteArrayList, indexOfRange, int32_t, Object$*, $ObjectArray*, int32_t, int32_t)},
	{"isClear", "([JI)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(CopyOnWriteArrayList, isClear, bool, $longs*, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList, isEmpty, bool)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, iterator, $Iterator*)},
	{"lambda$removeAll$0", "(Ljava/util/Collection;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CopyOnWriteArrayList, lambda$removeAll$0, bool, $Collection*, Object$*)},
	{"lambda$resetLock$2", "()Ljava/lang/reflect/Field;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CopyOnWriteArrayList, lambda$resetLock$2, $Field*)},
	{"lambda$retainAll$1", "(Ljava/util/Collection;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CopyOnWriteArrayList, lambda$retainAll$1, bool, $Collection*, Object$*)},
	{"lastIndexOf", "(Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList, lastIndexOf, int32_t, Object$*)},
	{"lastIndexOf", "(Ljava/lang/Object;I)I", "(TE;I)I", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, lastIndexOf, int32_t, Object$*, int32_t)},
	{"lastIndexOfRange", "(Ljava/lang/Object;[Ljava/lang/Object;II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CopyOnWriteArrayList, lastIndexOfRange, int32_t, Object$*, $ObjectArray*, int32_t, int32_t)},
	{"listIterator", "()Ljava/util/ListIterator;", "()Ljava/util/ListIterator<TE;>;", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, listIterator, $ListIterator*)},
	{"listIterator", "(I)Ljava/util/ListIterator;", "(I)Ljava/util/ListIterator<TE;>;", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, listIterator, $ListIterator*, int32_t)},
	{"nBits", "(I)[J", nullptr, $PRIVATE | $STATIC, $staticMethod(CopyOnWriteArrayList, nBits, $longs*, int32_t)},
	{"outOfBounds", "(II)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(CopyOnWriteArrayList, outOfBounds, $String*, int32_t, int32_t)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(CopyOnWriteArrayList, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(I)Ljava/lang/Object;", "(I)TE;", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, remove, $Object*, int32_t)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList, remove, bool, Object$*)},
	{"remove", "(Ljava/lang/Object;[Ljava/lang/Object;I)Z", nullptr, $PRIVATE, $method(CopyOnWriteArrayList, remove, bool, Object$*, $ObjectArray*, int32_t)},
	{"removeAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, removeAll, bool, $Collection*)},
	{"removeIf", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, removeIf, bool, $Predicate*)},
	{"removeRange", "(II)V", nullptr, 0, $virtualMethod(CopyOnWriteArrayList, removeRange, void, int32_t, int32_t)},
	{"replaceAll", "(Ljava/util/function/UnaryOperator;)V", "(Ljava/util/function/UnaryOperator<TE;>;)V", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, replaceAll, void, $UnaryOperator*)},
	{"replaceAllRange", "(Ljava/util/function/UnaryOperator;II)V", "(Ljava/util/function/UnaryOperator<TE;>;II)V", 0, $virtualMethod(CopyOnWriteArrayList, replaceAllRange, void, $UnaryOperator*, int32_t, int32_t)},
	{"resetLock", "()V", nullptr, $PRIVATE, $method(CopyOnWriteArrayList, resetLock, void)},
	{"retainAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, retainAll, bool, $Collection*)},
	{"set", "(ILjava/lang/Object;)Ljava/lang/Object;", "(ITE;)TE;", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, set, $Object*, int32_t, Object$*)},
	{"setArray", "([Ljava/lang/Object;)V", nullptr, $FINAL, $method(CopyOnWriteArrayList, setArray, void, $ObjectArray*)},
	{"setBit", "([JI)V", nullptr, $PRIVATE | $STATIC, $staticMethod(CopyOnWriteArrayList, setBit, void, $longs*, int32_t)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList, size, int32_t)},
	{"sort", "(Ljava/util/Comparator;)V", "(Ljava/util/Comparator<-TE;>;)V", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, sort, void, $Comparator*)},
	{"sortRange", "(Ljava/util/Comparator;II)V", "(Ljava/util/Comparator<-TE;>;II)V", 0, $virtualMethod(CopyOnWriteArrayList, sortRange, void, $Comparator*, int32_t, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, spliterator, $Spliterator*)},
	{"subList", "(II)Ljava/util/List;", "(II)Ljava/util/List<TE;>;", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, subList, $List*, int32_t, int32_t)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(CopyOnWriteArrayList, toArray, $ObjectArray*, $ObjectArray*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CopyOnWriteArrayList, toString, $String*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(CopyOnWriteArrayList, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _CopyOnWriteArrayList_InnerClassesInfo_[] = {
	{"java.util.concurrent.CopyOnWriteArrayList$COWSubListIterator", "java.util.concurrent.CopyOnWriteArrayList", "COWSubListIterator", $PRIVATE | $STATIC},
	{"java.util.concurrent.CopyOnWriteArrayList$COWSubList", "java.util.concurrent.CopyOnWriteArrayList", "COWSubList", $PRIVATE},
	{"java.util.concurrent.CopyOnWriteArrayList$COWIterator", "java.util.concurrent.CopyOnWriteArrayList", "COWIterator", $STATIC | $FINAL},
	{}
};

$ClassInfo _CopyOnWriteArrayList_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.CopyOnWriteArrayList",
	"java.lang.Object",
	"java.util.List,java.util.RandomAccess,java.lang.Cloneable,java.io.Serializable",
	_CopyOnWriteArrayList_FieldInfo_,
	_CopyOnWriteArrayList_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/List<TE;>;Ljava/util/RandomAccess;Ljava/lang/Cloneable;Ljava/io/Serializable;",
	nullptr,
	_CopyOnWriteArrayList_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.CopyOnWriteArrayList$COWSubListIterator,java.util.concurrent.CopyOnWriteArrayList$COWSubList,java.util.concurrent.CopyOnWriteArrayList$COWIterator"
};

$Object* allocate$CopyOnWriteArrayList($Class* clazz) {
	return $of($alloc(CopyOnWriteArrayList));
}

void CopyOnWriteArrayList::finalize() {
	this->$List::finalize();
}

$ObjectArray* CopyOnWriteArrayList::getArray() {
	return this->array;
}

void CopyOnWriteArrayList::setArray($ObjectArray* a) {
	$set(this, array, a);
}

void CopyOnWriteArrayList::init$() {
	$set(this, lock, $new($Object));
	setArray($$new($ObjectArray, 0));
}

void CopyOnWriteArrayList::init$($Collection* c) {
	$set(this, lock, $new($Object));
	$var($ObjectArray, es, nullptr);
	if ($nc($of(c))->getClass() == CopyOnWriteArrayList::class$) {
		$assign(es, $nc(($cast(CopyOnWriteArrayList, c)))->getArray());
	} else {
		$assign(es, c->toArray());
		$load($ArrayList);
		if ($of(c)->getClass() != $ArrayList::class$) {
			$load($ObjectArray);
			$assign(es, $Arrays::copyOf(es, $nc(es)->length, $getClass($ObjectArray)));
		}
	}
	setArray(es);
}

void CopyOnWriteArrayList::init$($ObjectArray* toCopyIn) {
	$set(this, lock, $new($Object));
	$load($ObjectArray);
	setArray($($Arrays::copyOf(toCopyIn, $nc(toCopyIn)->length, $getClass($ObjectArray))));
}

int32_t CopyOnWriteArrayList::size() {
	return $nc($(getArray()))->length;
}

bool CopyOnWriteArrayList::isEmpty() {
	return size() == 0;
}

int32_t CopyOnWriteArrayList::indexOfRange(Object$* o, $ObjectArray* es, int32_t from, int32_t to) {
	$init(CopyOnWriteArrayList);
	if (o == nullptr) {
		for (int32_t i = from; i < to; ++i) {
			if ($nc(es)->get(i) == nullptr) {
				return i;
			}
		}
	} else {
		for (int32_t i = from; i < to; ++i) {
			if ($nc($of(o))->equals($nc(es)->get(i))) {
				return i;
			}
		}
	}
	return -1;
}

int32_t CopyOnWriteArrayList::lastIndexOfRange(Object$* o, $ObjectArray* es, int32_t from, int32_t to) {
	$init(CopyOnWriteArrayList);
	if (o == nullptr) {
		for (int32_t i = to - 1; i >= from; --i) {
			if ($nc(es)->get(i) == nullptr) {
				return i;
			}
		}
	} else {
		for (int32_t i = to - 1; i >= from; --i) {
			if ($nc($of(o))->equals($nc(es)->get(i))) {
				return i;
			}
		}
	}
	return -1;
}

bool CopyOnWriteArrayList::contains(Object$* o) {
	return indexOf(o) >= 0;
}

int32_t CopyOnWriteArrayList::indexOf(Object$* o) {
	$var($ObjectArray, es, getArray());
	return indexOfRange(o, es, 0, $nc(es)->length);
}

int32_t CopyOnWriteArrayList::indexOf(Object$* e, int32_t index) {
	$var($ObjectArray, es, getArray());
	return indexOfRange(e, es, index, $nc(es)->length);
}

int32_t CopyOnWriteArrayList::lastIndexOf(Object$* o) {
	$var($ObjectArray, es, getArray());
	return lastIndexOfRange(o, es, 0, $nc(es)->length);
}

int32_t CopyOnWriteArrayList::lastIndexOf(Object$* e, int32_t index) {
	$var($ObjectArray, es, getArray());
	return lastIndexOfRange(e, es, 0, index + 1);
}

$Object* CopyOnWriteArrayList::clone() {
	try {
		$var(CopyOnWriteArrayList, clone, $cast(CopyOnWriteArrayList, $List::clone()));
		$nc(clone)->resetLock();
		$VarHandle::releaseFence();
		return $of(clone);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

$ObjectArray* CopyOnWriteArrayList::toArray() {
	return $cast($ObjectArray, $nc($(getArray()))->clone());
}

$ObjectArray* CopyOnWriteArrayList::toArray($ObjectArray* a) {
	$var($ObjectArray, es, getArray());
	int32_t len = $nc(es)->length;
	if ($nc(a)->length < len) {
		return $Arrays::copyOf(es, len, $of(a)->getClass());
	} else {
		$System::arraycopy(es, 0, a, 0, len);
		if (a->length > len) {
			a->set(len, nullptr);
		}
		return a;
	}
}

$Object* CopyOnWriteArrayList::elementAt($ObjectArray* a, int32_t index) {
	$init(CopyOnWriteArrayList);
	return $of($nc(a)->get(index));
}

$String* CopyOnWriteArrayList::outOfBounds(int32_t index, int32_t size) {
	$init(CopyOnWriteArrayList);
	$useLocalCurrentObjectStackCache();
	return $str({"Index: "_s, $$str(index), ", Size: "_s, $$str(size)});
}

$Object* CopyOnWriteArrayList::get(int32_t index) {
	return $of(elementAt($(getArray()), index));
}

$Object* CopyOnWriteArrayList::set(int32_t index, Object$* element) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->lock) {
		$var($ObjectArray, es, getArray());
		$var($Object, oldValue, elementAt(es, index));
		if (!$equals(oldValue, element)) {
			$assign(es, $cast($ObjectArray, $nc(es)->clone()));
			es->set(index, element);
		}
		setArray(es);
		return $of(oldValue);
	}
}

bool CopyOnWriteArrayList::add(Object$* e) {
	$synchronized(this->lock) {
		$var($ObjectArray, es, getArray());
		int32_t len = $nc(es)->length;
		$assign(es, $Arrays::copyOf(es, len + 1));
		es->set(len, e);
		setArray(es);
		return true;
	}
}

void CopyOnWriteArrayList::add(int32_t index, Object$* element) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->lock) {
		$var($ObjectArray, es, getArray());
		int32_t len = $nc(es)->length;
		if (index > len || index < 0) {
			$throwNew($IndexOutOfBoundsException, $(outOfBounds(index, len)));
		}
		$var($ObjectArray, newElements, nullptr);
		int32_t numMoved = len - index;
		if (numMoved == 0) {
			$assign(newElements, $Arrays::copyOf(es, len + 1));
		} else {
			$assign(newElements, $new($ObjectArray, len + 1));
			$System::arraycopy(es, 0, newElements, 0, index);
			$System::arraycopy(es, index, newElements, index + 1, numMoved);
		}
		$nc(newElements)->set(index, element);
		setArray(newElements);
	}
}

$Object* CopyOnWriteArrayList::remove(int32_t index) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->lock) {
		$var($ObjectArray, es, getArray());
		int32_t len = $nc(es)->length;
		$var($Object, oldValue, elementAt(es, index));
		int32_t numMoved = len - index - 1;
		$var($ObjectArray, newElements, nullptr);
		if (numMoved == 0) {
			$assign(newElements, $Arrays::copyOf(es, len - 1));
		} else {
			$assign(newElements, $new($ObjectArray, len - 1));
			$System::arraycopy(es, 0, newElements, 0, index);
			$System::arraycopy(es, index + 1, newElements, index, numMoved);
		}
		setArray(newElements);
		return $of(oldValue);
	}
}

bool CopyOnWriteArrayList::remove(Object$* o) {
	$var($ObjectArray, snapshot, getArray());
	int32_t index = indexOfRange(o, snapshot, 0, $nc(snapshot)->length);
	return index >= 0 && remove(o, snapshot, index);
}

bool CopyOnWriteArrayList::remove(Object$* o, $ObjectArray* snapshot, int32_t index) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->lock) {
		$var($ObjectArray, current, getArray());
		int32_t len = $nc(current)->length;
		if (snapshot != current) {
			bool findIndex$break = false;
			for (;;) {
				{
					int32_t prefix = $Math::min(index, len);
					for (int32_t i = 0; i < prefix; ++i) {
						if (!$equals(current->get(i), $nc(snapshot)->get(i)) && $Objects::equals(o, current->get(i))) {
							index = i;
							findIndex$break = true;
							break;
						}
					}
					if (findIndex$break) {
						break;
					}
					if (index >= len) {
						return false;
					}
					if ($equals(current->get(index), o)) {
						findIndex$break = true;
						break;
					}
					index = indexOfRange(o, current, index, len);
					if (index < 0) {
						return false;
					}
				}
				break;
			}
		}
		$var($ObjectArray, newElements, $new($ObjectArray, len - 1));
		$System::arraycopy(current, 0, newElements, 0, index);
		$System::arraycopy(current, index + 1, newElements, index, len - index - 1);
		setArray(newElements);
		return true;
	}
}

void CopyOnWriteArrayList::removeRange(int32_t fromIndex, int32_t toIndex) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->lock) {
		$var($ObjectArray, es, getArray());
		int32_t len = $nc(es)->length;
		if (fromIndex < 0 || toIndex > len || toIndex < fromIndex) {
			$throwNew($IndexOutOfBoundsException);
		}
		int32_t newlen = len - (toIndex - fromIndex);
		int32_t numMoved = len - toIndex;
		if (numMoved == 0) {
			setArray($($Arrays::copyOf(es, newlen)));
		} else {
			$var($ObjectArray, newElements, $new($ObjectArray, newlen));
			$System::arraycopy(es, 0, newElements, 0, fromIndex);
			$System::arraycopy(es, toIndex, newElements, fromIndex, numMoved);
			setArray(newElements);
		}
	}
}

bool CopyOnWriteArrayList::addIfAbsent(Object$* e) {
	$var($ObjectArray, snapshot, getArray());
	bool var$0 = indexOfRange(e, snapshot, 0, $nc(snapshot)->length) < 0;
	return var$0 && addIfAbsent(e, snapshot);
}

bool CopyOnWriteArrayList::addIfAbsent(Object$* e, $ObjectArray* snapshot) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->lock) {
		$var($ObjectArray, current, getArray());
		int32_t len = $nc(current)->length;
		if (snapshot != current) {
			int32_t common = $Math::min($nc(snapshot)->length, len);
			for (int32_t i = 0; i < common; ++i) {
				if (!$equals(current->get(i), $nc(snapshot)->get(i)) && $Objects::equals(e, current->get(i))) {
					return false;
				}
			}
			if (indexOfRange(e, current, common, len) >= 0) {
				return false;
			}
		}
		$var($ObjectArray, newElements, $Arrays::copyOf(current, len + 1));
		newElements->set(len, e);
		setArray(newElements);
		return true;
	}
}

bool CopyOnWriteArrayList::containsAll($Collection* c) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, es, getArray());
	int32_t len = $nc(es)->length;
	{
		$var($Iterator, i$, $nc(c)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, e, i$->next());
			{
				if (indexOfRange(e, es, 0, len) < 0) {
					return false;
				}
			}
		}
	}
	return true;
}

bool CopyOnWriteArrayList::removeAll($Collection* c) {
	$Objects::requireNonNull(c);
	return bulkRemove(static_cast<$Predicate*>($$new(CopyOnWriteArrayList$$Lambda$lambda$removeAll$0, c)));
}

bool CopyOnWriteArrayList::retainAll($Collection* c) {
	$Objects::requireNonNull(c);
	return bulkRemove(static_cast<$Predicate*>($$new(CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1, c)));
}

int32_t CopyOnWriteArrayList::addAllAbsent($Collection* c) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, cs, $nc(c)->toArray());
	$load($ArrayList);
	if ($of(c)->getClass() != $ArrayList::class$) {
		$assign(cs, $cast($ObjectArray, $nc(cs)->clone()));
	}
	if ($nc(cs)->length == 0) {
		return 0;
	}
	$synchronized(this->lock) {
		$var($ObjectArray, es, getArray());
		int32_t len = $nc(es)->length;
		int32_t added = 0;
		for (int32_t i = 0; i < $nc(cs)->length; ++i) {
			$var($Object0, e, cs->get(i));
			bool var$0 = indexOfRange(e, es, 0, len) < 0;
			if (var$0 && indexOfRange(e, cs, 0, added) < 0) {
				cs->set(added++, e);
			}
		}
		if (added > 0) {
			$var($ObjectArray, newElements, $Arrays::copyOf(es, len + added));
			$System::arraycopy(cs, 0, newElements, len, added);
			setArray(newElements);
		}
		return added;
	}
}

void CopyOnWriteArrayList::clear() {
	$synchronized(this->lock) {
		setArray($$new($ObjectArray, 0));
	}
}

bool CopyOnWriteArrayList::addAll($Collection* c) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, cs, ($nc($of(c))->getClass() == CopyOnWriteArrayList::class$) ? $nc(($cast(CopyOnWriteArrayList, c)))->getArray() : $nc(c)->toArray());
	if ($nc(cs)->length == 0) {
		return false;
	}
	$synchronized(this->lock) {
		$var($ObjectArray, es, getArray());
		int32_t len = $nc(es)->length;
		$var($ObjectArray, newElements, nullptr);
		bool var$0 = len == 0;
		if (var$0) {
			bool var$1 = $of(c)->getClass() == CopyOnWriteArrayList::class$;
			$load($ArrayList);
			var$0 = (var$1 || $of(c)->getClass() == $ArrayList::class$);
		}
		if (var$0) {
			$assign(newElements, cs);
		} else {
			$assign(newElements, $Arrays::copyOf(es, len + $nc(cs)->length));
			$System::arraycopy(cs, 0, newElements, len, $nc(cs)->length);
		}
		setArray(newElements);
		return true;
	}
}

bool CopyOnWriteArrayList::addAll(int32_t index, $Collection* c) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, cs, $nc(c)->toArray());
	$synchronized(this->lock) {
		$var($ObjectArray, es, getArray());
		int32_t len = $nc(es)->length;
		if (index > len || index < 0) {
			$throwNew($IndexOutOfBoundsException, $(outOfBounds(index, len)));
		}
		if ($nc(cs)->length == 0) {
			return false;
		}
		int32_t numMoved = len - index;
		$var($ObjectArray, newElements, nullptr);
		if (numMoved == 0) {
			$assign(newElements, $Arrays::copyOf(es, len + $nc(cs)->length));
		} else {
			$assign(newElements, $new($ObjectArray, len + $nc(cs)->length));
			$System::arraycopy(es, 0, newElements, 0, index);
			$System::arraycopy(es, index, newElements, index + cs->length, numMoved);
		}
		$System::arraycopy(cs, 0, newElements, index, $nc(cs)->length);
		setArray(newElements);
		return true;
	}
}

void CopyOnWriteArrayList::forEach($Consumer* action) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(action);
	{
		$var($ObjectArray, arr$, getArray());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, x, arr$->get(i$));
			{
				$var($Object, e, x);
				action->accept(e);
			}
		}
	}
}

bool CopyOnWriteArrayList::removeIf($Predicate* filter) {
	$Objects::requireNonNull(filter);
	return bulkRemove(filter);
}

$longs* CopyOnWriteArrayList::nBits(int32_t n) {
	$init(CopyOnWriteArrayList);
	return $new($longs, ((n - 1) >> 6) + 1);
}

void CopyOnWriteArrayList::setBit($longs* bits, int32_t i) {
	$init(CopyOnWriteArrayList);
	(*$nc(bits))[i >> 6] |= $sl((int64_t)1, i);
}

bool CopyOnWriteArrayList::isClear($longs* bits, int32_t i) {
	$init(CopyOnWriteArrayList);
	return ((int64_t)($nc(bits)->get(i >> 6) & (uint64_t)($sl((int64_t)1, i)))) == 0;
}

bool CopyOnWriteArrayList::bulkRemove($Predicate* filter) {
	$synchronized(this->lock) {
		return bulkRemove(filter, 0, $nc($(getArray()))->length);
	}
}

bool CopyOnWriteArrayList::bulkRemove($Predicate* filter, int32_t i, int32_t end) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, es, getArray());
	for (; i < end && !$nc(filter)->test($(elementAt(es, i))); ++i) {
	}
	if (i < end) {
		int32_t beg = i;
		$var($longs, deathRow, nBits(end - beg));
		int32_t deleted = 1;
		$nc(deathRow)->set(0, 1);
		for (i = beg + 1; i < end; ++i) {
			if ($nc(filter)->test($(elementAt(es, i)))) {
				setBit(deathRow, i - beg);
				++deleted;
			}
		}
		if (es != getArray()) {
			$throwNew($ConcurrentModificationException);
		}
		$var($ObjectArray, newElts, $Arrays::copyOf(es, $nc(es)->length - deleted));
		int32_t w = beg;
		for (i = beg; i < end; ++i) {
			if (isClear(deathRow, i - beg)) {
				newElts->set(w++, $nc(es)->get(i));
			}
		}
		$System::arraycopy(es, i, newElts, w, $nc(es)->length - i);
		setArray(newElts);
		return true;
	} else {
		if (es != getArray()) {
			$throwNew($ConcurrentModificationException);
		}
		return false;
	}
}

void CopyOnWriteArrayList::replaceAll($UnaryOperator* operator$) {
	$synchronized(this->lock) {
		replaceAllRange(operator$, 0, $nc($(getArray()))->length);
	}
}

void CopyOnWriteArrayList::replaceAllRange($UnaryOperator* operator$, int32_t i, int32_t end) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(operator$);
	$var($ObjectArray, es, $cast($ObjectArray, $nc($(getArray()))->clone()));
	for (; i < end; ++i) {
		es->set(i, $(operator$->apply($(elementAt(es, i)))));
	}
	setArray(es);
}

void CopyOnWriteArrayList::sort($Comparator* c) {
	$synchronized(this->lock) {
		sortRange(c, 0, $nc($(getArray()))->length);
	}
}

void CopyOnWriteArrayList::sortRange($Comparator* c, int32_t i, int32_t end) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, es, $cast($ObjectArray, $nc($(getArray()))->clone()));
	$Arrays::sort(es, i, end, c);
	setArray(es);
}

void CopyOnWriteArrayList::writeObject($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultWriteObject();
	$var($ObjectArray, es, getArray());
	s->writeInt($nc(es)->length);
	{
		$var($ObjectArray, arr$, es);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, element, arr$->get(i$));
			s->writeObject(element);
		}
	}
}

void CopyOnWriteArrayList::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	resetLock();
	int32_t len = s->readInt();
	$load($ObjectArray);
	$nc($($SharedSecrets::getJavaObjectInputStreamAccess()))->checkArray(s, $getClass($ObjectArray), len);
	$var($ObjectArray, es, $new($ObjectArray, len));
	for (int32_t i = 0; i < len; ++i) {
		es->set(i, $(s->readObject()));
	}
	setArray(es);
}

$String* CopyOnWriteArrayList::toString() {
	return $Arrays::toString($(getArray()));
}

bool CopyOnWriteArrayList::equals(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if ($equals(o, this)) {
		return true;
	}
	if (!($instanceOf($List, o))) {
		return false;
	}
	$var($List, list, $cast($List, o));
	$var($Iterator, it, $nc(list)->iterator());
	{
		$var($ObjectArray, arr$, getArray());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, element, arr$->get(i$));
			bool var$0 = !$nc(it)->hasNext();
			if (var$0 || !$Objects::equals(element, $($nc(it)->next()))) {
				return false;
			}
		}
	}
	return !$nc(it)->hasNext();
}

int32_t CopyOnWriteArrayList::hashCodeOfRange($ObjectArray* es, int32_t from, int32_t to) {
	$init(CopyOnWriteArrayList);
	$useLocalCurrentObjectStackCache();
	int32_t hashCode = 1;
	for (int32_t i = from; i < to; ++i) {
		$var($Object0, x, $nc(es)->get(i));
		hashCode = 31 * hashCode + (x == nullptr ? 0 : $nc($of(x))->hashCode());
	}
	return hashCode;
}

int32_t CopyOnWriteArrayList::hashCode() {
	$var($ObjectArray, es, getArray());
	return hashCodeOfRange(es, 0, $nc(es)->length);
}

$Iterator* CopyOnWriteArrayList::iterator() {
	return $new($CopyOnWriteArrayList$COWIterator, $(getArray()), 0);
}

$ListIterator* CopyOnWriteArrayList::listIterator() {
	return $new($CopyOnWriteArrayList$COWIterator, $(getArray()), 0);
}

$ListIterator* CopyOnWriteArrayList::listIterator(int32_t index) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, es, getArray());
	int32_t len = $nc(es)->length;
	if (index < 0 || index > len) {
		$throwNew($IndexOutOfBoundsException, $(outOfBounds(index, len)));
	}
	return $new($CopyOnWriteArrayList$COWIterator, es, index);
}

$Spliterator* CopyOnWriteArrayList::spliterator() {
	return $Spliterators::spliterator($(getArray()), $Spliterator::IMMUTABLE | $Spliterator::ORDERED);
}

$List* CopyOnWriteArrayList::subList(int32_t fromIndex, int32_t toIndex) {
	$synchronized(this->lock) {
		$var($ObjectArray, es, getArray());
		int32_t len = $nc(es)->length;
		int32_t size = toIndex - fromIndex;
		if (fromIndex < 0 || toIndex > len || size < 0) {
			$throwNew($IndexOutOfBoundsException);
		}
		return $new($CopyOnWriteArrayList$COWSubList, this, es, fromIndex, size);
	}
}

void CopyOnWriteArrayList::resetLock() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Field, lockField, $cast($Field, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2)))));
	try {
		$nc(lockField)->set(this, $$new($Object));
	} catch ($IllegalAccessException& e) {
		$throwNew($Error, static_cast<$Throwable*>(e));
	}
}

$Field* CopyOnWriteArrayList::lambda$resetLock$2() {
	$init(CopyOnWriteArrayList);
	$beforeCallerSensitive();
	try {
		$var($Field, f, CopyOnWriteArrayList::class$->getDeclaredField("lock"_s));
		$nc(f)->setAccessible(true);
		return f;
	} catch ($ReflectiveOperationException& e) {
		$throwNew($Error, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

bool CopyOnWriteArrayList::lambda$retainAll$1($Collection* c, Object$* e) {
	$init(CopyOnWriteArrayList);
	return !$nc(c)->contains(e);
}

bool CopyOnWriteArrayList::lambda$removeAll$0($Collection* c, Object$* e) {
	$init(CopyOnWriteArrayList);
	return $nc(c)->contains(e);
}

CopyOnWriteArrayList::CopyOnWriteArrayList() {
}

$Class* CopyOnWriteArrayList::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(CopyOnWriteArrayList$$Lambda$lambda$removeAll$0::classInfo$.name)) {
			return CopyOnWriteArrayList$$Lambda$lambda$removeAll$0::load$(name, initialize);
		}
		if (name->equals(CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1::classInfo$.name)) {
			return CopyOnWriteArrayList$$Lambda$lambda$retainAll$1$1::load$(name, initialize);
		}
		if (name->equals(CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2::classInfo$.name)) {
			return CopyOnWriteArrayList$$Lambda$lambda$resetLock$2$2::load$(name, initialize);
		}
	}
	$loadClass(CopyOnWriteArrayList, name, initialize, &_CopyOnWriteArrayList_ClassInfo_, allocate$CopyOnWriteArrayList);
	return class$;
}

$Class* CopyOnWriteArrayList::class$ = nullptr;

		} // concurrent
	} // util
} // java