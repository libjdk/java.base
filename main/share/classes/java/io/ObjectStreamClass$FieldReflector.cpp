#include <java/io/ObjectStreamClass$FieldReflector.h>

#include <java/io/Bits.h>
#include <java/io/ObjectStreamClass.h>
#include <java/io/ObjectStreamField.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/InternalError.h>
#include <java/lang/reflect/Field.h>
#include <java/util/ArrayList.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jcpp.h>

#undef INVALID_FIELD_OFFSET

using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $Bits = ::java::io::Bits;
using $ObjectStreamField = ::java::io::ObjectStreamField;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Field = ::java::lang::reflect::Field;
using $ArrayList = ::java::util::ArrayList;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $Unsafe = ::jdk::internal::misc::Unsafe;

namespace java {
	namespace io {

$FieldInfo _ObjectStreamClass$FieldReflector_FieldInfo_[] = {
	{"unsafe", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectStreamClass$FieldReflector, unsafe)},
	{"fields", "[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE | $FINAL, $field(ObjectStreamClass$FieldReflector, fields)},
	{"numPrimFields", "I", nullptr, $PRIVATE | $FINAL, $field(ObjectStreamClass$FieldReflector, numPrimFields)},
	{"readKeys", "[J", nullptr, $PRIVATE | $FINAL, $field(ObjectStreamClass$FieldReflector, readKeys)},
	{"writeKeys", "[J", nullptr, $PRIVATE | $FINAL, $field(ObjectStreamClass$FieldReflector, writeKeys)},
	{"offsets", "[I", nullptr, $PRIVATE | $FINAL, $field(ObjectStreamClass$FieldReflector, offsets)},
	{"typeCodes", "[C", nullptr, $PRIVATE | $FINAL, $field(ObjectStreamClass$FieldReflector, typeCodes)},
	{"types", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $FINAL, $field(ObjectStreamClass$FieldReflector, types)},
	{}
};

$MethodInfo _ObjectStreamClass$FieldReflector_MethodInfo_[] = {
	{"<init>", "([Ljava/io/ObjectStreamField;)V", nullptr, 0, $method(ObjectStreamClass$FieldReflector, init$, void, $ObjectStreamFieldArray*)},
	{"checkObjectFieldValueTypes", "(Ljava/lang/Object;[Ljava/lang/Object;)V", nullptr, 0, $virtualMethod(ObjectStreamClass$FieldReflector, checkObjectFieldValueTypes, void, Object$*, $ObjectArray*)},
	{"getFields", "()[Ljava/io/ObjectStreamField;", nullptr, 0, $virtualMethod(ObjectStreamClass$FieldReflector, getFields, $ObjectStreamFieldArray*)},
	{"getObjFieldValues", "(Ljava/lang/Object;[Ljava/lang/Object;)V", nullptr, 0, $virtualMethod(ObjectStreamClass$FieldReflector, getObjFieldValues, void, Object$*, $ObjectArray*)},
	{"getPrimFieldValues", "(Ljava/lang/Object;[B)V", nullptr, 0, $virtualMethod(ObjectStreamClass$FieldReflector, getPrimFieldValues, void, Object$*, $bytes*)},
	{"setObjFieldValues", "(Ljava/lang/Object;[Ljava/lang/Object;)V", nullptr, 0, $virtualMethod(ObjectStreamClass$FieldReflector, setObjFieldValues, void, Object$*, $ObjectArray*)},
	{"setObjFieldValues", "(Ljava/lang/Object;[Ljava/lang/Object;Z)V", nullptr, $PRIVATE, $method(ObjectStreamClass$FieldReflector, setObjFieldValues, void, Object$*, $ObjectArray*, bool)},
	{"setPrimFieldValues", "(Ljava/lang/Object;[B)V", nullptr, 0, $virtualMethod(ObjectStreamClass$FieldReflector, setPrimFieldValues, void, Object$*, $bytes*)},
	{}
};

$InnerClassInfo _ObjectStreamClass$FieldReflector_InnerClassesInfo_[] = {
	{"java.io.ObjectStreamClass$FieldReflector", "java.io.ObjectStreamClass", "FieldReflector", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ObjectStreamClass$FieldReflector_ClassInfo_ = {
	$ACC_SUPER,
	"java.io.ObjectStreamClass$FieldReflector",
	"java.lang.Object",
	nullptr,
	_ObjectStreamClass$FieldReflector_FieldInfo_,
	_ObjectStreamClass$FieldReflector_MethodInfo_,
	nullptr,
	nullptr,
	_ObjectStreamClass$FieldReflector_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.io.ObjectStreamClass"
};

$Object* allocate$ObjectStreamClass$FieldReflector($Class* clazz) {
	return $of($alloc(ObjectStreamClass$FieldReflector));
}

$Unsafe* ObjectStreamClass$FieldReflector::unsafe = nullptr;

void ObjectStreamClass$FieldReflector::init$($ObjectStreamFieldArray* fields) {
	$useLocalCurrentObjectStackCache();
	$set(this, fields, fields);
	int32_t nfields = $nc(fields)->length;
	$set(this, readKeys, $new($longs, nfields));
	$set(this, writeKeys, $new($longs, nfields));
	$set(this, offsets, $new($ints, nfields));
	$set(this, typeCodes, $new($chars, nfields));
	$var($ArrayList, typeList, $new($ArrayList));
	$var($Set, usedKeys, $new($HashSet));
	for (int32_t i = 0; i < nfields; ++i) {
		$var($ObjectStreamField, f, fields->get(i));
		$var($Field, rf, $nc(f)->getField());
		int64_t key = (rf != nullptr) ? $nc(ObjectStreamClass$FieldReflector::unsafe)->objectFieldOffset(rf) : (int64_t)$Unsafe::INVALID_FIELD_OFFSET;
		$nc(this->readKeys)->set(i, key);
		$nc(this->writeKeys)->set(i, usedKeys->add($($Long::valueOf(key))) ? key : (int64_t)$Unsafe::INVALID_FIELD_OFFSET);
		$nc(this->offsets)->set(i, f->getOffset());
		$nc(this->typeCodes)->set(i, f->getTypeCode());
		if (!f->isPrimitive()) {
			typeList->add((rf != nullptr) ? $nc(rf)->getType() : ($Class*)nullptr);
		}
	}
	$set(this, types, $fcast($ClassArray, typeList->toArray($$new($ClassArray, typeList->size()))));
	this->numPrimFields = nfields - $nc(this->types)->length;
}

$ObjectStreamFieldArray* ObjectStreamClass$FieldReflector::getFields() {
	return this->fields;
}

void ObjectStreamClass$FieldReflector::getPrimFieldValues(Object$* obj, $bytes* buf) {
	if (obj == nullptr) {
		$throwNew($NullPointerException);
	}
	for (int32_t i = 0; i < this->numPrimFields; ++i) {
		int64_t key = $nc(this->readKeys)->get(i);
		int32_t off = $nc(this->offsets)->get(i);
		switch ($nc(this->typeCodes)->get(i)) {
		case u'Z':
			{
				$Bits::putBoolean(buf, off, $nc(ObjectStreamClass$FieldReflector::unsafe)->getBoolean(obj, key));
				break;
			}
		case u'B':
			{
				$nc(buf)->set(off, $nc(ObjectStreamClass$FieldReflector::unsafe)->getByte(obj, key));
				break;
			}
		case u'C':
			{
				$Bits::putChar(buf, off, $nc(ObjectStreamClass$FieldReflector::unsafe)->getChar(obj, key));
				break;
			}
		case u'S':
			{
				$Bits::putShort(buf, off, $nc(ObjectStreamClass$FieldReflector::unsafe)->getShort(obj, key));
				break;
			}
		case u'I':
			{
				$Bits::putInt(buf, off, $nc(ObjectStreamClass$FieldReflector::unsafe)->getInt(obj, key));
				break;
			}
		case u'F':
			{
				$Bits::putFloat(buf, off, $nc(ObjectStreamClass$FieldReflector::unsafe)->getFloat(obj, key));
				break;
			}
		case u'J':
			{
				$Bits::putLong(buf, off, $nc(ObjectStreamClass$FieldReflector::unsafe)->getLong(obj, key));
				break;
			}
		case u'D':
			{
				$Bits::putDouble(buf, off, $nc(ObjectStreamClass$FieldReflector::unsafe)->getDouble(obj, key));
				break;
			}
		default:
			{
				$throwNew($InternalError);
			}
		}
	}
}

void ObjectStreamClass$FieldReflector::setPrimFieldValues(Object$* obj, $bytes* buf) {
	if (obj == nullptr) {
		$throwNew($NullPointerException);
	}
	for (int32_t i = 0; i < this->numPrimFields; ++i) {
		int64_t key = $nc(this->writeKeys)->get(i);
		if (key == $Unsafe::INVALID_FIELD_OFFSET) {
			continue;
		}
		int32_t off = $nc(this->offsets)->get(i);
		switch ($nc(this->typeCodes)->get(i)) {
		case u'Z':
			{
				$nc(ObjectStreamClass$FieldReflector::unsafe)->putBoolean(obj, key, $Bits::getBoolean(buf, off));
				break;
			}
		case u'B':
			{
				$nc(ObjectStreamClass$FieldReflector::unsafe)->putByte(obj, key, $nc(buf)->get(off));
				break;
			}
		case u'C':
			{
				$nc(ObjectStreamClass$FieldReflector::unsafe)->putChar(obj, key, $Bits::getChar(buf, off));
				break;
			}
		case u'S':
			{
				$nc(ObjectStreamClass$FieldReflector::unsafe)->putShort(obj, key, $Bits::getShort(buf, off));
				break;
			}
		case u'I':
			{
				$nc(ObjectStreamClass$FieldReflector::unsafe)->putInt(obj, key, $Bits::getInt(buf, off));
				break;
			}
		case u'F':
			{
				$nc(ObjectStreamClass$FieldReflector::unsafe)->putFloat(obj, key, $Bits::getFloat(buf, off));
				break;
			}
		case u'J':
			{
				$nc(ObjectStreamClass$FieldReflector::unsafe)->putLong(obj, key, $Bits::getLong(buf, off));
				break;
			}
		case u'D':
			{
				$nc(ObjectStreamClass$FieldReflector::unsafe)->putDouble(obj, key, $Bits::getDouble(buf, off));
				break;
			}
		default:
			{
				$throwNew($InternalError);
			}
		}
	}
}

void ObjectStreamClass$FieldReflector::getObjFieldValues(Object$* obj, $ObjectArray* vals) {
	$useLocalCurrentObjectStackCache();
	if (obj == nullptr) {
		$throwNew($NullPointerException);
	}
	for (int32_t i = this->numPrimFields; i < $nc(this->fields)->length; ++i) {

		$var($Object, var$0, nullptr)
		switch ($nc(this->typeCodes)->get(i)) {
		case u'L':
			{}
		case u'[':
			{
				$assign(var$0, $nc(ObjectStreamClass$FieldReflector::unsafe)->getReference(obj, $nc(this->readKeys)->get(i)));
				break;
			}
		default:
			{
				$throwNew($InternalError);
			}
		}
		$nc(vals)->set($nc(this->offsets)->get(i), var$0);
	}
}

void ObjectStreamClass$FieldReflector::checkObjectFieldValueTypes(Object$* obj, $ObjectArray* vals) {
	setObjFieldValues(obj, vals, true);
}

void ObjectStreamClass$FieldReflector::setObjFieldValues(Object$* obj, $ObjectArray* vals) {
	setObjFieldValues(obj, vals, false);
}

void ObjectStreamClass$FieldReflector::setObjFieldValues(Object$* obj, $ObjectArray* vals, bool dryRun) {
	$useLocalCurrentObjectStackCache();
	if (obj == nullptr) {
		$throwNew($NullPointerException);
	}
	for (int32_t i = this->numPrimFields; i < $nc(this->fields)->length; ++i) {
		int64_t key = $nc(this->writeKeys)->get(i);
		if (key == $Unsafe::INVALID_FIELD_OFFSET) {
			continue;
		}
		switch ($nc(this->typeCodes)->get(i)) {
		case u'L':
			{}
		case u'[':
			{
				{
					$var($Object0, val, $nc(vals)->get($nc(this->offsets)->get(i)));
					if (val != nullptr && !$nc($nc(this->types)->get(i - this->numPrimFields))->isInstance(val)) {
						$var($Field, f, $nc($nc(this->fields)->get(i))->getField());
						$var($String, var$6, $$str({"cannot assign instance of "_s, $($of(val)->getClass()->getName()), " to field "_s}));
						$var($String, var$5, $$concat(var$6, $($nc($nc(f)->getDeclaringClass())->getName())));
						$var($String, var$4, $$concat(var$5, "."_s));
						$var($String, var$3, $$concat(var$4, $(f->getName())));
						$var($String, var$2, $$concat(var$3, " of type "_s));
						$var($String, var$1, $$concat(var$2, $($nc(f->getType())->getName())));
						$var($String, var$0, $$concat(var$1, " in instance of "_s));
						$throwNew($ClassCastException, $$concat(var$0, $($nc($of(obj))->getClass()->getName())));
					}
					if (!dryRun) {
						$nc(ObjectStreamClass$FieldReflector::unsafe)->putReference(obj, key, val);
					}
				}
				break;
			}
		default:
			{
				$throwNew($InternalError);
			}
		}
	}
}

void clinit$ObjectStreamClass$FieldReflector($Class* class$) {
	$assignStatic(ObjectStreamClass$FieldReflector::unsafe, $Unsafe::getUnsafe());
}

ObjectStreamClass$FieldReflector::ObjectStreamClass$FieldReflector() {
}

$Class* ObjectStreamClass$FieldReflector::load$($String* name, bool initialize) {
	$loadClass(ObjectStreamClass$FieldReflector, name, initialize, &_ObjectStreamClass$FieldReflector_ClassInfo_, clinit$ObjectStreamClass$FieldReflector, allocate$ObjectStreamClass$FieldReflector);
	return class$;
}

$Class* ObjectStreamClass$FieldReflector::class$ = nullptr;

	} // io
} // java