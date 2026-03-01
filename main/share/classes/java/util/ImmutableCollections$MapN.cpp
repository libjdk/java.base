#include <java/util/ImmutableCollections$MapN.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/util/CollSer.h>
#include <java/util/ImmutableCollections$AbstractImmutableMap.h>
#include <java/util/ImmutableCollections$MapN$1.h>
#include <java/util/ImmutableCollections.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef IMM_MAP

using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $CollSer = ::java::util::CollSer;
using $ImmutableCollections$AbstractImmutableMap = ::java::util::ImmutableCollections$AbstractImmutableMap;
using $ImmutableCollections$MapN$1 = ::java::util::ImmutableCollections$MapN$1;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;

namespace java {
	namespace util {

$CompoundAttribute _ImmutableCollections$MapN_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$CompoundAttribute _ImmutableCollections$MapN_FieldAnnotations_table[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _ImmutableCollections$MapN_FieldAnnotations_size[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$FieldInfo _ImmutableCollections$MapN_FieldInfo_[] = {
	{"table", "[Ljava/lang/Object;", nullptr, $FINAL, $field(ImmutableCollections$MapN, table), _ImmutableCollections$MapN_FieldAnnotations_table},
	{"size", "I", nullptr, $FINAL, $field(ImmutableCollections$MapN, size$), _ImmutableCollections$MapN_FieldAnnotations_size},
	{}
};

$MethodInfo _ImmutableCollections$MapN_MethodInfo_[] = {
	{"<init>", "([Ljava/lang/Object;)V", nullptr, $TRANSIENT, $method(ImmutableCollections$MapN, init$, void, $ObjectArray*)},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ImmutableCollections$MapN, containsKey, bool, Object$*)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ImmutableCollections$MapN, containsValue, bool, Object$*)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(ImmutableCollections$MapN, entrySet, $Set*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(ImmutableCollections$MapN, get, $Object*, Object$*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ImmutableCollections$MapN, hashCode, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(ImmutableCollections$MapN, isEmpty, bool)},
	{"probe", "(Ljava/lang/Object;)I", nullptr, $PRIVATE, $method(ImmutableCollections$MapN, probe, int32_t, Object$*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(ImmutableCollections$MapN, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(ImmutableCollections$MapN, size, int32_t)},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(ImmutableCollections$MapN, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _ImmutableCollections$MapN_InnerClassesInfo_[] = {
	{"java.util.ImmutableCollections$MapN", "java.util.ImmutableCollections", "MapN", $STATIC | $FINAL},
	{"java.util.ImmutableCollections$AbstractImmutableMap", "java.util.ImmutableCollections", "AbstractImmutableMap", $STATIC | $ABSTRACT},
	{"java.util.ImmutableCollections$MapN$MapNIterator", "java.util.ImmutableCollections$MapN", "MapNIterator", 0},
	{"java.util.ImmutableCollections$MapN$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ImmutableCollections$MapN_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.ImmutableCollections$MapN",
	"java.util.ImmutableCollections$AbstractImmutableMap",
	nullptr,
	_ImmutableCollections$MapN_FieldInfo_,
	_ImmutableCollections$MapN_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/ImmutableCollections$AbstractImmutableMap<TK;TV;>;",
	nullptr,
	_ImmutableCollections$MapN_InnerClassesInfo_,
	_ImmutableCollections$MapN_Annotations_,
	nullptr,
	nullptr,
	"java.util.ImmutableCollections"
};

$Object* allocate$ImmutableCollections$MapN($Class* clazz) {
	return $of($alloc(ImmutableCollections$MapN));
}

void ImmutableCollections$MapN::init$($ObjectArray* input) {
	$useLocalCurrentObjectStackCache();
	$ImmutableCollections$AbstractImmutableMap::init$();
	if (((int32_t)($nc(input)->length & (uint32_t)1)) != 0) {
		$throwNew($InternalError, "length is odd"_s);
	}
	this->size$ = $nc(input)->length >> 1;
	int32_t len = 2 * input->length;
	len = (int32_t)((len + 1) & (uint32_t)~1);
	$set(this, table, $new($ObjectArray, len));
	for (int32_t i = 0; i < input->length; i += 2) {
		$var($Object, k, $Objects::requireNonNull(input->get(i)));
		$var($Object, v, $Objects::requireNonNull(input->get(i + 1)));
		int32_t idx = probe(k);
		if (idx >= 0) {
			$throwNew($IllegalArgumentException, $$str({"duplicate key: "_s, k}));
		} else {
			int32_t dest = -(idx + 1);
			$nc(this->table)->set(dest, k);
			$nc(this->table)->set(dest + 1, v);
		}
	}
}

bool ImmutableCollections$MapN::containsKey(Object$* o) {
	$Objects::requireNonNull(o);
	return this->size$ > 0 && probe(o) >= 0;
}

bool ImmutableCollections$MapN::containsValue(Object$* o) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(o);
	for (int32_t i = 1; i < $nc(this->table)->length; i += 2) {
		$var($Object0, v, $nc(this->table)->get(i));
		if (v != nullptr && $of(o)->equals(v)) {
			return true;
		}
	}
	return false;
}

int32_t ImmutableCollections$MapN::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t hash = 0;
	for (int32_t i = 0; i < $nc(this->table)->length; i += 2) {
		$var($Object0, k, $nc(this->table)->get(i));
		if (k != nullptr) {
			int32_t var$0 = $of(k)->hashCode();
			hash += var$0 ^ $nc($of($nc(this->table)->get(i + 1)))->hashCode();
		}
	}
	return hash;
}

$Object* ImmutableCollections$MapN::get(Object$* o) {
	if (this->size$ == 0) {
		$Objects::requireNonNull(o);
		return $of(nullptr);
	}
	int32_t i = probe(o);
	if (i >= 0) {
		return $of($nc(this->table)->get(i + 1));
	} else {
		return $of(nullptr);
	}
}

int32_t ImmutableCollections$MapN::size() {
	return this->size$;
}

bool ImmutableCollections$MapN::isEmpty() {
	return this->size$ == 0;
}

$Set* ImmutableCollections$MapN::entrySet() {
	return $new($ImmutableCollections$MapN$1, this);
}

int32_t ImmutableCollections$MapN::probe(Object$* pk) {
	$useLocalCurrentObjectStackCache();
	int32_t idx = $Math::floorMod($nc($of(pk))->hashCode(), $nc(this->table)->length >> 1) << 1;
	while (true) {
		$var($Object, ek, $nc(this->table)->get(idx));
		if (ek == nullptr) {
			return -idx - 1;
		} else if ($nc($of(pk))->equals(ek)) {
			return idx;
		} else if ((idx += 2) == $nc(this->table)->length) {
			idx = 0;
		}
	}
}

void ImmutableCollections$MapN::readObject($ObjectInputStream* in) {
	$throwNew($InvalidObjectException, "not serial proxy"_s);
}

$Object* ImmutableCollections$MapN::writeReplace() {
	$var($ObjectArray, array, $new($ObjectArray, 2 * this->size$));
	int32_t len = $nc(this->table)->length;
	int32_t dest = 0;
	for (int32_t i = 0; i < len; i += 2) {
		if ($nc(this->table)->get(i) != nullptr) {
			array->set(dest++, $nc(this->table)->get(i));
			array->set(dest++, $nc(this->table)->get(i + 1));
		}
	}
	return $of($new($CollSer, $CollSer::IMM_MAP, array));
}

ImmutableCollections$MapN::ImmutableCollections$MapN() {
}

$Class* ImmutableCollections$MapN::load$($String* name, bool initialize) {
	$loadClass(ImmutableCollections$MapN, name, initialize, &_ImmutableCollections$MapN_ClassInfo_, allocate$ImmutableCollections$MapN);
	return class$;
}

$Class* ImmutableCollections$MapN::class$ = nullptr;

	} // util
} // java