#include <sun/reflect/annotation/AnnotationSupport.h>

#include <java/lang/ClassCastException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/annotation/AnnotationFormatError.h>
#include <java/lang/annotation/Repeatable.h>
#include <java/lang/reflect/Array.h>
#include <java/lang/reflect/InvocationHandler.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Proxy.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/reflect/ReflectionFactory.h>
#include <sun/reflect/annotation/AnnotationSupport$1.h>
#include <sun/reflect/annotation/AnnotationType.h>
#include <jcpp.h>

#undef LANG_ACCESS

using $AnnotationArray = $Array<::java::lang::annotation::Annotation>;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Annotation = ::java::lang::annotation::Annotation;
using $AnnotationFormatError = ::java::lang::annotation::AnnotationFormatError;
using $Repeatable = ::java::lang::annotation::Repeatable;
using $1Array = ::java::lang::reflect::Array;
using $InvocationHandler = ::java::lang::reflect::InvocationHandler;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $Proxy = ::java::lang::reflect::Proxy;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ReflectionFactory = ::jdk::internal::reflect::ReflectionFactory;
using $AnnotationSupport$1 = ::sun::reflect::annotation::AnnotationSupport$1;
using $AnnotationType = ::sun::reflect::annotation::AnnotationType;

namespace sun {
	namespace reflect {
		namespace annotation {

$FieldInfo _AnnotationSupport_FieldInfo_[] = {
	{"LANG_ACCESS", "Ljdk/internal/access/JavaLangAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AnnotationSupport, LANG_ACCESS)},
	{}
};

$MethodInfo _AnnotationSupport_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AnnotationSupport, init$, void)},
	{"checkTypes", "([Ljava/lang/annotation/Annotation;Ljava/lang/annotation/Annotation;Ljava/lang/Class;)V", "<A::Ljava/lang/annotation/Annotation;>([TA;Ljava/lang/annotation/Annotation;Ljava/lang/Class<TA;>;)V", $PRIVATE | $STATIC, $staticMethod(AnnotationSupport, checkTypes, void, $AnnotationArray*, $Annotation*, $Class*)},
	{"containerBeforeContainee", "(Ljava/util/Map;Ljava/lang/Class;)Z", "<A::Ljava/lang/annotation/Annotation;>(Ljava/util/Map<Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;Ljava/lang/annotation/Annotation;>;Ljava/lang/Class<TA;>;)Z", $PRIVATE | $STATIC, $staticMethod(AnnotationSupport, containerBeforeContainee, bool, $Map*, $Class*)},
	{"getAssociatedAnnotations", "(Ljava/util/Map;Ljava/lang/Class;Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", "<A::Ljava/lang/annotation/Annotation;>(Ljava/util/Map<Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;Ljava/lang/annotation/Annotation;>;Ljava/lang/Class<*>;Ljava/lang/Class<TA;>;)[TA;", $PUBLIC | $STATIC, $staticMethod(AnnotationSupport, getAssociatedAnnotations, $AnnotationArray*, $Map*, $Class*, $Class*)},
	{"getDirectlyAndIndirectlyPresent", "(Ljava/util/Map;Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", "<A::Ljava/lang/annotation/Annotation;>(Ljava/util/Map<Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;Ljava/lang/annotation/Annotation;>;Ljava/lang/Class<TA;>;)[TA;", $PUBLIC | $STATIC, $staticMethod(AnnotationSupport, getDirectlyAndIndirectlyPresent, $AnnotationArray*, $Map*, $Class*)},
	{"getIndirectlyPresent", "(Ljava/util/Map;Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", "<A::Ljava/lang/annotation/Annotation;>(Ljava/util/Map<Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;Ljava/lang/annotation/Annotation;>;Ljava/lang/Class<TA;>;)[TA;", $PRIVATE | $STATIC, $staticMethod(AnnotationSupport, getIndirectlyPresent, $AnnotationArray*, $Map*, $Class*)},
	{"getValueArray", "(Ljava/lang/annotation/Annotation;)[Ljava/lang/annotation/Annotation;", "<A::Ljava/lang/annotation/Annotation;>(Ljava/lang/annotation/Annotation;)[TA;", $PRIVATE | $STATIC, $staticMethod(AnnotationSupport, getValueArray, $AnnotationArray*, $Annotation*)},
	{"invalidContainerException", "(Ljava/lang/annotation/Annotation;Ljava/lang/Throwable;)Ljava/lang/annotation/AnnotationFormatError;", nullptr, $PRIVATE | $STATIC, $staticMethod(AnnotationSupport, invalidContainerException, $AnnotationFormatError*, $Annotation*, $Throwable*)},
	{}
};

$InnerClassInfo _AnnotationSupport_InnerClassesInfo_[] = {
	{"sun.reflect.annotation.AnnotationSupport$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _AnnotationSupport_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.reflect.annotation.AnnotationSupport",
	"java.lang.Object",
	nullptr,
	_AnnotationSupport_FieldInfo_,
	_AnnotationSupport_MethodInfo_,
	nullptr,
	nullptr,
	_AnnotationSupport_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.reflect.annotation.AnnotationSupport$1"
};

$Object* allocate$AnnotationSupport($Class* clazz) {
	return $of($alloc(AnnotationSupport));
}

$JavaLangAccess* AnnotationSupport::LANG_ACCESS = nullptr;

void AnnotationSupport::init$() {
}

$AnnotationArray* AnnotationSupport::getDirectlyAndIndirectlyPresent($Map* annotations, $Class* annoClass) {
	$init(AnnotationSupport);
	$useLocalCurrentObjectStackCache();
	$var($List, result, $new($ArrayList));
	$var($Annotation, direct, $cast($Annotation, $nc(annotations)->get(annoClass)));
	if (direct != nullptr) {
		result->add(direct);
	}
	$var($AnnotationArray, indirect, getIndirectlyPresent(annotations, annoClass));
	if (indirect != nullptr && indirect->length != 0) {
		bool indirectFirst = direct == nullptr || containerBeforeContainee(annotations, annoClass);
		result->addAll((indirectFirst ? 0 : 1), $($Arrays::asList(indirect)));
	}
	$var($AnnotationArray, arr, $cast($AnnotationArray, $1Array::newInstance(annoClass, result->size())));
	return $fcast($AnnotationArray, result->toArray(arr));
}

$AnnotationArray* AnnotationSupport::getIndirectlyPresent($Map* annotations, $Class* annoClass) {
	$init(AnnotationSupport);
	$useLocalCurrentObjectStackCache();
	$load($Repeatable);
	$var($Repeatable, repeatable, $cast($Repeatable, $nc(annoClass)->getDeclaredAnnotation($Repeatable::class$)));
	if (repeatable == nullptr) {
		return nullptr;
	}
	$Class* containerClass = $nc(repeatable)->value();
	$var($Annotation, container, $cast($Annotation, $nc(annotations)->get(containerClass)));
	if (container == nullptr) {
		return nullptr;
	}
	$var($AnnotationArray, valueArray, getValueArray(container));
	checkTypes(valueArray, container, annoClass);
	return valueArray;
}

bool AnnotationSupport::containerBeforeContainee($Map* annotations, $Class* annoClass) {
	$init(AnnotationSupport);
	$useLocalCurrentObjectStackCache();
	$load($Repeatable);
	$Class* containerClass = $nc(($cast($Repeatable, $($nc(annoClass)->getDeclaredAnnotation($Repeatable::class$)))))->value();
	{
		$var($Iterator, i$, $nc($($nc(annotations)->keySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* c = $cast($Class, i$->next());
			{
				if (c == containerClass) {
					return true;
				}
				if (c == annoClass) {
					return false;
				}
			}
		}
	}
	return false;
}

$AnnotationArray* AnnotationSupport::getAssociatedAnnotations($Map* declaredAnnotations, $Class* decl, $Class* annoClass) {
	$init(AnnotationSupport);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(decl);
	$var($AnnotationArray, result, getDirectlyAndIndirectlyPresent(declaredAnnotations, annoClass));
	if ($nc($($AnnotationType::getInstance(annoClass)))->isInherited()) {
		$Class* superDecl = decl->getSuperclass();
		while ($nc(result)->length == 0 && superDecl != nullptr) {
			$assign(result, getDirectlyAndIndirectlyPresent($($nc(AnnotationSupport::LANG_ACCESS)->getDeclaredAnnotationMap(superDecl)), annoClass));
			superDecl = superDecl->getSuperclass();
		}
	}
	return result;
}

$AnnotationArray* AnnotationSupport::getValueArray($Annotation* container) {
	$init(AnnotationSupport);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$Class* containerClass = $nc(container)->annotationType();
		$var($AnnotationType, annoType, $AnnotationType::getInstance(containerClass));
		if (annoType == nullptr) {
			$throw($(invalidContainerException(container, nullptr)));
		}
		$var($Method, m, $cast($Method, $nc($($nc(annoType)->members()))->get("value"_s)));
		if (m == nullptr) {
			$throw($(invalidContainerException(container, nullptr)));
		}
		if ($Proxy::isProxyClass($of(container)->getClass())) {
			$var($InvocationHandler, handler, $Proxy::getInvocationHandler(container));
			try {
				$var($AnnotationArray, values, $cast($AnnotationArray, $nc(handler)->invoke(container, m, nullptr)));
				return values;
			} catch ($Throwable& t) {
				$throw($(invalidContainerException(container, t)));
			}
		} else {
			$Class* iface = $nc(m)->getDeclaringClass();
			if (!$nc(iface)->isAnnotation()) {
				$throwNew($UnsupportedOperationException, "Unsupported container annotation type."_s);
			}
			if (!$Modifier::isPublic(m->getModifiers())) {
				$throwNew($UnsupportedOperationException, "Unsupported value member."_s);
			}
			$var($Method, toInvoke, nullptr);
			if (!$Modifier::isPublic($nc(iface)->getModifiers())) {
				if ($System::getSecurityManager() != nullptr) {
					$assign(toInvoke, $cast($Method, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($AnnotationSupport$1, m)))));
				} else {
					$assign(toInvoke, $nc($($ReflectionFactory::getReflectionFactory()))->leafCopyMethod(m));
					$nc(toInvoke)->setAccessible(true);
				}
			} else {
				$assign(toInvoke, m);
			}
			$var($AnnotationArray, values, $cast($AnnotationArray, $nc(toInvoke)->invoke(container, $$new($ObjectArray, 0))));
			return values;
		}
	} catch ($IllegalAccessException& e) {
		$throw($(invalidContainerException(container, e)));
	} catch ($IllegalArgumentException& e) {
		$throw($(invalidContainerException(container, e)));
	} catch ($InvocationTargetException& e) {
		$throw($(invalidContainerException(container, e)));
	} catch ($ClassCastException& e) {
		$throw($(invalidContainerException(container, e)));
	}
	$shouldNotReachHere();
}

$AnnotationFormatError* AnnotationSupport::invalidContainerException($Annotation* anno, $Throwable* cause) {
	$init(AnnotationSupport);
	return $new($AnnotationFormatError, $$str({anno, " is an invalid container for repeating annotations"_s}), cause);
}

void AnnotationSupport::checkTypes($AnnotationArray* annotations, $Annotation* container, $Class* annoClass) {
	$init(AnnotationSupport);
	$useLocalCurrentObjectStackCache();
	{
		$var($AnnotationArray, arr$, annotations);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Annotation, a, arr$->get(i$));
			{
				if (!$nc(annoClass)->isInstance(a)) {
					$throwNew($AnnotationFormatError, $($String::format("%s is an invalid container for repeating annotations of type: %s"_s, $$new($ObjectArray, {
						$of(container),
						$of(annoClass)
					}))));
				}
			}
		}
	}
}

void clinit$AnnotationSupport($Class* class$) {
	$assignStatic(AnnotationSupport::LANG_ACCESS, $SharedSecrets::getJavaLangAccess());
}

AnnotationSupport::AnnotationSupport() {
}

$Class* AnnotationSupport::load$($String* name, bool initialize) {
	$loadClass(AnnotationSupport, name, initialize, &_AnnotationSupport_ClassInfo_, clinit$AnnotationSupport, allocate$AnnotationSupport);
	return class$;
}

$Class* AnnotationSupport::class$ = nullptr;

		} // annotation
	} // reflect
} // sun