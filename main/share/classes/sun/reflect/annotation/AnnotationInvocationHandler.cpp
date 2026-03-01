#include <sun/reflect/annotation/AnnotationInvocationHandler.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/annotation/AnnotationFormatError.h>
#include <java/lang/annotation/IncompleteAnnotationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Array.h>
#include <java/lang/reflect/InvocationHandler.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Proxy.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/function/DoubleFunction.h>
#include <java/util/function/Function.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/LongFunction.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/DoubleStream.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/Stream.h>
#include <sun/reflect/annotation/AnnotationInvocationHandler$1.h>
#include <sun/reflect/annotation/AnnotationInvocationHandler$UnsafeAccessor.h>
#include <sun/reflect/annotation/AnnotationType.h>
#include <sun/reflect/annotation/AnnotationTypeMismatchExceptionProxy.h>
#include <sun/reflect/annotation/ExceptionProxy.h>
#include <jcpp.h>

#undef ABSTRACT
#undef PRIVATE
#undef PUBLIC
#undef STATIC
#undef TYPE

using $MethodArray = $Array<::java::lang::reflect::Method>;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Short = ::java::lang::Short;
using $Void = ::java::lang::Void;
using $Annotation = ::java::lang::annotation::Annotation;
using $AnnotationFormatError = ::java::lang::annotation::AnnotationFormatError;
using $IncompleteAnnotationException = ::java::lang::annotation::IncompleteAnnotationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $1Array = ::java::lang::reflect::Array;
using $InvocationHandler = ::java::lang::reflect::InvocationHandler;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $Proxy = ::java::lang::reflect::Proxy;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $DoubleFunction = ::java::util::function::DoubleFunction;
using $Function = ::java::util::function::Function;
using $IntFunction = ::java::util::function::IntFunction;
using $LongFunction = ::java::util::function::LongFunction;
using $Collectors = ::java::util::stream::Collectors;
using $DoubleStream = ::java::util::stream::DoubleStream;
using $IntStream = ::java::util::stream::IntStream;
using $LongStream = ::java::util::stream::LongStream;
using $Stream = ::java::util::stream::Stream;
using $AnnotationInvocationHandler$1 = ::sun::reflect::annotation::AnnotationInvocationHandler$1;
using $AnnotationInvocationHandler$UnsafeAccessor = ::sun::reflect::annotation::AnnotationInvocationHandler$UnsafeAccessor;
using $AnnotationType = ::sun::reflect::annotation::AnnotationType;
using $AnnotationTypeMismatchExceptionProxy = ::sun::reflect::annotation::AnnotationTypeMismatchExceptionProxy;
using $ExceptionProxy = ::sun::reflect::annotation::ExceptionProxy;

