#include <sun/reflect/generics/scope/ConstructorScope.h>

#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/GenericDeclaration.h>
#include <sun/reflect/generics/scope/AbstractScope.h>
#include <sun/reflect/generics/scope/ClassScope.h>
#include <sun/reflect/generics/scope/Scope.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Constructor = ::java::lang::reflect::Constructor;
using $GenericDeclaration = ::java::lang::reflect::GenericDeclaration;
using $AbstractScope = ::sun::reflect::generics::scope::AbstractScope;
using $ClassScope = ::sun::reflect::generics::scope::ClassScope;
using $Scope = ::sun::reflect::generics::scope::Scope;

namespace sun {
	namespace reflect {
		namespace generics {
			namespace scope {

$MethodInfo _ConstructorScope_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/reflect/Constructor;)V", "(Ljava/lang/reflect/Constructor<*>;)V", $PRIVATE, $method(ConstructorScope, init$, void, $Constructor*)},
	{"computeEnclosingScope", "()Lsun/reflect/generics/scope/Scope;", nullptr, $PROTECTED, $virtualMethod(ConstructorScope, computeEnclosingScope, $Scope*)},
	{"getEnclosingClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PRIVATE, $method(ConstructorScope, getEnclosingClass, $Class*)},
	{"make", "(Ljava/lang/reflect/Constructor;)Lsun/reflect/generics/scope/ConstructorScope;", "(Ljava/lang/reflect/Constructor<*>;)Lsun/reflect/generics/scope/ConstructorScope;", $PUBLIC | $STATIC, $staticMethod(ConstructorScope, make, ConstructorScope*, $Constructor*)},
	{}
};

$ClassInfo _ConstructorScope_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.reflect.generics.scope.ConstructorScope",
	"sun.reflect.generics.scope.AbstractScope",
	nullptr,
	nullptr,
	_ConstructorScope_MethodInfo_,
	"Lsun/reflect/generics/scope/AbstractScope<Ljava/lang/reflect/Constructor<*>;>;"
};

$Object* allocate$ConstructorScope($Class* clazz) {
	return $of($alloc(ConstructorScope));
}

void ConstructorScope::init$($Constructor* c) {
	$AbstractScope::init$(c);
}

$Class* ConstructorScope::getEnclosingClass() {
	return $nc(($cast($Constructor, $(getRecvr()))))->getDeclaringClass();
}

$Scope* ConstructorScope::computeEnclosingScope() {
	return $ClassScope::make(getEnclosingClass());
}

ConstructorScope* ConstructorScope::make($Constructor* c) {
	$init(ConstructorScope);
	return $new(ConstructorScope, c);
}

ConstructorScope::ConstructorScope() {
}

$Class* ConstructorScope::load$($String* name, bool initialize) {
	$loadClass(ConstructorScope, name, initialize, &_ConstructorScope_ClassInfo_, allocate$ConstructorScope);
	return class$;
}

$Class* ConstructorScope::class$ = nullptr;

			} // scope
		} // generics
	} // reflect
} // sun