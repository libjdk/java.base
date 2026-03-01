#include <java/util/concurrent/atomic/AtomicLongFieldUpdater$CASUpdater.h>

#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Modifier.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/concurrent/atomic/AtomicLongFieldUpdater$CASUpdater$1.h>
#include <java/util/concurrent/atomic/AtomicLongFieldUpdater.h>
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
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Field = ::java::lang::reflect::Field;
using $Modifier = ::java::lang::reflect::Modifier;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $AtomicLongFieldUpdater = ::java::util::concurrent::atomic::AtomicLongFieldUpdater;
using $AtomicLongFieldUpdater$CASUpdater$1 = ::java::util::concurrent::atomic::AtomicLongFieldUpdater$CASUpdater$1;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {

$FieldInfo _AtomicLongFieldUpdater$CASUpdater_FieldInfo_[] = {
	{"U", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AtomicLongFieldUpdater$CASUpdater, U)},
	{"offset", "J", nullptr, $PRIVATE | $FINAL, $field(AtomicLongFieldUpdater$CASUpdater, offset)},
	{"cclass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $FINAL, $field(AtomicLongFieldUpdater$CASUpdater, cclass)},
	{"tclass", "Ljava/lang/Class;", "Ljava/lang/Class<TT;>;", $PRIVATE | $FINAL, $field(AtomicLongFieldUpdater$CASUpdater, tclass)},
	{}
};

$MethodInfo _AtomicLongFieldUpdater$CASUpdater_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)V", "(Ljava/lang/Class<TT;>;Ljava/lang/String;Ljava/lang/Class<*>;)V", 0, $method(AtomicLongFieldUpdater$CASUpdater, init$, void, $Class*, $String*, $Class*)},
	{"accessCheck", "(Ljava/lang/Object;)V", "(TT;)V", $PRIVATE | $FINAL, $method(AtomicLongFieldUpdater$CASUpdater, accessCheck, void, Object$*)},
	{"addAndGet", "(Ljava/lang/Object;J)J", "(TT;J)J", $PUBLIC | $FINAL, $virtualMethod(AtomicLongFieldUpdater$CASUpdater, addAndGet, int64_t, Object$*, int64_t)},
	{"compareAndSet", "(Ljava/lang/Object;JJ)Z", "(TT;JJ)Z", $PUBLIC | $FINAL, $virtualMethod(AtomicLongFieldUpdater$CASUpdater, compareAndSet, bool, Object$*, int64_t, int64_t)},
	{"decrementAndGet", "(Ljava/lang/Object;)J", "(TT;)J", $PUBLIC | $FINAL, $virtualMethod(AtomicLongFieldUpdater$CASUpdater, decrementAndGet, int64_t, Object$*)},
	{"get", "(Ljava/lang/Object;)J", "(TT;)J", $PUBLIC | $FINAL, $virtualMethod(AtomicLongFieldUpdater$CASUpdater, get, int64_t, Object$*)},
	{"getAndAdd", "(Ljava/lang/Object;J)J", "(TT;J)J", $PUBLIC | $FINAL, $virtualMethod(AtomicLongFieldUpdater$CASUpdater, getAndAdd, int64_t, Object$*, int64_t)},
	{"getAndDecrement", "(Ljava/lang/Object;)J", "(TT;)J", $PUBLIC | $FINAL, $virtualMethod(AtomicLongFieldUpdater$CASUpdater, getAndDecrement, int64_t, Object$*)},
	{"getAndIncrement", "(Ljava/lang/Object;)J", "(TT;)J", $PUBLIC | $FINAL, $virtualMethod(AtomicLongFieldUpdater$CASUpdater, getAndIncrement, int64_t, Object$*)},
	{"getAndSet", "(Ljava/lang/Object;J)J", "(TT;J)J", $PUBLIC | $FINAL, $virtualMethod(AtomicLongFieldUpdater$CASUpdater, getAndSet, int64_t, Object$*, int64_t)},
	{"incrementAndGet", "(Ljava/lang/Object;)J", "(TT;)J", $PUBLIC | $FINAL, $virtualMethod(AtomicLongFieldUpdater$CASUpdater, incrementAndGet, int64_t, Object$*)},
	{"lazySet", "(Ljava/lang/Object;J)V", "(TT;J)V", $PUBLIC | $FINAL, $virtualMethod(AtomicLongFieldUpdater$CASUpdater, lazySet, void, Object$*, int64_t)},
	{"set", "(Ljava/lang/Object;J)V", "(TT;J)V", $PUBLIC | $FINAL, $virtualMethod(AtomicLongFieldUpdater$CASUpdater, set, void, Object$*, int64_t)},
	{"throwAccessCheckException", "(Ljava/lang/Object;)V", "(TT;)V", $PRIVATE | $FINAL, $method(AtomicLongFieldUpdater$CASUpdater, throwAccessCheckException, void, Object$*)},
	{"weakCompareAndSet", "(Ljava/lang/Object;JJ)Z", "(TT;JJ)Z", $PUBLIC | $FINAL, $virtualMethod(AtomicLongFieldUpdater$CASUpdater, weakCompareAndSet, bool, Object$*, int64_t, int64_t)},
	{}
};

