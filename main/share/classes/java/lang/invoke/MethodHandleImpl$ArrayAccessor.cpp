#include <java/lang/invoke/MethodHandleImpl$ArrayAccessor.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ClassValue.h>
#include <java/lang/Error.h>
#include <java/lang/InternalError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/InvokerBytecodeGenerator.h>
#include <java/lang/invoke/MemberName.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleImpl$2.h>
#include <java/lang/invoke/MethodHandleImpl$ArrayAccess.h>
#include <java/lang/invoke/MethodHandleImpl$ArrayAccessor$1.h>
#include <java/lang/invoke/MethodHandleImpl$Intrinsic.h>
#include <java/lang/invoke/MethodHandleImpl.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <sun/invoke/util/Wrapper.h>
#include <jcpp.h>

#undef ARRAY_LENGTH
#undef ARRAY_LOAD
#undef ARRAY_STORE
#undef GET
#undef GETTER_INDEX
#undef IMPL_LOOKUP
#undef INDEX_LIMIT
#undef LENGTH
#undef LENGTH_INDEX
#undef OBJECT_ARRAY_GETTER
#undef OBJECT_ARRAY_LENGTH
#undef OBJECT_ARRAY_SETTER
#undef SET
#undef SETTER_INDEX
#undef TYPE
#undef TYPED_ACCESSORS

using $MethodHandleArray = $Array<::java::lang::invoke::MethodHandle>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassValue = ::java::lang::ClassValue;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Void = ::java::lang::Void;
using $InvokerBytecodeGenerator = ::java::lang::invoke::InvokerBytecodeGenerator;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleImpl = ::java::lang::invoke::MethodHandleImpl;
using $MethodHandleImpl$2 = ::java::lang::invoke::MethodHandleImpl$2;
using $MethodHandleImpl$ArrayAccess = ::java::lang::invoke::MethodHandleImpl$ArrayAccess;
using $MethodHandleImpl$ArrayAccessor$1 = ::java::lang::invoke::MethodHandleImpl$ArrayAccessor$1;
using $MethodHandleImpl$Intrinsic = ::java::lang::invoke::MethodHandleImpl$Intrinsic;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Wrapper = ::sun::invoke::util::Wrapper;

