#include <java/util/concurrent/atomic/AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl.h>

#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Modifier.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/concurrent/atomic/AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl$1.h>
#include <java/util/concurrent/atomic/AtomicIntegerFieldUpdater.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <jcpp.h>

#undef TYPE
#undef U

using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Field = ::java::lang::reflect::Field;
using $Modifier = ::java::lang::reflect::Modifier;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $AtomicIntegerFieldUpdater = ::java::util::concurrent::atomic::AtomicIntegerFieldUpdater;
using $AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl$1 = ::java::util::concurrent::atomic::AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl$1;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {

$FieldInfo _AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl_FieldInfo_[] = {
	{"U", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, U)},
	{"offset", "J", nullptr, $PRIVATE | $FINAL, $field(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, offset)},
	{"cclass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $FINAL, $field(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, cclass)},
	{"tclass", "Ljava/lang/Class;", "Ljava/lang/Class<TT;>;", $PRIVATE | $FINAL, $field(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, tclass)},
	{}
};

$MethodInfo _AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)V", "(Ljava/lang/Class<TT;>;Ljava/lang/String;Ljava/lang/Class<*>;)V", 0, $method(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, init$, void, $Class*, $String*, $Class*)},
	{"accessCheck", "(Ljava/lang/Object;)V", "(TT;)V", $PRIVATE | $FINAL, $method(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, accessCheck, void, Object$*)},
	{"addAndGet", "(Ljava/lang/Object;I)I", "(TT;I)I", $PUBLIC | $FINAL, $virtualMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, addAndGet, int32_t, Object$*, int32_t)},
	{"compareAndSet", "(Ljava/lang/Object;II)Z", "(TT;II)Z", $PUBLIC | $FINAL, $virtualMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, compareAndSet, bool, Object$*, int32_t, int32_t)},
	{"decrementAndGet", "(Ljava/lang/Object;)I", "(TT;)I", $PUBLIC | $FINAL, $virtualMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, decrementAndGet, int32_t, Object$*)},
	{"get", "(Ljava/lang/Object;)I", "(TT;)I", $PUBLIC | $FINAL, $virtualMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, get, int32_t, Object$*)},
	{"getAndAdd", "(Ljava/lang/Object;I)I", "(TT;I)I", $PUBLIC | $FINAL, $virtualMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, getAndAdd, int32_t, Object$*, int32_t)},
	{"getAndDecrement", "(Ljava/lang/Object;)I", "(TT;)I", $PUBLIC | $FINAL, $virtualMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, getAndDecrement, int32_t, Object$*)},
	{"getAndIncrement", "(Ljava/lang/Object;)I", "(TT;)I", $PUBLIC | $FINAL, $virtualMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, getAndIncrement, int32_t, Object$*)},
	{"getAndSet", "(Ljava/lang/Object;I)I", "(TT;I)I", $PUBLIC | $FINAL, $virtualMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, getAndSet, int32_t, Object$*, int32_t)},
	{"incrementAndGet", "(Ljava/lang/Object;)I", "(TT;)I", $PUBLIC | $FINAL, $virtualMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, incrementAndGet, int32_t, Object$*)},
	{"isAncestor", "(Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, isAncestor, bool, $ClassLoader*, $ClassLoader*)},
	{"isSamePackage", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, isSamePackage, bool, $Class*, $Class*)},
	{"lazySet", "(Ljava/lang/Object;I)V", "(TT;I)V", $PUBLIC | $FINAL, $virtualMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, lazySet, void, Object$*, int32_t)},
	{"set", "(Ljava/lang/Object;I)V", "(TT;I)V", $PUBLIC | $FINAL, $virtualMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, set, void, Object$*, int32_t)},
	{"throwAccessCheckException", "(Ljava/lang/Object;)V", "(TT;)V", $PRIVATE | $FINAL, $method(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, throwAccessCheckException, void, Object$*)},
	{"weakCompareAndSet", "(Ljava/lang/Object;II)Z", "(TT;II)Z", $PUBLIC | $FINAL, $virtualMethod(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, weakCompareAndSet, bool, Object$*, int32_t, int32_t)},
	{}
};

