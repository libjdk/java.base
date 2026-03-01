#include <java/lang/reflect/Constructor.h>

#include <java/lang/CharSequence.h>
#include <java/lang/SecurityException.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/annotation/AnnotationFormatError.h>
#include <java/lang/reflect/AccessibleObject.h>
#include <java/lang/reflect/AnnotatedElement.h>
#include <java/lang/reflect/AnnotatedType.h>
#include <java/lang/reflect/Executable.h>
#include <java/lang/reflect/GenericDeclaration.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Type.h>
#include <java/lang/reflect/TypeVariable.h>
#include <java/util/StringJoiner.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/reflect/ConstantPool.h>
#include <jdk/internal/reflect/ConstructorAccessor.h>
#include <jdk/internal/reflect/Reflection.h>
#include <jdk/internal/reflect/ReflectionFactory.h>
#include <sun/reflect/annotation/TypeAnnotation$TypeAnnotationTarget.h>
#include <sun/reflect/annotation/TypeAnnotationParser.h>
#include <sun/reflect/generics/factory/CoreReflectionFactory.h>
#include <sun/reflect/generics/factory/GenericsFactory.h>
#include <sun/reflect/generics/repository/ConstructorRepository.h>
#include <sun/reflect/generics/scope/ConstructorScope.h>
#include <sun/reflect/generics/scope/Scope.h>
#include <jcpp.h>

#undef ENUM
#undef METHOD_RECEIVER
#undef STATIC
#undef TYPE

using $AnnotationArray = $Array<::java::lang::annotation::Annotation>;
using $TypeArray = $Array<::java::lang::reflect::Type>;
using $TypeVariableArray = $Array<::java::lang::reflect::TypeVariable>;
using $AnnotationArray2 = $Array<::java::lang::annotation::Annotation, 2>;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $Annotation = ::java::lang::annotation::Annotation;
using $AnnotationFormatError = ::java::lang::annotation::AnnotationFormatError;
using $AccessibleObject = ::java::lang::reflect::AccessibleObject;
using $AnnotatedElement = ::java::lang::reflect::AnnotatedElement;
using $AnnotatedType = ::java::lang::reflect::AnnotatedType;
using $Executable = ::java::lang::reflect::Executable;
using $GenericDeclaration = ::java::lang::reflect::GenericDeclaration;
using $Modifier = ::java::lang::reflect::Modifier;
using $Type = ::java::lang::reflect::Type;
using $StringJoiner = ::java::util::StringJoiner;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ConstantPool = ::jdk::internal::reflect::ConstantPool;
using $ConstructorAccessor = ::jdk::internal::reflect::ConstructorAccessor;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $ReflectionFactory = ::jdk::internal::reflect::ReflectionFactory;
using $TypeAnnotation$TypeAnnotationTarget = ::sun::reflect::annotation::TypeAnnotation$TypeAnnotationTarget;
using $TypeAnnotationParser = ::sun::reflect::annotation::TypeAnnotationParser;
using $CoreReflectionFactory = ::sun::reflect::generics::factory::CoreReflectionFactory;
using $GenericsFactory = ::sun::reflect::generics::factory::GenericsFactory;
using $ConstructorRepository = ::sun::reflect::generics::repository::ConstructorRepository;
using $ConstructorScope = ::sun::reflect::generics::scope::ConstructorScope;
using $Scope = ::sun::reflect::generics::scope::Scope;