namespace sun {
	namespace reflect {
		namespace annotation {

class AnnotationInvocationHandler$$Lambda$toSourceString : public $DoubleFunction {
	$class(AnnotationInvocationHandler$$Lambda$toSourceString, $NO_CLASS_INIT, $DoubleFunction)
public:
	void init$() {
	}
	virtual $Object* apply(double d) override {
		 return $of(AnnotationInvocationHandler::toSourceString(d));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AnnotationInvocationHandler$$Lambda$toSourceString>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo AnnotationInvocationHandler$$Lambda$toSourceString::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AnnotationInvocationHandler$$Lambda$toSourceString, init$, void)},
	{"apply", "(D)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AnnotationInvocationHandler$$Lambda$toSourceString, apply, $Object*, double)},
	{}
};
$ClassInfo AnnotationInvocationHandler$$Lambda$toSourceString::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.reflect.annotation.AnnotationInvocationHandler$$Lambda$toSourceString",
	"java.lang.Object",
	"java.util.function.DoubleFunction",
	nullptr,
	methodInfos
};
$Class* AnnotationInvocationHandler$$Lambda$toSourceString::load$($String* name, bool initialize) {
	$loadClass(AnnotationInvocationHandler$$Lambda$toSourceString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AnnotationInvocationHandler$$Lambda$toSourceString::class$ = nullptr;

class AnnotationInvocationHandler$$Lambda$valueOf$1 : public $IntFunction {
	$class(AnnotationInvocationHandler$$Lambda$valueOf$1, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t i) override {
		 return $of($String::valueOf(i));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AnnotationInvocationHandler$$Lambda$valueOf$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo AnnotationInvocationHandler$$Lambda$valueOf$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AnnotationInvocationHandler$$Lambda$valueOf$1, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AnnotationInvocationHandler$$Lambda$valueOf$1, apply, $Object*, int32_t)},
	{}
};
$ClassInfo AnnotationInvocationHandler$$Lambda$valueOf$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.reflect.annotation.AnnotationInvocationHandler$$Lambda$valueOf$1",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* AnnotationInvocationHandler$$Lambda$valueOf$1::load$($String* name, bool initialize) {
	$loadClass(AnnotationInvocationHandler$$Lambda$valueOf$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AnnotationInvocationHandler$$Lambda$valueOf$1::class$ = nullptr;

class AnnotationInvocationHandler$$Lambda$toSourceString$2 : public $LongFunction {
	$class(AnnotationInvocationHandler$$Lambda$toSourceString$2, $NO_CLASS_INIT, $LongFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int64_t ell) override {
		 return $of(AnnotationInvocationHandler::toSourceString(ell));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AnnotationInvocationHandler$$Lambda$toSourceString$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo AnnotationInvocationHandler$$Lambda$toSourceString$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AnnotationInvocationHandler$$Lambda$toSourceString$2, init$, void)},
	{"apply", "(J)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AnnotationInvocationHandler$$Lambda$toSourceString$2, apply, $Object*, int64_t)},
	{}
};
$ClassInfo AnnotationInvocationHandler$$Lambda$toSourceString$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.reflect.annotation.AnnotationInvocationHandler$$Lambda$toSourceString$2",
	"java.lang.Object",
	"java.util.function.LongFunction",
	nullptr,
	methodInfos
};
$Class* AnnotationInvocationHandler$$Lambda$toSourceString$2::load$($String* name, bool initialize) {
	$loadClass(AnnotationInvocationHandler$$Lambda$toSourceString$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AnnotationInvocationHandler$$Lambda$toSourceString$2::class$ = nullptr;

class AnnotationInvocationHandler$$Lambda$toSourceString$3 : public $Function {
	$class(AnnotationInvocationHandler$$Lambda$toSourceString$3, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* clazz) override {
		 return $of(AnnotationInvocationHandler::toSourceString($cast($Class, clazz)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AnnotationInvocationHandler$$Lambda$toSourceString$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo AnnotationInvocationHandler$$Lambda$toSourceString$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AnnotationInvocationHandler$$Lambda$toSourceString$3, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AnnotationInvocationHandler$$Lambda$toSourceString$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo AnnotationInvocationHandler$$Lambda$toSourceString$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.reflect.annotation.AnnotationInvocationHandler$$Lambda$toSourceString$3",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* AnnotationInvocationHandler$$Lambda$toSourceString$3::load$($String* name, bool initialize) {
	$loadClass(AnnotationInvocationHandler$$Lambda$toSourceString$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AnnotationInvocationHandler$$Lambda$toSourceString$3::class$ = nullptr;

class AnnotationInvocationHandler$$Lambda$toSourceString$4 : public $Function {
	$class(AnnotationInvocationHandler$$Lambda$toSourceString$4, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(AnnotationInvocationHandler::toSourceString($cast($String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AnnotationInvocationHandler$$Lambda$toSourceString$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo AnnotationInvocationHandler$$Lambda$toSourceString$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AnnotationInvocationHandler$$Lambda$toSourceString$4, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AnnotationInvocationHandler$$Lambda$toSourceString$4, apply, $Object*, Object$*)},
	{}
};
$ClassInfo AnnotationInvocationHandler$$Lambda$toSourceString$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.reflect.annotation.AnnotationInvocationHandler$$Lambda$toSourceString$4",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* AnnotationInvocationHandler$$Lambda$toSourceString$4::load$($String* name, bool initialize) {
	$loadClass(AnnotationInvocationHandler$$Lambda$toSourceString$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AnnotationInvocationHandler$$Lambda$toSourceString$4::class$ = nullptr;

class AnnotationInvocationHandler$$Lambda$toString$5 : public $Function {
	$class(AnnotationInvocationHandler$$Lambda$toString$5, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* o) override {
		 return $of($Objects::toString(o));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AnnotationInvocationHandler$$Lambda$toString$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo AnnotationInvocationHandler$$Lambda$toString$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AnnotationInvocationHandler$$Lambda$toString$5, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AnnotationInvocationHandler$$Lambda$toString$5, apply, $Object*, Object$*)},
	{}
};
$ClassInfo AnnotationInvocationHandler$$Lambda$toString$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.reflect.annotation.AnnotationInvocationHandler$$Lambda$toString$5",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* AnnotationInvocationHandler$$Lambda$toString$5::load$($String* name, bool initialize) {
	$loadClass(AnnotationInvocationHandler$$Lambda$toString$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AnnotationInvocationHandler$$Lambda$toString$5::class$ = nullptr;

$FieldInfo _AnnotationInvocationHandler_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(AnnotationInvocationHandler, $assertionsDisabled)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(AnnotationInvocationHandler, serialVersionUID)},
	{"type", "Ljava/lang/Class;", "Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;", $PRIVATE | $FINAL, $field(AnnotationInvocationHandler, type)},
	{"memberValues", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(AnnotationInvocationHandler, memberValues)},
	{"memberMethods", "[Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(AnnotationInvocationHandler, memberMethods)},
	{}
};

$MethodInfo _AnnotationInvocationHandler_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/lang/Class;Ljava/util/Map;)V", "(Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;)V", 0, $method(AnnotationInvocationHandler, init$, void, $Class*, $Map*)},
	{"asOneOfUs", "(Ljava/lang/Object;)Lsun/reflect/annotation/AnnotationInvocationHandler;", nullptr, $PRIVATE, $method(AnnotationInvocationHandler, asOneOfUs, AnnotationInvocationHandler*, Object$*)},
	{"cloneArray", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(AnnotationInvocationHandler, cloneArray, $Object*, Object$*)},
	{"computeMemberMethods", "()[Ljava/lang/reflect/Method;", nullptr, $PRIVATE, $method(AnnotationInvocationHandler, computeMemberMethods, $MethodArray*)},
	{"convert", "([B)Ljava/util/stream/Stream;", "([B)Ljava/util/stream/Stream<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, convert, $Stream*, $bytes*)},
	{"convert", "([C)Ljava/util/stream/Stream;", "([C)Ljava/util/stream/Stream<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, convert, $Stream*, $chars*)},
	{"convert", "([F)Ljava/util/stream/Stream;", "([F)Ljava/util/stream/Stream<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, convert, $Stream*, $floats*)},
	{"convert", "([S)Ljava/util/stream/Stream;", "([S)Ljava/util/stream/Stream<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, convert, $Stream*, $shorts*)},
	{"convert", "([Z)Ljava/util/stream/Stream;", "([Z)Ljava/util/stream/Stream<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, convert, $Stream*, $booleans*)},
	{"equalsImpl", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Boolean;", nullptr, $PRIVATE, $method(AnnotationInvocationHandler, equalsImpl, $Boolean*, Object$*, Object$*)},
	{"getMemberMethods", "()[Ljava/lang/reflect/Method;", nullptr, $PRIVATE, $method(AnnotationInvocationHandler, getMemberMethods, $MethodArray*)},
	{"hashCodeImpl", "()I", nullptr, $PRIVATE, $method(AnnotationInvocationHandler, hashCodeImpl, int32_t)},
	{"invoke", "(Ljava/lang/Object;Ljava/lang/reflect/Method;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AnnotationInvocationHandler, invoke, $Object*, Object$*, $Method*, $ObjectArray*)},
	{"isPrintableAscii", "(C)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, isPrintableAscii, bool, char16_t)},
	{"memberValueEquals", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, memberValueEquals, bool, Object$*, Object$*)},
	{"memberValueHashCode", "(Ljava/lang/Object;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, memberValueHashCode, int32_t, Object$*)},
	{"memberValueToString", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, memberValueToString, $String*, Object$*)},
	{"quote", "(C)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, quote, $String*, char16_t)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(AnnotationInvocationHandler, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"stringStreamToString", "(Ljava/util/stream/Stream;)Ljava/lang/String;", "(Ljava/util/stream/Stream<Ljava/lang/String;>;)Ljava/lang/String;", $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, stringStreamToString, $String*, $Stream*)},
	{"toSourceString", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, toSourceString, $String*, $Class*)},
	{"toSourceString", "(F)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, toSourceString, $String*, float)},
	{"toSourceString", "(D)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, toSourceString, $String*, double)},
	{"toSourceString", "(C)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, toSourceString, $String*, char16_t)},
	{"toSourceString", "(B)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, toSourceString, $String*, int8_t)},
	{"toSourceString", "(J)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, toSourceString, $String*, int64_t)},
	{"toSourceString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(AnnotationInvocationHandler, toSourceString, $String*, $String*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"toStringImpl", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(AnnotationInvocationHandler, toStringImpl, $String*)},
	{"validateAnnotationMethods", "([Ljava/lang/reflect/Method;)V", nullptr, $PRIVATE, $method(AnnotationInvocationHandler, validateAnnotationMethods, void, $MethodArray*)},
	{}
};

$InnerClassInfo _AnnotationInvocationHandler_InnerClassesInfo_[] = {
	{"sun.reflect.annotation.AnnotationInvocationHandler$UnsafeAccessor", "sun.reflect.annotation.AnnotationInvocationHandler", "UnsafeAccessor", $PRIVATE | $STATIC},
	{"sun.reflect.annotation.AnnotationInvocationHandler$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _AnnotationInvocationHandler_ClassInfo_ = {
	$ACC_SUPER,
	"sun.reflect.annotation.AnnotationInvocationHandler",
	"java.lang.Object",
	"java.lang.reflect.InvocationHandler,java.io.Serializable",
	_AnnotationInvocationHandler_FieldInfo_,
	_AnnotationInvocationHandler_MethodInfo_,
	nullptr,
	nullptr,
	_AnnotationInvocationHandler_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.reflect.annotation.AnnotationInvocationHandler$UnsafeAccessor,sun.reflect.annotation.AnnotationInvocationHandler$1"
};

$Object* allocate$AnnotationInvocationHandler($Class* clazz) {
	return $of($alloc(AnnotationInvocationHandler));
}

int32_t AnnotationInvocationHandler::hashCode() {
	 return this->$InvocationHandler::hashCode();
}

bool AnnotationInvocationHandler::equals(Object$* obj) {
	 return this->$InvocationHandler::equals(obj);
}

$Object* AnnotationInvocationHandler::clone() {
	 return this->$InvocationHandler::clone();
}

$String* AnnotationInvocationHandler::toString() {
	 return this->$InvocationHandler::toString();
}

void AnnotationInvocationHandler::finalize() {
	this->$InvocationHandler::finalize();
}

bool AnnotationInvocationHandler::$assertionsDisabled = false;

void AnnotationInvocationHandler::init$($Class* type, $Map* memberValues) {
	$useLocalCurrentObjectStackCache();
	$var($ClassArray, superInterfaces, $nc(type)->getInterfaces());
	$load($Annotation);
	if (!type->isAnnotation() || superInterfaces->length != 1 || superInterfaces->get(0) != $Annotation::class$) {
		$throwNew($AnnotationFormatError, $$str({"Attempt to create proxy for a non-annotation type: "_s, $(type->getName())}));
	}
	$set(this, type, type);
	$set(this, memberValues, memberValues);
}

$Object* AnnotationInvocationHandler::invoke(Object$* proxy, $Method* method, $ObjectArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($String, member, $nc(method)->getName());
	int32_t parameterCount = method->getParameterCount();
	if (parameterCount == 1 && member == "equals"_s && $nc($(method->getParameterTypes()))->get(0) == $Object::class$) {
		return $of(equalsImpl(proxy, $nc(args)->get(0)));
	}
	if (parameterCount != 0) {
		$throwNew($AssertionError, $of("Too many parameters for an annotation method"_s));
	}
	if (member == "toString"_s) {
		return $of(toStringImpl());
	} else if (member == "hashCode"_s) {
		return $of($Integer::valueOf(hashCodeImpl()));
	} else if (member == "annotationType"_s) {
		return $of(this->type);
	}
	$var($Object, result, $nc(this->memberValues)->get(member));
	if (result == nullptr) {
		$throwNew($IncompleteAnnotationException, this->type, member);
	}
	if ($instanceOf($ExceptionProxy, result)) {
		$throw($($nc(($cast($ExceptionProxy, result)))->generateException()));
	}
	bool var$0 = $nc($of(result))->getClass()->isArray();
	if (var$0 && $1Array::getLength(result) != 0) {
		$assign(result, cloneArray(result));
	}
	return $of(result);
}

$Object* AnnotationInvocationHandler::cloneArray(Object$* array) {
	$useLocalCurrentObjectStackCache();
	$Class* type = $nc($of(array))->getClass();
	$load($bytes);
	if (type == $getClass($bytes)) {
		$var($bytes, byteArray, $cast($bytes, array));
		return $of(byteArray->clone());
	}
	$load($chars);
	if (type == $getClass($chars)) {
		$var($chars, charArray, $cast($chars, array));
		return $of(charArray->clone());
	}
	$load($doubles);
	if (type == $getClass($doubles)) {
		$var($doubles, doubleArray, $cast($doubles, array));
		return $of(doubleArray->clone());
	}
	$load($floats);
	if (type == $getClass($floats)) {
		$var($floats, floatArray, $cast($floats, array));
		return $of(floatArray->clone());
	}
	$load($ints);
	if (type == $getClass($ints)) {
		$var($ints, intArray, $cast($ints, array));
		return $of(intArray->clone());
	}
	$load($longs);
	if (type == $getClass($longs)) {
		$var($longs, longArray, $cast($longs, array));
		return $of(longArray->clone());
	}
	$load($shorts);
	if (type == $getClass($shorts)) {
		$var($shorts, shortArray, $cast($shorts, array));
		return $of(shortArray->clone());
	}
	$load($booleans);
	if (type == $getClass($booleans)) {
		$var($booleans, booleanArray, $cast($booleans, array));
		return $of(booleanArray->clone());
	}
	$var($ObjectArray, objectArray, $cast($ObjectArray, array));
	return $of(objectArray->clone());
}

$String* AnnotationInvocationHandler::toStringImpl() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, result, $new($StringBuilder, 128));
	result->append(u'@');
	result->append($($nc(this->type)->getName()));
	result->append(u'(');
	bool firstMember = true;
	$var($Set, entries, $nc(this->memberValues)->entrySet());
	bool loneValue = $nc(entries)->size() == 1;
	{
		$var($Iterator, i$, entries->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				if (firstMember) {
					firstMember = false;
				} else {
					result->append(", "_s);
				}
				$var($String, key, $cast($String, $nc(e)->getKey()));
				if (!loneValue || !"value"_s->equals(key)) {
					result->append(key);
					result->append(u'=');
				}
				loneValue = false;
				result->append($(memberValueToString($(e->getValue()))));
			}
		}
	}
	result->append(u')');
	return result->toString();
}

$String* AnnotationInvocationHandler::memberValueToString(Object$* value) {
	$init(AnnotationInvocationHandler);
	$useLocalCurrentObjectStackCache();
	$Class* type = $nc($of(value))->getClass();
	if (!$nc(type)->isArray()) {
		if (type == $Class::class$) {
			return toSourceString($cast($Class, value));
		} else if (type == $String::class$) {
			return toSourceString($cast($String, value));
		}
		$load($Character);
		if (type == $Character::class$) {
			return toSourceString($nc(($cast($Character, value)))->charValue());
		} else {
			$load($Double);
			if (type == $Double::class$) {
				return toSourceString($nc(($cast($Double, value)))->doubleValue());
			} else {
				$load($Float);
				if (type == $Float::class$) {
					return toSourceString($nc(($cast($Float, value)))->floatValue());
				} else {
					$load($Long);
					if (type == $Long::class$) {
						return toSourceString($nc(($cast($Long, value)))->longValue());
					} else {
						$load($Byte);
						if (type == $Byte::class$) {
							return toSourceString($nc(($cast($Byte, value)))->byteValue());
						} else {
							return $of(value)->toString();
						}
					}
				}
			}
		}
	} else {
		$var($Stream, stringStream, nullptr);
		$load($bytes);
		if (type == $getClass($bytes)) {
			$assign(stringStream, convert($cast($bytes, value)));
		} else {
			$load($chars);
			if (type == $getClass($chars)) {
				$assign(stringStream, convert($cast($chars, value)));
			} else {
				$load($doubles);
				if (type == $getClass($doubles)) {
					$assign(stringStream, $nc($($DoubleStream::of($cast($doubles, value))))->mapToObj(static_cast<$DoubleFunction*>($$new(AnnotationInvocationHandler$$Lambda$toSourceString))));
				} else {
					$load($floats);
					if (type == $getClass($floats)) {
						$assign(stringStream, convert($cast($floats, value)));
					} else {
						$load($ints);
						if (type == $getClass($ints)) {
							$assign(stringStream, $nc($($IntStream::of($cast($ints, value))))->mapToObj(static_cast<$IntFunction*>($$new(AnnotationInvocationHandler$$Lambda$valueOf$1))));
						} else {
							$load($longs);
							if (type == $getClass($longs)) {
								$assign(stringStream, $nc($($LongStream::of($cast($longs, value))))->mapToObj(static_cast<$LongFunction*>($$new(AnnotationInvocationHandler$$Lambda$toSourceString$2))));
							} else {
								$load($shorts);
								if (type == $getClass($shorts)) {
									$assign(stringStream, convert($cast($shorts, value)));
								} else {
									$load($booleans);
									if (type == $getClass($booleans)) {
										$assign(stringStream, convert($cast($booleans, value)));
									} else {
										$load($ClassArray);
										if (type == $getClass($ClassArray)) {
											$assign(stringStream, $nc($($Arrays::stream($cast($ClassArray, value))))->map(static_cast<$Function*>($$new(AnnotationInvocationHandler$$Lambda$toSourceString$3))));
										} else {
											$load($StringArray);
											if (type == $getClass($StringArray)) {
												$assign(stringStream, $nc($($Arrays::stream($cast($StringArray, value))))->map(static_cast<$Function*>($$new(AnnotationInvocationHandler$$Lambda$toSourceString$4))));
											} else {
												$assign(stringStream, $nc($($Arrays::stream($cast($ObjectArray, value))))->map(static_cast<$Function*>($$new(AnnotationInvocationHandler$$Lambda$toString$5))));
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return stringStreamToString(stringStream);
	}
}

$String* AnnotationInvocationHandler::toSourceString($Class* clazz) {
	$init(AnnotationInvocationHandler);
	$useLocalCurrentObjectStackCache();
	$Class* finalComponent = clazz;
	$var($StringBuilder, arrayBrackets, $new($StringBuilder));
	while ($nc(finalComponent)->isArray()) {
		finalComponent = finalComponent->getComponentType();
		arrayBrackets->append("[]"_s);
	}
	$var($String, var$1, $($nc(finalComponent)->getName()));
	$var($String, var$0, $$concat(var$1, $(arrayBrackets->toString())));
	return $concat(var$0, ".class"_s);
}

$String* AnnotationInvocationHandler::toSourceString(float f) {
	$init(AnnotationInvocationHandler);
	if ($Float::isFinite(f)) {
		return $str({$($Float::toString(f)), "f"_s});
	} else if ($Float::isInfinite(f)) {
		return (f < 0.0f) ? "-1.0f/0.0f"_s : "1.0f/0.0f"_s;
	} else {
		return "0.0f/0.0f"_s;
	}
}

$String* AnnotationInvocationHandler::toSourceString(double d) {
	$init(AnnotationInvocationHandler);
	if ($Double::isFinite(d)) {
		return $Double::toString(d);
	} else if ($Double::isInfinite(d)) {
		return (d < 0.0f) ? "-1.0/0.0"_s : "1.0/0.0"_s;
	} else {
		return "0.0/0.0"_s;
	}
}

$String* AnnotationInvocationHandler::toSourceString(char16_t c) {
	$init(AnnotationInvocationHandler);
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder, 4));
	sb->append(u'\'');
	sb->append($(quote(c)));
	return sb->append(u'\'')->toString();
}

$String* AnnotationInvocationHandler::quote(char16_t ch) {
	$init(AnnotationInvocationHandler);
	$useLocalCurrentObjectStackCache();
	switch (ch) {
	case u'\b':
		{
			return "\\b"_s;
		}
	case u'\f':
		{
			return "\\f"_s;
		}
	case u'\n':
		{
			return "\\n"_s;
		}
	case u'\r':
		{
			return "\\r"_s;
		}
	case u'\t':
		{
			return "\\t"_s;
		}
	case u'\'':
		{
			return "\\\'"_s;
		}
	case u'\"':
		{
			return "\\\""_s;
		}
	case u'\\':
		{
			return "\\\\"_s;
		}
	default:
		{
			return (isPrintableAscii(ch)) ? $String::valueOf(ch) : $String::format("\\u%04x"_s, $$new($ObjectArray, {$($of($Integer::valueOf((int32_t)ch)))}));
		}
	}
}

bool AnnotationInvocationHandler::isPrintableAscii(char16_t ch) {
	$init(AnnotationInvocationHandler);
	return ch >= u' ' && ch <= u'~';
}

$String* AnnotationInvocationHandler::toSourceString(int8_t b) {
	$init(AnnotationInvocationHandler);
	$useLocalCurrentObjectStackCache();
	return $String::format("(byte)0x%02x"_s, $$new($ObjectArray, {$($of($Byte::valueOf(b)))}));
}

$String* AnnotationInvocationHandler::toSourceString(int64_t ell) {
	$init(AnnotationInvocationHandler);
	return $str({$($String::valueOf(ell)), "L"_s});
}

$String* AnnotationInvocationHandler::toSourceString($String* s) {
	$init(AnnotationInvocationHandler);
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append(u'\"');
	for (int32_t i = 0; i < $nc(s)->length(); ++i) {
		sb->append($(quote(s->charAt(i))));
	}
	sb->append(u'\"');
	return sb->toString();
}

$Stream* AnnotationInvocationHandler::convert($bytes* values) {
	$init(AnnotationInvocationHandler);
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList, $nc(values)->length));
	{
		$var($bytes, arr$, values);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int8_t b = arr$->get(i$);
			list->add($(toSourceString(b)));
		}
	}
	return list->stream();
}

$Stream* AnnotationInvocationHandler::convert($chars* values) {
	$init(AnnotationInvocationHandler);
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList, $nc(values)->length));
	{
		$var($chars, arr$, values);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			char16_t c = arr$->get(i$);
			list->add($(toSourceString(c)));
		}
	}
	return list->stream();
}

$Stream* AnnotationInvocationHandler::convert($floats* values) {
	$init(AnnotationInvocationHandler);
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList, $nc(values)->length));
	{
		$var($floats, arr$, values);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			float f = arr$->get(i$);
			{
				list->add($(toSourceString(f)));
			}
		}
	}
	return list->stream();
}

$Stream* AnnotationInvocationHandler::convert($shorts* values) {
	$init(AnnotationInvocationHandler);
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList, $nc(values)->length));
	{
		$var($shorts, arr$, values);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int16_t s = arr$->get(i$);
			list->add($($Short::toString(s)));
		}
	}
	return list->stream();
}

$Stream* AnnotationInvocationHandler::convert($booleans* values) {
	$init(AnnotationInvocationHandler);
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList, $nc(values)->length));
	{
		$var($booleans, arr$, values);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			bool b = arr$->get(i$);
			list->add($($Boolean::toString(b)));
		}
	}
	return list->stream();
}

$String* AnnotationInvocationHandler::stringStreamToString($Stream* stream) {
	$init(AnnotationInvocationHandler);
	return $cast($String, $nc(stream)->collect($($Collectors::joining(", "_s, "{"_s, "}"_s))));
}

$Boolean* AnnotationInvocationHandler::equalsImpl(Object$* proxy, Object$* o) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($equals(o, proxy)) {
		return $Boolean::valueOf(true);
	}
	if (!$nc(this->type)->isInstance(o)) {
		return $Boolean::valueOf(false);
	}
	{
		$var($MethodArray, arr$, getMemberMethods());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Method, memberMethod, arr$->get(i$));
			{
				if ($nc(memberMethod)->isSynthetic()) {
					continue;
				}
				$var($String, member, $nc(memberMethod)->getName());
				$var($Object, ourValue, $nc(this->memberValues)->get(member));
				$var($Object, hisValue, nullptr);
				$var(AnnotationInvocationHandler, hisHandler, asOneOfUs(o));
				if (hisHandler != nullptr) {
					$assign(hisValue, $nc(hisHandler->memberValues)->get(member));
				} else {
					try {
						$assign(hisValue, memberMethod->invoke(o, $$new($ObjectArray, 0)));
					} catch ($InvocationTargetException& e) {
						return $Boolean::valueOf(false);
					} catch ($IllegalAccessException& e) {
						$throwNew($AssertionError, $of(e));
					}
				}
				if (!memberValueEquals(ourValue, hisValue)) {
					return $Boolean::valueOf(false);
				}
			}
		}
	}
	return $Boolean::valueOf(true);
}

AnnotationInvocationHandler* AnnotationInvocationHandler::asOneOfUs(Object$* o) {
	$beforeCallerSensitive();
	if ($Proxy::isProxyClass($nc($of(o))->getClass())) {
		$var($InvocationHandler, handler, $Proxy::getInvocationHandler(o));
		if ($instanceOf(AnnotationInvocationHandler, handler)) {
			return $cast(AnnotationInvocationHandler, handler);
		}
	}
	return nullptr;
}

bool AnnotationInvocationHandler::memberValueEquals(Object$* v1, Object$* v2) {
	$init(AnnotationInvocationHandler);
	$Class* type = $nc($of(v1))->getClass();
	if (!$nc(type)->isArray()) {
		return $of(v1)->equals(v2);
	}
	if ($instanceOf($ObjectArray, v1) && $instanceOf($ObjectArray, v2)) {
		return $Arrays::equals($cast($ObjectArray, v1), $cast($ObjectArray, v2));
	}
	if ($nc($of(v2))->getClass() != type) {
		return false;
	}
	$load($bytes);
	if (type == $getClass($bytes)) {
		return $Arrays::equals($cast($bytes, v1), $cast($bytes, v2));
	}
	$load($chars);
	if (type == $getClass($chars)) {
		return $Arrays::equals($cast($chars, v1), $cast($chars, v2));
	}
	$load($doubles);
	if (type == $getClass($doubles)) {
		return $Arrays::equals($cast($doubles, v1), $cast($doubles, v2));
	}
	$load($floats);
	if (type == $getClass($floats)) {
		return $Arrays::equals($cast($floats, v1), $cast($floats, v2));
	}
	$load($ints);
	if (type == $getClass($ints)) {
		return $Arrays::equals($cast($ints, v1), $cast($ints, v2));
	}
	$load($longs);
	if (type == $getClass($longs)) {
		return $Arrays::equals($cast($longs, v1), $cast($longs, v2));
	}
	$load($shorts);
	if (type == $getClass($shorts)) {
		return $Arrays::equals($cast($shorts, v1), $cast($shorts, v2));
	}
	$load($booleans);
	if (!AnnotationInvocationHandler::$assertionsDisabled && !(type == $getClass($booleans))) {
		$throwNew($AssertionError);
	}
	return $Arrays::equals($cast($booleans, v1), $cast($booleans, v2));
}

$MethodArray* AnnotationInvocationHandler::getMemberMethods() {
	$var($MethodArray, value, this->memberMethods);
	if (value == nullptr) {
		$assign(value, computeMemberMethods());
		$set(this, memberMethods, value);
	}
	return value;
}

$MethodArray* AnnotationInvocationHandler::computeMemberMethods() {
	$beforeCallerSensitive();
	return $cast($MethodArray, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($AnnotationInvocationHandler$1, this))));
}

void AnnotationInvocationHandler::validateAnnotationMethods($MethodArray* memberMethods) {
	$useLocalCurrentObjectStackCache();
	bool valid = true;
	$var($Method, currentMethod, nullptr);
	{
		$var($MethodArray, arr$, memberMethods);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Method, method, arr$->get(i$));
			{
				$assign(currentMethod, method);
				int32_t modifiers = $nc(method)->getModifiers();
				bool var$0 = method->isSynthetic() && ((int32_t)(modifiers & (uint32_t)($Modifier::STATIC | $Modifier::PRIVATE))) != 0;
				if (var$0 && method->getParameterCount() == 0) {
					continue;
				}
				bool var$2 = modifiers != ($Modifier::PUBLIC | $Modifier::ABSTRACT) || method->isDefault();
				bool var$1 = var$2 || method->getParameterCount() != 0;
				if (var$1 || $nc($(method->getExceptionTypes()))->length != 0) {
					valid = false;
					break;
				}
				$Class* returnType = method->getReturnType();
				if ($nc(returnType)->isArray()) {
					returnType = returnType->getComponentType();
					if (returnType->isArray()) {
						valid = false;
						break;
					}
				}
				$init($Void);
				bool var$4 = ($nc(returnType)->isPrimitive() && returnType != $Void::TYPE) || returnType == $String::class$ || returnType == $Class::class$;
				bool var$3 = var$4 || $nc(returnType)->isEnum();
				if (!(var$3 || $nc(returnType)->isAnnotation())) {
					valid = false;
					break;
				}
				$var($String, methodName, method->getName());
				bool var$6 = ($nc(methodName)->equals("toString"_s) && returnType == $String::class$);
				$init($Integer);
				bool var$5 = var$6 || ($nc(methodName)->equals("hashCode"_s) && returnType == $Integer::TYPE);
				if (var$5 || ($nc(methodName)->equals("annotationType"_s) && returnType == $Class::class$)) {
					valid = false;
					break;
				}
			}
		}
	}
	if (valid) {
		return;
	} else {
		$throwNew($AnnotationFormatError, $$str({"Malformed method on an annotation type: "_s, $($nc(currentMethod)->toString())}));
	}
}

int32_t AnnotationInvocationHandler::hashCodeImpl() {
	$useLocalCurrentObjectStackCache();
	int32_t result = 0;
	{
		$var($Iterator, i$, $nc($($nc(this->memberValues)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				int32_t var$0 = (127 * $nc(($cast($String, $($nc(e)->getKey()))))->hashCode());
				result += var$0 ^ memberValueHashCode($(e->getValue()));
			}
		}
	}
	return result;
}

int32_t AnnotationInvocationHandler::memberValueHashCode(Object$* value) {
	$init(AnnotationInvocationHandler);
	$Class* type = $nc($of(value))->getClass();
	if (!$nc(type)->isArray()) {
		return $of(value)->hashCode();
	}
	$load($bytes);
	if (type == $getClass($bytes)) {
		return $Arrays::hashCode($cast($bytes, value));
	}
	$load($chars);
	if (type == $getClass($chars)) {
		return $Arrays::hashCode($cast($chars, value));
	}
	$load($doubles);
	if (type == $getClass($doubles)) {
		return $Arrays::hashCode($cast($doubles, value));
	}
	$load($floats);
	if (type == $getClass($floats)) {
		return $Arrays::hashCode($cast($floats, value));
	}
	$load($ints);
	if (type == $getClass($ints)) {
		return $Arrays::hashCode($cast($ints, value));
	}
	$load($longs);
	if (type == $getClass($longs)) {
		return $Arrays::hashCode($cast($longs, value));
	}
	$load($shorts);
	if (type == $getClass($shorts)) {
		return $Arrays::hashCode($cast($shorts, value));
	}
	$load($booleans);
	if (type == $getClass($booleans)) {
		return $Arrays::hashCode($cast($booleans, value));
	}
	return $Arrays::hashCode($cast($ObjectArray, value));
}

void AnnotationInvocationHandler::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectInputStream$GetField, fields, $nc(s)->readFields());
	$Class* t = $cast($Class, $nc(fields)->get("type"_s, ($Object*)nullptr));
	$var($Map, streamVals, $cast($Map, fields->get("memberValues"_s, ($Object*)nullptr)));
	$var($AnnotationType, annotationType, nullptr);
	try {
		$assign(annotationType, $AnnotationType::getInstance(t));
	} catch ($IllegalArgumentException& e) {
		$throwNew($InvalidObjectException, "Non-annotation type in annotation serial stream"_s);
	}
	$var($Map, memberTypes, $nc(annotationType)->memberTypes());
	$var($Map, mv, $new($LinkedHashMap));
	{
		$var($Iterator, i$, $nc($($nc(streamVals)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, memberValue, $cast($Map$Entry, i$->next()));
			{
				$var($String, name, $cast($String, $nc(memberValue)->getKey()));
				$var($Object, value, nullptr);
				$Class* memberType = $cast($Class, $nc(memberTypes)->get(name));
				if (memberType != nullptr) {
					$assign(value, memberValue->getValue());
					if (!(memberType->isInstance(value) || $instanceOf($ExceptionProxy, value))) {
						$assign(value, $$new($AnnotationTypeMismatchExceptionProxy, $$str({$nc($of(value))->getClass(), "["_s, value, "]"_s}))->setMember($cast($Method, $($nc($(annotationType->members()))->get(name)))));
					}
				}
				mv->put(name, value);
			}
		}
	}
	$AnnotationInvocationHandler$UnsafeAccessor::setType(this, t);
	$AnnotationInvocationHandler$UnsafeAccessor::setMemberValues(this, mv);
}

void clinit$AnnotationInvocationHandler($Class* class$) {
	AnnotationInvocationHandler::$assertionsDisabled = !AnnotationInvocationHandler::class$->desiredAssertionStatus();
}

AnnotationInvocationHandler::AnnotationInvocationHandler() {
}

$Class* AnnotationInvocationHandler::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(AnnotationInvocationHandler$$Lambda$toSourceString::classInfo$.name)) {
			return AnnotationInvocationHandler$$Lambda$toSourceString::load$(name, initialize);
		}
		if (name->equals(AnnotationInvocationHandler$$Lambda$valueOf$1::classInfo$.name)) {
			return AnnotationInvocationHandler$$Lambda$valueOf$1::load$(name, initialize);
		}
		if (name->equals(AnnotationInvocationHandler$$Lambda$toSourceString$2::classInfo$.name)) {
			return AnnotationInvocationHandler$$Lambda$toSourceString$2::load$(name, initialize);
		}
		if (name->equals(AnnotationInvocationHandler$$Lambda$toSourceString$3::classInfo$.name)) {
			return AnnotationInvocationHandler$$Lambda$toSourceString$3::load$(name, initialize);
		}
		if (name->equals(AnnotationInvocationHandler$$Lambda$toSourceString$4::classInfo$.name)) {
			return AnnotationInvocationHandler$$Lambda$toSourceString$4::load$(name, initialize);
		}
		if (name->equals(AnnotationInvocationHandler$$Lambda$toString$5::classInfo$.name)) {
			return AnnotationInvocationHandler$$Lambda$toString$5::load$(name, initialize);
		}
	}
	$loadClass(AnnotationInvocationHandler, name, initialize, &_AnnotationInvocationHandler_ClassInfo_, clinit$AnnotationInvocationHandler, allocate$AnnotationInvocationHandler);
	return class$;
}

$Class* AnnotationInvocationHandler::class$ = nullptr;

		} // annotation
	} // reflect
} // sun