namespace java {
	namespace lang {
		namespace invoke {

$FieldInfo _MethodHandleImpl$ArrayAccessor_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MethodHandleImpl$ArrayAccessor, $assertionsDisabled)},
	{"GETTER_INDEX", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl$ArrayAccessor, GETTER_INDEX)},
	{"SETTER_INDEX", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl$ArrayAccessor, SETTER_INDEX)},
	{"LENGTH_INDEX", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl$ArrayAccessor, LENGTH_INDEX)},
	{"INDEX_LIMIT", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl$ArrayAccessor, INDEX_LIMIT)},
	{"TYPED_ACCESSORS", "Ljava/lang/ClassValue;", "Ljava/lang/ClassValue<[Ljava/lang/invoke/MethodHandle;>;", $STATIC | $FINAL, $staticField(MethodHandleImpl$ArrayAccessor, TYPED_ACCESSORS)},
	{"OBJECT_ARRAY_GETTER", "Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC | $FINAL, $staticField(MethodHandleImpl$ArrayAccessor, OBJECT_ARRAY_GETTER)},
	{"OBJECT_ARRAY_SETTER", "Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC | $FINAL, $staticField(MethodHandleImpl$ArrayAccessor, OBJECT_ARRAY_SETTER)},
	{"OBJECT_ARRAY_LENGTH", "Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC | $FINAL, $staticField(MethodHandleImpl$ArrayAccessor, OBJECT_ARRAY_LENGTH)},
	{}
};

$MethodInfo _MethodHandleImpl$ArrayAccessor_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(MethodHandleImpl$ArrayAccessor, init$, void)},
	{"correctType", "(Ljava/lang/Class;Ljava/lang/invoke/MethodHandleImpl$ArrayAccess;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandleImpl$ArrayAccess;)Ljava/lang/invoke/MethodType;", $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, correctType, $MethodType*, $Class*, $MethodHandleImpl$ArrayAccess*)},
	{"getAccessor", "(Ljava/lang/Class;Ljava/lang/invoke/MethodHandleImpl$ArrayAccess;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandleImpl$ArrayAccess;)Ljava/lang/invoke/MethodHandle;", $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, getAccessor, $MethodHandle*, $Class*, $MethodHandleImpl$ArrayAccess*)},
	{"getElementB", "([BI)B", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, getElementB, int8_t, $bytes*, int32_t)},
	{"getElementC", "([CI)C", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, getElementC, char16_t, $chars*, int32_t)},
	{"getElementD", "([DI)D", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, getElementD, double, $doubles*, int32_t)},
	{"getElementF", "([FI)F", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, getElementF, float, $floats*, int32_t)},
	{"getElementI", "([II)I", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, getElementI, int32_t, $ints*, int32_t)},
	{"getElementJ", "([JI)J", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, getElementJ, int64_t, $longs*, int32_t)},
	{"getElementL", "([Ljava/lang/Object;I)Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, getElementL, $Object*, $ObjectArray*, int32_t)},
	{"getElementS", "([SI)S", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, getElementS, int16_t, $shorts*, int32_t)},
	{"getElementZ", "([ZI)Z", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, getElementZ, bool, $booleans*, int32_t)},
	{"lengthB", "([B)I", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, lengthB, int32_t, $bytes*)},
	{"lengthC", "([C)I", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, lengthC, int32_t, $chars*)},
	{"lengthD", "([D)I", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, lengthD, int32_t, $doubles*)},
	{"lengthF", "([F)I", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, lengthF, int32_t, $floats*)},
	{"lengthI", "([I)I", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, lengthI, int32_t, $ints*)},
	{"lengthJ", "([J)I", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, lengthJ, int32_t, $longs*)},
	{"lengthL", "([Ljava/lang/Object;)I", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, lengthL, int32_t, $ObjectArray*)},
	{"lengthS", "([S)I", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, lengthS, int32_t, $shorts*)},
	{"lengthZ", "([Z)I", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, lengthZ, int32_t, $booleans*)},
	{"name", "(Ljava/lang/Class;Ljava/lang/invoke/MethodHandleImpl$ArrayAccess;)Ljava/lang/String;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandleImpl$ArrayAccess;)Ljava/lang/String;", $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, name, $String*, $Class*, $MethodHandleImpl$ArrayAccess*)},
	{"setElementB", "([BIB)V", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, setElementB, void, $bytes*, int32_t, int8_t)},
	{"setElementC", "([CIC)V", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, setElementC, void, $chars*, int32_t, char16_t)},
	{"setElementD", "([DID)V", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, setElementD, void, $doubles*, int32_t, double)},
	{"setElementF", "([FIF)V", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, setElementF, void, $floats*, int32_t, float)},
	{"setElementI", "([III)V", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, setElementI, void, $ints*, int32_t, int32_t)},
	{"setElementJ", "([JIJ)V", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, setElementJ, void, $longs*, int32_t, int64_t)},
	{"setElementL", "([Ljava/lang/Object;ILjava/lang/Object;)V", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, setElementL, void, $ObjectArray*, int32_t, Object$*)},
	{"setElementS", "([SIS)V", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, setElementS, void, $shorts*, int32_t, int16_t)},
	{"setElementZ", "([ZIZ)V", nullptr, $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, setElementZ, void, $booleans*, int32_t, bool)},
	{"type", "(Ljava/lang/Class;Ljava/lang/invoke/MethodHandleImpl$ArrayAccess;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandleImpl$ArrayAccess;)Ljava/lang/invoke/MethodType;", $STATIC, $staticMethod(MethodHandleImpl$ArrayAccessor, type, $MethodType*, $Class*, $MethodHandleImpl$ArrayAccess*)},
	{}
};

