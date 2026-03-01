#include <java/lang/reflect/AccessibleObject.h>

#include <java/lang/IllegalAccessException.h>
#include <java/lang/IllegalCallerException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Module.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/ref/WeakReference.h>
#include <java/lang/reflect/AccessibleObject$Cache.h>
#include <java/lang/reflect/AnnotatedElement.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Executable.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/InaccessibleObjectException.h>
#include <java/lang/reflect/Member.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/ReflectAccess.h>
#include <java/lang/reflect/ReflectPermission.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <jdk/internal/access/JavaLangReflectAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/reflect/Reflection.h>
#include <jdk/internal/reflect/ReflectionFactory$GetReflectionFactoryAction.h>
#include <jdk/internal/reflect/ReflectionFactory.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef ACCESS_PERMISSION

using $AnnotationArray = $Array<::java::lang::annotation::Annotation>;
using $AccessibleObjectArray = $Array<::java::lang::reflect::AccessibleObject>;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalCallerException = ::java::lang::IllegalCallerException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Annotation = ::java::lang::annotation::Annotation;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $WeakReference = ::java::lang::ref::WeakReference;
using $AccessibleObject$Cache = ::java::lang::reflect::AccessibleObject$Cache;
using $AnnotatedElement = ::java::lang::reflect::AnnotatedElement;
using $Constructor = ::java::lang::reflect::Constructor;
using $Executable = ::java::lang::reflect::Executable;
using $Field = ::java::lang::reflect::Field;
using $InaccessibleObjectException = ::java::lang::reflect::InaccessibleObjectException;
using $Member = ::java::lang::reflect::Member;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $ReflectAccess = ::java::lang::reflect::ReflectAccess;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $JavaLangReflectAccess = ::jdk::internal::access::JavaLangReflectAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $VM = ::jdk::internal::misc::VM;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $ReflectionFactory = ::jdk::internal::reflect::ReflectionFactory;
using $ReflectionFactory$GetReflectionFactoryAction = ::jdk::internal::reflect::ReflectionFactory$GetReflectionFactoryAction;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace lang {
		namespace reflect {

$NamedAttribute AccessibleObject_Attribute_var$0[] = {
	{"since", 's', "17"},
	{}
};

$CompoundAttribute _AccessibleObject_MethodAnnotations_init$0[] = {
	{"Ljava/lang/Deprecated;", AccessibleObject_Attribute_var$0},
	{}
};

$CompoundAttribute _AccessibleObject_MethodAnnotations_canAccess1[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$NamedAttribute AccessibleObject_Attribute_var$1[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _AccessibleObject_MethodAnnotations_isAccessible16[] = {
	{"Ljava/lang/Deprecated;", AccessibleObject_Attribute_var$1},
	{}
};

$CompoundAttribute _AccessibleObject_MethodAnnotations_setAccessible20[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _AccessibleObject_MethodAnnotations_setAccessible21[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _AccessibleObject_MethodAnnotations_trySetAccessible25[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$FieldInfo _AccessibleObject_FieldInfo_[] = {
	{"override", "Z", nullptr, 0, $field(AccessibleObject, override$)},
	{"reflectionFactory", "Ljdk/internal/reflect/ReflectionFactory;", nullptr, $STATIC | $FINAL, $staticField(AccessibleObject, reflectionFactory)},
	{"accessCheckCache", "Ljava/lang/Object;", nullptr, $VOLATILE, $field(AccessibleObject, accessCheckCache)},
	{"printStackWhenAccessFails", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(AccessibleObject, printStackWhenAccessFails)},
	{"printStackPropertiesSet", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(AccessibleObject, printStackPropertiesSet)},
	{}
};

$MethodInfo _AccessibleObject_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED | $DEPRECATED, $method(AccessibleObject, init$, void), nullptr, nullptr, _AccessibleObject_MethodAnnotations_init$0},
	{"canAccess", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL, $method(AccessibleObject, canAccess, bool, Object$*), nullptr, nullptr, _AccessibleObject_MethodAnnotations_canAccess1},
	{"checkAccess", "(Ljava/lang/Class;Ljava/lang/Class;Ljava/lang/Class;I)V", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;Ljava/lang/Class<*>;I)V", $FINAL, $method(AccessibleObject, checkAccess, void, $Class*, $Class*, $Class*, int32_t), "java.lang.IllegalAccessException"},
	{"checkCanSetAccessible", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", 0, $virtualMethod(AccessibleObject, checkCanSetAccessible, void, $Class*)},
	{"checkCanSetAccessible", "(Ljava/lang/Class;Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)V", $FINAL, $method(AccessibleObject, checkCanSetAccessible, void, $Class*, $Class*)},
	{"checkCanSetAccessible", "(Ljava/lang/Class;Ljava/lang/Class;Z)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;Z)Z", $PRIVATE, $method(AccessibleObject, checkCanSetAccessible, bool, $Class*, $Class*, bool)},
	{"checkPermission", "()V", nullptr, $STATIC, $staticMethod(AccessibleObject, checkPermission, void)},
	{"getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)TT;", $PUBLIC, $virtualMethod(AccessibleObject, getAnnotation, $Annotation*, $Class*)},
	{"getAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC, $virtualMethod(AccessibleObject, getAnnotations, $AnnotationArray*)},
	{"getAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)[TT;", $PUBLIC, $virtualMethod(AccessibleObject, getAnnotationsByType, $AnnotationArray*, $Class*)},
	{"getDeclaredAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)TT;", $PUBLIC, $virtualMethod(AccessibleObject, getDeclaredAnnotation, $Annotation*, $Class*)},
	{"getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC, $virtualMethod(AccessibleObject, getDeclaredAnnotations, $AnnotationArray*)},
	{"getDeclaredAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)[TT;", $PUBLIC, $virtualMethod(AccessibleObject, getDeclaredAnnotationsByType, $AnnotationArray*, $Class*)},
	{"getRoot", "()Ljava/lang/reflect/AccessibleObject;", nullptr, 0, $virtualMethod(AccessibleObject, getRoot, AccessibleObject*)},
	{"isAccessChecked", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PRIVATE, $method(AccessibleObject, isAccessChecked, bool, $Class*, $Class*)},
	{"isAccessChecked", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE, $method(AccessibleObject, isAccessChecked, bool, $Class*)},
	{"isAccessible", "()Z", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(AccessibleObject, isAccessible, bool), nullptr, nullptr, _AccessibleObject_MethodAnnotations_isAccessible16},
	{"isAnnotationPresent", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;)Z", $PUBLIC, $virtualMethod(AccessibleObject, isAnnotationPresent, bool, $Class*)},
	{"isSubclassOf", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PRIVATE, $method(AccessibleObject, isSubclassOf, bool, $Class*, $Class*)},
	{"printStackTraceWhenAccessFails", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(AccessibleObject, printStackTraceWhenAccessFails, bool)},
	{"setAccessible", "([Ljava/lang/reflect/AccessibleObject;Z)V", nullptr, $PUBLIC | $STATIC, $staticMethod(AccessibleObject, setAccessible, void, $AccessibleObjectArray*, bool), nullptr, nullptr, _AccessibleObject_MethodAnnotations_setAccessible20},
	{"setAccessible", "(Z)V", nullptr, $PUBLIC, $virtualMethod(AccessibleObject, setAccessible, void, bool), nullptr, nullptr, _AccessibleObject_MethodAnnotations_setAccessible21},
	{"setAccessible0", "(Z)Z", nullptr, 0, $virtualMethod(AccessibleObject, setAccessible0, bool, bool)},
	{"slowVerifyAccess", "(Ljava/lang/Class;Ljava/lang/Class;Ljava/lang/Class;I)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;Ljava/lang/Class<*>;I)Z", $PRIVATE, $method(AccessibleObject, slowVerifyAccess, bool, $Class*, $Class*, $Class*, int32_t)},
	{"toShortString", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(AccessibleObject, toShortString, $String*)},
	{"trySetAccessible", "()Z", nullptr, $PUBLIC | $FINAL, $method(AccessibleObject, trySetAccessible, bool), nullptr, nullptr, _AccessibleObject_MethodAnnotations_trySetAccessible25},
	{"verifyAccess", "(Ljava/lang/Class;Ljava/lang/Class;Ljava/lang/Class;I)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;Ljava/lang/Class<*>;I)Z", $FINAL, $method(AccessibleObject, verifyAccess, bool, $Class*, $Class*, $Class*, int32_t)},
	{}
};

$InnerClassInfo _AccessibleObject_InnerClassesInfo_[] = {
	{"java.lang.reflect.AccessibleObject$Cache", "java.lang.reflect.AccessibleObject", "Cache", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _AccessibleObject_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.reflect.AccessibleObject",
	"java.lang.Object",
	"java.lang.reflect.AnnotatedElement",
	_AccessibleObject_FieldInfo_,
	_AccessibleObject_MethodInfo_,
	nullptr,
	nullptr,
	_AccessibleObject_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.reflect.AccessibleObject$Cache"
};

$Object* allocate$AccessibleObject($Class* clazz) {
	return $of($alloc(AccessibleObject));
}

$ReflectionFactory* AccessibleObject::reflectionFactory = nullptr;
$volatile(bool) AccessibleObject::printStackWhenAccessFails = false;
$volatile(bool) AccessibleObject::printStackPropertiesSet = false;

void AccessibleObject::checkPermission() {
	$init(AccessibleObject);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		sm->checkPermission($SecurityConstants::ACCESS_PERMISSION);
	}
}

void AccessibleObject::setAccessible($AccessibleObjectArray* array$renamed, bool flag) {
	$init(AccessibleObject);
	$useLocalCurrentObjectStackCache();
	$var($AccessibleObjectArray, array, array$renamed);
	checkPermission();
	if (flag) {
		$Class* caller = $Reflection::getCallerClass();
		$assign(array, $cast($AccessibleObjectArray, $nc(array)->clone()));
		{
			$var($AccessibleObjectArray, arr$, array);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var(AccessibleObject, ao, arr$->get(i$));
				{
					$nc(ao)->checkCanSetAccessible(caller);
				}
			}
		}
	}
	{
		$var($AccessibleObjectArray, arr$, array);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var(AccessibleObject, ao, arr$->get(i$));
			{
				$nc(ao)->setAccessible0(flag);
			}
		}
	}
}

void AccessibleObject::setAccessible(bool flag) {
	AccessibleObject::checkPermission();
	setAccessible0(flag);
}

bool AccessibleObject::setAccessible0(bool flag) {
	this->override$ = flag;
	return flag;
}

bool AccessibleObject::trySetAccessible() {
	AccessibleObject::checkPermission();
	if (this->override$ == true) {
		return true;
	}
	$load($Member);
	if (!$Member::class$->isInstance(this)) {
		return setAccessible0(true);
	}
	$Class* declaringClass = $nc(($cast($Member, this)))->getDeclaringClass();
	if (declaringClass == $Class::class$ && $instanceOf($Constructor, this)) {
		return false;
	}
	if (checkCanSetAccessible($Reflection::getCallerClass(), declaringClass, false)) {
		return setAccessible0(true);
	} else {
		return false;
	}
}

void AccessibleObject::checkCanSetAccessible($Class* caller) {
}

void AccessibleObject::checkCanSetAccessible($Class* caller, $Class* declaringClass) {
	checkCanSetAccessible(caller, declaringClass, true);
}

bool AccessibleObject::checkCanSetAccessible($Class* caller, $Class* declaringClass, bool throwExceptionIfDenied) {
	$useLocalCurrentObjectStackCache();
	$load($MethodHandle);
	if (caller == $MethodHandle::class$) {
		$throwNew($IllegalCallerException);
	}
	$var($Module, callerModule, $nc(caller)->getModule());
	$var($Module, declaringModule, $nc(declaringClass)->getModule());
	if (callerModule == declaringModule) {
		return true;
	}
	if (callerModule == $Object::class$->getModule()) {
		return true;
	}
	if (!$nc(declaringModule)->isNamed()) {
		return true;
	}
	$var($String, pn, declaringClass->getPackageName());
	int32_t modifiers = 0;
	if ($instanceOf($Executable, this)) {
		modifiers = $nc(($cast($Executable, this)))->getModifiers();
	} else {
		modifiers = $nc(($cast($Field, this)))->getModifiers();
	}
	bool isClassPublic = $Modifier::isPublic(declaringClass->getModifiers());
	if (isClassPublic && $nc(declaringModule)->isExported(pn, callerModule)) {
		if ($Modifier::isPublic(modifiers)) {
			return true;
		}
		bool var$1 = $Modifier::isProtected(modifiers);
		bool var$0 = var$1 && $Modifier::isStatic(modifiers);
		if (var$0 && isSubclassOf(caller, declaringClass)) {
			return true;
		}
	}
	if ($nc(declaringModule)->isOpen(pn, callerModule)) {
		return true;
	}
	if (throwExceptionIfDenied) {
		$var($String, msg, "Unable to make "_s);
		if ($instanceOf($Field, this)) {
			$plusAssign(msg, "field "_s);
		}
		$plusAssign(msg, $$str({this, " accessible: "_s, declaringModule, " does not \""_s}));
		if (isClassPublic && $Modifier::isPublic(modifiers)) {
			$plusAssign(msg, "exports"_s);
		} else {
			$plusAssign(msg, "opens"_s);
		}
		$plusAssign(msg, $$str({" "_s, pn, "\" to "_s, callerModule}));
		$var($InaccessibleObjectException, e, $new($InaccessibleObjectException, msg));
		if (printStackTraceWhenAccessFails()) {
			e->printStackTrace($System::err);
		}
		$throw(e);
	}
	return false;
}

bool AccessibleObject::isSubclassOf($Class* queryClass, $Class* ofClass) {
	while (queryClass != nullptr) {
		if (queryClass == ofClass) {
			return true;
		}
		queryClass = queryClass->getSuperclass();
	}
	return false;
}

$String* AccessibleObject::toShortString() {
	return toString();
}

bool AccessibleObject::isAccessible() {
	return this->override$;
}

bool AccessibleObject::canAccess(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	$load($Member);
	if (!$Member::class$->isInstance(this)) {
		return this->override$;
	}
	$Class* declaringClass = $nc(($cast($Member, this)))->getDeclaringClass();
	int32_t modifiers = $nc(($cast($Member, this)))->getModifiers();
	if (!$Modifier::isStatic(modifiers) && ($instanceOf($Method, this) || $instanceOf($Field, this))) {
		if (obj == nullptr) {
			$throwNew($IllegalArgumentException, $$str({"null object for "_s, this}));
		}
		if (!$nc(declaringClass)->isAssignableFrom($nc($of(obj))->getClass())) {
			$throwNew($IllegalArgumentException, $$str({"object is not an instance of "_s, $(declaringClass->getName())}));
		}
	} else if (obj != nullptr) {
		$throwNew($IllegalArgumentException, $$str({"non-null object for "_s, this}));
	}
	if (this->override$) {
		return true;
	}
	$Class* caller = $Reflection::getCallerClass();
	$Class* targetClass = nullptr;
	if ($instanceOf($Constructor, this)) {
		targetClass = declaringClass;
	} else {
		targetClass = $Modifier::isStatic(modifiers) ? ($Class*)nullptr : $nc($of(obj))->getClass();
	}
	return verifyAccess(caller, declaringClass, targetClass, modifiers);
}

void AccessibleObject::init$() {
}

$Annotation* AccessibleObject::getAnnotation($Class* annotationClass) {
	$throwNew($UnsupportedOperationException, "All subclasses should override this method"_s);
	$shouldNotReachHere();
}

bool AccessibleObject::isAnnotationPresent($Class* annotationClass) {
	return $AnnotatedElement::isAnnotationPresent(annotationClass);
}

$AnnotationArray* AccessibleObject::getAnnotationsByType($Class* annotationClass) {
	$throwNew($UnsupportedOperationException, "All subclasses should override this method"_s);
	$shouldNotReachHere();
}

$AnnotationArray* AccessibleObject::getAnnotations() {
	return getDeclaredAnnotations();
}

$Annotation* AccessibleObject::getDeclaredAnnotation($Class* annotationClass) {
	return getAnnotation(annotationClass);
}

$AnnotationArray* AccessibleObject::getDeclaredAnnotationsByType($Class* annotationClass) {
	return getAnnotationsByType(annotationClass);
}

$AnnotationArray* AccessibleObject::getDeclaredAnnotations() {
	$throwNew($UnsupportedOperationException, "All subclasses should override this method"_s);
	$shouldNotReachHere();
}

bool AccessibleObject::isAccessChecked($Class* caller, $Class* targetClass) {
	$var($Object, cache, this->accessCheckCache);
	if ($instanceOf($AccessibleObject$Cache, cache)) {
		return $nc(($cast($AccessibleObject$Cache, cache)))->isCacheFor(caller, targetClass);
	}
	return false;
}

bool AccessibleObject::isAccessChecked($Class* caller) {
	$useLocalCurrentObjectStackCache();
	$var($Object, cache, this->accessCheckCache);
	if ($instanceOf($WeakReference, cache)) {
		$var($WeakReference, ref, $cast($WeakReference, cache));
		return $nc(ref)->refersTo(caller);
	}
	return false;
}

void AccessibleObject::checkAccess($Class* caller, $Class* memberClass, $Class* targetClass, int32_t modifiers) {
	if (!verifyAccess(caller, memberClass, targetClass, modifiers)) {
		$var($IllegalAccessException, e, $Reflection::newIllegalAccessException(caller, memberClass, targetClass, modifiers));
		if (printStackTraceWhenAccessFails()) {
			$nc(e)->printStackTrace($System::err);
		}
		$throw(e);
	}
}

bool AccessibleObject::verifyAccess($Class* caller, $Class* memberClass, $Class* targetClass, int32_t modifiers) {
	if (caller == memberClass) {
		return true;
	}
	if (targetClass != nullptr && $Modifier::isProtected(modifiers) && targetClass != memberClass) {
		if (isAccessChecked(caller, targetClass)) {
			return true;
		}
	} else if (isAccessChecked(caller)) {
		return true;
	}
	return slowVerifyAccess(caller, memberClass, targetClass, modifiers);
}

bool AccessibleObject::slowVerifyAccess($Class* caller, $Class* memberClass, $Class* targetClass, int32_t modifiers) {
	if (caller == nullptr) {
		return $Reflection::verifyPublicMemberAccess(memberClass, modifiers);
	}
	if (!$Reflection::verifyMemberAccess(caller, memberClass, targetClass, modifiers)) {
		return false;
	}
	$var($Object, cache, (targetClass != nullptr && $Modifier::isProtected(modifiers) && targetClass != memberClass) ? $AccessibleObject$Cache::protectedMemberCallerCache(caller, targetClass) : $of($new($WeakReference, caller)));
	$set(this, accessCheckCache, cache);
	return true;
}

bool AccessibleObject::printStackTraceWhenAccessFails() {
	$init(AccessibleObject);
	if (!AccessibleObject::printStackPropertiesSet && $VM::initLevel() >= 1) {
		$var($String, s, $GetPropertyAction::privilegedGetProperty("sun.reflect.debugModuleAccessChecks"_s));
		if (s != nullptr) {
			AccessibleObject::printStackWhenAccessFails = !s->equalsIgnoreCase("false"_s);
		}
		AccessibleObject::printStackPropertiesSet = true;
	}
	return AccessibleObject::printStackWhenAccessFails;
}

AccessibleObject* AccessibleObject::getRoot() {
	$throwNew($InternalError);
	$shouldNotReachHere();
}

void clinit$AccessibleObject($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		$SharedSecrets::setJavaLangReflectAccess($$new($ReflectAccess));
	}
	$assignStatic(AccessibleObject::reflectionFactory, $cast($ReflectionFactory, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ReflectionFactory$GetReflectionFactoryAction)))));
}

AccessibleObject::AccessibleObject() {
}

$Class* AccessibleObject::load$($String* name, bool initialize) {
	$loadClass(AccessibleObject, name, initialize, &_AccessibleObject_ClassInfo_, clinit$AccessibleObject, allocate$AccessibleObject);
	return class$;
}

$Class* AccessibleObject::class$ = nullptr;

		} // reflect
	} // lang
} // java