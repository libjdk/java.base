#include <java/util/concurrent/atomic/AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl.h>

#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Modifier.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/concurrent/atomic/AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl$1.h>
#include <java/util/concurrent/atomic/AtomicReferenceFieldUpdater.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <jcpp.h>

#undef U

using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Field = ::java::lang::reflect::Field;
using $Modifier = ::java::lang::reflect::Modifier;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $AtomicReferenceFieldUpdater = ::java::util::concurrent::atomic::AtomicReferenceFieldUpdater;
using $AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl$1 = ::java::util::concurrent::atomic::AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl$1;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {

$FieldInfo _AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl_FieldInfo_[] = {
	{"U", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, U)},
	{"offset", "J", nullptr, $PRIVATE | $FINAL, $field(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, offset)},
	{"cclass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $FINAL, $field(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, cclass)},
	{"tclass", "Ljava/lang/Class;", "Ljava/lang/Class<TT;>;", $PRIVATE | $FINAL, $field(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, tclass)},
	{"vclass", "Ljava/lang/Class;", "Ljava/lang/Class<TV;>;", $PRIVATE | $FINAL, $field(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, vclass)},
	{}
};

$MethodInfo _AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)V", "(Ljava/lang/Class<TT;>;Ljava/lang/Class<TV;>;Ljava/lang/String;Ljava/lang/Class<*>;)V", 0, $method(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, init$, void, $Class*, $Class*, $String*, $Class*)},
	{"accessCheck", "(Ljava/lang/Object;)V", "(TT;)V", $PRIVATE | $FINAL, $method(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, accessCheck, void, Object$*)},
	{"compareAndSet", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z", "(TT;TV;TV;)Z", $PUBLIC | $FINAL, $virtualMethod(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, compareAndSet, bool, Object$*, Object$*, Object$*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TT;)TV;", $PUBLIC | $FINAL, $virtualMethod(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, get, $Object*, Object$*)},
	{"getAndSet", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TT;TV;)TV;", $PUBLIC | $FINAL, $virtualMethod(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, getAndSet, $Object*, Object$*, Object$*)},
	{"isAncestor", "(Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, isAncestor, bool, $ClassLoader*, $ClassLoader*)},
	{"isSamePackage", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, isSamePackage, bool, $Class*, $Class*)},
	{"lazySet", "(Ljava/lang/Object;Ljava/lang/Object;)V", "(TT;TV;)V", $PUBLIC | $FINAL, $virtualMethod(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, lazySet, void, Object$*, Object$*)},
	{"set", "(Ljava/lang/Object;Ljava/lang/Object;)V", "(TT;TV;)V", $PUBLIC | $FINAL, $virtualMethod(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, set, void, Object$*, Object$*)},
	{"throwAccessCheckException", "(Ljava/lang/Object;)V", "(TT;)V", $PRIVATE | $FINAL, $method(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, throwAccessCheckException, void, Object$*)},
	{"throwCCE", "()V", nullptr, $STATIC, $staticMethod(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, throwCCE, void)},
	{"valueCheck", "(Ljava/lang/Object;)V", "(TV;)V", $PRIVATE | $FINAL, $method(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, valueCheck, void, Object$*)},
	{"weakCompareAndSet", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z", "(TT;TV;TV;)Z", $PUBLIC | $FINAL, $virtualMethod(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, weakCompareAndSet, bool, Object$*, Object$*, Object$*)},
	{}
};

