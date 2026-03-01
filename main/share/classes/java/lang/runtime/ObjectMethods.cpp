#include <java/lang/runtime/ObjectMethods.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/ConstantCallSite.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/invoke/TypeDescriptor.h>
#include <java/lang/runtime/ObjectMethods$1.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Arrays.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef CLASS_IS_INSTANCE
#undef DESCRIPTOR_MT
#undef FALSE
#undef HASH_COMBINER
#undef NAMES_MT
#undef OBJECTS_EQUALS
#undef OBJECTS_HASHCODE
#undef OBJECTS_TOSTRING
#undef OBJECT_EQ
#undef OBJECT_EQUALS
#undef OBJECT_HASHCODE
#undef OBJECT_METHODS_CLASS
#undef OBJECT_TO_STRING
#undef STRING_FORMAT
#undef TRUE
#undef TYPE
#undef ZERO

using $MethodHandleArray = $Array<::java::lang::invoke::MethodHandle>;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Short = ::java::lang::Short;
using $ConstantCallSite = ::java::lang::invoke::ConstantCallSite;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $TypeDescriptor = ::java::lang::invoke::TypeDescriptor;
using $ObjectMethods$1 = ::java::lang::runtime::ObjectMethods$1;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Arrays = ::java::util::Arrays;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;

namespace java {
	namespace lang {
		namespace runtime {

$FieldInfo _ObjectMethods_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ObjectMethods, $assertionsDisabled)},
	{"DESCRIPTOR_MT", "Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, DESCRIPTOR_MT)},
	{"NAMES_MT", "Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, NAMES_MT)},
	{"FALSE", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, FALSE)},
	{"TRUE", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, TRUE)},
	{"ZERO", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, ZERO)},
	{"CLASS_IS_INSTANCE", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, CLASS_IS_INSTANCE)},
	{"OBJECT_EQUALS", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, OBJECT_EQUALS)},
	{"OBJECTS_EQUALS", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, OBJECTS_EQUALS)},
	{"OBJECTS_HASHCODE", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, OBJECTS_HASHCODE)},
	{"OBJECTS_TOSTRING", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, OBJECTS_TOSTRING)},
	{"OBJECT_EQ", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, OBJECT_EQ)},
	{"OBJECT_HASHCODE", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, OBJECT_HASHCODE)},
	{"OBJECT_TO_STRING", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, OBJECT_TO_STRING)},
	{"STRING_FORMAT", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, STRING_FORMAT)},
	{"HASH_COMBINER", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, HASH_COMBINER)},
	{"primitiveEquals", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandle;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, primitiveEquals)},
	{"primitiveHashers", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandle;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, primitiveHashers)},
	{"primitiveToString", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandle;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ObjectMethods, primitiveToString)},
	{}
};

