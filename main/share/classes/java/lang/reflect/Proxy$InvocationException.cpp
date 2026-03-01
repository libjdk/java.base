#include <java/lang/reflect/Proxy$InvocationException.h>

#include <java/lang/IllegalAccessException.h>
#include <java/lang/InternalError.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Proxy.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;

namespace java {
	namespace lang {
		namespace reflect {

$CompoundAttribute _Proxy$InvocationException_FieldAnnotations_wrapMethodHandle[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$FieldInfo _Proxy$InvocationException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Proxy$InvocationException, serialVersionUID)},
	{"wrapMethodHandle", "Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticField(Proxy$InvocationException, wrapMethodHandle), _Proxy$InvocationException_FieldAnnotations_wrapMethodHandle},
	{}
};

$MethodInfo _Proxy$InvocationException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Throwable;)V", nullptr, 0, $method(Proxy$InvocationException, init$, void, $Throwable*)},
	{"wrap", "(Ljava/lang/Throwable;)Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(Proxy$InvocationException, wrap, $Object*, $Throwable*), "java.lang.reflect.Proxy$InvocationException"},
	{"wrapMH", "()Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(Proxy$InvocationException, wrapMH, $MethodHandle*)},
	{}
};

$InnerClassInfo _Proxy$InvocationException_InnerClassesInfo_[] = {
	{"java.lang.reflect.Proxy$InvocationException", "java.lang.reflect.Proxy", "InvocationException", $STATIC},
	{}
};

$ClassInfo _Proxy$InvocationException_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.reflect.Proxy$InvocationException",
	"java.lang.ReflectiveOperationException",
	nullptr,
	_Proxy$InvocationException_FieldInfo_,
	_Proxy$InvocationException_MethodInfo_,
	nullptr,
	nullptr,
	_Proxy$InvocationException_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.reflect.Proxy"
};

$Object* allocate$Proxy$InvocationException($Class* clazz) {
	return $of($alloc(Proxy$InvocationException));
}

$MethodHandle* Proxy$InvocationException::wrapMethodHandle = nullptr;

void Proxy$InvocationException::init$($Throwable* cause) {
	$ReflectiveOperationException::init$(cause);
}

$Object* Proxy$InvocationException::wrap($Throwable* cause) {
	$init(Proxy$InvocationException);
	$throwNew(Proxy$InvocationException, cause);
	$shouldNotReachHere();
}

$MethodHandle* Proxy$InvocationException::wrapMH() {
	$init(Proxy$InvocationException);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($MethodHandle, mh, Proxy$InvocationException::wrapMethodHandle);
	if (mh == nullptr) {
		try {
			$assignStatic(Proxy$InvocationException::wrapMethodHandle, ($assign(mh, $nc($($MethodHandles::lookup()))->findStatic(Proxy$InvocationException::class$, "wrap"_s, $($MethodType::methodType($Object::class$, $Throwable::class$))))));
		} catch ($NoSuchMethodException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		} catch ($IllegalAccessException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	}
	return mh;
}

Proxy$InvocationException::Proxy$InvocationException() {
}

Proxy$InvocationException::Proxy$InvocationException(const Proxy$InvocationException& e) : $ReflectiveOperationException(e) {
}

void Proxy$InvocationException::throw$() {
	throw *this;
}

$Class* Proxy$InvocationException::load$($String* name, bool initialize) {
	$loadClass(Proxy$InvocationException, name, initialize, &_Proxy$InvocationException_ClassInfo_, allocate$Proxy$InvocationException);
	return class$;
}

$Class* Proxy$InvocationException::class$ = nullptr;

		} // reflect
	} // lang
} // java