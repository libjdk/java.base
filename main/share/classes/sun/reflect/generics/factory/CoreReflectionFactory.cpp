#include <sun/reflect/generics/factory/CoreReflectionFactory.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/TypeNotPresentException.h>
#include <java/lang/reflect/Array.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/GenericDeclaration.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/ParameterizedType.h>
#include <java/lang/reflect/Type.h>
#include <java/lang/reflect/TypeVariable.h>
#include <java/lang/reflect/WildcardType.h>
#include <sun/reflect/generics/factory/GenericsFactory.h>
#include <sun/reflect/generics/reflectiveObjects/GenericArrayTypeImpl.h>
#include <sun/reflect/generics/reflectiveObjects/ParameterizedTypeImpl.h>
#include <sun/reflect/generics/reflectiveObjects/TypeVariableImpl.h>
#include <sun/reflect/generics/reflectiveObjects/WildcardTypeImpl.h>
#include <sun/reflect/generics/scope/Scope.h>
#include <sun/reflect/generics/tree/FieldTypeSignature.h>
#include <jcpp.h>

#undef TYPE

using $TypeArray = $Array<::java::lang::reflect::Type>;
using $FieldTypeSignatureArray = $Array<::sun::reflect::generics::tree::FieldTypeSignature>;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Short = ::java::lang::Short;
using $TypeNotPresentException = ::java::lang::TypeNotPresentException;
using $Void = ::java::lang::Void;
using $1Array = ::java::lang::reflect::Array;
using $Constructor = ::java::lang::reflect::Constructor;
using $GenericDeclaration = ::java::lang::reflect::GenericDeclaration;
using $Method = ::java::lang::reflect::Method;
using $ParameterizedType = ::java::lang::reflect::ParameterizedType;
using $Type = ::java::lang::reflect::Type;
using $TypeVariable = ::java::lang::reflect::TypeVariable;
using $WildcardType = ::java::lang::reflect::WildcardType;
using $GenericsFactory = ::sun::reflect::generics::factory::GenericsFactory;
using $GenericArrayTypeImpl = ::sun::reflect::generics::reflectiveObjects::GenericArrayTypeImpl;
using $ParameterizedTypeImpl = ::sun::reflect::generics::reflectiveObjects::ParameterizedTypeImpl;
using $TypeVariableImpl = ::sun::reflect::generics::reflectiveObjects::TypeVariableImpl;
using $WildcardTypeImpl = ::sun::reflect::generics::reflectiveObjects::WildcardTypeImpl;
using $Scope = ::sun::reflect::generics::scope::Scope;

namespace sun {
	namespace reflect {
		namespace generics {
			namespace factory {

$FieldInfo _CoreReflectionFactory_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(CoreReflectionFactory, $assertionsDisabled)},
	{"decl", "Ljava/lang/reflect/GenericDeclaration;", nullptr, $PRIVATE | $FINAL, $field(CoreReflectionFactory, decl)},
	{"scope", "Lsun/reflect/generics/scope/Scope;", nullptr, $PRIVATE | $FINAL, $field(CoreReflectionFactory, scope)},
	{}
};

$MethodInfo _CoreReflectionFactory_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/reflect/GenericDeclaration;Lsun/reflect/generics/scope/Scope;)V", nullptr, $PRIVATE, $method(CoreReflectionFactory, init$, void, $GenericDeclaration*, $Scope*)},
	{"findTypeVariable", "(Ljava/lang/String;)Ljava/lang/reflect/TypeVariable;", "(Ljava/lang/String;)Ljava/lang/reflect/TypeVariable<*>;", $PUBLIC, $virtualMethod(CoreReflectionFactory, findTypeVariable, $TypeVariable*, $String*)},
	{"getDecl", "()Ljava/lang/reflect/GenericDeclaration;", nullptr, $PRIVATE, $method(CoreReflectionFactory, getDecl, $GenericDeclaration*)},
	{"getDeclsLoader", "()Ljava/lang/ClassLoader;", nullptr, $PRIVATE, $method(CoreReflectionFactory, getDeclsLoader, $ClassLoader*)},
	{"getScope", "()Lsun/reflect/generics/scope/Scope;", nullptr, $PRIVATE, $method(CoreReflectionFactory, getScope, $Scope*)},
	{"make", "(Ljava/lang/reflect/GenericDeclaration;Lsun/reflect/generics/scope/Scope;)Lsun/reflect/generics/factory/CoreReflectionFactory;", nullptr, $PUBLIC | $STATIC, $staticMethod(CoreReflectionFactory, make, CoreReflectionFactory*, $GenericDeclaration*, $Scope*)},
	{"makeArrayType", "(Ljava/lang/reflect/Type;)Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeArrayType, $Type*, $Type*)},
	{"makeBool", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeBool, $Type*)},
	{"makeByte", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeByte, $Type*)},
	{"makeChar", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeChar, $Type*)},
	{"makeDouble", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeDouble, $Type*)},
	{"makeFloat", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeFloat, $Type*)},
	{"makeInt", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeInt, $Type*)},
	{"makeLong", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeLong, $Type*)},
	{"makeNamedType", "(Ljava/lang/String;)Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeNamedType, $Type*, $String*)},
	{"makeParameterizedType", "(Ljava/lang/reflect/Type;[Ljava/lang/reflect/Type;Ljava/lang/reflect/Type;)Ljava/lang/reflect/ParameterizedType;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeParameterizedType, $ParameterizedType*, $Type*, $TypeArray*, $Type*)},
	{"makeShort", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeShort, $Type*)},
	{"makeTypeVariable", "(Ljava/lang/String;[Lsun/reflect/generics/tree/FieldTypeSignature;)Ljava/lang/reflect/TypeVariable;", "(Ljava/lang/String;[Lsun/reflect/generics/tree/FieldTypeSignature;)Ljava/lang/reflect/TypeVariable<*>;", $PUBLIC, $virtualMethod(CoreReflectionFactory, makeTypeVariable, $TypeVariable*, $String*, $FieldTypeSignatureArray*)},
	{"makeVoid", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeVoid, $Type*)},
	{"makeWildcard", "([Lsun/reflect/generics/tree/FieldTypeSignature;[Lsun/reflect/generics/tree/FieldTypeSignature;)Ljava/lang/reflect/WildcardType;", nullptr, $PUBLIC, $virtualMethod(CoreReflectionFactory, makeWildcard, $WildcardType*, $FieldTypeSignatureArray*, $FieldTypeSignatureArray*)},
	{}
};