$InnerClassInfo _MethodHandleImpl$ArrayAccessor_InnerClassesInfo_[] = {
	{"java.lang.invoke.MethodHandleImpl$ArrayAccessor", "java.lang.invoke.MethodHandleImpl", "ArrayAccessor", $STATIC | $FINAL},
	{"java.lang.invoke.MethodHandleImpl$ArrayAccessor$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _MethodHandleImpl$ArrayAccessor_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.invoke.MethodHandleImpl$ArrayAccessor",
	"java.lang.Object",
	nullptr,
	_MethodHandleImpl$ArrayAccessor_FieldInfo_,
	_MethodHandleImpl$ArrayAccessor_MethodInfo_,
	nullptr,
	nullptr,
	_MethodHandleImpl$ArrayAccessor_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.invoke.MethodHandleImpl"
};

$Object* allocate$MethodHandleImpl$ArrayAccessor($Class* clazz) {
	return $of($alloc(MethodHandleImpl$ArrayAccessor));
}

bool MethodHandleImpl$ArrayAccessor::$assertionsDisabled = false;
$ClassValue* MethodHandleImpl$ArrayAccessor::TYPED_ACCESSORS = nullptr;
$MethodHandle* MethodHandleImpl$ArrayAccessor::OBJECT_ARRAY_GETTER = nullptr;
$MethodHandle* MethodHandleImpl$ArrayAccessor::OBJECT_ARRAY_SETTER = nullptr;
$MethodHandle* MethodHandleImpl$ArrayAccessor::OBJECT_ARRAY_LENGTH = nullptr;

void MethodHandleImpl$ArrayAccessor::init$() {
}

int32_t MethodHandleImpl$ArrayAccessor::getElementI($ints* a, int32_t i) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->get(i);
}

int64_t MethodHandleImpl$ArrayAccessor::getElementJ($longs* a, int32_t i) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->get(i);
}

float MethodHandleImpl$ArrayAccessor::getElementF($floats* a, int32_t i) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->get(i);
}

double MethodHandleImpl$ArrayAccessor::getElementD($doubles* a, int32_t i) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->get(i);
}

bool MethodHandleImpl$ArrayAccessor::getElementZ($booleans* a, int32_t i) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->get(i);
}

int8_t MethodHandleImpl$ArrayAccessor::getElementB($bytes* a, int32_t i) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->get(i);
}

int16_t MethodHandleImpl$ArrayAccessor::getElementS($shorts* a, int32_t i) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->get(i);
}

char16_t MethodHandleImpl$ArrayAccessor::getElementC($chars* a, int32_t i) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->get(i);
}

$Object* MethodHandleImpl$ArrayAccessor::getElementL($ObjectArray* a, int32_t i) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $of($nc(a)->get(i));
}

void MethodHandleImpl$ArrayAccessor::setElementI($ints* a, int32_t i, int32_t x) {
	$init(MethodHandleImpl$ArrayAccessor);
	$nc(a)->set(i, x);
}

void MethodHandleImpl$ArrayAccessor::setElementJ($longs* a, int32_t i, int64_t x) {
	$init(MethodHandleImpl$ArrayAccessor);
	$nc(a)->set(i, x);
}

void MethodHandleImpl$ArrayAccessor::setElementF($floats* a, int32_t i, float x) {
	$init(MethodHandleImpl$ArrayAccessor);
	$nc(a)->set(i, x);
}

void MethodHandleImpl$ArrayAccessor::setElementD($doubles* a, int32_t i, double x) {
	$init(MethodHandleImpl$ArrayAccessor);
	$nc(a)->set(i, x);
}

void MethodHandleImpl$ArrayAccessor::setElementZ($booleans* a, int32_t i, bool x) {
	$init(MethodHandleImpl$ArrayAccessor);
	$nc(a)->set(i, x);
}

void MethodHandleImpl$ArrayAccessor::setElementB($bytes* a, int32_t i, int8_t x) {
	$init(MethodHandleImpl$ArrayAccessor);
	$nc(a)->set(i, x);
}

void MethodHandleImpl$ArrayAccessor::setElementS($shorts* a, int32_t i, int16_t x) {
	$init(MethodHandleImpl$ArrayAccessor);
	$nc(a)->set(i, x);
}

void MethodHandleImpl$ArrayAccessor::setElementC($chars* a, int32_t i, char16_t x) {
	$init(MethodHandleImpl$ArrayAccessor);
	$nc(a)->set(i, x);
}

void MethodHandleImpl$ArrayAccessor::setElementL($ObjectArray* a, int32_t i, Object$* x) {
	$init(MethodHandleImpl$ArrayAccessor);
	$nc(a)->set(i, x);
}

int32_t MethodHandleImpl$ArrayAccessor::lengthI($ints* a) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->length;
}

int32_t MethodHandleImpl$ArrayAccessor::lengthJ($longs* a) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->length;
}

int32_t MethodHandleImpl$ArrayAccessor::lengthF($floats* a) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->length;
}

int32_t MethodHandleImpl$ArrayAccessor::lengthD($doubles* a) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->length;
}

int32_t MethodHandleImpl$ArrayAccessor::lengthZ($booleans* a) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->length;
}