$InnerClassInfo _AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl_InnerClassesInfo_[] = {
	{"java.util.concurrent.atomic.AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl", "java.util.concurrent.atomic.AtomicReferenceFieldUpdater", "AtomicReferenceFieldUpdaterImpl", $PRIVATE | $STATIC | $FINAL},
	{"java.util.concurrent.atomic.AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.atomic.AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl",
	"java.util.concurrent.atomic.AtomicReferenceFieldUpdater",
	nullptr,
	_AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl_FieldInfo_,
	_AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl_MethodInfo_,
	"<T:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/concurrent/atomic/AtomicReferenceFieldUpdater<TT;TV;>;",
	nullptr,
	_AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.atomic.AtomicReferenceFieldUpdater"
};

$Object* allocate$AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl($Class* clazz) {
	return $of($alloc(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl));
}

$Unsafe* AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::U = nullptr;

void AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::init$($Class* tclass, $Class* vclass, $String* fieldName, $Class* caller) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$AtomicReferenceFieldUpdater::init$();
	$var($Field, field, nullptr);
	$Class* fieldClass = nullptr;
	int32_t modifiers = 0;
	try {
		$assign(field, $cast($Field, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl$1, this, tclass, fieldName)))));
		modifiers = $nc(field)->getModifiers();
		$ReflectUtil::ensureMemberAccess(caller, tclass, nullptr, modifiers);
		$var($ClassLoader, cl, $nc(tclass)->getClassLoader());
		$var($ClassLoader, ccl, $nc(caller)->getClassLoader());
		if ((ccl != nullptr) && (ccl != cl) && ((cl == nullptr) || !isAncestor(cl, ccl))) {
			$ReflectUtil::checkPackageAccess(tclass);
		}
		fieldClass = field->getType();
	} catch ($PrivilegedActionException& pae) {
		$throwNew($RuntimeException, $(static_cast<$Throwable*>(pae->getException())));
	} catch ($Exception& ex) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ex));
	}
	if (vclass != fieldClass) {
		$throwNew($ClassCastException);
	}
	if ($nc(vclass)->isPrimitive()) {
		$throwNew($IllegalArgumentException, "Must be reference type"_s);
	}
	if (!$Modifier::isVolatile(modifiers)) {
		$throwNew($IllegalArgumentException, "Must be volatile type"_s);
	}
	bool var$1 = $Modifier::isProtected(modifiers);
	bool var$0 = var$1 && $nc(tclass)->isAssignableFrom(caller);
	$set(this, cclass, (var$0 && !isSamePackage(tclass, caller)) ? caller : tclass);
	$set(this, tclass, tclass);
	$set(this, vclass, vclass);
	this->offset = $nc(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::U)->objectFieldOffset(field);
}

bool AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::isAncestor($ClassLoader* first, $ClassLoader* second) {
	$init(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl);
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

bool AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::isSamePackage($Class* class1, $Class* class2) {
	$init(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl);
	$beforeCallerSensitive();
	bool var$0 = $nc(class1)->getClassLoader() == $nc(class2)->getClassLoader();
	if (var$0) {
		var$0 = class1->getPackageName() == class2->getPackageName();
	}
	return var$0;
}

void AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::accessCheck(Object$* obj) {
	if (!$nc(this->cclass)->isInstance(obj)) {
		throwAccessCheckException(obj);
	}
}

void AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::throwAccessCheckException(Object$* obj) {
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

void AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::valueCheck(Object$* v) {
	if (v != nullptr && !($nc(this->vclass)->isInstance(v))) {
		throwCCE();
	}
}

void AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::throwCCE() {
	$init(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl);
	$throwNew($ClassCastException);
}

bool AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::compareAndSet(Object$* obj, Object$* expect, Object$* update) {
	accessCheck(obj);
	valueCheck(update);
	return $nc(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::U)->compareAndSetReference(obj, this->offset, expect, update);
}

bool AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::weakCompareAndSet(Object$* obj, Object$* expect, Object$* update) {
	accessCheck(obj);
	valueCheck(update);
	return $nc(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::U)->compareAndSetReference(obj, this->offset, expect, update);
}

void AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::set(Object$* obj, Object$* newValue) {
	accessCheck(obj);
	valueCheck(newValue);
	$nc(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::U)->putReferenceVolatile(obj, this->offset, newValue);
}

void AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::lazySet(Object$* obj, Object$* newValue) {
	accessCheck(obj);
	valueCheck(newValue);
	$nc(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::U)->putReferenceRelease(obj, this->offset, newValue);
}

$Object* AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::get(Object$* obj) {
	accessCheck(obj);
	return $of($nc(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::U)->getReferenceVolatile(obj, this->offset));
}

$Object* AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::getAndSet(Object$* obj, Object$* newValue) {
	accessCheck(obj);
	valueCheck(newValue);
	return $of($nc(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::U)->getAndSetReference(obj, this->offset, newValue));
}

void clinit$AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl($Class* class$) {
	$assignStatic(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::U, $Unsafe::getUnsafe());
}

AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl() {
}

$Class* AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::load$($String* name, bool initialize) {
	$loadClass(AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, name, initialize, &_AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl_ClassInfo_, clinit$AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl, allocate$AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl);
	return class$;
}

$Class* AtomicReferenceFieldUpdater$AtomicReferenceFieldUpdaterImpl::class$ = nullptr;

			} // atomic
		} // concurrent
	} // util
} // java