$MethodInfo _ObjectMethods_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ObjectMethods, init$, void)},
	{"bootstrap", "(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/String;Ljava/lang/invoke/TypeDescriptor;Ljava/lang/Class;Ljava/lang/String;[Ljava/lang/invoke/MethodHandle;)Ljava/lang/Object;", "(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/String;Ljava/lang/invoke/TypeDescriptor;Ljava/lang/Class<*>;Ljava/lang/String;[Ljava/lang/invoke/MethodHandle;)Ljava/lang/Object;", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(ObjectMethods, bootstrap, $Object*, $MethodHandles$Lookup*, $String*, $TypeDescriptor*, $Class*, $String*, $MethodHandleArray*), "java.lang.Throwable"},
	{"eq", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectMethods, eq, bool, Object$*, Object$*)},
	{"eq", "(BB)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectMethods, eq, bool, int8_t, int8_t)},
	{"eq", "(SS)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectMethods, eq, bool, int16_t, int16_t)},
	{"eq", "(CC)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectMethods, eq, bool, char16_t, char16_t)},
	{"eq", "(II)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectMethods, eq, bool, int32_t, int32_t)},
	{"eq", "(JJ)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectMethods, eq, bool, int64_t, int64_t)},
	{"eq", "(FF)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectMethods, eq, bool, float, float)},
	{"eq", "(DD)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectMethods, eq, bool, double, double)},
	{"eq", "(ZZ)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectMethods, eq, bool, bool, bool)},
	{"equalator", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(ObjectMethods, equalator, $MethodHandle*, $Class*)},
	{"hashCombiner", "(II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectMethods, hashCombiner, int32_t, int32_t, int32_t)},
	{"hasher", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(ObjectMethods, hasher, $MethodHandle*, $Class*)},
	{"makeEquals", "(Ljava/lang/Class;Ljava/util/List;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(ObjectMethods, makeEquals, $MethodHandle*, $Class*, $List*)},
	{"makeHashCode", "(Ljava/lang/Class;Ljava/util/List;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(ObjectMethods, makeHashCode, $MethodHandle*, $Class*, $List*)},
	{"makeToString", "(Ljava/lang/Class;Ljava/util/List;Ljava/util/List;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;Ljava/util/List<Ljava/lang/String;>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(ObjectMethods, makeToString, $MethodHandle*, $Class*, $List*, $List*)},
	{"stringifier", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(ObjectMethods, stringifier, $MethodHandle*, $Class*)},
	{}
};

$InnerClassInfo _ObjectMethods_InnerClassesInfo_[] = {
	{"java.lang.runtime.ObjectMethods$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ObjectMethods_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.runtime.ObjectMethods",
	"java.lang.Object",
	nullptr,
	_ObjectMethods_FieldInfo_,
	_ObjectMethods_MethodInfo_,
	nullptr,
	nullptr,
	_ObjectMethods_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.runtime.ObjectMethods$1"
};

$Object* allocate$ObjectMethods($Class* clazz) {
	return $of($alloc(ObjectMethods));
}

bool ObjectMethods::$assertionsDisabled = false;
$MethodType* ObjectMethods::DESCRIPTOR_MT = nullptr;
$MethodType* ObjectMethods::NAMES_MT = nullptr;
$MethodHandle* ObjectMethods::FALSE = nullptr;
$MethodHandle* ObjectMethods::TRUE = nullptr;
$MethodHandle* ObjectMethods::ZERO = nullptr;
$MethodHandle* ObjectMethods::CLASS_IS_INSTANCE = nullptr;
$MethodHandle* ObjectMethods::OBJECT_EQUALS = nullptr;
$MethodHandle* ObjectMethods::OBJECTS_EQUALS = nullptr;
$MethodHandle* ObjectMethods::OBJECTS_HASHCODE = nullptr;
$MethodHandle* ObjectMethods::OBJECTS_TOSTRING = nullptr;
$MethodHandle* ObjectMethods::OBJECT_EQ = nullptr;
$MethodHandle* ObjectMethods::OBJECT_HASHCODE = nullptr;
$MethodHandle* ObjectMethods::OBJECT_TO_STRING = nullptr;
$MethodHandle* ObjectMethods::STRING_FORMAT = nullptr;
$MethodHandle* ObjectMethods::HASH_COMBINER = nullptr;
$HashMap* ObjectMethods::primitiveEquals = nullptr;
$HashMap* ObjectMethods::primitiveHashers = nullptr;
$HashMap* ObjectMethods::primitiveToString = nullptr;

void ObjectMethods::init$() {
}

int32_t ObjectMethods::hashCombiner(int32_t x, int32_t y) {
	$init(ObjectMethods);
	return x * 31 + y;
}

bool ObjectMethods::eq(Object$* a, Object$* b) {
	$init(ObjectMethods);
	return $equals(a, b);
}

bool ObjectMethods::eq(int8_t a, int8_t b) {
	$init(ObjectMethods);
	return a == b;
}

bool ObjectMethods::eq(int16_t a, int16_t b) {
	$init(ObjectMethods);
	return a == b;
}

bool ObjectMethods::eq(char16_t a, char16_t b) {
	$init(ObjectMethods);
	return a == b;
}

bool ObjectMethods::eq(int32_t a, int32_t b) {
	$init(ObjectMethods);
	return a == b;
}

bool ObjectMethods::eq(int64_t a, int64_t b) {
	$init(ObjectMethods);
	return a == b;
}

bool ObjectMethods::eq(float a, float b) {
	$init(ObjectMethods);
	return $Float::compare(a, b) == 0;
}

bool ObjectMethods::eq(double a, double b) {
	$init(ObjectMethods);
	return $Double::compare(a, b) == 0;
}

bool ObjectMethods::eq(bool a, bool b) {
	$init(ObjectMethods);
	return a == b;
}

$MethodHandle* ObjectMethods::equalator($Class* clazz) {
	$init(ObjectMethods);
	$useLocalCurrentObjectStackCache();
	$init($Boolean);
	return ($nc(clazz)->isPrimitive() ? $cast($MethodHandle, $nc(ObjectMethods::primitiveEquals)->get(clazz)) : $nc(ObjectMethods::OBJECTS_EQUALS)->asType($($MethodType::methodType($Boolean::TYPE, clazz, $$new($ClassArray, {clazz})))));
}

$MethodHandle* ObjectMethods::hasher($Class* clazz) {
	$init(ObjectMethods);
	$init($Integer);
	return ($nc(clazz)->isPrimitive() ? $cast($MethodHandle, $nc(ObjectMethods::primitiveHashers)->get(clazz)) : $nc(ObjectMethods::OBJECTS_HASHCODE)->asType($($MethodType::methodType($Integer::TYPE, clazz))));
}

$MethodHandle* ObjectMethods::stringifier($Class* clazz) {
	$init(ObjectMethods);
	return ($nc(clazz)->isPrimitive() ? $cast($MethodHandle, $nc(ObjectMethods::primitiveToString)->get(clazz)) : $nc(ObjectMethods::OBJECTS_TOSTRING)->asType($($MethodType::methodType($String::class$, clazz))));
}

$MethodHandle* ObjectMethods::makeEquals($Class* receiverClass, $List* getters) {
	$init(ObjectMethods);
	$useLocalCurrentObjectStackCache();
	$init($Boolean);
	$var($MethodType, rr, $MethodType::methodType($Boolean::TYPE, receiverClass, $$new($ClassArray, {receiverClass})));
	$var($MethodType, ro, $MethodType::methodType($Boolean::TYPE, receiverClass, $$new($ClassArray, {$Object::class$})));
	$var($MethodHandle, instanceFalse, $MethodHandles::dropArguments(ObjectMethods::FALSE, 0, $$new($ClassArray, {
		receiverClass,
		$Object::class$
	})));
	$var($MethodHandle, instanceTrue, $MethodHandles::dropArguments(ObjectMethods::TRUE, 0, $$new($ClassArray, {
		receiverClass,
		$Object::class$
	})));
	$var($MethodHandle, isSameObject, $nc(ObjectMethods::OBJECT_EQ)->asType(ro));
	$var($MethodHandle, isInstance, $MethodHandles::dropArguments($($nc(ObjectMethods::CLASS_IS_INSTANCE)->bindTo(receiverClass)), 0, $$new($ClassArray, {receiverClass})));
	$var($MethodHandle, accumulator, $MethodHandles::dropArguments(ObjectMethods::TRUE, 0, $$new($ClassArray, {
		receiverClass,
		receiverClass
	})));
	{
		$var($Iterator, i$, $nc(getters)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($MethodHandle, getter, $cast($MethodHandle, i$->next()));
			{
				$var($MethodHandle, equalator, ObjectMethods::equalator($($cast($Class, $nc($($nc(getter)->type()))->returnType()))));
				$var($MethodHandle, thisFieldEqual, $MethodHandles::filterArguments(equalator, 0, $$new($MethodHandleArray, {
					getter,
					getter
				})));
				$assign(accumulator, $MethodHandles::guardWithTest(thisFieldEqual, accumulator, $($nc(instanceFalse)->asType(rr))));
			}
		}
	}
	return $MethodHandles::guardWithTest(isSameObject, instanceTrue, $($MethodHandles::guardWithTest(isInstance, $($nc(accumulator)->asType(ro)), instanceFalse)));
}

$MethodHandle* ObjectMethods::makeHashCode($Class* receiverClass, $List* getters) {
	$init(ObjectMethods);
	$useLocalCurrentObjectStackCache();
	$var($MethodHandle, accumulator, $MethodHandles::dropArguments(ObjectMethods::ZERO, 0, $$new($ClassArray, {receiverClass})));
	{
		$var($Iterator, i$, $nc(getters)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($MethodHandle, getter, $cast($MethodHandle, i$->next()));
			{
				$var($MethodHandle, hasher, ObjectMethods::hasher($($cast($Class, $nc($($nc(getter)->type()))->returnType()))));
				$var($MethodHandle, hashThisField, $MethodHandles::filterArguments(hasher, 0, $$new($MethodHandleArray, {getter})));
				$var($MethodHandle, combineHashes, $MethodHandles::filterArguments(ObjectMethods::HASH_COMBINER, 0, $$new($MethodHandleArray, {
					accumulator,
					hashThisField
				})));
				$assign(accumulator, $MethodHandles::permuteArguments(combineHashes, $($nc(accumulator)->type()), $$new($ints, {
					0,
					0
				})));
			}
		}
	}
	return accumulator;
}

$MethodHandle* ObjectMethods::makeToString($Class* receiverClass, $List* getters, $List* names) {
	$init(ObjectMethods);
	$useLocalCurrentObjectStackCache();
	bool var$0 = !ObjectMethods::$assertionsDisabled;
	if (var$0) {
		int32_t var$1 = $nc(getters)->size();
		var$0 = !(var$1 == $nc(names)->size());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$var($ints, invArgs, $new($ints, $nc(getters)->size()));
	$Arrays::fill(invArgs, 0);
	$var($MethodHandleArray, filters, $new($MethodHandleArray, getters->size()));
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($($nc(receiverClass)->getSimpleName()))->append("["_s);
	for (int32_t i = 0; i < getters->size(); ++i) {
		$var($MethodHandle, getter, $cast($MethodHandle, getters->get(i)));
		$var($MethodHandle, stringify, stringifier($($cast($Class, $nc($($nc(getter)->type()))->returnType()))));
		$var($MethodHandle, stringifyThisField, $MethodHandles::filterArguments(stringify, 0, $$new($MethodHandleArray, {getter})));
		filters->set(i, stringifyThisField);
		sb->append($cast($String, $($nc(names)->get(i))))->append("=%s"_s);
		if (i != getters->size() - 1) {
			sb->append(", "_s);
		}
	}
	sb->append(u']');
	$var($String, formatString, sb->toString());
	$load($StringArray);
	$var($MethodHandle, formatter, $nc($($MethodHandles::insertArguments(ObjectMethods::STRING_FORMAT, 0, $$new($ObjectArray, {$of(formatString)}))))->asCollector($getClass($StringArray), getters->size()));
	if (getters->size() == 0) {
		$assign(formatter, $MethodHandles::dropArguments(formatter, 0, $$new($ClassArray, {receiverClass})));
	} else {
		$var($MethodHandle, filtered, $MethodHandles::filterArguments(formatter, 0, filters));
		$assign(formatter, $MethodHandles::permuteArguments(filtered, $($MethodType::methodType($String::class$, receiverClass)), invArgs));
	}
	return formatter;
}

$Object* ObjectMethods::bootstrap($MethodHandles$Lookup* lookup, $String* methodName, $TypeDescriptor* type, $Class* recordClass, $String* names, $MethodHandleArray* getters) {
	$init(ObjectMethods);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, methodType, nullptr);
	if ($instanceOf($MethodType, type)) {
		$assign(methodType, $cast($MethodType, type));
	} else {
		$assign(methodType, nullptr);
		$load($MethodHandle);
		if (!$of($MethodHandle::class$)->equals(type)) {
			$throwNew($IllegalArgumentException, $($nc($of(type))->toString()));
		}
	}
	$var($List, getterList, $List::of(getters));
	$var($String, s20655$, methodName);
	int32_t tmp20655$ = -1;
	switch ($nc(s20655$)->hashCode()) {
	case (int32_t)0xB2C87FBF:
		{
			if (s20655$->equals("equals"_s)) {
				tmp20655$ = 0;
			}
			break;
		}
	case 0x08CDAC1B:
		{
			if (s20655$->equals("hashCode"_s)) {
				tmp20655$ = 1;
			}
			break;
		}
	case (int32_t)0x9616526C:
		{
			if (s20655$->equals("toString"_s)) {
				tmp20655$ = 2;
			}
			break;
		}
	}

	$var($MethodHandle, var$0, nullptr)
	switch (tmp20655$) {
	case 0:
		{
			{
				$init($Boolean);
				if (methodType != nullptr && !methodType->equals($($of($MethodType::methodType($Boolean::TYPE, recordClass, $$new($ClassArray, {$Object::class$})))))) {
					$throwNew($IllegalArgumentException, $$str({"Bad method type: "_s, methodType}));
				}
				$assign(var$0, makeEquals(recordClass, getterList));
				break;
			}
		}
	case 1:
		{
			{
				$init($Integer);
				if (methodType != nullptr && !methodType->equals($($of($MethodType::methodType($Integer::TYPE, recordClass))))) {
					$throwNew($IllegalArgumentException, $$str({"Bad method type: "_s, methodType}));
				}
				$assign(var$0, makeHashCode(recordClass, getterList));
				break;
			}
		}
	case 2:
		{
			{
				if (methodType != nullptr && !methodType->equals($($of($MethodType::methodType($String::class$, recordClass))))) {
					$throwNew($IllegalArgumentException, $$str({"Bad method type: "_s, methodType}));
				}
				$var($List, nameList, ""_s->equals(names) ? $List::of() : $List::of($($nc(names)->split(";"_s))));
				int32_t var$1 = $nc(nameList)->size();
				if (var$1 != $nc(getterList)->size()) {
					$throwNew($IllegalArgumentException, "Name list and accessor list do not match"_s);
				}
				$assign(var$0, makeToString(recordClass, getterList, nameList));
				break;
			}
		}
	default:
		{
			$throwNew($IllegalArgumentException, methodName);
		}
	}
	$var($MethodHandle, handle, var$0);
	return $of(methodType != nullptr ? $of($new($ConstantCallSite, handle)) : $of(handle));
}

void clinit$ObjectMethods($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	ObjectMethods::$assertionsDisabled = !ObjectMethods::class$->desiredAssertionStatus();
	$load($MethodType);
	$assignStatic(ObjectMethods::DESCRIPTOR_MT, $MethodType::methodType($MethodType::class$));
	$load($List);
	$assignStatic(ObjectMethods::NAMES_MT, $MethodType::methodType($List::class$));
	$init($Boolean);
	$assignStatic(ObjectMethods::FALSE, $MethodHandles::constant($Boolean::TYPE, $($Boolean::valueOf(false))));
	$assignStatic(ObjectMethods::TRUE, $MethodHandles::constant($Boolean::TYPE, $($Boolean::valueOf(true))));
	$init($Integer);
	$assignStatic(ObjectMethods::ZERO, $MethodHandles::constant($Integer::TYPE, $($Integer::valueOf(0))));
	$assignStatic(ObjectMethods::primitiveEquals, $new($HashMap));
	$assignStatic(ObjectMethods::primitiveHashers, $new($HashMap));
	$assignStatic(ObjectMethods::primitiveToString, $new($HashMap));
	{
		try {
			$Class* OBJECT_METHODS_CLASS = ObjectMethods::class$;
			$var($MethodHandles$Lookup, publicLookup, $MethodHandles::publicLookup());
			$var($MethodHandles$Lookup, lookup, $MethodHandles::lookup());
			$var($ClassLoader, loader, $cast($ClassLoader, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ObjectMethods$1)))));
			$assignStatic(ObjectMethods::CLASS_IS_INSTANCE, $nc(publicLookup)->findVirtual($Class::class$, "isInstance"_s, $($MethodType::methodType($Boolean::TYPE, $Object::class$))));
			$assignStatic(ObjectMethods::OBJECT_EQUALS, publicLookup->findVirtual($Object::class$, "equals"_s, $($MethodType::methodType($Boolean::TYPE, $Object::class$))));
			$assignStatic(ObjectMethods::OBJECT_HASHCODE, publicLookup->findVirtual($Object::class$, "hashCode"_s, $($MethodType::fromMethodDescriptorString("()I"_s, loader))));
			$assignStatic(ObjectMethods::OBJECT_TO_STRING, publicLookup->findVirtual($Object::class$, "toString"_s, $($MethodType::methodType($String::class$))));
			$load($ObjectArray);
			$assignStatic(ObjectMethods::STRING_FORMAT, publicLookup->findStatic($String::class$, "format"_s, $($MethodType::methodType($String::class$, $String::class$, $$new($ClassArray, {$getClass($ObjectArray)})))));
			$load($Objects);
			$assignStatic(ObjectMethods::OBJECTS_EQUALS, publicLookup->findStatic($Objects::class$, "equals"_s, $($MethodType::methodType($Boolean::TYPE, $Object::class$, $$new($ClassArray, {$Object::class$})))));
			$assignStatic(ObjectMethods::OBJECTS_HASHCODE, publicLookup->findStatic($Objects::class$, "hashCode"_s, $($MethodType::methodType($Integer::TYPE, $Object::class$))));
			$assignStatic(ObjectMethods::OBJECTS_TOSTRING, publicLookup->findStatic($Objects::class$, "toString"_s, $($MethodType::methodType($String::class$, $Object::class$))));
			$assignStatic(ObjectMethods::OBJECT_EQ, $nc(lookup)->findStatic(OBJECT_METHODS_CLASS, "eq"_s, $($MethodType::methodType($Boolean::TYPE, $Object::class$, $$new($ClassArray, {$Object::class$})))));
			$assignStatic(ObjectMethods::HASH_COMBINER, lookup->findStatic(OBJECT_METHODS_CLASS, "hashCombiner"_s, $($MethodType::fromMethodDescriptorString("(II)I"_s, loader))));
			$init($Byte);
			$nc(ObjectMethods::primitiveEquals)->put($Byte::TYPE, $(lookup->findStatic(OBJECT_METHODS_CLASS, "eq"_s, $($MethodType::fromMethodDescriptorString("(BB)Z"_s, loader)))));
			$init($Short);
			$nc(ObjectMethods::primitiveEquals)->put($Short::TYPE, $(lookup->findStatic(OBJECT_METHODS_CLASS, "eq"_s, $($MethodType::fromMethodDescriptorString("(SS)Z"_s, loader)))));
			$init($Character);
			$nc(ObjectMethods::primitiveEquals)->put($Character::TYPE, $(lookup->findStatic(OBJECT_METHODS_CLASS, "eq"_s, $($MethodType::fromMethodDescriptorString("(CC)Z"_s, loader)))));
			$nc(ObjectMethods::primitiveEquals)->put($Integer::TYPE, $(lookup->findStatic(OBJECT_METHODS_CLASS, "eq"_s, $($MethodType::fromMethodDescriptorString("(II)Z"_s, loader)))));
			$init($Long);
			$nc(ObjectMethods::primitiveEquals)->put($Long::TYPE, $(lookup->findStatic(OBJECT_METHODS_CLASS, "eq"_s, $($MethodType::fromMethodDescriptorString("(JJ)Z"_s, loader)))));
			$init($Float);
			$nc(ObjectMethods::primitiveEquals)->put($Float::TYPE, $(lookup->findStatic(OBJECT_METHODS_CLASS, "eq"_s, $($MethodType::fromMethodDescriptorString("(FF)Z"_s, loader)))));
			$init($Double);
			$nc(ObjectMethods::primitiveEquals)->put($Double::TYPE, $(lookup->findStatic(OBJECT_METHODS_CLASS, "eq"_s, $($MethodType::fromMethodDescriptorString("(DD)Z"_s, loader)))));
			$nc(ObjectMethods::primitiveEquals)->put($Boolean::TYPE, $(lookup->findStatic(OBJECT_METHODS_CLASS, "eq"_s, $($MethodType::fromMethodDescriptorString("(ZZ)Z"_s, loader)))));
			$nc(ObjectMethods::primitiveHashers)->put($Byte::TYPE, $(lookup->findStatic($Byte::class$, "hashCode"_s, $($MethodType::fromMethodDescriptorString("(B)I"_s, loader)))));
			$nc(ObjectMethods::primitiveHashers)->put($Short::TYPE, $(lookup->findStatic($Short::class$, "hashCode"_s, $($MethodType::fromMethodDescriptorString("(S)I"_s, loader)))));
			$nc(ObjectMethods::primitiveHashers)->put($Character::TYPE, $(lookup->findStatic($Character::class$, "hashCode"_s, $($MethodType::fromMethodDescriptorString("(C)I"_s, loader)))));
			$nc(ObjectMethods::primitiveHashers)->put($Integer::TYPE, $(lookup->findStatic($Integer::class$, "hashCode"_s, $($MethodType::fromMethodDescriptorString("(I)I"_s, loader)))));
			$nc(ObjectMethods::primitiveHashers)->put($Long::TYPE, $(lookup->findStatic($Long::class$, "hashCode"_s, $($MethodType::fromMethodDescriptorString("(J)I"_s, loader)))));
			$nc(ObjectMethods::primitiveHashers)->put($Float::TYPE, $(lookup->findStatic($Float::class$, "hashCode"_s, $($MethodType::fromMethodDescriptorString("(F)I"_s, loader)))));
			$nc(ObjectMethods::primitiveHashers)->put($Double::TYPE, $(lookup->findStatic($Double::class$, "hashCode"_s, $($MethodType::fromMethodDescriptorString("(D)I"_s, loader)))));
			$nc(ObjectMethods::primitiveHashers)->put($Boolean::TYPE, $(lookup->findStatic($Boolean::class$, "hashCode"_s, $($MethodType::fromMethodDescriptorString("(Z)I"_s, loader)))));
			$nc(ObjectMethods::primitiveToString)->put($Byte::TYPE, $(lookup->findStatic($Byte::class$, "toString"_s, $($MethodType::methodType($String::class$, $Byte::TYPE)))));
			$nc(ObjectMethods::primitiveToString)->put($Short::TYPE, $(lookup->findStatic($Short::class$, "toString"_s, $($MethodType::methodType($String::class$, $Short::TYPE)))));
			$nc(ObjectMethods::primitiveToString)->put($Character::TYPE, $(lookup->findStatic($Character::class$, "toString"_s, $($MethodType::methodType($String::class$, $Character::TYPE)))));
			$nc(ObjectMethods::primitiveToString)->put($Integer::TYPE, $(lookup->findStatic($Integer::class$, "toString"_s, $($MethodType::methodType($String::class$, $Integer::TYPE)))));
			$nc(ObjectMethods::primitiveToString)->put($Long::TYPE, $(lookup->findStatic($Long::class$, "toString"_s, $($MethodType::methodType($String::class$, $Long::TYPE)))));
			$nc(ObjectMethods::primitiveToString)->put($Float::TYPE, $(lookup->findStatic($Float::class$, "toString"_s, $($MethodType::methodType($String::class$, $Float::TYPE)))));
			$nc(ObjectMethods::primitiveToString)->put($Double::TYPE, $(lookup->findStatic($Double::class$, "toString"_s, $($MethodType::methodType($String::class$, $Double::TYPE)))));
			$nc(ObjectMethods::primitiveToString)->put($Boolean::TYPE, $(lookup->findStatic($Boolean::class$, "toString"_s, $($MethodType::methodType($String::class$, $Boolean::TYPE)))));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($RuntimeException, static_cast<$Throwable*>(e));
		}
	}
}

ObjectMethods::ObjectMethods() {
}

$Class* ObjectMethods::load$($String* name, bool initialize) {
	$loadClass(ObjectMethods, name, initialize, &_ObjectMethods_ClassInfo_, clinit$ObjectMethods, allocate$ObjectMethods);
	return class$;
}

$Class* ObjectMethods::class$ = nullptr;

		} // runtime
	} // lang
} // java