namespace java {
	namespace lang {
		namespace reflect {

$CompoundAttribute _Constructor_MethodAnnotations_newInstance35[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{"Ljdk/internal/vm/annotation/ForceInline;", nullptr},
	{}
};

$CompoundAttribute _Constructor_MethodAnnotations_setAccessible37[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$FieldInfo _Constructor_FieldInfo_[] = {
	{"clazz", "Ljava/lang/Class;", "Ljava/lang/Class<TT;>;", $PRIVATE, $field(Constructor, clazz)},
	{"slot", "I", nullptr, $PRIVATE, $field(Constructor, slot)},
	{"parameterTypes", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE, $field(Constructor, parameterTypes)},
	{"exceptionTypes", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE, $field(Constructor, exceptionTypes)},
	{"modifiers", "I", nullptr, $PRIVATE, $field(Constructor, modifiers)},
	{"signature", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(Constructor, signature)},
	{"genericInfo", "Lsun/reflect/generics/repository/ConstructorRepository;", nullptr, $PRIVATE | $TRANSIENT, $field(Constructor, genericInfo)},
	{"annotations", "[B", nullptr, $PRIVATE, $field(Constructor, annotations)},
	{"parameterAnnotations", "[B", nullptr, $PRIVATE, $field(Constructor, parameterAnnotations)},
	{"constructorAccessor", "Ljdk/internal/reflect/ConstructorAccessor;", nullptr, $PRIVATE | $VOLATILE, $field(Constructor, constructorAccessor)},
	{"root", "Ljava/lang/reflect/Constructor;", "Ljava/lang/reflect/Constructor<TT;>;", $PRIVATE, $field(Constructor, root)},
	{}
};

$MethodInfo _Constructor_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;[Ljava/lang/Class;[Ljava/lang/Class;IILjava/lang/String;[B[B)V", "(Ljava/lang/Class<TT;>;[Ljava/lang/Class<*>;[Ljava/lang/Class<*>;IILjava/lang/String;[B[B)V", 0, $method(Constructor, init$, void, $Class*, $ClassArray*, $ClassArray*, int32_t, int32_t, $String*, $bytes*, $bytes*)},
	{"acquireConstructorAccessor", "()Ljdk/internal/reflect/ConstructorAccessor;", nullptr, $PRIVATE, $method(Constructor, acquireConstructorAccessor, $ConstructorAccessor*)},
	{"checkCanSetAccessible", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", 0, $virtualMethod(Constructor, checkCanSetAccessible, void, $Class*)},
	{"copy", "()Ljava/lang/reflect/Constructor;", "()Ljava/lang/reflect/Constructor<TT;>;", 0, $method(Constructor, copy, Constructor*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Constructor, equals, bool, Object$*)},
	{"getAnnotatedReceiverType", "()Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC, $virtualMethod(Constructor, getAnnotatedReceiverType, $AnnotatedType*)},
	{"getAnnotatedReturnType", "()Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC, $virtualMethod(Constructor, getAnnotatedReturnType, $AnnotatedType*)},
	{"getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)TT;", $PUBLIC, $virtualMethod(Constructor, getAnnotation, $Annotation*, $Class*)},
	{"getAnnotationBytes", "()[B", nullptr, 0, $virtualMethod(Constructor, getAnnotationBytes, $bytes*)},
	{"getConstructorAccessor", "()Ljdk/internal/reflect/ConstructorAccessor;", nullptr, 0, $method(Constructor, getConstructorAccessor, $ConstructorAccessor*)},
	{"getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC, $virtualMethod(Constructor, getDeclaredAnnotations, $AnnotationArray*)},
	{"getDeclaringClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<TT;>;", $PUBLIC, $virtualMethod(Constructor, getDeclaringClass, $Class*)},
	{"getExceptionTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(Constructor, getExceptionTypes, $ClassArray*)},
	{"getFactory", "()Lsun/reflect/generics/factory/GenericsFactory;", nullptr, $PRIVATE, $method(Constructor, getFactory, $GenericsFactory*)},
	{"getGenericExceptionTypes", "()[Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(Constructor, getGenericExceptionTypes, $TypeArray*)},
	{"getGenericInfo", "()Lsun/reflect/generics/repository/ConstructorRepository;", nullptr, 0, $virtualMethod(Constructor, getGenericInfo, $ConstructorRepository*)},
	{"getGenericParameterTypes", "()[Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(Constructor, getGenericParameterTypes, $TypeArray*)},
	{"getModifiers", "()I", nullptr, $PUBLIC, $virtualMethod(Constructor, getModifiers, int32_t)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Constructor, getName, $String*)},
	{"getParameterAnnotations", "()[[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC, $virtualMethod(Constructor, getParameterAnnotations, $AnnotationArray2*)},
	{"getParameterCount", "()I", nullptr, $PUBLIC, $virtualMethod(Constructor, getParameterCount, int32_t)},
	{"getParameterTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(Constructor, getParameterTypes, $ClassArray*)},
	{"getRawAnnotations", "()[B", nullptr, 0, $method(Constructor, getRawAnnotations, $bytes*)},
	{"getRawParameterAnnotations", "()[B", nullptr, 0, $method(Constructor, getRawParameterAnnotations, $bytes*)},
	{"getRoot", "()Ljava/lang/reflect/Constructor;", "()Ljava/lang/reflect/Constructor<TT;>;", 0, $virtualMethod(Constructor, getRoot, Constructor*)},
	{"getSharedExceptionTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", 0, $virtualMethod(Constructor, getSharedExceptionTypes, $ClassArray*)},
	{"getSharedParameterTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", 0, $virtualMethod(Constructor, getSharedParameterTypes, $ClassArray*)},
	{"getSignature", "()Ljava/lang/String;", nullptr, 0, $method(Constructor, getSignature, $String*)},
	{"getSlot", "()I", nullptr, 0, $method(Constructor, getSlot, int32_t)},
	{"getTypeParameters", "()[Ljava/lang/reflect/TypeVariable;", "()[Ljava/lang/reflect/TypeVariable<Ljava/lang/reflect/Constructor<TT;>;>;", $PUBLIC, $virtualMethod(Constructor, getTypeParameters, $TypeVariableArray*)},
	{"handleParameterNumberMismatch", "(I[Ljava/lang/Class;)Z", "(I[Ljava/lang/Class<*>;)Z", 0, $virtualMethod(Constructor, handleParameterNumberMismatch, bool, int32_t, $ClassArray*)},
	{"hasGenericInformation", "()Z", nullptr, 0, $virtualMethod(Constructor, hasGenericInformation, bool)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Constructor, hashCode, int32_t)},
	{"isSynthetic", "()Z", nullptr, $PUBLIC, $virtualMethod(Constructor, isSynthetic, bool)},
	{"isVarArgs", "()Z", nullptr, $PUBLIC, $virtualMethod(Constructor, isVarArgs, bool)},
	{"newInstance", "([Ljava/lang/Object;)Ljava/lang/Object;", "([Ljava/lang/Object;)TT;", $PUBLIC | $TRANSIENT, $method(Constructor, newInstance, $Object*, $ObjectArray*), "java.lang.InstantiationException,java.lang.IllegalAccessException,java.lang.IllegalArgumentException,java.lang.reflect.InvocationTargetException", nullptr, _Constructor_MethodAnnotations_newInstance35},
	{"newInstanceWithCaller", "([Ljava/lang/Object;ZLjava/lang/Class;)Ljava/lang/Object;", "([Ljava/lang/Object;ZLjava/lang/Class<*>;)TT;", 0, $method(Constructor, newInstanceWithCaller, $Object*, $ObjectArray*, bool, $Class*), "java.lang.InstantiationException,java.lang.IllegalAccessException,java.lang.reflect.InvocationTargetException"},
	{"setAccessible", "(Z)V", nullptr, $PUBLIC, $virtualMethod(Constructor, setAccessible, void, bool), nullptr, nullptr, _Constructor_MethodAnnotations_setAccessible37},
	{"setConstructorAccessor", "(Ljdk/internal/reflect/ConstructorAccessor;)V", nullptr, 0, $method(Constructor, setConstructorAccessor, void, $ConstructorAccessor*)},
	{"specificToGenericStringHeader", "(Ljava/lang/StringBuilder;)V", nullptr, 0, $virtualMethod(Constructor, specificToGenericStringHeader, void, $StringBuilder*)},
	{"specificToStringHeader", "(Ljava/lang/StringBuilder;)V", nullptr, 0, $virtualMethod(Constructor, specificToStringHeader, void, $StringBuilder*)},
	{"toGenericString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Constructor, toGenericString, $String*)},
	{"toShortString", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(Constructor, toShortString, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Constructor, toString, $String*)},
	{}
};

$ClassInfo _Constructor_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.reflect.Constructor",
	"java.lang.reflect.Executable",
	nullptr,
	_Constructor_FieldInfo_,
	_Constructor_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/reflect/Executable;"
};

$Object* allocate$Constructor($Class* clazz) {
	return $of($alloc(Constructor));
}

$GenericsFactory* Constructor::getFactory() {
	return $CoreReflectionFactory::make(this, $($ConstructorScope::make(this)));
}

$ConstructorRepository* Constructor::getGenericInfo() {
	$useLocalCurrentObjectStackCache();
	if (this->genericInfo == nullptr) {
		$var($String, var$0, getSignature());
		$set(this, genericInfo, $ConstructorRepository::make(var$0, $(getFactory())));
	}
	return this->genericInfo;
}

Constructor* Constructor::getRoot() {
	return this->root;
}

void Constructor::init$($Class* declaringClass, $ClassArray* parameterTypes, $ClassArray* checkedExceptions, int32_t modifiers, int32_t slot, $String* signature, $bytes* annotations, $bytes* parameterAnnotations) {
	$Executable::init$();
	$set(this, clazz, declaringClass);
	$set(this, parameterTypes, parameterTypes);
	$set(this, exceptionTypes, checkedExceptions);
	this->modifiers = modifiers;
	this->slot = slot;
	$set(this, signature, signature);
	$set(this, annotations, annotations);
	$set(this, parameterAnnotations, parameterAnnotations);
}

Constructor* Constructor::copy() {
	if (this->root != nullptr) {
		$throwNew($IllegalArgumentException, "Can not copy a non-root Constructor"_s);
	}
	$var(Constructor, res, $new<Constructor>(this->clazz, this->parameterTypes, this->exceptionTypes, this->modifiers, this->slot, this->signature, this->annotations, this->parameterAnnotations));
	$set(res, root, this);
	$set(res, constructorAccessor, this->constructorAccessor);
	$set(res, typeAnnotation, this->typeAnnotation);
	res->invokeAddress = this->invokeAddress;
	return res;
}

void Constructor::setAccessible(bool flag) {
	$AccessibleObject::checkPermission();
	if (flag) {
		checkCanSetAccessible($Reflection::getCallerClass());
	}
	setAccessible0(flag);
}

void Constructor::checkCanSetAccessible($Class* caller) {
	checkCanSetAccessible(caller, this->clazz);
	if (this->clazz == $Class::class$) {
		$throwNew($SecurityException, "Cannot make a java.lang.Class constructor accessible"_s);
	}
}

bool Constructor::hasGenericInformation() {
	return (getSignature() != nullptr);
}

$bytes* Constructor::getAnnotationBytes() {
	return this->annotations;
}

$Class* Constructor::getDeclaringClass() {
	return this->clazz;
}

$String* Constructor::getName() {
	return $nc(getDeclaringClass())->getName();
}

int32_t Constructor::getModifiers() {
	return this->modifiers;
}

$TypeVariableArray* Constructor::getTypeParameters() {
	if (getSignature() != nullptr) {
		return $nc($(getGenericInfo()))->getTypeParameters();
	} else {
		return $new($TypeVariableArray, 0);
	}
}

$ClassArray* Constructor::getSharedParameterTypes() {
	return this->parameterTypes;
}

$ClassArray* Constructor::getSharedExceptionTypes() {
	return this->exceptionTypes;
}

$ClassArray* Constructor::getParameterTypes() {
	return $cast($ClassArray, $nc(this->parameterTypes)->clone());
}

int32_t Constructor::getParameterCount() {
	return $nc(this->parameterTypes)->length;
}

$TypeArray* Constructor::getGenericParameterTypes() {
	return $Executable::getGenericParameterTypes();
}

$ClassArray* Constructor::getExceptionTypes() {
	return $cast($ClassArray, $nc(this->exceptionTypes)->clone());
}

$TypeArray* Constructor::getGenericExceptionTypes() {
	return $Executable::getGenericExceptionTypes();
}

bool Constructor::equals(Object$* obj) {
	{
		$var(Constructor, other, nullptr);
		bool var$0 = $instanceOf(Constructor, obj);
		if (var$0) {
			$assign(other, $cast(Constructor, obj));
			var$0 = true;
		}
		if (var$0) {
			if (getDeclaringClass() == $nc(other)->getDeclaringClass()) {
				return equalParamTypes(this->parameterTypes, other->parameterTypes);
			}
		}
	}
	return false;
}

int32_t Constructor::hashCode() {
	return $nc($($nc(getDeclaringClass())->getName()))->hashCode();
}

$String* Constructor::toString() {
	return sharedToString($Modifier::constructorModifiers(), false, this->parameterTypes, this->exceptionTypes);
}

void Constructor::specificToStringHeader($StringBuilder* sb) {
	$nc(sb)->append($($nc(getDeclaringClass())->getTypeName()));
}

$String* Constructor::toShortString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder, "constructor "_s));
	sb->append($($nc(getDeclaringClass())->getTypeName()));
	sb->append(u'(');
	$var($StringJoiner, sj, $new($StringJoiner, ","_s));
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
	sb->append($of(sj));
	sb->append(u')');
	return sb->toString();
}

$String* Constructor::toGenericString() {
	return sharedToGenericString($Modifier::constructorModifiers(), false);
}

void Constructor::specificToGenericStringHeader($StringBuilder* sb) {
	specificToStringHeader(sb);
}

$Object* Constructor::newInstance($ObjectArray* initargs) {
	$Class* caller = this->override$ ? ($Class*)nullptr : $Reflection::getCallerClass();
	return $of(newInstanceWithCaller(initargs, !this->override$, caller));
}

$Object* Constructor::newInstanceWithCaller($ObjectArray* args, bool checkAccess, $Class* caller) {
	$useLocalCurrentObjectStackCache();
	if (checkAccess) {
		this->checkAccess(caller, this->clazz, this->clazz, this->modifiers);
	}
	if (((int32_t)($nc(this->clazz)->getModifiers() & (uint32_t)$Modifier::ENUM)) != 0) {
		$throwNew($IllegalArgumentException, "Cannot reflectively create enum objects"_s);
	}
	$var($ConstructorAccessor, ca, this->constructorAccessor);
	if (ca == nullptr) {
		$assign(ca, acquireConstructorAccessor());
	}
	$var($Object, inst, $nc(ca)->newInstance(args));
	return $of(inst);
}

bool Constructor::isVarArgs() {
	return $Executable::isVarArgs();
}

bool Constructor::isSynthetic() {
	return $Executable::isSynthetic();
}

$ConstructorAccessor* Constructor::acquireConstructorAccessor() {
	$var($ConstructorAccessor, tmp, nullptr);
	if (this->root != nullptr) {
		$assign(tmp, $nc(this->root)->getConstructorAccessor());
	}
	if (tmp != nullptr) {
		$set(this, constructorAccessor, tmp);
	} else {
		$init($AccessibleObject);
		$assign(tmp, $nc($AccessibleObject::reflectionFactory)->newConstructorAccessor(this));
		setConstructorAccessor(tmp);
	}
	return tmp;
}

$ConstructorAccessor* Constructor::getConstructorAccessor() {
	return this->constructorAccessor;
}

void Constructor::setConstructorAccessor($ConstructorAccessor* accessor) {
	$set(this, constructorAccessor, accessor);
	if (this->root != nullptr) {
		$nc(this->root)->setConstructorAccessor(accessor);
	}
}

int32_t Constructor::getSlot() {
	return this->slot;
}

$String* Constructor::getSignature() {
	return this->signature;
}

$bytes* Constructor::getRawAnnotations() {
	return this->annotations;
}

$bytes* Constructor::getRawParameterAnnotations() {
	return this->parameterAnnotations;
}

$Annotation* Constructor::getAnnotation($Class* annotationClass) {
	return $Executable::getAnnotation(annotationClass);
}

$AnnotationArray* Constructor::getDeclaredAnnotations() {
	return $Executable::getDeclaredAnnotations();
}

$AnnotationArray2* Constructor::getParameterAnnotations() {
	return sharedGetParameterAnnotations(this->parameterTypes, this->parameterAnnotations);
}

bool Constructor::handleParameterNumberMismatch(int32_t resultLength, $ClassArray* parameterTypes) {
	int32_t numParameters = $nc(parameterTypes)->length;
	$Class* declaringClass = getDeclaringClass();
	if ($nc(declaringClass)->isEnum()) {
		$init($Integer);
		return resultLength + 2 == numParameters && parameterTypes->get(0) == $String::class$ && parameterTypes->get(1) == $Integer::TYPE;
	} else {
		bool var$1 = declaringClass->isAnonymousClass();
		if (var$1 || declaringClass->isLocalClass()) {
			return false;
		} else {
			bool var$3 = declaringClass->isMemberClass();
			if (var$3 && (((int32_t)(declaringClass->getModifiers() & (uint32_t)$Modifier::STATIC)) == 0) && resultLength + 1 == numParameters) {
				return true;
			} else {
				$throwNew($AnnotationFormatError, "Parameter annotations don\'t match number of parameters"_s);
			}
		}
	}
}

$AnnotatedType* Constructor::getAnnotatedReturnType() {
	return getAnnotatedReturnType0(getDeclaringClass());
}

$AnnotatedType* Constructor::getAnnotatedReceiverType() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* thisDeclClass = getDeclaringClass();
	$Class* enclosingClass = $nc(thisDeclClass)->getEnclosingClass();
	if (enclosingClass == nullptr) {
		return nullptr;
	}
	$Class* outerDeclaringClass = thisDeclClass->getDeclaringClass();
	if (outerDeclaringClass == nullptr) {
		return nullptr;
	}
	if ($Modifier::isStatic(thisDeclClass->getModifiers())) {
		return nullptr;
	}
	$var($bytes, var$0, getTypeAnnotationBytes0());
	$var($ConstantPool, var$1, $nc($($SharedSecrets::getJavaLangAccess()))->getConstantPool(thisDeclClass));
	$Class* var$2 = thisDeclClass;
	$init($TypeAnnotation$TypeAnnotationTarget);
	return $TypeAnnotationParser::buildAnnotatedType(var$0, var$1, static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(this))), var$2, $(parameterize(enclosingClass)), $TypeAnnotation$TypeAnnotationTarget::METHOD_RECEIVER);
}

Constructor::Constructor() {
}

$String* Constructor::getDescriptor() {
	$var($StringBuilder, sb, $new<$StringBuilder>());
	sb->append("(");
	for (int32_t i = 0; i < parameterTypes->length; i++) {
		$Class* type = $fcast<$Class>(parameterTypes->get(i));
		sb->append($ref(type->descriptorString()));
	}
	sb->append(")V");
	return $ref(sb->toString())->replace('.', '/');
}

void Constructor::initInstance(Object$* instance, $ObjectArray* initargs) {
	clazz->initInstance(this, instance, initargs);
}

$Class* Constructor::load$($String* name, bool initialize) {
	$loadClass(Constructor, name, initialize, &_Constructor_ClassInfo_, allocate$Constructor);
	return class$;
}

$Class* Constructor::class$ = nullptr;

		} // reflect
	} // lang
} // java