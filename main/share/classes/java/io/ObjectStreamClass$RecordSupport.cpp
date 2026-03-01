#include <java/io/ObjectStreamClass$RecordSupport.h>

#include <java/io/Bits.h>
#include <java/io/ObjectStreamClass$DeserializationConstructorsCache.h>
#include <java/io/ObjectStreamClass.h>
#include <java/io/ObjectStreamField.h>
#include <java/io/Serializable.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InternalError.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/RecordComponent.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/Map.h>
#include <jcpp.h>

#undef PRIM_VALUE_EXTRACTORS
#undef TYPE

using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $RecordComponentArray = $Array<::java::lang::reflect::RecordComponent>;
using $Bits = ::java::io::Bits;
using $ObjectStreamClass = ::java::io::ObjectStreamClass;
using $ObjectStreamClass$DeserializationConstructorsCache = ::java::io::ObjectStreamClass$DeserializationConstructorsCache;
using $ObjectStreamField = ::java::io::ObjectStreamField;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $Short = ::java::lang::Short;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Field = ::java::lang::reflect::Field;
using $RecordComponent = ::java::lang::reflect::RecordComponent;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Map = ::java::util::Map;

namespace java {
	namespace io {

class ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents : public $PrivilegedExceptionAction {
	$class(ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$($Class* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->getRecordComponents());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents>());
	}
	$Class* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents, inst$)},
	{}
};
$MethodInfo ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents, init$, void, $Class*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents, run, $Object*)},
	{}
};
$ClassInfo ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.io.ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	fieldInfos,
	methodInfos
};
$Class* ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents::load$($String* name, bool initialize) {
	$loadClass(ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents::class$ = nullptr;

$FieldInfo _ObjectStreamClass$RecordSupport_FieldInfo_[] = {
	{"PRIM_VALUE_EXTRACTORS", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandle;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ObjectStreamClass$RecordSupport, PRIM_VALUE_EXTRACTORS)},
	{}
};

$MethodInfo _ObjectStreamClass$RecordSupport_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(ObjectStreamClass$RecordSupport, init$, void)},
	{"deserializationCtr", "(Ljava/io/ObjectStreamClass;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(ObjectStreamClass$RecordSupport, deserializationCtr, $MethodHandle*, $ObjectStreamClass*)},
	{"numberPrimValues", "(Ljava/io/ObjectStreamClass;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass$RecordSupport, numberPrimValues, int32_t, $ObjectStreamClass*)},
	{"streamFieldExtractor", "(Ljava/lang/String;Ljava/lang/Class;Ljava/io/ObjectStreamClass;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/String;Ljava/lang/Class<*>;Ljava/io/ObjectStreamClass;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass$RecordSupport, streamFieldExtractor, $MethodHandle*, $String*, $Class*, $ObjectStreamClass*)},
	{}
};

$InnerClassInfo _ObjectStreamClass$RecordSupport_InnerClassesInfo_[] = {
	{"java.io.ObjectStreamClass$RecordSupport", "java.io.ObjectStreamClass", "RecordSupport", $STATIC | $FINAL},
	{}
};

$ClassInfo _ObjectStreamClass$RecordSupport_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.io.ObjectStreamClass$RecordSupport",
	"java.lang.Object",
	nullptr,
	_ObjectStreamClass$RecordSupport_FieldInfo_,
	_ObjectStreamClass$RecordSupport_MethodInfo_,
	nullptr,
	nullptr,
	_ObjectStreamClass$RecordSupport_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.io.ObjectStreamClass"
};

$Object* allocate$ObjectStreamClass$RecordSupport($Class* clazz) {
	return $of($alloc(ObjectStreamClass$RecordSupport));
}

$Map* ObjectStreamClass$RecordSupport::PRIM_VALUE_EXTRACTORS = nullptr;

void ObjectStreamClass$RecordSupport::init$() {
}

$MethodHandle* ObjectStreamClass$RecordSupport::deserializationCtr($ObjectStreamClass* desc) {
	$init(ObjectStreamClass$RecordSupport);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($MethodHandle, mh, $nc(desc)->deserializationCtr);
	if (mh != nullptr) {
		return mh;
	}
	$assign(mh, $nc(desc->deserializationCtrs)->get($(desc->getFields(false))));
	if (mh != nullptr) {
		return $set(desc, deserializationCtr, mh);
	}
	$var($RecordComponentArray, recordComponents, nullptr);
	try {
		$Class* cls = desc->forClass();
		$var($PrivilegedExceptionAction, pa, static_cast<$PrivilegedExceptionAction*>($new(ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents, static_cast<$Class*>($nc(cls)))));
		$assign(recordComponents, $cast($RecordComponentArray, $AccessController::doPrivileged(pa)));
	} catch ($PrivilegedActionException& e) {
		$throwNew($InternalError, $(e->getCause()));
	}
	$assign(mh, desc->getRecordConstructor());
	$assign(mh, $nc(mh)->asType($($nc($(mh->type()))->changeReturnType($Object::class$))));
	$load($bytes);
	$load($ObjectArray);
	$assign(mh, $MethodHandles::dropArguments(mh, $nc($(mh->type()))->parameterCount(), $$new($ClassArray, {
		$getClass($bytes),
		$getClass($ObjectArray)
	})));
	for (int32_t i = $nc(recordComponents)->length - 1; i >= 0; --i) {
		$var($String, name, $nc(recordComponents->get(i))->getName());
		$Class* type = $nc(recordComponents->get(i))->getType();
		$var($MethodHandle, combiner, streamFieldExtractor(name, type, desc));
		$assign(mh, $MethodHandles::foldArguments(mh, i, combiner));
	}
	return $set(desc, deserializationCtr, $nc(desc->deserializationCtrs)->putIfAbsentAndGet($(desc->getFields(false)), mh));
}

int32_t ObjectStreamClass$RecordSupport::numberPrimValues($ObjectStreamClass* desc) {
	$init(ObjectStreamClass$RecordSupport);
	$var($ObjectStreamFieldArray, fields, $nc(desc)->getFields());
	int32_t primValueCount = 0;
	for (int32_t i = 0; i < $nc(fields)->length; ++i) {
		if ($nc(fields->get(i))->isPrimitive()) {
			++primValueCount;
		} else {
			break;
		}
	}
	return primValueCount;
}

$MethodHandle* ObjectStreamClass$RecordSupport::streamFieldExtractor($String* pName, $Class* pType, $ObjectStreamClass* desc) {
	$init(ObjectStreamClass$RecordSupport);
	$useLocalCurrentObjectStackCache();
	$var($ObjectStreamFieldArray, fields, $nc(desc)->getFields(false));
	for (int32_t i = 0; i < $nc(fields)->length; ++i) {
		$var($ObjectStreamField, f, fields->get(i));
		$var($String, fName, $nc(f)->getName());
		if (!$nc(fName)->equals(pName)) {
			continue;
		}
		$Class* fType = $nc($(f->getField()))->getType();
		if (!$nc(pType)->isAssignableFrom(fType)) {
			$throwNew($InternalError, $$str({fName, " unassignable, pType:"_s, pType, ", fType:"_s, fType}));
		}
		if (f->isPrimitive()) {
			$var($MethodHandle, mh, $cast($MethodHandle, $nc(ObjectStreamClass$RecordSupport::PRIM_VALUE_EXTRACTORS)->get(fType)));
			if (mh == nullptr) {
				$throwNew($InternalError, $$str({"Unexpected type: "_s, fType}));
			}
			$assign(mh, $MethodHandles::insertArguments(mh, 1, $$new($ObjectArray, {$($of($Integer::valueOf(f->getOffset())))})));
			$load($ObjectArray);
			$assign(mh, $MethodHandles::dropArguments(mh, 1, $$new($ClassArray, {$getClass($ObjectArray)})));
			if (pType != fType) {
				$assign(mh, $nc(mh)->asType($($nc($(mh->type()))->changeReturnType(pType))));
			}
			return mh;
		} else {
			$load($ObjectArray);
			$var($MethodHandle, mh, $MethodHandles::arrayElementGetter($getClass($ObjectArray)));
			$assign(mh, $MethodHandles::insertArguments(mh, 1, $$new($ObjectArray, {$($of($Integer::valueOf(i - numberPrimValues(desc))))})));
			$load($bytes);
			$assign(mh, $MethodHandles::dropArguments(mh, 0, $$new($ClassArray, {$getClass($bytes)})));
			if (pType != $Object::class$) {
				$assign(mh, $nc(mh)->asType($($nc($(mh->type()))->changeReturnType(pType))));
			}
			return mh;
		}
	}
	$load($bytes);
	$load($ObjectArray);
	return $MethodHandles::empty($($MethodType::methodType(pType, $getClass($bytes), $$new($ClassArray, {$getClass($ObjectArray)}))));
}

void clinit$ObjectStreamClass$RecordSupport($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		$var($MethodHandles$Lookup, lkp, $MethodHandles::lookup());
		try {
			$init($Byte);
			$var($Object, var$0, $of($Byte::TYPE));
			$load($bytes);
			$var($Object, var$1, $of($MethodHandles::arrayElementGetter($getClass($bytes))));
			$init($Short);
			$var($Object, var$2, $of($Short::TYPE));
			$load($Bits);
			$init($Integer);
			$var($Object, var$3, $of($nc(lkp)->findStatic($Bits::class$, "getShort"_s, $($MethodType::methodType($Short::TYPE, $getClass($bytes), $$new($ClassArray, {$Integer::TYPE}))))));
			$var($Object, var$4, $of($Integer::TYPE));
			$var($Object, var$5, $of(lkp->findStatic($Bits::class$, "getInt"_s, $($MethodType::methodType($Integer::TYPE, $getClass($bytes), $$new($ClassArray, {$Integer::TYPE}))))));
			$init($Long);
			$var($Object, var$6, $of($Long::TYPE));
			$var($Object, var$7, $of(lkp->findStatic($Bits::class$, "getLong"_s, $($MethodType::methodType($Long::TYPE, $getClass($bytes), $$new($ClassArray, {$Integer::TYPE}))))));
			$init($Float);
			$var($Object, var$8, $of($Float::TYPE));
			$var($Object, var$9, $of(lkp->findStatic($Bits::class$, "getFloat"_s, $($MethodType::methodType($Float::TYPE, $getClass($bytes), $$new($ClassArray, {$Integer::TYPE}))))));
			$init($Double);
			$var($Object, var$10, $of($Double::TYPE));
			$var($Object, var$11, $of(lkp->findStatic($Bits::class$, "getDouble"_s, $($MethodType::methodType($Double::TYPE, $getClass($bytes), $$new($ClassArray, {$Integer::TYPE}))))));
			$init($Character);
			$var($Object, var$12, $of($Character::TYPE));
			$var($Object, var$13, $of(lkp->findStatic($Bits::class$, "getChar"_s, $($MethodType::methodType($Character::TYPE, $getClass($bytes), $$new($ClassArray, {$Integer::TYPE}))))));
			$init($Boolean);
			$var($Object, var$14, $of($Boolean::TYPE));
			$assignStatic(ObjectStreamClass$RecordSupport::PRIM_VALUE_EXTRACTORS, $Map::of(var$0, var$1, var$2, var$3, var$4, var$5, var$6, var$7, var$8, var$9, var$10, var$11, var$12, var$13, var$14, $(lkp->findStatic($Bits::class$, "getBoolean"_s, $($MethodType::methodType($Boolean::TYPE, $getClass($bytes), $$new($ClassArray, {$Integer::TYPE})))))));
		} catch ($NoSuchMethodException& e) {
			$throwNew($InternalError, "Can\'t lookup Bits.getXXX"_s, e);
		} catch ($IllegalAccessException& e) {
			$throwNew($InternalError, "Can\'t lookup Bits.getXXX"_s, e);
		}
	}
}

ObjectStreamClass$RecordSupport::ObjectStreamClass$RecordSupport() {
}

$Class* ObjectStreamClass$RecordSupport::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents::classInfo$.name)) {
			return ObjectStreamClass$RecordSupport$$Lambda$getRecordComponents::load$(name, initialize);
		}
	}
	$loadClass(ObjectStreamClass$RecordSupport, name, initialize, &_ObjectStreamClass$RecordSupport_ClassInfo_, clinit$ObjectStreamClass$RecordSupport, allocate$ObjectStreamClass$RecordSupport);
	return class$;
}

$Class* ObjectStreamClass$RecordSupport::class$ = nullptr;

	} // io
} // java