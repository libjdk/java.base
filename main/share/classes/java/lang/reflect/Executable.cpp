#include <java/lang/reflect/Executable.h>

#include <java/io/Serializable.h>
#include <java/lang/AbstractMethodError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/AccessibleObject.h>
#include <java/lang/reflect/AnnotatedElement.h>
#include <java/lang/reflect/AnnotatedType.h>
#include <java/lang/reflect/MalformedParametersException.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Parameter.h>
#include <java/lang/reflect/Type.h>
#include <java/lang/reflect/TypeVariable.h>
#include <java/util/Arrays.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/StringJoiner.h>
#include <java/util/function/Function.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/reflect/ConstantPool.h>
#include <sun/reflect/annotation/AnnotationParser.h>
#include <sun/reflect/annotation/AnnotationSupport.h>
#include <sun/reflect/annotation/TypeAnnotation$TypeAnnotationTarget.h>
#include <sun/reflect/annotation/TypeAnnotationParser.h>
#include <sun/reflect/generics/reflectiveObjects/ParameterizedTypeImpl.h>
#include <sun/reflect/generics/repository/ConstructorRepository.h>
#include <jcpp.h>

#undef ACCESS_MODIFIERS
#undef FINAL
#undef MANDATED
#undef METHOD_FORMAL_PARAMETER
#undef METHOD_RECEIVER
#undef METHOD_RETURN
#undef SYNTHETIC
#undef THROWS
#undef VARARGS

using $AnnotationArray = $Array<::java::lang::annotation::Annotation>;
using $AnnotatedTypeArray = $Array<::java::lang::reflect::AnnotatedType>;
using $ParameterArray = $Array<::java::lang::reflect::Parameter>;
using $TypeArray = $Array<::java::lang::reflect::Type>;
using $TypeVariableArray = $Array<::java::lang::reflect::TypeVariable>;
using $AnnotationArray2 = $Array<::java::lang::annotation::Annotation, 2>;
using $Serializable = ::java::io::Serializable;
using $AbstractMethodError = ::java::lang::AbstractMethodError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Annotation = ::java::lang::annotation::Annotation;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessibleObject = ::java::lang::reflect::AccessibleObject;
using $AnnotatedElement = ::java::lang::reflect::AnnotatedElement;
using $AnnotatedType = ::java::lang::reflect::AnnotatedType;
using $MalformedParametersException = ::java::lang::reflect::MalformedParametersException;
using $Modifier = ::java::lang::reflect::Modifier;
using $Parameter = ::java::lang::reflect::Parameter;
using $Type = ::java::lang::reflect::Type;
using $TypeVariable = ::java::lang::reflect::TypeVariable;
using $Arrays = ::java::util::Arrays;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $StringJoiner = ::java::util::StringJoiner;
using $Function = ::java::util::function::Function;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ConstantPool = ::jdk::internal::reflect::ConstantPool;
using $AnnotationParser = ::sun::reflect::annotation::AnnotationParser;
using $AnnotationSupport = ::sun::reflect::annotation::AnnotationSupport;
using $TypeAnnotation$TypeAnnotationTarget = ::sun::reflect::annotation::TypeAnnotation$TypeAnnotationTarget;
using $TypeAnnotationParser = ::sun::reflect::annotation::TypeAnnotationParser;
using $ParameterizedTypeImpl = ::sun::reflect::generics::reflectiveObjects::ParameterizedTypeImpl;
using $ConstructorRepository = ::sun::reflect::generics::repository::ConstructorRepository;