int32_t MethodHandleImpl$ArrayAccessor::lengthB($bytes* a) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->length;
}

int32_t MethodHandleImpl$ArrayAccessor::lengthS($shorts* a) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->length;
}

int32_t MethodHandleImpl$ArrayAccessor::lengthC($chars* a) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->length;
}

int32_t MethodHandleImpl$ArrayAccessor::lengthL($ObjectArray* a) {
	$init(MethodHandleImpl$ArrayAccessor);
	return $nc(a)->length;
}

$String* MethodHandleImpl$ArrayAccessor::name($Class* arrayClass, $MethodHandleImpl$ArrayAccess* access) {
	$init(MethodHandleImpl$ArrayAccessor);
	$useLocalCurrentObjectStackCache();
	$Class* elemClass = $nc(arrayClass)->getComponentType();
	if (elemClass == nullptr) {
		$throw($($MethodHandleStatics::newIllegalArgumentException("not an array"_s, arrayClass)));
	}
	$var($String, var$0, $($MethodHandleImpl$ArrayAccess::opName(access)));
	return $concat(var$0, $$str($Wrapper::basicTypeChar(elemClass)));
}

$MethodType* MethodHandleImpl$ArrayAccessor::type($Class* arrayClass, $MethodHandleImpl$ArrayAccess* access) {
	$init(MethodHandleImpl$ArrayAccessor);
	$useLocalCurrentObjectStackCache();
	$Class* elemClass = $nc(arrayClass)->getComponentType();
	$Class* arrayArgClass = arrayClass;
	if (!$nc(elemClass)->isPrimitive()) {
		$load($ObjectArray);
		arrayArgClass = $getClass($ObjectArray);
		elemClass = $Object::class$;
	}
	$init($MethodHandleImpl$2);

	$var($MethodType, var$0, nullptr)
	switch ($nc($MethodHandleImpl$2::$SwitchMap$java$lang$invoke$MethodHandleImpl$ArrayAccess)->get($nc((access))->ordinal())) {
	case 1:
		{
			$init($Integer);
			$assign(var$0, $MethodType::methodType(elemClass, arrayArgClass, $$new($ClassArray, {$Integer::TYPE})));
			break;
		}
	case 2:
		{
			$init($Void);
			$init($Integer);
			$assign(var$0, $MethodType::methodType($Void::TYPE, arrayArgClass, $$new($ClassArray, {
				$Integer::TYPE,
				elemClass
			})));
			break;
		}
	case 3:
		{
			$init($Integer);
			$assign(var$0, $MethodType::methodType($Integer::TYPE, arrayArgClass));
			break;
		}
	default:
		{
			$throw($($MethodHandleImpl::unmatchedArrayAccess(access)));
		}
	}
	return var$0;
}

$MethodType* MethodHandleImpl$ArrayAccessor::correctType($Class* arrayClass, $MethodHandleImpl$ArrayAccess* access) {
	$init(MethodHandleImpl$ArrayAccessor);
	$useLocalCurrentObjectStackCache();
	$Class* elemClass = $nc(arrayClass)->getComponentType();
	$init($MethodHandleImpl$2);

	$var($MethodType, var$0, nullptr)
	switch ($nc($MethodHandleImpl$2::$SwitchMap$java$lang$invoke$MethodHandleImpl$ArrayAccess)->get($nc((access))->ordinal())) {
	case 1:
		{
			$init($Integer);
			$assign(var$0, $MethodType::methodType(elemClass, arrayClass, $$new($ClassArray, {$Integer::TYPE})));
			break;
		}
	case 2:
		{
			$init($Void);
			$init($Integer);
			$assign(var$0, $MethodType::methodType($Void::TYPE, arrayClass, $$new($ClassArray, {
				$Integer::TYPE,
				elemClass
			})));
			break;
		}
	case 3:
		{
			$init($Integer);
			$assign(var$0, $MethodType::methodType($Integer::TYPE, arrayClass));
			break;
		}
	default:
		{
			$throw($($MethodHandleImpl::unmatchedArrayAccess(access)));
		}
	}
	return var$0;
}

