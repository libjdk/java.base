#include <java/util/stream/Collectors.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Enum.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/DoubleSummaryStatistics.h>
#include <java/util/EnumSet.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/IntSummaryStatistics.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/LongSummaryStatistics.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/StringJoiner.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/BinaryOperator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/Supplier.h>
#include <java/util/function/ToDoubleFunction.h>
#include <java/util/function/ToIntFunction.h>
#include <java/util/function/ToLongFunction.h>
#include <java/util/stream/BaseStream.h>
#include <java/util/stream/Collector$Characteristics.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors$1OptionalBox.h>
#include <java/util/stream/Collectors$1PairBox.h>
#include <java/util/stream/Collectors$CollectorImpl.h>
#include <java/util/stream/Collectors$Partition.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/access/JavaUtilCollectionAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef CH_CONCURRENT_ID
#undef CH_CONCURRENT_NOID
#undef CH_ID
#undef CH_NOID
#undef CH_UNORDERED_ID
#undef CH_UNORDERED_NOID
#undef CONCURRENT
#undef IDENTITY_FINISH
#undef UNORDERED

using $Map$EntryArray = $Array<::java::util::Map$Entry>;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $DoubleSummaryStatistics = ::java::util::DoubleSummaryStatistics;
using $EnumSet = ::java::util::EnumSet;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $IntSummaryStatistics = ::java::util::IntSummaryStatistics;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $LongSummaryStatistics = ::java::util::LongSummaryStatistics;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $StringJoiner = ::java::util::StringJoiner;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $BinaryOperator = ::java::util::function::BinaryOperator;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Supplier = ::java::util::function::Supplier;
using $ToDoubleFunction = ::java::util::function::ToDoubleFunction;
using $ToIntFunction = ::java::util::function::ToIntFunction;
using $ToLongFunction = ::java::util::function::ToLongFunction;
using $Collector = ::java::util::stream::Collector;
using $Collector$Characteristics = ::java::util::stream::Collector$Characteristics;
using $Collectors$1OptionalBox = ::java::util::stream::Collectors$1OptionalBox;
using $Collectors$1PairBox = ::java::util::stream::Collectors$1PairBox;
using $Collectors$CollectorImpl = ::java::util::stream::Collectors$CollectorImpl;
using $Collectors$Partition = ::java::util::stream::Collectors$Partition;
using $Stream = ::java::util::stream::Stream;
using $JavaUtilCollectionAccess = ::jdk::internal::access::JavaUtilCollectionAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace util {
		namespace stream {

class Collectors$$Lambda$lambda$uniqKeysMapMerger$0 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$uniqKeysMapMerger$0, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* m1, Object$* m2) override {
		 return $of(Collectors::lambda$uniqKeysMapMerger$0($cast($Map, m1), $cast($Map, m2)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$uniqKeysMapMerger$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$uniqKeysMapMerger$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$uniqKeysMapMerger$0, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$uniqKeysMapMerger$0, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$uniqKeysMapMerger$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$uniqKeysMapMerger$0",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$uniqKeysMapMerger$0::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$uniqKeysMapMerger$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$uniqKeysMapMerger$0::class$ = nullptr;

class Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($Function* keyMapper, $Function* valueMapper) {
		$set(this, keyMapper, keyMapper);
		$set(this, valueMapper, valueMapper);
	}
	virtual void accept(Object$* map, Object$* element) override {
		Collectors::lambda$uniqKeysMapAccumulator$1(keyMapper, valueMapper, $cast($Map, map), element);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1>());
	}
	$Function* keyMapper = nullptr;
	$Function* valueMapper = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1::fieldInfos[3] = {
	{"keyMapper", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1, keyMapper)},
	{"valueMapper", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1, valueMapper)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Function;Ljava/util/function/Function;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1, init$, void, $Function*, $Function*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1::class$ = nullptr;

class Collectors$$Lambda$lambda$castingIdentity$2$2 : public $Function {
	$class(Collectors$$Lambda$lambda$castingIdentity$2$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* i) override {
		 return Collectors::lambda$castingIdentity$2(i);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$castingIdentity$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$castingIdentity$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$castingIdentity$2$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$castingIdentity$2$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$castingIdentity$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$castingIdentity$2$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$castingIdentity$2$2::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$castingIdentity$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$castingIdentity$2$2::class$ = nullptr;

class Collectors$$Lambda$add$3 : public $BiConsumer {
	$class(Collectors$$Lambda$add$3, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, Object$* e) override {
		$sure($Collection, inst$)->add(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$add$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$add$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$add$3, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$add$3, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$add$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$add$3",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$add$3::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$add$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$add$3::class$ = nullptr;

class Collectors$$Lambda$lambda$toCollection$3$4 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$toCollection$3$4, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* r1, Object$* r2) override {
		 return $of(Collectors::lambda$toCollection$3($cast($Collection, r1), $cast($Collection, r2)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$toCollection$3$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$toCollection$3$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$toCollection$3$4, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$toCollection$3$4, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$toCollection$3$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$toCollection$3$4",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$toCollection$3$4::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$toCollection$3$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$toCollection$3$4::class$ = nullptr;

class Collectors$$Lambda$ArrayList$5 : public $Supplier {
	$class(Collectors$$Lambda$ArrayList$5, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($ArrayList));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$ArrayList$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$ArrayList$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$ArrayList$5, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$ArrayList$5, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$ArrayList$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$ArrayList$5",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$ArrayList$5::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$ArrayList$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$ArrayList$5::class$ = nullptr;

class Collectors$$Lambda$add$6 : public $BiConsumer {
	$class(Collectors$$Lambda$add$6, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, Object$* e) override {
		$sure($List, inst$)->add(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$add$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$add$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$add$6, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$add$6, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$add$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$add$6",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$add$6::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$add$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$add$6::class$ = nullptr;

class Collectors$$Lambda$lambda$toList$4$7 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$toList$4$7, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* left, Object$* right) override {
		 return $of(Collectors::lambda$toList$4($cast($ArrayList, left), $cast($ArrayList, right)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$toList$4$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$toList$4$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$toList$4$7, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$toList$4$7, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$toList$4$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$toList$4$7",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$toList$4$7::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$toList$4$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$toList$4$7::class$ = nullptr;

class Collectors$$Lambda$lambda$toUnmodifiableList$6$8 : public $Function {
	$class(Collectors$$Lambda$lambda$toUnmodifiableList$6$8, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* list) override {
		 return $of(Collectors::lambda$toUnmodifiableList$6($cast($ArrayList, list)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$toUnmodifiableList$6$8>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$toUnmodifiableList$6$8::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$toUnmodifiableList$6$8, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$toUnmodifiableList$6$8, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$toUnmodifiableList$6$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$toUnmodifiableList$6$8",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$toUnmodifiableList$6$8::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$toUnmodifiableList$6$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$toUnmodifiableList$6$8::class$ = nullptr;

class Collectors$$Lambda$HashSet$9 : public $Supplier {
	$class(Collectors$$Lambda$HashSet$9, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($HashSet));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$HashSet$9>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$HashSet$9::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$HashSet$9, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$HashSet$9, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$HashSet$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$HashSet$9",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$HashSet$9::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$HashSet$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$HashSet$9::class$ = nullptr;

class Collectors$$Lambda$add$10 : public $BiConsumer {
	$class(Collectors$$Lambda$add$10, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, Object$* e) override {
		$sure($Set, inst$)->add(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$add$10>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$add$10::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$add$10, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$add$10, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$add$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$add$10",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$add$10::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$add$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$add$10::class$ = nullptr;

class Collectors$$Lambda$lambda$toSet$7$11 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$toSet$7$11, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* left, Object$* right) override {
		 return $of(Collectors::lambda$toSet$7($cast($HashSet, left), $cast($HashSet, right)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$toSet$7$11>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$toSet$7$11::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$toSet$7$11, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$toSet$7$11, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$toSet$7$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$toSet$7$11",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$toSet$7$11::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$toSet$7$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$toSet$7$11::class$ = nullptr;

class Collectors$$Lambda$lambda$toUnmodifiableSet$9$12 : public $Function {
	$class(Collectors$$Lambda$lambda$toUnmodifiableSet$9$12, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* set) override {
		 return $of(Collectors::lambda$toUnmodifiableSet$9($cast($HashSet, set)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$toUnmodifiableSet$9$12>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$toUnmodifiableSet$9$12::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$toUnmodifiableSet$9$12, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$toUnmodifiableSet$9$12, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$toUnmodifiableSet$9$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$toUnmodifiableSet$9$12",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$toUnmodifiableSet$9$12::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$toUnmodifiableSet$9$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$toUnmodifiableSet$9$12::class$ = nullptr;

class Collectors$$Lambda$StringBuilder$13 : public $Supplier {
	$class(Collectors$$Lambda$StringBuilder$13, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($StringBuilder));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$StringBuilder$13>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$StringBuilder$13::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$StringBuilder$13, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$StringBuilder$13, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$StringBuilder$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$StringBuilder$13",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$StringBuilder$13::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$StringBuilder$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$StringBuilder$13::class$ = nullptr;

class Collectors$$Lambda$append$14 : public $BiConsumer {
	$class(Collectors$$Lambda$append$14, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, Object$* s) override {
		$sure($StringBuilder, inst$)->append($cast($CharSequence, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$append$14>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$append$14::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$append$14, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$append$14, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$append$14::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$append$14",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$append$14::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$append$14, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$append$14::class$ = nullptr;

class Collectors$$Lambda$lambda$joining$10$15 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$joining$10$15, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* r1, Object$* r2) override {
		 return $of(Collectors::lambda$joining$10($cast($StringBuilder, r1), $cast($StringBuilder, r2)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$joining$10$15>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$joining$10$15::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$joining$10$15, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$joining$10$15, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$joining$10$15::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$joining$10$15",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$joining$10$15::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$joining$10$15, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$joining$10$15::class$ = nullptr;

class Collectors$$Lambda$toString$16 : public $Function {
	$class(Collectors$$Lambda$toString$16, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($StringBuilder, inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$toString$16>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$toString$16::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$toString$16, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$toString$16, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$toString$16::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$toString$16",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$toString$16::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$toString$16, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$toString$16::class$ = nullptr;

class Collectors$$Lambda$lambda$joining$11$17 : public $Supplier {
	$class(Collectors$$Lambda$lambda$joining$11$17, $NO_CLASS_INIT, $Supplier)
public:
	void init$($CharSequence* delimiter, $CharSequence* prefix, $CharSequence* suffix) {
		$set(this, delimiter, delimiter);
		$set(this, prefix, prefix);
		$set(this, suffix, suffix);
	}
	virtual $Object* get() override {
		 return $of(Collectors::lambda$joining$11(delimiter, prefix, suffix));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$joining$11$17>());
	}
	$CharSequence* delimiter = nullptr;
	$CharSequence* prefix = nullptr;
	$CharSequence* suffix = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$joining$11$17::fieldInfos[4] = {
	{"delimiter", "Ljava/lang/CharSequence;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$joining$11$17, delimiter)},
	{"prefix", "Ljava/lang/CharSequence;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$joining$11$17, prefix)},
	{"suffix", "Ljava/lang/CharSequence;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$joining$11$17, suffix)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$joining$11$17::methodInfos[3] = {
	{"<init>", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;Ljava/lang/CharSequence;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$joining$11$17, init$, void, $CharSequence*, $CharSequence*, $CharSequence*)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$joining$11$17, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$joining$11$17::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$joining$11$17",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$joining$11$17::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$joining$11$17, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$joining$11$17::class$ = nullptr;

class Collectors$$Lambda$add$18 : public $BiConsumer {
	$class(Collectors$$Lambda$add$18, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, Object$* newElement) override {
		$sure($StringJoiner, inst$)->add($cast($CharSequence, newElement));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$add$18>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$add$18::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$add$18, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$add$18, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$add$18::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$add$18",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$add$18::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$add$18, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$add$18::class$ = nullptr;

class Collectors$$Lambda$merge$19 : public $BinaryOperator {
	$class(Collectors$$Lambda$merge$19, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$, Object$* other) override {
		 return $of($sure($StringJoiner, inst$)->merge($cast($StringJoiner, other)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$merge$19>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$merge$19::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$merge$19, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$merge$19, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$merge$19::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$merge$19",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$merge$19::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$merge$19, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$merge$19::class$ = nullptr;

class Collectors$$Lambda$toString$20 : public $Function {
	$class(Collectors$$Lambda$toString$20, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($StringJoiner, inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$toString$20>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$toString$20::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$toString$20, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$toString$20, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$toString$20::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$toString$20",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$toString$20::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$toString$20, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$toString$20::class$ = nullptr;

class Collectors$$Lambda$lambda$mapMerger$12$21 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$mapMerger$12$21, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$($BinaryOperator* mergeFunction) {
		$set(this, mergeFunction, mergeFunction);
	}
	virtual $Object* apply(Object$* m1, Object$* m2) override {
		 return $of(Collectors::lambda$mapMerger$12(mergeFunction, $cast($Map, m1), $cast($Map, m2)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$mapMerger$12$21>());
	}
	$BinaryOperator* mergeFunction = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$mapMerger$12$21::fieldInfos[2] = {
	{"mergeFunction", "Ljava/util/function/BinaryOperator;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$mapMerger$12$21, mergeFunction)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$mapMerger$12$21::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BinaryOperator;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$mapMerger$12$21, init$, void, $BinaryOperator*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$mapMerger$12$21, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$mapMerger$12$21::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$mapMerger$12$21",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$mapMerger$12$21::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$mapMerger$12$21, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$mapMerger$12$21::class$ = nullptr;

class Collectors$$Lambda$lambda$mapping$13$22 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$mapping$13$22, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($BiConsumer* downstreamAccumulator, $Function* mapper) {
		$set(this, downstreamAccumulator, downstreamAccumulator);
		$set(this, mapper, mapper);
	}
	virtual void accept(Object$* r, Object$* t) override {
		Collectors::lambda$mapping$13(downstreamAccumulator, mapper, r, t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$mapping$13$22>());
	}
	$BiConsumer* downstreamAccumulator = nullptr;
	$Function* mapper = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$mapping$13$22::fieldInfos[3] = {
	{"downstreamAccumulator", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$mapping$13$22, downstreamAccumulator)},
	{"mapper", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$mapping$13$22, mapper)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$mapping$13$22::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BiConsumer;Ljava/util/function/Function;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$mapping$13$22, init$, void, $BiConsumer*, $Function*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$mapping$13$22, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$mapping$13$22::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$mapping$13$22",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$mapping$13$22::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$mapping$13$22, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$mapping$13$22::class$ = nullptr;

class Collectors$$Lambda$lambda$flatMapping$15$23 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$flatMapping$15$23, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($Function* mapper, $BiConsumer* downstreamAccumulator) {
		$set(this, mapper, mapper);
		$set(this, downstreamAccumulator, downstreamAccumulator);
	}
	virtual void accept(Object$* r, Object$* t) override {
		Collectors::lambda$flatMapping$15(mapper, downstreamAccumulator, r, t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$flatMapping$15$23>());
	}
	$Function* mapper = nullptr;
	$BiConsumer* downstreamAccumulator = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$flatMapping$15$23::fieldInfos[3] = {
	{"mapper", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$flatMapping$15$23, mapper)},
	{"downstreamAccumulator", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$flatMapping$15$23, downstreamAccumulator)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$flatMapping$15$23::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Function;Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$flatMapping$15$23, init$, void, $Function*, $BiConsumer*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$flatMapping$15$23, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$flatMapping$15$23::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$flatMapping$15$23",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$flatMapping$15$23::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$flatMapping$15$23, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$flatMapping$15$23::class$ = nullptr;

class Collectors$$Lambda$lambda$filtering$16$24 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$filtering$16$24, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($Predicate* predicate, $BiConsumer* downstreamAccumulator) {
		$set(this, predicate, predicate);
		$set(this, downstreamAccumulator, downstreamAccumulator);
	}
	virtual void accept(Object$* r, Object$* t) override {
		Collectors::lambda$filtering$16(predicate, downstreamAccumulator, r, t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$filtering$16$24>());
	}
	$Predicate* predicate = nullptr;
	$BiConsumer* downstreamAccumulator = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$filtering$16$24::fieldInfos[3] = {
	{"predicate", "Ljava/util/function/Predicate;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$filtering$16$24, predicate)},
	{"downstreamAccumulator", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$filtering$16$24, downstreamAccumulator)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$filtering$16$24::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Predicate;Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$filtering$16$24, init$, void, $Predicate*, $BiConsumer*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$filtering$16$24, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$filtering$16$24::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$filtering$16$24",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$filtering$16$24::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$filtering$16$24, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$filtering$16$24::class$ = nullptr;

class Collectors$$Lambda$lambda$counting$17$25 : public $ToLongFunction {
	$class(Collectors$$Lambda$lambda$counting$17$25, $NO_CLASS_INIT, $ToLongFunction)
public:
	void init$() {
	}
	virtual int64_t applyAsLong(Object$* e) override {
		 return Collectors::lambda$counting$17(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$counting$17$25>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$counting$17$25::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$counting$17$25, init$, void)},
	{"applyAsLong", "(Ljava/lang/Object;)J", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$counting$17$25, applyAsLong, int64_t, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$counting$17$25::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$counting$17$25",
	"java.lang.Object",
	"java.util.function.ToLongFunction",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$counting$17$25::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$counting$17$25, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$counting$17$25::class$ = nullptr;

class Collectors$$Lambda$lambda$summingInt$18$26 : public $Supplier {
	$class(Collectors$$Lambda$lambda$summingInt$18$26, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(Collectors::lambda$summingInt$18());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summingInt$18$26>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$summingInt$18$26::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summingInt$18$26, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summingInt$18$26, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summingInt$18$26::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summingInt$18$26",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summingInt$18$26::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summingInt$18$26, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summingInt$18$26::class$ = nullptr;

class Collectors$$Lambda$lambda$summingInt$19$27 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$summingInt$19$27, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($ToIntFunction* mapper) {
		$set(this, mapper, mapper);
	}
	virtual void accept(Object$* a, Object$* t) override {
		Collectors::lambda$summingInt$19(mapper, $cast($ints, a), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summingInt$19$27>());
	}
	$ToIntFunction* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$summingInt$19$27::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/ToIntFunction;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$summingInt$19$27, mapper)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$summingInt$19$27::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/ToIntFunction;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summingInt$19$27, init$, void, $ToIntFunction*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summingInt$19$27, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summingInt$19$27::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summingInt$19$27",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summingInt$19$27::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summingInt$19$27, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summingInt$19$27::class$ = nullptr;

class Collectors$$Lambda$lambda$summingInt$20$28 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$summingInt$20$28, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a, Object$* b) override {
		 return $of(Collectors::lambda$summingInt$20($cast($ints, a), $cast($ints, b)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summingInt$20$28>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$summingInt$20$28::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summingInt$20$28, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summingInt$20$28, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summingInt$20$28::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summingInt$20$28",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summingInt$20$28::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summingInt$20$28, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summingInt$20$28::class$ = nullptr;

class Collectors$$Lambda$lambda$summingInt$21$29 : public $Function {
	$class(Collectors$$Lambda$lambda$summingInt$21$29, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a) override {
		 return $of(Collectors::lambda$summingInt$21($cast($ints, a)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summingInt$21$29>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$summingInt$21$29::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summingInt$21$29, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summingInt$21$29, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summingInt$21$29::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summingInt$21$29",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summingInt$21$29::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summingInt$21$29, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summingInt$21$29::class$ = nullptr;

class Collectors$$Lambda$lambda$summingLong$22$30 : public $Supplier {
	$class(Collectors$$Lambda$lambda$summingLong$22$30, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(Collectors::lambda$summingLong$22());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summingLong$22$30>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$summingLong$22$30::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summingLong$22$30, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summingLong$22$30, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summingLong$22$30::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summingLong$22$30",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summingLong$22$30::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summingLong$22$30, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summingLong$22$30::class$ = nullptr;

class Collectors$$Lambda$lambda$summingLong$23$31 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$summingLong$23$31, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($ToLongFunction* mapper) {
		$set(this, mapper, mapper);
	}
	virtual void accept(Object$* a, Object$* t) override {
		Collectors::lambda$summingLong$23(mapper, $cast($longs, a), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summingLong$23$31>());
	}
	$ToLongFunction* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$summingLong$23$31::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/ToLongFunction;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$summingLong$23$31, mapper)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$summingLong$23$31::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/ToLongFunction;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summingLong$23$31, init$, void, $ToLongFunction*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summingLong$23$31, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summingLong$23$31::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summingLong$23$31",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summingLong$23$31::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summingLong$23$31, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summingLong$23$31::class$ = nullptr;

class Collectors$$Lambda$lambda$summingLong$24$32 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$summingLong$24$32, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a, Object$* b) override {
		 return $of(Collectors::lambda$summingLong$24($cast($longs, a), $cast($longs, b)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summingLong$24$32>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$summingLong$24$32::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summingLong$24$32, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summingLong$24$32, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summingLong$24$32::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summingLong$24$32",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summingLong$24$32::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summingLong$24$32, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summingLong$24$32::class$ = nullptr;

class Collectors$$Lambda$lambda$summingLong$25$33 : public $Function {
	$class(Collectors$$Lambda$lambda$summingLong$25$33, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a) override {
		 return $of(Collectors::lambda$summingLong$25($cast($longs, a)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summingLong$25$33>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$summingLong$25$33::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summingLong$25$33, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summingLong$25$33, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summingLong$25$33::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summingLong$25$33",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summingLong$25$33::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summingLong$25$33, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summingLong$25$33::class$ = nullptr;

class Collectors$$Lambda$lambda$summingDouble$26$34 : public $Supplier {
	$class(Collectors$$Lambda$lambda$summingDouble$26$34, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(Collectors::lambda$summingDouble$26());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summingDouble$26$34>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$summingDouble$26$34::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summingDouble$26$34, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summingDouble$26$34, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summingDouble$26$34::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summingDouble$26$34",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summingDouble$26$34::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summingDouble$26$34, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summingDouble$26$34::class$ = nullptr;

class Collectors$$Lambda$lambda$summingDouble$27$35 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$summingDouble$27$35, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($ToDoubleFunction* mapper) {
		$set(this, mapper, mapper);
	}
	virtual void accept(Object$* a, Object$* t) override {
		Collectors::lambda$summingDouble$27(mapper, $cast($doubles, a), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summingDouble$27$35>());
	}
	$ToDoubleFunction* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$summingDouble$27$35::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/ToDoubleFunction;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$summingDouble$27$35, mapper)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$summingDouble$27$35::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/ToDoubleFunction;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summingDouble$27$35, init$, void, $ToDoubleFunction*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summingDouble$27$35, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summingDouble$27$35::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summingDouble$27$35",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summingDouble$27$35::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summingDouble$27$35, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summingDouble$27$35::class$ = nullptr;

class Collectors$$Lambda$lambda$summingDouble$28$36 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$summingDouble$28$36, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a, Object$* b) override {
		 return $of(Collectors::lambda$summingDouble$28($cast($doubles, a), $cast($doubles, b)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summingDouble$28$36>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$summingDouble$28$36::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summingDouble$28$36, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summingDouble$28$36, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summingDouble$28$36::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summingDouble$28$36",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summingDouble$28$36::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summingDouble$28$36, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summingDouble$28$36::class$ = nullptr;

class Collectors$$Lambda$lambda$summingDouble$29$37 : public $Function {
	$class(Collectors$$Lambda$lambda$summingDouble$29$37, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a) override {
		 return $of(Collectors::lambda$summingDouble$29($cast($doubles, a)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summingDouble$29$37>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$summingDouble$29$37::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summingDouble$29$37, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summingDouble$29$37, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summingDouble$29$37::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summingDouble$29$37",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summingDouble$29$37::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summingDouble$29$37, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summingDouble$29$37::class$ = nullptr;

class Collectors$$Lambda$lambda$averagingInt$30$38 : public $Supplier {
	$class(Collectors$$Lambda$lambda$averagingInt$30$38, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(Collectors::lambda$averagingInt$30());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$averagingInt$30$38>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$averagingInt$30$38::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$averagingInt$30$38, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$averagingInt$30$38, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$averagingInt$30$38::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$averagingInt$30$38",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$averagingInt$30$38::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$averagingInt$30$38, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$averagingInt$30$38::class$ = nullptr;

class Collectors$$Lambda$lambda$averagingInt$31$39 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$averagingInt$31$39, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($ToIntFunction* mapper) {
		$set(this, mapper, mapper);
	}
	virtual void accept(Object$* a, Object$* t) override {
		Collectors::lambda$averagingInt$31(mapper, $cast($longs, a), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$averagingInt$31$39>());
	}
	$ToIntFunction* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$averagingInt$31$39::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/ToIntFunction;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$averagingInt$31$39, mapper)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$averagingInt$31$39::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/ToIntFunction;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$averagingInt$31$39, init$, void, $ToIntFunction*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$averagingInt$31$39, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$averagingInt$31$39::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$averagingInt$31$39",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$averagingInt$31$39::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$averagingInt$31$39, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$averagingInt$31$39::class$ = nullptr;

class Collectors$$Lambda$lambda$averagingInt$32$40 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$averagingInt$32$40, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a, Object$* b) override {
		 return $of(Collectors::lambda$averagingInt$32($cast($longs, a), $cast($longs, b)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$averagingInt$32$40>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$averagingInt$32$40::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$averagingInt$32$40, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$averagingInt$32$40, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$averagingInt$32$40::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$averagingInt$32$40",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$averagingInt$32$40::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$averagingInt$32$40, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$averagingInt$32$40::class$ = nullptr;

class Collectors$$Lambda$lambda$averagingInt$33$41 : public $Function {
	$class(Collectors$$Lambda$lambda$averagingInt$33$41, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a) override {
		 return $of(Collectors::lambda$averagingInt$33($cast($longs, a)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$averagingInt$33$41>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$averagingInt$33$41::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$averagingInt$33$41, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$averagingInt$33$41, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$averagingInt$33$41::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$averagingInt$33$41",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$averagingInt$33$41::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$averagingInt$33$41, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$averagingInt$33$41::class$ = nullptr;

class Collectors$$Lambda$lambda$averagingLong$35$42 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$averagingLong$35$42, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($ToLongFunction* mapper) {
		$set(this, mapper, mapper);
	}
	virtual void accept(Object$* a, Object$* t) override {
		Collectors::lambda$averagingLong$35(mapper, $cast($longs, a), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$averagingLong$35$42>());
	}
	$ToLongFunction* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$averagingLong$35$42::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/ToLongFunction;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$averagingLong$35$42, mapper)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$averagingLong$35$42::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/ToLongFunction;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$averagingLong$35$42, init$, void, $ToLongFunction*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$averagingLong$35$42, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$averagingLong$35$42::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$averagingLong$35$42",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$averagingLong$35$42::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$averagingLong$35$42, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$averagingLong$35$42::class$ = nullptr;

class Collectors$$Lambda$lambda$averagingDouble$38$43 : public $Supplier {
	$class(Collectors$$Lambda$lambda$averagingDouble$38$43, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(Collectors::lambda$averagingDouble$38());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$averagingDouble$38$43>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$averagingDouble$38$43::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$averagingDouble$38$43, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$averagingDouble$38$43, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$averagingDouble$38$43::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$averagingDouble$38$43",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$averagingDouble$38$43::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$averagingDouble$38$43, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$averagingDouble$38$43::class$ = nullptr;

class Collectors$$Lambda$lambda$averagingDouble$39$44 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$averagingDouble$39$44, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($ToDoubleFunction* mapper) {
		$set(this, mapper, mapper);
	}
	virtual void accept(Object$* a, Object$* t) override {
		Collectors::lambda$averagingDouble$39(mapper, $cast($doubles, a), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$averagingDouble$39$44>());
	}
	$ToDoubleFunction* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$averagingDouble$39$44::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/ToDoubleFunction;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$averagingDouble$39$44, mapper)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$averagingDouble$39$44::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/ToDoubleFunction;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$averagingDouble$39$44, init$, void, $ToDoubleFunction*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$averagingDouble$39$44, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$averagingDouble$39$44::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$averagingDouble$39$44",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$averagingDouble$39$44::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$averagingDouble$39$44, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$averagingDouble$39$44::class$ = nullptr;

class Collectors$$Lambda$lambda$averagingDouble$40$45 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$averagingDouble$40$45, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a, Object$* b) override {
		 return $of(Collectors::lambda$averagingDouble$40($cast($doubles, a), $cast($doubles, b)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$averagingDouble$40$45>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$averagingDouble$40$45::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$averagingDouble$40$45, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$averagingDouble$40$45, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$averagingDouble$40$45::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$averagingDouble$40$45",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$averagingDouble$40$45::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$averagingDouble$40$45, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$averagingDouble$40$45::class$ = nullptr;

class Collectors$$Lambda$lambda$averagingDouble$41$46 : public $Function {
	$class(Collectors$$Lambda$lambda$averagingDouble$41$46, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a) override {
		 return $of(Collectors::lambda$averagingDouble$41($cast($doubles, a)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$averagingDouble$41$46>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$averagingDouble$41$46::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$averagingDouble$41$46, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$averagingDouble$41$46, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$averagingDouble$41$46::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$averagingDouble$41$46",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$averagingDouble$41$46::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$averagingDouble$41$46, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$averagingDouble$41$46::class$ = nullptr;

class Collectors$$Lambda$lambda$reducing$42$47 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$reducing$42$47, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($BinaryOperator* op) {
		$set(this, op, op);
	}
	virtual void accept(Object$* a, Object$* t) override {
		Collectors::lambda$reducing$42(op, $cast($ObjectArray, a), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$reducing$42$47>());
	}
	$BinaryOperator* op = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$reducing$42$47::fieldInfos[2] = {
	{"op", "Ljava/util/function/BinaryOperator;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$reducing$42$47, op)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$reducing$42$47::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BinaryOperator;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$reducing$42$47, init$, void, $BinaryOperator*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$reducing$42$47, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$reducing$42$47::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$reducing$42$47",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$reducing$42$47::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$reducing$42$47, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$reducing$42$47::class$ = nullptr;

class Collectors$$Lambda$lambda$reducing$43$48 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$reducing$43$48, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$($BinaryOperator* op) {
		$set(this, op, op);
	}
	virtual $Object* apply(Object$* a, Object$* b) override {
		 return $of(Collectors::lambda$reducing$43(op, $cast($ObjectArray, a), $cast($ObjectArray, b)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$reducing$43$48>());
	}
	$BinaryOperator* op = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$reducing$43$48::fieldInfos[2] = {
	{"op", "Ljava/util/function/BinaryOperator;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$reducing$43$48, op)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$reducing$43$48::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BinaryOperator;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$reducing$43$48, init$, void, $BinaryOperator*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$reducing$43$48, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$reducing$43$48::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$reducing$43$48",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$reducing$43$48::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$reducing$43$48, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$reducing$43$48::class$ = nullptr;

class Collectors$$Lambda$lambda$reducing$44$49 : public $Function {
	$class(Collectors$$Lambda$lambda$reducing$44$49, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a) override {
		 return Collectors::lambda$reducing$44($cast($ObjectArray, a));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$reducing$44$49>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$reducing$44$49::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$reducing$44$49, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$reducing$44$49, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$reducing$44$49::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$reducing$44$49",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$reducing$44$49::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$reducing$44$49, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$reducing$44$49::class$ = nullptr;

class Collectors$$Lambda$lambda$boxSupplier$45$50 : public $Supplier {
	$class(Collectors$$Lambda$lambda$boxSupplier$45$50, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Object$* identity) {
		$set(this, identity, identity);
	}
	virtual $Object* get() override {
		 return $of(Collectors::lambda$boxSupplier$45(identity));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$boxSupplier$45$50>());
	}
	$Object* identity = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$boxSupplier$45$50::fieldInfos[2] = {
	{"identity", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$boxSupplier$45$50, identity)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$boxSupplier$45$50::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$boxSupplier$45$50, init$, void, Object$*)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$boxSupplier$45$50, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$boxSupplier$45$50::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$boxSupplier$45$50",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$boxSupplier$45$50::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$boxSupplier$45$50, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$boxSupplier$45$50::class$ = nullptr;

class Collectors$$Lambda$lambda$reducing$46$51 : public $Supplier {
	$class(Collectors$$Lambda$lambda$reducing$46$51, $NO_CLASS_INIT, $Supplier)
public:
	void init$($BinaryOperator* op) {
		$set(this, op, op);
	}
	virtual $Object* get() override {
		 return $of(Collectors::lambda$reducing$46(op));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$reducing$46$51>());
	}
	$BinaryOperator* op = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$reducing$46$51::fieldInfos[2] = {
	{"op", "Ljava/util/function/BinaryOperator;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$reducing$46$51, op)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$reducing$46$51::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BinaryOperator;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$reducing$46$51, init$, void, $BinaryOperator*)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$reducing$46$51, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$reducing$46$51::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$reducing$46$51",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$reducing$46$51::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$reducing$46$51, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$reducing$46$51::class$ = nullptr;

class Collectors$$Lambda$accept$52 : public $BiConsumer {
	$class(Collectors$$Lambda$accept$52, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, Object$* t) override {
		$sure($Collectors$1OptionalBox, inst$)->accept(t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$accept$52>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$accept$52::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$accept$52, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$accept$52, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$accept$52::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$accept$52",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$accept$52::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$accept$52, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$accept$52::class$ = nullptr;

class Collectors$$Lambda$lambda$reducing$47$53 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$reducing$47$53, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a, Object$* b) override {
		 return $of(Collectors::lambda$reducing$47($cast($Collectors$1OptionalBox, a), $cast($Collectors$1OptionalBox, b)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$reducing$47$53>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$reducing$47$53::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$reducing$47$53, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$reducing$47$53, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$reducing$47$53::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$reducing$47$53",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$reducing$47$53::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$reducing$47$53, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$reducing$47$53::class$ = nullptr;

class Collectors$$Lambda$lambda$reducing$48$54 : public $Function {
	$class(Collectors$$Lambda$lambda$reducing$48$54, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a) override {
		 return $of(Collectors::lambda$reducing$48($cast($Collectors$1OptionalBox, a)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$reducing$48$54>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$reducing$48$54::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$reducing$48$54, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$reducing$48$54, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$reducing$48$54::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$reducing$48$54",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$reducing$48$54::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$reducing$48$54, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$reducing$48$54::class$ = nullptr;

class Collectors$$Lambda$lambda$reducing$49$55 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$reducing$49$55, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($BinaryOperator* op, $Function* mapper) {
		$set(this, op, op);
		$set(this, mapper, mapper);
	}
	virtual void accept(Object$* a, Object$* t) override {
		Collectors::lambda$reducing$49(op, mapper, $cast($ObjectArray, a), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$reducing$49$55>());
	}
	$BinaryOperator* op = nullptr;
	$Function* mapper = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$reducing$49$55::fieldInfos[3] = {
	{"op", "Ljava/util/function/BinaryOperator;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$reducing$49$55, op)},
	{"mapper", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$reducing$49$55, mapper)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$reducing$49$55::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BinaryOperator;Ljava/util/function/Function;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$reducing$49$55, init$, void, $BinaryOperator*, $Function*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$reducing$49$55, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$reducing$49$55::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$reducing$49$55",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$reducing$49$55::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$reducing$49$55, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$reducing$49$55::class$ = nullptr;

class Collectors$$Lambda$HashMap$56 : public $Supplier {
	$class(Collectors$$Lambda$HashMap$56, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($HashMap));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$HashMap$56>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$HashMap$56::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$HashMap$56, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$HashMap$56, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$HashMap$56::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$HashMap$56",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$HashMap$56::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$HashMap$56, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$HashMap$56::class$ = nullptr;

class Collectors$$Lambda$lambda$groupingBy$53$57 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$groupingBy$53$57, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($Function* classifier, $Supplier* downstreamSupplier, $BiConsumer* downstreamAccumulator) {
		$set(this, classifier, classifier);
		$set(this, downstreamSupplier, downstreamSupplier);
		$set(this, downstreamAccumulator, downstreamAccumulator);
	}
	virtual void accept(Object$* m, Object$* t) override {
		Collectors::lambda$groupingBy$53(classifier, downstreamSupplier, downstreamAccumulator, $cast($Map, m), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$groupingBy$53$57>());
	}
	$Function* classifier = nullptr;
	$Supplier* downstreamSupplier = nullptr;
	$BiConsumer* downstreamAccumulator = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$groupingBy$53$57::fieldInfos[4] = {
	{"classifier", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingBy$53$57, classifier)},
	{"downstreamSupplier", "Ljava/util/function/Supplier;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingBy$53$57, downstreamSupplier)},
	{"downstreamAccumulator", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingBy$53$57, downstreamAccumulator)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$groupingBy$53$57::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Function;Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$groupingBy$53$57, init$, void, $Function*, $Supplier*, $BiConsumer*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$groupingBy$53$57, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$groupingBy$53$57::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$groupingBy$53$57",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$groupingBy$53$57::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$groupingBy$53$57, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$groupingBy$53$57::class$ = nullptr;

class Collectors$$Lambda$lambda$groupingBy$55$58 : public $Function {
	$class(Collectors$$Lambda$lambda$groupingBy$55$58, $NO_CLASS_INIT, $Function)
public:
	void init$($Function* downstreamFinisher) {
		$set(this, downstreamFinisher, downstreamFinisher);
	}
	virtual $Object* apply(Object$* intermediate) override {
		 return $of(Collectors::lambda$groupingBy$55(downstreamFinisher, $cast($Map, intermediate)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$groupingBy$55$58>());
	}
	$Function* downstreamFinisher = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$groupingBy$55$58::fieldInfos[2] = {
	{"downstreamFinisher", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingBy$55$58, downstreamFinisher)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$groupingBy$55$58::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Function;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$groupingBy$55$58, init$, void, $Function*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$groupingBy$55$58, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$groupingBy$55$58::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$groupingBy$55$58",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$groupingBy$55$58::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$groupingBy$55$58, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$groupingBy$55$58::class$ = nullptr;

class Collectors$$Lambda$ConcurrentHashMap$59 : public $Supplier {
	$class(Collectors$$Lambda$ConcurrentHashMap$59, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($ConcurrentHashMap));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$ConcurrentHashMap$59>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$ConcurrentHashMap$59::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$ConcurrentHashMap$59, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$ConcurrentHashMap$59, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$ConcurrentHashMap$59::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$ConcurrentHashMap$59",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$ConcurrentHashMap$59::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$ConcurrentHashMap$59, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$ConcurrentHashMap$59::class$ = nullptr;

class Collectors$$Lambda$lambda$groupingByConcurrent$57$60 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$groupingByConcurrent$57$60, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($Function* classifier, $Supplier* downstreamSupplier, $BiConsumer* downstreamAccumulator) {
		$set(this, classifier, classifier);
		$set(this, downstreamSupplier, downstreamSupplier);
		$set(this, downstreamAccumulator, downstreamAccumulator);
	}
	virtual void accept(Object$* m, Object$* t) override {
		Collectors::lambda$groupingByConcurrent$57(classifier, downstreamSupplier, downstreamAccumulator, $cast($ConcurrentMap, m), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$groupingByConcurrent$57$60>());
	}
	$Function* classifier = nullptr;
	$Supplier* downstreamSupplier = nullptr;
	$BiConsumer* downstreamAccumulator = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$groupingByConcurrent$57$60::fieldInfos[4] = {
	{"classifier", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingByConcurrent$57$60, classifier)},
	{"downstreamSupplier", "Ljava/util/function/Supplier;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingByConcurrent$57$60, downstreamSupplier)},
	{"downstreamAccumulator", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingByConcurrent$57$60, downstreamAccumulator)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$groupingByConcurrent$57$60::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Function;Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$groupingByConcurrent$57$60, init$, void, $Function*, $Supplier*, $BiConsumer*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$groupingByConcurrent$57$60, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$groupingByConcurrent$57$60::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$groupingByConcurrent$57$60",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$groupingByConcurrent$57$60::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$groupingByConcurrent$57$60, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$groupingByConcurrent$57$60::class$ = nullptr;

class Collectors$$Lambda$lambda$groupingByConcurrent$59$61 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$groupingByConcurrent$59$61, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($Function* classifier, $Supplier* downstreamSupplier, $BiConsumer* downstreamAccumulator) {
		$set(this, classifier, classifier);
		$set(this, downstreamSupplier, downstreamSupplier);
		$set(this, downstreamAccumulator, downstreamAccumulator);
	}
	virtual void accept(Object$* m, Object$* t) override {
		Collectors::lambda$groupingByConcurrent$59(classifier, downstreamSupplier, downstreamAccumulator, $cast($ConcurrentMap, m), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$groupingByConcurrent$59$61>());
	}
	$Function* classifier = nullptr;
	$Supplier* downstreamSupplier = nullptr;
	$BiConsumer* downstreamAccumulator = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$groupingByConcurrent$59$61::fieldInfos[4] = {
	{"classifier", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingByConcurrent$59$61, classifier)},
	{"downstreamSupplier", "Ljava/util/function/Supplier;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingByConcurrent$59$61, downstreamSupplier)},
	{"downstreamAccumulator", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingByConcurrent$59$61, downstreamAccumulator)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$groupingByConcurrent$59$61::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Function;Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$groupingByConcurrent$59$61, init$, void, $Function*, $Supplier*, $BiConsumer*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$groupingByConcurrent$59$61, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$groupingByConcurrent$59$61::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$groupingByConcurrent$59$61",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$groupingByConcurrent$59$61::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$groupingByConcurrent$59$61, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$groupingByConcurrent$59$61::class$ = nullptr;

class Collectors$$Lambda$lambda$groupingByConcurrent$61$62 : public $Function {
	$class(Collectors$$Lambda$lambda$groupingByConcurrent$61$62, $NO_CLASS_INIT, $Function)
public:
	void init$($Function* downstreamFinisher) {
		$set(this, downstreamFinisher, downstreamFinisher);
	}
	virtual $Object* apply(Object$* intermediate) override {
		 return $of(Collectors::lambda$groupingByConcurrent$61(downstreamFinisher, $cast($ConcurrentMap, intermediate)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$groupingByConcurrent$61$62>());
	}
	$Function* downstreamFinisher = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$groupingByConcurrent$61$62::fieldInfos[2] = {
	{"downstreamFinisher", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingByConcurrent$61$62, downstreamFinisher)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$groupingByConcurrent$61$62::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Function;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$groupingByConcurrent$61$62, init$, void, $Function*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$groupingByConcurrent$61$62, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$groupingByConcurrent$61$62::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$groupingByConcurrent$61$62",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$groupingByConcurrent$61$62::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$groupingByConcurrent$61$62, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$groupingByConcurrent$61$62::class$ = nullptr;

class Collectors$$Lambda$lambda$partitioningBy$62$63 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$partitioningBy$62$63, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($BiConsumer* downstreamAccumulator, $Predicate* predicate) {
		$set(this, downstreamAccumulator, downstreamAccumulator);
		$set(this, predicate, predicate);
	}
	virtual void accept(Object$* result, Object$* t) override {
		Collectors::lambda$partitioningBy$62(downstreamAccumulator, predicate, $cast($Collectors$Partition, result), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$partitioningBy$62$63>());
	}
	$BiConsumer* downstreamAccumulator = nullptr;
	$Predicate* predicate = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$partitioningBy$62$63::fieldInfos[3] = {
	{"downstreamAccumulator", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$partitioningBy$62$63, downstreamAccumulator)},
	{"predicate", "Ljava/util/function/Predicate;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$partitioningBy$62$63, predicate)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$partitioningBy$62$63::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BiConsumer;Ljava/util/function/Predicate;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$partitioningBy$62$63, init$, void, $BiConsumer*, $Predicate*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$partitioningBy$62$63, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$partitioningBy$62$63::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$partitioningBy$62$63",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$partitioningBy$62$63::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$partitioningBy$62$63, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$partitioningBy$62$63::class$ = nullptr;

class Collectors$$Lambda$lambda$partitioningBy$63$64 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$partitioningBy$63$64, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$($BinaryOperator* op) {
		$set(this, op, op);
	}
	virtual $Object* apply(Object$* left, Object$* right) override {
		 return $of(Collectors::lambda$partitioningBy$63(op, $cast($Collectors$Partition, left), $cast($Collectors$Partition, right)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$partitioningBy$63$64>());
	}
	$BinaryOperator* op = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$partitioningBy$63$64::fieldInfos[2] = {
	{"op", "Ljava/util/function/BinaryOperator;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$partitioningBy$63$64, op)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$partitioningBy$63$64::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BinaryOperator;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$partitioningBy$63$64, init$, void, $BinaryOperator*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$partitioningBy$63$64, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$partitioningBy$63$64::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$partitioningBy$63$64",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$partitioningBy$63$64::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$partitioningBy$63$64, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$partitioningBy$63$64::class$ = nullptr;

class Collectors$$Lambda$lambda$partitioningBy$64$65 : public $Supplier {
	$class(Collectors$$Lambda$lambda$partitioningBy$64$65, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Collector* downstream) {
		$set(this, downstream, downstream);
	}
	virtual $Object* get() override {
		 return $of(Collectors::lambda$partitioningBy$64(downstream));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$partitioningBy$64$65>());
	}
	$Collector* downstream = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$partitioningBy$64$65::fieldInfos[2] = {
	{"downstream", "Ljava/util/stream/Collector;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$partitioningBy$64$65, downstream)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$partitioningBy$64$65::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/Collector;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$partitioningBy$64$65, init$, void, $Collector*)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$partitioningBy$64$65, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$partitioningBy$64$65::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$partitioningBy$64$65",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$partitioningBy$64$65::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$partitioningBy$64$65, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$partitioningBy$64$65::class$ = nullptr;

class Collectors$$Lambda$lambda$partitioningBy$65$66 : public $Function {
	$class(Collectors$$Lambda$lambda$partitioningBy$65$66, $NO_CLASS_INIT, $Function)
public:
	void init$($Collector* downstream) {
		$set(this, downstream, downstream);
	}
	virtual $Object* apply(Object$* par) override {
		 return $of(Collectors::lambda$partitioningBy$65(downstream, $cast($Collectors$Partition, par)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$partitioningBy$65$66>());
	}
	$Collector* downstream = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$partitioningBy$65$66::fieldInfos[2] = {
	{"downstream", "Ljava/util/stream/Collector;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$partitioningBy$65$66, downstream)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$partitioningBy$65$66::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/Collector;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$partitioningBy$65$66, init$, void, $Collector*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$partitioningBy$65$66, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$partitioningBy$65$66::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$partitioningBy$65$66",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$partitioningBy$65$66::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$partitioningBy$65$66, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$partitioningBy$65$66::class$ = nullptr;

class Collectors$$Lambda$lambda$toUnmodifiableMap$66$67 : public $Function {
	$class(Collectors$$Lambda$lambda$toUnmodifiableMap$66$67, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* map) override {
		 return $of(Collectors::lambda$toUnmodifiableMap$66($cast($Map, map)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$toUnmodifiableMap$66$67>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$toUnmodifiableMap$66$67::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$toUnmodifiableMap$66$67, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$toUnmodifiableMap$66$67, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$toUnmodifiableMap$66$67::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$toUnmodifiableMap$66$67",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$toUnmodifiableMap$66$67::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$toUnmodifiableMap$66$67, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$toUnmodifiableMap$66$67::class$ = nullptr;

class Collectors$$Lambda$lambda$toUnmodifiableMap$67$68 : public $Function {
	$class(Collectors$$Lambda$lambda$toUnmodifiableMap$67$68, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* map) override {
		 return $of(Collectors::lambda$toUnmodifiableMap$67($cast($HashMap, map)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$toUnmodifiableMap$67$68>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$toUnmodifiableMap$67$68::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$toUnmodifiableMap$67$68, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$toUnmodifiableMap$67$68, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$toUnmodifiableMap$67$68::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$toUnmodifiableMap$67$68",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$toUnmodifiableMap$67$68::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$toUnmodifiableMap$67$68, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$toUnmodifiableMap$67$68::class$ = nullptr;

class Collectors$$Lambda$lambda$toMap$68$69 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$toMap$68$69, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($Function* keyMapper, $Function* valueMapper, $BinaryOperator* mergeFunction) {
		$set(this, keyMapper, keyMapper);
		$set(this, valueMapper, valueMapper);
		$set(this, mergeFunction, mergeFunction);
	}
	virtual void accept(Object$* map, Object$* element) override {
		Collectors::lambda$toMap$68(keyMapper, valueMapper, mergeFunction, $cast($Map, map), element);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$toMap$68$69>());
	}
	$Function* keyMapper = nullptr;
	$Function* valueMapper = nullptr;
	$BinaryOperator* mergeFunction = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$toMap$68$69::fieldInfos[4] = {
	{"keyMapper", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$toMap$68$69, keyMapper)},
	{"valueMapper", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$toMap$68$69, valueMapper)},
	{"mergeFunction", "Ljava/util/function/BinaryOperator;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$toMap$68$69, mergeFunction)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$toMap$68$69::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Function;Ljava/util/function/Function;Ljava/util/function/BinaryOperator;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$toMap$68$69, init$, void, $Function*, $Function*, $BinaryOperator*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$toMap$68$69, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$toMap$68$69::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$toMap$68$69",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$toMap$68$69::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$toMap$68$69, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$toMap$68$69::class$ = nullptr;

class Collectors$$Lambda$lambda$toConcurrentMap$69$70 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$toConcurrentMap$69$70, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($Function* keyMapper, $Function* valueMapper, $BinaryOperator* mergeFunction) {
		$set(this, keyMapper, keyMapper);
		$set(this, valueMapper, valueMapper);
		$set(this, mergeFunction, mergeFunction);
	}
	virtual void accept(Object$* map, Object$* element) override {
		Collectors::lambda$toConcurrentMap$69(keyMapper, valueMapper, mergeFunction, $cast($ConcurrentMap, map), element);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$toConcurrentMap$69$70>());
	}
	$Function* keyMapper = nullptr;
	$Function* valueMapper = nullptr;
	$BinaryOperator* mergeFunction = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$toConcurrentMap$69$70::fieldInfos[4] = {
	{"keyMapper", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$toConcurrentMap$69$70, keyMapper)},
	{"valueMapper", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$toConcurrentMap$69$70, valueMapper)},
	{"mergeFunction", "Ljava/util/function/BinaryOperator;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$toConcurrentMap$69$70, mergeFunction)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$toConcurrentMap$69$70::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Function;Ljava/util/function/Function;Ljava/util/function/BinaryOperator;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$toConcurrentMap$69$70, init$, void, $Function*, $Function*, $BinaryOperator*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$toConcurrentMap$69$70, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$toConcurrentMap$69$70::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$toConcurrentMap$69$70",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$toConcurrentMap$69$70::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$toConcurrentMap$69$70, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$toConcurrentMap$69$70::class$ = nullptr;

class Collectors$$Lambda$IntSummaryStatistics$71 : public $Supplier {
	$class(Collectors$$Lambda$IntSummaryStatistics$71, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($IntSummaryStatistics));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$IntSummaryStatistics$71>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$IntSummaryStatistics$71::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$IntSummaryStatistics$71, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$IntSummaryStatistics$71, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$IntSummaryStatistics$71::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$IntSummaryStatistics$71",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$IntSummaryStatistics$71::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$IntSummaryStatistics$71, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$IntSummaryStatistics$71::class$ = nullptr;

class Collectors$$Lambda$lambda$summarizingInt$70$72 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$summarizingInt$70$72, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($ToIntFunction* mapper) {
		$set(this, mapper, mapper);
	}
	virtual void accept(Object$* r, Object$* t) override {
		Collectors::lambda$summarizingInt$70(mapper, $cast($IntSummaryStatistics, r), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summarizingInt$70$72>());
	}
	$ToIntFunction* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$summarizingInt$70$72::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/ToIntFunction;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$summarizingInt$70$72, mapper)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$summarizingInt$70$72::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/ToIntFunction;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summarizingInt$70$72, init$, void, $ToIntFunction*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summarizingInt$70$72, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summarizingInt$70$72::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summarizingInt$70$72",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summarizingInt$70$72::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summarizingInt$70$72, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summarizingInt$70$72::class$ = nullptr;

class Collectors$$Lambda$lambda$summarizingInt$71$73 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$summarizingInt$71$73, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* l, Object$* r) override {
		 return $of(Collectors::lambda$summarizingInt$71($cast($IntSummaryStatistics, l), $cast($IntSummaryStatistics, r)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summarizingInt$71$73>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$summarizingInt$71$73::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summarizingInt$71$73, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summarizingInt$71$73, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summarizingInt$71$73::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summarizingInt$71$73",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summarizingInt$71$73::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summarizingInt$71$73, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summarizingInt$71$73::class$ = nullptr;

class Collectors$$Lambda$LongSummaryStatistics$74 : public $Supplier {
	$class(Collectors$$Lambda$LongSummaryStatistics$74, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($LongSummaryStatistics));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$LongSummaryStatistics$74>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$LongSummaryStatistics$74::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$LongSummaryStatistics$74, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$LongSummaryStatistics$74, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$LongSummaryStatistics$74::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$LongSummaryStatistics$74",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$LongSummaryStatistics$74::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$LongSummaryStatistics$74, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$LongSummaryStatistics$74::class$ = nullptr;

class Collectors$$Lambda$lambda$summarizingLong$72$75 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$summarizingLong$72$75, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($ToLongFunction* mapper) {
		$set(this, mapper, mapper);
	}
	virtual void accept(Object$* r, Object$* t) override {
		Collectors::lambda$summarizingLong$72(mapper, $cast($LongSummaryStatistics, r), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summarizingLong$72$75>());
	}
	$ToLongFunction* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$summarizingLong$72$75::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/ToLongFunction;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$summarizingLong$72$75, mapper)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$summarizingLong$72$75::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/ToLongFunction;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summarizingLong$72$75, init$, void, $ToLongFunction*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summarizingLong$72$75, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summarizingLong$72$75::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summarizingLong$72$75",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summarizingLong$72$75::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summarizingLong$72$75, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summarizingLong$72$75::class$ = nullptr;

class Collectors$$Lambda$lambda$summarizingLong$73$76 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$summarizingLong$73$76, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* l, Object$* r) override {
		 return $of(Collectors::lambda$summarizingLong$73($cast($LongSummaryStatistics, l), $cast($LongSummaryStatistics, r)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summarizingLong$73$76>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$summarizingLong$73$76::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summarizingLong$73$76, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summarizingLong$73$76, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summarizingLong$73$76::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summarizingLong$73$76",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summarizingLong$73$76::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summarizingLong$73$76, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summarizingLong$73$76::class$ = nullptr;

class Collectors$$Lambda$DoubleSummaryStatistics$77 : public $Supplier {
	$class(Collectors$$Lambda$DoubleSummaryStatistics$77, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($DoubleSummaryStatistics));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$DoubleSummaryStatistics$77>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$DoubleSummaryStatistics$77::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$DoubleSummaryStatistics$77, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$DoubleSummaryStatistics$77, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$DoubleSummaryStatistics$77::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$DoubleSummaryStatistics$77",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$DoubleSummaryStatistics$77::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$DoubleSummaryStatistics$77, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$DoubleSummaryStatistics$77::class$ = nullptr;

class Collectors$$Lambda$lambda$summarizingDouble$74$78 : public $BiConsumer {
	$class(Collectors$$Lambda$lambda$summarizingDouble$74$78, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($ToDoubleFunction* mapper) {
		$set(this, mapper, mapper);
	}
	virtual void accept(Object$* r, Object$* t) override {
		Collectors::lambda$summarizingDouble$74(mapper, $cast($DoubleSummaryStatistics, r), t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summarizingDouble$74$78>());
	}
	$ToDoubleFunction* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$summarizingDouble$74$78::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/ToDoubleFunction;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$summarizingDouble$74$78, mapper)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$summarizingDouble$74$78::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/ToDoubleFunction;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summarizingDouble$74$78, init$, void, $ToDoubleFunction*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summarizingDouble$74$78, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summarizingDouble$74$78::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summarizingDouble$74$78",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summarizingDouble$74$78::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summarizingDouble$74$78, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summarizingDouble$74$78::class$ = nullptr;

class Collectors$$Lambda$lambda$summarizingDouble$75$79 : public $BinaryOperator {
	$class(Collectors$$Lambda$lambda$summarizingDouble$75$79, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* l, Object$* r) override {
		 return $of(Collectors::lambda$summarizingDouble$75($cast($DoubleSummaryStatistics, l), $cast($DoubleSummaryStatistics, r)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$summarizingDouble$75$79>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$lambda$summarizingDouble$75$79::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$summarizingDouble$75$79, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$summarizingDouble$75$79, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$summarizingDouble$75$79::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$summarizingDouble$75$79",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$summarizingDouble$75$79::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$summarizingDouble$75$79, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$summarizingDouble$75$79::class$ = nullptr;

class Collectors$$Lambda$lambda$teeing0$76$80 : public $Supplier {
	$class(Collectors$$Lambda$lambda$teeing0$76$80, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Supplier* c1Supplier, $Supplier* c2Supplier, $BiConsumer* c1Accumulator, $BiConsumer* c2Accumulator, $BinaryOperator* c1Combiner, $BinaryOperator* c2Combiner, $Function* c1Finisher, $Function* c2Finisher, $BiFunction* merger) {
		$set(this, c1Supplier, c1Supplier);
		$set(this, c2Supplier, c2Supplier);
		$set(this, c1Accumulator, c1Accumulator);
		$set(this, c2Accumulator, c2Accumulator);
		$set(this, c1Combiner, c1Combiner);
		$set(this, c2Combiner, c2Combiner);
		$set(this, c1Finisher, c1Finisher);
		$set(this, c2Finisher, c2Finisher);
		$set(this, merger, merger);
	}
	virtual $Object* get() override {
		 return $of(Collectors::lambda$teeing0$76(c1Supplier, c2Supplier, c1Accumulator, c2Accumulator, c1Combiner, c2Combiner, c1Finisher, c2Finisher, merger));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$teeing0$76$80>());
	}
	$Supplier* c1Supplier = nullptr;
	$Supplier* c2Supplier = nullptr;
	$BiConsumer* c1Accumulator = nullptr;
	$BiConsumer* c2Accumulator = nullptr;
	$BinaryOperator* c1Combiner = nullptr;
	$BinaryOperator* c2Combiner = nullptr;
	$Function* c1Finisher = nullptr;
	$Function* c2Finisher = nullptr;
	$BiFunction* merger = nullptr;
	static $FieldInfo fieldInfos[10];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$teeing0$76$80::fieldInfos[10] = {
	{"c1Supplier", "Ljava/util/function/Supplier;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$teeing0$76$80, c1Supplier)},
	{"c2Supplier", "Ljava/util/function/Supplier;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$teeing0$76$80, c2Supplier)},
	{"c1Accumulator", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$teeing0$76$80, c1Accumulator)},
	{"c2Accumulator", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$teeing0$76$80, c2Accumulator)},
	{"c1Combiner", "Ljava/util/function/BinaryOperator;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$teeing0$76$80, c1Combiner)},
	{"c2Combiner", "Ljava/util/function/BinaryOperator;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$teeing0$76$80, c2Combiner)},
	{"c1Finisher", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$teeing0$76$80, c1Finisher)},
	{"c2Finisher", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$teeing0$76$80, c2Finisher)},
	{"merger", "Ljava/util/function/BiFunction;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$teeing0$76$80, merger)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$teeing0$76$80::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Supplier;Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;Ljava/util/function/BiConsumer;Ljava/util/function/BinaryOperator;Ljava/util/function/BinaryOperator;Ljava/util/function/Function;Ljava/util/function/Function;Ljava/util/function/BiFunction;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$teeing0$76$80, init$, void, $Supplier*, $Supplier*, $BiConsumer*, $BiConsumer*, $BinaryOperator*, $BinaryOperator*, $Function*, $Function*, $BiFunction*)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$teeing0$76$80, get, $Object*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$teeing0$76$80::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$teeing0$76$80",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$teeing0$76$80::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$teeing0$76$80, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$teeing0$76$80::class$ = nullptr;

class Collectors$$Lambda$add$81 : public $BiConsumer {
	$class(Collectors$$Lambda$add$81, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, Object$* t) override {
		$sure($Collectors$1PairBox, inst$)->add(t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$add$81>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$add$81::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$add$81, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$add$81, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$add$81::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$add$81",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$add$81::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$add$81, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$add$81::class$ = nullptr;

class Collectors$$Lambda$combine$82 : public $BinaryOperator {
	$class(Collectors$$Lambda$combine$82, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$, Object$* other) override {
		 return $of($sure($Collectors$1PairBox, inst$)->combine($cast($Collectors$1PairBox, other)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$combine$82>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$combine$82::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$combine$82, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$combine$82, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$combine$82::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$combine$82",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$combine$82::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$combine$82, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$combine$82::class$ = nullptr;

class Collectors$$Lambda$get$83 : public $Function {
	$class(Collectors$$Lambda$get$83, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $sure($Collectors$1PairBox, inst$)->get();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$get$83>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Collectors$$Lambda$get$83::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Collectors$$Lambda$get$83, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$get$83, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$get$83::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$get$83",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Collectors$$Lambda$get$83::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$get$83, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$get$83::class$ = nullptr;

class Collectors$$Lambda$lambda$groupingBy$54$84 : public $BiFunction {
	$class(Collectors$$Lambda$lambda$groupingBy$54$84, $NO_CLASS_INIT, $BiFunction)
public:
	void init$($Function* downstreamFinisher) {
		$set(this, downstreamFinisher, downstreamFinisher);
	}
	virtual $Object* apply(Object$* k, Object$* v) override {
		 return Collectors::lambda$groupingBy$54(downstreamFinisher, k, v);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$groupingBy$54$84>());
	}
	$Function* downstreamFinisher = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$groupingBy$54$84::fieldInfos[2] = {
	{"downstreamFinisher", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingBy$54$84, downstreamFinisher)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$groupingBy$54$84::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Function;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$groupingBy$54$84, init$, void, $Function*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$groupingBy$54$84, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$groupingBy$54$84::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$groupingBy$54$84",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$groupingBy$54$84::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$groupingBy$54$84, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$groupingBy$54$84::class$ = nullptr;

class Collectors$$Lambda$lambda$groupingBy$52$85 : public $Function {
	$class(Collectors$$Lambda$lambda$groupingBy$52$85, $NO_CLASS_INIT, $Function)
public:
	void init$($Supplier* downstreamSupplier) {
		$set(this, downstreamSupplier, downstreamSupplier);
	}
	virtual $Object* apply(Object$* k) override {
		 return Collectors::lambda$groupingBy$52(downstreamSupplier, k);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$groupingBy$52$85>());
	}
	$Supplier* downstreamSupplier = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$groupingBy$52$85::fieldInfos[2] = {
	{"downstreamSupplier", "Ljava/util/function/Supplier;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$groupingBy$52$85, downstreamSupplier)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$groupingBy$52$85::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Supplier;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$groupingBy$52$85, init$, void, $Supplier*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$groupingBy$52$85, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$groupingBy$52$85::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$groupingBy$52$85",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$groupingBy$52$85::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$groupingBy$52$85, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$groupingBy$52$85::class$ = nullptr;

class Collectors$$Lambda$lambda$flatMapping$14$86 : public $Consumer {
	$class(Collectors$$Lambda$lambda$flatMapping$14$86, $NO_CLASS_INIT, $Consumer)
public:
	void init$($BiConsumer* downstreamAccumulator, Object$* r) {
		$set(this, downstreamAccumulator, downstreamAccumulator);
		$set(this, r, r);
	}
	virtual void accept(Object$* u) override {
		Collectors::lambda$flatMapping$14(downstreamAccumulator, r, u);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Collectors$$Lambda$lambda$flatMapping$14$86>());
	}
	$BiConsumer* downstreamAccumulator = nullptr;
	$Object* r = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Collectors$$Lambda$lambda$flatMapping$14$86::fieldInfos[3] = {
	{"downstreamAccumulator", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$flatMapping$14$86, downstreamAccumulator)},
	{"r", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Collectors$$Lambda$lambda$flatMapping$14$86, r)},
	{}
};
$MethodInfo Collectors$$Lambda$lambda$flatMapping$14$86::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BiConsumer;Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(Collectors$$Lambda$lambda$flatMapping$14$86, init$, void, $BiConsumer*, Object$*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Collectors$$Lambda$lambda$flatMapping$14$86, accept, void, Object$*)},
	{}
};
$ClassInfo Collectors$$Lambda$lambda$flatMapping$14$86::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Collectors$$Lambda$lambda$flatMapping$14$86",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Collectors$$Lambda$lambda$flatMapping$14$86::load$($String* name, bool initialize) {
	$loadClass(Collectors$$Lambda$lambda$flatMapping$14$86, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Collectors$$Lambda$lambda$flatMapping$14$86::class$ = nullptr;

$FieldInfo _Collectors_FieldInfo_[] = {
	{"CH_CONCURRENT_ID", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/stream/Collector$Characteristics;>;", $STATIC | $FINAL, $staticField(Collectors, CH_CONCURRENT_ID)},
	{"CH_CONCURRENT_NOID", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/stream/Collector$Characteristics;>;", $STATIC | $FINAL, $staticField(Collectors, CH_CONCURRENT_NOID)},
	{"CH_ID", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/stream/Collector$Characteristics;>;", $STATIC | $FINAL, $staticField(Collectors, CH_ID)},
	{"CH_UNORDERED_ID", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/stream/Collector$Characteristics;>;", $STATIC | $FINAL, $staticField(Collectors, CH_UNORDERED_ID)},
	{"CH_NOID", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/stream/Collector$Characteristics;>;", $STATIC | $FINAL, $staticField(Collectors, CH_NOID)},
	{"CH_UNORDERED_NOID", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/stream/Collector$Characteristics;>;", $STATIC | $FINAL, $staticField(Collectors, CH_UNORDERED_NOID)},
	{}
};

$MethodInfo _Collectors_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Collectors, init$, void)},
	{"averagingDouble", "(Ljava/util/function/ToDoubleFunction;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/function/ToDoubleFunction<-TT;>;)Ljava/util/stream/Collector<TT;*Ljava/lang/Double;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, averagingDouble, $Collector*, $ToDoubleFunction*)},
	{"averagingInt", "(Ljava/util/function/ToIntFunction;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/function/ToIntFunction<-TT;>;)Ljava/util/stream/Collector<TT;*Ljava/lang/Double;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, averagingInt, $Collector*, $ToIntFunction*)},
	{"averagingLong", "(Ljava/util/function/ToLongFunction;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/function/ToLongFunction<-TT;>;)Ljava/util/stream/Collector<TT;*Ljava/lang/Double;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, averagingLong, $Collector*, $ToLongFunction*)},
	{"boxSupplier", "(Ljava/lang/Object;)Ljava/util/function/Supplier;", "<T:Ljava/lang/Object;>(TT;)Ljava/util/function/Supplier<[TT;>;", $PRIVATE | $STATIC, $staticMethod(Collectors, boxSupplier, $Supplier*, Object$*)},
	{"castingIdentity", "()Ljava/util/function/Function;", "<I:Ljava/lang/Object;R:Ljava/lang/Object;>()Ljava/util/function/Function<TI;TR;>;", $PRIVATE | $STATIC, $staticMethod(Collectors, castingIdentity, $Function*)},
	{"collectingAndThen", "(Ljava/util/stream/Collector;Ljava/util/function/Function;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;A:Ljava/lang/Object;R:Ljava/lang/Object;RR:Ljava/lang/Object;>(Ljava/util/stream/Collector<TT;TA;TR;>;Ljava/util/function/Function<TR;TRR;>;)Ljava/util/stream/Collector<TT;TA;TRR;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, collectingAndThen, $Collector*, $Collector*, $Function*)},
	{"computeFinalSum", "([D)D", nullptr, $STATIC, $staticMethod(Collectors, computeFinalSum, double, $doubles*)},
	{"counting", "()Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>()Ljava/util/stream/Collector<TT;*Ljava/lang/Long;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, counting, $Collector*)},
	{"duplicateKeyException", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/IllegalStateException;", nullptr, $PRIVATE | $STATIC, $staticMethod(Collectors, duplicateKeyException, $IllegalStateException*, Object$*, Object$*, Object$*)},
	{"filtering", "(Ljava/util/function/Predicate;Ljava/util/stream/Collector;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;A:Ljava/lang/Object;R:Ljava/lang/Object;>(Ljava/util/function/Predicate<-TT;>;Ljava/util/stream/Collector<-TT;TA;TR;>;)Ljava/util/stream/Collector<TT;*TR;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, filtering, $Collector*, $Predicate*, $Collector*)},
	{"flatMapping", "(Ljava/util/function/Function;Ljava/util/stream/Collector;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;U:Ljava/lang/Object;A:Ljava/lang/Object;R:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+Ljava/util/stream/Stream<+TU;>;>;Ljava/util/stream/Collector<-TU;TA;TR;>;)Ljava/util/stream/Collector<TT;*TR;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, flatMapping, $Collector*, $Function*, $Collector*)},
	{"groupingBy", "(Ljava/util/function/Function;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TK;>;)Ljava/util/stream/Collector<TT;*Ljava/util/Map<TK;Ljava/util/List<TT;>;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, groupingBy, $Collector*, $Function*)},
	{"groupingBy", "(Ljava/util/function/Function;Ljava/util/stream/Collector;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;A:Ljava/lang/Object;D:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/stream/Collector<-TT;TA;TD;>;)Ljava/util/stream/Collector<TT;*Ljava/util/Map<TK;TD;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, groupingBy, $Collector*, $Function*, $Collector*)},
	{"groupingBy", "(Ljava/util/function/Function;Ljava/util/function/Supplier;Ljava/util/stream/Collector;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;D:Ljava/lang/Object;A:Ljava/lang/Object;M::Ljava/util/Map<TK;TD;>;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/function/Supplier<TM;>;Ljava/util/stream/Collector<-TT;TA;TD;>;)Ljava/util/stream/Collector<TT;*TM;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, groupingBy, $Collector*, $Function*, $Supplier*, $Collector*)},
	{"groupingByConcurrent", "(Ljava/util/function/Function;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TK;>;)Ljava/util/stream/Collector<TT;*Ljava/util/concurrent/ConcurrentMap<TK;Ljava/util/List<TT;>;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, groupingByConcurrent, $Collector*, $Function*)},
	{"groupingByConcurrent", "(Ljava/util/function/Function;Ljava/util/stream/Collector;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;A:Ljava/lang/Object;D:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/stream/Collector<-TT;TA;TD;>;)Ljava/util/stream/Collector<TT;*Ljava/util/concurrent/ConcurrentMap<TK;TD;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, groupingByConcurrent, $Collector*, $Function*, $Collector*)},
	{"groupingByConcurrent", "(Ljava/util/function/Function;Ljava/util/function/Supplier;Ljava/util/stream/Collector;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;A:Ljava/lang/Object;D:Ljava/lang/Object;M::Ljava/util/concurrent/ConcurrentMap<TK;TD;>;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/function/Supplier<TM;>;Ljava/util/stream/Collector<-TT;TA;TD;>;)Ljava/util/stream/Collector<TT;*TM;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, groupingByConcurrent, $Collector*, $Function*, $Supplier*, $Collector*)},
	{"joining", "()Ljava/util/stream/Collector;", "()Ljava/util/stream/Collector<Ljava/lang/CharSequence;*Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, joining, $Collector*)},
	{"joining", "(Ljava/lang/CharSequence;)Ljava/util/stream/Collector;", "(Ljava/lang/CharSequence;)Ljava/util/stream/Collector<Ljava/lang/CharSequence;*Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, joining, $Collector*, $CharSequence*)},
	{"joining", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/util/stream/Collector;", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/util/stream/Collector<Ljava/lang/CharSequence;*Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, joining, $Collector*, $CharSequence*, $CharSequence*, $CharSequence*)},
	{"lambda$averagingDouble$38", "()[D", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$averagingDouble$38, $doubles*)},
	{"lambda$averagingDouble$39", "(Ljava/util/function/ToDoubleFunction;[DLjava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$averagingDouble$39, void, $ToDoubleFunction*, $doubles*, Object$*)},
	{"lambda$averagingDouble$40", "([D[D)[D", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$averagingDouble$40, $doubles*, $doubles*, $doubles*)},
	{"lambda$averagingDouble$41", "([D)Ljava/lang/Double;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$averagingDouble$41, $Double*, $doubles*)},
	{"lambda$averagingInt$30", "()[J", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$averagingInt$30, $longs*)},
	{"lambda$averagingInt$31", "(Ljava/util/function/ToIntFunction;[JLjava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$averagingInt$31, void, $ToIntFunction*, $longs*, Object$*)},
	{"lambda$averagingInt$32", "([J[J)[J", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$averagingInt$32, $longs*, $longs*, $longs*)},
	{"lambda$averagingInt$33", "([J)Ljava/lang/Double;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$averagingInt$33, $Double*, $longs*)},
	{"lambda$averagingLong$35", "(Ljava/util/function/ToLongFunction;[JLjava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$averagingLong$35, void, $ToLongFunction*, $longs*, Object$*)},
	{"lambda$boxSupplier$45", "(Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$boxSupplier$45, $ObjectArray*, Object$*)},
	{"lambda$castingIdentity$2", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$castingIdentity$2, $Object*, Object$*)},
	{"lambda$counting$17", "(Ljava/lang/Object;)J", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$counting$17, int64_t, Object$*)},
	{"lambda$filtering$16", "(Ljava/util/function/Predicate;Ljava/util/function/BiConsumer;Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$filtering$16, void, $Predicate*, $BiConsumer*, Object$*, Object$*)},
	{"lambda$flatMapping$14", "(Ljava/util/function/BiConsumer;Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$flatMapping$14, void, $BiConsumer*, Object$*, Object$*)},
	{"lambda$flatMapping$15", "(Ljava/util/function/Function;Ljava/util/function/BiConsumer;Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$flatMapping$15, void, $Function*, $BiConsumer*, Object$*, Object$*)},
	{"lambda$groupingBy$52", "(Ljava/util/function/Supplier;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$groupingBy$52, $Object*, $Supplier*, Object$*)},
	{"lambda$groupingBy$53", "(Ljava/util/function/Function;Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;Ljava/util/Map;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$groupingBy$53, void, $Function*, $Supplier*, $BiConsumer*, $Map*, Object$*)},
	{"lambda$groupingBy$54", "(Ljava/util/function/Function;Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$groupingBy$54, $Object*, $Function*, Object$*, Object$*)},
	{"lambda$groupingBy$55", "(Ljava/util/function/Function;Ljava/util/Map;)Ljava/util/Map;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$groupingBy$55, $Map*, $Function*, $Map*)},
	{"lambda$groupingByConcurrent$57", "(Ljava/util/function/Function;Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;Ljava/util/concurrent/ConcurrentMap;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$groupingByConcurrent$57, void, $Function*, $Supplier*, $BiConsumer*, $ConcurrentMap*, Object$*)},
	{"lambda$groupingByConcurrent$59", "(Ljava/util/function/Function;Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;Ljava/util/concurrent/ConcurrentMap;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$groupingByConcurrent$59, void, $Function*, $Supplier*, $BiConsumer*, $ConcurrentMap*, Object$*)},
	{"lambda$groupingByConcurrent$61", "(Ljava/util/function/Function;Ljava/util/concurrent/ConcurrentMap;)Ljava/util/concurrent/ConcurrentMap;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$groupingByConcurrent$61, $ConcurrentMap*, $Function*, $ConcurrentMap*)},
	{"lambda$joining$10", "(Ljava/lang/StringBuilder;Ljava/lang/StringBuilder;)Ljava/lang/StringBuilder;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$joining$10, $StringBuilder*, $StringBuilder*, $StringBuilder*)},
	{"lambda$joining$11", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/util/StringJoiner;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$joining$11, $StringJoiner*, $CharSequence*, $CharSequence*, $CharSequence*)},
	{"lambda$mapMerger$12", "(Ljava/util/function/BinaryOperator;Ljava/util/Map;Ljava/util/Map;)Ljava/util/Map;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$mapMerger$12, $Map*, $BinaryOperator*, $Map*, $Map*)},
	{"lambda$mapping$13", "(Ljava/util/function/BiConsumer;Ljava/util/function/Function;Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$mapping$13, void, $BiConsumer*, $Function*, Object$*, Object$*)},
	{"lambda$partitioningBy$62", "(Ljava/util/function/BiConsumer;Ljava/util/function/Predicate;Ljava/util/stream/Collectors$Partition;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$partitioningBy$62, void, $BiConsumer*, $Predicate*, $Collectors$Partition*, Object$*)},
	{"lambda$partitioningBy$63", "(Ljava/util/function/BinaryOperator;Ljava/util/stream/Collectors$Partition;Ljava/util/stream/Collectors$Partition;)Ljava/util/stream/Collectors$Partition;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$partitioningBy$63, $Collectors$Partition*, $BinaryOperator*, $Collectors$Partition*, $Collectors$Partition*)},
	{"lambda$partitioningBy$64", "(Ljava/util/stream/Collector;)Ljava/util/stream/Collectors$Partition;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$partitioningBy$64, $Collectors$Partition*, $Collector*)},
	{"lambda$partitioningBy$65", "(Ljava/util/stream/Collector;Ljava/util/stream/Collectors$Partition;)Ljava/util/Map;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$partitioningBy$65, $Map*, $Collector*, $Collectors$Partition*)},
	{"lambda$reducing$42", "(Ljava/util/function/BinaryOperator;[Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$reducing$42, void, $BinaryOperator*, $ObjectArray*, Object$*)},
	{"lambda$reducing$43", "(Ljava/util/function/BinaryOperator;[Ljava/lang/Object;[Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$reducing$43, $ObjectArray*, $BinaryOperator*, $ObjectArray*, $ObjectArray*)},
	{"lambda$reducing$44", "([Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$reducing$44, $Object*, $ObjectArray*)},
	{"lambda$reducing$46", "(Ljava/util/function/BinaryOperator;)Ljava/util/stream/Collectors$1OptionalBox;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$reducing$46, $Collectors$1OptionalBox*, $BinaryOperator*)},
	{"lambda$reducing$47", "(Ljava/util/stream/Collectors$1OptionalBox;Ljava/util/stream/Collectors$1OptionalBox;)Ljava/util/stream/Collectors$1OptionalBox;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$reducing$47, $Collectors$1OptionalBox*, $Collectors$1OptionalBox*, $Collectors$1OptionalBox*)},
	{"lambda$reducing$48", "(Ljava/util/stream/Collectors$1OptionalBox;)Ljava/util/Optional;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$reducing$48, $Optional*, $Collectors$1OptionalBox*)},
	{"lambda$reducing$49", "(Ljava/util/function/BinaryOperator;Ljava/util/function/Function;[Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$reducing$49, void, $BinaryOperator*, $Function*, $ObjectArray*, Object$*)},
	{"lambda$summarizingDouble$74", "(Ljava/util/function/ToDoubleFunction;Ljava/util/DoubleSummaryStatistics;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summarizingDouble$74, void, $ToDoubleFunction*, $DoubleSummaryStatistics*, Object$*)},
	{"lambda$summarizingDouble$75", "(Ljava/util/DoubleSummaryStatistics;Ljava/util/DoubleSummaryStatistics;)Ljava/util/DoubleSummaryStatistics;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summarizingDouble$75, $DoubleSummaryStatistics*, $DoubleSummaryStatistics*, $DoubleSummaryStatistics*)},
	{"lambda$summarizingInt$70", "(Ljava/util/function/ToIntFunction;Ljava/util/IntSummaryStatistics;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summarizingInt$70, void, $ToIntFunction*, $IntSummaryStatistics*, Object$*)},
	{"lambda$summarizingInt$71", "(Ljava/util/IntSummaryStatistics;Ljava/util/IntSummaryStatistics;)Ljava/util/IntSummaryStatistics;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summarizingInt$71, $IntSummaryStatistics*, $IntSummaryStatistics*, $IntSummaryStatistics*)},
	{"lambda$summarizingLong$72", "(Ljava/util/function/ToLongFunction;Ljava/util/LongSummaryStatistics;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summarizingLong$72, void, $ToLongFunction*, $LongSummaryStatistics*, Object$*)},
	{"lambda$summarizingLong$73", "(Ljava/util/LongSummaryStatistics;Ljava/util/LongSummaryStatistics;)Ljava/util/LongSummaryStatistics;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summarizingLong$73, $LongSummaryStatistics*, $LongSummaryStatistics*, $LongSummaryStatistics*)},
	{"lambda$summingDouble$26", "()[D", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summingDouble$26, $doubles*)},
	{"lambda$summingDouble$27", "(Ljava/util/function/ToDoubleFunction;[DLjava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summingDouble$27, void, $ToDoubleFunction*, $doubles*, Object$*)},
	{"lambda$summingDouble$28", "([D[D)[D", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summingDouble$28, $doubles*, $doubles*, $doubles*)},
	{"lambda$summingDouble$29", "([D)Ljava/lang/Double;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summingDouble$29, $Double*, $doubles*)},
	{"lambda$summingInt$18", "()[I", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summingInt$18, $ints*)},
	{"lambda$summingInt$19", "(Ljava/util/function/ToIntFunction;[ILjava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summingInt$19, void, $ToIntFunction*, $ints*, Object$*)},
	{"lambda$summingInt$20", "([I[I)[I", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summingInt$20, $ints*, $ints*, $ints*)},
	{"lambda$summingInt$21", "([I)Ljava/lang/Integer;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summingInt$21, $Integer*, $ints*)},
	{"lambda$summingLong$22", "()[J", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summingLong$22, $longs*)},
	{"lambda$summingLong$23", "(Ljava/util/function/ToLongFunction;[JLjava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summingLong$23, void, $ToLongFunction*, $longs*, Object$*)},
	{"lambda$summingLong$24", "([J[J)[J", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summingLong$24, $longs*, $longs*, $longs*)},
	{"lambda$summingLong$25", "([J)Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$summingLong$25, $Long*, $longs*)},
	{"lambda$teeing0$76", "(Ljava/util/function/Supplier;Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;Ljava/util/function/BiConsumer;Ljava/util/function/BinaryOperator;Ljava/util/function/BinaryOperator;Ljava/util/function/Function;Ljava/util/function/Function;Ljava/util/function/BiFunction;)Ljava/util/stream/Collectors$1PairBox;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$teeing0$76, $Collectors$1PairBox*, $Supplier*, $Supplier*, $BiConsumer*, $BiConsumer*, $BinaryOperator*, $BinaryOperator*, $Function*, $Function*, $BiFunction*)},
	{"lambda$toCollection$3", "(Ljava/util/Collection;Ljava/util/Collection;)Ljava/util/Collection;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$toCollection$3, $Collection*, $Collection*, $Collection*)},
	{"lambda$toConcurrentMap$69", "(Ljava/util/function/Function;Ljava/util/function/Function;Ljava/util/function/BinaryOperator;Ljava/util/concurrent/ConcurrentMap;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$toConcurrentMap$69, void, $Function*, $Function*, $BinaryOperator*, $ConcurrentMap*, Object$*)},
	{"lambda$toList$4", "(Ljava/util/ArrayList;Ljava/util/ArrayList;)Ljava/util/ArrayList;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$toList$4, $ArrayList*, $ArrayList*, $ArrayList*)},
	{"lambda$toMap$68", "(Ljava/util/function/Function;Ljava/util/function/Function;Ljava/util/function/BinaryOperator;Ljava/util/Map;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$toMap$68, void, $Function*, $Function*, $BinaryOperator*, $Map*, Object$*)},
	{"lambda$toSet$7", "(Ljava/util/HashSet;Ljava/util/HashSet;)Ljava/util/HashSet;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$toSet$7, $HashSet*, $HashSet*, $HashSet*)},
	{"lambda$toUnmodifiableList$6", "(Ljava/util/ArrayList;)Ljava/util/List;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$toUnmodifiableList$6, $List*, $ArrayList*)},
	{"lambda$toUnmodifiableMap$66", "(Ljava/util/Map;)Ljava/util/Map;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$toUnmodifiableMap$66, $Map*, $Map*)},
	{"lambda$toUnmodifiableMap$67", "(Ljava/util/HashMap;)Ljava/util/Map;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$toUnmodifiableMap$67, $Map*, $HashMap*)},
	{"lambda$toUnmodifiableSet$9", "(Ljava/util/HashSet;)Ljava/util/Set;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$toUnmodifiableSet$9, $Set*, $HashSet*)},
	{"lambda$uniqKeysMapAccumulator$1", "(Ljava/util/function/Function;Ljava/util/function/Function;Ljava/util/Map;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$uniqKeysMapAccumulator$1, void, $Function*, $Function*, $Map*, Object$*)},
	{"lambda$uniqKeysMapMerger$0", "(Ljava/util/Map;Ljava/util/Map;)Ljava/util/Map;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Collectors, lambda$uniqKeysMapMerger$0, $Map*, $Map*, $Map*)},
	{"mapMerger", "(Ljava/util/function/BinaryOperator;)Ljava/util/function/BinaryOperator;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;M::Ljava/util/Map<TK;TV;>;>(Ljava/util/function/BinaryOperator<TV;>;)Ljava/util/function/BinaryOperator<TM;>;", $PRIVATE | $STATIC, $staticMethod(Collectors, mapMerger, $BinaryOperator*, $BinaryOperator*)},
	{"mapping", "(Ljava/util/function/Function;Ljava/util/stream/Collector;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;U:Ljava/lang/Object;A:Ljava/lang/Object;R:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TU;>;Ljava/util/stream/Collector<-TU;TA;TR;>;)Ljava/util/stream/Collector<TT;*TR;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, mapping, $Collector*, $Function*, $Collector*)},
	{"maxBy", "(Ljava/util/Comparator;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/Comparator<-TT;>;)Ljava/util/stream/Collector<TT;*Ljava/util/Optional<TT;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, maxBy, $Collector*, $Comparator*)},
	{"minBy", "(Ljava/util/Comparator;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/Comparator<-TT;>;)Ljava/util/stream/Collector<TT;*Ljava/util/Optional<TT;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, minBy, $Collector*, $Comparator*)},
	{"partitioningBy", "(Ljava/util/function/Predicate;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/function/Predicate<-TT;>;)Ljava/util/stream/Collector<TT;*Ljava/util/Map<Ljava/lang/Boolean;Ljava/util/List<TT;>;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, partitioningBy, $Collector*, $Predicate*)},
	{"partitioningBy", "(Ljava/util/function/Predicate;Ljava/util/stream/Collector;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;D:Ljava/lang/Object;A:Ljava/lang/Object;>(Ljava/util/function/Predicate<-TT;>;Ljava/util/stream/Collector<-TT;TA;TD;>;)Ljava/util/stream/Collector<TT;*Ljava/util/Map<Ljava/lang/Boolean;TD;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, partitioningBy, $Collector*, $Predicate*, $Collector*)},
	{"reducing", "(Ljava/lang/Object;Ljava/util/function/BinaryOperator;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(TT;Ljava/util/function/BinaryOperator<TT;>;)Ljava/util/stream/Collector<TT;*TT;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, reducing, $Collector*, Object$*, $BinaryOperator*)},
	{"reducing", "(Ljava/util/function/BinaryOperator;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/function/BinaryOperator<TT;>;)Ljava/util/stream/Collector<TT;*Ljava/util/Optional<TT;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, reducing, $Collector*, $BinaryOperator*)},
	{"reducing", "(Ljava/lang/Object;Ljava/util/function/Function;Ljava/util/function/BinaryOperator;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;U:Ljava/lang/Object;>(TU;Ljava/util/function/Function<-TT;+TU;>;Ljava/util/function/BinaryOperator<TU;>;)Ljava/util/stream/Collector<TT;*TU;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, reducing, $Collector*, Object$*, $Function*, $BinaryOperator*)},
	{"sumWithCompensation", "([DD)[D", nullptr, $STATIC, $staticMethod(Collectors, sumWithCompensation, $doubles*, $doubles*, double)},
	{"summarizingDouble", "(Ljava/util/function/ToDoubleFunction;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/function/ToDoubleFunction<-TT;>;)Ljava/util/stream/Collector<TT;*Ljava/util/DoubleSummaryStatistics;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, summarizingDouble, $Collector*, $ToDoubleFunction*)},
	{"summarizingInt", "(Ljava/util/function/ToIntFunction;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/function/ToIntFunction<-TT;>;)Ljava/util/stream/Collector<TT;*Ljava/util/IntSummaryStatistics;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, summarizingInt, $Collector*, $ToIntFunction*)},
	{"summarizingLong", "(Ljava/util/function/ToLongFunction;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/function/ToLongFunction<-TT;>;)Ljava/util/stream/Collector<TT;*Ljava/util/LongSummaryStatistics;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, summarizingLong, $Collector*, $ToLongFunction*)},
	{"summingDouble", "(Ljava/util/function/ToDoubleFunction;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/function/ToDoubleFunction<-TT;>;)Ljava/util/stream/Collector<TT;*Ljava/lang/Double;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, summingDouble, $Collector*, $ToDoubleFunction*)},
	{"summingInt", "(Ljava/util/function/ToIntFunction;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/function/ToIntFunction<-TT;>;)Ljava/util/stream/Collector<TT;*Ljava/lang/Integer;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, summingInt, $Collector*, $ToIntFunction*)},
	{"summingLong", "(Ljava/util/function/ToLongFunction;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>(Ljava/util/function/ToLongFunction<-TT;>;)Ljava/util/stream/Collector<TT;*Ljava/lang/Long;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, summingLong, $Collector*, $ToLongFunction*)},
	{"teeing", "(Ljava/util/stream/Collector;Ljava/util/stream/Collector;Ljava/util/function/BiFunction;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;R1:Ljava/lang/Object;R2:Ljava/lang/Object;R:Ljava/lang/Object;>(Ljava/util/stream/Collector<-TT;*TR1;>;Ljava/util/stream/Collector<-TT;*TR2;>;Ljava/util/function/BiFunction<-TR1;-TR2;TR;>;)Ljava/util/stream/Collector<TT;*TR;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, teeing, $Collector*, $Collector*, $Collector*, $BiFunction*)},
	{"teeing0", "(Ljava/util/stream/Collector;Ljava/util/stream/Collector;Ljava/util/function/BiFunction;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;A1:Ljava/lang/Object;A2:Ljava/lang/Object;R1:Ljava/lang/Object;R2:Ljava/lang/Object;R:Ljava/lang/Object;>(Ljava/util/stream/Collector<-TT;TA1;TR1;>;Ljava/util/stream/Collector<-TT;TA2;TR2;>;Ljava/util/function/BiFunction<-TR1;-TR2;TR;>;)Ljava/util/stream/Collector<TT;*TR;>;", $PRIVATE | $STATIC, $staticMethod(Collectors, teeing0, $Collector*, $Collector*, $Collector*, $BiFunction*)},
	{"toCollection", "(Ljava/util/function/Supplier;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;C::Ljava/util/Collection<TT;>;>(Ljava/util/function/Supplier<TC;>;)Ljava/util/stream/Collector<TT;*TC;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toCollection, $Collector*, $Supplier*)},
	{"toConcurrentMap", "(Ljava/util/function/Function;Ljava/util/function/Function;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/function/Function<-TT;+TU;>;)Ljava/util/stream/Collector<TT;*Ljava/util/concurrent/ConcurrentMap<TK;TU;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toConcurrentMap, $Collector*, $Function*, $Function*)},
	{"toConcurrentMap", "(Ljava/util/function/Function;Ljava/util/function/Function;Ljava/util/function/BinaryOperator;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/function/Function<-TT;+TU;>;Ljava/util/function/BinaryOperator<TU;>;)Ljava/util/stream/Collector<TT;*Ljava/util/concurrent/ConcurrentMap<TK;TU;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toConcurrentMap, $Collector*, $Function*, $Function*, $BinaryOperator*)},
	{"toConcurrentMap", "(Ljava/util/function/Function;Ljava/util/function/Function;Ljava/util/function/BinaryOperator;Ljava/util/function/Supplier;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;U:Ljava/lang/Object;M::Ljava/util/concurrent/ConcurrentMap<TK;TU;>;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/function/Function<-TT;+TU;>;Ljava/util/function/BinaryOperator<TU;>;Ljava/util/function/Supplier<TM;>;)Ljava/util/stream/Collector<TT;*TM;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toConcurrentMap, $Collector*, $Function*, $Function*, $BinaryOperator*, $Supplier*)},
	{"toList", "()Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>()Ljava/util/stream/Collector<TT;*Ljava/util/List<TT;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toList, $Collector*)},
	{"toMap", "(Ljava/util/function/Function;Ljava/util/function/Function;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/function/Function<-TT;+TU;>;)Ljava/util/stream/Collector<TT;*Ljava/util/Map<TK;TU;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toMap, $Collector*, $Function*, $Function*)},
	{"toMap", "(Ljava/util/function/Function;Ljava/util/function/Function;Ljava/util/function/BinaryOperator;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/function/Function<-TT;+TU;>;Ljava/util/function/BinaryOperator<TU;>;)Ljava/util/stream/Collector<TT;*Ljava/util/Map<TK;TU;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toMap, $Collector*, $Function*, $Function*, $BinaryOperator*)},
	{"toMap", "(Ljava/util/function/Function;Ljava/util/function/Function;Ljava/util/function/BinaryOperator;Ljava/util/function/Supplier;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;U:Ljava/lang/Object;M::Ljava/util/Map<TK;TU;>;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/function/Function<-TT;+TU;>;Ljava/util/function/BinaryOperator<TU;>;Ljava/util/function/Supplier<TM;>;)Ljava/util/stream/Collector<TT;*TM;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toMap, $Collector*, $Function*, $Function*, $BinaryOperator*, $Supplier*)},
	{"toSet", "()Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>()Ljava/util/stream/Collector<TT;*Ljava/util/Set<TT;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toSet, $Collector*)},
	{"toUnmodifiableList", "()Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>()Ljava/util/stream/Collector<TT;*Ljava/util/List<TT;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toUnmodifiableList, $Collector*)},
	{"toUnmodifiableMap", "(Ljava/util/function/Function;Ljava/util/function/Function;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/function/Function<-TT;+TU;>;)Ljava/util/stream/Collector<TT;*Ljava/util/Map<TK;TU;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toUnmodifiableMap, $Collector*, $Function*, $Function*)},
	{"toUnmodifiableMap", "(Ljava/util/function/Function;Ljava/util/function/Function;Ljava/util/function/BinaryOperator;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/function/Function<-TT;+TU;>;Ljava/util/function/BinaryOperator<TU;>;)Ljava/util/stream/Collector<TT;*Ljava/util/Map<TK;TU;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toUnmodifiableMap, $Collector*, $Function*, $Function*, $BinaryOperator*)},
	{"toUnmodifiableSet", "()Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;>()Ljava/util/stream/Collector<TT;*Ljava/util/Set<TT;>;>;", $PUBLIC | $STATIC, $staticMethod(Collectors, toUnmodifiableSet, $Collector*)},
	{"uniqKeysMapAccumulator", "(Ljava/util/function/Function;Ljava/util/function/Function;)Ljava/util/function/BiConsumer;", "<T:Ljava/lang/Object;K:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TK;>;Ljava/util/function/Function<-TT;+TV;>;)Ljava/util/function/BiConsumer<Ljava/util/Map<TK;TV;>;TT;>;", $PRIVATE | $STATIC, $staticMethod(Collectors, uniqKeysMapAccumulator, $BiConsumer*, $Function*, $Function*)},
	{"uniqKeysMapMerger", "()Ljava/util/function/BinaryOperator;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;M::Ljava/util/Map<TK;TV;>;>()Ljava/util/function/BinaryOperator<TM;>;", $PRIVATE | $STATIC, $staticMethod(Collectors, uniqKeysMapMerger, $BinaryOperator*)},
	{}
};

$InnerClassInfo _Collectors_InnerClassesInfo_[] = {
	{"java.util.stream.Collectors$Partition", "java.util.stream.Collectors", "Partition", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Collectors$CollectorImpl", "java.util.stream.Collectors", "CollectorImpl", $STATIC},
	{"java.util.stream.Collectors$1PairBox", nullptr, "PairBox", 0},
	{"java.util.stream.Collectors$1OptionalBox", nullptr, "OptionalBox", 0},
	{}
};

$ClassInfo _Collectors_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.util.stream.Collectors",
	"java.lang.Object",
	nullptr,
	_Collectors_FieldInfo_,
	_Collectors_MethodInfo_,
	nullptr,
	nullptr,
	_Collectors_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.Collectors$Partition,java.util.stream.Collectors$Partition$1,java.util.stream.Collectors$CollectorImpl,java.util.stream.Collectors$1PairBox,java.util.stream.Collectors$1OptionalBox"
};

$Object* allocate$Collectors($Class* clazz) {
	return $of($alloc(Collectors));
}

$Set* Collectors::CH_CONCURRENT_ID = nullptr;
$Set* Collectors::CH_CONCURRENT_NOID = nullptr;
$Set* Collectors::CH_ID = nullptr;
$Set* Collectors::CH_UNORDERED_ID = nullptr;
$Set* Collectors::CH_NOID = nullptr;
$Set* Collectors::CH_UNORDERED_NOID = nullptr;

void Collectors::init$() {
}

$IllegalStateException* Collectors::duplicateKeyException(Object$* k, Object$* u, Object$* v) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	return $new($IllegalStateException, $($String::format("Duplicate key %s (attempted merging values %s and %s)"_s, $$new($ObjectArray, {
		k,
		u,
		v
	}))));
}

$BinaryOperator* Collectors::uniqKeysMapMerger() {
	$init(Collectors);
	return static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$uniqKeysMapMerger$0));
}

$BiConsumer* Collectors::uniqKeysMapAccumulator($Function* keyMapper, $Function* valueMapper) {
	$init(Collectors);
	return static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1, keyMapper, valueMapper));
}

$Function* Collectors::castingIdentity() {
	$init(Collectors);
	return static_cast<$Function*>($new(Collectors$$Lambda$lambda$castingIdentity$2$2));
}

$Collector* Collectors::toCollection($Supplier* collectionFactory) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, collectionFactory);
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$add$3)));
	return $new($Collectors$CollectorImpl, var$0, var$1, static_cast<$BinaryOperator*>($$new(Collectors$$Lambda$lambda$toCollection$3$4)), Collectors::CH_ID);
}

$Collector* Collectors::toList() {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$ArrayList$5)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$add$6)));
	return $new($Collectors$CollectorImpl, var$0, var$1, static_cast<$BinaryOperator*>($$new(Collectors$$Lambda$lambda$toList$4$7)), Collectors::CH_ID);
}

$Collector* Collectors::toUnmodifiableList() {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$ArrayList$5)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$add$6)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$toList$4$7)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$toUnmodifiableList$6$8)), Collectors::CH_NOID);
}

$Collector* Collectors::toSet() {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$HashSet$9)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$add$10)));
	return $new($Collectors$CollectorImpl, var$0, var$1, static_cast<$BinaryOperator*>($$new(Collectors$$Lambda$lambda$toSet$7$11)), Collectors::CH_UNORDERED_ID);
}

$Collector* Collectors::toUnmodifiableSet() {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$HashSet$9)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$add$10)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$toSet$7$11)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$toUnmodifiableSet$9$12)), Collectors::CH_UNORDERED_NOID);
}

$Collector* Collectors::joining() {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$StringBuilder$13)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$append$14)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$joining$10$15)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$toString$16)), Collectors::CH_NOID);
}

$Collector* Collectors::joining($CharSequence* delimiter) {
	$init(Collectors);
	return joining(delimiter, ""_s, ""_s);
}

$Collector* Collectors::joining($CharSequence* delimiter, $CharSequence* prefix, $CharSequence* suffix) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$lambda$joining$11$17, delimiter, prefix, suffix)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$add$18)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$merge$19)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$toString$20)), Collectors::CH_NOID);
}

$BinaryOperator* Collectors::mapMerger($BinaryOperator* mergeFunction) {
	$init(Collectors);
	return static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$mapMerger$12$21, mergeFunction));
}

$Collector* Collectors::mapping($Function* mapper, $Collector* downstream) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($BiConsumer, downstreamAccumulator, $nc(downstream)->accumulator());
	$var($Supplier, var$0, downstream->supplier());
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$mapping$13$22, downstreamAccumulator, mapper)));
	$var($BinaryOperator, var$2, downstream->combiner());
	$var($Function, var$3, downstream->finisher());
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, var$3, $(downstream->characteristics()));
}

$Collector* Collectors::flatMapping($Function* mapper, $Collector* downstream) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($BiConsumer, downstreamAccumulator, $nc(downstream)->accumulator());
	$var($Supplier, var$0, downstream->supplier());
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$flatMapping$15$23, mapper, downstreamAccumulator)));
	$var($BinaryOperator, var$2, downstream->combiner());
	$var($Function, var$3, downstream->finisher());
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, var$3, $(downstream->characteristics()));
}

$Collector* Collectors::filtering($Predicate* predicate, $Collector* downstream) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($BiConsumer, downstreamAccumulator, $nc(downstream)->accumulator());
	$var($Supplier, var$0, downstream->supplier());
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$filtering$16$24, predicate, downstreamAccumulator)));
	$var($BinaryOperator, var$2, downstream->combiner());
	$var($Function, var$3, downstream->finisher());
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, var$3, $(downstream->characteristics()));
}

$Collector* Collectors::collectingAndThen($Collector* downstream, $Function* finisher) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Set, characteristics, $nc(downstream)->characteristics());
	$init($Collector$Characteristics);
	if ($nc(characteristics)->contains($Collector$Characteristics::IDENTITY_FINISH)) {
		if (characteristics->size() == 1) {
			$assign(characteristics, Collectors::CH_NOID);
		} else {
			$assign(characteristics, $EnumSet::copyOf(static_cast<$Collection*>(characteristics)));
			$nc(characteristics)->remove($Collector$Characteristics::IDENTITY_FINISH);
			$assign(characteristics, $Collections::unmodifiableSet(characteristics));
		}
	}
	$var($Supplier, var$0, downstream->supplier());
	$var($BiConsumer, var$1, downstream->accumulator());
	$var($BinaryOperator, var$2, downstream->combiner());
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, $($nc($(downstream->finisher()))->andThen(finisher)), characteristics);
}

$Collector* Collectors::counting() {
	$init(Collectors);
	return summingLong(static_cast<$ToLongFunction*>($$new(Collectors$$Lambda$lambda$counting$17$25)));
}

$Collector* Collectors::minBy($Comparator* comparator) {
	$init(Collectors);
	return reducing($($BinaryOperator::minBy(comparator)));
}

$Collector* Collectors::maxBy($Comparator* comparator) {
	$init(Collectors);
	return reducing($($BinaryOperator::maxBy(comparator)));
}

$Collector* Collectors::summingInt($ToIntFunction* mapper) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$lambda$summingInt$18$26)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$summingInt$19$27, mapper)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$summingInt$20$28)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$summingInt$21$29)), Collectors::CH_NOID);
}

$Collector* Collectors::summingLong($ToLongFunction* mapper) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$lambda$summingLong$22$30)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$summingLong$23$31, mapper)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$summingLong$24$32)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$summingLong$25$33)), Collectors::CH_NOID);
}

$Collector* Collectors::summingDouble($ToDoubleFunction* mapper) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$lambda$summingDouble$26$34)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$summingDouble$27$35, mapper)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$summingDouble$28$36)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$summingDouble$29$37)), Collectors::CH_NOID);
}

$doubles* Collectors::sumWithCompensation($doubles* intermediateSum, double value) {
	$init(Collectors);
	double tmp = value - $nc(intermediateSum)->get(1);
	double sum = intermediateSum->get(0);
	double velvel = sum + tmp;
	intermediateSum->set(1, (velvel - sum) - tmp);
	intermediateSum->set(0, velvel);
	return intermediateSum;
}

double Collectors::computeFinalSum($doubles* summands) {
	$init(Collectors);
	double tmp = $nc(summands)->get(0) + summands->get(1);
	double simpleSum = summands->get(summands->length - 1);
	bool var$0 = $Double::isNaN(tmp);
	if (var$0 && $Double::isInfinite(simpleSum)) {
		return simpleSum;
	} else {
		return tmp;
	}
}

$Collector* Collectors::averagingInt($ToIntFunction* mapper) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$lambda$averagingInt$30$38)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$averagingInt$31$39, mapper)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$averagingInt$32$40)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$averagingInt$33$41)), Collectors::CH_NOID);
}

$Collector* Collectors::averagingLong($ToLongFunction* mapper) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$lambda$averagingInt$30$38)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$averagingLong$35$42, mapper)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$averagingInt$32$40)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$averagingInt$33$41)), Collectors::CH_NOID);
}

$Collector* Collectors::averagingDouble($ToDoubleFunction* mapper) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$lambda$averagingDouble$38$43)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$averagingDouble$39$44, mapper)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$averagingDouble$40$45)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$averagingDouble$41$46)), Collectors::CH_NOID);
}

$Collector* Collectors::reducing(Object$* identity, $BinaryOperator* op) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, boxSupplier(identity));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$reducing$42$47, op)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$reducing$43$48, op)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$reducing$44$49)), Collectors::CH_NOID);
}

$Supplier* Collectors::boxSupplier(Object$* identity) {
	$init(Collectors);
	return static_cast<$Supplier*>($new(Collectors$$Lambda$lambda$boxSupplier$45$50, identity));
}

$Collector* Collectors::reducing($BinaryOperator* op) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	{
	}
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$lambda$reducing$46$51, op)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$accept$52)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$reducing$47$53)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$reducing$48$54)), Collectors::CH_NOID);
}

$Collector* Collectors::reducing(Object$* identity, $Function* mapper, $BinaryOperator* op) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, boxSupplier(identity));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$reducing$49$55, op, mapper)));
	$var($BinaryOperator, var$2, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$reducing$43$48, op)));
	return $new($Collectors$CollectorImpl, var$0, var$1, var$2, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$reducing$44$49)), Collectors::CH_NOID);
}

$Collector* Collectors::groupingBy($Function* classifier) {
	$init(Collectors);
	return groupingBy(classifier, $(toList()));
}

$Collector* Collectors::groupingBy($Function* classifier, $Collector* downstream) {
	$init(Collectors);
	return groupingBy(classifier, static_cast<$Supplier*>($$new(Collectors$$Lambda$HashMap$56)), downstream);
}

$Collector* Collectors::groupingBy($Function* classifier, $Supplier* mapFactory, $Collector* downstream) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, downstreamSupplier, $nc(downstream)->supplier());
	$var($BiConsumer, downstreamAccumulator, downstream->accumulator());
	$var($BiConsumer, accumulator, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$groupingBy$53$57, classifier, downstreamSupplier, downstreamAccumulator)));
	$var($BinaryOperator, merger, Collectors::mapMerger($(downstream->combiner())));
	$var($Supplier, mangledFactory, mapFactory);
	$init($Collector$Characteristics);
	if ($nc($(downstream->characteristics()))->contains($Collector$Characteristics::IDENTITY_FINISH)) {
		return $new($Collectors$CollectorImpl, mangledFactory, accumulator, merger, Collectors::CH_ID);
	} else {
		$var($Function, downstreamFinisher, downstream->finisher());
		$var($Function, finisher, static_cast<$Function*>($new(Collectors$$Lambda$lambda$groupingBy$55$58, downstreamFinisher)));
		return $new($Collectors$CollectorImpl, mangledFactory, accumulator, merger, finisher, Collectors::CH_NOID);
	}
}

$Collector* Collectors::groupingByConcurrent($Function* classifier) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Function, var$0, classifier);
	$var($Supplier, var$1, static_cast<$Supplier*>($new(Collectors$$Lambda$ConcurrentHashMap$59)));
	return groupingByConcurrent(var$0, var$1, $(toList()));
}

$Collector* Collectors::groupingByConcurrent($Function* classifier, $Collector* downstream) {
	$init(Collectors);
	return groupingByConcurrent(classifier, static_cast<$Supplier*>($$new(Collectors$$Lambda$ConcurrentHashMap$59)), downstream);
}

$Collector* Collectors::groupingByConcurrent($Function* classifier, $Supplier* mapFactory, $Collector* downstream) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, downstreamSupplier, $nc(downstream)->supplier());
	$var($BiConsumer, downstreamAccumulator, downstream->accumulator());
	$var($BinaryOperator, merger, Collectors::mapMerger($(downstream->combiner())));
	$var($Supplier, mangledFactory, mapFactory);
	$var($BiConsumer, accumulator, nullptr);
	$init($Collector$Characteristics);
	if ($nc($(downstream->characteristics()))->contains($Collector$Characteristics::CONCURRENT)) {
		$assign(accumulator, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$groupingByConcurrent$57$60, classifier, downstreamSupplier, downstreamAccumulator)));
	} else {
		$assign(accumulator, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$groupingByConcurrent$59$61, classifier, downstreamSupplier, downstreamAccumulator)));
	}
	if ($nc($(downstream->characteristics()))->contains($Collector$Characteristics::IDENTITY_FINISH)) {
		return $new($Collectors$CollectorImpl, mangledFactory, accumulator, merger, Collectors::CH_CONCURRENT_ID);
	} else {
		$var($Function, downstreamFinisher, downstream->finisher());
		$var($Function, finisher, static_cast<$Function*>($new(Collectors$$Lambda$lambda$groupingByConcurrent$61$62, downstreamFinisher)));
		return $new($Collectors$CollectorImpl, mangledFactory, accumulator, merger, finisher, Collectors::CH_CONCURRENT_NOID);
	}
}

$Collector* Collectors::partitioningBy($Predicate* predicate) {
	$init(Collectors);
	return partitioningBy(predicate, $(toList()));
}

$Collector* Collectors::partitioningBy($Predicate* predicate, $Collector* downstream) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($BiConsumer, downstreamAccumulator, $nc(downstream)->accumulator());
	$var($BiConsumer, accumulator, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$partitioningBy$62$63, downstreamAccumulator, predicate)));
	$var($BinaryOperator, op, downstream->combiner());
	$var($BinaryOperator, merger, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$lambda$partitioningBy$63$64, op)));
	$var($Supplier, supplier, static_cast<$Supplier*>($new(Collectors$$Lambda$lambda$partitioningBy$64$65, downstream)));
	$init($Collector$Characteristics);
	if ($nc($(downstream->characteristics()))->contains($Collector$Characteristics::IDENTITY_FINISH)) {
		return $new($Collectors$CollectorImpl, supplier, accumulator, merger, Collectors::CH_ID);
	} else {
		$var($Function, finisher, static_cast<$Function*>($new(Collectors$$Lambda$lambda$partitioningBy$65$66, downstream)));
		return $new($Collectors$CollectorImpl, supplier, accumulator, merger, finisher, Collectors::CH_NOID);
	}
}

$Collector* Collectors::toMap($Function* keyMapper, $Function* valueMapper) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$HashMap$56)));
	$var($BiConsumer, var$1, uniqKeysMapAccumulator(keyMapper, valueMapper));
	return $new($Collectors$CollectorImpl, var$0, var$1, $(uniqKeysMapMerger()), Collectors::CH_ID);
}

$Collector* Collectors::toUnmodifiableMap($Function* keyMapper, $Function* valueMapper) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(keyMapper), "keyMapper"_s);
	$Objects::requireNonNull($of(valueMapper), "valueMapper"_s);
	$var($Collector, var$0, toMap(keyMapper, valueMapper));
	return collectingAndThen(var$0, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$toUnmodifiableMap$66$67)));
}

$Collector* Collectors::toMap($Function* keyMapper, $Function* valueMapper, $BinaryOperator* mergeFunction) {
	$init(Collectors);
	return toMap(keyMapper, valueMapper, mergeFunction, static_cast<$Supplier*>($$new(Collectors$$Lambda$HashMap$56)));
}

$Collector* Collectors::toUnmodifiableMap($Function* keyMapper, $Function* valueMapper, $BinaryOperator* mergeFunction) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(keyMapper), "keyMapper"_s);
	$Objects::requireNonNull($of(valueMapper), "valueMapper"_s);
	$Objects::requireNonNull($of(mergeFunction), "mergeFunction"_s);
	$var($Collector, var$0, toMap(keyMapper, valueMapper, mergeFunction, static_cast<$Supplier*>($$new(Collectors$$Lambda$HashMap$56))));
	return collectingAndThen(var$0, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$toUnmodifiableMap$67$68)));
}

$Collector* Collectors::toMap($Function* keyMapper, $Function* valueMapper, $BinaryOperator* mergeFunction, $Supplier* mapFactory) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($BiConsumer, accumulator, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$toMap$68$69, keyMapper, valueMapper, mergeFunction)));
	return $new($Collectors$CollectorImpl, mapFactory, accumulator, $(mapMerger(mergeFunction)), Collectors::CH_ID);
}

$Collector* Collectors::toConcurrentMap($Function* keyMapper, $Function* valueMapper) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$ConcurrentHashMap$59)));
	$var($BiConsumer, var$1, uniqKeysMapAccumulator(keyMapper, valueMapper));
	return $new($Collectors$CollectorImpl, var$0, var$1, $(uniqKeysMapMerger()), Collectors::CH_CONCURRENT_ID);
}

$Collector* Collectors::toConcurrentMap($Function* keyMapper, $Function* valueMapper, $BinaryOperator* mergeFunction) {
	$init(Collectors);
	return toConcurrentMap(keyMapper, valueMapper, mergeFunction, static_cast<$Supplier*>($$new(Collectors$$Lambda$ConcurrentHashMap$59)));
}

$Collector* Collectors::toConcurrentMap($Function* keyMapper, $Function* valueMapper, $BinaryOperator* mergeFunction, $Supplier* mapFactory) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($BiConsumer, accumulator, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$toConcurrentMap$69$70, keyMapper, valueMapper, mergeFunction)));
	return $new($Collectors$CollectorImpl, mapFactory, accumulator, $(mapMerger(mergeFunction)), Collectors::CH_CONCURRENT_ID);
}

$Collector* Collectors::summarizingInt($ToIntFunction* mapper) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$IntSummaryStatistics$71)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$summarizingInt$70$72, mapper)));
	return $new($Collectors$CollectorImpl, var$0, var$1, static_cast<$BinaryOperator*>($$new(Collectors$$Lambda$lambda$summarizingInt$71$73)), Collectors::CH_ID);
}

$Collector* Collectors::summarizingLong($ToLongFunction* mapper) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$LongSummaryStatistics$74)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$summarizingLong$72$75, mapper)));
	return $new($Collectors$CollectorImpl, var$0, var$1, static_cast<$BinaryOperator*>($$new(Collectors$$Lambda$lambda$summarizingLong$73$76)), Collectors::CH_ID);
}

$Collector* Collectors::summarizingDouble($ToDoubleFunction* mapper) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Collectors$$Lambda$DoubleSummaryStatistics$77)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(Collectors$$Lambda$lambda$summarizingDouble$74$78, mapper)));
	return $new($Collectors$CollectorImpl, var$0, var$1, static_cast<$BinaryOperator*>($$new(Collectors$$Lambda$lambda$summarizingDouble$75$79)), Collectors::CH_ID);
}

$Collector* Collectors::teeing($Collector* downstream1, $Collector* downstream2, $BiFunction* merger) {
	$init(Collectors);
	return teeing0(downstream1, downstream2, merger);
}

$Collector* Collectors::teeing0($Collector* downstream1, $Collector* downstream2, $BiFunction* merger) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(downstream1), "downstream1"_s);
	$Objects::requireNonNull($of(downstream2), "downstream2"_s);
	$Objects::requireNonNull($of(merger), "merger"_s);
	$var($Supplier, c1Supplier, $cast($Supplier, $Objects::requireNonNull($($of($nc(downstream1)->supplier())), "downstream1 supplier"_s)));
	$var($Supplier, c2Supplier, $cast($Supplier, $Objects::requireNonNull($($of($nc(downstream2)->supplier())), "downstream2 supplier"_s)));
	$var($BiConsumer, c1Accumulator, $cast($BiConsumer, $Objects::requireNonNull($($of($nc(downstream1)->accumulator())), "downstream1 accumulator"_s)));
	$var($BiConsumer, c2Accumulator, $cast($BiConsumer, $Objects::requireNonNull($($of($nc(downstream2)->accumulator())), "downstream2 accumulator"_s)));
	$var($BinaryOperator, c1Combiner, $cast($BinaryOperator, $Objects::requireNonNull($($of($nc(downstream1)->combiner())), "downstream1 combiner"_s)));
	$var($BinaryOperator, c2Combiner, $cast($BinaryOperator, $Objects::requireNonNull($($of($nc(downstream2)->combiner())), "downstream2 combiner"_s)));
	$var($Function, c1Finisher, $cast($Function, $Objects::requireNonNull($($of($nc(downstream1)->finisher())), "downstream1 finisher"_s)));
	$var($Function, c2Finisher, $cast($Function, $Objects::requireNonNull($($of($nc(downstream2)->finisher())), "downstream2 finisher"_s)));
	$var($Set, characteristics, nullptr);
	$var($Set, c1Characteristics, $nc(downstream1)->characteristics());
	$var($Set, c2Characteristics, $nc(downstream2)->characteristics());
	bool var$0 = $nc(Collectors::CH_ID)->containsAll(c1Characteristics);
	if (var$0 || $nc(Collectors::CH_ID)->containsAll(c2Characteristics)) {
		$assign(characteristics, Collectors::CH_NOID);
	} else {
		$load($Collector$Characteristics);
		$var($EnumSet, c, $EnumSet::noneOf($Collector$Characteristics::class$));
		$nc(c)->addAll(c1Characteristics);
		c->retainAll(c2Characteristics);
		$init($Collector$Characteristics);
		c->remove($Collector$Characteristics::IDENTITY_FINISH);
		$assign(characteristics, $Collections::unmodifiableSet(c));
	}
	{
	}
	$var($Supplier, var$1, static_cast<$Supplier*>($new(Collectors$$Lambda$lambda$teeing0$76$80, c1Supplier, c2Supplier, c1Accumulator, c2Accumulator, c1Combiner, c2Combiner, c1Finisher, c2Finisher, merger)));
	$var($BiConsumer, var$2, static_cast<$BiConsumer*>($new(Collectors$$Lambda$add$81)));
	$var($BinaryOperator, var$3, static_cast<$BinaryOperator*>($new(Collectors$$Lambda$combine$82)));
	return $new($Collectors$CollectorImpl, var$1, var$2, var$3, static_cast<$Function*>($$new(Collectors$$Lambda$get$83)), characteristics);
}

$Collectors$1PairBox* Collectors::lambda$teeing0$76($Supplier* c1Supplier, $Supplier* c2Supplier, $BiConsumer* c1Accumulator, $BiConsumer* c2Accumulator, $BinaryOperator* c1Combiner, $BinaryOperator* c2Combiner, $Function* c1Finisher, $Function* c2Finisher, $BiFunction* merger) {
	$init(Collectors);
	return $new($Collectors$1PairBox, c1Supplier, c2Supplier, c1Accumulator, c2Accumulator, c1Combiner, c2Combiner, c1Finisher, c2Finisher, merger);
}

$DoubleSummaryStatistics* Collectors::lambda$summarizingDouble$75($DoubleSummaryStatistics* l, $DoubleSummaryStatistics* r) {
	$init(Collectors);
	$nc(l)->combine(r);
	return l;
}

void Collectors::lambda$summarizingDouble$74($ToDoubleFunction* mapper, $DoubleSummaryStatistics* r, Object$* t) {
	$init(Collectors);
	$nc(r)->accept($nc(mapper)->applyAsDouble(t));
}

$LongSummaryStatistics* Collectors::lambda$summarizingLong$73($LongSummaryStatistics* l, $LongSummaryStatistics* r) {
	$init(Collectors);
	$nc(l)->combine(r);
	return l;
}

void Collectors::lambda$summarizingLong$72($ToLongFunction* mapper, $LongSummaryStatistics* r, Object$* t) {
	$init(Collectors);
	$nc(r)->accept($nc(mapper)->applyAsLong(t));
}

$IntSummaryStatistics* Collectors::lambda$summarizingInt$71($IntSummaryStatistics* l, $IntSummaryStatistics* r) {
	$init(Collectors);
	$nc(l)->combine(r);
	return l;
}

void Collectors::lambda$summarizingInt$70($ToIntFunction* mapper, $IntSummaryStatistics* r, Object$* t) {
	$init(Collectors);
	$nc(r)->accept($nc(mapper)->applyAsInt(t));
}

void Collectors::lambda$toConcurrentMap$69($Function* keyMapper, $Function* valueMapper, $BinaryOperator* mergeFunction, $ConcurrentMap* map, Object$* element) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $nc(keyMapper)->apply(element));
	$nc(map)->merge(var$0, $($nc(valueMapper)->apply(element)), mergeFunction);
}

void Collectors::lambda$toMap$68($Function* keyMapper, $Function* valueMapper, $BinaryOperator* mergeFunction, $Map* map, Object$* element) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $nc(keyMapper)->apply(element));
	$nc(map)->merge(var$0, $($nc(valueMapper)->apply(element)), mergeFunction);
}

$Map* Collectors::lambda$toUnmodifiableMap$67($HashMap* map) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	return $Map::ofEntries($fcast($Map$EntryArray, $($nc($($nc(map)->entrySet()))->toArray($$new($Map$EntryArray, 0)))));
}

$Map* Collectors::lambda$toUnmodifiableMap$66($Map* map) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	return $Map::ofEntries($fcast($Map$EntryArray, $($nc($($nc(map)->entrySet()))->toArray($$new($Map$EntryArray, 0)))));
}

$Map* Collectors::lambda$partitioningBy$65($Collector* downstream, $Collectors$Partition* par) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $nc($($nc(downstream)->finisher()))->apply($nc(par)->forTrue));
	return $new($Collectors$Partition, var$0, $($nc($(downstream->finisher()))->apply($nc(par)->forFalse)));
}

$Collectors$Partition* Collectors::lambda$partitioningBy$64($Collector* downstream) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $nc($($nc(downstream)->supplier()))->get());
	return $new($Collectors$Partition, var$0, $($nc($(downstream->supplier()))->get()));
}

$Collectors$Partition* Collectors::lambda$partitioningBy$63($BinaryOperator* op, $Collectors$Partition* left, $Collectors$Partition* right) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $nc(op)->apply($nc(left)->forTrue, $nc(right)->forTrue));
	return $new($Collectors$Partition, var$0, $(op->apply($nc(left)->forFalse, $nc(right)->forFalse)));
}

void Collectors::lambda$partitioningBy$62($BiConsumer* downstreamAccumulator, $Predicate* predicate, $Collectors$Partition* result, Object$* t) {
	$init(Collectors);
	$nc(downstreamAccumulator)->accept($nc(predicate)->test(t) ? $nc(result)->forTrue : result->forFalse, t);
}

$ConcurrentMap* Collectors::lambda$groupingByConcurrent$61($Function* downstreamFinisher, $ConcurrentMap* intermediate) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$nc(intermediate)->replaceAll(static_cast<$BiFunction*>($$new(Collectors$$Lambda$lambda$groupingBy$54$84, downstreamFinisher)));
	$var($ConcurrentMap, castResult, intermediate);
	return castResult;
}

void Collectors::lambda$groupingByConcurrent$59($Function* classifier, $Supplier* downstreamSupplier, $BiConsumer* downstreamAccumulator, $ConcurrentMap* m, Object$* t) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Object, key, $Objects::requireNonNull($($nc(classifier)->apply(t)), "element cannot be mapped to a null key"_s));
	$var($Object, resultContainer, $nc(m)->computeIfAbsent(key, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$groupingBy$52$85, downstreamSupplier))));
	$synchronized(resultContainer) {
		$nc(downstreamAccumulator)->accept(resultContainer, t);
	}
}

void Collectors::lambda$groupingByConcurrent$57($Function* classifier, $Supplier* downstreamSupplier, $BiConsumer* downstreamAccumulator, $ConcurrentMap* m, Object$* t) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Object, key, $Objects::requireNonNull($($nc(classifier)->apply(t)), "element cannot be mapped to a null key"_s));
	$var($Object, resultContainer, $nc(m)->computeIfAbsent(key, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$groupingBy$52$85, downstreamSupplier))));
	$nc(downstreamAccumulator)->accept(resultContainer, t);
}

$Map* Collectors::lambda$groupingBy$55($Function* downstreamFinisher, $Map* intermediate) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$nc(intermediate)->replaceAll(static_cast<$BiFunction*>($$new(Collectors$$Lambda$lambda$groupingBy$54$84, downstreamFinisher)));
	$var($Map, castResult, intermediate);
	return castResult;
}

$Object* Collectors::lambda$groupingBy$54($Function* downstreamFinisher, Object$* k, Object$* v) {
	$init(Collectors);
	return $of($nc(downstreamFinisher)->apply(v));
}

void Collectors::lambda$groupingBy$53($Function* classifier, $Supplier* downstreamSupplier, $BiConsumer* downstreamAccumulator, $Map* m, Object$* t) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Object, key, $Objects::requireNonNull($($nc(classifier)->apply(t)), "element cannot be mapped to a null key"_s));
	$var($Object, container, $nc(m)->computeIfAbsent(key, static_cast<$Function*>($$new(Collectors$$Lambda$lambda$groupingBy$52$85, downstreamSupplier))));
	$nc(downstreamAccumulator)->accept(container, t);
}

$Object* Collectors::lambda$groupingBy$52($Supplier* downstreamSupplier, Object$* k) {
	$init(Collectors);
	return $of($nc(downstreamSupplier)->get());
}

void Collectors::lambda$reducing$49($BinaryOperator* op, $Function* mapper, $ObjectArray* a, Object$* t) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$nc(a)->set(0, $($nc(op)->apply(a->get(0), $($nc(mapper)->apply(t)))));
}

$Optional* Collectors::lambda$reducing$48($Collectors$1OptionalBox* a) {
	$init(Collectors);
	return $Optional::ofNullable($nc(a)->value);
}

$Collectors$1OptionalBox* Collectors::lambda$reducing$47($Collectors$1OptionalBox* a, $Collectors$1OptionalBox* b) {
	$init(Collectors);
	if ($nc(b)->present) {
		$nc(a)->accept(b->value);
	}
	return a;
}

$Collectors$1OptionalBox* Collectors::lambda$reducing$46($BinaryOperator* op) {
	$init(Collectors);
	return $new($Collectors$1OptionalBox, op);
}

$ObjectArray* Collectors::lambda$boxSupplier$45(Object$* identity) {
	$init(Collectors);
	return $new($ObjectArray, {identity});
}

$Object* Collectors::lambda$reducing$44($ObjectArray* a) {
	$init(Collectors);
	return $of($nc(a)->get(0));
}

$ObjectArray* Collectors::lambda$reducing$43($BinaryOperator* op, $ObjectArray* a, $ObjectArray* b) {
	$init(Collectors);
	$nc(a)->set(0, $($nc(op)->apply(a->get(0), $nc(b)->get(0))));
	return a;
}

void Collectors::lambda$reducing$42($BinaryOperator* op, $ObjectArray* a, Object$* t) {
	$init(Collectors);
	$nc(a)->set(0, $($nc(op)->apply(a->get(0), t)));
}

$Double* Collectors::lambda$averagingDouble$41($doubles* a) {
	$init(Collectors);
	return $Double::valueOf(($nc(a)->get(2) == 0) ? 0.0 : (computeFinalSum(a) / $nc(a)->get(2)));
}

$doubles* Collectors::lambda$averagingDouble$40($doubles* a, $doubles* b) {
	$init(Collectors);
	sumWithCompensation(a, $nc(b)->get(0));
	sumWithCompensation(a, $nc(b)->get(1));
	(*$nc(a))[2] += $nc(b)->get(2);
	(*a)[3] += b->get(3);
	return a;
}

void Collectors::lambda$averagingDouble$39($ToDoubleFunction* mapper, $doubles* a, Object$* t) {
	$init(Collectors);
	double val = $nc(mapper)->applyAsDouble(t);
	sumWithCompensation(a, val);
	++(*$nc(a))[2];
	(*a)[3] += val;
}

$doubles* Collectors::lambda$averagingDouble$38() {
	$init(Collectors);
	return $new($doubles, 4);
}

void Collectors::lambda$averagingLong$35($ToLongFunction* mapper, $longs* a, Object$* t) {
	$init(Collectors);
	(*$nc(a))[0] += $nc(mapper)->applyAsLong(t);
	++(*a)[1];
}

$Double* Collectors::lambda$averagingInt$33($longs* a) {
	$init(Collectors);
	return $Double::valueOf(($nc(a)->get(1) == 0) ? 0.0 : (double)$nc(a)->get(0) / a->get(1));
}

$longs* Collectors::lambda$averagingInt$32($longs* a, $longs* b) {
	$init(Collectors);
	(*$nc(a))[0] += $nc(b)->get(0);
	(*a)[1] += b->get(1);
	return a;
}

void Collectors::lambda$averagingInt$31($ToIntFunction* mapper, $longs* a, Object$* t) {
	$init(Collectors);
	(*$nc(a))[0] += $nc(mapper)->applyAsInt(t);
	++(*a)[1];
}

$longs* Collectors::lambda$averagingInt$30() {
	$init(Collectors);
	return $new($longs, 2);
}

$Double* Collectors::lambda$summingDouble$29($doubles* a) {
	$init(Collectors);
	return $Double::valueOf(computeFinalSum(a));
}

$doubles* Collectors::lambda$summingDouble$28($doubles* a, $doubles* b) {
	$init(Collectors);
	sumWithCompensation(a, $nc(b)->get(0));
	(*$nc(a))[2] += $nc(b)->get(2);
	return sumWithCompensation(a, b->get(1));
}

void Collectors::lambda$summingDouble$27($ToDoubleFunction* mapper, $doubles* a, Object$* t) {
	$init(Collectors);
	double val = $nc(mapper)->applyAsDouble(t);
	sumWithCompensation(a, val);
	(*$nc(a))[2] += val;
}

$doubles* Collectors::lambda$summingDouble$26() {
	$init(Collectors);
	return $new($doubles, 3);
}

$Long* Collectors::lambda$summingLong$25($longs* a) {
	$init(Collectors);
	return $Long::valueOf($nc(a)->get(0));
}

$longs* Collectors::lambda$summingLong$24($longs* a, $longs* b) {
	$init(Collectors);
	(*$nc(a))[0] += $nc(b)->get(0);
	return a;
}

void Collectors::lambda$summingLong$23($ToLongFunction* mapper, $longs* a, Object$* t) {
	$init(Collectors);
	(*$nc(a))[0] += $nc(mapper)->applyAsLong(t);
}

$longs* Collectors::lambda$summingLong$22() {
	$init(Collectors);
	return $new($longs, 1);
}

$Integer* Collectors::lambda$summingInt$21($ints* a) {
	$init(Collectors);
	return $Integer::valueOf($nc(a)->get(0));
}

$ints* Collectors::lambda$summingInt$20($ints* a, $ints* b) {
	$init(Collectors);
	(*$nc(a))[0] += $nc(b)->get(0);
	return a;
}

void Collectors::lambda$summingInt$19($ToIntFunction* mapper, $ints* a, Object$* t) {
	$init(Collectors);
	(*$nc(a))[0] += $nc(mapper)->applyAsInt(t);
}

$ints* Collectors::lambda$summingInt$18() {
	$init(Collectors);
	return $new($ints, 1);
}

int64_t Collectors::lambda$counting$17(Object$* e) {
	$init(Collectors);
	return 1;
}

void Collectors::lambda$filtering$16($Predicate* predicate, $BiConsumer* downstreamAccumulator, Object$* r, Object$* t) {
	$init(Collectors);
	if ($nc(predicate)->test(t)) {
		$nc(downstreamAccumulator)->accept(r, t);
	}
}

void Collectors::lambda$flatMapping$15($Function* mapper, $BiConsumer* downstreamAccumulator, Object$* r, Object$* t) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	{
		$var($Stream, result, $cast($Stream, $nc(mapper)->apply(t)));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					if (result != nullptr) {
						$nc(($cast($Stream, $(result->sequential()))))->forEach(static_cast<$Consumer*>($$new(Collectors$$Lambda$lambda$flatMapping$14$86, downstreamAccumulator, r)));
					}
				} catch ($Throwable& t$) {
					if (result != nullptr) {
						try {
							result->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				if (result != nullptr) {
					result->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void Collectors::lambda$flatMapping$14($BiConsumer* downstreamAccumulator, Object$* r, Object$* u) {
	$init(Collectors);
	$nc(downstreamAccumulator)->accept(r, u);
}

void Collectors::lambda$mapping$13($BiConsumer* downstreamAccumulator, $Function* mapper, Object$* r, Object$* t) {
	$init(Collectors);
	$nc(downstreamAccumulator)->accept(r, $($nc(mapper)->apply(t)));
}

$Map* Collectors::lambda$mapMerger$12($BinaryOperator* mergeFunction, $Map* m1, $Map* m2) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(m2)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			$var($Object, var$0, $nc(e)->getKey());
			$nc(m1)->merge(var$0, $(e->getValue()), mergeFunction);
		}
	}
	return m1;
}

$StringJoiner* Collectors::lambda$joining$11($CharSequence* delimiter, $CharSequence* prefix, $CharSequence* suffix) {
	$init(Collectors);
	return $new($StringJoiner, delimiter, prefix, suffix);
}

$StringBuilder* Collectors::lambda$joining$10($StringBuilder* r1, $StringBuilder* r2) {
	$init(Collectors);
	$nc(r1)->append(static_cast<$CharSequence*>(r2));
	return r1;
}

$Set* Collectors::lambda$toUnmodifiableSet$9($HashSet* set) {
	$init(Collectors);
	return $Set::of($($nc(set)->toArray()));
}

$HashSet* Collectors::lambda$toSet$7($HashSet* left, $HashSet* right) {
	$init(Collectors);
	int32_t var$0 = $nc(left)->size();
	if (var$0 < $nc(right)->size()) {
		right->addAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(left))));
		return right;
	} else {
		left->addAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(right))));
		return left;
	}
}

$List* Collectors::lambda$toUnmodifiableList$6($ArrayList* list) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$load($ArrayList);
	if ($nc($of(list))->getClass() == $ArrayList::class$) {
		return $nc($($SharedSecrets::getJavaUtilCollectionAccess()))->listFromTrustedArray($(list->toArray()));
	} else {
		$throwNew($IllegalArgumentException);
	}
}

$ArrayList* Collectors::lambda$toList$4($ArrayList* left, $ArrayList* right) {
	$init(Collectors);
	$nc(left)->addAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>(right))));
	return left;
}

$Collection* Collectors::lambda$toCollection$3($Collection* r1, $Collection* r2) {
	$init(Collectors);
	$nc(r1)->addAll(r2);
	return r1;
}

$Object* Collectors::lambda$castingIdentity$2(Object$* i) {
	$init(Collectors);
	return $of(i);
}

void Collectors::lambda$uniqKeysMapAccumulator$1($Function* keyMapper, $Function* valueMapper, $Map* map, Object$* element) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	$var($Object, k, $nc(keyMapper)->apply(element));
	$var($Object, v, $Objects::requireNonNull($($nc(valueMapper)->apply(element))));
	$var($Object, u, $nc(map)->putIfAbsent(k, v));
	if (u != nullptr) {
		$throw($(duplicateKeyException(k, u, v)));
	}
}

$Map* Collectors::lambda$uniqKeysMapMerger$0($Map* m1, $Map* m2) {
	$init(Collectors);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(m2)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($Object, k, $nc(e)->getKey());
				$var($Object, v, $Objects::requireNonNull($(e->getValue())));
				$var($Object, u, $nc(m1)->putIfAbsent(k, v));
				if (u != nullptr) {
					$throw($(duplicateKeyException(k, u, v)));
				}
			}
		}
	}
	return m1;
}

void clinit$Collectors($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$init($Collector$Characteristics);
	$assignStatic(Collectors::CH_CONCURRENT_ID, $Collections::unmodifiableSet($($EnumSet::of($Collector$Characteristics::CONCURRENT, $Collector$Characteristics::UNORDERED, $Collector$Characteristics::IDENTITY_FINISH))));
	$assignStatic(Collectors::CH_CONCURRENT_NOID, $Collections::unmodifiableSet($($EnumSet::of(static_cast<$Enum*>($Collector$Characteristics::CONCURRENT), static_cast<$Enum*>($Collector$Characteristics::UNORDERED)))));
	$assignStatic(Collectors::CH_ID, $Collections::unmodifiableSet($($EnumSet::of($Collector$Characteristics::IDENTITY_FINISH))));
	$assignStatic(Collectors::CH_UNORDERED_ID, $Collections::unmodifiableSet($($EnumSet::of(static_cast<$Enum*>($Collector$Characteristics::UNORDERED), static_cast<$Enum*>($Collector$Characteristics::IDENTITY_FINISH)))));
	$assignStatic(Collectors::CH_NOID, $Collections::emptySet());
	$assignStatic(Collectors::CH_UNORDERED_NOID, $Collections::unmodifiableSet($($EnumSet::of($Collector$Characteristics::UNORDERED))));
}

Collectors::Collectors() {
}

$Class* Collectors::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Collectors$$Lambda$lambda$uniqKeysMapMerger$0::classInfo$.name)) {
			return Collectors$$Lambda$lambda$uniqKeysMapMerger$0::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1::classInfo$.name)) {
			return Collectors$$Lambda$lambda$uniqKeysMapAccumulator$1$1::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$castingIdentity$2$2::classInfo$.name)) {
			return Collectors$$Lambda$lambda$castingIdentity$2$2::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$add$3::classInfo$.name)) {
			return Collectors$$Lambda$add$3::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$toCollection$3$4::classInfo$.name)) {
			return Collectors$$Lambda$lambda$toCollection$3$4::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$ArrayList$5::classInfo$.name)) {
			return Collectors$$Lambda$ArrayList$5::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$add$6::classInfo$.name)) {
			return Collectors$$Lambda$add$6::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$toList$4$7::classInfo$.name)) {
			return Collectors$$Lambda$lambda$toList$4$7::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$toUnmodifiableList$6$8::classInfo$.name)) {
			return Collectors$$Lambda$lambda$toUnmodifiableList$6$8::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$HashSet$9::classInfo$.name)) {
			return Collectors$$Lambda$HashSet$9::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$add$10::classInfo$.name)) {
			return Collectors$$Lambda$add$10::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$toSet$7$11::classInfo$.name)) {
			return Collectors$$Lambda$lambda$toSet$7$11::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$toUnmodifiableSet$9$12::classInfo$.name)) {
			return Collectors$$Lambda$lambda$toUnmodifiableSet$9$12::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$StringBuilder$13::classInfo$.name)) {
			return Collectors$$Lambda$StringBuilder$13::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$append$14::classInfo$.name)) {
			return Collectors$$Lambda$append$14::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$joining$10$15::classInfo$.name)) {
			return Collectors$$Lambda$lambda$joining$10$15::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$toString$16::classInfo$.name)) {
			return Collectors$$Lambda$toString$16::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$joining$11$17::classInfo$.name)) {
			return Collectors$$Lambda$lambda$joining$11$17::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$add$18::classInfo$.name)) {
			return Collectors$$Lambda$add$18::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$merge$19::classInfo$.name)) {
			return Collectors$$Lambda$merge$19::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$toString$20::classInfo$.name)) {
			return Collectors$$Lambda$toString$20::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$mapMerger$12$21::classInfo$.name)) {
			return Collectors$$Lambda$lambda$mapMerger$12$21::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$mapping$13$22::classInfo$.name)) {
			return Collectors$$Lambda$lambda$mapping$13$22::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$flatMapping$15$23::classInfo$.name)) {
			return Collectors$$Lambda$lambda$flatMapping$15$23::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$filtering$16$24::classInfo$.name)) {
			return Collectors$$Lambda$lambda$filtering$16$24::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$counting$17$25::classInfo$.name)) {
			return Collectors$$Lambda$lambda$counting$17$25::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summingInt$18$26::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summingInt$18$26::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summingInt$19$27::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summingInt$19$27::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summingInt$20$28::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summingInt$20$28::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summingInt$21$29::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summingInt$21$29::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summingLong$22$30::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summingLong$22$30::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summingLong$23$31::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summingLong$23$31::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summingLong$24$32::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summingLong$24$32::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summingLong$25$33::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summingLong$25$33::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summingDouble$26$34::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summingDouble$26$34::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summingDouble$27$35::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summingDouble$27$35::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summingDouble$28$36::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summingDouble$28$36::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summingDouble$29$37::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summingDouble$29$37::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$averagingInt$30$38::classInfo$.name)) {
			return Collectors$$Lambda$lambda$averagingInt$30$38::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$averagingInt$31$39::classInfo$.name)) {
			return Collectors$$Lambda$lambda$averagingInt$31$39::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$averagingInt$32$40::classInfo$.name)) {
			return Collectors$$Lambda$lambda$averagingInt$32$40::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$averagingInt$33$41::classInfo$.name)) {
			return Collectors$$Lambda$lambda$averagingInt$33$41::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$averagingLong$35$42::classInfo$.name)) {
			return Collectors$$Lambda$lambda$averagingLong$35$42::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$averagingDouble$38$43::classInfo$.name)) {
			return Collectors$$Lambda$lambda$averagingDouble$38$43::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$averagingDouble$39$44::classInfo$.name)) {
			return Collectors$$Lambda$lambda$averagingDouble$39$44::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$averagingDouble$40$45::classInfo$.name)) {
			return Collectors$$Lambda$lambda$averagingDouble$40$45::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$averagingDouble$41$46::classInfo$.name)) {
			return Collectors$$Lambda$lambda$averagingDouble$41$46::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$reducing$42$47::classInfo$.name)) {
			return Collectors$$Lambda$lambda$reducing$42$47::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$reducing$43$48::classInfo$.name)) {
			return Collectors$$Lambda$lambda$reducing$43$48::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$reducing$44$49::classInfo$.name)) {
			return Collectors$$Lambda$lambda$reducing$44$49::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$boxSupplier$45$50::classInfo$.name)) {
			return Collectors$$Lambda$lambda$boxSupplier$45$50::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$reducing$46$51::classInfo$.name)) {
			return Collectors$$Lambda$lambda$reducing$46$51::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$accept$52::classInfo$.name)) {
			return Collectors$$Lambda$accept$52::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$reducing$47$53::classInfo$.name)) {
			return Collectors$$Lambda$lambda$reducing$47$53::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$reducing$48$54::classInfo$.name)) {
			return Collectors$$Lambda$lambda$reducing$48$54::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$reducing$49$55::classInfo$.name)) {
			return Collectors$$Lambda$lambda$reducing$49$55::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$HashMap$56::classInfo$.name)) {
			return Collectors$$Lambda$HashMap$56::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$groupingBy$53$57::classInfo$.name)) {
			return Collectors$$Lambda$lambda$groupingBy$53$57::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$groupingBy$55$58::classInfo$.name)) {
			return Collectors$$Lambda$lambda$groupingBy$55$58::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$ConcurrentHashMap$59::classInfo$.name)) {
			return Collectors$$Lambda$ConcurrentHashMap$59::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$groupingByConcurrent$57$60::classInfo$.name)) {
			return Collectors$$Lambda$lambda$groupingByConcurrent$57$60::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$groupingByConcurrent$59$61::classInfo$.name)) {
			return Collectors$$Lambda$lambda$groupingByConcurrent$59$61::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$groupingByConcurrent$61$62::classInfo$.name)) {
			return Collectors$$Lambda$lambda$groupingByConcurrent$61$62::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$partitioningBy$62$63::classInfo$.name)) {
			return Collectors$$Lambda$lambda$partitioningBy$62$63::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$partitioningBy$63$64::classInfo$.name)) {
			return Collectors$$Lambda$lambda$partitioningBy$63$64::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$partitioningBy$64$65::classInfo$.name)) {
			return Collectors$$Lambda$lambda$partitioningBy$64$65::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$partitioningBy$65$66::classInfo$.name)) {
			return Collectors$$Lambda$lambda$partitioningBy$65$66::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$toUnmodifiableMap$66$67::classInfo$.name)) {
			return Collectors$$Lambda$lambda$toUnmodifiableMap$66$67::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$toUnmodifiableMap$67$68::classInfo$.name)) {
			return Collectors$$Lambda$lambda$toUnmodifiableMap$67$68::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$toMap$68$69::classInfo$.name)) {
			return Collectors$$Lambda$lambda$toMap$68$69::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$toConcurrentMap$69$70::classInfo$.name)) {
			return Collectors$$Lambda$lambda$toConcurrentMap$69$70::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$IntSummaryStatistics$71::classInfo$.name)) {
			return Collectors$$Lambda$IntSummaryStatistics$71::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summarizingInt$70$72::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summarizingInt$70$72::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summarizingInt$71$73::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summarizingInt$71$73::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$LongSummaryStatistics$74::classInfo$.name)) {
			return Collectors$$Lambda$LongSummaryStatistics$74::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summarizingLong$72$75::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summarizingLong$72$75::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summarizingLong$73$76::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summarizingLong$73$76::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$DoubleSummaryStatistics$77::classInfo$.name)) {
			return Collectors$$Lambda$DoubleSummaryStatistics$77::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summarizingDouble$74$78::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summarizingDouble$74$78::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$summarizingDouble$75$79::classInfo$.name)) {
			return Collectors$$Lambda$lambda$summarizingDouble$75$79::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$teeing0$76$80::classInfo$.name)) {
			return Collectors$$Lambda$lambda$teeing0$76$80::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$add$81::classInfo$.name)) {
			return Collectors$$Lambda$add$81::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$combine$82::classInfo$.name)) {
			return Collectors$$Lambda$combine$82::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$get$83::classInfo$.name)) {
			return Collectors$$Lambda$get$83::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$groupingBy$54$84::classInfo$.name)) {
			return Collectors$$Lambda$lambda$groupingBy$54$84::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$groupingBy$52$85::classInfo$.name)) {
			return Collectors$$Lambda$lambda$groupingBy$52$85::load$(name, initialize);
		}
		if (name->equals(Collectors$$Lambda$lambda$flatMapping$14$86::classInfo$.name)) {
			return Collectors$$Lambda$lambda$flatMapping$14$86::load$(name, initialize);
		}
	}
	$loadClass(Collectors, name, initialize, &_Collectors_ClassInfo_, clinit$Collectors, allocate$Collectors);
	return class$;
}

$Class* Collectors::class$ = nullptr;

		} // stream
	} // util
} // java