$InnerClassInfo _AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl_InnerClassesInfo_[] = {
	{"java.util.concurrent.atomic.AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl", "java.util.concurrent.atomic.AtomicIntegerFieldUpdater", "AtomicIntegerFieldUpdaterImpl", $PRIVATE | $STATIC | $FINAL},
	{"java.util.concurrent.atomic.AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.atomic.AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl",
	"java.util.concurrent.atomic.AtomicIntegerFieldUpdater",
	nullptr,
	_AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl_FieldInfo_,
	_AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/util/concurrent/atomic/AtomicIntegerFieldUpdater<TT;>;",
	nullptr,
	_AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.atomic.AtomicIntegerFieldUpdater"
};

$Object* allocate$AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl($Class* clazz) {
	return $of($alloc(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl));
}

$Unsafe* AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::U = nullptr;

void AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::init$($Class* tclass, $String* fieldName, $Class* caller) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$AtomicIntegerFieldUpdater::init$();
	$var($Field, field, nullptr);
	int32_t modifiers = 0;
	try {
		$assign(field, $cast($Field, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl$1, this, tclass, fieldName)))));
		modifiers = $nc(field)->getModifiers();
		$ReflectUtil::ensureMemberAccess(caller, tclass, nullptr, modifiers);
		$var($ClassLoader, cl, $nc(tclass)->getClassLoader());
		$var($ClassLoader, ccl, $nc(caller)->getClassLoader());
		if ((ccl != nullptr) && (ccl != cl) && ((cl == nullptr) || !isAncestor(cl, ccl))) {
			$ReflectUtil::checkPackageAccess(tclass);
		}
	} catch ($PrivilegedActionException& pae) {
		$throwNew($RuntimeException, $(static_cast<$Throwable*>(pae->getException())));
	} catch ($Exception& ex) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ex));
	}
	$init($Integer);
	if ($nc(field)->getType() != $Integer::TYPE) {
		$throwNew($IllegalArgumentException, "Must be integer type"_s);
	}
	if (!$Modifier::isVolatile(modifiers)) {
		$throwNew($IllegalArgumentException, "Must be volatile type"_s);
	}
	bool var$1 = $Modifier::isProtected(modifiers);
	bool var$0 = var$1 && $nc(tclass)->isAssignableFrom(caller);
	$set(this, cclass, (var$0 && !isSamePackage(tclass, caller)) ? caller : tclass);
	$set(this, tclass, tclass);
	this->offset = $nc(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::U)->objectFieldOffset(field);
}

bool AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::isAncestor($ClassLoader* first, $ClassLoader* second) {
	$init(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl);
	$beforeCallerSensitive();
	$var($ClassLoader, acl, first);
	do {
		$assign(acl, $nc(acl)->getParent());
		if (second == acl) {
			return true;
		}
	} while (acl != nullptr);
	return false;
}

bool AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::isSamePackage($Class* class1, $Class* class2) {
	$init(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl);
	$beforeCallerSensitive();
	bool var$0 = $nc(class1)->getClassLoader() == $nc(class2)->getClassLoader();
	if (var$0) {
		var$0 = class1->getPackageName() == class2->getPackageName();
	}
	return var$0;
}

void AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::accessCheck(Object$* obj) {
	if (!$nc(this->cclass)->isInstance(obj)) {
		throwAccessCheckException(obj);
	}
}

void AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::throwAccessCheckException(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if (this->cclass == this->tclass) {
		$throwNew($ClassCastException);
	} else {
		$var($String, var$2, $$str({"Class "_s, $($nc(this->cclass)->getName()), " can not access a protected member of class "_s}));
		$var($String, var$1, $$concat(var$2, $($nc(this->tclass)->getName())));
		$var($String, var$0, $$concat(var$1, " using an instance of "_s));
		$throwNew($RuntimeException, static_cast<$Throwable*>($$new($IllegalAccessException, $$concat(var$0, $($nc($of(obj))->getClass()->getName())))));
	}
}

bool AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::compareAndSet(Object$* obj, int32_t expect, int32_t update) {
	accessCheck(obj);
	return $nc(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::U)->compareAndSetInt(obj, this->offset, expect, update);
}

bool AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::weakCompareAndSet(Object$* obj, int32_t expect, int32_t update) {
	accessCheck(obj);
	return $nc(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::U)->compareAndSetInt(obj, this->offset, expect, update);
}

void AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::set(Object$* obj, int32_t newValue) {
	accessCheck(obj);
	$nc(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::U)->putIntVolatile(obj, this->offset, newValue);
}

void AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::lazySet(Object$* obj, int32_t newValue) {
	accessCheck(obj);
	$nc(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::U)->putIntRelease(obj, this->offset, newValue);
}

int32_t AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::get(Object$* obj) {
	accessCheck(obj);
	return $nc(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::U)->getIntVolatile(obj, this->offset);
}

int32_t AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::getAndSet(Object$* obj, int32_t newValue) {
	accessCheck(obj);
	return $nc(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::U)->getAndSetInt(obj, this->offset, newValue);
}

int32_t AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::getAndAdd(Object$* obj, int32_t delta) {
	accessCheck(obj);
	return $nc(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::U)->getAndAddInt(obj, this->offset, delta);
}

int32_t AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::getAndIncrement(Object$* obj) {
	return getAndAdd(obj, 1);
}

int32_t AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::getAndDecrement(Object$* obj) {
	return getAndAdd(obj, -1);
}

int32_t AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::incrementAndGet(Object$* obj) {
	return getAndAdd(obj, 1) + 1;
}

int32_t AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::decrementAndGet(Object$* obj) {
	return getAndAdd(obj, -1) - 1;
}

int32_t AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::addAndGet(Object$* obj, int32_t delta) {
	return getAndAdd(obj, delta) + delta;
}

void clinit$AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl($Class* class$) {
	$assignStatic(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::U, $Unsafe::getUnsafe());
}

AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl() {
}

$Class* AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::load$($String* name, bool initialize) {
	$loadClass(AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, name, initialize, &_AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl_ClassInfo_, clinit$AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl, allocate$AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl);
	return class$;
}

$Class* AtomicIntegerFieldUpdater$AtomicIntegerFieldUpdaterImpl::class$ = nullptr;

			} // atomic
		} // concurrent
	} // util
} // java