$InnerClassInfo _AtomicLongFieldUpdater$CASUpdater_InnerClassesInfo_[] = {
	{"java.util.concurrent.atomic.AtomicLongFieldUpdater$CASUpdater", "java.util.concurrent.atomic.AtomicLongFieldUpdater", "CASUpdater", $PRIVATE | $STATIC | $FINAL},
	{"java.util.concurrent.atomic.AtomicLongFieldUpdater$CASUpdater$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _AtomicLongFieldUpdater$CASUpdater_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.atomic.AtomicLongFieldUpdater$CASUpdater",
	"java.util.concurrent.atomic.AtomicLongFieldUpdater",
	nullptr,
	_AtomicLongFieldUpdater$CASUpdater_FieldInfo_,
	_AtomicLongFieldUpdater$CASUpdater_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/util/concurrent/atomic/AtomicLongFieldUpdater<TT;>;",
	nullptr,
	_AtomicLongFieldUpdater$CASUpdater_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.atomic.AtomicLongFieldUpdater"
};

$Object* allocate$AtomicLongFieldUpdater$CASUpdater($Class* clazz) {
	return $of($alloc(AtomicLongFieldUpdater$CASUpdater));
}

$Unsafe* AtomicLongFieldUpdater$CASUpdater::U = nullptr;

void AtomicLongFieldUpdater$CASUpdater::init$($Class* tclass, $String* fieldName, $Class* caller) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$AtomicLongFieldUpdater::init$();
	$var($Field, field, nullptr);
	int32_t modifiers = 0;
	try {
		$assign(field, $cast($Field, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($AtomicLongFieldUpdater$CASUpdater$1, this, tclass, fieldName)))));
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
	$init($Long);
	if ($nc(field)->getType() != $Long::TYPE) {
		$throwNew($IllegalArgumentException, "Must be long type"_s);
	}
	if (!$Modifier::isVolatile(modifiers)) {
		$throwNew($IllegalArgumentException, "Must be volatile type"_s);
	}
	bool var$1 = $Modifier::isProtected(modifiers);
	bool var$0 = var$1 && $nc(tclass)->isAssignableFrom(caller);
	$set(this, cclass, (var$0 && !isSamePackage(tclass, caller)) ? caller : tclass);
	$set(this, tclass, tclass);
	this->offset = $nc(AtomicLongFieldUpdater$CASUpdater::U)->objectFieldOffset(field);
}

void AtomicLongFieldUpdater$CASUpdater::accessCheck(Object$* obj) {
	if (!$nc(this->cclass)->isInstance(obj)) {
		throwAccessCheckException(obj);
	}
}

void AtomicLongFieldUpdater$CASUpdater::throwAccessCheckException(Object$* obj) {
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

bool AtomicLongFieldUpdater$CASUpdater::compareAndSet(Object$* obj, int64_t expect, int64_t update) {
	accessCheck(obj);
	return $nc(AtomicLongFieldUpdater$CASUpdater::U)->compareAndSetLong(obj, this->offset, expect, update);
}

bool AtomicLongFieldUpdater$CASUpdater::weakCompareAndSet(Object$* obj, int64_t expect, int64_t update) {
	accessCheck(obj);
	return $nc(AtomicLongFieldUpdater$CASUpdater::U)->compareAndSetLong(obj, this->offset, expect, update);
}

void AtomicLongFieldUpdater$CASUpdater::set(Object$* obj, int64_t newValue) {
	accessCheck(obj);
	$nc(AtomicLongFieldUpdater$CASUpdater::U)->putLongVolatile(obj, this->offset, newValue);
}

void AtomicLongFieldUpdater$CASUpdater::lazySet(Object$* obj, int64_t newValue) {
	accessCheck(obj);
	$nc(AtomicLongFieldUpdater$CASUpdater::U)->putLongRelease(obj, this->offset, newValue);
}

int64_t AtomicLongFieldUpdater$CASUpdater::get(Object$* obj) {
	accessCheck(obj);
	return $nc(AtomicLongFieldUpdater$CASUpdater::U)->getLongVolatile(obj, this->offset);
}

int64_t AtomicLongFieldUpdater$CASUpdater::getAndSet(Object$* obj, int64_t newValue) {
	accessCheck(obj);
	return $nc(AtomicLongFieldUpdater$CASUpdater::U)->getAndSetLong(obj, this->offset, newValue);
}

int64_t AtomicLongFieldUpdater$CASUpdater::getAndAdd(Object$* obj, int64_t delta) {
	accessCheck(obj);
	return $nc(AtomicLongFieldUpdater$CASUpdater::U)->getAndAddLong(obj, this->offset, delta);
}

int64_t AtomicLongFieldUpdater$CASUpdater::getAndIncrement(Object$* obj) {
	return getAndAdd(obj, 1);
}

int64_t AtomicLongFieldUpdater$CASUpdater::getAndDecrement(Object$* obj) {
	return getAndAdd(obj, -1);
}

int64_t AtomicLongFieldUpdater$CASUpdater::incrementAndGet(Object$* obj) {
	return getAndAdd(obj, 1) + 1;
}

int64_t AtomicLongFieldUpdater$CASUpdater::decrementAndGet(Object$* obj) {
	return getAndAdd(obj, -1) - 1;
}

int64_t AtomicLongFieldUpdater$CASUpdater::addAndGet(Object$* obj, int64_t delta) {
	return getAndAdd(obj, delta) + delta;
}

void clinit$AtomicLongFieldUpdater$CASUpdater($Class* class$) {
	$assignStatic(AtomicLongFieldUpdater$CASUpdater::U, $Unsafe::getUnsafe());
}

AtomicLongFieldUpdater$CASUpdater::AtomicLongFieldUpdater$CASUpdater() {
}

$Class* AtomicLongFieldUpdater$CASUpdater::load$($String* name, bool initialize) {
	$loadClass(AtomicLongFieldUpdater$CASUpdater, name, initialize, &_AtomicLongFieldUpdater$CASUpdater_ClassInfo_, clinit$AtomicLongFieldUpdater$CASUpdater, allocate$AtomicLongFieldUpdater$CASUpdater);
	return class$;
}

$Class* AtomicLongFieldUpdater$CASUpdater::class$ = nullptr;

			} // atomic
		} // concurrent
	} // util
} // java