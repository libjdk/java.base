#include <java/lang/reflect/Method.h>

#include <java/lang/CharSequence.h>
#include <java/lang/TypeNotPresentException.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/annotation/AnnotationFormatError.h>
#include <java/lang/reflect/AccessibleObject.h>
#include <java/lang/reflect/AnnotatedType.h>
#include <java/lang/reflect/Executable.h>
#include <java/lang/reflect/GenericDeclaration.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Type.h>
#include <java/lang/reflect/TypeVariable.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/StringJoiner.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/reflect/ConstantPool.h>
#include <jdk/internal/reflect/MethodAccessor.h>
#include <jdk/internal/reflect/Reflection.h>
#include <jdk/internal/reflect/ReflectionFactory.h>
#include <sun/reflect/annotation/AnnotationParser.h>
#include <sun/reflect/annotation/AnnotationType.h>
#include <sun/reflect/annotation/ExceptionProxy.h>
#include <sun/reflect/annotation/TypeNotPresentExceptionProxy.h>
#include <sun/reflect/generics/factory/CoreReflectionFactory.h>
#include <sun/reflect/generics/factory/GenericsFactory.h>
#include <sun/reflect/generics/repository/ConstructorRepository.h>
#include <sun/reflect/generics/repository/MethodRepository.h>
#include <sun/reflect/generics/scope/MethodScope.h>
#include <sun/reflect/generics/scope/Scope.h>
#include <jcpp.h>

#include <jdk/internal/reflect/CallerSensitive.h>
#include <jdk/internal/vm/annotation/Hidden.h>

#undef ABSTRACT
#undef BRIDGE
#undef PUBLIC
#undef STATIC

using $AnnotationArray = $Array<::java::lang::annotation::Annotation>;
using $TypeArray = $Array<::java::lang::reflect::Type>;
using $TypeVariableArray = $Array<::java::lang::reflect::TypeVariable>;
using $AnnotationArray2 = $Array<::java::lang::annotation::Annotation, 2>;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $TypeNotPresentException = ::java::lang::TypeNotPresentException;
using $Annotation = ::java::lang::annotation::Annotation;
using $AnnotationFormatError = ::java::lang::annotation::AnnotationFormatError;
using $AccessibleObject = ::java::lang::reflect::AccessibleObject;
using $AnnotatedType = ::java::lang::reflect::AnnotatedType;
using $Executable = ::java::lang::reflect::Executable;
using $GenericDeclaration = ::java::lang::reflect::GenericDeclaration;
using $Modifier = ::java::lang::reflect::Modifier;
using $Type = ::java::lang::reflect::Type;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $StringJoiner = ::java::util::StringJoiner;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ConstantPool = ::jdk::internal::reflect::ConstantPool;
using $MethodAccessor = ::jdk::internal::reflect::MethodAccessor;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $ReflectionFactory = ::jdk::internal::reflect::ReflectionFactory;
using $AnnotationParser = ::sun::reflect::annotation::AnnotationParser;
using $AnnotationType = ::sun::reflect::annotation::AnnotationType;
using $ExceptionProxy = ::sun::reflect::annotation::ExceptionProxy;
using $TypeNotPresentExceptionProxy = ::sun::reflect::annotation::TypeNotPresentExceptionProxy;
using $CoreReflectionFactory = ::sun::reflect::generics::factory::CoreReflectionFactory;
using $GenericsFactory = ::sun::reflect::generics::factory::GenericsFactory;
using $ConstructorRepository = ::sun::reflect::generics::repository::ConstructorRepository;
using $MethodRepository = ::sun::reflect::generics::repository::MethodRepository;
using $MethodScope = ::sun::reflect::generics::scope::MethodScope;
using $Scope = ::sun::reflect::generics::scope::Scope;

