#include <jdk/internal/reflect/NativeMethodAccessorImpl.h>

#include <java/lang/reflect/Method.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jdk/internal/reflect/DelegatingMethodAccessorImpl.h>
#include <jdk/internal/reflect/MethodAccessor.h>
#include <jdk/internal/reflect/MethodAccessorGenerator.h>
#include <jdk/internal/reflect/MethodAccessorImpl.h>
#include <jdk/internal/reflect/ReflectionFactory.h>
#include <jcpp.h>

#include <java/lang/LongArray.h>
#include <java/lang/Util.h>
#include <java/lang/reflect/InvocationTargetException.h>

using ::java::lang::Util;
using ::java::lang::LongArray;
using ::java::lang::reflect::InvocationTargetException;

#undef GENERATED_OFFSET
#undef U

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Method = ::java::lang::reflect::Method;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $DelegatingMethodAccessorImpl = ::jdk::internal::reflect::DelegatingMethodAccessorImpl;
using $MethodAccessorImpl = ::jdk::internal::reflect::MethodAccessorImpl;

namespace jdk {
	namespace internal {
		namespace reflect {

$FieldInfo _NativeMethodAccessorImpl_FieldInfo_[] = {
	{"U", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(NativeMethodAccessorImpl, U)},
	{"GENERATED_OFFSET", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(NativeMethodAccessorImpl, GENERATED_OFFSET)},
	{"method", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $FINAL, $field(NativeMethodAccessorImpl, method)},
	{"parent", "Ljdk/internal/reflect/DelegatingMethodAccessorImpl;", nullptr, $PRIVATE, $field(NativeMethodAccessorImpl, parent)},
	{"numInvocations", "I", nullptr, $PRIVATE, $field(NativeMethodAccessorImpl, numInvocations)},
	{"generated", "I", nullptr, $PRIVATE | $VOLATILE, $field(NativeMethodAccessorImpl, generated)},
	{}
};

$MethodInfo _NativeMethodAccessorImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/reflect/Method;)V", nullptr, 0, $method(NativeMethodAccessorImpl, init$, void, $Method*)},
	{"invoke", "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(NativeMethodAccessorImpl, invoke, $Object*, Object$*, $ObjectArray*), "java.lang.IllegalArgumentException,java.lang.reflect.InvocationTargetException"},
	{"invoke0", "(Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(NativeMethodAccessorImpl, invoke0, $Object*, $Method*, Object$*, $ObjectArray*)},
	{"setParent", "(Ljdk/internal/reflect/DelegatingMethodAccessorImpl;)V", nullptr, 0, $virtualMethod(NativeMethodAccessorImpl, setParent, void, $DelegatingMethodAccessorImpl*)},
	{"*invokeSpecial", "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, 1},
	{"*invokev", "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, 1},
	{}
};

#define _METHOD_INDEX_invoke0 2

$ClassInfo _NativeMethodAccessorImpl_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.reflect.NativeMethodAccessorImpl",
	"jdk.internal.reflect.MethodAccessorImpl",
	nullptr,
	_NativeMethodAccessorImpl_FieldInfo_,
	_NativeMethodAccessorImpl_MethodInfo_
};

$Object* allocate$NativeMethodAccessorImpl($Class* clazz) {
	return $of($alloc(NativeMethodAccessorImpl));
}

$Unsafe* NativeMethodAccessorImpl::U = nullptr;
int64_t NativeMethodAccessorImpl::GENERATED_OFFSET = 0;

void NativeMethodAccessorImpl::init$($Method* method) {
	$MethodAccessorImpl::init$();
	$set(this, method, method);
}

$Object* NativeMethodAccessorImpl::invoke(Object$* obj, $ObjectArray* args) {
	return NativeMethodAccessorImpl::invoke0(this->method, obj, args);
}

void NativeMethodAccessorImpl::setParent($DelegatingMethodAccessorImpl* parent) {
	$set(this, parent, parent);
}

$Object* NativeMethodAccessorImpl::invoke0($Method* method, Object$* obj, $ObjectArray* args) {
	try {
		return method->clazz->invoke(method, obj, args);
	} catch (InvocationTargetException& e0) {
		// forward 
		throw e0;
	} catch ($Throwable& e) {
		$throwNew(InvocationTargetException, e);
	}
	return nullptr;
}

void clinit$NativeMethodAccessorImpl($Class* class$) {
	$assignStatic(NativeMethodAccessorImpl::U, $Unsafe::getUnsafe());
	NativeMethodAccessorImpl::GENERATED_OFFSET = $nc(NativeMethodAccessorImpl::U)->objectFieldOffset(NativeMethodAccessorImpl::class$, "generated"_s);
}

NativeMethodAccessorImpl::NativeMethodAccessorImpl() {
}

$Object* NativeMethodAccessorImpl::invokeSpecial(Object$* obj, $ObjectArray* args) {
	try {
		return method->clazz->invokeSpecial(method, obj, args);
	} catch (InvocationTargetException& e0) {
		// forward
		throw e0;
	} catch ($Throwable& e) {
		$throwNew(InvocationTargetException, e);
	}
	return nullptr;
}

$Value NativeMethodAccessorImpl::invokev(Object$* obj, $Value* argv) {
	return method->clazz->invokev(method, obj, argv);
}

$Class* NativeMethodAccessorImpl::load$($String* name, bool initialize) {
	$loadClass(NativeMethodAccessorImpl, name, initialize, &_NativeMethodAccessorImpl_ClassInfo_, clinit$NativeMethodAccessorImpl, allocate$NativeMethodAccessorImpl);
	return class$;
}

$Class* NativeMethodAccessorImpl::class$ = nullptr;

		} // reflect
	} // internal
} // jdk