$ClassInfo _CoreReflectionFactory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.reflect.generics.factory.CoreReflectionFactory",
	"java.lang.Object",
	"sun.reflect.generics.factory.GenericsFactory",
	_CoreReflectionFactory_FieldInfo_,
	_CoreReflectionFactory_MethodInfo_
};

$Object* allocate$CoreReflectionFactory($Class* clazz) {
	return $of($alloc(CoreReflectionFactory));
}

bool CoreReflectionFactory::$assertionsDisabled = false;

void CoreReflectionFactory::init$($GenericDeclaration* d, $Scope* s) {
	$set(this, decl, d);
	$set(this, scope, s);
}

$GenericDeclaration* CoreReflectionFactory::getDecl() {
	return this->decl;
}

$Scope* CoreReflectionFactory::getScope() {
	return this->scope;
}

$ClassLoader* CoreReflectionFactory::getDeclsLoader() {
	$beforeCallerSensitive();
	if ($instanceOf($Class, this->decl)) {
		return $nc(($cast($Class, this->decl)))->getClassLoader();
	}
	if ($instanceOf($Method, this->decl)) {
		return $nc($nc(($cast($Method, this->decl)))->getDeclaringClass())->getClassLoader();
	}
	if (!CoreReflectionFactory::$assertionsDisabled && !$instanceOf($Constructor, this->decl)) {
		$throwNew($AssertionError, $of("Constructor expected"_s));
	}
	return $nc($nc(($cast($Constructor, this->decl)))->getDeclaringClass())->getClassLoader();
}

CoreReflectionFactory* CoreReflectionFactory::make($GenericDeclaration* d, $Scope* s) {
	$init(CoreReflectionFactory);
	return $new(CoreReflectionFactory, d, s);
}

$TypeVariable* CoreReflectionFactory::makeTypeVariable($String* name, $FieldTypeSignatureArray* bounds) {
	return $TypeVariableImpl::make($(getDecl()), name, bounds, this);
}

$WildcardType* CoreReflectionFactory::makeWildcard($FieldTypeSignatureArray* ubs, $FieldTypeSignatureArray* lbs) {
	return $WildcardTypeImpl::make(ubs, lbs, this);
}

$ParameterizedType* CoreReflectionFactory::makeParameterizedType($Type* declaration, $TypeArray* typeArgs, $Type* owner) {
	return $ParameterizedTypeImpl::make($cast($Class, declaration), typeArgs, owner);
}

$TypeVariable* CoreReflectionFactory::findTypeVariable($String* name) {
	return $nc($(getScope()))->lookup(name);
}

$Type* CoreReflectionFactory::makeNamedType($String* name) {
	$beforeCallerSensitive();
	try {
		return $Class::forName(name, false, $(getDeclsLoader()));
	} catch ($ClassNotFoundException& c) {
		$throwNew($TypeNotPresentException, name, c);
	}
	$shouldNotReachHere();
}

$Type* CoreReflectionFactory::makeArrayType($Type* componentType) {
	if ($instanceOf($Class, componentType)) {
		return $of($($1Array::newInstance($cast($Class, componentType), 0)))->getClass();
	} else {
		return $GenericArrayTypeImpl::make(componentType);
	}
}

$Type* CoreReflectionFactory::makeByte() {
	$init($Byte);
	return $Byte::TYPE;
}

$Type* CoreReflectionFactory::makeBool() {
	$init($Boolean);
	return $Boolean::TYPE;
}

$Type* CoreReflectionFactory::makeShort() {
	$init($Short);
	return $Short::TYPE;
}

$Type* CoreReflectionFactory::makeChar() {
	$init($Character);
	return $Character::TYPE;
}

$Type* CoreReflectionFactory::makeInt() {
	$init($Integer);
	return $Integer::TYPE;
}

$Type* CoreReflectionFactory::makeLong() {
	$init($Long);
	return $Long::TYPE;
}

$Type* CoreReflectionFactory::makeFloat() {
	$init($Float);
	return $Float::TYPE;
}

$Type* CoreReflectionFactory::makeDouble() {
	$init($Double);
	return $Double::TYPE;
}

$Type* CoreReflectionFactory::makeVoid() {
	$init($Void);
	return $Void::TYPE;
}

void clinit$CoreReflectionFactory($Class* class$) {
	CoreReflectionFactory::$assertionsDisabled = !CoreReflectionFactory::class$->desiredAssertionStatus();
}

CoreReflectionFactory::CoreReflectionFactory() {
}

$Class* CoreReflectionFactory::load$($String* name, bool initialize) {
	$loadClass(CoreReflectionFactory, name, initialize, &_CoreReflectionFactory_ClassInfo_, clinit$CoreReflectionFactory, allocate$CoreReflectionFactory);
	return class$;
}

$Class* CoreReflectionFactory::class$ = nullptr;

			} // factory
		} // generics
	} // reflect
} // sun