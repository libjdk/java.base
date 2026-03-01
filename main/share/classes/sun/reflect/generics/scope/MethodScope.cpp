#include <sun/reflect/generics/scope/MethodScope.h>

#include <java/lang/reflect/GenericDeclaration.h>
#include <java/lang/reflect/Method.h>
#include <sun/reflect/generics/scope/AbstractScope.h>
#include <sun/reflect/generics/scope/ClassScope.h>
#include <sun/reflect/generics/scope/Scope.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GenericDeclaration = ::java::lang::reflect::GenericDeclaration;
using $Method = ::java::lang::reflect::Method;
using $AbstractScope = ::sun::reflect::generics::scope::AbstractScope;
using $ClassScope = ::sun::reflect::generics::scope::ClassScope;
using $Scope = ::sun::reflect::generics::scope::Scope;

namespace sun {
	namespace reflect {
		namespace generics {
			namespace scope {

$MethodInfo _MethodScope_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/reflect/Method;)V", nullptr, $PRIVATE, $method(MethodScope, init$, void, $Method*)},
	{"computeEnclosingScope", "()Lsun/reflect/generics/scope/Scope;", nullptr, $PROTECTED, $virtualMethod(MethodScope, computeEnclosingScope, $Scope*)},
	{"getEnclosingClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PRIVATE, $method(MethodScope, getEnclosingClass, $Class*)},
	{"make", "(Ljava/lang/reflect/Method;)Lsun/reflect/generics/scope/MethodScope;", nullptr, $PUBLIC | $STATIC, $staticMethod(MethodScope, make, MethodScope*, $Method*)},
	{}
};

$ClassInfo _MethodScope_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.reflect.generics.scope.MethodScope",
	"sun.reflect.generics.scope.AbstractScope",
	nullptr,
	nullptr,
	_MethodScope_MethodInfo_,
	"Lsun/reflect/generics/scope/AbstractScope<Ljava/lang/reflect/Method;>;"
};

$Object* allocate$MethodScope($Class* clazz) {
	return $of($alloc(MethodScope));
}

void MethodScope::init$($Method* m) {
	$AbstractScope::init$(m);
}

$Class* MethodScope::getEnclosingClass() {
	return $nc(($cast($Method, $(getRecvr()))))->getDeclaringClass();
}

$Scope* MethodScope::computeEnclosingScope() {
	return $ClassScope::make(getEnclosingClass());
}

MethodScope* MethodScope::make($Method* m) {
	$init(MethodScope);
	return $new(MethodScope, m);
}

MethodScope::MethodScope() {
}

$Class* MethodScope::load$($String* name, bool initialize) {
	$loadClass(MethodScope, name, initialize, &_MethodScope_ClassInfo_, allocate$MethodScope);
	return class$;
}

$Class* MethodScope::class$ = nullptr;

			} // scope
		} // generics
	} // reflect
} // sun