namespace java {
	namespace lang {
		namespace reflect {

$CompoundAttribute _Method_FieldAnnotations_clazz[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _Method_FieldAnnotations_modifiers[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _Method_MethodAnnotations_invoke32[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{"Ljdk/internal/vm/annotation/ForceInline;", nullptr},
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Method_MethodAnnotations_setAccessible38[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$FieldInfo _Method_FieldInfo_[] = {
	{"clazz", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE, $field(Method, clazz), _Method_FieldAnnotations_clazz},
	{"slot", "I", nullptr, $PRIVATE, $field(Method, slot)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Method, name)},
	{"returnType", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE, $field(Method, returnType)},
	{"parameterTypes", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE, $field(Method, parameterTypes)},
	{"exceptionTypes", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE, $field(Method, exceptionTypes)},
	{"modifiers", "I", nullptr, $PRIVATE, $field(Method, modifiers), _Method_FieldAnnotations_modifiers},
	{"signature", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(Method, signature)},
	{"genericInfo", "Lsun/reflect/generics/repository/MethodRepository;", nullptr, $PRIVATE | $TRANSIENT, $field(Method, genericInfo)},
	{"annotations", "[B", nullptr, $PRIVATE, $field(Method, annotations)},
	{"parameterAnnotations", "[B", nullptr, $PRIVATE, $field(Method, parameterAnnotations)},
	{"annotationDefault", "[B", nullptr, $PRIVATE, $field(Method, annotationDefault)},
	{"methodAccessor", "Ljdk/internal/reflect/MethodAccessor;", nullptr, $PRIVATE | $VOLATILE, $field(Method, methodAccessor)},
	{"root", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE, $field(Method, root)},
	{}
};

$MethodInfo _Method_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;Ljava/lang/String;[Ljava/lang/Class;Ljava/lang/Class;[Ljava/lang/Class;IILjava/lang/String;[B[B[B)V", "(Ljava/lang/Class<*>;Ljava/lang/String;[Ljava/lang/Class<*>;Ljava/lang/Class<*>;[Ljava/lang/Class<*>;IILjava/lang/String;[B[B[B)V", 0, $method(Method, init$, void, $Class*, $String*, $ClassArray*, $Class*, $ClassArray*, int32_t, int32_t, $String*, $bytes*, $bytes*, $bytes*)},
	{"acquireMethodAccessor", "()Ljdk/internal/reflect/MethodAccessor;", nullptr, $PRIVATE, $method(Method, acquireMethodAccessor, $MethodAccessor*)},
	{"checkCanSetAccessible", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", 0, $virtualMethod(Method, checkCanSetAccessible, void, $Class*)},
	{"copy", "()Ljava/lang/reflect/Method;", nullptr, 0, $method(Method, copy, Method*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Method, equals, bool, Object$*)},
	{"getAnnotatedReturnType", "()Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC, $virtualMethod(Method, getAnnotatedReturnType, $AnnotatedType*)},
	{"getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)TT;", $PUBLIC, $virtualMethod(Method, getAnnotation, $Annotation*, $Class*)},
	{"getAnnotationBytes", "()[B", nullptr, 0, $virtualMethod(Method, getAnnotationBytes, $bytes*)},
	{"getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC, $virtualMethod(Method, getDeclaredAnnotations, $AnnotationArray*)},
	{"getDeclaringClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(Method, getDeclaringClass, $Class*)},
	{"getDefaultValue", "()Ljava/lang/Object;", nullptr, $PUBLIC, $method(Method, getDefaultValue, $Object*)},
	{"getExceptionTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(Method, getExceptionTypes, $ClassArray*)},
	{"getFactory", "()Lsun/reflect/generics/factory/GenericsFactory;", nullptr, $PRIVATE, $method(Method, getFactory, $GenericsFactory*)},
	{"getGenericExceptionTypes", "()[Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(Method, getGenericExceptionTypes, $TypeArray*)},
	{"getGenericInfo", "()Lsun/reflect/generics/repository/MethodRepository;", nullptr, 0, $virtualMethod(Method, getGenericInfo, $ConstructorRepository*)},
	{"getGenericParameterTypes", "()[Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(Method, getGenericParameterTypes, $TypeArray*)},
	{"getGenericReturnType", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $method(Method, getGenericReturnType, $Type*)},
	{"getGenericSignature", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(Method, getGenericSignature, $String*)},
	{"getMethodAccessor", "()Ljdk/internal/reflect/MethodAccessor;", nullptr, 0, $method(Method, getMethodAccessor, $MethodAccessor*)},
	{"getModifiers", "()I", nullptr, $PUBLIC, $virtualMethod(Method, getModifiers, int32_t)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Method, getName, $String*)},
	{"getParameterAnnotations", "()[[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC, $virtualMethod(Method, getParameterAnnotations, $AnnotationArray2*)},
	{"getParameterCount", "()I", nullptr, $PUBLIC, $virtualMethod(Method, getParameterCount, int32_t)},
	{"getParameterTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(Method, getParameterTypes, $ClassArray*)},
	{"getReturnType", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $method(Method, getReturnType, $Class*)},
	{"getRoot", "()Ljava/lang/reflect/Method;", nullptr, 0, $virtualMethod(Method, getRoot, Method*)},
	{"getSharedExceptionTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", 0, $virtualMethod(Method, getSharedExceptionTypes, $ClassArray*)},
	{"getSharedParameterTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", 0, $virtualMethod(Method, getSharedParameterTypes, $ClassArray*)},
	{"getTypeParameters", "()[Ljava/lang/reflect/TypeVariable;", "()[Ljava/lang/reflect/TypeVariable<Ljava/lang/reflect/Method;>;", $PUBLIC, $virtualMethod(Method, getTypeParameters, $TypeVariableArray*)},
	{"handleParameterNumberMismatch", "(I[Ljava/lang/Class;)Z", "(I[Ljava/lang/Class<*>;)Z", 0, $virtualMethod(Method, handleParameterNumberMismatch, bool, int32_t, $ClassArray*)},
	{"hasGenericInformation", "()Z", nullptr, 0, $virtualMethod(Method, hasGenericInformation, bool)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Method, hashCode, int32_t)},
	{"invoke", "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $TRANSIENT, $method(Method, invoke, $Object*, Object$*, $ObjectArray*), "java.lang.IllegalAccessException,java.lang.IllegalArgumentException,java.lang.reflect.InvocationTargetException", nullptr, _Method_MethodAnnotations_invoke32},
	{"isBridge", "()Z", nullptr, $PUBLIC, $method(Method, isBridge, bool)},
	{"isDefault", "()Z", nullptr, $PUBLIC, $method(Method, isDefault, bool)},
	{"isSynthetic", "()Z", nullptr, $PUBLIC, $virtualMethod(Method, isSynthetic, bool)},
	{"isVarArgs", "()Z", nullptr, $PUBLIC, $virtualMethod(Method, isVarArgs, bool)},
	{"leafCopy", "()Ljava/lang/reflect/Method;", nullptr, 0, $method(Method, leafCopy, Method*)},
	{"setAccessible", "(Z)V", nullptr, $PUBLIC, $virtualMethod(Method, setAccessible, void, bool), nullptr, nullptr, _Method_MethodAnnotations_setAccessible38},
	{"setMethodAccessor", "(Ljdk/internal/reflect/MethodAccessor;)V", nullptr, 0, $method(Method, setMethodAccessor, void, $MethodAccessor*)},
	{"specificToGenericStringHeader", "(Ljava/lang/StringBuilder;)V", nullptr, 0, $virtualMethod(Method, specificToGenericStringHeader, void, $StringBuilder*)},
	{"specificToStringHeader", "(Ljava/lang/StringBuilder;)V", nullptr, 0, $virtualMethod(Method, specificToStringHeader, void, $StringBuilder*)},
	{"toGenericString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Method, toGenericString, $String*)},
	{"toShortSignature", "()Ljava/lang/String;", nullptr, 0, $method(Method, toShortSignature, $String*)},
	{"toShortString", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(Method, toShortString, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Method, toString, $String*)},
	{}
};

$ClassInfo _Method_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.reflect.Method",
	"java.lang.reflect.Executable",
	nullptr,
	_Method_FieldInfo_,
	_Method_MethodInfo_
};

$Object* allocate$Method($Class* clazz) {
	return $of($alloc(Method));
}

$String* Method::getGenericSignature() {
	return this->signature;
}

$GenericsFactory* Method::getFactory() {
	return $CoreReflectionFactory::make(this, $($MethodScope::make(this)));
}

$ConstructorRepository* Method::getGenericInfo() {
	$useLocalCurrentObjectStackCache();
	if (this->genericInfo == nullptr) {
		$var($String, var$0, getGenericSignature());
		$set(this, genericInfo, $MethodRepository::make(var$0, $(getFactory())));
	}
	return this->genericInfo;
}

void Method::init$($Class* declaringClass, $String* name, $ClassArray* parameterTypes, $Class* returnType, $ClassArray* checkedExceptions, int32_t modifiers, int32_t slot, $String* signature, $bytes* annotations, $bytes* parameterAnnotations, $bytes* annotationDefault) {
	$Executable::init$();
	$set(this, clazz, declaringClass);
	$set(this, name, name);
	$set(this, parameterTypes, parameterTypes);
	$set(this, returnType, returnType);
	$set(this, exceptionTypes, checkedExceptions);
	this->modifiers = modifiers;
	this->slot = slot;
	$set(this, signature, signature);
	$set(this, annotations, annotations);
	$set(this, parameterAnnotations, parameterAnnotations);
	$set(this, annotationDefault, annotationDefault);
}

Method* Method::copy() {
	if (this->root != nullptr) {
		$throwNew($IllegalArgumentException, "Can not copy a non-root Method"_s);
	}
	$var(Method, res, $new<Method>(this->clazz, this->name, this->parameterTypes, this->returnType, this->exceptionTypes, this->modifiers, this->slot, this->signature, this->annotations, this->parameterAnnotations, this->annotationDefault));
	$set(res, root, this);
	$set(res, methodAccessor, this->methodAccessor);
	$set(res, typeAnnotation, this->typeAnnotation);
	res->invokeAddress = this->invokeAddress;
	res->virtualOffset = this->virtualOffset;
	res->virtualIndex = this->virtualIndex;
	return res;
}

Method* Method::leafCopy() {
	if (this->root == nullptr) {
		$throwNew($IllegalArgumentException, "Can only leafCopy a non-root Method"_s);
	}
	$var(Method, res, $new(Method, this->clazz, this->name, this->parameterTypes, this->returnType, this->exceptionTypes, this->modifiers, this->slot, this->signature, this->annotations, this->parameterAnnotations, this->annotationDefault));
	$set(res, root, this->root);
	$set(res, methodAccessor, this->methodAccessor);
	return res;
}

void Method::setAccessible(bool flag) {
	$AccessibleObject::checkPermission();
	if (flag) {
		checkCanSetAccessible($Reflection::getCallerClass());
	}
	setAccessible0(flag);
}

void Method::checkCanSetAccessible($Class* caller) {
	checkCanSetAccessible(caller, this->clazz);
}

Method* Method::getRoot() {
	return this->root;
}

bool Method::hasGenericInformation() {
	return (getGenericSignature() != nullptr);
}

$bytes* Method::getAnnotationBytes() {
	return this->annotations;
}

$Class* Method::getDeclaringClass() {
	return this->clazz;
}

$String* Method::getName() {
	return this->name;
}

int32_t Method::getModifiers() {
	return this->modifiers;
}

$TypeVariableArray* Method::getTypeParameters() {
	if (getGenericSignature() != nullptr) {
		return $nc($($cast($MethodRepository, getGenericInfo())))->getTypeParameters();
	} else {
		return $new($TypeVariableArray, 0);
	}
}

$Class* Method::getReturnType() {
	return this->returnType;
}

$Type* Method::getGenericReturnType() {
	if (getGenericSignature() != nullptr) {
		return $nc($($cast($MethodRepository, getGenericInfo())))->getReturnType();
	} else {
		return getReturnType();
	}
}

$ClassArray* Method::getSharedParameterTypes() {
	return this->parameterTypes;
}

$ClassArray* Method::getSharedExceptionTypes() {
	return this->exceptionTypes;
}

$ClassArray* Method::getParameterTypes() {
	return $cast($ClassArray, $nc(this->parameterTypes)->clone());
}

int32_t Method::getParameterCount() {
	return $nc(this->parameterTypes)->length;
}

$TypeArray* Method::getGenericParameterTypes() {
	return $Executable::getGenericParameterTypes();
}

$ClassArray* Method::getExceptionTypes() {
	return $cast($ClassArray, $nc(this->exceptionTypes)->clone());
}

$TypeArray* Method::getGenericExceptionTypes() {
	return $Executable::getGenericExceptionTypes();
}

bool Method::equals(Object$* obj) {
	{
		$var(Method, other, nullptr);
		bool var$0 = $instanceOf(Method, obj);
		if (var$0) {
			$assign(other, $cast(Method, obj));
			var$0 = true;
		}
		if (var$0) {
			bool var$1 = (getDeclaringClass() == $nc(other)->getDeclaringClass());
			if (var$1) {
				var$1 = (getName() == other->getName());
			}
			if (var$1) {
				if (!$nc($of(this->returnType))->equals(other->getReturnType())) {
					return false;
				}
				return equalParamTypes(this->parameterTypes, other->parameterTypes);
			}
		}
	}
	return false;
}

int32_t Method::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = $nc($($nc(getDeclaringClass())->getName()))->hashCode();
	return var$0 ^ $nc($(getName()))->hashCode();
}

$String* Method::toString() {
	int32_t var$0 = $Modifier::methodModifiers();
	return sharedToString(var$0, isDefault(), this->parameterTypes, this->exceptionTypes);
}

void Method::specificToStringHeader($StringBuilder* sb) {
	$useLocalCurrentObjectStackCache();
	$nc(sb)->append($($nc(getReturnType())->getTypeName()))->append(u' ');
	sb->append($($nc(getDeclaringClass())->getTypeName()))->append(u'.');
	sb->append($(getName()));
}

$String* Method::toShortString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({"method "_s, $($nc(getDeclaringClass())->getTypeName()), $$str(u'.')}));
	return $concat(var$0, $(toShortSignature()));
}

$String* Method::toShortSignature() {
	$useLocalCurrentObjectStackCache();
	$var($StringJoiner, sj, $new($StringJoiner, ","_s, $$str({$(getName()), "("_s}), ")"_s));
	{
		$var($ClassArray, arr$, getParameterTypes());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* parameterType = arr$->get(i$);
			{
				sj->add($($nc(parameterType)->getTypeName()));
			}
		}
	}
	return sj->toString();
}

$String* Method::toGenericString() {
	int32_t var$0 = $Modifier::methodModifiers();
	return sharedToGenericString(var$0, isDefault());
}

void Method::specificToGenericStringHeader($StringBuilder* sb) {
	$useLocalCurrentObjectStackCache();
	$var($Type, genRetType, getGenericReturnType());
	$nc(sb)->append($($nc(genRetType)->getTypeName()))->append(u' ');
	sb->append($($nc(getDeclaringClass())->getTypeName()))->append(u'.');
	sb->append($(getName()));
}

$Object* Method::invoke(Object$* obj, $ObjectArray* args) {
	if (!this->override$) {
		$Class* caller = $Reflection::getCallerClass();
		checkAccess(caller, this->clazz, $Modifier::isStatic(this->modifiers) ? ($Class*)nullptr : $nc($of(obj))->getClass(), this->modifiers);
	}
	$var($MethodAccessor, ma, this->methodAccessor);
	if (ma == nullptr) {
		$assign(ma, acquireMethodAccessor());
	}
	return $of($nc(ma)->invoke(obj, args));
}

bool Method::isBridge() {
	return ((int32_t)(getModifiers() & (uint32_t)$Modifier::BRIDGE)) != 0;
}

bool Method::isVarArgs() {
	return $Executable::isVarArgs();
}

bool Method::isSynthetic() {
	return $Executable::isSynthetic();
}

bool Method::isDefault() {
	bool var$0 = (((int32_t)(getModifiers() & (uint32_t)(($Modifier::ABSTRACT | $Modifier::PUBLIC) | $Modifier::STATIC))) == $Modifier::PUBLIC);
	return var$0 && $nc(getDeclaringClass())->isInterface();
}

$MethodAccessor* Method::acquireMethodAccessor() {
	$var($MethodAccessor, tmp, nullptr);
	if (this->root != nullptr) {
		$assign(tmp, $nc(this->root)->getMethodAccessor());
	}
	if (tmp != nullptr) {
		$set(this, methodAccessor, tmp);
	} else {
		$init($AccessibleObject);
		$assign(tmp, $nc($AccessibleObject::reflectionFactory)->newMethodAccessor(this));
		setMethodAccessor(tmp);
	}
	return tmp;
}

$MethodAccessor* Method::getMethodAccessor() {
	return this->methodAccessor;
}

void Method::setMethodAccessor($MethodAccessor* accessor) {
	$set(this, methodAccessor, accessor);
	if (this->root != nullptr) {
		$nc(this->root)->setMethodAccessor(accessor);
	}
}

$Object* Method::getDefaultValue() {
	$useLocalCurrentObjectStackCache();
	if (this->annotationDefault == nullptr) {
		return $of(nullptr);
	}
	$Class* memberType = $AnnotationType::invocationHandlerReturnType(getReturnType());
	$Class* var$0 = memberType;
	$var($ByteBuffer, var$1, $ByteBuffer::wrap(this->annotationDefault));
	$var($ConstantPool, var$2, $nc($($SharedSecrets::getJavaLangAccess()))->getConstantPool(getDeclaringClass()));
	$var($Object, result, $AnnotationParser::parseMemberValue(var$0, var$1, var$2, getDeclaringClass()));
	if ($instanceOf($ExceptionProxy, result)) {
		{
			$var($TypeNotPresentExceptionProxy, proxy, nullptr);
			bool var$3 = $instanceOf($TypeNotPresentExceptionProxy, result);
			if (var$3) {
				$assign(proxy, $cast($TypeNotPresentExceptionProxy, result));
				var$3 = true;
			}
			if (var$3) {
				$var($String, var$4, $nc(proxy)->typeName());
				$throwNew($TypeNotPresentException, var$4, $(proxy->getCause()));
			}
		}
		$throwNew($AnnotationFormatError, $$str({"Invalid default: "_s, this}));
	}
	return $of(result);
}

$Annotation* Method::getAnnotation($Class* annotationClass) {
	return $Executable::getAnnotation(annotationClass);
}

$AnnotationArray* Method::getDeclaredAnnotations() {
	return $Executable::getDeclaredAnnotations();
}

$AnnotationArray2* Method::getParameterAnnotations() {
	return sharedGetParameterAnnotations(this->parameterTypes, this->parameterAnnotations);
}

$AnnotatedType* Method::getAnnotatedReturnType() {
	return getAnnotatedReturnType0($(getGenericReturnType()));
}

bool Method::handleParameterNumberMismatch(int32_t resultLength, $ClassArray* parameterTypes) {
	$throwNew($AnnotationFormatError, "Parameter annotations don\'t match number of parameters"_s);
	$shouldNotReachHere();
}

Method::Method() {
}

bool Method::isStatic() {
	return (getModifiers() & Modifier::STATIC) != 0;
}

bool Method::isCallerSensitive() {
	$load(::jdk::internal::reflect::CallerSensitive);
	return getAnnotation(::jdk::internal::reflect::CallerSensitive::class$) != nullptr;
}

bool Method::isHidden() {
	$load(::jdk::internal::vm::annotation::Hidden);
	return getAnnotation(::jdk::internal::vm::annotation::Hidden::class$) != nullptr;
}

$Object* Method::invokeSpecial(Object$* obj, $ObjectArray* args) {
	$MethodAccessor* ma = this->methodAccessor;
	if (ma != nullptr) {
		return ma->invokeSpecial(obj, args);
	} else {
		$var($MethodAccessor, ma2, acquireMethodAccessor());
		return ma2->invokeSpecial(obj, args);
	}
}

$Value Method::invokev(Object$* obj, $Value* argv) {
	$var($MethodAccessor, ma, this->methodAccessor);
	if (ma != nullptr) {
		return ma->invokev(obj, argv);
	} else {
		$var($MethodAccessor, ma2, acquireMethodAccessor());
		return ma2->invokev(obj, argv);
	}
}

$String* Method::getDescriptor() {
	$var($StringBuilder, sb, $new<$StringBuilder>());
	sb->append("(");
	for (int32_t i = 0; i < parameterTypes->length; i++) {
		$Class* type = $fcast<$Class>(parameterTypes->get(i));
		sb->append($ref(type->descriptorString()));
	}
	sb->append(")");
	sb->append($ref(returnType->descriptorString()));
	return $ref(sb->toString())->replace(u'.', u'/');
}

$Class* Method::load$($String* name, bool initialize) {
	$loadClass(Method, name, initialize, &_Method_ClassInfo_, allocate$Method);
	return class$;
}

$Class* Method::class$ = nullptr;

		} // reflect
	} // lang
} // java