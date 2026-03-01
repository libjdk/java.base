#include <java/util/Comparator.h>

#include <java/io/Serializable.h>
#include <java/lang/Comparable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/SerializedLambda.h>
#include <java/util/Collections.h>
#include <java/util/Comparators$NaturalOrderComparator.h>
#include <java/util/Comparators$NullComparator.h>
#include <java/util/Objects.h>
#include <java/util/function/Function.h>
#include <java/util/function/ToDoubleFunction.h>
#include <java/util/function/ToIntFunction.h>
#include <java/util/function/ToLongFunction.h>
#include <jcpp.h>

#undef INSTANCE

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Comparable = ::java::lang::Comparable;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $SerializedLambda = ::java::lang::invoke::SerializedLambda;
using $Collections = ::java::util::Collections;
using $Comparators$NaturalOrderComparator = ::java::util::Comparators$NaturalOrderComparator;
using $Comparators$NullComparator = ::java::util::Comparators$NullComparator;
using $Objects = ::java::util::Objects;
using $Function = ::java::util::function::Function;
using $ToDoubleFunction = ::java::util::function::ToDoubleFunction;
using $ToIntFunction = ::java::util::function::ToIntFunction;
using $ToLongFunction = ::java::util::function::ToLongFunction;

namespace java {
	namespace util {

class Comparator$$Lambda$lambda$thenComparing$36697e65$1 : public Comparator, public $Serializable {
	$class(Comparator$$Lambda$lambda$thenComparing$36697e65$1, $NO_CLASS_INIT, Comparator, $Serializable)
public:
	void init$(Comparator* inst, Comparator* other) {
		$set(this, inst$, inst);
		$set(this, other, other);
	}
	virtual int32_t compare(Object$* c1, Object$* c2) override {
		 return $nc(inst$)->lambda$thenComparing$36697e65$1(other, c1, c2);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Comparator$$Lambda$lambda$thenComparing$36697e65$1>());
	}
	Comparator* inst$ = nullptr;
	Comparator* other = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Comparator$$Lambda$lambda$thenComparing$36697e65$1::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Comparator$$Lambda$lambda$thenComparing$36697e65$1, inst$)},
	{"other", "Ljava/util/Comparator;", nullptr, $PUBLIC, $field(Comparator$$Lambda$lambda$thenComparing$36697e65$1, other)},
	{}
};
$MethodInfo Comparator$$Lambda$lambda$thenComparing$36697e65$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Comparator;Ljava/util/Comparator;)V", nullptr, $PUBLIC, $method(Comparator$$Lambda$lambda$thenComparing$36697e65$1, init$, void, Comparator*, Comparator*)},
	{"compare", "(Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(Comparator$$Lambda$lambda$thenComparing$36697e65$1, compare, int32_t, Object$*, Object$*)},
	{}
};
$ClassInfo Comparator$$Lambda$lambda$thenComparing$36697e65$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Comparator$$Lambda$lambda$thenComparing$36697e65$1",
	"java.lang.Object",
	"java.util.Comparator,java.io.Serializable",
	fieldInfos,
	methodInfos
};
$Class* Comparator$$Lambda$lambda$thenComparing$36697e65$1::load$($String* name, bool initialize) {
	$loadClass(Comparator$$Lambda$lambda$thenComparing$36697e65$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Comparator$$Lambda$lambda$thenComparing$36697e65$1::class$ = nullptr;

class Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1 : public Comparator, public $Serializable {
	$class(Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1, $NO_CLASS_INIT, Comparator, $Serializable)
public:
	void init$(Comparator* keyComparator, $Function* keyExtractor) {
		$set(this, keyComparator, keyComparator);
		$set(this, keyExtractor, keyExtractor);
	}
	virtual int32_t compare(Object$* c1, Object$* c2) override {
		 return Comparator::lambda$comparing$ea9a8b3a$1(keyComparator, keyExtractor, c1, c2);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1>());
	}
	Comparator* keyComparator = nullptr;
	$Function* keyExtractor = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1::fieldInfos[3] = {
	{"keyComparator", "Ljava/util/Comparator;", nullptr, $PUBLIC, $field(Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1, keyComparator)},
	{"keyExtractor", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1, keyExtractor)},
	{}
};
$MethodInfo Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Comparator;Ljava/util/function/Function;)V", nullptr, $PUBLIC, $method(Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1, init$, void, Comparator*, $Function*)},
	{"compare", "(Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1, compare, int32_t, Object$*, Object$*)},
	{}
};
$ClassInfo Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1",
	"java.lang.Object",
	"java.util.Comparator,java.io.Serializable",
	fieldInfos,
	methodInfos
};
$Class* Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1::load$($String* name, bool initialize) {
	$loadClass(Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1::class$ = nullptr;

class Comparator$$Lambda$lambda$comparing$77a9974f$1$2 : public Comparator, public $Serializable {
	$class(Comparator$$Lambda$lambda$comparing$77a9974f$1$2, $NO_CLASS_INIT, Comparator, $Serializable)
public:
	void init$($Function* keyExtractor) {
		$set(this, keyExtractor, keyExtractor);
	}
	virtual int32_t compare(Object$* c1, Object$* c2) override {
		 return Comparator::lambda$comparing$77a9974f$1(keyExtractor, c1, c2);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Comparator$$Lambda$lambda$comparing$77a9974f$1$2>());
	}
	$Function* keyExtractor = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Comparator$$Lambda$lambda$comparing$77a9974f$1$2::fieldInfos[2] = {
	{"keyExtractor", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Comparator$$Lambda$lambda$comparing$77a9974f$1$2, keyExtractor)},
	{}
};
$MethodInfo Comparator$$Lambda$lambda$comparing$77a9974f$1$2::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Function;)V", nullptr, $PUBLIC, $method(Comparator$$Lambda$lambda$comparing$77a9974f$1$2, init$, void, $Function*)},
	{"compare", "(Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(Comparator$$Lambda$lambda$comparing$77a9974f$1$2, compare, int32_t, Object$*, Object$*)},
	{}
};
$ClassInfo Comparator$$Lambda$lambda$comparing$77a9974f$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Comparator$$Lambda$lambda$comparing$77a9974f$1$2",
	"java.lang.Object",
	"java.util.Comparator,java.io.Serializable",
	fieldInfos,
	methodInfos
};
$Class* Comparator$$Lambda$lambda$comparing$77a9974f$1$2::load$($String* name, bool initialize) {
	$loadClass(Comparator$$Lambda$lambda$comparing$77a9974f$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Comparator$$Lambda$lambda$comparing$77a9974f$1$2::class$ = nullptr;

class Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3 : public Comparator, public $Serializable {
	$class(Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3, $NO_CLASS_INIT, Comparator, $Serializable)
public:
	void init$($ToIntFunction* keyExtractor) {
		$set(this, keyExtractor, keyExtractor);
	}
	virtual int32_t compare(Object$* c1, Object$* c2) override {
		 return Comparator::lambda$comparingInt$7b0bb60$1(keyExtractor, c1, c2);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3>());
	}
	$ToIntFunction* keyExtractor = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3::fieldInfos[2] = {
	{"keyExtractor", "Ljava/util/function/ToIntFunction;", nullptr, $PUBLIC, $field(Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3, keyExtractor)},
	{}
};
$MethodInfo Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/ToIntFunction;)V", nullptr, $PUBLIC, $method(Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3, init$, void, $ToIntFunction*)},
	{"compare", "(Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3, compare, int32_t, Object$*, Object$*)},
	{}
};
$ClassInfo Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3",
	"java.lang.Object",
	"java.util.Comparator,java.io.Serializable",
	fieldInfos,
	methodInfos
};
$Class* Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3::load$($String* name, bool initialize) {
	$loadClass(Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3::class$ = nullptr;

class Comparator$$Lambda$lambda$comparingLong$6043328a$1$4 : public Comparator, public $Serializable {
	$class(Comparator$$Lambda$lambda$comparingLong$6043328a$1$4, $NO_CLASS_INIT, Comparator, $Serializable)
public:
	void init$($ToLongFunction* keyExtractor) {
		$set(this, keyExtractor, keyExtractor);
	}
	virtual int32_t compare(Object$* c1, Object$* c2) override {
		 return Comparator::lambda$comparingLong$6043328a$1(keyExtractor, c1, c2);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Comparator$$Lambda$lambda$comparingLong$6043328a$1$4>());
	}
	$ToLongFunction* keyExtractor = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Comparator$$Lambda$lambda$comparingLong$6043328a$1$4::fieldInfos[2] = {
	{"keyExtractor", "Ljava/util/function/ToLongFunction;", nullptr, $PUBLIC, $field(Comparator$$Lambda$lambda$comparingLong$6043328a$1$4, keyExtractor)},
	{}
};
$MethodInfo Comparator$$Lambda$lambda$comparingLong$6043328a$1$4::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/ToLongFunction;)V", nullptr, $PUBLIC, $method(Comparator$$Lambda$lambda$comparingLong$6043328a$1$4, init$, void, $ToLongFunction*)},
	{"compare", "(Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(Comparator$$Lambda$lambda$comparingLong$6043328a$1$4, compare, int32_t, Object$*, Object$*)},
	{}
};
$ClassInfo Comparator$$Lambda$lambda$comparingLong$6043328a$1$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Comparator$$Lambda$lambda$comparingLong$6043328a$1$4",
	"java.lang.Object",
	"java.util.Comparator,java.io.Serializable",
	fieldInfos,
	methodInfos
};
$Class* Comparator$$Lambda$lambda$comparingLong$6043328a$1$4::load$($String* name, bool initialize) {
	$loadClass(Comparator$$Lambda$lambda$comparingLong$6043328a$1$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Comparator$$Lambda$lambda$comparingLong$6043328a$1$4::class$ = nullptr;

class Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5 : public Comparator, public $Serializable {
	$class(Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5, $NO_CLASS_INIT, Comparator, $Serializable)
public:
	void init$($ToDoubleFunction* keyExtractor) {
		$set(this, keyExtractor, keyExtractor);
	}
	virtual int32_t compare(Object$* c1, Object$* c2) override {
		 return Comparator::lambda$comparingDouble$8dcf42ea$1(keyExtractor, c1, c2);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5>());
	}
	$ToDoubleFunction* keyExtractor = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5::fieldInfos[2] = {
	{"keyExtractor", "Ljava/util/function/ToDoubleFunction;", nullptr, $PUBLIC, $field(Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5, keyExtractor)},
	{}
};
$MethodInfo Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/ToDoubleFunction;)V", nullptr, $PUBLIC, $method(Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5, init$, void, $ToDoubleFunction*)},
	{"compare", "(Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5, compare, int32_t, Object$*, Object$*)},
	{}
};
$ClassInfo Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5",
	"java.lang.Object",
	"java.util.Comparator,java.io.Serializable",
	fieldInfos,
	methodInfos
};
$Class* Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5::load$($String* name, bool initialize) {
	$loadClass(Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5::class$ = nullptr;

$CompoundAttribute _Comparator_Annotations_[] = {
	{"Ljava/lang/FunctionalInterface;", nullptr},
	{}
};

$MethodInfo _Comparator_MethodInfo_[] = {
	{"$deserializeLambda$", "(Ljava/lang/invoke/SerializedLambda;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Comparator, $deserializeLambda$, $Object*, $SerializedLambda*)},
	{"compare", "(Ljava/lang/Object;Ljava/lang/Object;)I", "(TT;TT;)I", $PUBLIC | $ABSTRACT, $virtualMethod(Comparator, compare, int32_t, Object$*, Object$*)},
	{"comparing", "(Ljava/util/function/Function;Ljava/util/Comparator;)Ljava/util/Comparator;", "<T:Ljava/lang/Object;U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TU;>;Ljava/util/Comparator<-TU;>;)Ljava/util/Comparator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Comparator, comparing, Comparator*, $Function*, Comparator*)},
	{"comparing", "(Ljava/util/function/Function;)Ljava/util/Comparator;", "<T:Ljava/lang/Object;U::Ljava/lang/Comparable<-TU;>;>(Ljava/util/function/Function<-TT;+TU;>;)Ljava/util/Comparator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Comparator, comparing, Comparator*, $Function*)},
	{"comparingDouble", "(Ljava/util/function/ToDoubleFunction;)Ljava/util/Comparator;", "<T:Ljava/lang/Object;>(Ljava/util/function/ToDoubleFunction<-TT;>;)Ljava/util/Comparator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Comparator, comparingDouble, Comparator*, $ToDoubleFunction*)},
	{"comparingInt", "(Ljava/util/function/ToIntFunction;)Ljava/util/Comparator;", "<T:Ljava/lang/Object;>(Ljava/util/function/ToIntFunction<-TT;>;)Ljava/util/Comparator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Comparator, comparingInt, Comparator*, $ToIntFunction*)},
	{"comparingLong", "(Ljava/util/function/ToLongFunction;)Ljava/util/Comparator;", "<T:Ljava/lang/Object;>(Ljava/util/function/ToLongFunction<-TT;>;)Ljava/util/Comparator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Comparator, comparingLong, Comparator*, $ToLongFunction*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"lambda$comparing$77a9974f$1", "(Ljava/util/function/Function;Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Comparator, lambda$comparing$77a9974f$1, int32_t, $Function*, Object$*, Object$*)},
	{"lambda$comparing$ea9a8b3a$1", "(Ljava/util/Comparator;Ljava/util/function/Function;Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Comparator, lambda$comparing$ea9a8b3a$1, int32_t, Comparator*, $Function*, Object$*, Object$*)},
	{"lambda$comparingDouble$8dcf42ea$1", "(Ljava/util/function/ToDoubleFunction;Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Comparator, lambda$comparingDouble$8dcf42ea$1, int32_t, $ToDoubleFunction*, Object$*, Object$*)},
	{"lambda$comparingInt$7b0bb60$1", "(Ljava/util/function/ToIntFunction;Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Comparator, lambda$comparingInt$7b0bb60$1, int32_t, $ToIntFunction*, Object$*, Object$*)},
	{"lambda$comparingLong$6043328a$1", "(Ljava/util/function/ToLongFunction;Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Comparator, lambda$comparingLong$6043328a$1, int32_t, $ToLongFunction*, Object$*, Object$*)},
	{"lambda$thenComparing$36697e65$1", "(Ljava/util/Comparator;Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PRIVATE | $SYNTHETIC, $method(Comparator, lambda$thenComparing$36697e65$1, int32_t, Comparator*, Object$*, Object$*)},
	{"naturalOrder", "()Ljava/util/Comparator;", "<T::Ljava/lang/Comparable<-TT;>;>()Ljava/util/Comparator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Comparator, naturalOrder, Comparator*)},
	{"nullsFirst", "(Ljava/util/Comparator;)Ljava/util/Comparator;", "<T:Ljava/lang/Object;>(Ljava/util/Comparator<-TT;>;)Ljava/util/Comparator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Comparator, nullsFirst, Comparator*, Comparator*)},
	{"nullsLast", "(Ljava/util/Comparator;)Ljava/util/Comparator;", "<T:Ljava/lang/Object;>(Ljava/util/Comparator<-TT;>;)Ljava/util/Comparator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Comparator, nullsLast, Comparator*, Comparator*)},
	{"reverseOrder", "()Ljava/util/Comparator;", "<T::Ljava/lang/Comparable<-TT;>;>()Ljava/util/Comparator<TT;>;", $PUBLIC | $STATIC, $staticMethod(Comparator, reverseOrder, Comparator*)},
	{"reversed", "()Ljava/util/Comparator;", "()Ljava/util/Comparator<TT;>;", $PUBLIC, $virtualMethod(Comparator, reversed, Comparator*)},
	{"thenComparing", "(Ljava/util/Comparator;)Ljava/util/Comparator;", "(Ljava/util/Comparator<-TT;>;)Ljava/util/Comparator<TT;>;", $PUBLIC, $virtualMethod(Comparator, thenComparing, Comparator*, Comparator*)},
	{"thenComparing", "(Ljava/util/function/Function;Ljava/util/Comparator;)Ljava/util/Comparator;", "<U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TU;>;Ljava/util/Comparator<-TU;>;)Ljava/util/Comparator<TT;>;", $PUBLIC, $virtualMethod(Comparator, thenComparing, Comparator*, $Function*, Comparator*)},
	{"thenComparing", "(Ljava/util/function/Function;)Ljava/util/Comparator;", "<U::Ljava/lang/Comparable<-TU;>;>(Ljava/util/function/Function<-TT;+TU;>;)Ljava/util/Comparator<TT;>;", $PUBLIC, $virtualMethod(Comparator, thenComparing, Comparator*, $Function*)},
	{"thenComparingDouble", "(Ljava/util/function/ToDoubleFunction;)Ljava/util/Comparator;", "(Ljava/util/function/ToDoubleFunction<-TT;>;)Ljava/util/Comparator<TT;>;", $PUBLIC, $virtualMethod(Comparator, thenComparingDouble, Comparator*, $ToDoubleFunction*)},
	{"thenComparingInt", "(Ljava/util/function/ToIntFunction;)Ljava/util/Comparator;", "(Ljava/util/function/ToIntFunction<-TT;>;)Ljava/util/Comparator<TT;>;", $PUBLIC, $virtualMethod(Comparator, thenComparingInt, Comparator*, $ToIntFunction*)},
	{"thenComparingLong", "(Ljava/util/function/ToLongFunction;)Ljava/util/Comparator;", "(Ljava/util/function/ToLongFunction<-TT;>;)Ljava/util/Comparator<TT;>;", $PUBLIC, $virtualMethod(Comparator, thenComparingLong, Comparator*, $ToLongFunction*)},
	{}
};

$ClassInfo _Comparator_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.Comparator",
	nullptr,
	nullptr,
	nullptr,
	_Comparator_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	nullptr,
	_Comparator_Annotations_
};

$Object* allocate$Comparator($Class* clazz) {
	return $of($alloc(Comparator));
}

bool Comparator::equals(Object$* obj) {
	 return this->$Object::equals(obj);
}

Comparator* Comparator::reversed() {
	return $Collections::reverseOrder(this);
}

Comparator* Comparator::thenComparing(Comparator* other) {
	$Objects::requireNonNull(other);
	return $cast(Comparator, $cast($Serializable, static_cast<Comparator*>($new(Comparator$$Lambda$lambda$thenComparing$36697e65$1, this, other))));
}

Comparator* Comparator::thenComparing($Function* keyExtractor, Comparator* keyComparator) {
	return thenComparing($(comparing(keyExtractor, keyComparator)));
}

Comparator* Comparator::thenComparing($Function* keyExtractor) {
	return thenComparing($(comparing(keyExtractor)));
}

Comparator* Comparator::thenComparingInt($ToIntFunction* keyExtractor) {
	return thenComparing($(comparingInt(keyExtractor)));
}

Comparator* Comparator::thenComparingLong($ToLongFunction* keyExtractor) {
	return thenComparing($(comparingLong(keyExtractor)));
}

Comparator* Comparator::thenComparingDouble($ToDoubleFunction* keyExtractor) {
	return thenComparing($(comparingDouble(keyExtractor)));
}

Comparator* Comparator::reverseOrder() {
	return $Collections::reverseOrder();
}

Comparator* Comparator::naturalOrder() {
	$init($Comparators$NaturalOrderComparator);
	return static_cast<Comparator*>($Comparators$NaturalOrderComparator::INSTANCE);
}

Comparator* Comparator::nullsFirst(Comparator* comparator) {
	return $new($Comparators$NullComparator, true, comparator);
}

Comparator* Comparator::nullsLast(Comparator* comparator) {
	return $new($Comparators$NullComparator, false, comparator);
}

Comparator* Comparator::comparing($Function* keyExtractor, Comparator* keyComparator) {
	$Objects::requireNonNull(keyExtractor);
	$Objects::requireNonNull(keyComparator);
	return $cast(Comparator, $cast($Serializable, static_cast<Comparator*>($new(Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1, keyComparator, keyExtractor))));
}

Comparator* Comparator::comparing($Function* keyExtractor) {
	$Objects::requireNonNull(keyExtractor);
	return $cast(Comparator, $cast($Serializable, static_cast<Comparator*>($new(Comparator$$Lambda$lambda$comparing$77a9974f$1$2, keyExtractor))));
}

Comparator* Comparator::comparingInt($ToIntFunction* keyExtractor) {
	$Objects::requireNonNull(keyExtractor);
	return $cast(Comparator, $cast($Serializable, static_cast<Comparator*>($new(Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3, keyExtractor))));
}

Comparator* Comparator::comparingLong($ToLongFunction* keyExtractor) {
	$Objects::requireNonNull(keyExtractor);
	return $cast(Comparator, $cast($Serializable, static_cast<Comparator*>($new(Comparator$$Lambda$lambda$comparingLong$6043328a$1$4, keyExtractor))));
}

Comparator* Comparator::comparingDouble($ToDoubleFunction* keyExtractor) {
	$Objects::requireNonNull(keyExtractor);
	return $cast(Comparator, $cast($Serializable, static_cast<Comparator*>($new(Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5, keyExtractor))));
}

$Object* Comparator::$deserializeLambda$($SerializedLambda* lambda) {
	$useLocalCurrentObjectStackCache();
	{
		$var($String, s5472$, $nc(lambda)->getImplMethodName());
		int32_t tmp5472$ = -1;
		switch ($nc(s5472$)->hashCode()) {
		case (int32_t)0xCA32E4F1:
			{
				if (s5472$->equals("lambda$comparingLong$6043328a$1"_s)) {
					tmp5472$ = 0;
				}
				break;
			}
		case (int32_t)0xDE5D85E8:
			{
				if (s5472$->equals("lambda$comparing$ea9a8b3a$1"_s)) {
					tmp5472$ = 1;
				}
				break;
			}
		case (int32_t)0x9C7E29F4:
			{
				if (s5472$->equals("lambda$comparing$77a9974f$1"_s)) {
					tmp5472$ = 2;
				}
				break;
			}
		case 0x75184C64:
			{
				if (s5472$->equals("lambda$comparingDouble$8dcf42ea$1"_s)) {
					tmp5472$ = 3;
				}
				break;
			}
		case (int32_t)0xCCB1D0FC:
			{
				if (s5472$->equals("lambda$thenComparing$36697e65$1"_s)) {
					tmp5472$ = 4;
				}
				break;
			}
		case 0x313F0992:
			{
				if (s5472$->equals("lambda$comparingInt$7b0bb60$1"_s)) {
					tmp5472$ = 5;
				}
				break;
			}
		}
		switch (tmp5472$) {
		case 0:
			{
				bool var$4 = lambda->getImplMethodKind() == 6;
				bool var$3 = var$4 && $nc($of($(lambda->getFunctionalInterfaceClass())))->equals("java/util/Comparator"_s);
				bool var$2 = var$3 && $nc($of($(lambda->getFunctionalInterfaceMethodName())))->equals("compare"_s);
				bool var$1 = var$2 && $nc($of($(lambda->getFunctionalInterfaceMethodSignature())))->equals("(Ljava/lang/Object;Ljava/lang/Object;)I"_s);
				bool var$0 = var$1 && $nc($of($(lambda->getImplClass())))->equals("java/util/Comparator"_s);
				if (var$0 && $nc($of($(lambda->getImplMethodSignature())))->equals("(Ljava/util/function/ToLongFunction;Ljava/lang/Object;Ljava/lang/Object;)I"_s)) {
					return $of(static_cast<Comparator*>($new(Comparator$$Lambda$lambda$comparingLong$6043328a$1$4, $cast($ToLongFunction, $(lambda->getCapturedArg(0))))));
				}
				break;
			}
		case 1:
			{
				bool var$9 = lambda->getImplMethodKind() == 6;
				bool var$8 = var$9 && $nc($of($(lambda->getFunctionalInterfaceClass())))->equals("java/util/Comparator"_s);
				bool var$7 = var$8 && $nc($of($(lambda->getFunctionalInterfaceMethodName())))->equals("compare"_s);
				bool var$6 = var$7 && $nc($of($(lambda->getFunctionalInterfaceMethodSignature())))->equals("(Ljava/lang/Object;Ljava/lang/Object;)I"_s);
				bool var$5 = var$6 && $nc($of($(lambda->getImplClass())))->equals("java/util/Comparator"_s);
				if (var$5 && $nc($of($(lambda->getImplMethodSignature())))->equals("(Ljava/util/Comparator;Ljava/util/function/Function;Ljava/lang/Object;Ljava/lang/Object;)I"_s)) {
					$var(Comparator, var$10, $cast(Comparator, lambda->getCapturedArg(0)));
					return $of(static_cast<Comparator*>($new(Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1, var$10, $cast($Function, $(lambda->getCapturedArg(1))))));
				}
				break;
			}
		case 2:
			{
				bool var$15 = lambda->getImplMethodKind() == 6;
				bool var$14 = var$15 && $nc($of($(lambda->getFunctionalInterfaceClass())))->equals("java/util/Comparator"_s);
				bool var$13 = var$14 && $nc($of($(lambda->getFunctionalInterfaceMethodName())))->equals("compare"_s);
				bool var$12 = var$13 && $nc($of($(lambda->getFunctionalInterfaceMethodSignature())))->equals("(Ljava/lang/Object;Ljava/lang/Object;)I"_s);
				bool var$11 = var$12 && $nc($of($(lambda->getImplClass())))->equals("java/util/Comparator"_s);
				if (var$11 && $nc($of($(lambda->getImplMethodSignature())))->equals("(Ljava/util/function/Function;Ljava/lang/Object;Ljava/lang/Object;)I"_s)) {
					return $of(static_cast<Comparator*>($new(Comparator$$Lambda$lambda$comparing$77a9974f$1$2, $cast($Function, $(lambda->getCapturedArg(0))))));
				}
				break;
			}
		case 3:
			{
				bool var$20 = lambda->getImplMethodKind() == 6;
				bool var$19 = var$20 && $nc($of($(lambda->getFunctionalInterfaceClass())))->equals("java/util/Comparator"_s);
				bool var$18 = var$19 && $nc($of($(lambda->getFunctionalInterfaceMethodName())))->equals("compare"_s);
				bool var$17 = var$18 && $nc($of($(lambda->getFunctionalInterfaceMethodSignature())))->equals("(Ljava/lang/Object;Ljava/lang/Object;)I"_s);
				bool var$16 = var$17 && $nc($of($(lambda->getImplClass())))->equals("java/util/Comparator"_s);
				if (var$16 && $nc($of($(lambda->getImplMethodSignature())))->equals("(Ljava/util/function/ToDoubleFunction;Ljava/lang/Object;Ljava/lang/Object;)I"_s)) {
					return $of(static_cast<Comparator*>($new(Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5, $cast($ToDoubleFunction, $(lambda->getCapturedArg(0))))));
				}
				break;
			}
		case 4:
			{
				bool var$25 = lambda->getImplMethodKind() == 9;
				bool var$24 = var$25 && $nc($of($(lambda->getFunctionalInterfaceClass())))->equals("java/util/Comparator"_s);
				bool var$23 = var$24 && $nc($of($(lambda->getFunctionalInterfaceMethodName())))->equals("compare"_s);
				bool var$22 = var$23 && $nc($of($(lambda->getFunctionalInterfaceMethodSignature())))->equals("(Ljava/lang/Object;Ljava/lang/Object;)I"_s);
				bool var$21 = var$22 && $nc($of($(lambda->getImplClass())))->equals("java/util/Comparator"_s);
				if (var$21 && $nc($of($(lambda->getImplMethodSignature())))->equals("(Ljava/util/Comparator;Ljava/lang/Object;Ljava/lang/Object;)I"_s)) {
					$var(Comparator, var$26, $cast(Comparator, lambda->getCapturedArg(0)));
					return $of(static_cast<Comparator*>($new(Comparator$$Lambda$lambda$thenComparing$36697e65$1, var$26, $cast(Comparator, $(lambda->getCapturedArg(1))))));
				}
				break;
			}
		case 5:
			{
				bool var$31 = lambda->getImplMethodKind() == 6;
				bool var$30 = var$31 && $nc($of($(lambda->getFunctionalInterfaceClass())))->equals("java/util/Comparator"_s);
				bool var$29 = var$30 && $nc($of($(lambda->getFunctionalInterfaceMethodName())))->equals("compare"_s);
				bool var$28 = var$29 && $nc($of($(lambda->getFunctionalInterfaceMethodSignature())))->equals("(Ljava/lang/Object;Ljava/lang/Object;)I"_s);
				bool var$27 = var$28 && $nc($of($(lambda->getImplClass())))->equals("java/util/Comparator"_s);
				if (var$27 && $nc($of($(lambda->getImplMethodSignature())))->equals("(Ljava/util/function/ToIntFunction;Ljava/lang/Object;Ljava/lang/Object;)I"_s)) {
					return $of(static_cast<Comparator*>($new(Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3, $cast($ToIntFunction, $(lambda->getCapturedArg(0))))));
				}
				break;
			}
		}
	}
	$throwNew($IllegalArgumentException, "Invalid lambda deserialization"_s);
}

int32_t Comparator::lambda$comparingDouble$8dcf42ea$1($ToDoubleFunction* keyExtractor, Object$* c1, Object$* c2) {
	double var$0 = $nc(keyExtractor)->applyAsDouble(c1);
	return $Double::compare(var$0, keyExtractor->applyAsDouble(c2));
}

int32_t Comparator::lambda$comparingLong$6043328a$1($ToLongFunction* keyExtractor, Object$* c1, Object$* c2) {
	int64_t var$0 = $nc(keyExtractor)->applyAsLong(c1);
	return $Long::compare(var$0, keyExtractor->applyAsLong(c2));
}

int32_t Comparator::lambda$comparingInt$7b0bb60$1($ToIntFunction* keyExtractor, Object$* c1, Object$* c2) {
	int32_t var$0 = $nc(keyExtractor)->applyAsInt(c1);
	return $Integer::compare(var$0, keyExtractor->applyAsInt(c2));
}

int32_t Comparator::lambda$comparing$77a9974f$1($Function* keyExtractor, Object$* c1, Object$* c2) {
	$useLocalCurrentObjectStackCache();
	return $nc(($cast($Comparable, $($nc(keyExtractor)->apply(c1)))))->compareTo($(keyExtractor->apply(c2)));
}

int32_t Comparator::lambda$comparing$ea9a8b3a$1(Comparator* keyComparator, $Function* keyExtractor, Object$* c1, Object$* c2) {
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $nc(keyExtractor)->apply(c1));
	return $nc(keyComparator)->compare(var$0, $(keyExtractor->apply(c2)));
}

int32_t Comparator::lambda$thenComparing$36697e65$1(Comparator* other, Object$* c1, Object$* c2) {
	int32_t res = compare(c1, c2);
	return (res != 0) ? res : $nc(other)->compare(c1, c2);
}

$Class* Comparator::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Comparator$$Lambda$lambda$thenComparing$36697e65$1::classInfo$.name)) {
			return Comparator$$Lambda$lambda$thenComparing$36697e65$1::load$(name, initialize);
		}
		if (name->equals(Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1::classInfo$.name)) {
			return Comparator$$Lambda$lambda$comparing$ea9a8b3a$1$1::load$(name, initialize);
		}
		if (name->equals(Comparator$$Lambda$lambda$comparing$77a9974f$1$2::classInfo$.name)) {
			return Comparator$$Lambda$lambda$comparing$77a9974f$1$2::load$(name, initialize);
		}
		if (name->equals(Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3::classInfo$.name)) {
			return Comparator$$Lambda$lambda$comparingInt$7b0bb60$1$3::load$(name, initialize);
		}
		if (name->equals(Comparator$$Lambda$lambda$comparingLong$6043328a$1$4::classInfo$.name)) {
			return Comparator$$Lambda$lambda$comparingLong$6043328a$1$4::load$(name, initialize);
		}
		if (name->equals(Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5::classInfo$.name)) {
			return Comparator$$Lambda$lambda$comparingDouble$8dcf42ea$1$5::load$(name, initialize);
		}
	}
	$loadClass(Comparator, name, initialize, &_Comparator_ClassInfo_, allocate$Comparator);
	return class$;
}

$Class* Comparator::class$ = nullptr;

	} // util
} // java