$MethodHandle* MethodHandleImpl$ArrayAccessor::getAccessor($Class* arrayClass, $MethodHandleImpl$ArrayAccess* access) {
	$init(MethodHandleImpl$ArrayAccessor);
	$useLocalCurrentObjectStackCache();
	$var($String, name, MethodHandleImpl$ArrayAccessor::name(arrayClass, access));
	$var($MethodType, type, MethodHandleImpl$ArrayAccessor::type(arrayClass, access));
	try {
		$init($MethodHandles$Lookup);
		return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findStatic(MethodHandleImpl$ArrayAccessor::class$, name, type);
	} catch ($ReflectiveOperationException& ex) {
		$throw($($MethodHandleStatics::uncaughtException(ex)));
	}
	$shouldNotReachHere();
}

void clinit$MethodHandleImpl$ArrayAccessor($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$load($MethodHandleImpl);
	MethodHandleImpl$ArrayAccessor::$assertionsDisabled = !$MethodHandleImpl::class$->desiredAssertionStatus();
	$assignStatic(MethodHandleImpl$ArrayAccessor::TYPED_ACCESSORS, $new($MethodHandleImpl$ArrayAccessor$1));
	{
		$load($ObjectArray);
		$var($MethodHandleArray, cache, $cast($MethodHandleArray, $nc(MethodHandleImpl$ArrayAccessor::TYPED_ACCESSORS)->get($getClass($ObjectArray))));
		$init($MethodHandleImpl$ArrayAccess);
		$init($MethodHandleImpl$Intrinsic);
		$nc(cache)->set(MethodHandleImpl$ArrayAccessor::GETTER_INDEX, $assignStatic(MethodHandleImpl$ArrayAccessor::OBJECT_ARRAY_GETTER, $MethodHandleImpl::makeIntrinsic($(MethodHandleImpl$ArrayAccessor::getAccessor($getClass($ObjectArray), $MethodHandleImpl$ArrayAccess::GET)), $MethodHandleImpl$Intrinsic::ARRAY_LOAD)));
		cache->set(MethodHandleImpl$ArrayAccessor::SETTER_INDEX, $assignStatic(MethodHandleImpl$ArrayAccessor::OBJECT_ARRAY_SETTER, $MethodHandleImpl::makeIntrinsic($(MethodHandleImpl$ArrayAccessor::getAccessor($getClass($ObjectArray), $MethodHandleImpl$ArrayAccess::SET)), $MethodHandleImpl$Intrinsic::ARRAY_STORE)));
		cache->set(MethodHandleImpl$ArrayAccessor::LENGTH_INDEX, $assignStatic(MethodHandleImpl$ArrayAccessor::OBJECT_ARRAY_LENGTH, $MethodHandleImpl::makeIntrinsic($(MethodHandleImpl$ArrayAccessor::getAccessor($getClass($ObjectArray), $MethodHandleImpl$ArrayAccess::LENGTH)), $MethodHandleImpl$Intrinsic::ARRAY_LENGTH)));
		if (!MethodHandleImpl$ArrayAccessor::$assertionsDisabled && !($InvokerBytecodeGenerator::isStaticallyInvocable($($nc(MethodHandleImpl$ArrayAccessor::OBJECT_ARRAY_GETTER)->internalMemberName())))) {
			$throwNew($AssertionError);
		}
		if (!MethodHandleImpl$ArrayAccessor::$assertionsDisabled && !($InvokerBytecodeGenerator::isStaticallyInvocable($($nc(MethodHandleImpl$ArrayAccessor::OBJECT_ARRAY_SETTER)->internalMemberName())))) {
			$throwNew($AssertionError);
		}
		if (!MethodHandleImpl$ArrayAccessor::$assertionsDisabled && !($InvokerBytecodeGenerator::isStaticallyInvocable($($nc(MethodHandleImpl$ArrayAccessor::OBJECT_ARRAY_LENGTH)->internalMemberName())))) {
			$throwNew($AssertionError);
		}
	}
}

MethodHandleImpl$ArrayAccessor::MethodHandleImpl$ArrayAccessor() {
}

$Class* MethodHandleImpl$ArrayAccessor::load$($String* name, bool initialize) {
	$loadClass(MethodHandleImpl$ArrayAccessor, name, initialize, &_MethodHandleImpl$ArrayAccessor_ClassInfo_, clinit$MethodHandleImpl$ArrayAccessor, allocate$MethodHandleImpl$ArrayAccessor);
	return class$;
}

$Class* MethodHandleImpl$ArrayAccessor::class$ = nullptr;

		} // invoke
	} // lang
} // java