namespace java {
	namespace lang {
		namespace reflect {

class Executable$$Lambda$getTypeName : public $Function {
	$class(Executable$$Lambda$getTypeName, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Type, inst$)->getTypeName());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Executable$$Lambda$getTypeName>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Executable$$Lambda$getTypeName::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Executable$$Lambda$getTypeName, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Executable$$Lambda$getTypeName, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Executable$$Lambda$getTypeName::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.reflect.Executable$$Lambda$getTypeName",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Executable$$Lambda$getTypeName::load$($String* name, bool initialize) {
	$loadClass(Executable$$Lambda$getTypeName, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Executable$$Lambda$getTypeName::class$ = nullptr;

class Executable$$Lambda$typeVarBounds$1 : public $Function {
	$class(Executable$$Lambda$typeVarBounds$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* typeVar) override {
		 return $of(Executable::typeVarBounds($cast($TypeVariable, typeVar)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Executable$$Lambda$typeVarBounds$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Executable$$Lambda$typeVarBounds$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Executable$$Lambda$typeVarBounds$1, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Executable$$Lambda$typeVarBounds$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Executable$$Lambda$typeVarBounds$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.reflect.Executable$$Lambda$typeVarBounds$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Executable$$Lambda$typeVarBounds$1::load$($String* name, bool initialize) {
	$loadClass(Executable$$Lambda$typeVarBounds$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Executable$$Lambda$typeVarBounds$1::class$ = nullptr;

$FieldInfo _Executable_FieldInfo_[] = {
	{"hasRealParameterData", "Z", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(Executable, hasRealParameterData$)},
	{"parameters", "[Ljava/lang/reflect/Parameter;", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(Executable, parameters)},
	{"declaredAnnotations", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;Ljava/lang/annotation/Annotation;>;", $PRIVATE | $VOLATILE | $TRANSIENT, $field(Executable, declaredAnnotations$)},
	{"typeAnnotation", "[B", nullptr, 2, $field(Executable, typeAnnotation)},
	{}
};

$MethodInfo _Executable_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*getAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC},
	{"*getDeclaredAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC},
	{"*getDeclaredAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC},
	{"getDeclaringClass", "()Ljava/lang/Class;", nullptr, $PUBLIC | $ABSTRACT},
	{"getModifiers", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{"getTypeParameters", "()[Ljava/lang/reflect/TypeVariable;", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(Executable, init$, void)},
	{"declaredAnnotations", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;Ljava/lang/annotation/Annotation;>;", $PRIVATE, $method(Executable, declaredAnnotations, $Map*)},
	{"equalParamTypes", "([Ljava/lang/Class;[Ljava/lang/Class;)Z", "([Ljava/lang/Class<*>;[Ljava/lang/Class<*>;)Z", 0, $virtualMethod(Executable, equalParamTypes, bool, $ClassArray*, $ClassArray*)},
	{"getAllGenericParameterTypes", "()[Ljava/lang/reflect/Type;", nullptr, 0, $virtualMethod(Executable, getAllGenericParameterTypes, $TypeArray*)},
	{"getAnnotatedExceptionTypes", "()[Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC, $virtualMethod(Executable, getAnnotatedExceptionTypes, $AnnotatedTypeArray*)},
	{"getAnnotatedParameterTypes", "()[Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC, $virtualMethod(Executable, getAnnotatedParameterTypes, $AnnotatedTypeArray*)},
	{"getAnnotatedReceiverType", "()Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC, $virtualMethod(Executable, getAnnotatedReceiverType, $AnnotatedType*)},
	{"getAnnotatedReturnType", "()Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Executable, getAnnotatedReturnType, $AnnotatedType*)},
	{"getAnnotatedReturnType0", "(Ljava/lang/reflect/Type;)Ljava/lang/reflect/AnnotatedType;", nullptr, 0, $virtualMethod(Executable, getAnnotatedReturnType0, $AnnotatedType*, $Type*)},
	{"getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)TT;", $PUBLIC, $virtualMethod(Executable, getAnnotation, $Annotation*, $Class*)},
	{"getAnnotationBytes", "()[B", nullptr, $ABSTRACT, $virtualMethod(Executable, getAnnotationBytes, $bytes*)},
	{"getAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)[TT;", $PUBLIC, $virtualMethod(Executable, getAnnotationsByType, $AnnotationArray*, $Class*)},
	{"getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC, $virtualMethod(Executable, getDeclaredAnnotations, $AnnotationArray*)},
	{"getExceptionTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC | $ABSTRACT, $virtualMethod(Executable, getExceptionTypes, $ClassArray*)},
	{"getGenericExceptionTypes", "()[Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(Executable, getGenericExceptionTypes, $TypeArray*)},
	{"getGenericInfo", "()Lsun/reflect/generics/repository/ConstructorRepository;", nullptr, $ABSTRACT, $virtualMethod(Executable, getGenericInfo, $ConstructorRepository*)},
	{"getGenericParameterTypes", "()[Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(Executable, getGenericParameterTypes, $TypeArray*)},
	{"getParameterAnnotations", "()[[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Executable, getParameterAnnotations, $AnnotationArray2*)},
	{"getParameterCount", "()I", nullptr, $PUBLIC, $virtualMethod(Executable, getParameterCount, int32_t)},
	{"getParameterTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC | $ABSTRACT, $virtualMethod(Executable, getParameterTypes, $ClassArray*)},
	{"getParameters", "()[Ljava/lang/reflect/Parameter;", nullptr, $PUBLIC, $virtualMethod(Executable, getParameters, $ParameterArray*)},
	{"getParameters0", "()[Ljava/lang/reflect/Parameter;", nullptr, $PRIVATE | $NATIVE, $method(Executable, getParameters0, $ParameterArray*)},
	{"getSharedExceptionTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $ABSTRACT, $virtualMethod(Executable, getSharedExceptionTypes, $ClassArray*)},
	{"getSharedParameterTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $ABSTRACT, $virtualMethod(Executable, getSharedParameterTypes, $ClassArray*)},
	{"getTypeAnnotationBytes", "()[B", nullptr, 0, $virtualMethod(Executable, getTypeAnnotationBytes, $bytes*)},
	{"getTypeAnnotationBytes0", "()[B", nullptr, $NATIVE, $virtualMethod(Executable, getTypeAnnotationBytes0, $bytes*)},
	{"handleParameterNumberMismatch", "(I[Ljava/lang/Class;)Z", "(I[Ljava/lang/Class<*>;)Z", $ABSTRACT, $virtualMethod(Executable, handleParameterNumberMismatch, bool, int32_t, $ClassArray*)},
	{"hasGenericInformation", "()Z", nullptr, $ABSTRACT, $virtualMethod(Executable, hasGenericInformation, bool)},
	{"hasRealParameterData", "()Z", nullptr, 0, $virtualMethod(Executable, hasRealParameterData, bool)},
	{"*isAnnotationPresent", "(Ljava/lang/Class;)Z", nullptr, $PUBLIC},
	{"isSynthetic", "()Z", nullptr, $PUBLIC, $virtualMethod(Executable, isSynthetic, bool)},
	{"isVarArgs", "()Z", nullptr, $PUBLIC, $virtualMethod(Executable, isVarArgs, bool)},
	{"parameterize", "(Ljava/lang/Class;)Ljava/lang/reflect/Type;", "(Ljava/lang/Class<*>;)Ljava/lang/reflect/Type;", 0, $virtualMethod(Executable, parameterize, $Type*, $Class*)},
	{"parseParameterAnnotations", "([B)[[Ljava/lang/annotation/Annotation;", nullptr, 0, $virtualMethod(Executable, parseParameterAnnotations, $AnnotationArray2*, $bytes*)},
	{"printModifiersIfNonzero", "(Ljava/lang/StringBuilder;IZ)V", nullptr, 0, $virtualMethod(Executable, printModifiersIfNonzero, void, $StringBuilder*, int32_t, bool)},
	{"privateGetParameters", "()[Ljava/lang/reflect/Parameter;", nullptr, $PRIVATE, $method(Executable, privateGetParameters, $ParameterArray*)},
	{"sharedGetParameterAnnotations", "([Ljava/lang/Class;[B)[[Ljava/lang/annotation/Annotation;", "([Ljava/lang/Class<*>;[B)[[Ljava/lang/annotation/Annotation;", 0, $virtualMethod(Executable, sharedGetParameterAnnotations, $AnnotationArray2*, $ClassArray*, $bytes*)},
	{"sharedToGenericString", "(IZ)Ljava/lang/String;", nullptr, 0, $virtualMethod(Executable, sharedToGenericString, $String*, int32_t, bool)},
	{"sharedToString", "(IZ[Ljava/lang/Class;[Ljava/lang/Class;)Ljava/lang/String;", "(IZ[Ljava/lang/Class<*>;[Ljava/lang/Class<*>;)Ljava/lang/String;", 0, $virtualMethod(Executable, sharedToString, $String*, int32_t, bool, $ClassArray*, $ClassArray*)},
	{"specificToGenericStringHeader", "(Ljava/lang/StringBuilder;)V", nullptr, $ABSTRACT, $virtualMethod(Executable, specificToGenericStringHeader, void, $StringBuilder*)},
	{"specificToStringHeader", "(Ljava/lang/StringBuilder;)V", nullptr, $ABSTRACT, $virtualMethod(Executable, specificToStringHeader, void, $StringBuilder*)},
	{"synthesizeAllParams", "()[Ljava/lang/reflect/Parameter;", nullptr, $PRIVATE, $method(Executable, synthesizeAllParams, $ParameterArray*)},
	{"toGenericString", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Executable, toGenericString, $String*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"typeVarBounds", "(Ljava/lang/reflect/TypeVariable;)Ljava/lang/String;", "(Ljava/lang/reflect/TypeVariable<*>;)Ljava/lang/String;", $STATIC, $staticMethod(Executable, typeVarBounds, $String*, $TypeVariable*)},
	{"verifyParameters", "([Ljava/lang/reflect/Parameter;)V", nullptr, $PRIVATE, $method(Executable, verifyParameters, void, $ParameterArray*)},
	{}
};

#define _METHOD_INDEX_getParameters0 32
#define _METHOD_INDEX_getTypeAnnotationBytes0 36

$ClassInfo _Executable_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.lang.reflect.Executable",
	"java.lang.reflect.AccessibleObject",
	"java.lang.reflect.Member,java.lang.reflect.GenericDeclaration",
	_Executable_FieldInfo_,
	_Executable_MethodInfo_
};

$Object* allocate$Executable($Class* clazz) {
	return $of($alloc(Executable));
}

bool Executable::isAnnotationPresent($Class* annotationClass) {
	 return this->$AccessibleObject::isAnnotationPresent(annotationClass);
}

$AnnotationArray* Executable::getAnnotations() {
	 return this->$AccessibleObject::getAnnotations();
}

$Annotation* Executable::getDeclaredAnnotation($Class* annotationClass) {
	 return this->$AccessibleObject::getDeclaredAnnotation(annotationClass);
}

$AnnotationArray* Executable::getDeclaredAnnotationsByType($Class* annotationClass) {
	 return this->$AccessibleObject::getDeclaredAnnotationsByType(annotationClass);
}

int32_t Executable::hashCode() {
	 return this->$AccessibleObject::hashCode();
}

bool Executable::equals(Object$* obj) {
	 return this->$AccessibleObject::equals(obj);
}

$Object* Executable::clone() {
	 return this->$AccessibleObject::clone();
}

$String* Executable::toString() {
	 return this->$AccessibleObject::toString();
}

void Executable::finalize() {
	this->$AccessibleObject::finalize();
}

void Executable::init$() {
	$AccessibleObject::init$();
}

bool Executable::equalParamTypes($ClassArray* params1, $ClassArray* params2) {
	if ($nc(params1)->length == $nc(params2)->length) {
		for (int32_t i = 0; i < params1->length; ++i) {
			if (params1->get(i) != params2->get(i)) {
				return false;
			}
		}
		return true;
	}
	return false;
}

$AnnotationArray2* Executable::parseParameterAnnotations($bytes* parameterAnnotations) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, var$0, parameterAnnotations);
	$var($ConstantPool, var$1, $nc($($SharedSecrets::getJavaLangAccess()))->getConstantPool(getDeclaringClass()));
	return $AnnotationParser::parseParameterAnnotations(var$0, var$1, getDeclaringClass());
}

void Executable::printModifiersIfNonzero($StringBuilder* sb, int32_t mask, bool isDefault) {
	$useLocalCurrentObjectStackCache();
	int32_t mod = (int32_t)(getModifiers() & (uint32_t)mask);
	if (mod != 0 && !isDefault) {
		$nc(sb)->append($($Modifier::toString(mod)))->append(u' ');
	} else {
		int32_t access_mod = (int32_t)(mod & (uint32_t)$Modifier::ACCESS_MODIFIERS);
		if (access_mod != 0) {
			$nc(sb)->append($($Modifier::toString(access_mod)))->append(u' ');
		}
		if (isDefault) {
			$nc(sb)->append("default "_s);
		}
		mod = ((int32_t)(mod & (uint32_t)~$Modifier::ACCESS_MODIFIERS));
		if (mod != 0) {
			$nc(sb)->append($($Modifier::toString(mod)))->append(u' ');
		}
	}
}

$String* Executable::sharedToString(int32_t modifierMask, bool isDefault, $ClassArray* parameterTypes, $ClassArray* exceptionTypes) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($StringBuilder, sb, $new($StringBuilder));
		printModifiersIfNonzero(sb, modifierMask, isDefault);
		specificToStringHeader(sb);
		sb->append($cast($String, $($nc($($nc($($Arrays::stream(parameterTypes)))->map(static_cast<$Function*>($$new(Executable$$Lambda$getTypeName)))))->collect($($Collectors::joining(","_s, "("_s, ")"_s))))));
		if ($nc(exceptionTypes)->length > 0) {
			sb->append($cast($String, $($nc($($nc($($Arrays::stream(exceptionTypes)))->map(static_cast<$Function*>($$new(Executable$$Lambda$getTypeName)))))->collect($($Collectors::joining(","_s, " throws "_s, ""_s))))));
		}
		return sb->toString();
	} catch ($Exception& e) {
		return $str({"<"_s, e, ">"_s});
	}
	$shouldNotReachHere();
}

$String* Executable::typeVarBounds($TypeVariable* typeVar) {
	$init(Executable);
	$useLocalCurrentObjectStackCache();
	$var($TypeArray, bounds, $nc(typeVar)->getBounds());
	if ($nc(bounds)->length == 1 && $nc($of(bounds->get(0)))->equals($Object::class$)) {
		return typeVar->getName();
	} else {
		$var($String, var$0, $$str({$(typeVar->getName()), " extends "_s}));
		return $concat(var$0, $cast($String, $($nc($($nc($($Arrays::stream(bounds)))->map(static_cast<$Function*>($$new(Executable$$Lambda$getTypeName)))))->collect($($Collectors::joining(" & "_s))))));
	}
}

$String* Executable::sharedToGenericString(int32_t modifierMask, bool isDefault) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($StringBuilder, sb, $new($StringBuilder));
		printModifiersIfNonzero(sb, modifierMask, isDefault);
		$var($TypeVariableArray, typeparms, getTypeParameters());
		if ($nc(typeparms)->length > 0) {
			sb->append($cast($String, $($nc($($nc($($Arrays::stream(typeparms)))->map(static_cast<$Function*>($$new(Executable$$Lambda$typeVarBounds$1)))))->collect($($Collectors::joining(","_s, "<"_s, "> "_s))))));
		}
		specificToGenericStringHeader(sb);
		sb->append(u'(');
		$var($StringJoiner, sj, $new($StringJoiner, ","_s));
		$var($TypeArray, params, getGenericParameterTypes());
		for (int32_t j = 0; j < $nc(params)->length; ++j) {
			$var($String, param, $nc(params->get(j))->getTypeName());
			if (isVarArgs() && (j == params->length - 1)) {
				$assign(param, $nc(param)->replaceFirst("\\[\\]$"_s, "..."_s));
			}
			sj->add(param);
		}
		sb->append($(sj->toString()));
		sb->append(u')');
		$var($TypeArray, exceptionTypes, getGenericExceptionTypes());
		if ($nc(exceptionTypes)->length > 0) {
			sb->append($cast($String, $($nc($($nc($($Arrays::stream(exceptionTypes)))->map(static_cast<$Function*>($$new(Executable$$Lambda$getTypeName)))))->collect($($Collectors::joining(","_s, " throws "_s, ""_s))))));
		}
		return sb->toString();
	} catch ($Exception& e) {
		return $str({"<"_s, e, ">"_s});
	}
	$shouldNotReachHere();
}

int32_t Executable::getParameterCount() {
	$throwNew($AbstractMethodError);
	$shouldNotReachHere();
}

$TypeArray* Executable::getGenericParameterTypes() {
	if (hasGenericInformation()) {
		return $nc($(getGenericInfo()))->getParameterTypes();
	} else {
		return $fcast($TypeArray, getParameterTypes());
	}
}

$TypeArray* Executable::getAllGenericParameterTypes() {
	$useLocalCurrentObjectStackCache();
	bool genericInfo = hasGenericInformation();
	if (!genericInfo) {
		return $fcast($TypeArray, getParameterTypes());
	} else {
		bool realParamData = hasRealParameterData();
		$var($TypeArray, genericParamTypes, getGenericParameterTypes());
		$var($TypeArray, nonGenericParamTypes, $fcast($TypeArray, getParameterTypes()));
		if (realParamData) {
			$var($TypeArray, out, $new($TypeArray, $nc(nonGenericParamTypes)->length));
			$var($ParameterArray, params, getParameters());
			int32_t fromidx = 0;
			for (int32_t i = 0; i < out->length; ++i) {
				$var($Parameter, param, $nc(params)->get(i));
				bool var$0 = $nc(param)->isSynthetic();
				if (var$0 || $nc(param)->isImplicit()) {
					out->set(i, nonGenericParamTypes->get(i));
				} else {
					out->set(i, $nc(genericParamTypes)->get(fromidx));
					++fromidx;
				}
			}
			return out;
		} else {
			return $nc(genericParamTypes)->length == $nc(nonGenericParamTypes)->length ? genericParamTypes : nonGenericParamTypes;
		}
	}
}

$ParameterArray* Executable::getParameters() {
	return $cast($ParameterArray, $nc($(privateGetParameters()))->clone());
}

$ParameterArray* Executable::synthesizeAllParams() {
	$useLocalCurrentObjectStackCache();
	int32_t realparams = getParameterCount();
	$var($ParameterArray, out, $new($ParameterArray, realparams));
	for (int32_t i = 0; i < realparams; ++i) {
		out->set(i, $$new($Parameter, $$str({"arg"_s, $$str(i)}), 0, this, i));
	}
	return out;
}

void Executable::verifyParameters($ParameterArray* parameters) {
	$useLocalCurrentObjectStackCache();
	int32_t mask = ($Modifier::FINAL | $Modifier::SYNTHETIC) | $Modifier::MANDATED;
	if (getParameterCount() != $nc(parameters)->length) {
		$throwNew($MalformedParametersException, "Wrong number of parameters in MethodParameters attribute"_s);
	}
	{
		$var($ParameterArray, arr$, parameters);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Parameter, parameter, arr$->get(i$));
			{
				$var($String, name, $nc(parameter)->getRealName());
				int32_t mods = parameter->getModifiers();
				if (name != nullptr) {
					bool var$3 = name->isEmpty();
					bool var$2 = var$3 || name->indexOf((int32_t)u'.') != -1;
					bool var$1 = var$2 || name->indexOf((int32_t)u';') != -1;
					bool var$0 = var$1 || name->indexOf((int32_t)u'[') != -1;
					if (var$0 || name->indexOf((int32_t)u'/') != -1) {
						$throwNew($MalformedParametersException, $$str({"Invalid parameter name \""_s, name, "\""_s}));
					}
				}
				if (mods != ((int32_t)(mods & (uint32_t)mask))) {
					$throwNew($MalformedParametersException, "Invalid parameter modifiers"_s);
				}
			}
		}
	}
}

$ParameterArray* Executable::privateGetParameters() {
	$var($ParameterArray, tmp, this->parameters);
	if (tmp == nullptr) {
		try {
			$assign(tmp, getParameters0());
		} catch ($IllegalArgumentException& e) {
			$throwNew($MalformedParametersException, "Invalid constant pool index"_s);
		}
		if (tmp == nullptr) {
			this->hasRealParameterData$ = false;
			$assign(tmp, synthesizeAllParams());
		} else {
			this->hasRealParameterData$ = true;
			verifyParameters(tmp);
		}
		$set(this, parameters, tmp);
	}
	return tmp;
}

bool Executable::hasRealParameterData() {
	if (this->parameters == nullptr) {
		privateGetParameters();
	}
	return this->hasRealParameterData$;
}

$ParameterArray* Executable::getParameters0() {
	// TODO
	return nullptr;
}

$bytes* Executable::getTypeAnnotationBytes0() {
	return typeAnnotation;
}

$bytes* Executable::getTypeAnnotationBytes() {
	return getTypeAnnotationBytes0();
}

$TypeArray* Executable::getGenericExceptionTypes() {
	$useLocalCurrentObjectStackCache();
	$var($TypeArray, result, nullptr);
	bool var$0 = hasGenericInformation();
	if (var$0 && ($nc(($assign(result, $nc($(getGenericInfo()))->getExceptionTypes())))->length > 0)) {
		return result;
	} else {
		return $fcast($TypeArray, getExceptionTypes());
	}
}

bool Executable::isVarArgs() {
	return ((int32_t)(getModifiers() & (uint32_t)$Modifier::VARARGS)) != 0;
}

bool Executable::isSynthetic() {
	return $Modifier::isSynthetic(getModifiers());
}

$AnnotationArray2* Executable::sharedGetParameterAnnotations($ClassArray* parameterTypes, $bytes* parameterAnnotations) {
	$useLocalCurrentObjectStackCache();
	int32_t numParameters = $nc(parameterTypes)->length;
	if (parameterAnnotations == nullptr) {
		return $new($AnnotationArray2, numParameters, 0);
	}
	$var($AnnotationArray2, result, parseParameterAnnotations(parameterAnnotations));
	if ($nc(result)->length != numParameters && handleParameterNumberMismatch(result->length, parameterTypes)) {
		$var($AnnotationArray2, tmp, $new($AnnotationArray2, numParameters));
		$System::arraycopy(result, 0, tmp, numParameters - result->length, result->length);
		for (int32_t i = 0; i < numParameters - result->length; ++i) {
			tmp->set(i, $$new($AnnotationArray, 0));
		}
		$assign(result, tmp);
	}
	return result;
}

$Annotation* Executable::getAnnotation($Class* annotationClass) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(annotationClass);
	return $cast($Annotation, annotationClass->cast($($nc($(declaredAnnotations()))->get(annotationClass))));
}

$AnnotationArray* Executable::getAnnotationsByType($Class* annotationClass) {
	$Objects::requireNonNull(annotationClass);
	return $AnnotationSupport::getDirectlyAndIndirectlyPresent($(declaredAnnotations()), annotationClass);
}

$AnnotationArray* Executable::getDeclaredAnnotations() {
	return $AnnotationParser::toArray($(declaredAnnotations()));
}

$Map* Executable::declaredAnnotations() {
	$useLocalCurrentObjectStackCache();
	$var($Map, declAnnos, nullptr);
	if (($assign(declAnnos, this->declaredAnnotations$)) == nullptr) {
		$synchronized(this) {
			if (($assign(declAnnos, this->declaredAnnotations$)) == nullptr) {
				$var(Executable, root, $cast(Executable, getRoot()));
				if (root != nullptr) {
					$assign(declAnnos, root->declaredAnnotations());
				} else {
					$var($bytes, var$0, getAnnotationBytes());
					$var($ConstantPool, var$1, $nc($($SharedSecrets::getJavaLangAccess()))->getConstantPool(getDeclaringClass()));
					$assign(declAnnos, $AnnotationParser::parseAnnotations(var$0, var$1, getDeclaringClass()));
				}
				$set(this, declaredAnnotations$, declAnnos);
			}
		}
	}
	return declAnnos;
}

$AnnotatedType* Executable::getAnnotatedReturnType0($Type* returnType) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, var$0, getTypeAnnotationBytes0());
	$var($ConstantPool, var$1, $nc($($SharedSecrets::getJavaLangAccess()))->getConstantPool(getDeclaringClass()));
	$init($TypeAnnotation$TypeAnnotationTarget);
	return $TypeAnnotationParser::buildAnnotatedType(var$0, var$1, static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(this)), getDeclaringClass(), returnType, $TypeAnnotation$TypeAnnotationTarget::METHOD_RETURN);
}

$AnnotatedType* Executable::getAnnotatedReceiverType() {
	$useLocalCurrentObjectStackCache();
	if ($Modifier::isStatic(this->getModifiers())) {
		return nullptr;
	}
	$var($bytes, var$0, getTypeAnnotationBytes0());
	$var($ConstantPool, var$1, $nc($($SharedSecrets::getJavaLangAccess()))->getConstantPool(getDeclaringClass()));
	$Class* var$2 = getDeclaringClass();
	$init($TypeAnnotation$TypeAnnotationTarget);
	return $TypeAnnotationParser::buildAnnotatedType(var$0, var$1, static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(this)), var$2, $(parameterize(getDeclaringClass())), $TypeAnnotation$TypeAnnotationTarget::METHOD_RECEIVER);
}

$Type* Executable::parameterize($Class* c) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* ownerClass = $nc(c)->getDeclaringClass();
	$var($TypeVariableArray, typeVars, c->getTypeParameters());
	if (ownerClass == nullptr || $Modifier::isStatic(c->getModifiers())) {
		if ($nc(typeVars)->length == 0) {
			return c;
		} else {
			return $ParameterizedTypeImpl::make(c, $fcast($TypeArray, typeVars), nullptr);
		}
	}
	$var($Type, ownerType, parameterize(ownerClass));
	if ($instanceOf($Class, ownerType) && $nc(typeVars)->length == 0) {
		return c;
	} else {
		return $ParameterizedTypeImpl::make(c, $fcast($TypeArray, typeVars), ownerType);
	}
}

$AnnotatedTypeArray* Executable::getAnnotatedParameterTypes() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, var$0, getTypeAnnotationBytes0());
	$var($ConstantPool, var$1, $nc($($SharedSecrets::getJavaLangAccess()))->getConstantPool(getDeclaringClass()));
	$Class* var$2 = getDeclaringClass();
	$init($TypeAnnotation$TypeAnnotationTarget);
	return $TypeAnnotationParser::buildAnnotatedTypes(var$0, var$1, static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(this)), var$2, $(getAllGenericParameterTypes()), $TypeAnnotation$TypeAnnotationTarget::METHOD_FORMAL_PARAMETER);
}

$AnnotatedTypeArray* Executable::getAnnotatedExceptionTypes() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, var$0, getTypeAnnotationBytes0());
	$var($ConstantPool, var$1, $nc($($SharedSecrets::getJavaLangAccess()))->getConstantPool(getDeclaringClass()));
	$Class* var$2 = getDeclaringClass();
	$init($TypeAnnotation$TypeAnnotationTarget);
	return $TypeAnnotationParser::buildAnnotatedTypes(var$0, var$1, static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(this)), var$2, $(getGenericExceptionTypes()), $TypeAnnotation$TypeAnnotationTarget::THROWS);
}

Executable::Executable() {
}

$Class* Executable::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Executable$$Lambda$getTypeName::classInfo$.name)) {
			return Executable$$Lambda$getTypeName::load$(name, initialize);
		}
		if (name->equals(Executable$$Lambda$typeVarBounds$1::classInfo$.name)) {
			return Executable$$Lambda$typeVarBounds$1::load$(name, initialize);
		}
	}
	$loadClass(Executable, name, initialize, &_Executable_ClassInfo_, allocate$Executable);
	return class$;
}

$Class* Executable::class$ = nullptr;

		} // reflect
	} // lang
} // java