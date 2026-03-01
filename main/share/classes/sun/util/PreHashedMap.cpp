#include <sun/util/PreHashedMap.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/util/AbstractMap.h>
#include <java/util/Set.h>
#include <sun/util/PreHashedMap$1.h>
#include <sun/util/PreHashedMap$2.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $AbstractMap = ::java::util::AbstractMap;
using $Set = ::java::util::Set;
using $PreHashedMap$1 = ::sun::util::PreHashedMap$1;
using $PreHashedMap$2 = ::sun::util::PreHashedMap$2;

namespace sun {
	namespace util {

$FieldInfo _PreHashedMap_FieldInfo_[] = {
	{"rows", "I", nullptr, $PRIVATE | $FINAL, $field(PreHashedMap, rows)},
	{"size", "I", nullptr, $PRIVATE | $FINAL, $field(PreHashedMap, size$)},
	{"shift", "I", nullptr, $PRIVATE | $FINAL, $field(PreHashedMap, shift)},
	{"mask", "I", nullptr, $PRIVATE | $FINAL, $field(PreHashedMap, mask)},
	{"ht", "[Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(PreHashedMap, ht)},
	{}
};

$MethodInfo _PreHashedMap_MethodInfo_[] = {
	{"<init>", "(IIII)V", nullptr, $PROTECTED, $method(PreHashedMap, init$, void, int32_t, int32_t, int32_t, int32_t)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<Ljava/lang/String;TV;>;>;", $PUBLIC, $virtualMethod(PreHashedMap, entrySet, $Set*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(PreHashedMap, get, $Object*, Object$*)},
	{"init", "([Ljava/lang/Object;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(PreHashedMap, init, void, $ObjectArray*)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(PreHashedMap, keySet, $Set*)},
	{"put", "(Ljava/lang/String;Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/String;TV;)TV;", $PUBLIC, $virtualMethod(PreHashedMap, put, $Object*, $String*, Object$*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(PreHashedMap, put, $Object*, Object$*, Object$*)},
	{"toV", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PRIVATE, $method(PreHashedMap, toV, $Object*, Object$*)},
	{}
};

$InnerClassInfo _PreHashedMap_InnerClassesInfo_[] = {
	{"sun.util.PreHashedMap$2", nullptr, nullptr, 0},
	{"sun.util.PreHashedMap$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _PreHashedMap_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.util.PreHashedMap",
	"java.util.AbstractMap",
	nullptr,
	_PreHashedMap_FieldInfo_,
	_PreHashedMap_MethodInfo_,
	"<V:Ljava/lang/Object;>Ljava/util/AbstractMap<Ljava/lang/String;TV;>;",
	nullptr,
	_PreHashedMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.PreHashedMap$2,sun.util.PreHashedMap$2$1,sun.util.PreHashedMap$2$1$1,sun.util.PreHashedMap$1,sun.util.PreHashedMap$1$1"
};

$Object* allocate$PreHashedMap($Class* clazz) {
	return $of($alloc(PreHashedMap));
}

void PreHashedMap::init$(int32_t rows, int32_t size, int32_t shift, int32_t mask) {
	$AbstractMap::init$();
	this->rows = rows;
	this->size$ = size;
	this->shift = shift;
	this->mask = mask;
	$set(this, ht, $new($ObjectArray, rows));
	init(this->ht);
}

$Object* PreHashedMap::toV(Object$* x) {
	return $of(x);
}

$Object* PreHashedMap::get(Object$* k) {
	int32_t h = (int32_t)(($sr($nc($of(k))->hashCode(), this->shift)) & (uint32_t)this->mask);
	$var($ObjectArray, a, $cast($ObjectArray, $nc(this->ht)->get(h)));
	if (a == nullptr) {
		return $of(nullptr);
	}
	for (;;) {
		if ($nc($of($nc(a)->get(0)))->equals(k)) {
			return $of(toV(a->get(1)));
		}
		if ($nc(a)->length < 3) {
			return $of(nullptr);
		}
		$assign(a, $cast($ObjectArray, $nc(a)->get(2)));
	}
}

$Object* PreHashedMap::put($String* k, Object$* v) {
	$useLocalCurrentObjectStackCache();
	int32_t h = (int32_t)(($sr($nc(k)->hashCode(), this->shift)) & (uint32_t)this->mask);
	$var($ObjectArray, a, $cast($ObjectArray, $nc(this->ht)->get(h)));
	if (a == nullptr) {
		$throwNew($UnsupportedOperationException, k);
	}
	for (;;) {
		if ($nc($of($nc(a)->get(0)))->equals(k)) {
			$var($Object, ov, toV(a->get(1)));
			a->set(1, v);
			return $of(ov);
		}
		if ($nc(a)->length < 3) {
			$throwNew($UnsupportedOperationException, k);
		}
		$assign(a, $cast($ObjectArray, $nc(a)->get(2)));
	}
}

$Set* PreHashedMap::keySet() {
	return $new($PreHashedMap$1, this);
}

$Set* PreHashedMap::entrySet() {
	return $new($PreHashedMap$2, this);
}

$Object* PreHashedMap::put(Object$* k, Object$* v) {
	return $of(this->put($cast($String, k), v));
}

PreHashedMap::PreHashedMap() {
}

$Class* PreHashedMap::load$($String* name, bool initialize) {
	$loadClass(PreHashedMap, name, initialize, &_PreHashedMap_ClassInfo_, allocate$PreHashedMap);
	return class$;
}

$Class* PreHashedMap::class$ = nullptr;

	} // util
} // sun